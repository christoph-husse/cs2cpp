using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Diagnostics;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    enum TypeUsage
    {
        FieldDecl,
        TemplateParameter,
        Parameter,
        ReturnValue,
        VarDecl,
        Pointer,
        New,
        MemberRef,
    }

    [Serializable]
    class ASTVisitor_Shared : CodeWriter
    {
        /// <summary>
        /// Switch between HPP mode (false) and CPP mode (true)
        /// </summary>
        public bool EmitDefinitions { get; set; }
        public Assembly Part { get; private set; }

        public ASTVisitor_Shared(Assembly part, Assembly whole, bool emitDefinitions)
            : base(whole, null)
        {
            EmitDefinitions = emitDefinitions;
            Parent = this;
            Part = part;
        }

        protected override IDisposable EnterNamespace(string[] inNestedNamespace)
        {
            NameManager.CurrentNamespace = inNestedNamespace;
            return base.EnterNamespace(inNestedNamespace);
        }

        protected override void LeaveNamespace(string[] inNestedNamespace)
        {
            NameManager.CurrentNamespace = null;
            base.LeaveNamespace(inNestedNamespace);
        }


        protected void ProcessTypeGroupsByNamespace(IEnumerable<IEnumerable<SCITypeDefinition>> typeGroups, Procedure<SCITypeDefinition> procedure)
        {
            foreach (var group in typeGroups)
            {
                if (group.IsEmpty() || !group.Any(Part.ContainsType))
                    continue;

                using (Namespace(group.First().Namespace))
                {
                    foreach (var type in group)
                    {
                        procedure(type);
                    }
                }
            }
        }


        protected void ProcessTypeGroupsByNamespace(IEnumerable<IEnumerable<Mono.CSharp.Delegate>> typeGroups, Procedure<Mono.CSharp.Delegate> procedure)
        {
            foreach (var group in typeGroups)
            {
                if (group.IsEmpty() || !group.Any(Part.ContainsType))
                    continue;

                using (Namespace(group.First().GetNamespace()))
                {
                    foreach (var type in group)
                    {
                        procedure(type);
                    }
                }
            }
        }

        public void WriteTypeDefinition(SCITypeDefinition iface)
        {
            using (NameManager.EnterType(iface))
            {
                var builtin = iface.GetBuiltinName();

                WriteLine();
                HandleTypeDeclaration(iface);
                WriteInheritenceList(iface);
                WriteLine("{");
                using (Indent(4))
                {
                    iface.Fields.Apply(WriteFieldDeclaration);
                    WriteLine();

                    if(iface.BuiltinType == BuiltinTypeSpec.Type.Object)
                        WriteLine("virtual ~Object() { }");


                    String paramlessCtor = " = default;", structDerefCtor = ";";
					Boolean emitStaticConstructor = true;

                    if (builtin != null)
                    {
                        // find out data storage field
                        var fields = iface.Fields.Where(e => !e.IsStatic).ToArray();

                        if (fields.Length != 1)
                            throw new ApplicationException();

                        var field = fields[0];
                        if (field.Type.IsPointer)
                        {
                            if ((iface.BuiltinType != BuiltinTypeSpec.Type.UIntPtr) && (iface.BuiltinType != BuiltinTypeSpec.Type.IntPtr))
                                throw new ApplicationException();
                        }
                        else
                        {
                            if (field.Type.Definition.BuiltinType != iface.BuiltinType)
                                throw new ApplicationException();
                        }

                        // add type conversion operators
                        WriteLine(iface.Name + "(" + builtin + " const& value) : " + field.Name + " (value) { }");
                        WriteLine("operator " + builtin + "() { return " + field.Name + "; }");
                        WriteLine("typedef " + builtin + " TBuiltinType;");
                        structDerefCtor = " : " + field.Name + " (src->" + field.Name + ") { }";
                    }

					if (iface.FullOriginalName == "System.Nullable<T>")
                    {
                        WriteLine("bool operator !=(const std::nullptr_t& b) { return has_value; }");
                        WriteLine("bool operator ==(const std::nullptr_t& b) { return !has_value; }");
                        WriteLine(iface.Name + "(const std::nullptr_t& np) : value(), has_value(false) { }");
                        WriteLine(iface.Name + "(const T& src) : value(src), has_value(true) { }");
                        WriteLine("operator T() { return get_Value(); }");

                        paramlessCtor = " : value(), has_value(false) { }";
                        structDerefCtor = " : value(src->value), has_value(src->has_value) { }";

						emitStaticConstructor = false;
                    }
                    
                    if (iface.IsStruct)
                    {
                        WriteTypeReference(iface.Handle, TypeUsage.New);
                        WriteLine("* operator ->() { return this; }");

                        Write(iface.Name);
                        WriteLine("()" + paramlessCtor);

                        Write(iface.Name);
                        Write("(const ");
                        WriteTypeReference(iface.Handle, TypeUsage.New);
                        WriteLine("* src)" + structDerefCtor);

                        Write("operator ");
                        WriteTypeReference(iface.Handle, TypeUsage.New);
                        Write("*() { return ::cli::box<");
                        WriteTypeReference(iface.Handle, TypeUsage.New);
                        WriteLine("*>(this); }");

                        WriteLine();

						emitStaticConstructor = false;
                    }

					if(iface.HasStaticConstructor && emitStaticConstructor)
						WriteLine(iface.Name + "();");

                    iface.Methods.Apply(WriteMethod);
                    WriteLine();
                    iface.Handle.InstanceMethods.Apply(e => e.Definition.Implements.Apply(i => WriteInterfaceMethodProxy(ECppGenPass.Both, iface.Handle, i, e)));
                    iface.InterfaceProxies.Apply(e => WriteInterfaceMethodProxy(ECppGenPass.Both, iface.Handle, e.Key, e.Value));
                }
                WriteLine("};");
                WriteLine();
            }
        }

        private void WriteFieldDeclaration(SCIFieldDefinition field)
        {
            if (field.IsConst)
            {
                var builtin = field.Type.Definition.BuiltinType;

                if ((builtin == BuiltinTypeSpec.Type.String) || (builtin == BuiltinTypeSpec.Type.Decimal))
                {
                    Write("static /*constexpr*/ ");
                    WriteTypeReference(field.Type, TypeUsage.FieldDecl);
                    Write(" ");
                    Write(field.Name);
                    Write("() { return ");
                    Write(field.ConstExpression);
                    WriteLine("; }");
                }
                else
                {
                    Write("static constexpr ");
                    WriteTypeReference(field.Type, TypeUsage.FieldDecl);
                    Write(" ");
                    Write(field.Name);
                    Write(" = ");
                    Write(field.ConstExpression);
                    WriteLine(";");
                }
            }
            else
            {
                if (field.IsStatic)
                    Write("static ");

                WriteFieldTypeReference(field);
                Write(field.Name);
                WriteSemicolon();
            }
        }

        protected  void WriteFieldTypeReference(SCIFieldDefinition field)
        {
            WriteTypeReference(field.Type, TypeUsage.FieldDecl);
            Write((field.IsRecursive && field.IsStatic ? "*" : "") + " ");
        }

        private void WriteInheritenceList(SCITypeDefinition type)
        {
            if ((type.BaseClass != null) || !type.NewInterfaces.IsEmpty())
            {
                Write(" : ");

                if (type.BaseClass != null)
                {
                    Write("public virtual ");
                    HandleTypeSpec(type.BaseClass);
                    Write(", ");
                }

                if (!type.NewInterfaces.IsEmpty())
                {
                    type.NewInterfaces.Apply(e =>
                    {
                        Write("public virtual ");
                        HandleTypeSpec(e);
                        Write(", ");
                    });
                }

                RemoveBack(",");
            }
        }


        public void HandleTypeDeclaration(SCITypeDefinition type)
        {

            if (type.IsGeneric)
            {
                Write("template<");
                type.TypeArgumentsOfParentScope.Concat(type.TypeParameters).Apply(e =>
                {
                    if (e.IsGenericParameter)
                    {
                        Write("class ");
                        Write(e.GenericParameter.Name);
                    }
                    else
                        WriteTypeReference(e, TypeUsage.TemplateParameter);

                    Write(", ");
                });
                RemoveBack(",");
                Write("> struct MANAGED_API ");
                Write(type.Name);
            }
            else
                Write("struct MANAGED_API " + type.Name);
        }

        public override object Visit(ConstInitializer init)
        {
            init.Expr.Accept(this);

            return null;
        }

        internal T ResolveMember<T>(MemberSpec member) where T : SCIMemberDefinition
        {
            var type = SCITypeHandle.Wrap(member.DeclaringType);
            return (T)type.Definition.ResolveMember(member);
        }

        internal void WriteMemberReference(MemberSpec member)
        {
            var type = SCITypeHandle.Wrap(member.DeclaringType);
            var name = type.Definition.ResolveMember(member).Name;

            if (((NameManager.CurrentType != null) && (NameManager.CurrentType.Handle == type)) || !member.IsStatic)
                Write(name);
            else
            {
                WriteTypeReference(type, TypeUsage.New);
                Write("::");
                Write(name);
            }
            
        }

        public void WriteTypeReference(SCITypeHandle type, TypeUsage usage, IEnumerable<SCITypeHandle> typeArguments = null )
        {
            if (usage == TypeUsage.New)
            {
                if (type.IsIntPtr)
                {
                    Write("::System::IntPtr");
                    return;
                }
            }

            if (usage == TypeUsage.MemberRef)
                usage = TypeUsage.New;

            HandleTypeSpec(type, usage != TypeUsage.New, usage != TypeUsage.New, typeArguments);

            if (usage != TypeUsage.New)
            {
                if (type.IsDefinition)
                {
                    var def = type.Definition;

                    if (def.IsInterface || def.IsClass)
                        Write("*");
                }
                else if(type.IsArray)
                    Write("*");
            }
        }

        public void HandleTypeSpec(SCITypeHandle type, bool resolveBuiltinTypes = false, bool resolveVoid = true, IEnumerable<SCITypeHandle> typeArguments = null)
        {
            if (typeArguments != null)
            {
                if (type.IsGenericParameter || !type.HasTypeArguments)
                    throw new ArgumentException("Type arguments can only be given for generic types.");

                if(typeArguments.Count() != type.AllTypeArguments.Count)
                    throw new ArgumentException("Number of explicit type arguments must match the expected type parameter count.");
            }

            typeArguments = typeArguments ?? type.AllTypeArguments;

            if (type.IsArray)
            {
                Write("cli::array<");
                WriteTypeReference(type.Indirection, TypeUsage.TemplateParameter);
                Write(">");
            }
            else if (type.IsPointer)
            {
                WriteTypeReference(type.Indirection, TypeUsage.Pointer);
                Write("*");
            }
            else if (!type.IsGenericParameter && type.HasTypeArguments)
            {
                Write(type.Definition.ComputeReferenceName(resolveBuiltinTypes, resolveVoid));
                Write("<");
                typeArguments.Apply(e =>
                {
                    WriteTypeReference(e, TypeUsage.TemplateParameter);
                    Write(", ");
                });
                RemoveBack(",");
                Write(">");
            }
            else
            {
                if (type.IsGenericParameter)
                    Write(type.GenericParameter.Name);
                else
                    Write(type.Definition.ComputeReferenceName(resolveBuiltinTypes, resolveVoid));
            }
        }

        public void WriteMethod(SCIMethodDefinition method)
        {
            using (NameManager.EnterMethod(method))
            {
                if ((NameManager.CurrentType.IsInterface || method.IsAbstract) && EmitDefinitions)
                    return;

                if (EmitDefinitions)
                {
                    // TODO: for this to work, each assembly needs to be translated immediately after MCS has compiled it
                    // WriteLine("// " + method.Location);

                    if (method.Parent.IsGeneric)
                    {
                        Write("template<");
                        method.Parent.AllTypeParameters.Apply(e => Write("class " + e.GenericParameter.Name + ", "));
                        RemoveBack(",");
                        WriteLine(">");
                    }
                }

                if (method.HasTypeParameters)
                {
                    Write("template<");
                    method.TypeParameters.Apply(e => Write("class " + e.GenericParameter.Name + ", "));
                    RemoveBack(",");
                    WriteLine(">");
                }

                if (!EmitDefinitions)
                {
                    if (method.IsStatic)
                        Write("static ");

                    if (method.IsVirtual || method.IsAbstract || method.IsFinalizer)
                        Write("virtual ");
                }

                if (method.IsSetter && method.Property.HasGetter)
                {
                    WriteTypeReference(method.Property.Getter.ReturnType, TypeUsage.ReturnValue);
                }
                else
                {
                    if (method.ReturnType != null)
                        WriteTypeReference(method.ReturnType, TypeUsage.ReturnValue);
                    else
                        Write("void");
                }

                Write(" ");

                if (EmitDefinitions)
                {
                    WriteTypeReference(method.Parent.Handle, TypeUsage.MemberRef);
                    Write("::" + method.Name + "(");
                }
                else
                    Write(method.Name + "(");

                WriteMethodParameters(method.Parameters.Select(e => e.Type), method.Parameters.Select(e => e.Name));
                Write(")");

                if (!NameManager.CurrentType.IsInterface && !method.IsAbstract)
                {
                    if (EmitDefinitions)
                    {
                        WriteMethodBody(method);
                    }
                    else
                    {
                        WriteMethodsPolymorphicModifier(method);
                        Write(";");
                    }
                }
                else
                {
                    WriteMethodsPolymorphicModifier(method);
                    Write(" = 0;");
                }

                WriteLine();
            }
        }

        protected virtual void WriteMethodBody(SCIMethodDefinition method)
        {
        }

        protected void WriteMethodParameters(IEnumerable<SCITypeHandle> paramTypes, IEnumerable<String> paramNames)
        {
            foreach (var param in paramTypes.Zip(paramNames))
            {
                if (param.Key.IsVariableArgumentList)
                {
                    Write("...");
                }
                else
                {
                    WriteTypeReference(param.Key, TypeUsage.Parameter);

                    Write(" ");
                    Write(param.Value);
                }

                Write(", ");
            }

            RemoveBack(",");
        }

        private void WriteMethodsPolymorphicModifier(SCIMethodDefinition method)
        {
            if (method.IsNew)
                Write(" /*new*/"); // C++ has no modifier for that one, but we still emit it as a comment for clarity
            else if (method.IsSealed)
                Write(" final");
            else if (method.DoesOverride)
                Write(" override");
        }

        protected void WriteInterfaceMethodProxy(ECppGenPass pass, SCITypeHandle @class, SCIMethodHandle iface, SCIMethodHandle impl)
        {
            var implDef = impl.Definition;
            var ifaceDef = iface.Definition;
            bool isGeneric = impl.DeclaringType.AllTypeParameters.Any();

            if (isGeneric && EmitDefinitions && ((pass & ECppGenPass.Template) == 0))
                return;

            if (!isGeneric && EmitDefinitions && ((pass & ECppGenPass.NonTemplate) == 0))
                return;

            if (EmitDefinitions)
            {
                WriteLine("// Automatically generated method stub");

                if (isGeneric)
                {
                    Write("template<");
                    impl.DeclaringType.AllTypeParameters.Apply(e => Write("class " + e.GenericParameter.Name + ", "));
                    RemoveBack(",");
                    WriteLine(">");
                }
            }

            if(!EmitDefinitions)
                Write("virtual ");

            if (implDef.IsSetter && implDef.Property.HasGetter)
            {
                WriteTypeReference(implDef.Property.Getter.ReturnType, TypeUsage.ReturnValue);
            }
            else
            {
                if (implDef.ReturnType != null)
                    WriteTypeReference(implDef.ReturnType, TypeUsage.ReturnValue);
                else
                    Write("void");
            }

            Write(" ");

            if (EmitDefinitions)
            {
                WriteTypeReference(@class, TypeUsage.New);
                Write("::" + ifaceDef.Name + "(");
            }
            else
                Write(ifaceDef.Name + "(");

            WriteMethodParameters(implDef.Parameters.Select(e => e.Type), implDef.Parameters.Select(e => e.Name));
            Write(")");

            if (!EmitDefinitions)
            {
                WriteLine(" override;");
            }
            else
            {
                WriteLine(" {");

                if (iface.ReturnType != null)
                    Write("    return ");

                Write(implDef.Name);
                Write("(");
                implDef.Parameters.Apply(e =>
                {
                    Write(e.Name);
                    Write(", ");
                });
                RemoveBack(", ");

                WriteLine(");");
                WriteLine("}");
                WriteLine();
            }
        }

        public override object Visit(Constant constant)
        {
            dynamic c = constant;

            if (constant is Mono.CSharp.BoolConstant)
            {
                Write(c.Value ? "true" : "false");
            }
            else if (constant is Mono.CSharp.CharConstant)
            {
                char ch = c.Value;


                if ((ch >= 32) && (ch <= 'z'))
                    Write("u'" + ((ch == '\\') || (ch == '\'') ? "\\" : "") + ch + "'");
                else
                    Write("u'\\x" + Convert.ToString(c.Value, 16) + "'");
            }
            else if (constant is Mono.CSharp.DecimalConstant)
            {
                Write("cli::decimal<int>(\"" + c.Value.ToString() + "\")");
            }
            else if (constant is Mono.CSharp.DoubleConstant)
            {
                double value = c.Value;

                if (double.IsNaN(value)) Write("std::numeric_limits<double>::quiet_NaN()");
                else if (double.IsPositiveInfinity(value)) Write("std::numeric_limits<double>::infinity()");
                else if (double.IsNegativeInfinity(value)) Write("-std::numeric_limits<double>::infinity()");
                else if (double.MaxValue <= value) Write("std::numeric_limits<double>::max()");
                else if (double.MinValue >= value) Write("std::numeric_limits<double>::min()");
                else if (double.Epsilon >= value) Write("std::numeric_limits<double>::epsilon()");
                else
                {
                    var v = value.ToString().Replace(",", ".");
                    if (!v.Contains("."))
                        v += ".";

                    Write(v);
                }
            }
            else if (constant is Mono.CSharp.FloatConstant)
            {
                float value = c.Value;

                if (float.IsNaN(value)) Write("std::numeric_limits<float>::quiet_NaN()");
                else if (float.IsPositiveInfinity(value)) Write("std::numeric_limits<float>::infinity()");
                else if (float.IsNegativeInfinity(value)) Write("-std::numeric_limits<float>::infinity()");
                else if (float.MaxValue <= value) Write("std::numeric_limits<float>::max()");
                else if (float.MinValue >= value) Write("std::numeric_limits<float>::min()");
                else if (float.Epsilon >= value) Write("std::numeric_limits<float>::epsilon()");
                else
                {
                    var v = value.ToString().Replace(",", ".");
                    if (!v.Contains("."))
                        v += ".";

                    Write(v + "f");
                }
            }
            else if (constant is Mono.CSharp.IntConstant)
            {
                Write(c.Value.ToString());
            }
            else if (constant is Mono.CSharp.ByteConstant)
            {
                Write(c.Value.ToString());
            }
            else if (constant is Mono.CSharp.SByteConstant)
            {
                Write(c.Value.ToString());
            }
            else if (constant is Mono.CSharp.ShortConstant)
            {
                Write(c.Value.ToString());
            }
            else if (constant is Mono.CSharp.UShortConstant)
            {
                Write(c.Value.ToString());
            }
            else if (constant is Mono.CSharp.LongConstant)
            {
                if (c.Value == Int64.MinValue)
                {
                    /* Clang developers:
                     *  "9223372036854775808L" doesn't fit into a signed long; "-9223372036854775808L" does, but the standard states
                     *  that we aren't allowed to take that into account when we parse integer literals.
                     */
                    Write("(-" + Int64.MaxValue + "L - 1)");
                }
                else
                    Write(c.Value + "L");
            }
            else if (constant is Mono.CSharp.NullConstant)
            {
                Write("nullptr");
            }
            else if (constant is Mono.CSharp.StringConstant)
            {
                String escaped = "";
                var chars = new object[] { '\"', "\\\"", '\\', "\\\\", '\0', "\\0", '\a', "\\a", 
                    '\b', "\\b", '\f', "\\f", '\n', "\\n", '\r', "\\r",  '\t', "\\t",
                    '\v', "\\v", '\'', "\\'",};

                foreach (var ch in c.Value)
                {
                    bool hasChar = false;

                    for (int i = 0; i < chars.Length; i += 2)
                    {
                        if (ch == (char) chars[i])
                        {
                            escaped += chars[i + 1];
                            hasChar = true;
                            break;
                        }
                    }

                    if (!hasChar)
                        escaped += ch;
                }

                Write("_T(\"" + escaped + "\")");
            }
            else if (constant is Mono.CSharp.UIntConstant)
            {
                Write(c.Value + "U");
            }
            else if (constant is Mono.CSharp.ULongConstant)
            {
                Write(c.Value + "UL");
            }
            else if (constant is EnumConstant)
            {
                var v = constant as EnumConstant;
                var enumType = SCITypeDefinition.Wrap(v.Type);

                if (!(v.Child is IntegralConstant))
                    throw new ArgumentException();

                if (NameManager.CurrentType == enumType)
                    throw new ApplicationException();

                // does integral value refer to valid enum member?
                SCIEnumMemberDefinition match = null;

                // is composed of flags?
                bool isFlags = enumType.Raw.Attributes.Any(
                    e =>
                    {
                        var name = e.Expr as SimpleName;
                        if (name == null)
                            return false;

                        return name.Name == "Flags";
                    });

                foreach (var member in enumType.Members)
                {
                    var entry = (member as SCIEnumMemberDefinition);

                    if (entry.Long == v.GetValueAsLong())
                    {
                        match = entry;
                        break;
                    }
                }

                if (match == null)
                {
                    Write("(");
                    WriteTypeReference(SCITypeHandle.Wrap(v.Type), TypeUsage.VarDecl);
                    Write(")");
                    Write(v.GetValueAsLong() + "L");
                }
                else
                {
                    WriteTypeReference(SCITypeHandle.Wrap(v.Type), TypeUsage.New);
                    Write("::");
                    Write(match.Name);
                }
            }
            else if (constant is ReducedExpression.ReducedConstantExpression)
            {
                var origValue = c.Original as Constant;

                if (origValue == null)
                    throw new ArgumentException();

                Visit(origValue);
            }
            else throw new ArgumentException();

            return null;
        }
    }

}
