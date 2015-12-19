using System;
using System.Collections.Generic;
using Mono.CSharp;
using NotImplementedException = System.NotImplementedException;

namespace Cs2Cpp
{
    /// <summary>
    /// Only a subset of all distinct possible types is currently differentiable
    /// via Visit() calls. If you need to further specialize Visit(), feel free to
    /// add the proper Visit() call to IStructuralVisitor and this adapter. But 
    /// always make sure that there is some code that actually calls the Visit()
    /// method you add.
    /// </summary>
    [Serializable]
    class StructuralVisitorAdapter : StructuralVisitor
    {
        public virtual void VisitMembers(IEnumerable<MemberCore> members)
        {
            if (members == null)
                return;

            foreach (var member in members)
            {
                member.Accept(this);
            }
        }
        
        public override void VisitTypeContainer(TypeContainer tc)
        {
            if (tc.Containers == null)
                return;
            
            foreach (var e in tc.Containers)
            {
                e.Accept(this);
            }
        }

        protected virtual void VisitBlock(Block block)
        {
            if (block.Statements == null)
                return;

            foreach (var e in block.Statements)
            {
                e.Accept(this);
            }
        }

        public override object Visit(Mono.CSharp.Nullable.Wrap cast)
        {
            return ((StructuralVisitor)this).Visit(cast);
        }

        public override object Visit(Mono.CSharp.Nullable.Unwrap node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Nullable.Lifted node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(OperatorCast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ImplicitDelegateCreation node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ParameterReference node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(AnonymousExpression.AnonymousMethodMethod node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Catch node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Statement node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ModuleContainer.StaticDataContainer node)
        {
            throw new NotImplementedException();
        }

        public override object Visit(MemberCore node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ShimExpression node)
        {
            throw new NotImplementedException();
        }

        public override object Visit(AnonymousMethodStorey node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(AnonymousMethodExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(AnonymousMethodBody node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ModuleContainer node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(NamespaceContainer node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Class node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Struct node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Interface node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(DelegateInvocation node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Delegate node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Enum node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(FixedField node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Const node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Field node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(FieldExpr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Operator node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Indexer node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Method node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Property node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Property.GetMethod node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Property.SetMethod node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Constructor node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Destructor node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(EventField node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(EventProperty node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(EnumMember node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(BlockVariableDeclaration node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(BlockConstantDeclaration node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(EmptyStatement node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(EmptyExpressionStatement node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(EmptyExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ErrorExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(If node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(UserOperatorCall node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Do node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(While node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(VarExpr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(For node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(StatementExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(StatementErrorExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Return node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Goto node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(LabeledStatement node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(GotoDefault node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(GotoCase node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Throw node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Break node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Continue node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Block node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Switch node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(StatementList node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Lock node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Unchecked node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Checked node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Unsafe node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Fixed node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(TryFinally node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(TryCatch node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(CompoundAssign.TargetExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Using node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Foreach node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Yield node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(YieldBreak node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ReducedExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(PointerArithmetic node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(IndexerExpr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(StringConcat node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(MethodGroupExpr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Iterator node)
        {
            throw new NotImplementedException();
        }

        public override object Visit(GenericTypeExpr node)
        {
            throw new NotImplementedException();
        }

        public override object Visit(Expression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(NewInitialize.InitializerTargetExpression node)
        {
            throw new NotImplementedException();
        }

        public override object Visit(NewDelegate node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(UnboxCast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(BoxedCast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ClassCast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(LocalTemporary node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(UserCast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ConvCast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ArrayIndexCast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ArrayPtr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(OpcodeCast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(EmptyCast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Fixed.ExpressionEmitter node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(PropertyExpr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ArrayAccess node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(MemberAccess node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(QualifiedAliasMember node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(LocalVariableReference node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Constant node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(BooleanExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(SimpleName node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ParenthesizedExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Unary node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(UnaryMutator node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Indirection node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Is node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(As node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Cast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ComposedCast node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(DefaultValueExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(DefaultParameterValueExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Binary node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Nullable.NullCoalescingOperator node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Conditional node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Invocation node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(New node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(NewAnonymousType node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(NewInitialize node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ArrayCreation node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(This node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ArglistAccess node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Arglist node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(TypeOf node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(SizeOf node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(CheckedExpr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(UnCheckedExpr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ElementAccess node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(BaseThis node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(StackAlloc node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(SimpleAssign node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(CompoundAssign node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(TypeExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(LambdaExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ConstInitializer node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(ArrayInitializer node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.AQueryClause.QueryExpressionAccess node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.AQueryClause.QueryExpressionInvocation node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.QueryExpression node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.QueryStartClause node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.SelectMany node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.Select node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.GroupBy node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.Let node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.Where node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.Join node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.GroupJoin node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.OrderByAscending node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.OrderByDescending node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.ThenByAscending node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Mono.CSharp.Linq.ThenByDescending node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(RefValueExpr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(RefTypeExpr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(MakeRefExpr node)
        {
             throw new NotImplementedException();
        }

        public override object Visit(Await node)
        {
             throw new NotImplementedException();
        }

       
    }
}
