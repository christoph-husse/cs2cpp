using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using Mono.CSharp;
using Delegate = Mono.CSharp.Delegate;
using Enum = Mono.CSharp.Enum;
using Nullable = Mono.CSharp.Nullable;
using Linq = Mono.CSharp.Linq;

namespace Cs2Cpp
{
    [Serializable]
    [Flags]
    enum ECppGenPass
    {
        NonTemplate = 1,
        Template = 2,
        Both = 3,
    }

    [Serializable]
    class CppSourceGenerator : CppSourceGeneratorBase
    {
        private Dictionary<AnonymousMethodStorey, MethodStorey> m_Storeys = new Dictionary<AnonymousMethodStorey, MethodStorey>();
        private int m_SwitchCaseCounter = 0, m_StoreyMarker = -1;
        private readonly Stack<Dictionary<SwitchLabel, int>> m_SwitchCaseMaps = new Stack<Dictionary<SwitchLabel, int>>();
        protected Dictionary<SwitchLabel, int> SwitchCaseMap { get { return m_SwitchCaseMaps.Peek(); } }
        protected CppSourceGenerator StoreyCppGenerator { get; private set; }
        protected CppHeaderGenerator StoreyHppGenerator { get; private set; }

        [Serializable]
        private class MethodStorey
        {
            public SCITypeDefinition Type { get; private set; }
            public String InstanceName { get; private set; }

            public MethodStorey(CppSourceGenerator gen, AnonymousMethodStorey storey)
            {
                Type = SCITypeDefinition.Wrap(storey);
                InstanceName = gen.GenerateTemporaryVariableName("storey_");
            }
        }

        public CppSourceGenerator(Assembly part, Assembly whole)
            : base(part, whole)
        {
        }


        public String Process(ECppGenPass pass, Action<String> splitter = null)
        {
            var types = Metadata.Structs.Concat(Metadata.Classes).Where(Part.ContainsType).ToArray();

            var proxies = new Dictionary<SCITypeHandle, List<KeyValuePair<SCIMethodHandle, SCIMethodHandle>>>();
            Action<SCITypeHandle, SCIMethodHandle, SCIMethodHandle> addProxy =
                (c, a, b) =>
                    {
                        var type = c ?? b.DeclaringType;
                        List<KeyValuePair<SCIMethodHandle, SCIMethodHandle>> list;
                        if (!proxies.TryGetValue(type, out list))
                            proxies.Add(type, list = new List<KeyValuePair<SCIMethodHandle, SCIMethodHandle>>());
                        list.Add(new KeyValuePair<SCIMethodHandle, SCIMethodHandle>(a, b));
                    };
            types.Apply(
                c =>
                c.Handle.InstanceMethods.Apply(
                    e => e.Definition.Implements.Apply(i => addProxy(e.DeclaringType, i, e))));
            types.Apply(c => c.InterfaceProxies.Apply(e => addProxy(c, e.Key, e.Value)));

            proxies.Apply(
                e =>
                    {
                        var @class = e.Key.Definition;
                        using (Namespace(@class.Namespace))
                        {
                            using (NameManager.EnterType(@class))
                            {
                                e.Value.Distinct().Apply(
                                    x => WriteInterfaceMethodProxy(pass, e.Key, x.Key, x.Value));
                            }
                        }
                    });

            types.Apply(
                e =>
                    {
                        WriteTypeImplementation(pass, e);
                        Write("\x00");
                    });


            StringBuilder builder = new StringBuilder();
            List<StringBuilder> builders = new List<StringBuilder>();
            CppSourceGenerator gen = this;

            while (gen != null)
            {
                builders.Insert(0, gen.Builder);
                gen = gen.StoreyCppGenerator;
            }

            if ((StoreyHppGenerator != null) && (splitter == null))
                builders.Insert(0, StoreyHppGenerator.Builder);

            foreach (var e in builders)
            {
                builder.Append(e); 
            }

            // apply file splitting
            string result = builder.ToString();
            StringBuilder partBuilder = new StringBuilder();

            if (splitter == null)
                return result.Replace('\x00', ' ');

            foreach(var part in result.Split('\x00'))
            {
                partBuilder.Append(part);

                if(partBuilder.Length > 2000000)
                {
                    splitter(partBuilder.ToString());
                    partBuilder = new StringBuilder();
                }
            }

            if(partBuilder.Length > 0)
                splitter(partBuilder.ToString());

            return (StoreyHppGenerator != null) ? StoreyHppGenerator.Builder.ToString().Replace('\x00', ' ') : "";
        }

