using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    internal class SCIPropertyDefinition : SCIMemberDefinition
    {
        [NonSerialized]
        private PropertyBase m_Raw;

        public new PropertyBase Raw { get { return m_Raw; } private set { m_Raw = value; } }
        public SCIMethodDefinition Getter { get; private set; }
        public SCIMethodDefinition Setter { get; private set; }
        public bool HasGetter { get { return Getter != null; } }
        public bool HasSetter { get { return Setter != null; } }

        public SCIPropertyDefinition(SCITypeDefinition parent, PropertyBase source)
            : base(parent, source)
        {
            Raw = source;

            if (source.Get != null)
                Getter = new SCIMethodDefinition(parent, this, (PropertyBase.GetMethod)source.Get);

            if (source.Set != null)
                Setter = new SCIMethodDefinition(parent, this, (PropertyBase.SetMethod)source.Set);
        }
    }

}
