using Aeroform.Common.Interfaces;
using Aeroform.Unmanaged.XPLMBindings;

namespace Aeroform.Unmanaged
{
    public class XPlaneDebug : IXPlaneDebug
    {
        public void DebugString(string message)
        {
            XPlaneWrappers.XPLMDebugString(message);
        }
    }
}