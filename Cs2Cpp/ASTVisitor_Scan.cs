using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using Mono.CSharp;
using Delegate = Mono.CSharp.Delegate;
using Enum = Mono.CSharp.Enum;

namespace Cs2Cpp
{
    [Serializable]
    class ASTVisitor_Scan : StructuralVisitorAdapter
    {
        [NonSerialized]
        private List<Delegate> m_Delegates = new List<Delegate>();
        [NonSerialized]
        private IEnumerable<IEnumerable<Delegate>> m_DelegatesByNamespace = new IEnumerable<Delegate>[0];

        private readonly List<SCITypeDefinition> m_Enums = new List<SCITypeDefinition>();
        private readonly List<SCITypeDefinition> m_Structs = new List<SCITypeDefinition>();
        private readonly List<SCITypeDefinition> m_Interfaces = new List<SCITypeDefinition>();
        private readonly List<SCITypeDefinition> m_Classes = new List<SCITypeDefinition>();

        private readonly Dictionary<string, SCITypeDefinition> m_NameToType = new Dictionary<string, SCITypeDefinition>();
        private readonly Dictionary<string, SCIMethodDefinition> m_NameToMethod = new Dictionary<string, SCIMethodDefinition>();

        public IEnumerable<Delegate> Delegates { get { return m_Delegates; } }
        public IEnumerable<SCITypeDefinition> Enums { get; private set; }
        public IEnumerable<SCITypeDefinition> Structs { get; private set; }
        public IEnumerable<SCITypeDefinition> Interfaces { get; private set; }
        public IEnumerable<SCITypeDefinition> Classes { get; private set; }
        public IEnumerable<SCITypeDefinition> SICs { get { return Structs.Union(Interfaces.Union(Classes)).ToArray(); } }

        public SCITypeDefinition Object { get; private set; }
        public SCITypeDefinition Delegate { get; private set; }
        public SCITypeDefinition ValueType { get; private set; }
        public SCITypeDefinition EnumType { get; private set; }
        public SCITypeDefinition IEnumerator { get; private set; }
        public SCITypeDefinition IEnumerable { get; private set; }

        public IEnumerable<IEnumerable<Delegate>> DelegatesByNamespace { get { return m_DelegatesByNamespace; } private set { m_DelegatesByNamespace = value; } }
        public IEnumerable<IEnumerable<SCITypeDefinition>> EnumsByNamespace { get; private set; }
        public IEnumerable<IEnumerable<SCITypeDefinition>> StructsByDependency { get; private set; }
        public IEnumerable<IEnumerable<SCITypeDefinition>> InterfacesByInheritence { get; private set; }
        public IEnumerable<IEnumerable<SCITypeDefinition>> ClassesByInheritence { get; private set; }
        public IEnumerable<IEnumerable<SCITypeDefinition>> SICByNamespace { get; private set; }

        public static IEnumerable<IEnumerable<SCITypeDefinition>> GroupTypesByNamespace(IEnumerable<SCITypeDefinition> input)
        {
            return (from e in input
                   group e by e.Namespace into tmp
                   orderby tmp.Key
                   select tmp.ToArray()).ToArray();
        }

