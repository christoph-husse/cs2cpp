using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    internal class SCIEnumMemberDefinition : SCIMemberDefinition
    {
        [NonSerialized]
        private EnumMember m_Raw;

        public new EnumMember Raw { get { return m_Raw; } private set { m_Raw = value; } }
        public bool IsSigned { get; private set; }
        public long Long { get; private set; }
        public ulong ULong { get; private set; }

        public SCIEnumMemberDefinition(SCITypeDefinition parent, EnumMember source)
            : base(parent, source, false)
        {
            Raw = source;

            if ((Raw.Initializer == null) || (Raw.Initializer is Mono.CSharp.Enum.ImplicitInitializer))
            {
                IsSigned = true;

                // value is plus one relative to preceding member
                if (Parent.Members.IsEmpty())
                {
                    Long = 0;
                    ULong = 0;
                }
                else
                {
                    var prev = parent.Members.Last() as SCIEnumMemberDefinition;

                    Long = prev.Long + 1;
                    ULong = prev.ULong + 1;
                }
            }
            else
            {
                var initializer = (ConstInitializer)Raw.Initializer;
                var value = (initializer.Expr as EnumConstant).Child;

                if (value is IntegralConstant)
                {
                    var integral = value as IntegralConstant;
                    Long = integral.GetValueAsLong();
                    ULong = unchecked((ulong)Long);
                    IsSigned = !((integral is ULongConstant) || (integral is UIntConstant) || (integral is UShortConstant) || (integral is ByteConstant));
                }
                else
                    throw new ArgumentException();
            }

            ResolveName();
        }
    }
}
