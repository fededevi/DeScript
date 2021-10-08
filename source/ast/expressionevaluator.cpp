#include "expressionevaluator.h"
#include "expression.h"
#include "datatype.h"
#include <stdexcept>

void *ExpressionEvaluator::visit(const Add *node, void *data) const
{
    Literal * left  = static_cast<Literal *>(node->left->evaluate());
    Literal * right = static_cast<Literal *>(node->right->evaluate());

    const Method & method(left->type->methods.at(MethodSignature("operator+", {left->type, right->type})));
    return method.implementation({(void*)left, (void*)right});

}

void *ExpressionEvaluator::visit(const Sub *node, void *data) const
{
}

void *ExpressionEvaluator::visit(const Mul *node, void *data) const
{
}

void *ExpressionEvaluator::visit(const Div *node, void *data) const
{
}

void *ExpressionEvaluator::visit(const Mod *node, void *data) const
{

}

void *ExpressionEvaluator::visit(const Int *node, void *) const{
    return new Int(node->value);
}

void *ExpressionEvaluator::visit(const Id *node, void *) const{
    return new Id(node->value);
}

void *ExpressionEvaluator::visit(const Float *node, void *) const{
    return new Float(node->value);
}

void *ExpressionEvaluator::visit(const Boolean *node, void *) const{
    return new Boolean(node->value);
}


void *ExpressionEvaluator::visit(const LessThan *node, void *) const
{

}

void *ExpressionEvaluator::visit(const LessEqual *node, void *) const
{

}

void *ExpressionEvaluator::visit(const GreaterEqual *node, void *) const
{

}

void *ExpressionEvaluator::visit(const GreaterThan *node, void *) const
{

}

void *ExpressionEvaluator::visit(const Equal *node, void *) const
{

}

void *ExpressionEvaluator::visit(const NotEqual *node, void *) const
{

}

void *ExpressionEvaluator::visit(const Not *node, void *) const
{

}

void *ExpressionEvaluator::visit(const And *node, void *) const
{

}

void *ExpressionEvaluator::visit(const Or *node, void *) const
{

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