        protected override void CheckBreakpoints()
        {
#if !DEBUG2
            string findWhat = "cli::box('3'";

            for (int i = Math.Max(0, Builder.Length - 150); i < Builder.Length; i++)
            {
                if (Builder.IsSubString(findWhat, i))
                    break;
            }
#endif
        }


        public override object Visit(Break stmt)
        {
            Write("break");

            WriteSemicolon();

            return null;
        }

        protected bool NeedsExplicitCast(SCITypeHandle from, SCITypeHandle to)
        {
            if ((from == null) || (to == null))
                return false;

            if (from.IsDefinition)
            {
                if (from.Definition.IsInterface && from.Implements(to))
                    return false;

                if (from.Definition.IsClass && from.DerivesFrom(to))
                    return false;

                if (from.Definition.IsBuiltinType && to.Definition.IsBuiltinType)
                    return false;
            }
            
            return (from != to);
        }

        protected void WriteExplicitCast(SCITypeHandle from, SCITypeHandle to)
        {
            // look for conversion operator
            Func<SCIMethodHandle, bool> selector = e => (e.Definition as SCIOperatorDefinition).IsImplicitConversion &&
                                                        e.ParameterTypes[0].IsAssignableFrom(@from);

            SCIMethodHandle op = to.AllOperators.FirstOrDefault(selector) ?? from.AllOperators.FirstOrDefault(selector);

            if (op == null)
            {
                if (from.IsDefinition)
                {
                    if (!from.Definition.IsClass && !from.Definition.IsInterface && to.IsDefinition && (to.Definition.BuiltinType == BuiltinTypeSpec.Type.Object))
                    {
						Write ("cli::box");
						if (!to.IsDefinition || (to.Definition.BuiltinType != BuiltinTypeSpec.Type.Object)) {
							Write ("<");
							WriteTypeReference (to, TypeUsage.ReturnValue);
							Write (">");
						}

                        return;
                    }
                }
                else if (from.IsGenericParameter)
                {
                    if(to.IsDefinition && (to.Definition.BuiltinType == BuiltinTypeSpec.Type.Object))
                    {
                        Write ("cli::box");
						if (!to.IsDefinition || (to.Definition.BuiltinType != BuiltinTypeSpec.Type.Object)) {
							Write ("<");
							WriteTypeReference (to, TypeUsage.ReturnValue);
							Write (">");
						}

                        return;
                    }
                }

                NeedsExplicitCast(from, to);
                throw new ApplicationException();
            }
            else
            {
                // apply conversion
                WriteTypeReference(op.DeclaringType, TypeUsage.New);
                Write("::");
                Write(op.Name);
            }
        }

        public override object Visit(ArrayCreation expr)
        {
            Write("(new cli::array<");
            WriteTypeReference(SCITypeHandle.Wrap(expr.ElementType), TypeUsage.Parameter);
            Write(">(");

            if (expr.Initializer != null)
            {
                // does expression need to be cast?
                TypeSpec targetType = expr.ElementType;

                //if (expr.Initializer.VariableDeclaration != null)
                //{
                //    var cast = expr.Initializer.VariableDeclaration.TypeExpression as ComposedCast;

                //    if (cast != null)
                //        targetType = cast.Left.Type;
                //}

                Write("{");
                foreach (var e in expr.Initializer.Elements)
                {
                    SCITypeHandle elemType = e.Type;

                    if (e is ElementAccess)
                        elemType = elemType.Indirection;

                    bool doCast = NeedsExplicitCast(elemType, targetType);

                    if (doCast)
                    {
                        WriteExplicitCast(elemType, targetType);
                        Write("(");
                    }

                    e.Accept(this);

                    if (doCast)
                        Write(")");

                    Write(", ");   
                }
                RemoveBack(",");
                Write("}");
            }
            else
                WriteArguments(expr.Arguments.Select(e => (SCITypeHandle)e.Type), expr.Arguments);

            Write("))");

            return null;
        }