        public void Process(ModuleContainer module, Assembly mscorlib)
        {
            m_Delegates.Clear();
            m_Enums.Clear();
            m_Structs.Clear();
            m_Interfaces.Clear();
            m_Classes.Clear();
            m_NameToType.Clear();
            m_NameToMethod.Clear();

            Object = null;
            ValueType = null;

            module.Accept(this);

            m_Delegates = m_Delegates.Distinct().ToList();
            Enums = m_Enums.Distinct().ToArray();
            Structs = m_Structs.Distinct().ToArray();
            Interfaces = m_Interfaces.Distinct().ToArray();
            Classes = m_Classes.Except(new SCITypeDefinition[] { ValueType, Object }).ToList();

            // System.Object and System.ValueType must come before all interfaces&structs!
            if (mscorlib == null)
            {
                ValueType = (from x in Classes where x.BuiltinType == BuiltinTypeSpec.Type.ValueType select x).First();
                EnumType = (from x in Classes where (x.BuiltinType == BuiltinTypeSpec.Type.Enum) && !x.BaseClass.IsEnum select x).First();
                Object = (from x in Classes where x.BuiltinType == BuiltinTypeSpec.Type.Object select x).First();
                Delegate = (from x in Classes where x.BuiltinType == BuiltinTypeSpec.Type.Delegate select x).First();
                IEnumerator = (from x in Interfaces where x.BuiltinType == BuiltinTypeSpec.Type.IEnumerator select x).First();
                IEnumerable = (from x in Interfaces where x.BuiltinType == BuiltinTypeSpec.Type.IEnumerable select x).First();
            }
            else
            {
                ValueType = mscorlib.Metadata.ValueType;
                EnumType = mscorlib.Metadata.EnumType;
                Object = mscorlib.Metadata.Object;
                Delegate = mscorlib.Metadata.Delegate;
                IEnumerator = mscorlib.Metadata.IEnumerator;
                IEnumerable = mscorlib.Metadata.IEnumerable;
            }

            m_Enums.Clear();
            m_Structs.Clear();
            m_Interfaces.Clear();
            m_Classes.Clear();

            // run multi-phase type initialization
            SICs.Apply(e => e.Load_Step2());
            SICs.Apply(e => m_NameToType.Add(e.FullOriginalName, e));

            DelegatesByNamespace = (from e in Delegates group e by e.GetNamespace() into tmp orderby tmp.Key select tmp.ToArray()).ToArray();
            EnumsByNamespace = GroupTypesByNamespace(Enums);
            StructsByDependency = SortByMemberDependencies(Structs);
            InterfacesByInheritence = SortByInheritence(Interfaces);
            ClassesByInheritence = SortByInheritence(Classes);
            SICByNamespace = GroupTypesByNamespace(Classes.Union(Structs.Union(Interfaces)));
        }

        public SCITypeDefinition ResolveImportedType(string originalName)
        {
            SCITypeDefinition def;
            if(!m_NameToType.TryGetValue(originalName, out def))
                throw new ArgumentException("No mapping for type \"" + originalName + "\".");

            return def;
        }

        public SCIMethodDefinition ResolveImportedMethod(ImportedParameterMemberDefinition imported)
        {
            var type = ResolveImportedType(imported.Provider.DeclaringType.FullName);
            SCIMethodDefinition def;

            foreach (var method in type.Methods)
            {
                if (method.OriginalName != imported.Name)
                    continue;

                if (method.Parameters.Count() != imported.Parameters.Count)
                    continue;

                bool matches = true;
                for (int i = 0; i < imported.Parameters.Count;i++ )
                {
                    SCITypeDefinition pType = SCITypeDefinition.Wrap(imported.Parameters.Types[i]);

                    if (method.Parameters.ElementAt(i).Type != pType)
                    {
                        matches = false;
                        break;
                    }
                }

                    if(!matches)
                        continue;

                    return method;
            }

            throw new ArgumentException("No mapping for method \"" + "\".");
        }

        public IEnumerable<IEnumerable<SCITypeDefinition>> SortByMemberDependencies(IEnumerable<SCITypeDefinition> src)
        {
            src = src.Distinct();
            var inheritence = new List<List<SCITypeDefinition>>();
            var normSrc = src.ToList();

            inheritence.Add(normSrc);

            for (; ; )
            {
                var baseClasses = new List<SCITypeDefinition>();

                foreach (var iface in inheritence[0])
                {
                    baseClasses.AddRange(
                        iface.Fields.Select(e => e.Type).Where(f => f.IsDefinition && f.Definition.IsStruct).Select(e => e.Definition));
                }

                baseClasses = baseClasses.Distinct().Intersect(normSrc).ToList();

                if (baseClasses.Count > 0)
                {
                    var superClasses = inheritence[0].Except(baseClasses).ToList();

                    if (superClasses.IsEmpty())
                    {
                        if (baseClasses.Any(e => e.BaseClass.Definition != ValueType))
                            throw new ArgumentException("Cycle in structure definiton.");

                        break;
                    }
                    else
                    {
                        inheritence[0] = superClasses;
                        inheritence.Insert(0, baseClasses);
                    }
                }
                else
                {
                    break;
                }
            }

            /*
             *  There are other structural dependencies that need to be considered. For instance
             *  multiple structures of the same inheritence level could link to each other through
             *  fields without creating a cycle. This is valid but they can not be torn apart by the
             *  previous field based dependency analysis, because they all depend on each other. 
             */

            foreach(var level in inheritence)
            {
                var allInLevel = level.ToArray();
                var ordered = new List<SCITypeDefinition>();

                while(level.Any())
                {
                    foreach (var @struct in allInLevel)
                    {
                        var dependencies = @struct.Fields.Select(e => e.Type).Where(
                            f => f.IsDefinition && f.Definition.IsStruct).
                            Select(e => e.Definition).Distinct().Without(@struct).Intersect(allInLevel);

                        if (!dependencies.Except(ordered).Any())
                        {
                            ordered.Add(@struct);
                            level.Remove(@struct);
                        }
                    }   
                }

                level.Clear();
                level.AddRange(ordered.Distinct());
            }

            return inheritence.Select(GroupTypesByNamespace).Aggregate(
                new List<IEnumerable<SCITypeDefinition>>(),
                (r, g) =>
                {
                    r.AddRange(g);
                    return r;
                }).ToArray();
        }

