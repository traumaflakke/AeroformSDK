#include "aeroform_common.h"

#include "PluginManager.h"
#include "LogManager.h"
#include "XPLMPlugin.h"
#include "XPLMUtilities.h"

#include <cstring>
#include <algorithm>
#include <XPLMDisplay.h>

PluginManager::PluginManager() 
    : libraryManager(),
      benchmarkManager(libraryManager),
      configManager("aeroform.json"),
      runtimeManager(RuntimeManager::getInstance()) {
    LogManager::getInstance().log("PluginManager constructed", LogLevel::DEBUG);
}

PluginManager::~PluginManager() {
    shutdown();
}

std::string PluginManager::getPluginPath() {
    char pluginPath[512];
    XPLMGetPluginInfo(XPLMGetMyID(), NULL, pluginPath, NULL, NULL);
    
    std::string path(pluginPath);
    
    // Заменяем двоеточия на слеши
    std::replace(path.begin(), path.end(), ':', '/');
    
    // Удаляем метку тома, если путь не начинается с /Users, сохраняя начальный слеш
    if (path.substr(0, 6) != "/Users") {
        size_t secondSlash = path.find('/', 1);  // Ищем второй слеш
        if (secondSlash != std::string::npos) {
            path = "/" + path.substr(secondSlash + 1);  // Сохраняем начальный слеш
        }
    }
    
    // Удаляем .xpl в конце пути
    size_t macXplPos = path.rfind(AEROFORM_PLUGIN_FILENAME);
    if (macXplPos != std::string::npos) {
        path = path.substr(0, macXplPos);
    }
    
    // Убеждаемся, что путь заканчивается на слеш
    if (!path.empty() && path.back() != '/') {
        path += '/';
    }
    
    return path;
}

bool PluginManager::initialize() {
    LogManager::getInstance().initialize("aeroform.log");
    LogManager::getInstance().log("PluginManager::initialize() started", LogLevel::INFO);

    if (!configManager.loadConfig()) {
        LogManager::getInstance().log("Failed to load configuration", LogLevel::ERROR);
        return false;
    }

    std::string pluginPath = getPluginPath();
    std::string runtimeConfigPath = pluginPath + "Aeroform.Loader.runtimeconfig.json";
    std::string dllPath = pluginPath + "Aeroform.Loader.dll";

    if (!runtimeManager.initialize(runtimeConfigPath, dllPath)) {
        LogManager::getInstance().log("Failed to initialize RuntimeManager", LogLevel::ERROR);
        return false; 
    }

    // Регистрируем обработчик клавиш
    XPLMRegisterKeySniffer(PluginManager::keySnifferCallback, 1, nullptr);

    return true;
}

void PluginManager::shutdown() {
    LogManager::getInstance().log("PluginManager::shutdown() started", LogLevel::INFO);
    
    // Здесь можно добавить завершение работы других компонентов
    // libraryManager.unloadLibrary();
    
    LogManager::getInstance().shutdown();
}

int PluginManager::start(char* outName, char* outSig, char* outDesc) {
    if (!initialize()) {
        LogManager::getInstance().log("Failed to initialize PluginManager", LogLevel::ERROR);
        return 0;
    }

    strcpy(outName, (configManager.getName() + " [Aeroform v" + AEROFORM_VERSION + "]").c_str());
    strcpy(outSig, "aeroform.bridge");
    strcpy(outDesc, (configManager.getDescription() + " v" + configManager.getVersion()).c_str());

    return 1;
}

void PluginManager::stop() {
    // LogManager::getInstance().log("XPluginStop() called", LogLevel::INFO);
    // libraryManager.CallPluginStop();
    shutdown();
}

void PluginManager::enable() {
    // LogManager::getInstance().log("Plugin enabled", LogLevel::INFO);
    // libraryManager.CallPluginEnable();
}

void PluginManager::disable() {
    // LogManager::getInstance().log("Plugin disabled", LogLevel::INFO);
    // libraryManager.CallPluginDisable();
}

void PluginManager::receiveMessage(int inMessage, void* inParam) {
    // LogManager::getInstance().log("Received message: " + std::to_string(inMessage), LogLevel::DEBUG);
    // libraryManager.CallPluginReceiveMessage(inMessage, inParam);
}

void PluginManager::onKeyPress(char key, XPLMKeyFlags flags, char virtualKey) {
    LogManager::getInstance().log("onKeyPress() called, pressed key: " + std::to_string(key) + 
    " Flag: " + std::to_string(flags) + " VirtualKey: " + std::to_string(virtualKey), LogLevel::DEBUG);

    // Проверяем, нажата ли клавиша F12 (virtualKey 123) с зажатым Shift (flags 9 или 17)
    if (virtualKey == 122 && (flags == 9)) {
        LogManager::getInstance().log("Shift+F12 pressed. Reloading Aeroform.dll", LogLevel::INFO);
        XPLMReloadPlugins();
    }
}

int PluginManager::keySnifferCallback(char inChar, XPLMKeyFlags inFlags, char inVirtualKey, void* inRefcon) {
    PluginManager::getInstance().onKeyPress(inChar, inFlags, inVirtualKey);
    return 1; // Возвращаем 1, чтобы позволить другим обработчикам также обрабатывать это событие
}
