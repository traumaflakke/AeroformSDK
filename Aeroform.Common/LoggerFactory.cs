using Aeroform.Common.Interfaces;
using System;

namespace Aeroform.Common
{
    public static class LoggerFactory
    {
        private static Func<ILogger> createLogger;

        public static void Initialize(Func<ILogger> factory)
        {
            createLogger = factory ?? throw new ArgumentNullException(nameof(factory));
        }

        public static ILogger GetLogger()
        {
            if (createLogger == null)
            {
                throw new InvalidOperationException("LoggerFactory is not initialized.");
            }
            return createLogger();
        }
    }
}