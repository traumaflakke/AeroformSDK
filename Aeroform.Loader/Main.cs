using Aeroform.Core;
using System.Runtime.InteropServices;

namespace Aeroform.Loader;

public class Main
{
    [UnmanagedCallersOnly]
    public static void Initialize()
    {
        try
        {
            Logger.Log("Initialized Aeroform.Loader");
        }
        catch (Exception ex)
        {
            Logger.Log($"Error during initialization: {ex.Message}");
            Logger.Log($"StackTrace: {ex.StackTrace}");
        }
    }
}