        public override object Visit(Foreach stmt)
        {
            var tmpVar = GenerateTemporaryVariableName();
            var type = SCITypeHandle.Wrap(stmt.Expr.Type);


            Write("for(auto " + tmpVar + " : ");
            stmt.Expr.Accept(this);

            if ((type.Definition != null) && !type.Definition.Implements(Metadata.IEnumerable.Handle))
            {
                // find enumerator method.... (must be there since C# code is valid)
                var enumerator = type.AllInstanceMethods.First(e => 
                    (e.ParameterTypes.Count == 0) &&
                    (e.ReturnType.Definition.Implements(Metadata.IEnumerator.Handle)) &&
                    (e.Name == "GetEnumerator"));

                WriteDereference(stmt.Expr);
                Write(enumerator.Name);
                Write("()");
            }

            Write(") ");
            WriteBlock(stmt.Body, () =>
            {
                Write("auto ");
                Write(NameManager.ResolveVariableDeclaration(stmt.Variable));
                Write(" = cli::cast<");
                WriteTypeReference(SCITypeHandle.Wrap(stmt.Variable.Type), TypeUsage.VarDecl);
                WriteLine(">(" + tmpVar + ");");
            });

            return null;
        }

        public override object Visit(GotoDefault stmt)
        {
            Write("goto case_" + SwitchCaseMap.First(e => e.Key.IsDefault).Value);
            WriteSemicolon();

            return null;
        }

        private bool AreSwitchLabelsEqual(Expression a, Expression b)
        {
            if ((a == null) ^ (b == null))
                return false;

            if (a.GetType() != b.GetType())
                return false;

            var aVal = (a as Constant).GetValue();
            var bVal = (b as Constant).GetValue();

            return aVal.Equals(bVal);
        }

        public override object Visit(GotoCase stmt)
        {
            Write("goto case_" + SwitchCaseMap.First(e => AreSwitchLabelsEqual(e.Key.Converted, stmt.Expr)).Value);
            WriteSemicolon();

            return null;
        }

        public override object Visit(Switch stmt)
        {
            m_SwitchCaseMaps.Push(new Dictionary<SwitchLabel, int>());
            stmt.Sections.Apply(
                e =>
                {
                    m_SwitchCaseCounter++;
                    e.Labels.Apply(x => SwitchCaseMap.Add(x, m_SwitchCaseCounter));
                });

            if (stmt.SwitchType.BuiltinType == BuiltinTypeSpec.Type.String)
            {
                var defaultSection = stmt.Sections.FirstOrDefault(e => e.Labels.Any(x => x.IsDefault));
                var strValue = DeclareTemporaryVariable(stmt.Expr);
                var switchValue = DeclareTemporaryVariable("::System::Int32", "-1");
                var map = new Dictionary<SwitchSection, int>();

                stmt.Sections.Except(new[] {defaultSection}).Apply(
                    e =>
                    {
                        Write("if(");
                        foreach(var x in e.Labels)
                        {
                            Write("::System::String::Equals3(" + strValue + ", ");

                            if (x.Label is Constant)
                                x.Label.Accept(this);
                            else
                            {
                                if (!(x.Converted is StringConstant))
                                    Write("_T(\"");
                                    
                                x.Converted.Accept(this);

                                if (!(x.Converted is StringConstant))
                                    Write("\")");
                            }

                            Write(")");

                            if ((e.Labels.Count > 1) && (x != e.Labels.Last()))
                                WriteLine(" ||");
                        }

                        int counter;
                        map.Add(e, counter = map.Count);
                        WriteLine(") " + switchValue + " = " + counter + ";");
                    });

                WriteLine("switch(" + switchValue + ")");
                WriteLine("{");
                using (Indent(4))
                {
                    stmt.Sections.Apply(
                        e =>
                        {
                            if (e == defaultSection)
                                WriteLine("default: case_" + SwitchCaseMap[e.Labels[0]] + ": ");
                            else
                                WriteLine("case " + map[e] + ": case_" + SwitchCaseMap[e.Labels[0]] + ": ");

                            e.Block.Accept(this);
                        });
                }
                WriteLine("}");
            }
            else
            {
                Write("switch(");
                stmt.Expr.Accept(this);
                WriteLine(") {");
                using (Indent(4))
                {
                    stmt.Sections.Apply(
                        e =>
                        {
                            e.Labels.Apply(
                                x =>
                                {
                                    if (x.IsDefault)
                                        Write("default: ");
                                    else
                                    {
                                        Write("case ");

                                        if (x.Converted is Constant)
                                            x.Converted.Accept(this);
                                        else
                                            throw new ArgumentException();

                                        Write(": ");
                                    }
                                });

                            Write("case_" + SwitchCaseMap[e.Labels[0]] + ": ");

                            e.Block.Accept(this);
                        });
                }
                WriteLine("}");
            }

            m_SwitchCaseMaps.Pop();

            return null;
        }

