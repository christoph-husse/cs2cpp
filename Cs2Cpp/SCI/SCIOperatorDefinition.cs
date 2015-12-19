using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    internal class SCIOperatorDefinition : SCIMethodDefinition
    {
        public bool IsImplicitConversion { get; private set; }

        public SCIOperatorDefinition(SCITypeDefinition parent, Operator source)
            : base(parent, source)
        {
                IsImplicitConversion = source.OperatorType == Operator.OpType.Implicit;
        }
    }
}
