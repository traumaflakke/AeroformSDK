namespace Aeroform.Core.Legacy;

using System.Runtime.InteropServices;
public static class Bootstrap
{
    [UnmanagedCallersOnly]
    public static void Initialize()
    {
        Console.Write("▲ Aeroform.Core | DEBUG | Aeroform.Core.Legacy.Bootstrap.Initialize() called");
    }
}