        protected override void WriteMethodBody(SCIMethodDefinition method)
        {
            if (method.HasBody)
            {
                WriteLine(" {");
                using (Indent(4))
                {
                    // in case of hoisted parameters, we need to instanciate a storey
                    var @params = method.Parameters.Where(e => ((Parameter)e.Raw).HoistedVariant != null).ToArray();

                    if (!@params.IsEmpty())
                    {
                        var hoistedParams = @params.Select(e => ((Parameter)e.Raw).HoistedVariant).ToArray();

                        if (!(hoistedParams[0].Storey is StateMachine))
                        {
                            var storey = InstanciateMethodStorey(hoistedParams[0].Storey);

                            // copy params
                            foreach (var p in @params)
                            {
                                var hoistedField = storey.Type.Fields.First(e => e.OriginalName == p.Name);

                                // initialize hoisted variable
                                Write(storey.InstanceName + "->" + hoistedField.Name + " = " + p.Name);
                                WriteSemicolon();
                            }
                        }
                    }

                    foreach (var e in method.Body.Statements)
                    {
                        e.Accept(this);
                    }

                    if (method.IsSetter)
                    {
                        // TODO: fix this to return only getter when return value required by parent expression
                        // return current getter value
                        Visit((Return)null);
                    }
                }
                WriteLine("}");
            }
            else
            {
                if (method.IsExtern)
                {
                    // TODO: check for DllImport and generate stub
                    WriteLine(" {");
                    WriteLine("  // TODO: \"Unimplemented external method!\"");
                    WriteLine("  throw cli::gcnew<System::NotImplementedException>();");
                    WriteLine("}");
                }
                else
                {
                    // TODO: implement automatic events
                    WriteLine(" {");
                    WriteLine("  // TODO: \"Implement automatic events!\"");
                    WriteLine("}");
                }
            }
        }

        public override object Visit(AnonymousMethodBody body)
        {

            if (body.Storey == null)
            {
                // No local variables are used in the lambda
                // TODO: Is this really equivalent to creating a member function?
                Write("cli::bind([&] (");
                WriteParameters(body.Parameters);
                Write(") -> ");
                WriteTypeReference(body.ReturnType, TypeUsage.ReturnValue);
                Write(" ");
		
				using(NameManager.EnterLambda(body))
				{
					body.Block.Accept(this);
				}

                Write(")");
            }
            else
            {
                // local variables are used in the lambda, so C++ lambdas have a significiantly different semantic
                // such that we can't use them...
                var storey = m_Storeys[body.Storey];
                var method = storey.Type.Methods.First(e => e.OriginalName == body.Method.MethodName.Name);

                Write("cli::bind(" + storey.InstanceName + ", &");
                WriteTypeReference(storey.Type, TypeUsage.New);
                Write("::");
                Write(method.Name);
                Write(")");
            }

            return null;
        }

