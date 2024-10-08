#include "BenchmarkManager.h"
#include "LogManager.h"
#include <chrono>
#include <cmath>
#include <random>
#include <vector>
#include <iomanip>
#include <sstream>

BenchmarkManager::BenchmarkManager(LibraryManager& libManager) : libraryManager(libManager) {}

BenchmarkManager::~BenchmarkManager() {}

void BenchmarkManager::runCppBenchmark() {
    LogManager::getInstance().log("Running C++ benchmark", LogLevel::INFO);
    
    // Простой C++ бенчмарк
    auto simpleBenchmarkResult = measureExecutionTime([this]() {
        int x = 0;
        for (int i = 0; i < 1000000; i++) {
            x += i;
        }
        return x;
    }, "C++ simple benchmark");

    // Сложный C++ бенчмарк
    auto complexBenchmarkResult = measureExecutionTime([this]() {
        std::vector<double> data(100000);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1000.0, 1000.0); 

        for (auto& d : data) {
            d = dis(gen);
        }

        double sum = 0.0;
        for (const auto& d : data) {
            sum += std::sqrt(std::abs(d)) * std::sin(d);
        }

        return sum;
    }, "C++ complex benchmark");

    LogManager::getInstance().log("C++ simple benchmark result: " + std::to_string(simpleBenchmarkResult.first) + 
                                  ", Time: " + formatDuration(simpleBenchmarkResult.second), LogLevel::INFO);
    LogManager::getInstance().log("C++ complex benchmark result: " + std::to_string(complexBenchmarkResult.first) + 
                                  ", Time: " + formatDuration(complexBenchmarkResult.second), LogLevel::INFO);
}

void BenchmarkManager::runCSharpBenchmark() {
    LogManager::getInstance().log("Running C# benchmark", LogLevel::INFO);
    
    typedef int (*SimpleBenchmarkFunc)();
    auto simpleBenchmark = reinterpret_cast<SimpleBenchmarkFunc>(libraryManager.getFunction("RunSimpleBenchmark"));
    
    if (simpleBenchmark) {
        auto result = measureExecutionTime([&]() {
            return simpleBenchmark();
        }, "C# simple benchmark");
        
        LogManager::getInstance().log("C# simple benchmark result: " + std::to_string(result.first) + 
                                      ", Time: " + formatDuration(result.second), LogLevel::INFO);
    } else {
        LogManager::getInstance().log("Failed to get C# simple benchmark function", LogLevel::ERROR);
    }
    
    typedef double (*ComplexBenchmarkFunc)();
    auto complexBenchmark = reinterpret_cast<ComplexBenchmarkFunc>(libraryManager.getFunction("RunComplexBenchmark"));
    
    if (complexBenchmark) {
        auto result = measureExecutionTime([&]() {
            return complexBenchmark();
        }, "C# complex benchmark");
        
        LogManager::getInstance().log("C# complex benchmark result: " + std::to_string(result.first) + 
                                      ", Time: " + formatDuration(result.second), LogLevel::INFO);
    } else {
        LogManager::getInstance().log("Failed to get C# complex benchmark function", LogLevel::ERROR);
    }
}

template<typename Func>
std::pair<double, std::chrono::duration<double, std::micro>> BenchmarkManager::measureExecutionTime(Func func, const std::string& benchmarkName) {
    auto start = std::chrono::high_resolution_clock::now();
    auto result = func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> diff = end - start;
    
    return {static_cast<double>(result), diff};
}

std::string BenchmarkManager::formatDuration(const std::chrono::duration<double, std::micro>& duration) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << duration.count() << " microseconds";
    return oss.str();
}