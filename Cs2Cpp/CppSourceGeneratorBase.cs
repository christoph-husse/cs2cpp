using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using Mono.CSharp;
using Delegate = Mono.CSharp.Delegate;
using Enum = Mono.CSharp.Enum;
using Nullable = Mono.CSharp.Nullable;
using Linq = Mono.CSharp.Linq;

namespace Cs2Cpp
{
    [Serializable]
    class CppSourceGeneratorBase : ASTVisitor_Shared
    {
        protected int m_TmpCounter;
        public ASTVisitor_Scan Metadata { get { return Assembly.NameManager.Context; } }

        public CppSourceGeneratorBase(Assembly part, Assembly whole)
            : base(part, whole, true)
        {
        }


        public void WriteTypeImplementation(ECppGenPass pass, SCITypeDefinition iface)
        {
            using (Namespace(iface.Namespace))
            {
                if ((pass & ECppGenPass.NonTemplate) != 0)
                {
                    WriteLine();
                    iface.Fields.Apply(
                        e =>
                            {
                                if (!e.IsStatic || e.IsConst)
                                    return;

                                var field = (Field) e.Raw;

                                if (!iface.IsGeneric)
                                {
                                    WriteFieldTypeReference(e);
                                    Write(" ");
                                    WriteMemberReference(field.Spec);
                                    WriteSemicolon();
                                }

                                //if (field.Initializer != null)
                                //{
                                //    using (NameManager.EnterType(iface))
                                //    {
                                //        Write(" = ");

                                //        var arrInit = field.Initializer as ArrayInitializer;
                                //        if (arrInit != null)
                                //        {
                                //            Write("new ");
                                //            WriteTypeReference(e.Type, TypeUsage.New);
                                //            Write("(");
                                //            field.Initializer.Accept(this);
                                //            Write(")");
                                //        }
                                //        else if(field.Initializer is New)
                                //        {
                                //            var @new = field.Initializer as New;

                                //            if (@new.Type.IsDelegate)
                                //            {
                                //                Write("cli::bind(");
                                //                @new.Arguments[0].Expr.Accept(this);
                                //                Write(")");
                                //            }
                                //            else
                                //                field.Initializer.Accept(this);
                                //        }
                                //        else
                                //            field.Initializer.Accept(this);
                                //    }
                                //}
                            });
                }

                using (NameManager.EnterType(iface))
                {
#if DEBUG
                    Console.WriteLine("Processing type \"" + iface.FullName + "\"...");
#endif

					WriteLine();

                    if (iface.Name == "String")
                        iface = iface;

					if(iface.HasStaticConstructor && !iface.IsStruct)
					{
						if ((iface.IsGeneric && ((pass & ECppGenPass.Template) != 0)) || (!iface.IsGeneric && ((pass & ECppGenPass.NonTemplate) != 0)))
						{
							if (iface.IsGeneric)
		                    {
		                        Write("template<");
		                        iface.AllTypeParameters.Apply(e => Write("class " + e.GenericParameter.Name + ", "));
		                        RemoveBack(",");
		                        WriteLine(">");
		                    }
						
							WriteTypeReference(iface.Handle, TypeUsage.MemberRef);
							WriteLine("::" + iface.Name + "()");
							WriteLine("{");
							using(Indent(4))
							{
                                WriteLine("static volatile bool initialized = false;");
						    	WriteLine("static std::recursive_mutex mutex;");
						    	WriteLine("if(!initialized)");
						    	WriteLine("{");
						    	WriteLine("    std::lock_guard<std::recursive_mutex> lock(mutex);");
						    	WriteLine("    if(!initialized)");
						    	Write("        static_constructor();");
								WriteLine("");
						    	WriteLine("    initialized = true;");
								WriteLine("}");
								WriteLine("");
							}
							WriteLine("}");
							WriteLine();
						}
					}

                    iface.Methods.Apply(
                        e =>
                            {
                                bool isGeneric = iface.IsGeneric || e.HasTypeParameters;

                                if ((isGeneric && ((pass & ECppGenPass.Template) != 0)) ||
                                        (!isGeneric && ((pass & ECppGenPass.NonTemplate) != 0)))
                                    WriteMethod(e);
                            });
                }
            }
        }


        #region Fancy stuff

        public override object Visit(ConstInitializer init)
        {
            init.Expr.Accept(this);

            return null;
        }

        public override object Visit(ArrayInitializer init)
        {
            Write("{ ");
            init.Elements.Apply(e => { e.Accept(this); Write(", "); });
            RemoveBack(",");
            Write("} ");

            return null;
        }

        public override object Visit(ClassCast cast)
        {
            Write("cli::cast<");
            WriteTypeReference(SCITypeHandle.Wrap(cast.Type), TypeUsage.TemplateParameter);
            Write(">(");
            cast.Child.Accept(this);
            Write(")");

            return null;
        }

        protected void WriteDereference(Expression expr)
        {
            if (expr is BaseThis)
            {
                Write("::");
                return;
            }

            Write("->");
        }

        public override object Visit(FieldExpr expr)
        {
            var field = ResolveMember<SCIFieldDefinition>(expr.Spec);

            if (expr.IsStatic)
            {
                if(field.IsRecursive)
                    Write("(*");

                WriteMemberReference(expr.Spec);

                if (field.IsRecursive)
                    Write(")");
            }
            else
            {
                if (expr.InstanceExpression != null)
                {
                    WriteIndirectedExpression(expr.InstanceExpression);
                    WriteDereference(expr.InstanceExpression);
                    WriteMemberReference(expr.Spec);
                }
                else
                {
                    // we are referring to a "this" field
                    if (expr.Name != "this")
                        throw new ApplicationException();

                    if (field.Parent.IsStruct)
                        Write("(*this)");
                    else
                        Write("this");
                }
            }

            return null;
        }

