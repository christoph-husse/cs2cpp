using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Mono.CSharp;
using Delegate = Mono.CSharp.Delegate;
using Enum = Mono.CSharp.Enum;

namespace Cs2Cpp
{
    class Assembly : CompilerPlugin
    {
        private readonly static Dictionary<ITypeDefinition, TypeDefinition> s_TypeMappings = new Dictionary<ITypeDefinition, TypeDefinition>();
        private readonly static HashSet<SCITypeHandle> s_GenericInstanciations = new HashSet<SCITypeHandle>();
        private readonly static Dictionary<object, Assembly> m_AssemblyMapping = new Dictionary<object, Assembly>();
        private string m_TempFile;

        private readonly HashSet<string> m_TypeList = new HashSet<string>();

        public NameManager NameManager { get; private set; }
        public CompilationFramework Framework { get; private set; }
        public AssemblyDefinition Definition { get { return NameManager.CurrentModule.DeclaringAssembly; } }
        public ASTVisitor_Scan Metadata { get { return NameManager.Context; } }
        public String Signature { get; private set; }
        public String[] SourceDirectories { get; private set; }
        public String Name { get; private set; }
        public String NativeModule { get; private set; }
        public String HeaderFile { get; private set; }
        public String QualifiedName { get { return IsMscorlib ? Name : Name + "_" + Signature; } }
        public bool IsMscorlib { get; private set; }
        public bool IsLibrary { get; private set; }
        public IEnumerable<Assembly> Dependencies { get; private set; }
        public IEnumerable<SCITypeHandle> GenericInstanciations { get { return s_GenericInstanciations; } } 

        private static Assembly TryOpenFromSourceDir(string[] sourceDir)
        {
            return m_AssemblyMapping.Select(e => e.Value).FirstOrDefault(
                e => (e.SourceDirectories.Length == sourceDir.Length) && e.SourceDirectories.Zip(sourceDir, Utilities.ArePathsToDirectoryEqual).All(x => x));
        }

        public static Assembly OpenMscorlib(CompilationFramework framework)
        {
            var assembly = TryOpenFromSourceDir(new []{framework.MscorlibSourceDir});

            if (assembly != null)
                return assembly;
            else
                return new Assembly(framework, new[]{framework.MscorlibSourceDir}, isMscorlib: true);
        }

        public static Assembly Open(CompilationFramework framework, string[] sourceDirectory)
        {
            var assembly = TryOpenFromSourceDir(sourceDirectory);

            if (assembly != null)
                return assembly;
            else
                return new Assembly(framework, sourceDirectory, isMscorlib: false);
        }

