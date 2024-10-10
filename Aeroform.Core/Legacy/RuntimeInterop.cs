using System.Runtime.InteropServices;

namespace Aeroform.Core.Legacy;

public static unsafe class RuntimeInterop
{
    [UnmanagedCallersOnly]
    public static void SetStdOut(delegate* unmanaged[Cdecl]<IntPtr, int, void> callback)
    {
        Console.SetOut(new CallbackTextWriter(callback));
    }

    private class CallbackTextWriter : TextWriter
    {
        private readonly delegate* unmanaged[Cdecl]<IntPtr, int, void> _callback;

        public CallbackTextWriter(delegate* unmanaged[Cdecl]<IntPtr, int, void> callback)
        {
            _callback = callback;
        }

        public override void Write(string? value)
        {
            if (value != null)
            {
                var bytes = System.Text.Encoding.UTF8.GetBytes(value);
                fixed (byte* ptr = bytes)
                {
                    _callback((IntPtr)ptr, bytes.Length);
                }
            }
        }

        public override System.Text.Encoding Encoding => System.Text.Encoding.UTF8;
    }
}