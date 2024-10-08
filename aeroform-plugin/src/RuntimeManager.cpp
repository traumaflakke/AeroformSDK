#include "RuntimeManager.h"
#include "LogManager.h"
#include "PluginManager.h"
#include <nethost.h>
#include <hostfxr.h>
#include <coreclr_delegates.h>
#include <cassert>
#include <vector>
#include "aeroform_common.h"
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#define STR(s) L ## s
#define CH(c) L ## c
#define DIR_SEPARATOR L'\\'
#else
#include <dlfcn.h>
#define STR(s) s
#define CH(c) c
#define DIR_SEPARATOR '/'
#endif

using string_t = std::basic_string<char_t>;

void redirect_trace_output(const char* message) {
    std::string msg(message);
    LogManager::getInstance().log("CoreCLR Trace: " + msg, LogLevel::DEBUG);
}

class RuntimeManager::Impl {
public:
    hostfxr_handle cxt = nullptr;
    load_assembly_and_get_function_pointer_fn load_assembly_and_get_function_pointer = nullptr;
    std::string dllPath;
    
    hostfxr_initialize_for_runtime_config_fn init_for_config_fptr = nullptr;
    hostfxr_get_runtime_delegate_fn get_delegate_fptr = nullptr;
    hostfxr_close_fn close_fptr = nullptr;
    void* hostfxr_lib = nullptr;

    ~Impl() {
        if (cxt) {
            close_fptr(cxt);
        }
    }
};

RuntimeManager::RuntimeManager() : pImpl(std::make_unique<Impl>()) {}

RuntimeManager::~RuntimeManager() = default;

bool RuntimeManager::initialize(const std::string& runtimeConfigPath, const std::string& dllPath) {
    LogManager::getInstance().log("Initializing .NET Runtime", LogLevel::INFO);
    
    std::string pluginPath = PluginManager::getPluginPath();
    if (pluginPath.back() != '/') {
        pluginPath += '/';
    }

    const std::string dotnetRoot = pluginPath + "dotnet";
    setenv("DOTNET_ROOT", dotnetRoot.c_str(), 1);
    setenv("DOTNET_SHARED_PATH", dotnetRoot.c_str(), 1);
    setenv("DOTNET_MULTILEVEL_LOOKUP", "1", 1);
    LogManager::getInstance().log("Set DOTNET_ROOT and DOTNET_SHARED_PATH to: " + dotnetRoot, LogLevel::DEBUG);

    setenv("COREHOST_TRACE", "1", 1);
    setenv("COREHOST_TRACEFILE", (pluginPath + "corehost_trace.log").c_str(), 1);
    LogManager::getInstance().log("Set COREHOST_TRACE=1 and COREHOST_TRACEFILE=" + pluginPath + "corehost_trace.log", LogLevel::DEBUG);

    pImpl->dllPath = dllPath;

    if (!load_hostfxr()) {
        LogManager::getInstance().log("Failed to load hostfxr", LogLevel::ERROR);
        return false;
    }

    LogManager::getInstance().log("Начинаем инициализацию .NET runtime", LogLevel::INFO);
    LogManager::getInstance().log("Путь к конфигурационному файлу: " + runtimeConfigPath, LogLevel::DEBUG);
    
    hostfxr_handle cxt = nullptr;
    int rc = pImpl->init_for_config_fptr(runtimeConfigPath.c_str(), nullptr, &cxt);
    if (rc != 0 && rc != 1) {
        LogManager::getInstance().log("Ошибка инициализации .NET runtime. Код ошибки: " + std::to_string(rc), LogLevel::ERROR);
        return false;
    }
    if (rc == 1) {
        LogManager::getInstance().log(".NET runtime уже инициализирован", LogLevel::INFO);
    } else {
        LogManager::getInstance().log("Успешная инициализация .NET runtime", LogLevel::INFO);
    }

    pImpl->cxt = cxt;

    rc = pImpl->get_delegate_fptr(
        cxt,
        hdt_load_assembly_and_get_function_pointer,
        reinterpret_cast<void**>(&pImpl->load_assembly_and_get_function_pointer));

    if (rc != 0 || pImpl->load_assembly_and_get_function_pointer == nullptr) {
        LogManager::getInstance().log("Failed to get load_assembly_and_get_function_pointer. Error code: " + std::to_string(rc), LogLevel::ERROR);
        pImpl->close_fptr(cxt);
        return false;
    }

    // Вызываем Initialize
    const char* type_name = "Aeroform.Loader.Main, Aeroform.Loader";
    const char* method_name = "Initialize";
    
    void* function_pointer = nullptr;
    rc = pImpl->load_assembly_and_get_function_pointer(
        dllPath.c_str(),
        type_name,
        method_name,
        UNMANAGEDCALLERSONLY_METHOD,
        nullptr,
        &function_pointer);

    if (rc != 0 || function_pointer == nullptr) {
        LogManager::getInstance().log("Failed to get function pointer for Initialize. Error code: " + std::to_string(rc), LogLevel::ERROR);
        pImpl->close_fptr(cxt);
        return false;
    }

    LogManager::getInstance().log("Successfully got function pointer for Initialize", LogLevel::DEBUG);

    typedef void (*InitializeFn)();
    auto initialize = reinterpret_cast<InitializeFn>(function_pointer);
    
    LogManager::getInstance().log("Calling Initialize function", LogLevel::DEBUG);
    try {
        initialize();
        LogManager::getInstance().log("Initialize function called successfully", LogLevel::INFO);
    } catch (const std::exception& e) {
        LogManager::getInstance().log("Exception occurred while calling Initialize: " + std::string(e.what()), LogLevel::ERROR);
        return false;
    } catch (...) {
        LogManager::getInstance().log("Unknown exception occurred while calling Initialize", LogLevel::ERROR);
        return false;
    }

    LogManager::getInstance().log(".NET Runtime initialized successfully", LogLevel::INFO);
    return true;
}

