#include "aeroform_common.h"
#include "LogManager.h"
#include "XPLMUtilities.h"
#include <iostream>
#include <ctime>

LogManager* LogManager::instance = nullptr;
std::mutex LogManager::instanceMutex;

LogManager::LogManager() : isInitialized(false) {
    internalLog("LogManager constructor called");
}

LogManager::~LogManager() {
    internalLog("LogManager destructor called");
    shutdown();
}

void LogManager::shutdown() {
    std::lock_guard<std::mutex> lock(logMutex);
    internalLog("LogManager::shutdown() called");
    if (isInitialized.load()) {
        internalLog("Closing log file");
        if (logFile.is_open()) {
            logFile.close();
        }
        logFilePath.clear();
        isInitialized.store(false);
    }
    internalLog("LogManager::shutdown() completed");
}

std::string LogManager::logLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:    return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR:   return "ERROR";
        case LogLevel::DEBUG:   return "DEBUG";
        default:                return "UNKNOWN";
    }
}

void LogManager::internalLog(const std::string& message) {
    std::string formattedMessage = "[AEROFORM_INTERNAL] " + message + "\n";
    XPLMDebugString(formattedMessage.c_str());
}

void LogManager::log(const std::string& message, LogLevel level, bool consoleOutput) {
    std::lock_guard<std::mutex> lock(logMutex);
    if (!isInitialized.load()) {
        internalLog("LogManager not initialized. Message: " + message);
        return;
    }

    std::time_t now = std::time(nullptr);
    char timestamp[20];
    std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    std::string formattedMessage = std::string("[AEROFORM] [") + logLevelToString(level) + "] [" + timestamp + "] " + message + "\n";

    if (consoleOutput) {
        XPLMDebugString(formattedMessage.c_str());
    }

    if (logFile.is_open()) {
        logFile << formattedMessage;
        logFile.flush();
    }
}

LogManager& LogManager::getInstance() {
    std::lock_guard<std::mutex> lock(instanceMutex);
    if (instance == nullptr) {
        instance = new LogManager();
    }
    return *instance;
}

void LogManager::initialize(const std::string& logFilePath) {
    std::lock_guard<std::mutex> lock(logMutex);
    internalLog("LogManager::initialize() called with path: " + logFilePath);
    if (!isInitialized.load()) {
        this->logFilePath = logFilePath;
        logFile.open(logFilePath, std::ios::app);
        if (!logFile.is_open()) {
            internalLog("Failed to open log file: " + logFilePath);
        } else {
            isInitialized.store(true);
            internalLog("Log file opened successfully");
            const char* asciiArt = R"(
=======================================================================
                _                   __                      
               /_\   ___ _ __ ___  / _| ___  _ __ _ __ ___  
              //_\\ / _ \ '__/ _ \| |_ / _ \| '__| '_ ` _ \ 
             /  _  \  __/ | | (_) |  _| (_) | |  | | | | | |
             \_/ \_/\___|_|  \___/|_|  \___/|_|  |_| |_| |_|
                                               
=======================================================================
)";
            XPLMDebugString("\n");
            XPLMDebugString(asciiArt);
            XPLMDebugString("\n");
        }
    }
    internalLog("LogManager::initialize() completed");
}