using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    internal class SCIFieldDefinition : SCIMemberDefinition
    {
        [NonSerialized]
        private FieldBase m_Raw;

        public new FieldBase Raw { get { return m_Raw; } private set { m_Raw = value; } }
        public SCITypeHandle Type { get; private set; }

        public bool IsStatic { get; private set; }
        public bool IsConst { get; private set; }
        public bool IsRecursive { get; private set; }
        public String ConstExpression { get; private set; }

        public SCIFieldDefinition(SCITypeDefinition parent, FieldBase source)
            : base(parent, source)
        {
            Raw = source;
            Type = SCITypeHandle.Wrap(Raw.MemberType);
            IsStatic = Raw.IsStatic;
            IsConst = Raw is Const;
            IsRecursive = (Type == Parent.Handle) && !parent.IsClass && !IsConst;

            if (IsConst)
            {
                // immediately evaluate constant expression, since we potentially need this in a 
                // snapshot file and "Raw" won't be serialized.
                var emitter = new ASTVisitor_Shared(Assembly,Assembly, false);
                using (NameManager.EnterType(Parent))
                {
                    ((Raw as Const).Initializer).Accept(emitter);
                }
                ConstExpression = emitter.CodeWriterState.Builder.ToString();
            }
        }
    }

}
