//
// visit.cs: Visitors for parsed dom
//
// Authors: Mike Krüger (mkrueger@novell.com)
//          Marek Safar (marek.safar@gmail.com)
//
// Dual licensed under the terms of the MIT X11 or GNU GPL
//
// Copyright (c) 2010 Novell, Inc (http://www.novell.com)
// Copyright 2011 Xamarin Inc
//

using System;
using System.Diagnostics;
using Mono.CSharp.Linq;
using Mono.CSharp.Nullable;

namespace Mono.CSharp
{
    [Serializable]
    public abstract class StructuralVisitor
    {
        public StructuralVisitor()
        {

        }

        public virtual object Visit(MemberCore member)
        {
            return null;
        }

        public virtual void VisitTypeContainer(TypeContainer tc)
        {
            foreach (TypeContainer container in tc.Containers)
            {
                container.Accept(this);
            }
        }

        public virtual void VisitTypeContainer(TypeDefinition tc)
        {
            foreach (MemberCore member in tc.Members)
            {
                member.Accept(this);
            }
        }

        public virtual object Visit(NewInitialize.InitializerTargetExpression node)
        {
            return null;
        }

        public virtual object Visit(ModuleContainer module)
        {
            VisitTypeContainer(module);

            return null;
        }

        public virtual object Visit(UsingNamespace un)
        {
            return null;
        }

        public virtual object Visit(UsingAliasNamespace uan)
        {
            return null;
        }

        public virtual object Visit(Iterator node)
        {
            return null;
        }

        public virtual object Visit(UsingExternAlias uea)
        {
            return null;
        }

        public virtual object Visit(GenericTypeExpr expr)
        {
            return null;
        }

        public virtual object Visit(Wrap cast)
        {
            return null;
        }

        public virtual object Visit(Unwrap node)
        {
            return null;
        }

        public virtual object Visit(Lifted node)
        {
            return null;
        }


        public virtual object Visit(OperatorCast node)
        {
            return null;
        }

        public virtual object Visit(ImplicitDelegateCreation node)
        {
            return null;
        }

        public virtual object Visit(ParameterReference node)
        {
            return null;
        }

        public virtual object Visit(AnonymousExpression.AnonymousMethodMethod node)
        {
            return null;
        }

        public virtual object Visit(Catch node)
        {
            return null;
        }

        public virtual object Visit(Statement node)
        {
            return null;
        }

        public virtual object Visit(ShimExpression node)
        {
            return null;
        }

        #if STATIC
        public virtual object Visit(ModuleContainer.StaticDataContainer node)
        {
            return null;
        }
        #endif

        public virtual object Visit(AnonymousMethodStorey node)
        {
            return null;
        }

        public virtual object Visit(AnonymousMethodExpression node)
        {
            return null;
        }

        public virtual object Visit(AnonymousMethodBody node)
        {
            return null;
        }


        public virtual object Visit(NamespaceContainer node)
        {
            return null;
        }

        public virtual object Visit(Class node)
        {
            return null;
        }

        public virtual object Visit(Struct node)
        {
            return null;
        }

        public virtual object Visit(Interface node)
        {
            return null;
        }

        public virtual object Visit(DelegateInvocation node)
        {
            return null;
        }

        public virtual object Visit(Delegate node)
        {
            return null;
        }

        public virtual object Visit(Enum node)
        {
            return null;
        }

        public virtual object Visit(FixedField node)
        {
            return null;
        }

        public virtual object Visit(Const node)
        {
            return null;
        }

        public virtual object Visit(Field node)
        {
            return null;
        }

        public virtual object Visit(FieldExpr node)
        {
            return null;
        }

        public virtual object Visit(Operator node)
        {
            return null;
        }

        public virtual object Visit(Indexer node)
        {
            return null;
        }

        public virtual object Visit(Method node)
        {
            return null;
        }

        public virtual object Visit(Property node)
        {
            return null;
        }

        public virtual object Visit(PropertyBase.GetMethod node)
        {
            return null;
        }

        public virtual object Visit(PropertyBase.SetMethod node)
        {
            return null;
        }

        public virtual object Visit(Constructor node)
        {
            return null;
        }

        public virtual object Visit(Destructor node)
        {
            return null;
        }

        public virtual object Visit(EventField node)
        {
            return null;
        }

        public virtual object Visit(EventProperty node)
        {
            return null;
        }

