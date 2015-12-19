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
    class CppHeaderDebugGenerator : ASTVisitor_Shared
    {
        public ASTVisitor_Scan Metadata { get { return Assembly.NameManager.Context; } }

        public CppHeaderDebugGenerator(Assembly part, Assembly whole)
            : base(part, whole, false)
        {
        }


        public string Process()
        {
            WriteLine();
            WriteLine("static void Constructor_Test() { ");
            using (Indent(4))
            {
                Metadata.Structs.Where(Part.ContainsType).Apply(WriteTypeImplementation);
                Metadata.Classes.Where(Part.ContainsType).Apply(WriteTypeImplementation);
            }
            WriteLine("}");
            WriteLine();

            return Builder.ToString();
        }

        public void WriteTypeImplementation(SCITypeDefinition iface)
        {
            if (iface.IsAbstract)
                return;

            List<SCITypeHandle> args = null;

            if (iface.IsGeneric)
            {
                args = new List<SCITypeHandle>();

                foreach (var param in iface.Handle.AllTypeParameters)
                {
                    if (param.GenericParameter.HasAnyTypeConstraint)
                    {
                        // TODO: provide type arguments which also satisfy possible type constraints
                        return;
                    }

                    args.Add(Metadata.Object.Handle);
                }
            }

            Write("new ");
            WriteTypeReference(iface.Handle, TypeUsage.New, args);
            WriteLine("();");

        }
    }
}
