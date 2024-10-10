namespace Aeroform.Common.Interfaces
{
    public enum LogLevel
    {
        Info,
        Warning,
        Error,
        Debug
    }

    public interface ILogger
    {
        void Log(string message, LogLevel level = LogLevel.Info);
    }
}