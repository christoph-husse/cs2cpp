using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MS.Internal.Xml.XPath;
using Mono.CSharp;
using Delegate = Mono.CSharp.Delegate;

namespace Cs2Cpp
{
    [Serializable]
    class SCIDefinition
    {
        private readonly static Dictionary<object, SCIDefinition> s_TypeMappings = new Dictionary<object, SCIDefinition>();
        private readonly static HashSet<String> s_TypeNamesCheck = new HashSet<String>();

        public static void Reset()
        {
            // reset all static state
            s_TypeMappings.Clear();
            s_TypeNamesCheck.Clear();
        }

        [NonSerialized]
        private TypeDefinition m_Raw;

        private readonly Dictionary<SCIMethodHandle, SCIMethodHandle> m_InterfaceProxies = new Dictionary<SCIMethodHandle, SCIMethodHandle>();
        [NonSerialized]
        private readonly Dictionary<MemberCore, SCIMemberDefinition> m_MemberMapping = new Dictionary<MemberCore, SCIMemberDefinition>();
        private readonly SCIMemberQueryable<SCIMemberDefinition> m_Members = new SCIMemberQueryable<SCIMemberDefinition>();
        private readonly SCIMemberQueryable<SCIFieldDefinition> m_Fields = new SCIMemberQueryable<SCIFieldDefinition>();
        private readonly SCIMemberQueryable<SCIEventDefinition> m_Events = new SCIMemberQueryable<SCIEventDefinition>();
        private readonly SCIMemberQueryable<SCIMethodDefinition> m_Methods = new SCIMemberQueryable<SCIMethodDefinition>();
        private readonly SCIMemberQueryable<SCIPropertyDefinition> m_Properties = new SCIMemberQueryable<SCIPropertyDefinition>();
        private readonly SCIMemberQueryable<SCIOperatorDefinition> m_Operators = new SCIMemberQueryable<SCIOperatorDefinition>();
        private readonly SCITypeQueryable<SCITypeHandle> m_NewInterfaces = new SCITypeQueryable<SCITypeHandle>();
        private readonly SCITypeQueryable<SCITypeHandle> m_ReimplementedInterfaces = new SCITypeQueryable<SCITypeHandle>();
        private readonly SCITypeQueryable<SCITypeHandle> m_AllInterfaces = new SCITypeQueryable<SCITypeHandle>();
        private readonly SCITypeQueryable<SCITypeHandle> m_AllBaseClasses = new SCITypeQueryable<SCITypeHandle>();
        private bool m_HasReachedStep2;

        internal TypeDefinition Raw { get { return m_Raw; } private set { m_Raw = value; } }
        protected TypeSpec Spec { get { return Raw.Definition; } }

        public NameManager NameManager { get { return Assembly.NameManager; } }
        public Assembly Assembly { get; private set; }
        public String FullName { get; private set; }
        public String FullOriginalName { get; private set; }
        public String Name { get; private set; }
        public SCIMethodDefinition MainMethod { get; private set; }
        public String Namespace { get; private set; }
        public String[] NamespaceParts { get; private set; }
        public SCITypeHandle Handle { get; private set; }

        public BuiltinTypeSpec.Type BuiltinType { get { return Raw.CurrentType.BuiltinType; } }

        /// <summary>
        /// In case of a nested class, <see cref="Parent"/> will hold the type in which
        /// this type is defined.
        /// </summary>
        public SCIDefinition EnclosingType { get; private set; }

        public ISCITypeQueryable<SCITypeHandle> NewInterfaces { get { return m_NewInterfaces; } }
        public ISCITypeQueryable<SCITypeHandle> ReimplementedInterfaces { get { return m_ReimplementedInterfaces; } }
        public ISCITypeQueryable<SCITypeHandle> AllInterfaces { get { return m_AllInterfaces; } }
        public SCITypeHandle BaseClass { get; private set; }
        public ISCITypeQueryable<SCITypeHandle> AllBaseClasses { get { return m_AllBaseClasses; } }