        private Assembly(CompilationFramework framework, string[] sourceDirectory, bool isMscorlib)
        {
            SourceDirectories = sourceDirectory.ToArray();
            Name = isMscorlib ? "mscorlib" : Path.GetFileName(Path.GetDirectoryName(sourceDirectory.Last() + "/"));
            IsMscorlib = isMscorlib;
            Framework = framework;
            NameManager = new NameManager();

            Console.WriteLine("Loading assembly at \"" + SourceDirectories.Last() + "\".");

            sourceDirectory = sourceDirectory.Select(Path.GetFullPath).ToArray();
            if (sourceDirectory.Any(e => !Directory.Exists(e)))
                throw new ArgumentException("Source code directory \"" + sourceDirectory + "\" does not exist.");


            List<String> mcsArgs;
            try
            {
                if (!IsMscorlib && (sourceDirectory.Length == 1))
                {
                    // TODO: gather dependencies through build file
                    Dependencies = new [] { Assembly.OpenMscorlib(Framework) };
                    IsLibrary = false;
                    m_TempFile = Path.GetTempFileName();
                    NativeModule = m_TempFile;
                    mcsArgs = new List<string>(new String[]
                                                   {
                                                       @"-optimize+",
                                                       @"/warn:0",
                                                       @"/unsafe",
                                                       @"/target:exe",
                                                       @"-sdk:4",
                                                       @"-lib:" + framework.Root + "/lib/",
                                                       //@"-r:Microsoft.CSharp",
                                                       //@"-r:System",
                                                       //@"-r:System.Xml",
                                                       "-out:" + NativeModule,
                                                       @"-define:NET_1_1;NET_2_0;NET_3_0;NET_3_5;NET_4_0",

                                                   });
                }
                else
                {
                    IsLibrary = true;
                    Dependencies = new Assembly[0];
                    NativeModule = framework.Root + "/lib/mscorlib.dll";
                    mcsArgs = new List<string>(new String[]
                                                   {
                                                       @"-optimize+",
                                                       @"-debug-",
                                                       @"/warn:0",
                                                       @"/unsafe",
                                                       @"/target:library",
                                                       @"-nostdlib+",
                                                       @"-sdk:4",
                                                       "-out:" + NativeModule,
                                                       @"-define:INSIDE_CORLIB;LIBC;NET_1_1;NET_2_0;NET_3_0;NET_3_5;NET_4_0"
                                                       ,
                                                   });
                }

                MemoryStream sigData = new MemoryStream();
                foreach (var dir in sourceDirectory)
                {
                    foreach (var file in Directory.GetFiles(dir, "*.cs", SearchOption.AllDirectories))
                    {
                        var bytes = File.ReadAllBytes(file);
                        sigData.Write(bytes, 0, bytes.Length);
                        mcsArgs.Add(file);
                    }
                }

                // compute the unique signature of source code
                var hash = System.Security.Cryptography.SHA1.Create().ComputeHash(sigData);
                long signature = 0;
                for (int i = 0; i < 8; i++)
                {
                    signature |= ((long)hash[i]) << (i * 8);
                }
                Signature = Convert.ToString(signature, 16);

                if (IsMscorlib)
                    HeaderFile = "mscorlib.hpp";
                else
                    HeaderFile = QualifiedName + ".hpp";

                if (IsMscorlib && (sourceDirectory.Length == 1) && !File.Exists(framework.Root + "/lib/mscorlib.dll"))
                {
                    CompilerCallableEntryPoint.Reset();
                    if (!CompilerCallableEntryPoint.InvokeCompiler(mcsArgs.ToArray(), (TextWriter)null))
                        throw new ArgumentException("Assembly could not be loaded. See console output for details.");    
                }

                // compile NET module
                CompilerCallableEntryPoint.Reset();
                if (!CompilerCallableEntryPoint.InvokeCompiler(mcsArgs.ToArray(), this))
                    throw new ArgumentException("Assembly could not be loaded. See console output for details.");

                if (!IsMscorlib && (sourceDirectory.Length == 1))
                {
                    NativeModule = framework.Root + "/lib/" + QualifiedName + ".dll";
                    File.Delete(NativeModule);
                    File.Move(m_TempFile, NativeModule);
                }
            }
            finally
            {
                try
                {
                    if (m_TempFile != null)
                    {
                        File.Delete(m_TempFile);
                        m_TempFile = null;
                    }
                }
                catch
                {
                }
            }
        }

        public static void Reset()
        {
            // reset all static state
            m_AssemblyMapping.Clear();
            s_TypeMappings.Clear();
            s_GenericInstanciations.Clear();
        }

        public static Assembly Resolve(IAssemblyDefinition definition)
        {
            Assembly assembly;
            if(m_AssemblyMapping.TryGetValue(definition, out assembly))
                return assembly;

            if(definition is ImportedAssemblyDefinition)
            {
                var imported = (ImportedAssemblyDefinition)definition;
                var match = m_AssemblyMapping.Select(e => e.Value).FirstOrDefault(e => Utilities.ArePathsToFileEqual(imported.Location, e.NativeModule));

                if(match == null)
                    throw new ArgumentException("Assembly at \"" + imported.Location + "\" was not loaded.");

                m_AssemblyMapping.Add(imported, match);
                return match;
            }
            else
            {
                var def = (AssemblyDefinition)definition;
                throw new ArgumentException("Assembly at \"" + "\" was not loaded.");
            }
        }

        public static Assembly Resolve(IKVM.Reflection.Assembly definition)
        {
            Assembly assembly;
            if (m_AssemblyMapping.TryGetValue(definition, out assembly))
                return assembly;

            var match = m_AssemblyMapping.Select(e => e.Value).FirstOrDefault(e => Utilities.ArePathsToFileEqual(definition.Location, e.NativeModule));

            if (match == null)
                throw new ArgumentException("Assembly at \"" + definition.Location + "\" was not loaded.");

            m_AssemblyMapping.Add(definition, match);
            return match;
        }

        public static Assembly Resolve(TypeDefinition type)
        {
            // TODO: Check for generic instanciation of type defined in different assembly.
            return Resolve(type.DeclaringAssembly);
        }

