#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>
#include <nlohmann/json.hpp>

class ConfigManager {
public:
    ConfigManager(const std::string& configPath);
    
    bool loadConfig();
    
    std::string getName() const;
    std::string getVersion() const;
    std::string getDescription() const;
    std::string getAuthor() const;
    std::string getLicense() const;
    std::string getXPlaneVersion() const;
    
    bool isLoggingEnabled() const;
    bool isDebugModeEnabled() const;
    bool isAutoUpdateEnabled() const;

private:
    std::string configPath;
    nlohmann::json config;
};

#endif // CONFIG_MANAGER_H