        public ISCIMemberQueryable<SCIMemberDefinition> Members { get { Load_Step2(); return m_Members; } }
        public ISCIMemberQueryable<SCIFieldDefinition> Fields { get { Load_Step2(); return m_Fields; } }
        public ISCIMemberQueryable<SCIEventDefinition> Events { get { Load_Step2(); return m_Events; } }
        public ISCIMemberQueryable<SCIMethodDefinition> Methods { get { Load_Step2(); return m_Methods; } }
        public ISCIMemberQueryable<SCIPropertyDefinition> Properties { get { Load_Step2(); return m_Properties; } }
        public ISCIMemberQueryable<SCIOperatorDefinition> Operators { get { Load_Step2(); return m_Operators; } }
        public IDictionary<SCIMethodHandle, SCIMethodHandle> InterfaceProxies { get { return m_InterfaceProxies; } } 

        public bool IsInterface { get { return Raw is Interface; } }
        public bool IsAbstract { get { return ((Raw.ModFlags & Modifiers.ABSTRACT) != 0) || IsInterface; } }
        public bool IsStruct { get { return Raw is Struct; } }
        public bool IsClass { get { return (Raw is Class) || (Raw is Delegate) || (Raw is HoistedStoreyClass); } }
        public bool IsBuiltinType { get { return GetBuiltinName() != null; } }
        public bool IsDelegate { get { return (BuiltinType == BuiltinTypeSpec.Type.Delegate) || AllBaseClasses.Any(e => e.Definition.BuiltinType == BuiltinTypeSpec.Type.Delegate); } }
        public bool IsEnum { get { return AllBaseClasses.Any(e => e.Definition.BuiltinType == BuiltinTypeSpec.Type.Enum); } }
        public bool IsVoid { get { return (BuiltinType == BuiltinTypeSpec.Type.Other) && (Name == "Void"); } }
        /// <summary>
        /// Does this type have generic parameters or arguments?
        /// </summary>
        public bool IsGeneric { get { return HasParentScopeTypeArguments || HasTypeParameters; } }

        public bool HasTypeParameters { get { return !TypeParameters.IsEmpty(); } }
        public bool HasParentScopeTypeArguments { get { return !TypeArgumentsOfParentScope.IsEmpty(); } }
        /// <summary>
        /// This
        /// </summary>
        public IEnumerable<SCITypeHandle> TypeArgumentsOfParentScope { get; private set; }
        public IEnumerable<SCITypeHandle> TypeParametersOfParentScope { get; private set; }
        public IEnumerable<SCITypeHandle> AllTypeParameters {
            get { return TypeArgumentsOfParentScope.Concat(TypeParameters); }
        }

        /// <summary>
        /// Type parameters needed to instanciate this type.
        /// </summary>
        public IEnumerable<SCITypeHandle> TypeParameters { get; private set; }

        public IEnumerable<SCITypeHandle> DelegateParameterTypes { get; private set; }
        public SCITypeHandle DelegateReturnType { get; private set; }

        public static SCIDefinition Wrap(TypeDefinition def)
        {
            SCIDefinition res;

            if (s_TypeMappings.TryGetValue(def, out res))
                return res;

            return new SCIDefinition(def);
        }

        public static SCIDefinition Wrap(ITypeDefinition def_)
        {
            return Wrap((TypeDefinition)def_);
        }

        public static SCIDefinition Wrap(TypeSpec spec)
        {
            SCIDefinition res;

            if (spec.MemberDefinition is ImportedTypeDefinition)
            {
                var imported = (ImportedTypeDefinition)spec.MemberDefinition;

                if (s_TypeMappings.TryGetValue(imported, out res))
                    return res;

                var assembly = Cs2Cpp.Assembly.Resolve(imported.DeclaringAssembly);
                res = assembly.NameManager.Context.OriginalNameToType(imported.Namespace + "." + imported.Name);

                s_TypeMappings.Add(imported, res);
                return res;
            }
            else
            {
                var def = (TypeDefinition) spec.MemberDefinition;

                if (s_TypeMappings.TryGetValue(def, out res))
                    return res;

                return new SCIDefinition(def);
            }
        }

        public bool HasMember(String name)
        {
            return Members.Contains(name) || ((BaseClass != null) && BaseClass.Definition.Members.Contains(name));
        }

