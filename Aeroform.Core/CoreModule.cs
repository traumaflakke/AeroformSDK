using Aeroform.Common;
using Aeroform.Common.Interfaces;
using System;

namespace Aeroform.Core
{
    public class CoreModule : IAeroformModule
    {
        private readonly ILogger _logger;

        public string Name => "Aeroform.Core";
        public Version Version => new Version(1, 0, 0);

        public CoreModule()
        {
            _logger = LoggerFactory.GetLogger() ?? throw new ArgumentNullException(nameof(_logger));
        }

        public void Initialize()
        {
            _logger.Log($"Initializing {Name} module", LogLevel.Info);
            // Инициализация основных компонентов
        }

        public void Shutdown()
        {
            _logger.Log($"Shutting down {Name} module", LogLevel.Info);
            // Очистка ресурсов
        }
    }
}
