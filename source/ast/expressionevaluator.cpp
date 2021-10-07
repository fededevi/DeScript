#include "expressionevaluator.h"
#include "expression.h"
#include <stdexcept>

void *ExpressionEvaluator::visit(const Add *node, void *data) const
{
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


void *ExpressionEvaluator::visit(const LessThan *node, void *data) const
{
}

void *ExpressionEvaluator::visit(const LessEqual *node, void *data) const
{

}

void *ExpressionEvaluator::visit(const GreaterEqual *node, void *data) const
{

}

void *ExpressionEvaluator::visit(const GreaterThan *node, void *data) const
{

}

void *ExpressionEvaluator::visit(const Equal *node, void *data) const
{

}

void *ExpressionEvaluator::visit(const NotEqual *node, void *data) const
{

}

void *ExpressionEvaluator::visit(const Not *node, void *data) const
{

}



