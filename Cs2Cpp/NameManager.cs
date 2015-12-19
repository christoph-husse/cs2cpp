using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Security.Cryptography;
using System.IO;
using Mono.CSharp;

namespace Cs2Cpp
{
    [Serializable]
    class NameManager
    {
        private const bool RANDOMIZE_NAMES = false;
        private readonly Stack<TypeScope> m_TypeNesting = new Stack<TypeScope>();
		private readonly Stack<AnonymousMethodBody> m_LambdaStack = new Stack<AnonymousMethodBody>();
        private static readonly HashSet<String> m_Keywords = new HashSet<String>();

        [Serializable]
        private class ModuleContextStub : IModuleContext
        {
            public ModuleContainer Module { get; set; }
        }

        private ModuleContextStub m_ModContext = new ModuleContextStub();

        public IModuleContext ModuleContext
        {
            get
            {
                m_ModContext.Module = CurrentModule;
                return m_ModContext;
            }
        }

        public ModuleContainer CurrentModule { get; set; }
        public ASTVisitor_Scan Context { get; set; }
        public SCITypeDefinition CurrentType { get { return (m_TypeNesting.Count == 0) ? null : m_TypeNesting.Peek().Type; } }
		public AnonymousMethodBody CurrentLambda { get { return (m_LambdaStack.Count == 0) ? null : m_LambdaStack.Peek(); } }
        public SCIMethodDefinition CurrentMemberMethod
        {
            get { return (m_TypeNesting.Count == 0) ? null : m_TypeNesting.Peek().CurrentMethod; }
            set { m_TypeNesting.Peek().CurrentMethod = value; }
        }
        public String[] CurrentNamespace { get; set; }

		[Serializable]
        private class LambdaScope : IDisposable
        {
            public AnonymousMethodBody Method { get; private set; }
			public NameManager Parent { get; private set; }

            public LambdaScope(NameManager parent, AnonymousMethodBody method)
            {
                Parent = parent;
                Method = method;
				Parent.m_LambdaStack.Push(method);
            }

            public void Dispose()
            {
                if(Parent.m_LambdaStack.Pop() != Method)
					throw new ApplicationException();

                Method = null;
            }
        }

        [Serializable]
        private class TypeScope : IDisposable
        {
            public SCITypeDefinition Type { get; private set; }
            public SCIMethodDefinition CurrentMethod { get; set; }

            public TypeScope(SCITypeDefinition inType)
            {
                Type = inType;
            }

            public void Dispose()
            {
                Type.NameManager.LeaveType(Type);
                Type = null;
            }
        }

        [Serializable]
        private class MemberScope : IDisposable
        {
            private SCIMemberDefinition m_Member;

            public MemberScope(SCIMemberDefinition inMember)
            {
                m_Member = inMember;
            }

            public void Dispose()
            {
                m_Member.NameManager.LeaveMethod(m_Member);
                m_Member = null;
            }
        }


        static NameManager()
        {
            List<String> keywords = new List<string>();
            keywords.AddRange(new String[]{
                "alignas","alignof", "and", "and_eq", "asm", "auto,", 
                "bitand", "bitor", "bool", "break", "case", "catch", "char", "char16_t", "char32_t",
                "class", "compl", "const", "constexpr", "const_cast", "continue", "decltype",
                "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export",
                "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable",
                "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private",
                "protected", "public", "register", "reinterpret_cast", "return", "short", "signed", "sizeof",
                "static", "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local",
                "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual",
                "void", "volatile", "wchar_t", "while", "xor", "xor_eq", "char16_t", 
                
                // special keywords introduced by our compiler
                "cli", "constructor", "gcnew", "static_constructor",
             });

            // I hate C++ macros. Wipe them out! This is only a desperate attempt to resolve conflicts...
            keywords.AddRange(new String[]{
                "stderr", "stdin", "stdout",
            });

            keywords.Apply(e => m_Keywords.Add(e));
        }

		public IDisposable EnterLambda(AnonymousMethodBody method)
        {
            return new LambdaScope(this, method);
        }

        public IDisposable EnterType(ITypeDefinition type)
        {
            return EnterType(SCITypeDefinition.Wrap(type));
        }

        public IDisposable EnterType(SCITypeDefinition type)
        {
            m_TypeNesting.Push(new TypeScope(type));
            return m_TypeNesting.Peek();
        }

        private void LeaveType(SCITypeDefinition type)
        {
            if (m_TypeNesting.Pop().Type != type)
                throw new ApplicationException();
        }

        public IDisposable EnterMethod(SCIMethodDefinition member)
        {
            CurrentMemberMethod = member;
            return new MemberScope(member);
        }

        private void LeaveMethod(SCIMemberDefinition member)
        {
            CurrentMemberMethod = null;
        }

        private readonly Random rnd = new Random();

        internal String UndecorateName(String decorated)
        {
            String res = new String(decorated.Select(e =>
                {
                    if (Char.IsLetterOrDigit(e) || (e == '_'))
                        return e;
                    else
                        return '_';
                }).ToArray()) + (RANDOMIZE_NAMES ? ("_" + rnd.Next()) : "");

            while (m_Keywords.Contains(res))
                res = res + "_";

            return res;
        }

        internal String ImportName(String undecorated, IEnumerable<String> reserved)
        {
            int i = 2;
            string res = undecorated;

            while (reserved.Contains(res))
                res = undecorated + (i++);

            return res;
        }

        internal String ResolveVariableDeclaration(ILocalVariable local_)
        {
            return (CurrentMemberMethod as SCIMethodDefinition).DeclareVariable(local_).Name;
        }

        internal String ResolveVariableReference(ILocalVariable local_)
        {
            return (CurrentMemberMethod as SCIMethodDefinition).ResolveVariable(local_).Name;
        }

        internal String ResolveLocalReference(ILocalVariable local_)
        {
            return (CurrentMemberMethod as SCIMethodDefinition).ResolveLocal(local_).Name;
        }
    }
}
