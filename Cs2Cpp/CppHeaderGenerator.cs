using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Mono.CSharp;
using Delegate = Mono.CSharp.Delegate;
using Enum = System.Enum;

namespace Cs2Cpp
{
    [Serializable]
    class CppHeaderGenerator : ASTVisitor_Shared
    {
        public ASTVisitor_Scan Metadata { get { return Assembly.NameManager.Context; } }
        public Assembly Assembly { get; private set; }

        public CppHeaderGenerator(Assembly part, Assembly whole)
            : base(part, whole, false)
        {
            Assembly = whole;
        }

        public String Process()
        {
            ProcessTypeGroupsByNamespace(Metadata.SICByNamespace, (@struct) =>
                                                                  {
                                                                      using (Assembly.NameManager.EnterType(@struct))
                                                                      {
                                                                          HandleTypeDeclaration(@struct);
                                                                          WriteSemicolon();
                                                                      }
                                                                  });

            var list = new List<SCITypeDefinition>();

            if (Part.IsMscorlib)
            {
                list.Add(Metadata.Object);
                list.Add(Metadata.ValueType);
                list.AddRange(Metadata.EnumType.AllInterfaces.Select(e => e.Definition));
                list.Add(Metadata.EnumType);

                using (Namespace("System"))
                {
                    list.Apply(WriteTypeDefinition);
                }

                WriteLine();
                WriteLine("#include \"cli-enum.hpp\"");
                WriteLine();
            }

            ProcessTypeGroupsByNamespace(Metadata.EnumsByNamespace, WriteEnum);

            using(Namespace("cli"))
            {
                foreach (var e in Metadata.Enums.Where(Part.ContainsType))
                {
					WriteLine("template<> struct enum_to_impl<" + e.FullName + "> { typedef " + e.FullName + "_Impl type; };");
                }
            }

            ProcessTypeGroupsByNamespace(Metadata.DelegatesByNamespace, e => e.Accept(this));

            ProcessTypeGroupsByNamespace(Metadata.InterfacesByInheritence,
                                         e =>
                                         {
                                             if (list.All(x => x != e))
                                                 WriteTypeDefinition(e);
                                         }

                );
            ProcessTypeGroupsByNamespace(Metadata.StructsByDependency, WriteTypeDefinition);
            ProcessTypeGroupsByNamespace(Metadata.ClassesByInheritence,
                                         e =>
                                         {
                                             if (e.Name == "Locale")
                                                 e = e;

                                             if (list.All(x => x != e))
                                                 WriteTypeDefinition(e);
                                         }

                );

            WriteLine();

            return Builder.ToString();
        }

        public override object Visit(Delegate @delegate)
        {
            using (Assembly.NameManager.EnterType(@delegate))
            {
                var type = @delegate.CurrentType;

                if (type.IsGenericRecursively())
                {
                    Write("template<");
                    type.GetAllTypeArguments().Apply(
                        e =>
                        {
                            Write("class ");
                            Write(e.Name);

                            Write(", ");
                        });
                    RemoveBack(",");

                    Write("> using " + SCITypeDefinition.Wrap(type).Name + " = ");
                }
                else
                    Write("typedef ");

                Write("cli::delegate<");
                WriteTypeReference(SCITypeHandle.Wrap(@delegate.MemberType), TypeUsage.ReturnValue);
                Write(" (");
                @delegate.Parameters.FixedParameters.Apply(
                    e =>
                    {
                        var param = (Parameter)e;
                        if (param.Type != null)
                        {
                            if (param.Type.IsGenericParameter)
                                Write(((TypeParameter)param.Type.MemberDefinition).Name);
                            else
                                WriteTypeReference(SCITypeHandle.Wrap(param.Type), TypeUsage.Parameter);
                        }
                        else if (param.TypeExpression != null)
                            param.TypeExpression.Accept(this);
                        else
                            throw new ArgumentException();

                        Write(" ");
                        Write(param.Name);
                        Write(", ");
                    });
                RemoveBack(", ");
                Write(")>");

                if (!type.IsGenericRecursively())
                    Write(" " + SCITypeDefinition.Wrap(type).Name);

                WriteSemicolon();
            }

            return null;
        }

        public void WriteEnum(SCITypeDefinition @enum)
        {
            using (Assembly.NameManager.EnterType(@enum))
            {
                WriteLine();
                WriteLine("enum class " + @enum.Name);
                WriteLine("{");
                using (Indent(4))
                {
                    foreach (var member in @enum.Members)
                    {
                        var em = member as SCIEnumMemberDefinition;

                        Write(em.Name);
                        Write(" = ");

                        if (em.IsSigned)
                            Write(em.Long.ToString());
                        else
                            Write(em.ULong.ToString());

                        WriteLine(",");
                    }
                }
                WriteLine("};");
                WriteLine();

                WriteLine("struct " + @enum.Name + "_Impl : public cli::enumeration<" + @enum.Name + ">");
	            WriteLine("{");
                using (Indent(4))
                {
                    WriteLine(@enum.Name + "_Impl(const " + @enum.Name + "& val) : cli::enumeration<" + @enum.Name + ">(val) { }");
					WriteLine("operator " + @enum.Name + "() { return value; }");
                    WriteLine();

                    WriteLine("virtual const std::vector<" + @enum.Name + ">& GetValues() const override");
                    WriteLine("{");
                    using (Indent(4))
                    {
                        WriteLine("static std::vector<" + @enum.Name + "> res =");
                        WriteLine("{");
                        using (Indent(4))
                        {
                            foreach (var member in @enum.Members)
                            {
                                var em = member as SCIEnumMemberDefinition;
                                WriteLine(@enum.Name + "::" + em.Name + ",");
                            }
                        }
                        WriteLine("};");
                        WriteLine("return res;");
                    }
                    WriteLine("}");
                    WriteLine();
                    WriteLine("virtual const std::vector<::System::String*>& GetStrings() const override");
                    WriteLine("{");
                    using (Indent(4))
                    {
                        WriteLine("static std::vector<::System::String*> res =");
                        WriteLine("{");
                        using (Indent(4))
                        {
                            foreach (var member in @enum.Members)
                            {
                                var em = member as SCIEnumMemberDefinition;
                                WriteLine("_T(\"" + em.Name + "\"),");
                            }
                        }
                        WriteLine("};");
                        WriteLine("return res;");
                    }
                    WriteLine("}");
                }
                WriteLine("};");
                WriteLine();
            }
        }

    }
}
