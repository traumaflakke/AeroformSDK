using Aeroform.Common.Interfaces;
using System;

namespace Aeroform.Common
{
    public class CommonModule : IAeroformModule
    {
        public string Name => "Aeroform.Common";
        public Version Version => new Version(1, 0, 0);

        public CommonModule()
        {
            Console.WriteLine("CommonModule constructor");
        }

        public void Initialize()
        {
            
        }

        public void Shutdown()
        {

        }
    }
}
