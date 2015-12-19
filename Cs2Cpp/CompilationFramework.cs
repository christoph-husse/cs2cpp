using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    public class CompilationFramework : CompilerPlugin
    {
        public String Root { get; private set; }
        public bool DevelopmentMode { get; set; }
        public String MscorlibSourceDir { get; private set; }
        public String CMakeListsExecutableTemplate { get; private set; }
        public String CMakeListsDevExecutableTemplate { get; private set; }

        public CompilationFramework(string frameworkRoot, string mscorlibSourceDir)
        {
            MscorlibSourceDir = Path.GetFullPath(mscorlibSourceDir);
            Root = Path.GetFullPath(frameworkRoot);

            if (!Directory.Exists(Root))
                throw new ArgumentException("The given mscorlib source directory \"" + mscorlibSourceDir + "\" is invalid.");

            if(!Directory.Exists(Root) || 
                    !Directory.Exists(Root + "/cli") || 
                    !Directory.Exists(Root + "/cli/dev") || 
                    !Directory.Exists(Root + "/cli/include") ||
                    !Directory.Exists(Root + "/cli/templates") ||
                    !Directory.Exists(Root + "/lib") || 
                    !Directory.Exists(Root + "/include"))
                throw new ArgumentException("The given framework root directory \"" + Root + "\" is invalid.");

            CMakeListsDevExecutableTemplate = File.ReadAllText(Root + "/cli/templates/CMakeLists_DevExecutable.txt");
            CMakeListsExecutableTemplate = File.ReadAllText(Root + "/cli/templates/CMakeLists_Executable.txt");
        }

        public bool Compile(string sourceDirectory)
        {
            string cppFileDir = Root + "/src/";

            StaticStateResetter.Reset();
            var assembly = Assembly.Open(this, new[]{sourceDirectory});

            if (Directory.Exists(cppFileDir))
            {
                Directory.Delete(cppFileDir, true);
                Thread.Sleep(500);
            }
            Directory.CreateDirectory(cppFileDir);

            var combinedAsm = Assembly.Open(this, assembly.Dependencies.Select(e => e.SourceDirectories.Last()).Union(new[]{sourceDirectory}).ToArray());
            int r=0;
            CompileAssembly(assembly, combinedAsm, ref r);

            if (DevelopmentMode)
            {
                string cppFiles = "";
                for (int i = 0; i < r; i++)
                    cppFiles += "list(APPEND sources \"${CMAKE_SOURCE_DIR}/src/" + i + ".cpp\")";

                WriteFile(cppFileDir + "CMakeLists.txt",
                          CMakeListsDevExecutableTemplate.Replace("{%NAME%}", assembly.QualifiedName).Replace(
                              "{%CPPFILES%}", cppFiles));
            }
            else
            {
                WriteFile(cppFileDir + "CMakeLists.txt",
                          CMakeListsExecutableTemplate.Replace("{%NAME%}", assembly.QualifiedName));
            }

            CompileAssembly(assembly.Dependencies.First(), combinedAsm, ref r);

            return true;
        }

        private static void WriteFile(String path, String content)
        {
            try
            {
                File.Delete(path);
            }
            catch
            {

            }

            File.WriteAllText(path, content);
        }


        private static bool CompileAssembly(Assembly part, Assembly whole, ref int iFile)
        {
            Console.WriteLine("Generating C++ code for \"" + part.SourceDirectories.Last() + "\"...");

            // translate to C++
            var framework = whole.Framework;
            string incFileContent = new CppHeaderGenerator(part, whole).Process();
            string templateIncFileContent = new CppSourceGenerator(part, whole).Process(ECppGenPass.Template) + new GenericInstanceGenerator(part, whole).Process();
            var cppFileContent = new List<String>();
            string cppStoryHeader = new CppSourceGenerator(part, whole).Process(ECppGenPass.NonTemplate, cppFileContent.Add);

            // write files
            string incFile = framework.Root + "/include/" + part.QualifiedName + ".hpp";
            string templateIncFile = framework.Root + "/include/" + part.QualifiedName + ".template.hpp";
            string cppFileDir = framework.Root + "/src/";
            string stdafx = "stdafx_" + part.QualifiedName + ".hpp";

            if (part.IsMscorlib)
                incFileContent = "#include \"cli-predecl.hpp\"\r\n\r\n" + incFileContent + "\r\n\r\n#include \"cli.hpp\"\r\n" + "#include \"" + templateIncFile + "\"\r\n";
			else
				incFileContent += "#include \"" + templateIncFile + "\"\r\n";

            WriteFile(incFile, incFileContent);
            WriteFile(templateIncFile, templateIncFileContent);

            for (int i = 0; i < cppFileContent.Count; i++, iFile++)
            {
                var content = "#include \"" + stdafx + "\"\r\n\r\n" + cppFileContent[i];

                if (!part.IsLibrary && (iFile == 0))
                {
                    // add main() routine
                    SCIMethodDefinition main = null;
                    foreach(var @class in whole.Metadata.Classes.Where(part.ContainsType))
                    {
                        foreach (var method in @class.Methods)
                        {
                            if (!((method.ReturnType == null) || method.ReturnType.IsVoid ||
                                  (method.ReturnType.IsDefinition &&
                                   (method.ReturnType.Definition.BuiltinType == BuiltinTypeSpec.Type.Int))))
                                continue;

                            if (method.HasTypeParameters || !method.IsStatic || !method.HasBody ||
                                (method.Parameters.Count() != 1) ||
                                (method.Name != "Main"))
                                continue;

                            var param = method.Parameters.First();
                            if (!param.Type.IsArray || !param.Type.Indirection.IsDefinition ||
                                (param.Type.Indirection.Definition.BuiltinType != BuiltinTypeSpec.Type.String))
                                continue;

                            main = method;
                            break;
                        }
                    }

                    content += "\r\n\r\nDEFINE_MAIN_ROUTINE(" + main.FullName + ");\r\n";
                }

                if (iFile == 0)
                    content += new CppHeaderDebugGenerator(part, whole).Process();

                WriteFile(cppFileDir + iFile + ".cpp", content);
            }

            var headers = part.Dependencies.Concat(new[] { part }).Aggregate("", (r, e) => r + "#include \"" + e.HeaderFile + "\"\r\n");
            WriteFile(cppFileDir + stdafx, headers + "\r\n" + cppStoryHeader);


            return true;
        }
    }
}
