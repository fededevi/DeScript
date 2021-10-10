#include "expressionevaluator.h"
#include "expression.h"
#include "datatype.h"
#include <stdexcept>
#include <iostream>

void * evaluateBinaryMethodCall(const BinaryExpression *node, const Name & name, Context * ctx) {
    std::unique_ptr<Literal> left  = std::unique_ptr<Literal>(static_cast<Literal *>(node->left->evaluate(ctx)));
    std::unique_ptr<Literal> right = std::unique_ptr<Literal>(static_cast<Literal *>(node->right->evaluate(ctx)));

    MethodSignature ms = MethodSignature({name, {left->type, right->type}});

    if (!left->type->contains(ms))
        std::cout << "Undefined method -> " <<left->type->name << ":" << Method::signature(ms) << std::endl;

    Method method(left->type->methods.at(ms));

    return method.implementation({left.get(), right.get()});
}

void * evaluateUnaryMethodCall(const UnaryExpression *node, const Name & name, Context * ctx) {
    std::unique_ptr<Literal> op  = std::unique_ptr<Literal>(static_cast<Literal *>(node->operand->evaluate(ctx)));

    MethodSignature ms = MethodSignature({name, {op->type}});

    if (!op->type->contains(ms))
        std::cout << "Undefined method -> " <<op->type->name << ":" << Method::signature(ms) << std::endl;

    Method method(op->type->methods.at(ms));

    return method.implementation({op.get()});

}

void *ExpressionEvaluator::visit(const Add *node, void * data) const{
    return evaluateBinaryMethodCall(node, Name("+"), static_cast<Context *>(data) );
}

void *ExpressionEvaluator::visit(const Sub *node, void *data) const{
    return evaluateBinaryMethodCall(node, Name("-"), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const Mul *node, void *data) const{
    return evaluateBinaryMethodCall(node, Name("*"), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const Div *node, void *data) const{
    return evaluateBinaryMethodCall(node, Name("/"), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const Mod *node, void *data) const{
    return evaluateBinaryMethodCall(node, Name("%"), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const Int *node, void *) const{
    return new Int(node->value);
}

void *ExpressionEvaluator::visit(const Id *node, void * data) const{
    Context * c = static_cast<Context *>(data);
    return c->data.at(node->value).get();
}

void *ExpressionEvaluator::visit(const Float *node, void *) const{
    return new Float(node->value);
}

void *ExpressionEvaluator::visit(const Boolean *node, void *) const{
    return new Boolean(node->value);
}


void *ExpressionEvaluator::visit(const LessThan *node, void * data) const{
    return evaluateBinaryMethodCall(node, Name("<"), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const LessEqual *node, void * data) const{
    return evaluateBinaryMethodCall(node, Name("<="), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const GreaterEqual *node, void * data) const{
    return evaluateBinaryMethodCall(node, Name(">="), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const GreaterThan *node, void * data) const{
    return evaluateBinaryMethodCall(node, Name(">"), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const Equal *node, void * data) const{
    return evaluateBinaryMethodCall(node, Name("=="), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const NotEqual *node, void * data) const{
    return evaluateBinaryMethodCall(node, Name("!="), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const Not *node, void * data) const{
    return evaluateUnaryMethodCall(node, Name("!"), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const Neg *node, void * data) const
{
    return evaluateUnaryMethodCall(node, Name("-"), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const And *node, void * data) const{
    return evaluateBinaryMethodCall(node, Name("&&"), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const Or *node, void * data) const{
    return evaluateBinaryMethodCall(node, Name("||"), static_cast<Context *>(data));
}

void *ExpressionEvaluator::visit(const TypeId *node, void *data) const
{

}

void *ExpressionEvaluator::visit(const Parameter *node, void *data) const
{

}

void *ExpressionEvaluator::visit(const Method *node, void *data) const
{

}