        public virtual object Visit(EnumMember node)
        {
            return null;
        }

        public virtual object Visit(BlockVariableDeclaration node)
        {
            return null;
        }

        public virtual object Visit(BlockConstantDeclaration node)
        {
            return null;
        }

        public virtual object Visit(EmptyStatement node)
        {
            return null;
        }

        public virtual object Visit(EmptyExpressionStatement node)
        {
            return null;
        }

        public virtual object Visit(EmptyExpression node)
        {
            return null;
        }

        public virtual object Visit(ErrorExpression node)
        {
            return null;
        }

        public virtual object Visit(If node)
        {
            return null;
        }

        public virtual object Visit(UserOperatorCall node)
        {
            return null;
        }

        public virtual object Visit(Do node)
        {
            return null;
        }

        public virtual object Visit(While node)
        {
            return null;
        }

        public virtual object Visit(VarExpr node)
        {
            return null;
        }

        public virtual object Visit(For node)
        {
            return null;
        }

        public virtual object Visit(StatementExpression node)
        {
            return null;
        }

        public virtual object Visit(StatementErrorExpression node)
        {
            return null;
        }

        public virtual object Visit(Return node)
        {
            return null;
        }

        public virtual object Visit(Goto node)
        {
            return null;
        }

        public virtual object Visit(LabeledStatement node)
        {
            return null;
        }

        public virtual object Visit(GotoDefault node)
        {
            return null;
        }

        public virtual object Visit(GotoCase node)
        {
            return null;
        }

        public virtual object Visit(Throw node)
        {
            return null;
        }

        public virtual object Visit(Break node)
        {
            return null;
        }

        public virtual object Visit(Continue node)
        {
            return null;
        }

        public virtual object Visit(Block node)
        {
            return null;
        }

        public virtual object Visit(Switch node)
        {
            return null;
        }

        public virtual object Visit(StatementList node)
        {
            return null;
        }

        public virtual object Visit(Lock node)
        {
            return null;
        }

        public virtual object Visit(Unchecked node)
        {
            return null;
        }

        public virtual object Visit(Checked node)
        {
            return null;
        }

        public virtual object Visit(Unsafe node)
        {
            return null;
        }

        public virtual object Visit(Fixed node)
        {
            return null;
        }

        public virtual object Visit(TryFinally node)
        {
            return null;
        }

        public virtual object Visit(TryCatch node)
        {
            return null;
        }

        public virtual object Visit(CompoundAssign.TargetExpression node)
        {
            return null;
        }

        public virtual object Visit(Using node)
        {
            return null;
        }

        public virtual object Visit(Foreach node)
        {
            return null;
        }

        public virtual object Visit(Yield node)
        {
            return null;
        }

        public virtual object Visit(YieldBreak node)
        {
            return null;
        }

        public virtual object Visit(ReducedExpression node)
        {
            return null;
        }

        public virtual object Visit(PointerArithmetic node)
        {
            return null;
        }

        public virtual object Visit(IndexerExpr node)
        {
            return null;
        }

        public virtual object Visit(StringConcat node)
        {
            return null;
        }

        public virtual object Visit(MethodGroupExpr node)
        {
            return null;
        }

        public virtual object Visit(Expression node)
        {
            return null;
        }

        public virtual object Visit(NewDelegate node)
        {
            return null;
        }

        public virtual object Visit(UnboxCast node)
        {
            return null;
        }

        public virtual object Visit(BoxedCast node)
        {
            return null;
        }

        public virtual object Visit(ClassCast node)
        {
            return null;
        }

        public virtual object Visit(LocalTemporary node)
        {
            return null;
        }

        public virtual object Visit(UserCast node)
        {
            return null;
        }

        public virtual object Visit(ConvCast node)
        {
            return null;
        }

        public virtual object Visit(ArrayIndexCast node)
        {
            return null;
        }

        public virtual object Visit(ArrayPtr node)
        {
            return null;
        }

        public virtual object Visit(OpcodeCast node)
        {
            return null;
        }

        public virtual object Visit(EmptyCast node)
        {
            return null;
        }

        public virtual object Visit(Fixed.ExpressionEmitter node)
        {
            return null;
        }

        public virtual object Visit(PropertyExpr node)
        {
            return null;
        }

        public virtual object Visit(ArrayAccess node)
        {
            return null;
        }

        public virtual object Visit(MemberAccess node)
        {
            return null;
        }

