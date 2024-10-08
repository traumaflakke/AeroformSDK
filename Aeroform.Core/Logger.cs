using Aeroform.Unmanaged.XPLMBindings;

namespace Aeroform.Core;

public enum LogLevel
{
    Info,
    Warning,
    Error,
    Debug
}

public class Logger
{
    private static string logFilePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "aeroform.log");

    private static string GetLogLevelString(LogLevel level) {
        return level switch {
            LogLevel.Info => "INFO",
            LogLevel.Warning => "WARNING",
            LogLevel.Error => "ERROR",
            LogLevel.Debug => "DEBUG",
            _ => "UNKNOWN"
        };
    }

    public static void Log(string message, LogLevel level = LogLevel.Info)
    {
        try {
            XPlaneWrappers.XPLMDebugString($"[Aeroform.Core] [{GetLogLevelString(level)}] {message}{Environment.NewLine}");
            File.AppendAllText(logFilePath, $"[Aeroform.Core] [{GetLogLevelString(level)}] {message}{Environment.NewLine}");
        } catch (Exception e) {
            File.AppendAllText(logFilePath, $"[Aeroform.Core] [{GetLogLevelString(level)}] {message}{Environment.NewLine}");
        }
    }
}
