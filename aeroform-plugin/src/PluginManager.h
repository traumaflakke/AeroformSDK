#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include "LibraryManager.h"
#include "BenchmarkManager.h"
#include "ConfigManager.h"
#include "RuntimeManager.h"
#include "XPLMDefs.h"

#include <string>

class PluginManager {
public:
    static PluginManager& getInstance() {
        static PluginManager instance;
        return instance;
    }

    bool initialize();
    void shutdown();
    int start(char* outName, char* outSig, char* outDesc);
    void stop();
    void enable();
    void disable();
    void receiveMessage(int inMessage, void* inParam);    

    static std::string getPluginPath();

    // Добавляем метод для обработки клавиш
    void onKeyPress(char key, XPLMKeyFlags flags, char virtualKey);

    // Статический метод обратного вызова для XPLMRegisterKeySniffer
    static int keySnifferCallback(char inChar, XPLMKeyFlags inFlags, char inVirtualKey, void* inRefcon);

    // Сделаем конструктор и деструктор публичными
    PluginManager();
    ~PluginManager();

private:
    PluginManager(const PluginManager&) = delete;
    PluginManager& operator=(const PluginManager&) = delete;

    LibraryManager libraryManager;
    BenchmarkManager benchmarkManager;
    ConfigManager configManager;
    RuntimeManager& runtimeManager;
};

#endif // PLUGIN_MANAGER_H