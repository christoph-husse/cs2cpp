using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;

namespace Cs2Cpp
{

    [Serializable]
    internal class SCIMethodDefinition : SCIMemberDefinition
    {
        [NonSerialized]
        private static readonly Dictionary<String, SCIMethodDefinition> s_MethodMapping =
            new Dictionary<String, SCIMethodDefinition>();
        [NonSerialized]
        private static readonly Dictionary<ImportedParameterMemberDefinition, SCIMethodDefinition> s_ImportedMethods =
            new Dictionary<ImportedParameterMemberDefinition, SCIMethodDefinition>();

        public static void Reset()
        {
            // reset all static state
            s_MethodMapping.Clear();
        }

        [NonSerialized]
        private readonly Dictionary<ILocalVariable, SCILocalDefinition> m_Locals =
            new Dictionary<ILocalVariable, SCILocalDefinition>();
        [NonSerialized]
        private readonly Dictionary<ILocalVariable, SCILocalDefinition> m_Variables =
            new Dictionary<ILocalVariable, SCILocalDefinition>();
        [NonSerialized]
        private readonly Dictionary<ILocalVariable, SCILocalDefinition> m_Parameters =
            new Dictionary<ILocalVariable, SCILocalDefinition>();

        private readonly String m_Signature;
        private readonly bool m_IsGetter;
        private readonly bool m_IsAddDelegate;
        [NonSerialized]
        private dynamic m_Raw;

        /// <summary>
        /// A signature is meant to uniquely identify a method. Thus it also takes the type
        /// into account in which the method is defined, as well as the assembly (strong name).
        /// This is of utmost importance for polymorphism to be mapped correctly to C++.
        /// Note that this signature is generated, regardless of whether a method is polymorphic.
        /// </summary>
        public String Signature
        {
            get { return m_Signature; }
        }

        protected new dynamic Raw { get { return m_Raw; } private set { m_Raw = value; } }
        protected MethodSpec Spec
        {
            get
            {
                return (MethodOrOperator != null) ? MethodOrOperator.Spec : (PropertyOrEvent != null) ? PropertyOrEvent.Spec
                    : (Constructor != null) ? Constructor.Spec : Destructor.Spec;
            }
        }
        public bool IsMethodOrOperator { get { return MethodOrOperator != null; } }
        protected MethodOrOperator MethodOrOperator { get { return Raw as MethodOrOperator; } }
        protected AbstractPropertyEventMethod PropertyOrEvent { get { return Raw as AbstractPropertyEventMethod; } }
        protected Constructor Constructor { get { return Raw as Constructor; } }
        protected Destructor Destructor { get { return Raw as Destructor; } }
        public IEnumerable<SCILocalDefinition> Variables { get { return m_Variables.Values; } }
        public IEnumerable<SCILocalDefinition> Parameters { get { return m_Parameters.Values; } }
        public bool IsGetter { get { return IsAccessor && m_IsGetter; } }
        public bool IsAccessor { get; private set; }
        public bool IsSetter { get { return !m_IsGetter && IsAccessor; } }
        public bool IsAddDelegate { get { return IsEvent && m_IsAddDelegate; } }
        public bool IsEvent { get; private set; }
        public bool IsPublic { get; private set; }
        public bool IsFinalizer { get { return (Destructor != null); } }
        public bool IsConstructorOrFinalizer { get { return (Constructor != null) || (Destructor != null); } }
        public bool IsConstructor { get { return (Constructor != null); } }
        public bool IsRemoveDelegate { get { return !m_IsAddDelegate && IsEvent; } }
        public SCIPropertyDefinition Property { get; private set; }

        /// <summary>
        /// Was the method marked with the "override" modifier in C#?
        /// </summary>
        public bool IsCSOverride { get; private set; }
        /// <summary>
        /// Does this method override anything, like interface/abstract/virtual methods?
        /// This is different from <see cref="IsCSOverride"/>, in that this property
        /// may actually be true even though <see cref="IsCSOverride"/> isn't.
        /// </summary>
        public bool DoesOverride { get { return (BaseMethod != null); } }
        public bool DoesImplementExplicitly { get { return !Implements.IsEmpty() && IsPrivate; } }
        public bool IsExtern { get; private set; }
        public bool IsPrivate { get; private set; }
        /// <summary>
        /// Has the C# "new" modifier? If so, then this method, even though it has the
        /// same name as a virtual base method, will still not override it.
        /// </summary>
        public bool IsNew { get; private set; }
        public bool IsSealed { get; private set; }
        public bool IsDllImport { get; private set; }
        public bool IsVirtual { get; private set; }
        public bool IsAbstract { get; private set; }
        public bool IsStatic { get; private set; }
        public SCITypeHandle ReturnType { get; private set; }
        public Block Body { get { return Raw.Block_LastNonNull; } }
        public Location Location { get { return Raw.Location; } }
        public bool HasBody { get { return (Raw != null) && (Body != null); } }