        protected String GetAssignmentCast(SCITypeHandle dst, Expression srcExpr)
        {
            String cast = "";
            SCITypeHandle src = srcExpr.Type;

            if (dst == src)
                return "";

            if (dst.IsArray && src.IsArray && (src.Indirection != dst.Indirection))
            {
                var elemType = dst.Indirection;

                if (elemType.IsGenericParameter)
                {
                    if (elemType.GenericParameter.IsConstrained)
                    {
                        // TODO: Add type constraints using static_assert, so the C++ compiler will
                        // validate this cast in a more general form
                    }

                    if (NameManager.CurrentMemberMethod.AllTypeParameters.Any(e => e.GenericParameter == elemType.GenericParameter))
                    {
                        // type parameter is bound so we treat it as usual type
                    }
                    else
                        return "";
                }

                cast = "->template CovariantCast<";
                using (var builder = PrivateBuilder())
                {
                    WriteTypeReference(dst.Indirection, TypeUsage.TemplateParameter);
                    cast += builder + ">()";
                }
            }
            else if (dst.IsDefinition && dst.Definition.IsDelegate && src.IsDefinition && src.Definition.IsDelegate &&
                (dst.Definition.BuiltinType == BuiltinTypeSpec.Type.None) && (src.Definition.BuiltinType == BuiltinTypeSpec.Type.None))
            {
                var dstDef = dst.Definition;
                var srcDef = src.Definition;
                int castCount = 0;
                Action<SCITypeHandle, SCITypeHandle> castParam =
                    (dstParam, srcParam) =>
                    {
                        if((dstParam == null) ^ (srcParam == null))
                            throw new ApplicationException();

                        if (srcParam == null)
                        {
                            Write("void, ");
                            return;
                        }

                        bool needCast = false;

                        if (dstParam != srcParam)
                        {
                            if (dstParam.IsGenericParameter)
                            {
                                if (NameManager.CurrentMemberMethod.AllTypeParameters.All(e => e.GenericParameter != dstParam.GenericParameter))
                                    needCast = true;
                            }
                            else
                                needCast = true;
                        }

                        if (needCast)
                        {
                            castCount++;
                            WriteTypeReference(dstParam, TypeUsage.TemplateParameter);
                        }
                        else
                            WriteTypeReference(srcParam, TypeUsage.TemplateParameter);

                        Write(", ");
                    };

                cast = "->Cast<cli::delegate<";
                using (var builder = PrivateBuilder())
                {
                    castParam(dstDef.DelegateReturnType, srcDef.DelegateReturnType);
                    RemoveBack(", ");
                    Write("(");
                    dstDef.DelegateParameterTypes.ZipApply(srcDef.DelegateParameterTypes, castParam);
                    RemoveBack(", ");
                    Write(")");
                    cast += builder + ">>()";
                }

                if (castCount == 0)
                    return "";
                else
                    return cast;
            }

            return cast;
        }

        public override object Visit(SimpleAssign assign)
        {
            WriteAssignment(assign.Source, assign.Target, assign.Type);
            return null;
        }

        //public override object Visit( assign)
        //{
        //    return null;
        //}

        public void WriteAssignment(Expression source, Expression target, SCITypeHandle assignType)
        {
            var dstProp = target as PropertyExpr;
            var srcProp = source as PropertyExpr;
            Action<PropertyExpr> writeInstance = (prop) =>
            {
                if (prop.InstanceExpression != null)
                {
                    prop.InstanceExpression.Accept(this);
                    WriteDereference(prop.InstanceExpression);
                }
            };

            // need array conversion?
            String arrCast = GetAssignmentCast(assignType, source);
            
            if (dstProp != null)
            {
                writeInstance(dstProp);
                WriteMemberReference(dstProp.Setter);
                Write("(");

                if (srcProp != null)
                {
                    writeInstance(srcProp);
                    WriteMemberReference(srcProp.Getter);
                    Write("()");
                }
                else
                    source.Accept(this);

                Write(arrCast + ")");
            }
            else if (target is IndexerExpr)
            {
                target.Accept(this);
            }
            else if (srcProp != null)
            {
                target.Accept(this);
                Write(" = ");
                writeInstance(srcProp);
                WriteMemberReference(srcProp.Getter);
                Write("()" + arrCast);
            }
            else
            {
                target.Accept(this);
                Write(" = ");
                source.Accept(this);
                Write(arrCast);
            }
        }

        public override object Visit(MemberAccess access)
        {
            SCITypeHandle type = access.LeftExpression.Type;
            var member = type.Definition.ResolveMember(access.Name);

            access.LeftExpression.Accept(this);

            if ((access.LeftExpression is BaseThis) || member.Raw.IsStatic)
                Write("::");
            else
                Write("->");

            if (member is SCIPropertyDefinition)
            {
                var prop = member as SCIPropertyDefinition;
                Write(prop.Getter.Name);
                Write("()");
            }
            else
            {
                Write(member.Name);
            }

            return null;
        }

        protected void WriteArguments(IEnumerable<Argument> @params)
        {
            WriteArguments((IEnumerable<SCITypeHandle>) null, @params);
        }

        protected void WriteArguments(IEnumerable<TypeSpec> actualTypes, IEnumerable<Expression> @params)
        {
            WriteArguments(actualTypes.Select(e => (SCITypeHandle)e), @params);
        }

        protected void WriteArguments(IEnumerable<TypeSpec> actualTypes, IEnumerable<Argument> @params)
        {
            WriteArguments(actualTypes.Select(e => (SCITypeHandle)e), @params);
        }

        protected void WriteArguments(IEnumerable<SCITypeHandle> actualTypes, IEnumerable<Expression> @params)
        {
            if (@params == null)
                return;

            if (actualTypes == null)
            {
                @params.Apply(e =>
                                  {
                                      e.Accept(this);
                                      Write(", ");
                                  });
            }
            else
            {
                @params.ZipApply(actualTypes, (e, t) =>
                                                  {
                                                      e.Accept(this);
                                                      Write(GetAssignmentCast(t, e) + ", ");
                                                  });
            }
            RemoveBack(",");
        }

        protected void WriteArguments(IEnumerable<SCITypeHandle> actualTypes, IEnumerable<Argument> @params)
        {
            if (@params == null)
                return;

            if (actualTypes == null)
            {
                @params.Apply(e =>
                                  {
                                      e.Expr.Accept(this);
                                      Write(", ");
                                  });
            }
            else
            {
                @params.ZipApply(actualTypes, (e, t) =>
                                                  {
                                                      e.Expr.Accept(this);
                                                      Write(GetAssignmentCast(t, e.Expr) + ", ");
                                                  });
            }
            RemoveBack(",");
        }

        public void HandleParameter(Parameter param)
        {
            if (param.Type.Kind == MemberKind.InternalCompilerType)
            {
                if (param.Type.MemberDefinition.Name == "__arglist")
                    Write("...");
                else
                    throw new NotImplementedException();
            }
            else
            {
                if (param.Type != null)
                    WriteTypeReference(SCITypeHandle.Wrap(param.Type), TypeUsage.Parameter);
                else if (param.TypeExpression != null)
                    param.TypeExpression.Accept(this);
                else
                    throw new ArgumentException();

                Write(" ");
                Write(NameManager.ResolveVariableDeclaration(param));
            }
        }

        protected void WriteParameters(IEnumerable<IParameterData> @params)
        {
            if (@params == null)
                return;

            @params.Apply(e =>
            {
                HandleParameter((Parameter)e);

                Write(", ");
            });

            RemoveBack(",");
        }

        protected void WriteParameters(ParametersCompiled @params)
        {
            if (@params != null)
                WriteParameters(@params.FixedParameters);
        }

        public override object Visit(DelegateInvocation inv)
        {
            SCITypeHandle del = inv.InstanceExpr.Type;

            inv.InstanceExpr.Accept(this);
            Write("->Invoke(");
            WriteArguments(inv.Method.Parameters.Types.Select(e => (SCITypeHandle)e), inv.Arguments);
            Write(")");

            return null;
        }

        public override object Visit(CompoundAssign.TargetExpression target)
        {
            target.Child.Accept(this);
            return null;
        }

