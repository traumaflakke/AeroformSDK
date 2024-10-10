using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Loader;
using Aeroform.Common.Interfaces;

namespace Aeroform.Loader
{
    public class ModuleLoader
    {
        private readonly string _baseDirectory;
        private readonly ILogger _logger;
        private readonly Dictionary<string, IAeroformModule> loadedModules;
        private readonly AssemblyLoadContext _sharedContext;

        public ModuleLoader(string baseDirectory, ILogger logger)
        {
            _baseDirectory = Path.GetFullPath(baseDirectory);
            _logger = logger;
            loadedModules = new Dictionary<string, IAeroformModule>();
            _sharedContext = new AssemblyLoadContext("SharedModuleContext", true);
            
            // Load and initialize Aeroform.Common.dll
            LoadCommonAssembly();
        }

        private void LoadCommonAssembly()
        {
            var commonPath = Path.Combine(_baseDirectory, "Aeroform.Common.dll");
            if (File.Exists(commonPath))
            {
                try
                {
                    var assembly = _sharedContext.LoadFromAssemblyPath(commonPath);
                    _logger.Log($"Aeroform.Common.dll loaded successfully from {commonPath}", LogLevel.Info);

                    // Find and instantiate the CommonModule
                    var moduleType = assembly.GetTypes().FirstOrDefault(t => !t.IsAbstract && t.IsPublic && t.Name == "CommonModule");
                    if (moduleType != null)
                    {
                        _logger.Log($"Found CommonModule type: {moduleType.FullName}", LogLevel.Info);
                        var module = InstantiateModule(moduleType);
                        if (module != null)
                        {
                            loadedModules["Aeroform.Common"] = module;
                            module.Initialize();
                            _logger.Log("CommonModule loaded and initialized successfully", LogLevel.Info);
                        }
                    }
                    else
                    {
                        _logger.Log("No valid CommonModule found in Aeroform.Common.dll", LogLevel.Error);
                        _logger.Log($"Available types: {string.Join(", ", assembly.GetTypes().Select(t => t.FullName))}", LogLevel.Info);
                    }
                }
                catch (Exception ex)
                {
                    _logger.Log($"Failed to load Aeroform.Common.dll: {ex}", LogLevel.Error);
                }
            }
            else
            {
                _logger.Log($"Aeroform.Common.dll not found at {commonPath}", LogLevel.Warning);
            }
        }

        public IAeroformModule? LoadModule(string modulePath)
        {
            if (string.IsNullOrEmpty(modulePath))
            {
                throw new ArgumentNullException(nameof(modulePath));
            }

            var fullPath = Path.GetFullPath(Path.Combine(_baseDirectory, modulePath));
            var moduleName = Path.GetFileNameWithoutExtension(fullPath);

            _logger.Log($"Attempting to load module: {moduleName} from {fullPath}", LogLevel.Info);

            if (loadedModules.ContainsKey(moduleName))
            {
                _logger.Log($"Module {moduleName} is already loaded.", LogLevel.Warning);
                return loadedModules[moduleName];
            }

            try
            {
                EnsureFileExists(fullPath);

                Assembly assembly;
                if (moduleName == "Aeroform.Common")
                {
                    // Aeroform.Common is already loaded in the shared context
                    assembly = _sharedContext.Assemblies.FirstOrDefault(a => a.GetName().Name == "Aeroform.Common");
                    if (assembly == null)
                    {
                        throw new InvalidOperationException("Aeroform.Common assembly not found in shared context");
                    }
                }
                else
                {
                    assembly = _sharedContext.LoadFromAssemblyPath(fullPath);
                }
                
                var types = assembly.GetTypes();
                var moduleType = types.FirstOrDefault(t => !t.IsAbstract && t.IsPublic && t.Name.EndsWith("Module"));

                if (moduleType == null)
                {
                    _logger.Log($"No valid public module found in {fullPath}. Skipping.", LogLevel.Info);
                    _logger.Log($"Available types: {string.Join(", ", types.Select(t => t.FullName))}", LogLevel.Info);
                    return null;
                }

                var module = InstantiateModule(moduleType);
                if (module == null)
                {
                    return null;
                }

                loadedModules[moduleName] = module;
                module.Initialize();
                _logger.Log($"Module {moduleName} loaded and initialized successfully", LogLevel.Info);
                return module;
            }
            catch (Exception ex)
            {
                _logger.Log($"Error loading module {moduleName}: {ex}", LogLevel.Error);
                throw;
            }
        }

        private IAeroformModule? InstantiateModule(Type moduleType)
        {
            var constructor = moduleType.GetConstructor(Type.EmptyTypes);
            if (constructor == null)
            {
                _logger.Log($"Module {moduleType.FullName} does not have a parameterless constructor. Skipping.", LogLevel.Error);
                return null;
            }

            try
            {
                var module = constructor.Invoke(null) as IAeroformModule;
                if (module == null)
                {
                    _logger.Log($"Failed to create instance of module {moduleType.FullName} or it does not implement IAeroformModule", LogLevel.Error);
                    return null;
                }
                return module;
            }
            catch (Exception ex)
            {
                _logger.Log($"Error instantiating module {moduleType.FullName}: {ex}", LogLevel.Error);
                return null;
            }
        }

        public void UnloadModule(string moduleName)
        {
            if (!loadedModules.TryGetValue(moduleName, out var module))
            {
                throw new InvalidOperationException($"Module {moduleName} is not loaded.");
            }

            try
            {
                _logger.Log($"Unloading module: {moduleName}", LogLevel.Info);
                module.Shutdown();
                loadedModules.Remove(moduleName);
                _logger.Log($"Module {moduleName} unloaded successfully", LogLevel.Info);
            }
            catch (Exception ex)
            {
                _logger.Log($"Error unloading module {moduleName}: {ex}", LogLevel.Error);
                throw;
            }
        }

        public void ReloadModule(string modulePath)
        {
            var moduleName = Path.GetFileNameWithoutExtension(modulePath);
            UnloadModule(moduleName);
            LoadModule(modulePath);
        }

        public IAeroformModule? GetModule(string moduleName)
        {
            return loadedModules.TryGetValue(moduleName, out var module) ? module : null;
        }

        public IEnumerable<IAeroformModule> GetAllModules()
        {
            return loadedModules.Values;
        }

        private void EnsureFileExists(string path)
        {
            if (!File.Exists(path))
            {
                throw new FileNotFoundException($"Module file not found: {path}");
            }
        }

        public void Dispose()
        {
            foreach (var module in loadedModules.Values)
            {
                module.Shutdown();
            }
            loadedModules.Clear();
            _sharedContext.Unload();
        }
    }
}
