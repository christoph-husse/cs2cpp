using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cs2Cpp
{
    class GenericInstanceGenerator : ASTVisitor_Shared
    {
        public ASTVisitor_Scan Metadata { get { return Assembly.NameManager.Context; } }

        public GenericInstanceGenerator(Assembly part, Assembly whole)
            : base(part, whole, false)
        {

        }

        public string Process()
        {
            WriteLine();

            foreach(var type in Metadata.Structs.Concat(Metadata.Classes).Where(Part.ContainsType))
            {
                foreach (var field in type.Fields)
                {
                    if (!field.IsStatic || field.IsConst || !type.IsGeneric)
                        continue;

                    Write("template<");
                    type.AllTypeParameters.Apply(e => Write("class " + e.GenericParameter.Name + ", "));
                    RemoveBack(",");
                    Write("> ");
                    WriteTypeReference(field.Type, TypeUsage.FieldDecl);
                    Write(" ");
                    WriteMemberReference(field.Raw.Spec);
                    WriteSemicolon();
                }
            }

            WriteLine();

            return Builder.ToString();
        }
    }
}
