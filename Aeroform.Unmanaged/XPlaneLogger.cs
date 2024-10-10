using Aeroform.Common.Interfaces;
using Aeroform.Unmanaged.XPLMBindings;

namespace Aeroform.Unmanaged
{
    public class XPlaneLogger : ILogger
    {
        public void Log(string message, LogLevel level = LogLevel.Info)
        {
            string formattedMessage = $"[AEROFORM] [{level}] {message}";
            XPlaneWrappers.XPLMDebugString(formattedMessage);
        }
    }
}
