using System;
using System.Runtime.InteropServices;

public static unsafe class RuntimeInterop
{
    [UnmanagedCallersOnly]
    public static void SetStdOut(IntPtr callback)
    {
        Console.SetOut(new CallbackTextWriter(callback));
    }

    private class CallbackTextWriter : TextWriter
    {
        private readonly delegate* unmanaged[Cdecl]<IntPtr, int, void> _callback;

        public CallbackTextWriter(IntPtr callback)
        {
            _callback = (delegate* unmanaged[Cdecl]<IntPtr, int, void>)callback;
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