        public static Assembly Resolve(MemberCore member)
        {
            // TODO: Check for generic instanciation of type defined in different assembly.
            return Resolve(member.Module.DeclaringAssembly);
        }

        public static Assembly Resolve(TypeSpec spec)
        {
            // TODO: Check for generic instanciation of type defined in different assembly.
            return Resolve(spec.MemberDefinition.DeclaringAssembly);
        }

        public TypeDefinition ResolveTypeDefinition(ITypeDefinition type)
        {
            TypeDefinition res;

            if (type is ImportedTypeDefinition)
            {
                var imported = (ImportedTypeDefinition)type;

                if (s_TypeMappings.TryGetValue(imported, out res))
                    return res;

                var assembly = Cs2Cpp.Assembly.Resolve(imported.DeclaringAssembly);
                res = assembly.NameManager.Context.ResolveImportedType(imported.Namespace + "." + imported.Name).Raw;

                s_TypeMappings.Add(imported, res);
                return res;
            }
            else
                return (TypeDefinition) type;
        }

        public static void RegisterGenericInstanciation(SCITypeHandle type)
        {
            if(!type.IsFullyInstanciated || !type.IsGeneric)
                throw new ArgumentException();

            s_GenericInstanciations.Add(type);
        }

        public bool ContainsType(SCITypeDefinition type)
        {
            var def = type.Raw as ITypeDefinition;
            return m_TypeList.Contains(def.Namespace + "." + def.Name);
        }

        public bool ContainsType(Delegate type)
        {
            var def = type as ITypeDefinition;
            return m_TypeList.Contains(def.Namespace + "." + def.Name);
        }

        class ASTVisitor_NameExtract : StructuralVisitorAdapter
        {
            private HashSet<string> m_TypeList = new HashSet<string>();

            public ASTVisitor_NameExtract(HashSet<string> typeList)
            {
                m_TypeList = typeList;
            }

            public void Process(ModuleContainer module)
            {
                module.Accept(this);
            }

            public override object Visit(AnonymousMethodStorey storey)
            {
                return null;
            }

            public override object Visit(ModuleContainer.StaticDataContainer member)
            {
                return null;
            }

            public override object Visit(ModuleContainer mod)
            {
                VisitTypeContainer(mod);

                return null;
            }

            public override object Visit(NamespaceContainer ns)
            {
                VisitTypeContainer(ns);

                return null;
            }

            public override object Visit(Delegate @delegate)
            {
                var def = @delegate.CurrentType.MemberDefinition;
                m_TypeList.Add(def.Namespace + "." + def.Name);

                return null;
            }

            public override object Visit(Enum @enum)
            {
                var def = @enum.CurrentType.MemberDefinition;
                m_TypeList.Add(def.Namespace + "." + def.Name);

                return null;
            }

            private void VisitSIC(TypeDefinition sic)
            {
                foreach (var member in sic.Members)
                {
                    if (member is TypeDefinition)
                        member.Accept(this);
                }

                var def = sic as ITypeDefinition;

                if (sic.IsPartial)
                {
                    // Mono has already merged all partials into one container...
                    if (sic.PartialContainer == sic)
                        m_TypeList.Add(def.Namespace + "." + def.Name);
                }
                else
                {
                    m_TypeList.Add(def.Namespace + "." + def.Name);
                }
            }

            public override object Visit(Struct @struct)
            {
                VisitSIC(@struct);

                return null;
            }

            public override object Visit(Interface iface)
            {
                VisitSIC(iface);

                return null;
            }

            public override object Visit(Class @class)
            {
                VisitSIC(@class);

                return null;
            }
        }

        protected override ECompilerAction AfterEmitButBeforeSaving(ModuleContainer module)
        {
            m_TypeList.Clear();

            m_AssemblyMapping.Add(module.DeclaringAssembly, this);

            if(SourceDirectories.Length == 1)
            {
                var typeScanVisitor = new ASTVisitor_NameExtract(m_TypeList);
                typeScanVisitor.Process(module);
            }
            else
            {
                NameManager.CurrentModule = module;

                // sort interfaces and classes by inheritence and also find all other toplevel types...
                var typeScanVisitor = new ASTVisitor_Scan();
                typeScanVisitor.Process(module, null);

                NameManager.Context = typeScanVisitor;
            }

            return ECompilerAction.Exit;
        }
    }
}