        public bool HasTypeParameters { get { return (TypeParameters != null) && !TypeParameters.IsEmpty(); } }
        public IEnumerable<SCITypeHandle> TypeParameters { get; private set; }
        public IEnumerable<SCITypeHandle> AllTypeParameters { get { return Parent.AllTypeParameters.Concat(TypeParameters); } } 

        public List<SCIMethodHandle> Implements { get; private set; }
        public SCIMethodHandle BaseMethod { get; internal set; }

        public bool IsPolymorphic { get; private set; }

        public SCIMethodDefinition(SCITypeDefinition parent, Constructor source)
            : this(parent, (MemberCore)source)
        {
            SharedInitializer(true);
        }

        public SCIMethodDefinition(SCITypeDefinition parent, Destructor source)
            : this(parent, (MemberCore)source)
        {
            SharedInitializer(true);
        }

        public SCIMethodDefinition(SCITypeDefinition parent, MethodOrOperator source)
            : this(parent, (MemberCore)source)
        {
            SharedInitializer();
        }

        public SCIMethodDefinition(SCITypeDefinition parent, SCIPropertyDefinition prop, PropertyBase.GetMethod source)
            : this(parent, (MemberCore)source)
        {
            IsAccessor = true;
            m_IsGetter = true;
            Property = prop;

            SharedInitializer();
        }

        public SCIMethodDefinition(SCITypeDefinition parent, SCIPropertyDefinition prop, PropertyBase.SetMethod source)
            : this(parent, (MemberCore)source)
        {
            m_IsGetter = false;
            IsAccessor = true;
            Property = prop;

            SharedInitializer();
        }

        public SCIMethodDefinition(SCITypeDefinition parent, Event.AEventAccessor source)
            : this(parent, (MemberCore)source)
        {
            IsEvent = true;

            if ((source is EventField.AddDelegateMethod) || (source is EventProperty.AddDelegateMethod))
                m_IsAddDelegate = true;
            else if ((source is EventField.RemoveDelegateMethod) || (source is EventProperty.RemoveDelegateMethod))
                m_IsAddDelegate = false;
            else
                throw new ArgumentException();

            SharedInitializer();
        }


        private SCIMethodDefinition(SCITypeDefinition parent)
            : base(parent, null, false)
        {
            Raw = null;
        }

        private SCIMethodDefinition(SCITypeDefinition parent, MemberCore source)
            : base(parent, source, false)
        {
            Raw = source;
            m_Signature = Convert.ToString(ComputeMethodSignature(Raw.Spec), 16);
            IsDllImport = IsExtern && HasAttribute(typeof(DllImportAttribute));
            ReturnType = (Raw.ReturnType != null) ? SCITypeHandle.Wrap((TypeSpec)Raw.ReturnType) : null;
        }

        private void SharedInitializer(bool resolveName = true, String prefix = "")
        {
            IsCSOverride = (Raw.ModFlags & Modifiers.OVERRIDE) != 0; 
            IsExtern = (Raw.ModFlags & Modifiers.EXTERN) != 0; 
            IsNew = (Raw.ModFlags & Modifiers.NEW) != 0;
            IsPublic = (Raw.ModFlags & Modifiers.PUBLIC) != 0;
            IsPrivate = (Raw.ModFlags & Modifiers.PRIVATE) != 0;
            IsSealed = (Raw.ModFlags & Modifiers.SEALED) != 0;
            IsAbstract = ((Raw.ModFlags & Modifiers.ABSTRACT) != 0) || Parent.IsInterface;
            IsVirtual = ((Raw.ModFlags & Modifiers.VIRTUAL) != 0) || Parent.IsInterface || IsAbstract || IsCSOverride;
            IsStatic = Raw.IsStatic;
            Implements = new List<SCIMethodHandle>();

            ResolvePolymorphism();

            if ((Raw is Method) && (Raw.TypeParametersCount > 0))
                TypeParameters = ((TypeParameterSpec[]) Raw.TypeParameters).Select(SCITypeHandle.Wrap).ToArray();
            else
                TypeParameters = new SCITypeHandle[0];
            
            // resolve variables/parameters
            Func<IParameterData, SCILocalDefinition> resolver = (IParameterData e) => ResolveParameter((Parameter)e);
            Extensions.Apply(Raw.ParameterInfo.FixedParameters, resolver);

            // must be fully setup when we call this
            if (resolveName)
                ResolveName(prefix);

            s_MethodMapping.Add(Signature, this);
        }

