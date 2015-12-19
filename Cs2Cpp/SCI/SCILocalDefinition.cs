using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    internal class SCILocalDefinition
    {
        [NonSerialized]
        private ILocalVariable m_Raw;

        public ILocalVariable Raw { get { return m_Raw; } private set { m_Raw = value; } }
        public String Name { get; private set; }
        public SCITypeHandle Type { get; private set; }
        public SCIMethodDefinition Method { get; private set; }

        public SCILocalDefinition(SCIMethodDefinition parent, dynamic local)
        {
            Method = parent;
            Raw = local;

            if (local.Type != null)
                Type = SCITypeHandle.Wrap(local.Type);
            else
                Type = SCITypeHandle.Wrap(local.TypeExpression);

            Name = parent.NameManager.ImportName(parent.NameManager.UndecorateName(local.Name), Method.Variables.Union(Method.Parameters).Select(e => e.Name));
        }
    }

}