        /// <summary>
        /// Orders class&ifaces based on their inheritence tree, so that C++ does not
        /// complain when defining them in that order. Afterwards it groups all 
        /// inheritence-equivalent types by namespace, minimizing clutter in the
        /// final header output. This works also in case of nested types, where there
        /// is naturally only one namespace for all of them.
        /// </summary>
        public static IEnumerable<IEnumerable<SCITypeDefinition>> SortByInheritence(IEnumerable<SCITypeDefinition> src)
        {
            var inheritence = new List<List<SCITypeDefinition>> { src.ToList() };

            for (; ; )
            {
                var baseClasses = new List<SCITypeDefinition>();

                foreach (var iface in inheritence[0])
                {
                    baseClasses.AddRange(from e in inheritence[0]
                                         where (e.IsInterface && iface.Implements(e)) || (e.IsClass && iface.IsClass && iface.DerivesFrom(e))
                                         select e);
                }

                if (baseClasses.Count > 0)
                {
                    baseClasses = baseClasses.Distinct().ToList();
                    inheritence[0] = inheritence[0].Except(baseClasses).ToList();
                    inheritence.Insert(0, baseClasses);
                }
                else
                {
                    break;
                }
            }

            return inheritence.Select(GroupTypesByNamespace).Aggregate(new List<IEnumerable<SCITypeDefinition>>(), (r, g) => { r.AddRange(g); return r; });
        }

        public ASTVisitor_Scan()
        {
        }

        public override object Visit(AnonymousMethodStorey storey)
        {
            return null;
        }


        public override object Visit(ModuleContainer.StaticDataContainer member)
        {
            return null;
        }

        public override object Visit(ModuleContainer mod)
        {
            VisitTypeContainer(mod);

            return null;
        }

        public override object Visit(NamespaceContainer ns)
        {
            VisitTypeContainer(ns);

            return null;
        }

        public override object Visit(Delegate @delegate)
        {
            m_Delegates.Add(@delegate);

            return null;
        }

        public override object Visit(Enum @enum)
        {
            m_Enums.Add(SCITypeDefinition.Wrap(@enum));

            return null;
        }

        private void VisitSIC(TypeDefinition sic, IList<SCITypeDefinition> sicList)
        {
            foreach(var member in sic.Members)
            {
                if (member is TypeDefinition)
                    member.Accept(this);
            }

            if (sic.IsPartial)
            {
                // Mono has already merged all partials into one container...
                if (sic.PartialContainer == sic)
                    sicList.Add(SCITypeDefinition.Wrap(sic));
            }
            else
            {
                sicList.Add(SCITypeDefinition.Wrap(sic));
            }
        }

        public override object Visit(Struct @struct)
        {
            VisitSIC(@struct, m_Structs);

            return null;
        }

        public override object Visit(Interface iface)
        {
            VisitSIC(iface, m_Interfaces);

            return null;
        }

        public override object Visit(Class @class)
        {
            VisitSIC(@class, m_Classes);

            return null;
        }
    }
}
