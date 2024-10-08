#include "ConfigManager.h"
#include <fstream>
#include "LogManager.h"
#include "PluginManager.h"

ConfigManager::ConfigManager(const std::string& configFileName) : configPath(PluginManager::getPluginPath() + configFileName) {}

bool ConfigManager::loadConfig() {
    std::ifstream configFile(configPath);
    if (!configFile.is_open()) {
        LogManager::getInstance().log("Failed to open config file: " + configPath, LogLevel::ERROR);
        return false;
    }

    config = nlohmann::json::parse(configFile, nullptr, false);

    if (config.is_discarded()) {
        LogManager::getInstance().log("Failed to parse config file", LogLevel::ERROR);
        return false;
    }

    LogManager::getInstance().log("Config loaded successfully", LogLevel::INFO);
    return true;
}

std::string ConfigManager::getName() const {
    return config.value("name", std::string(""));
}

std::string ConfigManager::getVersion() const {
    return config.value("version", std::string(""));
}

std::string ConfigManager::getDescription() const {
    return config.value("description", std::string(""));
}

std::string ConfigManager::getAuthor() const {
    return config.value("author", std::string(""));
}

std::string ConfigManager::getLicense() const {
    return config.value("license", std::string(""));
}

std::string ConfigManager::getXPlaneVersion() const {
    return config.value("xplane_version", std::string(""));
}

bool ConfigManager::isLoggingEnabled() const {
    return config.value("settings", nlohmann::json::object()).value("enable_logging", false);
}

bool ConfigManager::isDebugModeEnabled() const {
    return config.value("settings", nlohmann::json::object()).value("debug_mode", false);
}

bool ConfigManager::isAutoUpdateEnabled() const {
    return config.value("settings", nlohmann::json::object()).value("auto_update", false);
}