void* RuntimeManager::getFunction(const std::string& typeName, const std::string& methodName) {
    if (!pImpl->load_assembly_and_get_function_pointer || pImpl->dllPath.empty()) {
        LogManager::getInstance().log("Runtime not initialized or DLL path is empty", LogLevel::ERROR);
        return nullptr;
    }

    void* function = nullptr;
    int rc = pImpl->load_assembly_and_get_function_pointer(
        pImpl->dllPath.c_str(),
        typeName.c_str(),
        methodName.c_str(),
        UNMANAGEDCALLERSONLY_METHOD,
        nullptr,
        reinterpret_cast<void**>(&function));

    if (rc != 0 || function == nullptr) {
        LogManager::getInstance().log("Failed to get function: " + methodName, LogLevel::ERROR);
        return nullptr;
    }

    return function;
}

bool RuntimeManager::load_hostfxr() {
    std::string pluginPath = PluginManager::getPluginPath();
    if (pluginPath.back() != '/') {
        pluginPath += '/';
    }
    
    std::string dotnetRoot = pluginPath + "dotnet";
    
    get_hostfxr_parameters parameters{};
    parameters.dotnet_root = dotnetRoot.c_str();
    parameters.size = sizeof(get_hostfxr_parameters);

    size_t buffer_size = 0;
    get_hostfxr_path(nullptr, &buffer_size, &parameters);
    
    std::vector<char> buffer(buffer_size);
    int rc = get_hostfxr_path(buffer.data(), &buffer_size, &parameters);
    if (rc != 0) {
        LogManager::getInstance().log("Failed to get hostfxr path. Error code: " + std::to_string(rc), LogLevel::ERROR);
        return false;
    }

    std::string hostfxr_path(buffer.data());
    LogManager::getInstance().log("Attempting to load hostfxr from: " + hostfxr_path, LogLevel::DEBUG);

    void* lib = AEROFORM_LOAD_LIBRARY(hostfxr_path.c_str());
    if (!lib) {
        LogManager::getInstance().log("Failed to load hostfxr library: " + std::string(AEROFORM_LIBRARY_ERROR), LogLevel::ERROR);
        return false;
    }
    pImpl->hostfxr_lib = lib;

    LogManager::getInstance().log("Successfully loaded hostfxr library", LogLevel::DEBUG);

    pImpl->init_for_config_fptr = reinterpret_cast<hostfxr_initialize_for_runtime_config_fn>(AEROFORM_GET_PROC_ADDRESS(lib, "hostfxr_initialize_for_runtime_config"));
    pImpl->get_delegate_fptr = reinterpret_cast<hostfxr_get_runtime_delegate_fn>(AEROFORM_GET_PROC_ADDRESS(lib, "hostfxr_get_runtime_delegate"));
    pImpl->close_fptr = reinterpret_cast<hostfxr_close_fn>(AEROFORM_GET_PROC_ADDRESS(lib, "hostfxr_close"));

    if (!pImpl->init_for_config_fptr || !pImpl->get_delegate_fptr || !pImpl->close_fptr) {
        LogManager::getInstance().log("Failed to get one or more required functions from hostfxr", LogLevel::ERROR);
        return false;
    }

    hostfxr_set_error_writer_fn error_writer = reinterpret_cast<hostfxr_set_error_writer_fn>(
        AEROFORM_GET_PROC_ADDRESS(lib, "hostfxr_set_error_writer"));
    if (error_writer) {
        error_writer(redirect_trace_output);
        LogManager::getInstance().log("Set custom error writer for CoreCLR tracing", LogLevel::DEBUG);
    } else {
        LogManager::getInstance().log("Failed to set custom error writer for CoreCLR tracing", LogLevel::WARNING);
    }

    LogManager::getInstance().log("Successfully loaded all required functions from hostfxr", LogLevel::DEBUG);
    return true;
}