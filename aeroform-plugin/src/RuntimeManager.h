#ifndef RUNTIME_MANAGER_H
#define RUNTIME_MANAGER_H

#include <string>
#include <memory>

class RuntimeManager {
public:
    static RuntimeManager& getInstance() {
        static RuntimeManager instance;
        return instance;
    }

    bool initialize(const std::string& runtimeConfigPath, const std::string& dllPath);
    //bool reload();
    bool reinitialize();
    void shutdown();
    bool reloadAssembly();
    void* getFunction(const std::string& typeName, const std::string& methodName);

private:
    RuntimeManager();
    ~RuntimeManager();
    RuntimeManager(const RuntimeManager&) = delete;
    RuntimeManager& operator=(const RuntimeManager&) = delete;

    bool load_hostfxr();

    class Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif // RUNTIME_MANAGER_H