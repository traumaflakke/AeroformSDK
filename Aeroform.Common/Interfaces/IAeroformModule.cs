using System;

namespace Aeroform.Common.Interfaces;

public interface IAeroformModule
{
    void Initialize();
    void Shutdown();
    string Name { get; }
    Version Version { get; }
}
