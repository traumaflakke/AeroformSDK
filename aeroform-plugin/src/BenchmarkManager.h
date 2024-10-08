#ifndef BENCHMARK_MANAGER_H
#define BENCHMARK_MANAGER_H

#include <functional>
#include <string>
#include <chrono>
#include "LibraryManager.h"

class BenchmarkManager {
public:
    BenchmarkManager(LibraryManager& libManager);
    ~BenchmarkManager();

    void runCppBenchmark();
    void runCSharpBenchmark();

private:
    LibraryManager& libraryManager;

    template<typename Func>
    std::pair<double, std::chrono::duration<double, std::micro>> measureExecutionTime(Func func, const std::string& benchmarkName);
    
    std::string formatDuration(const std::chrono::duration<double, std::micro>& duration);
};

#endif // BENCHMARK_MANAGER_H