        public void InitializeName()
        {
            Implements = Implements.Distinct().ToList();

            if (!IsPolymorphic)
                return;

            if (BaseMethod == null)
                m_Name = NameManager.UndecorateName(OriginalName) + "_" + Signature;
            else
                m_Name = BaseMethod.Name;
        }

        public bool CanImplement(SCIMethodDefinition ifaceMethod)
        {
            if (!ifaceMethod.IsAbstract || !ifaceMethod.IsPolymorphic || !ifaceMethod.Parent.IsInterface)
                throw new ApplicationException("Target method does not seem to be of an interface.");

            if (ReturnType != ifaceMethod.ReturnType)
                return false;

            if (Parameters.Count() != ifaceMethod.Parameters.Count())
                return false;

            return Parameters.Zip(ifaceMethod.Parameters, (a, b) => a.Type == b.Type).All(e => e);
        }

        public static SCIMethodDefinition Wrap(MethodSpec method)
        {
            return ResolveFromSpec(method);
        }

        private static SCIMethodDefinition ResolveFromSpec(MethodSpec method, int depth = 0)
        {
            SCIMethodDefinition def;

            if (depth > 5)
            {
                // this means we are in serious trouble...
                throw new ArgumentException("Stack overflow.");
            }

            if (s_MethodMapping.TryGetValue(Convert.ToString(ComputeMethodSignature(method), 16), out def))
                return def;

            // for some reason, it might happen that the type was not loaded, even though we apply
            // sorting by dependence
            SCITypeDefinition.Wrap(method.DeclaringType).Load_Step2();

            if (s_MethodMapping.TryGetValue(Convert.ToString(ComputeMethodSignature(method), 16), out def))
                return def;

            // this shall only happen in case of virtual generic functions
            if (method.Definition is IGenericMethodDefinition)
            {
                var spec = ((Method)method.GenericDefinition).Spec;

                if (spec == method)
                {
                    var declType = SCITypeHandle.Wrap(spec.DeclaringType);

                    if(declType.AllBaseClasses.Any(e => e.Definition.BuiltinType == BuiltinTypeSpec.Type.Delegate))
                        return new SCIMethodDefinition(SCITypeDefinition.Wrap(spec.DeclaringType), ((Method)method.GenericDefinition));
                    else
                        throw new ArgumentException();
                }
                else
                {
                    return ResolveFromSpec(spec, depth + 1);
                }
            }
            else
            {
                dynamic implementing = null;
                var type = SCITypeDefinition.Wrap(method.DeclaringType);

                var imported = method.Definition as ImportedParameterMemberDefinition;
                if(imported != null)
                {
                    SCIMethodDefinition res;
                    if (s_ImportedMethods.TryGetValue(imported, out res))
                        return res;

                    Assembly assembly = Cs2Cpp.Assembly.Resolve(imported.Provider.DeclaringType.Assembly);
                    res = assembly.NameManager.Context.ResolveImportedMethod(imported);

                    s_ImportedMethods.Add(imported, res);
                    return res;
                }

                var propOrEvent = method.Definition as AbstractPropertyEventMethod;
                if (propOrEvent != null)
                    implementing = propOrEvent.MethodData.Method;

                var methodOrOp = method.Definition as MethodOrOperator;
                if (methodOrOp != null)
                    implementing = methodOrOp.MethodData.Method;

                if (implementing.Spec == method)
                    throw new ArgumentException();

                return ResolveFromSpec(implementing.Spec, depth + 1);
            }
        }


