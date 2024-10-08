#include "aeroform_common.h"
#include "LibraryManager.h"
#include "LogManager.h"
#include "XPLMPlugin.h"
#include <stdexcept>
#include <algorithm>
#include "PluginManager.h"
#include "xplane_api.h"
#include "aeroform_api.h"

typedef void (*InitializeAeroformFunc)(XPlaneAPI*, AeroformAPI*);
InitializeAeroformFunc initializeAeroform = nullptr;

LibraryManager::LibraryManager() : libHandle(nullptr) {
    LogManager::getInstance().log("LibraryManager constructed", LogLevel::DEBUG);
}

LibraryManager::~LibraryManager() {
    LogManager::getInstance().log("LibraryManager destructor called", LogLevel::DEBUG);
    unloadLibrary();
}

bool LibraryManager::loadLibrary() {
    const char* libraryName = AEROFORM_BRIDGE_LIB_FILENAME;

    LogManager::getInstance().log("Attempting to load library: " + std::string(libraryName), LogLevel::DEBUG);
    
    std::string path = PluginManager::getPluginPath() + libraryName;
    
    LogManager::getInstance().log("Attempting to load library from: " + path, LogLevel::DEBUG);
    
    {
        std::lock_guard<std::mutex> lock(libMutex);
        libHandle = AEROFORM_LOAD_LIBRARY(path.c_str());
        if (!libHandle) {
            const char* errorMsg = AEROFORM_LIBRARY_ERROR;
            if (errorMsg)
                LogManager::getInstance().log("Failed to load library: " + path + "\nError: " + errorMsg, LogLevel::ERROR);
            else 
                LogManager::getInstance().log("Failed to load library: " + path, LogLevel::ERROR);
            return false;
        }
    }

    LogManager::getInstance().log("Successfully loaded library: " + path, LogLevel::INFO);

    LogManager::getInstance().log("Attempting to get InitializeAeroform function", LogLevel::DEBUG);
    initializeAeroform = (InitializeAeroformFunc)getFunction("InitializeAeroform");

    if (initializeAeroform) {
        LogManager::getInstance().log("Successfully got InitializeAeroform function", LogLevel::DEBUG);

        LogManager::getInstance().log("Filling XPlaneAPI structure", LogLevel::DEBUG);       
        XPlaneAPI xplaneApi;
        AeroformAPI aeroformApi;
        FillXPlaneAPI(&xplaneApi);
        FillAeroformAPI(&aeroformApi);
        
        LogManager::getInstance().log("Calling InitializeAeroform function", LogLevel::DEBUG);
        initializeAeroform(&xplaneApi, &aeroformApi);
        LogManager::getInstance().log("InitializeAeroform function called successfully", LogLevel::INFO);
    } else {
        LogManager::getInstance().log("Failed to get InitializeAeroform function", LogLevel::ERROR);
        return false;
    }

    return true;
}

void LibraryManager::unloadLibrary() {
    std::lock_guard<std::mutex> lock(libMutex);
    if (libHandle) {
        LogManager::getInstance().log("Unloading library", LogLevel::DEBUG);
        AEROFORM_FREE_LIBRARY(libHandle);
        libHandle = nullptr;
        LogManager::getInstance().log("Library unloaded", LogLevel::INFO);
    }
}

void* LibraryManager::getFunction(const std::string& functionName) {
    std::lock_guard<std::mutex> lock(libMutex);
    
    if (!libHandle) {
        LogManager::getInstance().log("Attempt to get function from unloaded library: " + functionName, LogLevel::ERROR);
        return nullptr;
    }

    void* func = AEROFORM_GET_PROC_ADDRESS(libHandle, functionName.c_str());
    if (!func) {
        LogManager::getInstance().log("Failed to get function: " + functionName, LogLevel::ERROR);
    } else {
        LogManager::getInstance().log("Successfully got function: " + functionName, LogLevel::DEBUG);
    }
    return func;
}

bool LibraryManager::LoadPluginFunctions() {
    pluginStop = (PluginStopFunc)getFunction("PluginStop");
    pluginEnable = (PluginEnableFunc)getFunction("PluginEnable");
    pluginDisable = (PluginDisableFunc)getFunction("PluginDisable");
    pluginReceiveMessage = (PluginReceiveMessageFunc)getFunction("PluginReceiveMessage");

    return pluginStop && pluginEnable && pluginDisable && pluginReceiveMessage;
}

void LibraryManager::CallPluginStop() {
    if (pluginStop) pluginStop();
}

int LibraryManager::CallPluginEnable() {
    return pluginEnable ? pluginEnable() : 0;
}

void LibraryManager::CallPluginDisable() {
    if (pluginDisable) pluginDisable();
}

void LibraryManager::CallPluginReceiveMessage(int inMessage, void* inParam) {
    if (pluginReceiveMessage) pluginReceiveMessage(inMessage, inParam);
}