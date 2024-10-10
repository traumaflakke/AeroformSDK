using Aeroform.Common;
using Aeroform.Common.Interfaces;
using System;

namespace Aeroform.Unmanaged
{
    public class UnmanagedModule : IAeroformModule
    {
        private readonly ILogger _logger;

        public string Name => "Aeroform.Unmanaged";
        public Version Version => new Version(1, 0, 0);

        public UnmanagedModule()
        {
            _logger = LoggerFactory.GetLogger() ?? throw new ArgumentNullException(nameof(_logger));
        }

        public void Initialize()
        {
            _logger.Log($"Initializing {Name} module", LogLevel.Info);
            // Инициализация компонентов для работы с неуправляемым кодом
        }

        public void Shutdown()
        {
            _logger.Log($"Shutting down {Name} module", LogLevel.Info);
            // Очистка ресурсов, освобождение неуправляемых ресурсов
        }
    }
}
