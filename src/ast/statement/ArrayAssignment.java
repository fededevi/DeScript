package ast.statement;

import ast.context.Context;
import ast.expression.Expression;
import ast.expression.literal.ArrayLiteral;

/**
 * Represents the assignemnt of a expression  to an array index
 * <IDENTIFIER> [<EXPRESSION>] = <EXPRESSION>
 */
public class ArrayAssignment extends Assignment {

    Expression index;

    public ArrayAssignment(Identifier identifier, Expression index, Expression expression)
    {
        super(identifier,expression);
        this.index = index;
    }

    public void execute(Context c) {
        //Get the array literal from the context
        ArrayLiteral al = (ArrayLiteral) c.value(identifier);
        //Set the value n the index, whatever that means
        al.set(index.evaluate(c), expression.evaluate(c));
        //put the new array into the context
        c.assign(identifier, al );

        if (next != null)
            next.execute(c);
    }

    public String toString()
    {
        String a =  identifier + "[" +index+ "]"+":=" + expression + ";\n";

        if (next != null)
            a += next;
        return a;
    }
}
