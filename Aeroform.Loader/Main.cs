using System.Runtime.InteropServices;
using Aeroform.Common;
using Aeroform.Common.Interfaces;
using Aeroform.Core;
using Aeroform.Unmanaged;
using System.Reflection;

namespace Aeroform.Loader
{
    public static class Main
    {
        private static ModuleLoader loader = null!;
        private static ILogger logger = null!;

        [UnmanagedCallersOnly]
        public static void Initialize()
        {
            try
            {
                var xplaneDebug = new XPlaneDebug();
                LoggerFactory.Initialize(() => new Logger(xplaneDebug));

                logger = LoggerFactory.GetLogger();
                logger.Log("Aeroform.Loader initialization started", LogLevel.Info);

                // Тестовый вывод для проверки перенаправления консоли
                Console.WriteLine("This is a test console output from Aeroform.Loader.Initialize");

                var currentDirectory = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
                logger.Log($"Current directory: {currentDirectory}", LogLevel.Info);

                // Инициализация загрузчика модулей
                loader = new ModuleLoader(currentDirectory!, logger!);

                // Загрузка Common, Core и Unmanaged модулей
                LoadModuleSafely("Aeroform.Common.dll");
                LoadModuleSafely("Aeroform.Core.dll");
                LoadModuleSafely("Aeroform.Unmanaged.dll");

                logger.Log("Aeroform.Loader initialization completed", LogLevel.Info);
            }
            catch (Exception ex)
            {
                if (logger != null)
                {
                    logger.Log($"Error during Aeroform.Loader initialization: {ex}", LogLevel.Error);
                    logger.Log($"Stack trace: {ex.StackTrace}", LogLevel.Error);
                }
                else
                {
                    // Если логгер еще не инициализирован, используем запасной вариант
                    Console.WriteLine($"Critical error during initialization: {ex}");
                    Console.WriteLine($"Stack trace: {ex.StackTrace}");
                }
            }
        }

        private static void LoadModuleSafely(string moduleName)
        {
            try
            {
                var module = loader.LoadModule(moduleName);
                if (module != null)
                {
                    logger.Log($"Module {moduleName} loaded successfully", LogLevel.Info);
                    
                    // Дополнительная проверка инициализации модуля
                    if (module is IAeroformModule aeroformModule)
                    {
                        aeroformModule.Initialize();
                        logger.Log($"Module {moduleName} initialized successfully", LogLevel.Info);
                    }
                    else
                    {
                        logger.Log($"Module {moduleName} does not implement IAeroformModule", LogLevel.Warning);
                    }
                }
                else
                {
                    logger.Log($"Failed to load module {moduleName}", LogLevel.Error);
                }
            }
            catch (Exception ex)
            {
                logger.Log($"Error loading module {moduleName}: {ex}", LogLevel.Error);
                logger.Log($"Stack trace: {ex.StackTrace}", LogLevel.Error);
            }
        }

        [UnmanagedCallersOnly]
        public static void Shutdown()
        {
            try
            {
                logger.Log("Aeroform.Loader shutdown started", LogLevel.Info);

                foreach (var module in loader.GetAllModules())
                {
                    try
                    {
                        loader.UnloadModule(module.Name);
                        logger.Log($"Module {module.Name} unloaded successfully", LogLevel.Info);
                    }
                    catch (Exception ex)
                    {
                        logger.Log($"Error unloading module {module.Name}: {ex}", LogLevel.Error);
                        logger.Log($"Stack trace: {ex.StackTrace}", LogLevel.Error);
                    }
                }

                logger.Log("Aeroform.Loader shutdown completed", LogLevel.Info);
            }
            catch (Exception ex)
            {
                logger.Log($"Error during Aeroform.Loader shutdown: {ex}", LogLevel.Error);
                logger.Log($"Stack trace: {ex.StackTrace}", LogLevel.Error);
            }
        }

        [UnmanagedCallersOnly]
        public static void ReloadModules()
        {
            try
            {
                foreach (var module in loader.GetAllModules())
                {
                    logger.Log($"Reloading module: {module.Name}", LogLevel.Info);

                    try
                    {
                        loader.UnloadModule(module.Name);
                        logger.Log($"Module unloaded: {module.Name}", LogLevel.Info);
                        LoadModuleSafely($"{module.Name}.dll");
                    }
                    catch (Exception ex)
                    {
                        logger.Log($"Error reloading module {module.Name}: {ex}", LogLevel.Error);
                        logger.Log($"Stack trace: {ex.StackTrace}", LogLevel.Error);
                    }
                }
            }
            catch (Exception ex)
            {
                logger.Log($"Error reloading modules: {ex}", LogLevel.Error);
                logger.Log($"Stack trace: {ex.StackTrace}", LogLevel.Error);
            }
        }
    }
}