        public override object Visit(CompoundAssign assign)
        {
            if (assign.Target is EventExpr)
            {
                var expr = assign.Target as EventExpr;

                if (expr.IsInstance)
                {
                    expr.InstanceExpression.Accept(this);
                    WriteDereference(expr);
                }

                Write(SCIMethodHandle.Wrap(expr.Operator).Name);
                Write("(");
                assign.Source.Accept(this);
                Write(")");
            }
            else
            {
                Write("(");

                var dst = assign.Target;
                var src = assign.Source;

                if (dst is ArrayAccess)
                {
                    dst.Accept(this);
                    Write(" = ");
                    src.Accept(this);
                }
                else if (dst is PropertyExpr)
                {
                    var propExpr = dst as PropertyExpr;

                    WritePropertyExpression(propExpr, true, new[] { src });
                }
                else if ((dst is FieldExpr) || (dst is ParameterReference) || (dst is LocalVariableReference))
                {
                    dst.Accept(this);
                    Write(" = ");
                    src.Accept(this);
                }
                else if (dst is Indirection)
                {
                    dst.Accept(this);
                    Write(" = ");
                    src.Accept(this);
                }
                else
                    throw new NotImplementedException();

                Write(")");
            }

            return null;
        }


        public override object Visit(Iterator stmt)
        {
            // TODO: Yield iterator
            //stmt.Storey.Accept(this);
            Write("(nullptr/*TODO: Implement Yield Expression!*/)");

            return null;
        }

        public override object Visit(ElementAccess node)
        {
            var arrType = SCITypeHandle.Wrap(node.Type);
            node.Expr.Accept(this);

            if (arrType.IsPointer)
            {
                foreach (var arg in node.Arguments)
                {
                    Write("[");
                    arg.Expr.Accept(this);
                    Write("]");
                }
            }
            else if ((arrType.Definition != null) && (arrType.Definition.BuiltinType == BuiltinTypeSpec.Type.String))
            {
                Write("->get_Chars(");
                node.Arguments[0].Expr.Accept(this);
                Write(")");
            }
            else
            {
                Write("->at(");
                WriteArguments(node.Arguments.Select(e => (SCITypeHandle) e.Type), node.Arguments);
                Write(")");
            }
            return null;
        }

        public override object Visit(GenericTypeExpr node)
        {
            WriteTypeReference(SCITypeHandle.Wrap(node.Type), TypeUsage.New);

            return null;
        }

        public override object Visit(StatementList node)
        {
            node.Statements.Apply(e =>
            {
                e.Accept(this);
                RemoveBack(", ");
                Write(", ");
            });
            RemoveBack(", ");

            return null;
        }

        private void EmitStringConcat(StringConcat concat, Expression freeString)
        {
            var left = concat.Arguments[0].Expr;
            var leftArray = left as ArrayCreation;

            Write("cli::concat(");
            if (leftArray != null)
            {
                // three or more operands are packed into an array - we unpack them...
                leftArray.Initializer.Elements.Apply(e => { e.Accept(this); Write(", "); });
                RemoveBack(", ");
            }
            else
            {
                left.Accept(this);
                Write(", ");
                concat.Arguments[1].Expr.Accept(this);
            }

            if (freeString != null)
            {
                Write(", ");
                freeString.Accept(this);
            }

            Write(")");
        }

        public override object Visit(Binary expr)
        {
            bool isAssign = (expr.Left is CompoundAssign.TargetExpression);

            if(expr.Left is StringConcat)
            {
                EmitStringConcat(expr.Left as StringConcat, expr.Right);
                return null;
            }
            else if (!isAssign)
            {
                Write("(");

                if (expr.Left is SimpleAssign)
                {
                    Write("(");
                    expr.Left.Accept(this);
                    Write(")");
                }
                else
                    expr.Left.Accept(this);
            }
            else
            {
                var target = expr.Left as CompoundAssign.TargetExpression;

                if (target.Child is PropertyExpr)
                {
                    WritePropertyExpression(target.Child as PropertyExpr, false);
                }
                else
                    expr.Left.Accept(this);
            }

            WriteBinaryOperator(expr.Oper, false);

            if (expr.Left is SimpleAssign)
            {
                Write("(");
                expr.Right.Accept(this);
                Write(")");
            }
            else
                expr.Right.Accept(this);

            if (!isAssign)
                Write(")");

            return null;
        }

        protected bool TypeSupportsNativeOps(TypeSpec type)
        {
            switch (type.BuiltinType)
            {
                case BuiltinTypeSpec.Type.Byte:
                case BuiltinTypeSpec.Type.Char:
                case BuiltinTypeSpec.Type.Double:
                case BuiltinTypeSpec.Type.Float:
                case BuiltinTypeSpec.Type.Int:
                case BuiltinTypeSpec.Type.IntPtr:
                case BuiltinTypeSpec.Type.Long:
                case BuiltinTypeSpec.Type.SByte:
                case BuiltinTypeSpec.Type.Short:
                case BuiltinTypeSpec.Type.UInt:
                case BuiltinTypeSpec.Type.UIntPtr:
                case BuiltinTypeSpec.Type.ULong:
                case BuiltinTypeSpec.Type.UShort:
                    return true;

                default:
                    return false;
            }
        }

        protected void WriteBinaryOperator(Binary.Operator oper, bool isAssign)
        {
            switch (oper)
            {
                case Binary.Operator.Addition: Write(" +"); break;
                case Binary.Operator.BitwiseAnd: Write(" &"); break;
                case Binary.Operator.BitwiseOr: Write(" |"); break;
                case Binary.Operator.Division: Write(" /"); break;
                case Binary.Operator.Equality: Write(" == "); break;
                case Binary.Operator.ExclusiveOr: Write(" ^"); break;
                case Binary.Operator.GreaterThan: Write(" >"); break;
                case Binary.Operator.GreaterThanOrEqual: Write(" >="); break;
                case Binary.Operator.Inequality: Write(" !="); break;
                case Binary.Operator.LessThan: Write(" <"); break;
                case Binary.Operator.LessThanOrEqual: Write(" <="); break;
                case Binary.Operator.LogicalAnd: Write(" &&"); break;
                case Binary.Operator.LogicalOr: Write(" ||"); break;
                case Binary.Operator.Modulus: Write(" %"); break;
                case Binary.Operator.Multiply: Write(" *"); break;
                case Binary.Operator.LeftShift: Write(" <<"); break;
                case Binary.Operator.RightShift: Write(" >>"); break;
                case Binary.Operator.Subtraction: Write(" -"); break;
                default:
                    throw new NotImplementedException();
            }

            if (isAssign)
                Write("= ");
            else
                Write(" ");
        }

        public override object Visit(ArrayAccess access)
        {
            var args = access.ElementAccess.Arguments;

            access.ElementAccess.Expr.Accept(this);
            Write("->at(");
            WriteArguments(args.Select(e => (SCITypeHandle)e.Type), args);
            Write(")");

            return null;
        }


        public override object Visit(PropertyExpr expr)
        {
            WritePropertyExpression(expr, false);
            return null;
        }

