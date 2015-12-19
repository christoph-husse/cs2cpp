using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using Cs2Cpp;
using Mono.CSharp;

namespace UnitTests
{
    class Program
    {
        static void Main(string[] args)
        {
            //Demo.Testing.Run(args);

            var compiler = new CompilationFramework(@"../../../build-environment", @"../../../UnitTest/mscorelib.dll/");
            compiler.DevelopmentMode = args.Contains("-dev-mode");
            compiler.Compile(@"../../../UnitTest/tests/arrays");
        }
    }
}
