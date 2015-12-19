using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    internal class SCIEventDefinition : SCIMemberDefinition
    {
        [NonSerialized]
        private Event m_Raw;

        public new Event Raw { get { return m_Raw; } private set { m_Raw = value; } }
        public SCIMethodDefinition Add { get; private set; }
        public SCIMethodDefinition Remove { get; private set; }

        public SCIEventDefinition(SCITypeDefinition parent, Event source)
            : base(parent, source)
        {
            Raw = source;

            if (source.Add != null)
                Add = new SCIMethodDefinition(parent, source.Add);

            if (source.Remove != null)
                Remove = new SCIMethodDefinition(parent, source.Remove);
        }
    }

}
