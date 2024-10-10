using Aeroform.Common.Interfaces;

namespace Aeroform.Core
{
    public class Logger : ILogger
    {
        private readonly IXPlaneDebug xplaneDebug;
        private static string logFilePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "aeroform.log");

        public Logger(IXPlaneDebug xplaneDebug)
        {
            this.xplaneDebug = xplaneDebug;
        }

        public void Log(string message, LogLevel level = LogLevel.Info)
        {
            string logMessage = $"[AEROFORM.Core] [{level}] -> {message}";
            xplaneDebug.DebugString(logMessage + Environment.NewLine);
            File.AppendAllText(logFilePath, logMessage + Environment.NewLine);
        }
    }
}