        protected void WritePropertyExpression(PropertyExpr expr, bool isSetter, IEnumerable<Expression> explicitParams = null, Action writeParams = null)
        {
            MethodSpec method = isSetter ? expr.Setter : expr.Getter;

            if (expr.IsStatic)
            {
                WriteTypeReference(SCITypeHandle.Wrap(expr.DeclaringType), TypeUsage.New);
                Write("::" + SCIMethodDefinition.Wrap(method).Name + "(");

                if (writeParams != null)
                {
                    writeParams();
                }
                else
                {
                    if (explicitParams != null)
                        explicitParams.Apply(e => e.Accept(this));
                    else
                        WriteParameters(method.Parameters.FixedParameters);
                }

                Write(")");
            }
            else
            {
                if (expr.InstanceExpression != null)
                {
                    expr.InstanceExpression.Accept(this);
                    WriteDereference(expr.InstanceExpression);
                }

                Write(SCIMethodDefinition.Wrap(method).Name + "(");

                if (writeParams != null)
                {
                    writeParams();
                }
                else
                {
                    if (explicitParams != null)
                        explicitParams.Apply(e => e.Accept(this));
                    else
                        WriteParameters(method.Parameters.FixedParameters);
                }

                Write(")");
            }
        }

        public override object Visit(UnaryMutator expr)
        {
            var mode = expr.UnaryMutatorMode;

            if (expr.Expr is PropertyExpr)
            {
                var propExpr = expr.Expr as PropertyExpr;
                String op = " + 1";

                switch (mode)
                {
                    case UnaryMutator.Mode.PreDecrement:
                        op = " - 1";
                        goto case UnaryMutator.Mode.PreIncrement;
                    case UnaryMutator.Mode.PreIncrement:
                        WritePropertyExpression(propExpr, true, writeParams: () =>
                            {
                                WritePropertyExpression(propExpr, false);
                                Write(op);
                            });
                        break;

                    case UnaryMutator.Mode.PostDecrement:
                        op = " - 1";
                        goto case UnaryMutator.Mode.PostIncrement;
                    case UnaryMutator.Mode.PostIncrement:
                        var tmpVar = GenerateTemporaryVariableName();
                        Write("[&]() { auto " + tmpVar + " = ");
                        WritePropertyExpression(propExpr, false);
                        Write("; ");

                        WritePropertyExpression(propExpr, true, writeParams: () =>
                                                                {
                                                                    Write(tmpVar);
                                                                    Write(op);
                                                                });
                        Write("; return " + tmpVar + "; }()");
                        break;
                    default:
                        throw new ArgumentException();
                }
            }
            else
            {
                if (expr.Operation is UserOperatorCall)
                {
                    switch (mode)
                    {
                        case UnaryMutator.Mode.PreDecrement:
                        case UnaryMutator.Mode.PreIncrement:
                            expr.Operation.Accept(this);
                            break;

                        case UnaryMutator.Mode.PostDecrement:
                        case UnaryMutator.Mode.PostIncrement:
                            var tmpVar = GenerateTemporaryVariableName();
                            Write("[&]() { auto " + tmpVar + " = ");
                            expr.Expr.Accept(this);
                            Write("; ");
                            ((UserOperatorCall) expr.Operation).Arguments[0].Expr = expr.Expr;
                            expr.Operation.Accept(this);
                            Write("; return " + tmpVar + "; }()");
                            break;
                        default:
                            throw new ArgumentException();
                    }
                }
                else
                {
                    switch (mode)
                    {
                        case UnaryMutator.Mode.PreIncrement:
                            Write("++");
                            expr.Expr.Accept(this);
                            break;
                        case UnaryMutator.Mode.PreDecrement:
                            Write("--");
                            expr.Expr.Accept(this);
                            break;
                        case UnaryMutator.Mode.PostIncrement:
                            expr.Expr.Accept(this);
                            Write("++");
                            break;
                        case UnaryMutator.Mode.PostDecrement:
                            expr.Expr.Accept(this);
                            Write("--");
                            break;
                        default:
                            throw new ArgumentException();
                    }
                }
            }

            return null;
        }


        public override object Visit(Throw stmt)
        {
            Write("throw ");

            if (stmt.Expr != null)
                stmt.Expr.Accept(this);

            WriteSemicolon();

            return null;
        }

        public override object Visit(New expr)
        {
            var type = SCITypeHandle.Wrap(expr.Type);

            if (type.Definition.IsClass)
            {
                Write("cli::gcnew<");
                WriteTypeReference(type, TypeUsage.New);
                Write(">(");
                if (expr.Arguments != null)
                {
                    if(expr.Method == null)
                        WriteArguments(expr.Arguments);
                    else
                        WriteArguments(expr.Method.Parameters.Types, expr.Arguments);
                }
                Write(")");
            }
            else if (type.Definition.IsStruct)
            {
                Write("cli::ctor<");
                WriteTypeReference(type, TypeUsage.New);
                Write(">(");
                if(expr.Arguments != null)
                    WriteArguments(expr.Method.Parameters.Types, expr.Arguments);
                Write(")");
            }
            else
                throw new ApplicationException();

            return null;
        }

        public override object Visit(OpcodeCast cast)
        {
            if (cast.Type.IsUnmanaged && cast.UnderlyingType.IsUnmanaged)
            {
                // no conversion operators can be involved here...
                Write("(");
                WriteTypeReference(SCITypeHandle.Wrap(cast.Type), TypeUsage.VarDecl);
                Write(")(");
                cast.Child.Accept(this);
                Write(")");
            }
            else
                throw new NotImplementedException();

            return null;
        }

        protected void WriteTypeReference(Expression expr, TypeUsage usage)
        {
            WriteTypeReference(SCITypeHandle.Wrap(expr.Type), usage);
        }

        protected String GenerateTemporaryVariableName(String prefix = "tmp_")
        {
            // TODO: generate unique name
            String varName = prefix + (m_TmpCounter++);

            return varName;
        }

        protected String DeclareTemporaryVariable(String type, String init)
        {
            var varName = GenerateTemporaryVariableName();
            WriteLine(type + " " + varName + " = " + init + ";");
            return varName;
        }

        protected String DeclareTemporaryVariable(TypeSpec type, Expression init = null)
        {
            var varName = GenerateTemporaryVariableName();

            WriteTypeReference(SCITypeHandle.Wrap(type), TypeUsage.VarDecl);
            Write(" " + varName);

            if (init != null)
            {
                Write(" = ");
                init.Accept(this);
            }

            WriteSemicolon();

            return varName;
        }

        protected String DeclareTemporaryVariable(Expression inInit)
        {
            return DeclareTemporaryVariable(inInit.Type, inInit);
        }

