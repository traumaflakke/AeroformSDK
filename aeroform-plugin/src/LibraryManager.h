#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include <string>
#include <mutex>

class LibraryManager {
public:
    LibraryManager();
    ~LibraryManager();

    bool loadLibrary();
    void unloadLibrary();
    void* getFunction(const std::string& functionName);

    typedef void (*PluginStopFunc)();
    typedef int (*PluginEnableFunc)();
    typedef void (*PluginDisableFunc)();
    typedef void (*PluginReceiveMessageFunc)(int, void*);

    bool LoadPluginFunctions();
    int CallPluginStart(char* outName, char* outSig, char* outDesc);
    void CallPluginStop();
    int CallPluginEnable();
    void CallPluginDisable();
    void CallPluginReceiveMessage(int inMessage, void* inParam);

private:
    void* libHandle;
    std::mutex libMutex;

    PluginStopFunc pluginStop;
    PluginEnableFunc pluginEnable;
    PluginDisableFunc pluginDisable;
    PluginReceiveMessageFunc pluginReceiveMessage;
};

#endif // LIBRARY_MANAGER_H