        public virtual object Visit(QualifiedAliasMember node)
        {
            return null;
        }

        public virtual object Visit(LocalVariableReference node)
        {
            return null;
        }

        public virtual object Visit(Constant node)
        {
            return null;
        }

        public virtual object Visit(BooleanExpression node)
        {
            return null;
        }

        public virtual object Visit(SimpleName node)
        {
            return null;
        }

        public virtual object Visit(ParenthesizedExpression node)
        {
            return null;
        }

        public virtual object Visit(Unary node)
        {
            return null;
        }

        public virtual object Visit(UnaryMutator node)
        {
            return null;
        }

        public virtual object Visit(Indirection node)
        {
            return null;
        }

        public virtual object Visit(Is node)
        {
            return null;
        }

        public virtual object Visit(As node)
        {
            return null;
        }

        public virtual object Visit(Cast node)
        {
            return null;
        }

        public virtual object Visit(ComposedCast node)
        {
            return null;
        }

        public virtual object Visit(DefaultValueExpression node)
        {
            return null;
        }

        public virtual object Visit(DefaultParameterValueExpression node)
        {
            return null;
        }

        public virtual object Visit(Binary node)
        {
            return null;
        }

        public virtual object Visit(NullCoalescingOperator node)
        {
            return null;
        }

        public virtual object Visit(Conditional node)
        {
            return null;
        }

        public virtual object Visit(Invocation node)
        {
            return null;
        }

        public virtual object Visit(New node)
        {
            return null;
        }

        public virtual object Visit(NewAnonymousType node)
        {
            return null;
        }

        public virtual object Visit(NewInitialize node)
        {
            return null;
        }

        public virtual object Visit(ArrayCreation node)
        {
            return null;
        }

        public virtual object Visit(This node)
        {
            return null;
        }

        public virtual object Visit(ArglistAccess node)
        {
            return null;
        }

        public virtual object Visit(Arglist node)
        {
            return null;
        }

        public virtual object Visit(TypeOf node)
        {
            return null;
        }

        public virtual object Visit(SizeOf node)
        {
            return null;
        }

        public virtual object Visit(CheckedExpr node)
        {
            return null;
        }

        public virtual object Visit(UnCheckedExpr node)
        {
            return null;
        }

        public virtual object Visit(ElementAccess node)
        {
            return null;
        }

        public virtual object Visit(BaseThis node)
        {
            return null;
        }

        public virtual object Visit(StackAlloc node)
        {
            return null;
        }

        public virtual object Visit(SimpleAssign node)
        {
            return null;
        }

        public virtual object Visit(CompoundAssign node)
        {
            return null;
        }

        public virtual object Visit(TypeExpression node)
        {
            return null;
        }

        public virtual object Visit(LambdaExpression node)
        {
            return null;
        }

        public virtual object Visit(ConstInitializer node)
        {
            return null;
        }

        public virtual object Visit(ArrayInitializer node)
        {
            return null;
        }

        public virtual object Visit(AQueryClause.QueryExpressionAccess node)
        {
            return null;
        }

        public virtual object Visit(AQueryClause.QueryExpressionInvocation node)
        {
            return null;
        }

        public virtual object Visit(QueryExpression node)
        {
            return null;
        }

        public virtual object Visit(QueryStartClause node)
        {
            return null;
        }

        public virtual object Visit(SelectMany node)
        {
            return null;
        }

        public virtual object Visit(Select node)
        {
            return null;
        }

        public virtual object Visit(GroupBy node)
        {
            return null;
        }

        public virtual object Visit(Let node)
        {
            return null;
        }

        public virtual object Visit(Where node)
        {
            return null;
        }

        public virtual object Visit(Join node)
        {
            return null;
        }

        public virtual object Visit(GroupJoin node)
        {
            return null;
        }

        public virtual object Visit(OrderByAscending node)
        {
            return null;
        }

        public virtual object Visit(OrderByDescending node)
        {
            return null;
        }

        public virtual object Visit(ThenByAscending node)
        {
            return null;
        }

        public virtual object Visit(ThenByDescending node)
        {
            return null;
        }

        public virtual object Visit(RefValueExpr node)
        {
            return null;
        }

        public virtual object Visit(RefTypeExpr node)
        {
            return null;
        }

        public virtual object Visit(MakeRefExpr node)
        {
            return null;
        }

        public virtual object Visit(Await node)
        {
            return null;
        }
    }
}