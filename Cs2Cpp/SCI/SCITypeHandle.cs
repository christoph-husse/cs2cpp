using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;

namespace Cs2Cpp
{
    interface IReadonlyArray<T> : IEnumerable<T>
    {
        T this[int index] { get; }
        int Count { get; }
        int IndexOf(T value);
        int IndexOf(Func<T, bool> where);
    }

    [Serializable]
    class ReadonlyArray<T> : IReadonlyArray<T>
    {
        private readonly IList<T> m_Src;

        public ReadonlyArray(IEnumerable<T> src)
        {
            m_Src = src.ToList();
            Count = m_Src.Count;
        }

        public ReadonlyArray(IList<T> src)
        {
            m_Src = src;
            Count = src.Count;
        }

        public ReadonlyArray()
        {
            m_Src = new List<T>();
            Count = 0;
        }

        public int IndexOf(T value)
        {
            return m_Src.IndexOf(value);
        }

        public T this[int index] {
            get { return m_Src[index]; }
        }
        public int Count { get; private set; }

        public IEnumerator<T> GetEnumerator()
        {
            return m_Src.GetEnumerator();
        }

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return m_Src.GetEnumerator();
        }

        public int IndexOf(Func<T, bool> where)
        {
            for (int i = 0; i < Count; i++)
            {
                if (where(this[i]))
                    return i;
            }

            return -1;
        }
    }

    [Serializable]
    class SCITypeHandle : IEqualityComparer<SCITypeHandle>, IEquatable<SCITypeHandle>
    {
        [NonSerialized]
        private TypeSpec m_Spec;
        [NonSerialized]
        private TypeParameterSpec m_GenericParameter;

        private IReadonlyArray<SCIMethodHandle> m_AllBaseMethods, m_AllInterfaceMethods, m_InstanceMethods, m_NewInterfaceMethods, m_ReimplementedInterfaceMethods,
            m_AllStaticMethods, m_StaticMethods;
        private IReadonlyArray<SCITypeHandle> m_AllTypeArguments = new ReadonlyArray<SCITypeHandle>(), m_AllTypeParameters = new ReadonlyArray<SCITypeHandle>();
        private IReadonlyArray<SCITypeHandle> m_AllInterfaces, m_AllBaseClasses;

        public NameManager NameManager { get { return Assembly.NameManager; } }
        public Assembly Assembly { get; private set; }
        public TypeSpec Spec { get { return m_Spec; } }
        public SCITypeHandle Indirection { get; private set; }
        /// <summary>
        /// A type definition NEVER includes type arguments, all except
        /// those from parent scope. So if this handle refers to a fully
        /// instanciated generic type, then those arguments are stored 
        /// separately in <see cref="TypeArguments"/>.
        /// </summary>
        public SCITypeDefinition Definition { get; private set; }

        public TypeParameterSpec GenericParameter { get { return m_GenericParameter; } private set { m_GenericParameter = value; } }

        public IReadonlyArray<SCITypeHandle> AllTypeArguments { get { return m_AllTypeArguments; } }
        public IReadonlyArray<SCITypeHandle> AllTypeParameters { get { return m_AllTypeParameters; } }
        public bool HasTypeArguments { get { return !AllTypeArguments.IsEmpty(); } }
        public bool HasIndirection { get { return Indirection != null; } }
        public bool IsDefinition { get { return Definition != null; } }
        public bool IsGenericParameter { get { return GenericParameter != null; } }
        public bool IsVoid { get { return IsDefinition && (Definition.BuiltinType == BuiltinTypeSpec.Type.Other) && (Definition.FullOriginalName == "System.Void"); } }
        public bool IsArray { get { return m_Spec.IsArray; } }
        public bool IsPointer { get { return m_Spec.IsPointer; } }
        public bool IsIntPtr { get { return (IsPointer && Indirection.IsDefinition && Indirection.Definition.IsVoid) || (IsDefinition && (Definition.BuiltinType == BuiltinTypeSpec.Type.IntPtr)); } }
        public bool IsEnum { get { return (IsDefinition && Definition.IsEnum); } }

        public bool IsNullable
        {
            get
            {
                if(IsGenericParameter)
                {
                    return GenericParameter.HasSpecialClass || GenericParameter.IsReferenceType;
                }
                else
                {
                    return Spec.IsClass || Spec.IsArray || Spec.IsNullableType;
                }
            }
        }

        public bool IsVariableArgumentList { get; private set; }
        public bool IsFullyInstanciated { get; private set; }
        public bool IsGeneric { get { return m_AllTypeArguments.Any(); } }
        public IReadonlyArray<SCIMethodHandle> InstanceMethods { get { return m_InstanceMethods ?? (m_InstanceMethods = ComputeInstanceMethods()); } }
        public IReadonlyArray<SCIMethodHandle> StaticMethods { get { return m_StaticMethods ?? (m_StaticMethods = ComputeStaticMethods()); } }
        public IReadonlyArray<SCIMethodHandle> AllStaticMethods { get { return m_AllStaticMethods ?? (m_AllStaticMethods = ComputeAllStaticMethods()); } }
        public IEnumerable<SCIMethodHandle> AllInstanceMethods { get { return InstanceMethods.Concat(AllBaseMethods); } }
        public IEnumerable<SCIMethodHandle> AllOperators { get { return AllStaticMethods.Where(e => e.Definition is SCIOperatorDefinition); } }
        public IReadonlyArray<SCIMethodHandle> AllBaseMethods { get { return m_AllBaseMethods ?? (m_AllBaseMethods = (Definition.BaseClass != null) ? Definition.BaseClass.ComputeAllBaseMethods() : new ReadonlyArray<SCIMethodHandle>()); } }
        public IReadonlyArray<SCIMethodHandle> AllInterfaceMethods { get { return m_AllInterfaceMethods ?? (m_AllInterfaceMethods = ComputeAllInterfaceMethods()); } }
        public IReadonlyArray<SCIMethodHandle> NewInterfaceMethods { get { return m_NewInterfaceMethods ?? (m_NewInterfaceMethods = ComputeNewInterfaceMethods()); } }
        public IReadonlyArray<SCITypeHandle> AllBaseClasses { get { return m_AllBaseClasses ?? (m_AllBaseClasses = ComputeAllBaseClasses()); } }
        public IReadonlyArray<SCITypeHandle> AllInterfaces { get { return m_AllInterfaces ?? (m_AllInterfaces = ComputeAllInterfaces()); } }
        public IReadonlyArray<SCIMethodHandle> ReimplementedInterfaceMethods { get { return m_ReimplementedInterfaceMethods ?? (m_ReimplementedInterfaceMethods = ComputeReimplementedInterfaceMethods()); } }

        public SCITypeHandle(TypeSpec spec, SCITypeDefinition definition = null)
        {
            m_Spec = spec;
            Assembly = Assembly.Resolve(spec);
            m_AllBaseMethods = m_AllInterfaceMethods = m_InstanceMethods = m_NewInterfaceMethods
                            = m_ReimplementedInterfaceMethods = m_AllStaticMethods = m_StaticMethods = new ReadonlyArray<SCIMethodHandle>();
            m_AllInterfaces = m_AllBaseClasses = new ReadonlyArray<SCITypeHandle>();

            if (spec.Kind == MemberKind.InternalCompilerType)
            {
                if (spec.Name == "__arglist")
                    IsVariableArgumentList = true;
                else
                    throw new NotImplementedException();
            }
            else
            {
                if (!spec.IsGenericParameter)
                {
                    if (IsArray)
                    {
                        var arr = spec as ArrayContainer;

                        Indirection = Wrap(arr.Element);
                    }
                    else if (IsPointer)
                    {
                        var ptr = spec as PointerContainer;

                        Indirection = Wrap(ptr.Element);
                    }
                    else
                    {
                        Definition = definition ?? SCITypeDefinition.Wrap(spec);

                        var args = new List<SCITypeHandle>();
                        var param = new List<SCITypeHandle>();
                        var list = spec;

                        while (list != null)
                        {
                            var listDef = Assembly.ResolveTypeDefinition((ITypeDefinition)list.Definition);
                            IEnumerable<SCITypeHandle> parmRange = null;

                            if (listDef.CurrentTypeParameters != null)
                                param.InsertRange(0, parmRange = ((ITypeDefinition)listDef).TypeParameters.Select(Wrap));

                            if (list.TypeArguments.IsEmpty())
                                args.InsertRange(0, parmRange ?? new SCITypeHandle[0]);
                            else
                                args.InsertRange(0, list.TypeArguments.Select(Wrap));

                            list = list.DeclaringType;
                        }

                        m_AllBaseMethods = m_AllInterfaceMethods = m_InstanceMethods = m_NewInterfaceMethods
                            = m_ReimplementedInterfaceMethods = m_AllStaticMethods = m_StaticMethods = null;
                        m_AllInterfaces = m_AllBaseClasses = null;

                        m_AllTypeArguments = new ReadonlyArray<SCITypeHandle>(args);
                        m_AllTypeParameters = new ReadonlyArray<SCITypeHandle>(param);

                        if(AllTypeArguments.Count != AllTypeParameters.Count)
                            throw new ApplicationException();

                        if (Definition.Name == "List")
                            Definition = Definition;

                        IsFullyInstanciated = m_AllTypeArguments.All(e => !e.IsGenericParameter && e.IsFullyInstanciated);
                        if (IsFullyInstanciated && IsGeneric)
                            Assembly.RegisterGenericInstanciation(this);
                    }
                }
                else
                {
                    GenericParameter = (TypeParameterSpec) spec;
                }
            }
        }

        public static implicit operator SCITypeHandle(SCITypeDefinition def)
        {
            return def.Handle;
        }

        private IReadonlyArray<SCIMethodHandle> ComputeInstanceMethods()
        {
            return new ReadonlyArray<SCIMethodHandle>(Definition.Methods.Where(e => !e.IsStatic).Select(e => SCIMethodHandle.Wrap(e, this)));
        }

        private IReadonlyArray<SCIMethodHandle> ComputeStaticMethods()
        {
            return new ReadonlyArray<SCIMethodHandle>(Definition.Methods.Where(e => e.IsStatic).Select(e => SCIMethodHandle.Wrap(e, this)));
        }

        private IReadonlyArray<SCIMethodHandle> ComputeAllStaticMethods()
        {
            if (Definition.BaseClass == null)
                return StaticMethods;
            else
                return new ReadonlyArray<SCIMethodHandle>(StaticMethods.Concat(Definition.BaseClass.AllStaticMethods.Select(e => SCIMethodHandle.Wrap(e, this))));
        }

        private IReadonlyArray<SCIMethodHandle> ComputeAllBaseMethods()
        {
            if(Definition.BaseClass == null)
                return InstanceMethods;
            else
                return new ReadonlyArray<SCIMethodHandle>(InstanceMethods.Concat(Definition.Handle.AllBaseMethods.Select(e => SCIMethodHandle.Wrap(e, this))));
        }

        private IReadonlyArray<SCIMethodHandle> ComputeReimplementedInterfaceMethods()
        {
            var res = new List<SCIMethodHandle>();

            foreach (var iface in Definition.ReimplementedInterfaces)
            {
                res.AddRange(iface.AllInterfaceMethods.Select(e => SCIMethodHandle.Wrap(e, this)));
            }

            return new ReadonlyArray<SCIMethodHandle>(res.Distinct());
        }

        private IReadonlyArray<SCITypeHandle> ComputeAllBaseClasses()
        {
            return new ReadonlyArray<SCITypeHandle>(Definition.AllBaseClasses.Apply(e => e.Instanciate(AllTypeParameters, AllTypeArguments)));
        }

        private IReadonlyArray<SCITypeHandle> ComputeAllInterfaces()
        {
            return new ReadonlyArray<SCITypeHandle>(Definition.AllInterfaces.Apply(e => e.Instanciate(AllTypeParameters, AllTypeArguments)));
        }

        private IReadonlyArray<SCIMethodHandle> ComputeNewInterfaceMethods()
        {
            var res = new List<SCIMethodHandle>();

            foreach (var iface in Definition.NewInterfaces)
            {
                res.AddRange(iface.AllInterfaceMethods.Select(e => SCIMethodHandle.Wrap(e, this)));
            }

            return new ReadonlyArray<SCIMethodHandle>(
                res.Distinct().Except(
                    (Definition.BaseClass != null) 
                        ? (IEnumerable<SCIMethodHandle>)Definition.BaseClass.AllInterfaceMethods 
                        : new SCIMethodHandle[0]));
        }

        private IReadonlyArray<SCIMethodHandle> ComputeAllInterfaceMethods()
        {
            var res = new List<SCIMethodHandle>();

            if (Definition.IsInterface)
                res.AddRange(InstanceMethods);

            foreach (var iface in Definition.AllInterfaces)
            {
                res.AddRange(iface.AllInterfaceMethods.Select(e => SCIMethodHandle.Wrap(e, this)));
            }

            return new ReadonlyArray<SCIMethodHandle>(res.Distinct());
        }

        public bool Implements(SCITypeHandle iface)
        {
            if (!iface.Definition.IsInterface)
                throw new ArgumentException();

            return AllInterfaces.Any(e => e == iface);
        }

        public bool DerivesFrom(SCITypeHandle type)
        {
            if (!Definition.IsClass || !type.Definition.IsClass)
                throw new ArgumentException();

            return AllBaseClasses.Any(e => e == type);
        }

        public bool IsAssignableFrom(SCITypeHandle from)
        {
            if (from == this)
                return true;

            if (Definition.IsInterface)
            {
                if (from.Definition.IsClass || from.Definition.IsInterface)
                    return from.Implements(this);
                else
                    return false;
            }
            else if (Definition.IsClass)
            {
                if (from.Definition.IsClass)
                    return from.DerivesFrom(this);
                else
                    return false;
            }
            else
                return false;
        }

        public static SCITypeHandle Wrap(TypeSpec spec)
        {
            return new SCITypeHandle(spec);
        }

        public static SCITypeHandle Wrap(TypeExpression spec)
        {
            return new SCITypeHandle(spec.Type);
        }

        public static bool operator ==(SCITypeHandle x, SCITypeHandle y)
        {
            if (Object.Equals(x, null) ^ Object.Equals(y, null))
                return false;

            return Object.Equals(x, null) || x.Equals(y);
        }

        public static bool operator !=(SCITypeHandle x, SCITypeHandle y)
        {
            return !(x == y);
        }

        public bool Equals(SCITypeHandle x, SCITypeHandle y)
        {
            if (x.IsGenericParameter && y.IsGenericParameter)
            {
                if (x.GenericParameter.Name != y.GenericParameter.Name)
                    return false;

                // TODO: Add more checks to see if x and y really refer to the same generic parameter
                // Specs are not reliable, since the same parameter may have different spec instances.
                return true;
            }
            else if (x.HasIndirection)
            {
                if (!y.HasIndirection)
                    return false;

                if ((x.IsPointer ^ y.IsPointer) || (x.IsArray ^ y.IsArray))
                    return false;

                return x.Indirection.Equals(y.Indirection);
            }
            else
            {
                return x.m_Spec == y.m_Spec;
            }
        }

        public static implicit operator SCITypeHandle(TypeSpec src)
        {
            if (src == null)
                return null;

            if ((src.Kind == MemberKind.InternalCompilerType) && (src.Name == "null"))
                return null;

            return Wrap(src);
        }

        public override bool Equals(object obj)
        {
            if (obj is SCITypeHandle)
                return Equals(this, obj as SCITypeHandle);
            else
                return base.Equals(obj);
        }

        public override int GetHashCode()
        {
            return GetHashCode(this);
        }

        public int GetHashCode(SCITypeHandle obj)
        {
            return obj.m_Spec.GetHashCode();
        }

        public bool Equals(SCITypeHandle other)
        {
            return Equals(this, other);
        }

        public override string ToString()
        {
            return m_Spec.ToString();
        }

        public SCITypeHandle Instanciate(IReadonlyArray<SCITypeHandle> parameters, IReadonlyArray<SCITypeHandle> arguments)
        {
            return SCITypeHandle.Wrap(new TypeParameterInflator(NameManager.ModuleContext, Spec, parameters.Select(e => e.GenericParameter).ToArray(),
                                      arguments.Select(e => e.Spec).ToArray()).Inflate(Spec));
        }
    }
}
