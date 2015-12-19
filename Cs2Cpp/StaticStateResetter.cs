using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cs2Cpp
{
    static class StaticStateResetter
    {
        public static void Reset()
        {
            SCIMethodDefinition.Reset();
            SCITypeDefinition.Reset();
            Assembly.Reset();
        }
    }
}