        public override object Visit(Nullable.NullCoalescingOperator op)
        {
            int v = 0;

            switch(v)
            {
                case 0:
                    int a = -1;
                    goto case 2;
                case 1:
                    a = 1;
                    goto default;
                case 2:
                    break;
                case 3:
                    if(v == 3)
                        break;
                    a = 2;
                    break;
                default:
                    goto case 3;
            }

            /*
             * Nasty thing, since there is no equivalent in C++ and unfortunately,
             * it is paramount to only evaluate an expression if its predecessor
             * yields null. To further complicate matters, we must only evaluate
             * each expression at most once, and the resulting substitute for the
             * coalescing operator shall be an expression itself, not a statement!
             */
            WriteLine("([&]() {");
            using (Indent(4))
            {
                String leftName;
                var type = SCITypeHandle.Wrap(op.LeftExpression.Type);
                bool isNullable = type.IsNullable;

                if (!isNullable)
                {
                    var wrapped = ((Nullable.Unwrap)op.LeftExpression).Original;

                    leftName = DeclareTemporaryVariable(wrapped);
                    WriteLine("if(" + leftName + ".get_HasValue()) {");
                }
                else
                {
                    leftName = DeclareTemporaryVariable(op.LeftExpression);
                    WriteLine("if(" + leftName + " == nullptr) {");
                }

                using (Indent(4))
                {
                    Write("return ");
                    op.RightExpression.Accept(this);
                    WriteSemicolon();
                }
                WriteLine("} else");
                Write("    return " + leftName + (!isNullable ? ".get_Value()" : ""));
                WriteSemicolon();
            }
            WriteLine("})()");

            return null;
        }

