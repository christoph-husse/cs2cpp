using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    delegate void Procedure();

    [Serializable]
    delegate void Procedure<in T1>(T1 arg1);

    [Serializable]
    delegate void Procedure<in T1, in T2>(T1 arg1, T2 arg2);

    static class Extensions
    {
        public static bool IsSubString(this StringBuilder This, String str, int index)
        {
            for (int i = index, j = 0; j < str.Length; i++, j++)
            {
                if (i >= This.Length)
                    return false;

              if (This[i] != str[j])
                    return false;
            }

            return true;
        }

        public static bool IsPolymorphicOverride(this IMethodData This)
        {
            Method method = This as Method;

            if (method != null)
            {
                if ((method.BaseMethod != null) || (method.MethodData.implementing != null))
                    return true;
            }

            AbstractPropertyEventMethod propEvent = This as AbstractPropertyEventMethod;

            if (propEvent != null)
            {
                if (propEvent.MethodData.implementing != null)
                    return true;
            }

            return false;
        }

        public static bool IsPolymorphic(this IMethodData This)
        {
            return IsPolymorphicOverride(This) || This.Spec.IsVirtual;
        }

        /// <summary>
        /// This really is super ugly and either a sign of that the Mono C# compiler
        /// is one huge hack or a compiler does not need even parts of this information, 
        /// which is doubtful...
        /// </summary>
        public static MethodSpec GetPolymorphicBaseMethod(this IMethodData This)
        {
            Method method = This as Method;

            if (method != null)
            {
                if (method.BaseMethod != null)
                    return ((Method)method.BaseMethod.MemberDefinition).GetPolymorphicBaseMethod();
                else if (method.MethodData.implementing != null)
                    return ((Method)method.MethodData.implementing.MemberDefinition).GetPolymorphicBaseMethod();
            }

            AbstractPropertyEventMethod propEvent = This as AbstractPropertyEventMethod;

            if (propEvent != null)
            {
                if (propEvent.MethodData.implementing != null)
                    return ((AbstractPropertyEventMethod)propEvent.MethodData.implementing.MemberDefinition).GetPolymorphicBaseMethod();

                if (propEvent.Spec.IsVirtual)
                {
                    // TODO: also handle events, not only properties

                    if ((propEvent.ModFlags & Modifiers.OVERRIDE) != 0)
                    {
                        // we have to resolve such overrides ourselves, since the Mono compiler does not seem to expose this functionality!?
                        var type = propEvent.CurrentType;

                        do
                        {
                            if ((type = type.BaseType) == null)
                                throw new ApplicationException("Property marked as overridden but no base property could be determined.");

                            var typeDef = ((TypeDefinition)type.MemberDefinition);

                            foreach (var prop in typeDef.Members.FilterType<Property, MemberCore>())
                            {
                                var sigA = propEvent.ParameterInfo.GetSignatureForError();

                                if (prop.Get != null)
                                {
                                    var sigB = prop.Get.ParameterInfo.GetSignatureForError();
                                    if ((prop.Get.MemberName.Basename == propEvent.MemberName.Basename) && (sigA == sigB))
                                        return prop.Get.GetPolymorphicBaseMethod();
                                }

                                if (prop.Set != null)
                                {
                                    var sigB = prop.Set.ParameterInfo.GetSignatureForError();
                                    if ((prop.Set.MemberName.Basename == propEvent.MemberName.Basename) && (sigA == sigB))
                                        return prop.Set.GetPolymorphicBaseMethod();
                                }
                            }
                        } while (true);
                    }
                }
            }

            return This.Spec;
        }

        public static void ZipApply<A, B>(this IEnumerable<A> a, IEnumerable<B> b, Action<A,B> doSomething)
        {
            var enumA = a.GetEnumerator();
            var enumB = b.GetEnumerator();

            while (enumA.MoveNext())
            {
                enumB.MoveNext();
                doSomething(enumA.Current, enumB.Current);
            }

            if(enumA.MoveNext() || enumB.MoveNext())
                throw new InvalidOperationException("Zipped sequences are not of same length!");
        }

        public static bool IsGenericRecursively(this TypeSpec This)
        {
            while (This != null)
            {
                if (This.TypeArguments.Length > 0)
                    return true;

                This = This.DeclaringType;
            }

            return false;
        }

        public static IEnumerable<TypeSpec> GetAllTypeArguments(this TypeSpec This)
        {
            List<TypeSpec> result = new List<TypeSpec>();

            while (This != null)
            {
                result.InsertRange(0, This.TypeArguments);

                This = This.DeclaringType;
            }

            return result;
        }

        public static IEnumerable<TypeSpec> GetTypeArgumentsOfParentScope(this TypeSpec This)
        {
            List<TypeSpec> result = new List<TypeSpec>();

            This = This.DeclaringType;

            while (This != null)
            {
                result.InsertRange(0, This.TypeArguments);

                This = This.DeclaringType;
            }

            return result;
        }

        public static int FindIndex<T>(this IEnumerable<T> This, Func<T, bool> where)
        {
            int i = 0;

            foreach (var e in This)
            {
                if (where(e))
                    return i;

                i++;
            }

            return -1;
        }

        public static IEnumerable<TypeSpec> GetTypeParametersOfParentScope(this TypeSpec This)
        {
            List<TypeSpec> result = new List<TypeSpec>();

            This = This.DeclaringType;

            while (This != null)
            {
                var def = ((TypeDefinition) This.Definition);

                if (def.CurrentTypeParameters != null)
                    result.InsertRange(0, ((ITypeDefinition)def).TypeParameters);

                This = This.DeclaringType;
            }

            return result;
        }

        public static String GetNamespace(this TypeSpec This)
        {
            try
            {
                while (This.IsNested) This = This.DeclaringType;

                return This.MetaType.Namespace;
            }
            catch
            {
                return "";
            }
        }

        public static String GetNamespace(this TypeDefinition This)
        {
            var list = This.Parent;
            String fullName = "";
            while (list != null)
            {
                var ns = list as NamespaceContainer;

                if (ns != null)
                {
                    fullName = ns.NS.Name + ((fullName.Length > 0) ? "::" + fullName : "");
                    break;
                }

                list = list.Parent;
            }

            return fullName.Replace(".", "::");
        }

        public static bool IsSet<T>(this System.Enum This, T value)
        {
            return This.HasFlag((System.Enum)(Object)value);
        }

        public static bool IsAnySet<T>(this System.Enum This, params T[] value)
        {
            foreach (var v in value)
            {
                if ((((int)(Object)This) & ((int)(Object)v)) != 0)
                    return true;
            }

            return false;
        }

        public static T MaskedBy<T>(this System.Enum This, params T[] value)
        {
            int mask = 0;

            foreach (var v in value)
            {
                mask |= ((int)(Object)v);
            }

            return (T)(Object)(((int)(Object)This) & mask);
        }

        public static bool AreAllSet<T>(this System.Enum This, params T[] value)
        {
            foreach (var v in value) if (!This.HasFlag((System.Enum)(Object)v)) return false;
            return true;
        }

        public static bool IsEmpty<TVal>(this IEnumerable<TVal> This) 
        {
            return (This == null) || !This.GetEnumerator().MoveNext();
        }

        public static IEnumerable<TVal> Once<TVal>(
            this IEnumerable<TVal> This,
            Procedure inDoSomethingAtMostOnce)
        {
            if (!This.IsEmpty())
                inDoSomethingAtMostOnce();

            return This;
        }

        public static IEnumerable<TVal> Apply<TVal>(
            this IEnumerable<TVal> This,
            Procedure<TVal> inFunction)
        {
            if (This == null) return This;
            foreach (var e in This) inFunction(e);
            return This;
        }

        public static IEnumerable<TRes> FilterType<TRes, TIn>(this IEnumerable<TIn> This) where TRes : class
        {
            return This.Where(e => e is TRes).Select(e => e as TRes);
        }

        public static IEnumerable<T> Without<T>(
            this IEnumerable<T> This,
            T inElement)
        {
            return This.Where(
                e => !e.Equals(inElement));
        }

        public static IEnumerable<TVal> Flatten<TEnum, TVal>(this IEnumerable<TEnum> This) where TEnum : IEnumerable<TVal>
        {
            return This.Aggregate(new List<TVal>(), (r, e) => { r.AddRange(e); return r; });
        }


        public static IEnumerable<TRes> Apply<TRes, TVal>(
            this IEnumerable<TVal> This,
            Func<TVal, TRes> inFunction)
        {
            List<TRes> result = new List<TRes>();

            foreach (var e in This) result.Add(inFunction(e));

            return result;
        }

        public static IEnumerable<KeyValuePair<TThis, TWith>> Zip<TThis, TWith>(
            this IEnumerable<TThis> This,
            IEnumerable<TWith> inWith)
        {
            return This.Zip(inWith, (a, b) => new KeyValuePair<TThis, TWith>(a, b));
        }

        public static TRes FoldLeft<TRes, TVal>(
            this IEnumerable<TVal> This,
            Func<TVal, TRes, TRes> inTransform,
            TRes inStart)
        {
            foreach (var s in This)
            {
                inStart = inTransform(s, inStart);
            }

            return inStart;
        }

        public static String RemoveEnd(this String This, int inCharCountToRemove)
        {
            return This.Remove(
                Math.Max(0, This.Length - inCharCountToRemove),
                Math.Min(This.Length, inCharCountToRemove));
        }

        public static String XMLEscape(this String This)
        {
            return This.Replace("&", "&amp;").Replace("<", "&lt;").Replace(">", "&gt;");
        }

        public static List<String> XmlTokenize(this String This)
        {
            List<String> tokens = new List<string>();
            String token = "";

            // tokenize text
            for (int i = 0; i < This.Length; i++)
            {
                Char c = This[i];

                if ((c <= 32) || (c == '<') || (c == '>'))
                {
                    if (c == '>')
                        token += '>';

                    if (token.Length > 0)
                        tokens.Add(token);

                    token = "";

                    if (c == '<')
                        token += '<';
                }
                else
                    token += c;
            }

            if (token.Length > 0)
                tokens.Add(token);

            return tokens;
        }
    }

}
