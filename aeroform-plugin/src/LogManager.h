#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <string>
#include <fstream>
#include <mutex>
#include <atomic>

enum class LogLevel {
    INFO,
    WARNING,
    ERROR,
    DEBUG
};

class LogManager {
public:
    static LogManager& getInstance();

    void initialize(const std::string& logFilePath);
    void shutdown();
    void log(const std::string& message, LogLevel level = LogLevel::INFO, bool consoleOutput = true, bool isClean = false);

    LogManager(const LogManager&) = delete;
    LogManager& operator=(const LogManager&) = delete;

private:
    LogManager();
    ~LogManager();

    static LogManager* instance;
    static std::mutex instanceMutex;
    std::mutex logMutex;

    std::ofstream logFile;
    std::atomic<bool> isInitialized;
    std::string logFilePath;

    std::string logLevelToString(LogLevel level);
    void internalLog(const std::string& message);
};

#endif // LOG_MANAGER_H