using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    class SCIMethodHandle : IEqualityComparer<SCIMethodHandle>
    {
        public SCIMethodDefinition Definition { get; private set; }
        public SCITypeHandle DeclaringType { get; private set; }
        public SCITypeHandle Context { get; private set; }
        public IReadonlyArray<SCITypeHandle> ParameterTypes { get; private set; }
        public IReadonlyArray<SCITypeHandle> ExplicitTypeParameters { get; private set; }
        public SCITypeHandle ReturnType { get; private set; }
        public String Name { get { return Definition.Name; } }

        public static SCIMethodHandle Wrap(SCIMethodHandle handle, SCITypeHandle context = null)
        {
            var res = new SCIMethodHandle();

            res.Definition = handle.Definition;
            res.Context = context;
            res.DeclaringType = res.ConvertType(handle.DeclaringType);
            res.ParameterTypes = new ReadonlyArray<SCITypeHandle>(handle.ParameterTypes.Select(res.ConvertType));
            res.ReturnType = res.ConvertType(handle.ReturnType);
            res.ExplicitTypeParameters = new ReadonlyArray<SCITypeHandle>();

            return res;
        }

        public static SCIMethodHandle Wrap(SCIMethodDefinition def, SCITypeHandle context = null)
        {
            var res = new SCIMethodHandle();

            res.Definition = def;
            res.Context = context;
            res.DeclaringType = res.ConvertType(res.Definition.Parent.Handle);
            res.ParameterTypes = new ReadonlyArray<SCITypeHandle>(def.Parameters.Select(e => res.ConvertType(e.Type)));
            res.ReturnType = res.ConvertType(def.ReturnType);
            res.ExplicitTypeParameters = new ReadonlyArray<SCITypeHandle>();

            return res;
        }

        public static SCIMethodHandle Wrap(MethodSpec spec)
        {
            var res = Wrap(SCIMethodDefinition.Wrap(spec), SCITypeHandle.Wrap(spec.DeclaringType));

            if (spec.TypeArguments != null)
                res.ExplicitTypeParameters = new ReadonlyArray<SCITypeHandle>(spec.TypeArguments.Select(e => (SCITypeHandle)e));

            return res;
        }

        private bool HasSameNonGenericSignature(SCIMethodHandle method)
        {
            if (method.Definition.OriginalName != Definition.OriginalName)
                return false;

            if (method.ParameterTypes.Count != ParameterTypes.Count)
                return false;

            for (int i = 0; i < ParameterTypes.Count; i++)
            {
                if (ParameterTypes[i] != method.ParameterTypes[i])
                    return false;
            }

            return true;
        }

        public bool CanOverride(SCIMethodHandle method)
        {
            // TODO: method with enclosing type parameters can cause signature collision. Generic methods
            // are to be threaded with lower priority to resolve this!
            if (!HasSameNonGenericSignature(method))
                return false;

            return ReturnType == method.ReturnType;
        }

        public bool HasSameSignature(SCIMethodHandle method)
        {
            if (!HasSameNonGenericSignature(method))
                return false;

            // TODO: Maybe also add support for generic methods, which though should not be used in this context

            return true;
        }

        private SCITypeHandle ConvertType(SCITypeHandle handle)
        {
            if (handle == null)
                return null;

            if (!handle.IsGenericParameter)
            {
                if (Context.AllTypeParameters.Count == 0)
                    return handle;
                else
                    return handle.Instanciate(Context.AllTypeParameters, Context.AllTypeArguments);
            }
            else
            {
                int pos = Context.AllTypeParameters.IndexOf(handle);
                if (pos >= 0)
                    return Context.AllTypeArguments[pos];

                return handle;
            }
        }

        public override string ToString()
        {
            String res = ((ReturnType != null) ? ReturnType.ToString() : "void") + " " + Definition.FullName + " (";
            res = ParameterTypes.Zip(Definition.Parameters, (t,p) => t.ToString() + " " + p.Name + ",").FoldLeft((s,r) => r += s, res);
            if (res.EndsWith(","))
                res = res.Substring(0, res.Length - 1);

            return res + ")";
        }

        public static bool operator ==(SCIMethodHandle x, SCIMethodHandle y)
        {
            if (Object.Equals(x, null) ^ Object.Equals(y, null))
                return false;

            return Object.Equals(x, null) || x.Equals(y);
        }

        public static bool operator !=(SCIMethodHandle x, SCIMethodHandle y)
        {
            return !(x == y);
        }

        public override bool Equals(object obj)
        {
            if (obj is SCIMethodHandle)
                return Equals(this, obj as SCIMethodHandle);
            else
                return base.Equals(obj);
        }

        public override int GetHashCode()
        {
            return GetHashCode(this);
        }

        public bool Equals(SCIMethodHandle x, SCIMethodHandle y)
        {
            if (x.Definition != y.Definition)
                return false;

            return x.HasSameSignature(y) && (x.ReturnType == y.ReturnType);
        }

        public int GetHashCode(SCIMethodHandle obj)
        {
            return obj.Definition.GetHashCode();
        }
    }
}
