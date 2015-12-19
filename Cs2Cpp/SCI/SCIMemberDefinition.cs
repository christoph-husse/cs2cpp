using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    internal class SCIMemberDefinition
    {
        protected String m_Name;
        [NonSerialized]
        private MemberCore m_Raw;

        public MemberCore Raw { get { return m_Raw; } private set { m_Raw = value; } }

        public NameManager NameManager { get { return Assembly.NameManager; } }
        public Assembly Assembly { get; private set; }
        public String FullName { get; protected set; }
        public String Name { get { if(m_Name == null) throw new InvalidOperationException(); return m_Name; } }
        public String OriginalName { get; protected set; }
        public SCITypeDefinition Parent { get; private set; }

        public SCIMemberDefinition(SCITypeDefinition parent, MemberCore source, bool resolveName = true, string prefix = "")
        {
            Assembly = Assembly.Resolve(source);
            Parent = parent;
            Raw = source;
            OriginalName = Raw.MemberName.Basename;

            if (resolveName)
                ResolveName(prefix);
        }

        public bool HasAttribute(Type type)
        {
            return Raw.Attributes.Any(
                e =>
                {
                    var name = e.Expr as SimpleName;
                    if (name == null)
                        return false;

                    return name.Name == "Flags";
                });
        }

        protected void ResolveName(String prefix = "")
        {
            var method = this as SCIMethodDefinition;

            int i = 2;
            string undecorated = NameManager.UndecorateName(Raw.MemberName.Basename);
            string name = undecorated;

            while (Parent.HasMember(name) || SCITypeDefinition.HasType(name))
            {
                name = undecorated + (i++);
            }

            if (method != null)
            {
                if (method.IsConstructor)
                    name = (method.IsStatic ? "static_" : "") + "constructor";

                if (method.IsFinalizer)
                    name = "~" + Parent.Name;
            }

            m_Name = name;
            FullName = Parent.FullName + "::" + name;

            Parent.AddMember(this);
        }

        public override string ToString()
        {
            return FullName;
        }
    }
}
