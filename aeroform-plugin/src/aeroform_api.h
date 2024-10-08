#ifndef AEROFORM_API_H
#define AEROFORM_API_H

#include <stdint.h>
#include "LogManager.h"
#include "PluginManager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*LogDebugDelegate)(const char* message);
typedef void (*LogInfoDelegate)(const char* message);
typedef void (*LogWarningDelegate)(const char* message);
typedef void (*LogErrorDelegate)(const char* message);
typedef const char* (*GetPluginPathDelegate)();

struct AeroformAPI {
    LogDebugDelegate logDebug;
    LogInfoDelegate logInfo;
    LogWarningDelegate logWarning;
    LogErrorDelegate logError;
    GetPluginPathDelegate getPluginPath;
};

void FillAeroformAPI(AeroformAPI* api) {
    api->logDebug = [](const char* message) { LogManager::getInstance().log(message, LogLevel::DEBUG); };
    api->logInfo = [](const char* message) { LogManager::getInstance().log(message, LogLevel::INFO); };
    api->logWarning = [](const char* message) { LogManager::getInstance().log(message, LogLevel::WARNING); };
    api->logError = [](const char* message) { LogManager::getInstance().log(message, LogLevel::ERROR); };

    api->getPluginPath = []() -> const char* { return PluginManager::getPluginPath().c_str(); };
}

#ifdef __cplusplus
}
#endif

#endif // AEROFORM_API_H