        public void AddMember(SCIMemberDefinition member)
        {
            m_Members.Add(member);
            m_MemberMapping.Add(member.Raw, member);

            if(member is SCIFieldDefinition) m_Fields.Add((SCIFieldDefinition)member);
            if (member is SCIEventDefinition) m_Events.Add((SCIEventDefinition)member);
            if (member is SCIOperatorDefinition) m_Operators.Add((SCIOperatorDefinition)member);
            if (member is SCIPropertyDefinition) m_Properties.Add((SCIPropertyDefinition)member);
            if (member is SCIMethodDefinition) m_Methods.Add((SCIMethodDefinition)member);
        }

        public SCIMemberDefinition ResolveMember(String member)
        {
            var res = m_Members.FirstOrDefault(e => e.OriginalName == member);

            if (res != null)
                return res;

            return BaseClass.Definition.ResolveMember(member);
        }

        public SCIMemberDefinition ResolveMember(MemberCore member)
        {
            return m_MemberMapping[member];
        }

        public bool Implements(SCITypeHandle iface)
        {
            if(!iface.Definition.IsInterface)
                throw new ArgumentException();

            return AllInterfaces.Any(e => e == iface);
        }

        public bool DerivesFrom(SCITypeHandle type)
        {
            if (!IsClass || !type.Definition.IsClass)
                throw new ArgumentException();

            return AllBaseClasses.Any(e => e == type);
        }

        public bool DerivesFrom(BuiltinTypeSpec.Type type)
        {
            return AllBaseClasses.Any(e => e.Definition.BuiltinType == type);
        }

        private SCIDefinition(TypeDefinition source)
        {
            Assembly = Cs2Cpp.Assembly.Resolve(source);
            Raw = source;

            ImportType();

            /*
             * Shall not do any operation that relies on other type's information.
             */

            // collect all inherited interfaces and base classes
            var allBaseIfaces = new List<TypeSpec>();
            var baseClasses = new List<SCITypeHandle>();
            var list = Raw.BaseType;

            while (list != null)
            {
                if (list.Interfaces != null)
                    allBaseIfaces.AddRange(list.Interfaces);

                baseClasses.Add(SCITypeHandle.Wrap(list));

                if (BaseClass == null)
                    BaseClass = SCITypeHandle.Wrap(list);

                list = list.BaseType;
            }

            EnrichInterfaceList(allBaseIfaces);

            // collect all indirectly inherited interfaces
            var newIfaces = new List<TypeSpec>(Raw.Interfaces ?? new TypeSpec[0]);
            EnrichInterfaceList(newIfaces);

            m_NewInterfaces = new SCITypeQueryable<SCITypeHandle>(newIfaces.Except(allBaseIfaces).Select(SCITypeHandle.Wrap));
            m_ReimplementedInterfaces = new SCITypeQueryable<SCITypeHandle>(newIfaces.Select(SCITypeHandle.Wrap));
            m_AllBaseClasses = new SCITypeQueryable<SCITypeHandle>(baseClasses);
            m_AllInterfaces = new SCITypeQueryable<SCITypeHandle>(allBaseIfaces.Select(SCITypeHandle.Wrap).Union(NewInterfaces));

            if (Spec.DeclaringType != null)
                EnclosingType = Wrap(Spec.DeclaringType);

            TypeArgumentsOfParentScope = Spec.GetTypeArgumentsOfParentScope().Select(SCITypeHandle.Wrap).ToArray();
            TypeParametersOfParentScope = Spec.GetTypeParametersOfParentScope().Select(SCITypeHandle.Wrap).ToArray();

            if (Raw.CurrentTypeParameters != null)
                TypeParameters = ((ITypeDefinition)Raw).TypeParameters.Select(SCITypeHandle.Wrap).ToArray();
            else
                TypeParameters = new SCITypeHandle[0];

            Handle = new SCITypeHandle(Spec, this);

            if ((source as Delegate) != null)
            {
                var del = source as Delegate;
                DelegateReturnType = SCITypeHandle.Wrap(del.MemberType);
                DelegateParameterTypes = del.Parameters.FixedParameters.Select(
                    e =>
                    {
                        var param = (Parameter) e;
                        if (param.Type != null)
                            return (SCITypeHandle) param.Type;
                        else if (param.TypeExpression != null)
                            return (SCITypeHandle) param.TypeExpression.Type;
                        else
                            throw new ArgumentException();
                    }).ToArray();
            }
            else
            {
                DelegateParameterTypes = new SCITypeHandle[0];
            }

            FullOriginalName = Namespace.Replace("::", ".") + ((Namespace.Length > 0) ? "." : "");
            var enclosing = EnclosingType;
            while(enclosing != null)
            {
                FullOriginalName += enclosing.Raw.MemberName.GetSignatureForError() + ".";
                enclosing = enclosing.EnclosingType;
            }
            FullOriginalName += Raw.MemberName.GetSignatureForError();

            if(!Assembly.IsLibrary)
            {
                // scan for main method
                MainMethod = null;
                foreach(var method in Methods)
                {
                    if (!((method.ReturnType == null) || method.ReturnType.IsVoid || (method.ReturnType.IsDefinition && 
                            (method.ReturnType.Definition.BuiltinType == BuiltinTypeSpec.Type.Int))))
                        continue;

                    if (method.HasTypeParameters || !method.IsStatic || !method.HasBody  || (method.Parameters.Count() != 1) ||
                            (method.Name != "Main"))
                        continue;

                    var param = method.Parameters.First();
                    if (!param.Type.IsArray || !param.Type.Indirection.IsDefinition || (param.Type.Indirection.Definition.BuiltinType != BuiltinTypeSpec.Type.String))
                        continue;

                    MainMethod = method;
                    break;
                }
            }
        }