        private MethodStorey InstanciateMethodStorey(AnonymousMethodStorey storey)
        {
            if (StoreyHppGenerator == null)
                StoreyHppGenerator = new CppHeaderGenerator(Part, Assembly);

            if (StoreyCppGenerator == null)
            {
                StoreyCppGenerator = new CppSourceGenerator(Part, Assembly);
                StoreyCppGenerator.StoreyHppGenerator = StoreyHppGenerator;
            }

            if (m_Storeys.ContainsKey(storey))
                return m_Storeys[storey];

            // define and implement storey
            MethodStorey def = new MethodStorey(this, storey);
            m_Storeys.Add(storey, def);

            using (StoreyHppGenerator.Namespace(def.Type.Namespace))
            {
                StoreyHppGenerator.WriteTypeDefinition(def.Type);
            }

            StoreyCppGenerator.WriteTypeImplementation(ECppGenPass.Both, def.Type);

            // instanciate storey as local variable in current scope 
            using (Inserter(m_StoreyMarker))
            {
                Write("auto " + def.InstanceName + " = cli::gcnew<");
                WriteTypeReference(def.Type, TypeUsage.New);
                WriteLine(">();");
            }

            return def;
        }

        protected void SetStoreyMarker()
        {
            m_StoreyMarker = GetMarker();
        }

        protected void ClearStoreyMarker()
        {
            m_StoreyMarker = -1;
        }

        public override object Visit(For stmt)
        {
            // all storeys within the for(...) brakets must be defined outside
            SetStoreyMarker();

            Write("for(");
            AlternateSemicolon = ", ";
            stmt.Initializer.Accept(this);
            AlternateSemicolon = null;
            RemoveBack(", "); Write("; ");

            if (stmt.Condition != null)
            {
                stmt.Condition.Accept(this);
                RemoveBack(";");
            }
            Write("; ");

            var stmtList = stmt.Iterator as StatementList;
            if (stmtList != null)
            {
                stmtList.Statements.Apply(e => { e.Accept(this); RemoveBack(";"); Write(", "); });
                RemoveBack(",");
            }
            else
            {
                stmt.Iterator.Accept(this);
                RemoveBack(";");
            }

            Write(")");

            if (stmt.Statement is Block)
            {
                ClearStoreyMarker();
                stmt.Statement.Accept(this);
            }
            else
            {
                WriteLine(" {");
                using (Indent(4))
                {
                    ClearStoreyMarker();
                    stmt.Statement.Accept(this);
                }
                WriteLine("}");
            }

            return null;
        }