        public override object Visit(EmptyCast cast)
        {
            if (cast.Type.IsUnmanaged)
            {
                Write("(");
                WriteTypeReference(SCITypeHandle.Wrap(cast.Type), TypeUsage.VarDecl);
                Write(")");
            }
            else
            {
                Write("cli::cast<");
                WriteTypeReference(SCITypeHandle.Wrap(cast.Type), TypeUsage.VarDecl);
                Write(">");
            }

            Write("(");
            cast.Child.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(Lock stmt)
        {
            if (stmt.Statement is Block)
            {
                WriteBlock((Block)stmt.Statement, () =>
                {
                    Write("cli::lock_guard{");
                    stmt.Expr.Accept(this);
                    WriteLine("};");
                });
            }
            else
            {
                WriteBlockContent(stmt.Statement, () =>
                {
                    Write("cli::lock_guard{");
                    stmt.Expr.Accept(this);
                    WriteLine("};");
                });
            }

            return null;
        }

        public override object Visit(Unchecked stmt)
        {
            Write("/*unchecked*/ ");
            stmt.Block.Accept(this);

            return null;
        }

        public override object Visit(Checked stmt)
        {
            Write("/*checked*/ ");
            stmt.Block.Accept(this);

            return null;
        }

        public override object Visit(ArglistAccess node)
        {
            Write("__arglist");
            return null;
        }

        public override object Visit(Fixed stmt)
        {
            WriteBlockContent((dynamic)stmt.Statement, (Procedure)(() =>
            {
                WriteTypeReference(SCITypeHandle.Wrap(stmt.Variables.Variable.Type), TypeUsage.VarDecl);
                Write(" " + NameManager.ResolveVariableDeclaration(stmt.Variables.Variable) + " = cli::fixed_guard(");
                stmt.Variables.Initializer.Accept(this);
                Write(")");
                WriteSemicolon();

                stmt.Variables.Declarators.Apply(v =>
                {
                    WriteTypeReference(SCITypeHandle.Wrap(v.Variable.Type), TypeUsage.VarDecl);
                    Write(" " + NameManager.ResolveVariableDeclaration(v.Variable) + " = cli::fixed_guard(");
                    v.Initializer.Accept(this);
                    Write(")");
                    WriteSemicolon();
                });
            }), "FIXED - BLOCK");

            return null;
        }

        public override object Visit(Using stmt)
        {
            dynamic explicitBlock = stmt;

            while (explicitBlock is Using) explicitBlock = explicitBlock.Statement;

            Procedure writer = () =>
            {
                explicitBlock = stmt;

                while (explicitBlock is Using)
                {
                    Write("auto ");
                    explicitBlock.Variables.Initializer.Accept(this);
                    WriteSemicolon();
                    Write("cli::using_guard{");
                    explicitBlock.Variables.Initializer.Target.Accept(this);
                    Write("}");
                    WriteSemicolon();

                    explicitBlock = explicitBlock.Statement;
                }
            };

            if (explicitBlock is Block)
                WriteBlockContent((Block)explicitBlock, writer, "USING - BLOCK");
            else
            {
                WriteLine("{");
                using (Indent(4))
                {
                    writer();
                }
                WriteLine("}");
            }


            return null;
        }

        public override object Visit(StackAlloc expr)
        {
            WriteTypeReference(SCITypeHandle.Wrap(expr.TypeExpression.Type), TypeUsage.VarDecl);
            Write("[");
            expr.CountExpression.Accept(this);
            Write("]");

            return null;
        }

        public override object Visit(TypeOf expr)
        {
            Write("cli::typeof<");
            WriteTypeReference(expr, TypeUsage.New);
            Write(">::info");

            return null;
        }

        public override object Visit(Unary expr)
        {
            switch (expr.Oper)
            {
                case Unary.Operator.AddressOf: Write("&"); break;
                case Unary.Operator.LogicalNot: Write("!"); break;
                case Unary.Operator.OnesComplement: Write("~"); break;
                case Unary.Operator.UnaryNegation: Write("-"); break;
                case Unary.Operator.UnaryPlus: Write("+"); break;
                default:
                    throw new NotImplementedException();
            }

            Write("(");
            expr.Expr.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(PointerArithmetic expr)
        {
            Write("(");
            expr.Left.Accept(this);
            WriteBinaryOperator(expr.Operator, (expr.Left is CompoundAssign.TargetExpression));
            expr.Right.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(TryCatch stmt)
        {
            Write("try ");
            WriteBlock(stmt.Block);
            stmt.Clauses.Apply(e => { e.Accept(this); });

            return null;
        }

        public override object Visit(Catch stmt)
        {
            Write("catch(");

            if (stmt.CatchType != null)
            {
                WriteTypeReference(SCITypeHandle.Wrap(stmt.CatchType), TypeUsage.VarDecl);

                if (stmt.Variable != null)
                {
                    Write(" ");
                    Write(NameManager.ResolveVariableDeclaration(stmt.Variable));
                }
            }
            else
            {
                Write("...");
            }

            Write(") ");
            stmt.Block.Accept(this);

            return null;
        }

        public override object Visit(TryFinally stmt)
        {
            var tryCatch = stmt.Statement as TryCatch;

            if (tryCatch != null)
                WriteLine("try");

            WriteLine("{");
            using (Indent(4))
            {
                Write("cli::finally_guard([&]() ");
                stmt.Finallyblock.Accept(this);
                RemoveBack("}");
                WriteLine("});");

                if (tryCatch != null)
                    WriteBlockContent(tryCatch.Block);
                else
                    WriteBlockContent((Block)stmt.Statement);
            }
            WriteLine("}");

            if (tryCatch != null)
                tryCatch.Clauses.Apply(e => { e.Accept(this); });

            return null;
        }

        public override object Visit(Linq.AQueryClause.QueryExpressionInvocation expr)
        {
            //var access = expr.Exp as Linq.AQueryClause.QueryExpressionAccess;

            //Write("cli::linq::" + access.Name + "(");
            //WriteParameters(expr.Arguments);
            //Write(")");

            return null;
        }

        public override object Visit(ArrayIndexCast cast)
        {
            Write("(");
            WriteTypeReference(SCITypeHandle.Wrap(cast.Type), TypeUsage.VarDecl);
            Write(")");
            cast.Child.Accept(this);

            return null;
        }

        protected void WriteIndirectedExpression(Expression expr)
        {
            SCITypeHandle type = expr.Type;
            bool needsMap = type.IsArray || type.IsGenericParameter || type.Definition.IsBuiltinType ||
                type.IsIntPtr || type.IsEnum;

            if (needsMap)
                Write("cli::import(");

            expr.Accept(this);

            if (needsMap)
                Write(")");
        }

        public override object Visit(Invocation expr)
        {
            var method = SCIMethodHandle.Wrap(expr.MethodGroup.BestCandidate);

            if (expr.Exp is MemberAccess)
            {
                var access = (expr.Exp as MemberAccess).LeftExpression;

                if (method.Definition.IsStatic)
                {
                    WriteTypeReference(method.DeclaringType, TypeUsage.New);
                    Write("::");
                }
                else
                {
                    WriteIndirectedExpression(access);
                    WriteDereference(access);
                }
            }
            else if (expr.Exp is SimpleName)
            {
                // we will write the potentially wrong method name stored here in the next step, correctly.
                if (method.DeclaringType.Definition != NameManager.CurrentType)
                {
                    if (method.Definition.IsAbstract)
                    {
                        if (method.Definition.Implements.Any())
                            method = method.Definition.Implements.First();
                        else
                        {
                            // figure out first implementation (abstract methods can't be generic, so this is a bit easier)
                            var super = NameManager.CurrentType.Handle;
                            SCIMethodHandle impl = null;

                            while((super != null) && (super != method.DeclaringType.Definition))
                            {
                                if ((impl = super.AllInstanceMethods.FirstOrDefault(e => e.Definition.BaseMethod == method)) != null)
                                    break;

                                super = super.Definition.BaseClass;
                            }

                            if(super == null)
                                throw new ArgumentException("Something went terribly wrong");

                            if (impl != null)
                            {
                                WriteTypeReference(super, TypeUsage.New);
                                Write("::");

                                method = impl;
                            }
                            else
                            {
                                if (!NameManager.CurrentType.IsAbstract)
                                    throw new ArgumentException("Abstract method was not implemented. (This can't really happen)");
                            }
                                
                        }
                    }
                    else
                    {
                        WriteTypeReference(method.DeclaringType, TypeUsage.New);
                        Write("::");
                    }
                }
            }
            else if (expr.Exp is MethodGroupExpr)
            {

            }
            else
                throw new ArgumentException();

            Char c = Builder[Builder.Length - 1];
            bool wasDeref = (c == ':') || (c == '>') || (c == '.');

            if (!method.ExplicitTypeParameters.IsEmpty() && wasDeref)
                Write("template ");

            Write(method.Name);

            if (!method.ExplicitTypeParameters.IsEmpty())
            {
                Write("<");
                method.ExplicitTypeParameters.Apply(e => { WriteTypeReference(e, TypeUsage.TemplateParameter); Write(", "); });
                RemoveBack(", ");
                Write(">");
            }

            Write("(");
            WriteArguments(method.ParameterTypes, expr.Arguments);
            Write(")");

            return null;
        }

        protected void WriteOperatorType(Operator opDef)
        {
            switch (opDef.OperatorType)
            {
                case Operator.OpType.UnaryPlus:
                case Operator.OpType.Addition: Write(" +"); break;
                case Operator.OpType.BitwiseAnd: Write(" &"); break;
                case Operator.OpType.BitwiseOr: Write(" |"); break;
                case Operator.OpType.Division: Write(" /"); break;
                case Operator.OpType.Equality: Write(" == "); break;
                case Operator.OpType.ExclusiveOr: Write(" ^"); break;
                case Operator.OpType.GreaterThan: Write(" >"); break;
                case Operator.OpType.GreaterThanOrEqual: Write(" >="); break;
                case Operator.OpType.Inequality: Write(" !="); break;
                case Operator.OpType.LessThan: Write(" <"); break;
                case Operator.OpType.LessThanOrEqual: Write(" <="); break;
                case Operator.OpType.Modulus: Write(" %"); break;
                case Operator.OpType.Multiply: Write(" *"); break;
                case Operator.OpType.LeftShift: Write(" <<"); break;
                case Operator.OpType.RightShift: Write(" >>"); break;
                case Operator.OpType.UnaryNegation:
                case Operator.OpType.Subtraction: Write(" -"); break;
                case Operator.OpType.Decrement: Write(" --"); break;
                case Operator.OpType.Increment: Write(" ++"); break;

                case Operator.OpType.True:
                case Operator.OpType.False:
                default:
                    throw new NotImplementedException();
            }
        }

        public override object Visit(EmptyExpression node)
        {
            return null;
        }

        public override object Visit(UserOperatorCall userOp)
        {
            bool isUnary = userOp.Arguments.Count == 1;
            Expression left = userOp.Arguments[0].Expr;
            Expression right = isUnary ? null : userOp.Arguments[1].Expr;
            var targetAssign = (left as CompoundAssign.TargetExpression);
            bool isAssign = targetAssign != null;

            if (isAssign)
            {
                // TODO: only side-effect free compound assignments are supported
                left = targetAssign.Child;
            }

            WriteMemberReference(userOp.Operator);
            Write("(");
            left.Accept(this);

            if (!isUnary)
            {
                Write(", ");
                right.Accept(this);
            }

            Write(")");

            return null;
        }

        private bool CanEmitBuiltinCast(SCITypeHandle source, SCITypeHandle target)
        {
            if (!source.IsDefinition || !target.IsDefinition || !source.Definition.IsBuiltinType ||
                    !target.Definition.IsBuiltinType)
                return false;

            if (target.AllInstanceMethods.Any(e => e.Name.StartsWith("op_Implicit")))
                return false;

            return true;
        }

        public override object Visit(UserCast cast)
        {
            SCITypeHandle target = cast.Type;
            SCITypeHandle source = cast.Source.Type;

            if (target.IsIntPtr)
            {
                Write("(void*)");
                cast.Source.Accept(this);
            }
            else if (CanEmitBuiltinCast(source, target))
            {
                Write("(");
                Write(target.Definition.GetBuiltinName());
                Write(")");
                cast.Source.Accept(this);
            }
            else
            {
                var method = SCIMethodHandle.Wrap(cast.Method);
                WriteMethodReference(method);
                Write("(");
                cast.Source.Accept(this);
                Write(")");
            }

            return null;
        }

        public override object Visit(ConvCast cast)
        {
            Write("(");
            WriteTypeReference(SCITypeHandle.Wrap(cast.Type), TypeUsage.VarDecl);
            Write(")");
            cast.Child.Accept(this);

            return null;
        }

        public override object Visit(ComposedCast cast)
        {
            WriteTypeReference(SCITypeHandle.Wrap(cast.Type), TypeUsage.New);

            return null;
        }

        public override object Visit(IndexerExpr idx)
        {
            idx.InstanceExpression.Accept(this);
            WriteDereference(idx.InstanceExpression);

            if (idx.Getter != null)
            {
                WriteMemberReference(idx.Getter);
                Write("(");
                WriteArguments(SCIMethodHandle.Wrap(idx.Getter).ParameterTypes, idx.Arguments);
                Write(")");
            }
            else
            {
                WriteMemberReference(idx.Setter);
                Write("(");
                WriteArguments(SCIMethodHandle.Wrap(idx.Setter).ParameterTypes, idx.Arguments);
                Write(")");
            }

            return null;
        }

        public override object Visit(StringConcat concat)
        {
            EmitStringConcat(concat, null);
            return null;
        }

        public override object Visit (BoxedCast cast)
		{
			var target = SCITypeHandle.Wrap (cast.Type);

			Write ("cli::box");
			if (!target.IsDefinition || (target.Definition.BuiltinType != BuiltinTypeSpec.Type.Object)) {
				Write ("<");
				WriteTypeReference (target, TypeUsage.VarDecl);
				Write (">");
			}
			Write("(");
            cast.Child.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(UnboxCast cast)
        {
            Write("cli::unbox<");
            WriteTypeReference(SCITypeHandle.Wrap(cast.Type), TypeUsage.VarDecl);
            Write(">(");
            cast.Child.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(Is expr)
        {
            Write("cli::is<");
            WriteTypeReference(SCITypeHandle.Wrap(expr.ProbeType.Type), TypeUsage.New);
            Write(">(");
            expr.Expr.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(As expr)
        {
            Write("cli::as<");
            WriteTypeReference(SCITypeHandle.Wrap(expr.ProbeType.Type), TypeUsage.VarDecl);
            Write(">(");
            expr.Expr.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(NewDelegate del)
        {
            var method = SCIMethodHandle.Wrap(del.MethodGroup.BestCandidate);

            Write("cli::bind(");
            if (del.MethodGroup.IsInstance)
            {
                del.MethodGroup.InstanceExpression.Accept(this);
                Write(", ");
            }

            Write("&");
            WriteMethodReference(method);
            Write(")");

            return null;
        }

        public override object Visit(MethodGroupExpr expr)
        {
            var method = expr.BestCandidate;

            if (method.IsStatic)
            {
                WriteMemberReference(method);
            }
            else
            {
                expr.InstanceExpression.Accept(this);
                WriteDereference(expr.InstanceExpression);
                Write(SCIMethodDefinition.Wrap(method).Name);
            }

            return null;
        }

        public override object Visit(BaseThis expr)
        {
            WriteTypeReference(NameManager.CurrentType.BaseClass, TypeUsage.New);

            return null;
        }

        public override object Visit(BlockConstantDeclaration decl)
        {
            Write("const ");
            Visit((BlockVariableDeclaration)decl);

            return null;
        }

        public override object Visit(DefaultValueExpression expr)
        {
            WriteTypeReference(SCITypeHandle.Wrap(expr.Type), TypeUsage.VarDecl);
            Write("()");

            return null;
        }

        public override object Visit(NewInitialize.InitializerTargetExpression node)
        {
            return null;
        }

        public override object Visit(NewInitialize expr)
        {
            if (expr.Initializers.IsCollectionInitializer)
            {
                var type = SCITypeHandle.Wrap(expr.Type);

                WriteLine("cli::init(");
                WriteTypeReference(type, TypeUsage.VarDecl);
                Write("(");
                WriteArguments(expr.Arguments.Select(e => type), expr.Arguments);
                Write(")");

                foreach (var tmp in expr.Initializers.Initializers)
                {
                    var init = tmp as CollectionElementInitializer;
                    WriteArguments(init.Arguments.Select(e => type), init.Arguments);
                }
                Write(")");
            }
            else
            {
                // object initializer - looks weird because it shall be an expression, not a statement
                WriteLine("([&]() { ");
                using (Indent(4))
                {
                    String tmp = "tmp_" + (m_TmpCounter++);

                    Write("auto " + tmp + " = cli::gcnew<");
                    WriteTypeReference(SCITypeHandle.Wrap(expr.Type), TypeUsage.New);
                    Write(">(");
                //    WriteArguments(null, expr.Arguments);
                    WriteLine(");");

                    expr.Initializers.Initializers.Apply(e =>
                    {
                        var init = e as ElementInitializer;

                        Write(tmp);
                        WriteAssignment(init.Source, init.Target, init.Type);
                        WriteLine(";");
                    });

                    WriteLine();
                    WriteLine("return " + tmp + ";");
                }
                WriteLine("})()");
            }

            return null;
        }

        public override object Visit(CheckedExpr expr)
        {
            Write("cli::checked(");
            expr.Expr.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(UnCheckedExpr expr)
        {
            Write("cli::unchecked(");
            expr.Expr.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(Nullable.Wrap cast)
        {
            Write("cli::wrap_nullable(");
            cast.Child.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(Nullable.Unwrap cast)
        {
            Write("cli::unwrap_nullable(");
            cast.Original.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(Nullable.Lifted cast)
        {
            Write("cli::nullable_lifted(");
            cast.Expr.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(OperatorCast cast)
        {
            var method = SCIMethodHandle.Wrap(cast.ConversionOperator);

            WriteMethodReference(method);
            Write("(");
            cast.Child.Accept(this);
            Write(")");

            return null;
        }

        private void WriteMethodReference(SCIMethodHandle method)
        {
            WriteTypeReference(method.DeclaringType, TypeUsage.New);
            Write("::");

            if(method.ExplicitTypeParameters.Any())
            {
                Write("template ");
                Write(method.Name);
                Write("<");
                method.ExplicitTypeParameters.Apply(
                    e =>
                        {
                            WriteTypeReference(e, TypeUsage.New);
                            Write(", ");
                        });
                RemoveBack(", ");
                Write(">");
            }
            else
                Write(method.Name);
        }

        public override object Visit(ImplicitDelegateCreation del)
        {
            SCIMethodHandle method = SCIMethodHandle.Wrap(del.MethodGroup.BestCandidate);

            if (method.Definition.IsStatic)
            {
                Write("cli::bind(&");
                WriteMethodReference(method);
                Write(")");
            }
            else
            {
                Write("cli::bind(");
                del.MethodGroup.InstanceExpression.Accept(this);
                Write(", &");
                WriteMethodReference(method);
                Write(")");
            }

            return null;
        }

        #endregion

        #region Obvious stuff

        public override object Visit(Block block)
        {
            WriteBlock(block);

            return null;
        }

        protected void WriteBlock(Block block, Procedure injection = null, String title = null)
        {
            if ((block.Statements.Count == 1) && (block.Statements[0] is For))
            {
                WriteBlockContent(block, injection, title);
            }
            else
            {
                WriteLine("{");
                using (Indent(4))
                {
                    WriteBlockContent(block, injection, title);
                }
                WriteLine("}");
            }
        }

        protected void WriteBlockContent(Statement block, Procedure injection = null, String title = null)
        {
            if (title != null)
                WriteLine("/* " + title + " */");

            if (injection != null)
                injection();

            WriteLine("{");
            using (Indent(4))
            {
                block.Accept(this);
            }
            WriteLine("}");
        }

        protected void WriteBlockContent(Block block, Procedure injection = null, String title = null)
        {
            if (title != null)
                WriteLine("/* " + title + " */");

            if (injection != null)
                injection();

            VisitBlock(block);
        }

       

        public override object Visit(Return stmt)
        {
            Func<CppSourceGenerator> g = null;
            Func<object> b = g;
            var method = NameManager.CurrentMemberMethod as SCIMethodDefinition;

            if ((method != null) && method.IsSetter && method.Property.HasGetter)
            {
                // TODO: fix this to return only getter when return value required by parent expression
                // return current getter value
                Write("return " + method.Property.Getter.Name + "(");

                // forward setter parameters in case of indexers
                foreach (var p in method.Parameters)
                {
                    if (p == method.Parameters.Last())
                        break;

                    Write(p.Name);
                    Write(", ");
                }

                RemoveBack(", ");
                WriteLine(")");
            }
            else
            {
				var parentRet = NameManager.CurrentMemberMethod.ReturnType;

				if(stmt is ContextualReturn)
				{
					if(NameManager.CurrentLambda != null)
						parentRet = NameManager.CurrentLambda.ReturnType;

					if((parentRet != null) && parentRet.IsVoid)
	                	Write("");
					else
						Write("return");
				}
				else
					Write("return");

                if ((stmt != null) && (stmt.Expr != null))
                {
                    SCITypeHandle resType = stmt.Expr.Type;
                    
                    Write(" ");

                    if(resType != method.ReturnType)
                    {
                        if(resType.IsArray && method.ReturnType.IsArray)
                        {
                            stmt.Expr.Accept(this);
                            Write("->CovariantCast<");
                            WriteTypeReference(method.ReturnType.Indirection, TypeUsage.FieldDecl);
                            Write(">()");
                        }
                        else
                            stmt.Expr.Accept(this);
                    }
                    else
                        stmt.Expr.Accept(this);
                }
            }

            WriteSemicolon();

            return null;
        }

        public override object Visit(SimpleName name)
        {
            if (name.Type != null)
                WriteTypeReference(SCITypeHandle.Wrap(name.Type), TypeUsage.New);
            else 
            {
                if (NameManager.CurrentMemberMethod != null)
                {
                    var varName = NameManager.CurrentMemberMethod.Variables.FirstOrDefault(e => e.Name == name.Name);
                    if (varName != null)
                    {
                        Write(varName.Name);
                        return null;
                    }

                    var paramName = NameManager.CurrentMemberMethod.Parameters.FirstOrDefault(e => e.Name == name.Name);
                    if (paramName != null)
                    {
                        Write(paramName.Name);
                        return null;
                    }
                }

                var member = NameManager.CurrentType.ResolveMember(name.Name);
                if (member is SCIPropertyDefinition)
                {
                    var prop = member as SCIPropertyDefinition;
                    Write(prop.Getter.Name);
                    Write("()");
                }
                else
                    Write(member.Name);
            }

            return null;
        }

        public override object Visit(StatementExpression stmt)
        {
            stmt.Expr.Accept(this);
            WriteSemicolon();

            return null;
        }

        protected void WriteDifferenceType(SCITypeHandle baseType, SCITypeHandle diffType)
        {
            String baseStr, diffStr;

            using (var gen = PrivateBuilder())
            {
                WriteTypeReference(baseType, TypeUsage.VarDecl);
                baseStr = gen.ToString();
                while (baseStr.EndsWith("*")) baseStr = baseStr.Substring(0, baseStr.Length - 1);
            }

            using (var gen = PrivateBuilder())
            {
                WriteTypeReference(diffType, TypeUsage.VarDecl);
                diffStr = gen.ToString();
            }

            if (!diffStr.StartsWith(baseStr))
                throw new ApplicationException();

            // pointers are the only type difference in C#
            String res = diffStr.Substring(baseStr.Length);

            if (res.Any(c => c != '*'))
                throw new ApplicationException();

            Write(res);
        }


        public override object Visit(VarExpr v)
        {
            Write("auto");

            return null;
        }

        public override object Visit(TypeExpression expr)
        {
            WriteTypeReference(SCITypeHandle.Wrap(expr.Type), TypeUsage.New);

            return null;
        }

        public override object Visit(LocalTemporary tmp)
        {
            return null;
        }

        public override object Visit(Continue stmt)
        {
            Write("continue");
            WriteSemicolon();

            return null;
        }

        public override object Visit(EmptyStatement stmt)
        {
            WriteSemicolon();

            return null;
        }

        public override object Visit(While stmt)
        {
            Write("while(");
            stmt.expr.Accept(this);
            Write(") ");
            stmt.Statement.Accept(this);

            return null;
        }

        public override object Visit(Do stmt)
        {
            Write("do ");
            stmt.EmbeddedStatement.Accept(this);
            Write("while(");
            stmt.expr.Accept(this);
            Write(")");
            WriteSemicolon();

            return null;
        }

        public override object Visit(SizeOf node)
        {
            Write("sizeof(");
            node.TypeExpression.Accept(this);
            Write(")");

            return null;
        }

        protected void WriteStatementAsBlock(Statement stmt)
        {
            if (stmt is Block)
            {
                stmt.Accept(this);
            }
            else
            {
                WriteLine("{");
                using (Indent(4))
                {
                    stmt.Accept(this);
                }
                WriteLine("}");
            }
        }

        public override object Visit(If stmt)
        {
            Write("if(");
            stmt.Expr.Accept(this);
            WriteLine(") ");
            WriteStatementAsBlock(stmt.TrueStatement);

            if (stmt.FalseStatement != null)
            {
                WriteLine(" else ");
                WriteStatementAsBlock(stmt.FalseStatement);
            }

            return null;
        }

        public override object Visit(LabeledStatement stmt)
        {
            WriteLine(stmt.Name + ":");

            return null;
        }

        public override object Visit(Conditional expr)
        {
            expr.Expr.Accept(this);
            Write(" ? ");
            expr.TrueExpr.Accept(this);
            Write(" : ");
            expr.FalseExpr.Accept(this);

            return null;
        }

        public override object Visit(Unsafe stmt)
        {
            WriteBlockContent(stmt.Block);
            return null;
        }

        public override object Visit(ShimExpression node)
        {
            return node.Expr.Accept(this);
        }

        public override object Visit(Fixed.ExpressionEmitter emitter)
        {
            emitter.Expr.Accept(this);

            return null;
        }

        public override object Visit(Cast cast)
        {
            Write("(");
            cast.TargetType.Accept(this);
            Write(")");
            cast.Expr.Accept(this);

            return null;
        }

        public override object Visit(Indirection expr)
        {
            Write("(*");
            expr.Expr.Accept(this);
            Write(")");

            return null;
        }

        public override object Visit(ArrayPtr arrayPtr)
        {
            arrayPtr.Array.Accept(this);

            return null;
        }

        public override object Visit(This expr)
        {
            if(NameManager.CurrentType.IsStruct)
                Write("(*this)");
            else
                Write("this");

            return null;
        }

        public override object Visit(Goto stmt)
        {
            Write("goto " + stmt.Target);
            WriteSemicolon();

            return null;
        }

        public override object Visit(ReducedExpression expr)
        {
            expr.Expr.Accept(this);

            return null;
        }

        #endregion
    }
}