        private void EnrichInterfaceList(IList<TypeSpec> list)
        {
            var frontier = new List<TypeSpec>(list);
            var allIfaces = new HashSet<TypeSpec>(list);

            while (frontier.Count > 0)
            {
                var oldFrontier = frontier.ToArray();
                frontier.Clear();

                foreach (var i in oldFrontier)
                {
                    if (i.Interfaces == null)
                        continue;

                    foreach (var n in i.Interfaces)
                    {
                        if (!allIfaces.Contains(n))
                        {
                            frontier.Add(n);
                            list.Add(n);
                            allIfaces.Add(n);
                        }
                    }
                }
            }
        }

        public void Load_Step2()
        {
            /*
             * May depend on other types and thus must be done recursively. So we
             * just add a check to detect endless recursion.
             */
            if (m_HasReachedStep2)
                return;

            m_HasReachedStep2 = true;

            // collect all members
            if (Raw.Members.Any(e => (e is EnumMember)))
            {
                // an enum can only contain enum members!
                Raw.Members.Where(e => (e is EnumMember)).Apply(e => new SCIEnumMemberDefinition(this, e as EnumMember));
            }
            else
            {
                Raw.Members.Where(e => (e is Const)).Apply(e => new SCIFieldDefinition(this, e as FieldBase));
                Raw.Members.Where(e => (e is Field)).Apply(e => new SCIFieldDefinition(this, e as FieldBase));
                Raw.Members.Where(e => (e is Constructor)).Apply(e => new SCIMethodDefinition(this, (dynamic)e));
                Raw.Members.Where(e => (e is Destructor)).Apply(e => new SCIMethodDefinition(this, (dynamic)e));
                Raw.Members.Where(e => (e is Method)).Apply(e => new SCIMethodDefinition(this, (dynamic)e));
                Raw.Members.Where(e => (e is Operator)).Apply(e => new SCIOperatorDefinition(this, e as Operator));
                Raw.Members.Where(e => (e is PropertyBase)).Apply(e => new SCIPropertyDefinition(this, e as PropertyBase));
                Raw.Members.Where(e => (e is Event)).Apply(e => new SCIEventDefinition(this, e as Event));
            }

            ResolvePolymorphism();

            foreach (var method in Methods)
            {
                method.InitializeName();
            }
        }

        public override string ToString()
        {
            return "[" + (IsInterface ? "interface" : (IsClass ? "class" : (IsStruct ? "struct" : "enum"))) + "] " + FullName;
        }

        public static bool HasType(String unqualifiedName)
        {
            return s_TypeNamesCheck.Contains(unqualifiedName);
        }

