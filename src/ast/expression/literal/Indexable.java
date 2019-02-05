package ast.expression.literal;

import ast.expression.Expression;

public abstract class Indexable extends Literal{

    public abstract Literal at(Literal index);
    public abstract void set(Expression index, Expression value);

}
