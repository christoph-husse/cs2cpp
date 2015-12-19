using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Mono.CSharp;


namespace Cs2Cpp
{
    [Serializable]
    class CodeWriterState
    {
        public StringBuilder Builder = new StringBuilder();
        public bool IsNewLine = false;
        public int LineIndent = 0;
        public int InsertAt = -1;
        public bool ConsoleOutput = false;
    }

    [Serializable]
    class ASTVisitorBase : StructuralVisitorAdapter
    {
        public CodeWriterState CodeWriterState { get; private set; }

        public ASTVisitorBase()
        {
            CodeWriterState = new CodeWriterState();
        }

    }

    [Serializable]
    class CodeWriter : ASTVisitorBase
    {
        public ASTVisitorBase Parent { get; protected set; }
        public Assembly Assembly { get; private set; }
        public NameManager NameManager { get { return Assembly.NameManager; } }
        public StringBuilder Builder { get { return State.Builder; } }
        private bool IsNewLine { get { return State.IsNewLine; } }
        private int LineIndent { get { return State.LineIndent; } }
        protected CodeWriterState State { get { return Parent.CodeWriterState; } }
        public String AlternateSemicolon { get; set; }

        protected CodeWriter(Assembly assembly, ASTVisitorBase inParent)
        {
            Assembly = assembly;
            Parent = inParent;
        }

        public virtual void Reset()
        {
            Builder.Clear();
        }

        protected void WriteSemicolon()
        {
            if (AlternateSemicolon != null)
            {
                Write(AlternateSemicolon);
            }
            else
            {  
                if (RemoveBack("\r\n"))
                    State.IsNewLine = false;

                WriteLine(";");
            }
        }

        [Serializable]
        private class PrivateBuilderImpl : IDisposable
        {
            private StringBuilder m_Backup;
            private CodeWriter m_Parent;
            private CodeWriterState m_OldState;

            public PrivateBuilderImpl(CodeWriter parent)
            {
                m_Parent = parent;
                m_Backup = parent.Builder;
                m_OldState = new CodeWriterState()
                                 {
                                      IsNewLine = parent.State.IsNewLine,
                                      LineIndent = parent.State.LineIndent,
                                 };
                m_Parent.State.LineIndent = 0;
                m_Parent.State.IsNewLine = false;
                parent.State.Builder = new StringBuilder();
            }

            public void Dispose()
            {
                m_Parent.State.Builder = m_Backup;
                m_Parent.State.IsNewLine = m_OldState.IsNewLine;
                m_Parent.State.LineIndent = m_OldState.LineIndent;
            }

            public override string ToString()
            {
                return m_Parent.Builder.ToString();
            }
        }

        protected IDisposable PrivateBuilder()
        {
            return new PrivateBuilderImpl(this);
        }


        public void Write(String value)
        {
            String line = "";

            if (IsNewLine)
            {
                line = new String(' ', LineIndent);
                State.IsNewLine = false;
            }

            line += value;

            if(State.ConsoleOutput)
                Console.Write(line);

            if (State.InsertAt == -1)
                Builder.Append(line);
            else
            {
                Builder.Insert(State.InsertAt, line);
                State.InsertAt += line.Length;
            }

            CheckBreakpoints();
        }

        public bool WasStaticDereference()
        {
            if ((Builder[Builder.Length - 1] == ':') && (Builder[Builder.Length - 2] == ':'))
                return true;

            return false;
        }

        public int GetMarker()
        {
            return Builder.Length;
        }

        public void ReplaceInRegion(int start, int end, char[] what, char[] with)
        {
            // TODO: really remove chars
            for (int i = start; i < end; i++)
            {
                char c = Builder[i];
                for (int x = 0; x < what.Length; x++) Builder[i] = (what[x] == c) ? with[x] : c;
            }
        }

        protected virtual void CheckBreakpoints()
        {
        }

        public void WriteLine(String value = "")
        {
            String line = "";

            if (IsNewLine)
                line = new String(' ', LineIndent);

            line += value;

            if (State.ConsoleOutput)
                Console.WriteLine(line);

            if (State.InsertAt == -1)
                Builder.AppendLine(line);
            else
            {
                Builder.Insert(State.InsertAt, line + Environment.NewLine);
                State.InsertAt += line.Length + Environment.NewLine.Length;
            }

            CheckBreakpoints();
            State.IsNewLine = true;
        }