        private void ResolvePolymorphism()
        {
            if (!IsStruct && !IsClass)
                return;

#if DEBUG
            // this will test our polymorphism resolver with what we already know
            foreach(var method in Handle.InstanceMethods)
            {

                if (method.Definition.BaseMethod != null)
                {
                    // try to find overridden base method
                    bool found = false;

                    foreach (var candidate in Handle.AllBaseMethods)
                    {
                        if (candidate.Definition.IsVirtual && candidate.CanOverride(method))
                        {
                            found = true;
                            if (method.Definition.BaseMethod != candidate)
                                throw new ApplicationException();
                            break;
                        }
                    }

                    if(!found)
                        throw new ApplicationException();
                }

                if (!method.Definition.Implements.IsEmpty())
                {
                    bool found = false;

                    foreach (var candidate in Handle.AllInterfaceMethods)
                    {
                        if (candidate.CanOverride(method))
                        {
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        throw new ApplicationException();
                }
            }
#endif

            bool[] explicitImpl = new bool[Handle.ReimplementedInterfaceMethods.Count];

            foreach (var method in Handle.InstanceMethods)
            {
                var def = method.Definition;

                if (!def.DoesImplementExplicitly || def.Implements.IsEmpty())
                    continue;

                // this is not a hotpath...
                var declType = def.Implements.First().DeclaringType;

                if (ReimplementedInterfaces.All(e => e != declType))
                    continue; // may explicitly implement interface in base class

                // so which method does it implement?
                int pos = Handle.ReimplementedInterfaceMethods.FindIndex(e => (e.DeclaringType == declType) && e.CanOverride(method));
                if(pos < 0)
                    throw new ApplicationException(); // Bug: If this happens we obviously got something wrong in the above lines

                explicitImpl[pos] = true;
            }

            // filter all explicitly implemented interface methods
            var implicitImpl = Handle.ReimplementedInterfaceMethods.Where((e, i) => !explicitImpl[i]).ToList();
            Array.Clear(explicitImpl, 0, explicitImpl.Length);

            foreach (var method in Handle.InstanceMethods)
            {
                var def = method.Definition;

                if (def.Implements.IsEmpty() || def.DoesImplementExplicitly)
                    continue;

                var declType = def.Implements.First().DeclaringType;

                if (ReimplementedInterfaces.All(e => e != declType))
                    continue; // may implicitly implement interface in base class

                // so which methods does it implement?
#if DEBUG
                int pos = implicitImpl.FindIndex(e => (e.DeclaringType == declType) && e.CanOverride(method));
                if (pos < 0)
                    throw new ApplicationException(); // Bug: If this happens we obviously got something wrong in the above lines
#endif

                // create method stubs for all matching interface methods
                for (int i = 0; i < implicitImpl.Count; i++)
                {
                    var impl = implicitImpl[i];

                    if (!impl.CanOverride(method))
                        continue;

                    explicitImpl[i] = true;

                    // add stub for interface method
                    method.Definition.Implements.Add(impl);
                }
            }

            // which methods have not been implemented?
            implicitImpl = implicitImpl.Where((e, i) => !explicitImpl[i]).ToList();
            Array.Clear(explicitImpl, 0, explicitImpl.Length);

            for (int i = 0; i < implicitImpl.Count; i++ )
            {
                var unresolved = implicitImpl[i];

                // try to find matching base method
                bool found = false;

                foreach (var method in Handle.AllBaseMethods)
                {
                    if (unresolved.CanOverride(method) && !method.Definition.DoesImplementExplicitly)
                    {
                        // add stub for interface method
                        explicitImpl[i] = true;
                        found = true;

                        AddInterfaceProxy(unresolved, method);
                        break;

                    }
                }

                if (!found && !IsAbstract)
                    throw new ApplicationException();
            }

            // resolve base methods for properties and events
            foreach (var propOrEvent in Handle.InstanceMethods)
            {
                var def = propOrEvent.Definition;

                if (!def.IsAccessor && !def.IsEvent || !def.IsCSOverride || (def.BaseMethod != null))
                    continue;

                foreach (var candidate in Handle.AllBaseMethods)
                {
                    if (candidate.CanOverride(propOrEvent))
                    {
                        def.BaseMethod = candidate;
                        break;
                    }
                }

                if(def.BaseMethod == null)
                    throw new ApplicationException();
            }
        }

        public void AddInterfaceProxy(SCIMethodHandle iface, SCIMethodHandle impl)
        {
            if (!iface.CanOverride(impl) || impl.Definition.Parent.IsInterface || !iface.Definition.Parent.IsInterface ||
                    impl.Definition.IsStatic)
                throw new ArgumentException();

            m_InterfaceProxies.Add(iface, impl);
        }

        private void ImportType()
        {
            // derive new name
            String undecorated = NameManager.UndecorateName(Raw.MemberName.Name);
            int i = 2;
            String name = undecorated;

            while (s_TypeNamesCheck.Contains(name))
            {
                name = undecorated + (i++);
            }

            s_TypeNamesCheck.Add(name);
            Name = name;
            Namespace = Raw.GetNamespace();
            NamespaceParts = Namespace.Split(new string[] { "::" }, StringSplitOptions.RemoveEmptyEntries);
            FullName = ((Namespace.Length > 0) ? Namespace : "") + "::" + Name;

            s_TypeMappings.Add(Raw, this);
        }

        public String GetBuiltinName()
        {
            switch (Spec.BuiltinType)
            {
                case BuiltinTypeSpec.Type.Bool: return "bool";
                case BuiltinTypeSpec.Type.Byte: return "unsigned char";
                case BuiltinTypeSpec.Type.Char: return "char16_t";
                case BuiltinTypeSpec.Type.Double: return "double";
                case BuiltinTypeSpec.Type.Float: return "float";
                case BuiltinTypeSpec.Type.Int: return "int32_t";
                case BuiltinTypeSpec.Type.IntPtr: return "void*";
                case BuiltinTypeSpec.Type.Long: return "int64_t";
                case BuiltinTypeSpec.Type.SByte: return "signed char";
                case BuiltinTypeSpec.Type.Short: return "int16_t";
                case BuiltinTypeSpec.Type.UInt: return "uint32_t";
                case BuiltinTypeSpec.Type.UIntPtr: return "void*";
                case BuiltinTypeSpec.Type.ULong: return "uint64_t";
                case BuiltinTypeSpec.Type.UShort: return "uint16_t";
                default:
                    return null;
            }
        }

        /// <summary>
        /// Type name references are context sensitive. Even though one could just use the full name,
        /// this would make the generated source code utterly verbose. Instead we try to optimize
        /// efficiently by stripping off unnecessary namespaces. It is not the shortest form in the general
        /// case but usually it is.
        /// The current context is given implicitly by <see cref="NameManager.CurrentType"/>.
        /// </summary>
        public String ComputeReferenceName(bool resolveBuiltinTypes = true, bool resolveVoid = true)
        {
            if (Spec.Kind == MemberKind.InternalCompilerType)
            {
                if (Spec.MemberDefinition.Name == "__arglist")
                    return "...";
                else
                    throw new NotImplementedException();
            }

            var ctx = NameManager.CurrentType;

            if (resolveBuiltinTypes)
            {
                var name = GetBuiltinName();
                if (name != null)
                    return name;
            }

            if (resolveVoid && (Spec.BuiltinType == BuiltinTypeSpec.Type.Other) && (Spec.MetaType.FullName == "System.Void"))
                return "void";

            String result = "";

            if (!Spec.IsGenericParameter)
            {
                var refNs = NamespaceParts;
                var currNs = NameManager.CurrentNamespace ?? new[]{""};
                IEnumerable<String> nsPrefix = refNs;

                if ((refNs.Length >= currNs.Length) && (currNs.Zip(refNs).FoldLeft((e, r) => (e.Key == e.Value) & r, true)))
                    nsPrefix = refNs.Skip(currNs.Length); // use relative namespace
                else
                    result += "::"; // start from global namespace (thus absolute)

                if (!nsPrefix.IsEmpty())
                    result += nsPrefix.FoldLeft((e, r) => r + e + "::", "");

                return result + Name;
            }
            else
                return Name;
        }
    }
}