        private void ResolvePolymorphism()
        {
            if (Parent.Name.Contains("NestedBase"))
                IsNew = IsNew;

            //// does overwrite something?
            dynamic method = MethodOrOperator;

            if (PropertyOrEvent != null)
                method = PropertyOrEvent;

            if (method == null)
                return; // constructor & whatever

            if (method.MethodData.implementing != null)
            {
                SCIMethodHandle impl = SCIMethodHandle.Wrap(method.MethodData.implementing);

                if (IsCSOverride && !impl.DeclaringType.Definition.IsInterface)
                    BaseMethod = impl;
                else
                    Implements.Add(impl);
            }

            if ((MethodOrOperator != null) && (method.BaseMethod != null))
            {
                SCIMethodHandle impl = SCIMethodHandle.Wrap(method.BaseMethod);

                if (IsCSOverride && !impl.DeclaringType.Definition.IsInterface && (BaseMethod == null))
                    BaseMethod = impl;
            }

            IsPolymorphic = DoesOverride || IsVirtual || IsAbstract || IsCSOverride;
            IsPolymorphic &= !DoesImplementExplicitly;
        }


        public SCILocalDefinition ResolveLocal(ILocalVariable local_)
        {
            return m_Locals[local_];
        }

        public SCILocalDefinition ResolveVariable(ILocalVariable local_)
        {
            dynamic local = local_;

            if (local.Name.Length == 0)
                return null;

            if (m_Variables.ContainsKey(local))
                return m_Variables[local];
            else
            {
                var res = new SCILocalDefinition(this, local);
                m_Locals.Add(local_, res);
                m_Variables.Add(local, res);
                return res;
            }
        }

        public SCILocalDefinition DeclareVariable(ILocalVariable local_)
        {
            dynamic local = local_;

            if (local.Name.Length == 0)
                return null;

            if (m_Variables.ContainsKey(local))
                return m_Variables[local];

            // does variable-declaration overwrite an existing one (different scopes)?
            var entry = m_Variables.FirstOrDefault(e => ((dynamic)e.Value.Raw).Name == local.Name);
            if (entry.Key != null)
            {

                m_Variables.Remove(entry.Key);
            }

            var res = new SCILocalDefinition(this, local);
            m_Locals.Add(local_, res);
            m_Variables.Add(local, res);
            return res;
        }

        private SCILocalDefinition ResolveParameter(Parameter local_)
        {
            dynamic local = local_;

            if (local.Name.Length == 0)
                return null;

            if (m_Parameters.ContainsKey(local))
                return m_Parameters[local];
            else
            {
                var res = new SCILocalDefinition(this, local);
                m_Locals.Add(local_, res);
                m_Parameters.Add(local, res);
                return res;
            }
        }

        /// <summary>
        /// For any given set of six million methods, probability that any of its elements collide
        /// is about one to one million. So even if you have huge libraries, I' rather congratulate 
        /// you to a lottery win ;).
        /// 
        /// The method signature is composed of the full name, including all namespaces,
        /// all nested types and the method name itself. Followed by all parameter types
        /// with context sensitive names (only necessaty namespaces/nestings included). 
        /// Additionally, there may be a list of generic parameters. In case of explicit
        /// interface implementations, the fully qualified name of that interface is also
        /// appended at the end.
        /// </summary>
        private static Int64 ComputeMethodSignature(MethodSpec method)
        {
            // has explicit interface implementation?
            String ext = "";
            dynamic def = method.Definition;

            if ((def is AbstractPropertyEventMethod) || (def is MethodOrOperator))
            {
                ext = def.MethodData.MethodBuilder.ToString();

                if (((int) def.MethodData.Flags & (int) MethodAttributes.SpecialName) != 0)
                    ext += "[SpecialName]";
            }

            String sig = method.GetSignatureForError() + ext + ":" + method.IsStatic;
            var hash = SHA1.Create().ComputeHash(Encoding.Unicode.GetBytes(sig));
            Int64 res = 0;
            for (int i = 0; i < Math.Min(8, hash.Length); i++)
            {
                res |= ((Int64)hash[i]) << (i * 8);
            }

            return res;
        }

        public override string ToString()
        {
            String res = ((ReturnType != null)? ReturnType.ToString() : "void") + " " + FullName + " (";
            Parameters.Apply(p => res += p.Type.ToString() + " " + p.Name + ",");
            if (res.EndsWith(","))
                res = res.Substring(0, res.Length - 1);

            return res + ")";
        }
    }
}