        public bool RemoveBack(String strToRemove)
        {
            int i = Builder.Length - 1;
            bool removeNewLine = false;

            for (; i >= 0; i--)
            {
                if (Builder[i] == '\n')
                    removeNewLine = true;

                if (Builder.IsSubString(strToRemove, i) || (Builder[i] > 32))
                {
                    if(!Builder.IsSubString(strToRemove, i))
                        return false;

                    if(removeNewLine)
                        State.IsNewLine = false;

                    Builder.Remove(i, Builder.Length - i);

                    return true;
                }
            }

            return false;
        }

        [Serializable]
        private class IndentScope : IDisposable
        {
            private CodeWriter m_Parent;
            private int m_Width;

            public IndentScope(CodeWriter inParent, int inWidth)
            {
                m_Parent = inParent;
                m_Width = inWidth;
                m_Parent.State.LineIndent += m_Width;
            }

            public void Dispose()
            {
                if (m_Parent != null)
                    m_Parent.State.LineIndent -= m_Width;

                m_Parent = null;
            }
        }

        public IDisposable Indent(int inWidth)
        {
            return new IndentScope(this, inWidth);
        }

        [Serializable]
        private class BackupScope : IDisposable
        {
            protected CodeWriter Parent { get; private set; }
            private readonly int m_InsertAt;
            private readonly int m_LineIndent;
            private readonly bool m_IsNewLine;

            public BackupScope(CodeWriter inParent)
            {
                Parent = inParent;
                m_InsertAt = Parent.State.InsertAt;
                m_IsNewLine = Parent.State.IsNewLine;
                m_LineIndent = Parent.State.LineIndent;
            }

            public void Dispose()
            {
                if (Parent != null)
                {
                    Parent.State.InsertAt = m_InsertAt;
                    Parent.State.IsNewLine = m_IsNewLine;
                    Parent.State.LineIndent = m_LineIndent;
                }

                Parent = null;
            }
        }

        [Serializable]
        private class InserterScope : BackupScope
        {
            public InserterScope(CodeWriter inParent, int atOffset) : base(inParent)
            {
                Parent.State.InsertAt = atOffset;
            }
        }

        public IDisposable Inserter(int atOffset)
        {
            return new InserterScope(this, atOffset);
        }

        [Serializable]
        private class NamespaceScope : IDisposable
        {
            private CodeWriter m_Parent;
            private String[] m_NestedNamespace;
            private String[] m_NamespaceBackup;
            private IDisposable m_Terminator;

            public NamespaceScope(CodeWriter inParent, String inNamespace)
            {
                m_Parent = inParent;
                m_NamespaceBackup = m_Parent.NameManager.CurrentNamespace;
                m_NestedNamespace = inNamespace.Split(new string[]{"::"}, StringSplitOptions.None);
                m_Terminator = m_Parent.EnterNamespace(m_NestedNamespace);
            }

            public void Dispose()
            {
                if (m_Terminator != null)
                    m_Terminator.Dispose();

                m_Terminator = null;

                if (m_Parent != null)
                    m_Parent.LeaveNamespace(m_NestedNamespace);

                m_Parent.NameManager.CurrentNamespace = m_NamespaceBackup;
                m_Parent = null;
            }
        }

        protected virtual void LeaveNamespace(String[] inNestedNamespace)
        {
            WriteLine(new String('}', inNestedNamespace.Length));
        }

        protected virtual IDisposable EnterNamespace(String[] inNestedNamespace)
        {
            if ((inNestedNamespace.Length == 0) || inNestedNamespace.Any(String.IsNullOrEmpty))
                return new DisposablePlaceholder();
            
            WriteLine(inNestedNamespace.FoldLeft((v, r) => r + "namespace " + v + " { ", "").RemoveEnd(3) + " {");
            return Indent(4);
        }

        private class DisposablePlaceholder : IDisposable
        {
            public void Dispose()
            {
            }
        }

        public IDisposable Namespace(String inNamespace)
        {
            if(String.IsNullOrEmpty(inNamespace))
                return new DisposablePlaceholder();
            else
                return new NamespaceScope(this, inNamespace);
        }
    }
}
