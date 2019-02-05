package ast.expression.literal;

import ast.context.Context;
import ast.expression.Expression;

import java.util.HashMap;

public class ArrayLiteral extends Indexable {

    public HashMap<Literal,Literal> value = new HashMap<>();

    public ArrayLiteral( )
    {
        //Initialize as empty hashmap for now..
    }

    @Override
    public Expression evaluate(Context c) {
        return this;
    }

    public HashMap<Literal,Literal> value()
    {
        return value;
    }

    public String toString()
    {
        return "" + value;
    }

    @Override
    public Literal at(Literal index) {
        return value.get(index);
    }

    @Override
    public void set(Expression index, Expression value) {
        this.value.put((Literal)index,(Literal)value);
    }
}
