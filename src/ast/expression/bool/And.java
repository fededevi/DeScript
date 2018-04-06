package ast.expression.bool;

import ast.context.Context;
import ast.expression.Binary;
import ast.expression.Expression;
import ast.expression.literal.BooleanLiteral;

public class And extends Binary {
	
	public And(Expression l, Expression r) {
		super(l, r);
	}

	@Override
	public Expression evaluate(Context c) {
		
		BooleanLiteral l = (BooleanLiteral)left.evaluate(c);
		BooleanLiteral r = (BooleanLiteral)right.evaluate(c);
	
		return new BooleanLiteral(l.value == r.value == true);
	}

	public String toString()
	{
		return "("+left + "&&" + right+")";
	}

}
