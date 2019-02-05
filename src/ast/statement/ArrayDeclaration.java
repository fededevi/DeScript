package ast.statement;

import ast.context.Context;
import ast.expression.literal.ArrayLiteral;

/**
 * Represents the declaration of an array:
 * var <IDENTIFIER>[];
 */

public class ArrayDeclaration extends Statement{
    Identifier identifier;

    public ArrayDeclaration(Identifier i)
    {
        this.identifier = i;
    }

    @Override
    public void execute(Context c) {

        c.addNew(identifier, new ArrayLiteral());

        if (next != null)
            next.execute(c);
    }



    public String toString()
    {
        String a =  "var " +identifier +"[];\n";

        if (next != null)
            a += next;
        return a;
    }
}