        public override object Visit(BlockVariableDeclaration decl)
        {
            // collect declared variables
            var locVars = new Dictionary<LocalVariable, Expression>(); 
            var hoistedVars = new Dictionary<LocalVariable, Expression>();

            if (decl.Variable.HoistedVariant == null)
                locVars.Add(decl.Variable, decl.Initializer);
            else
                hoistedVars.Add(decl.Variable, decl.Initializer);

            if (decl.Declarators != null)
            {
                decl.Declarators.Apply(e =>
                {
                    if (e.Variable.HoistedVariant == null)
                        locVars.Add(e.Variable, e.Initializer);
                    else
                        hoistedVars.Add(e.Variable, e.Initializer);
                });
            }

            // get common base type
            var baseType = SCITypeHandle.Wrap(decl.TypeExpression.Type);
            String baseStr;

            using (var gen = PrivateBuilder())
            {
                WriteTypeReference(baseType, TypeUsage.VarDecl);
                baseStr = gen.ToString();
                while (baseStr.EndsWith("*")) baseStr = baseStr.Substring(0, baseStr.Length - 1);
            }

            // emit local variables
            if (!locVars.IsEmpty())
            {
                Write(baseStr);
                Write(" ");

                foreach (var locVar in locVars)
                {
                    var init = locVar.Value;
                    var variable = locVar.Key;

                    if (init != null)
                    {
                        if (init is Assign)
                        {
                            var simple = init as SimpleAssign;

                            if ((init is SimpleAssign) && (simple.Source is StackAlloc))
                            {
                                var sa = simple.Source as StackAlloc;

                                WriteDifferenceType(baseType, SCITypeHandle.Wrap(init.Type).Indirection);
                                simple.Target.Accept(this);
                                Write("[");
                                sa.CountExpression.Accept(this);
                                Write("]");
                            }
                            else
                            {
                                WriteDifferenceType(baseType, init.Type);
                                init.Accept(this);
                            }
                        }
                        else
                        {
                            WriteDifferenceType(baseType, variable.Type);
                            Write(NameManager.ResolveVariableDeclaration(variable) + " = ");
                            init.Accept(this);
                        }
                    }
                    else
                    {
                        WriteDifferenceType(baseType, variable.Type);
                        Write(NameManager.ResolveVariableDeclaration(variable));
                    }

                    RemoveBack(";");
                    Write(", ");
                }

                RemoveBack(", ");
                WriteSemicolon();
            }

            // emit hoisted variables
            if (!hoistedVars.IsEmpty())
            {
                foreach (var hoistedVar in hoistedVars)
                {
                    var variable = hoistedVar.Key;
                    var hoisted = variable.HoistedVariant;
                    var init = hoistedVar.Value;
                    var storey = InstanciateMethodStorey(hoisted.Storey); // call will only do this once per storey
                    //var hoistedField = storey.Type.Fields.First(e => e.OriginalName == variable.Name);

                    // initialize hoisted variable
                    if (init != null)
                        init.Accept(this);

                    WriteSemicolon();
                }
            }

            return null;
        }

        public override object Visit(ParameterReference pref)
        {
            var variable = pref.Parameter;

            if (variable.HoistedVariant != null)
            {
                var hoisted = variable.HoistedVariant;

                if (!m_Storeys.ContainsKey(hoisted.Storey))
                {
                    if (NameManager.CurrentType != SCITypeDefinition.Wrap(hoisted.Storey))
                    {
                        var lambdaMethod = ((AnonymousExpression.AnonymousMethodMethod)NameManager.CurrentMemberMethod.Raw).AnonymousMethod;
                        var accessor = hoisted.Accessors[lambdaMethod];
                        accessor.Accept(this);
                    }
                    else
                        Write(variable.Name);
                }
                else
                {
                    var storey = m_Storeys[hoisted.Storey];
                    var hoistedField = storey.Type.Fields.First(e => e.OriginalName == variable.Name);
                    Write(storey.InstanceName + "->" + hoistedField.Name);
                }
            }
            else
                Write(NameManager.ResolveLocalReference(pref.Parameter));

            return null;
        }

        public override object Visit(LocalVariableReference vref)
        {
            var variable = vref.local_info;

            if (variable.HoistedVariant != null)
            {
                var hoisted = variable.HoistedVariant;

                if (!m_Storeys.ContainsKey(hoisted.Storey))
                {
                    if (NameManager.CurrentType != SCITypeDefinition.Wrap(hoisted.Storey))
                    {
                        var lambdaMethod = ((AnonymousExpression.AnonymousMethodMethod)NameManager.CurrentMemberMethod.Raw).AnonymousMethod;
                        var accessor = hoisted.Accessors[lambdaMethod];
                        accessor.Accept(this);
                    }
                    else
                        Write(variable.Name);
                }
                else
                {
                    var storey = m_Storeys[hoisted.Storey];
                    var hoistedField = storey.Type.Fields.First(e => e.OriginalName == variable.Name);
                    Write(storey.InstanceName + "->" + hoistedField.Name);
                }
            }
            else
                Write(NameManager.ResolveVariableDeclaration(variable));

            return null;
        }
    }
}
