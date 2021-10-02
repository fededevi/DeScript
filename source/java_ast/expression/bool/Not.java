package ast.expression.bool;

import ast.context.Context;
import ast.expression.Expression;
import ast.expression.Unary;
import ast.expression.literal.BooleanLiteral;

public class Not extends Unary {

	public Not(Expression p)
	{
		param = p;
	}
	
	public Expression evaluate(Context c) {

		BooleanLiteral l = (BooleanLiteral)param.evaluate(c);
		
		return new BooleanLiteral(!l.value);
	}


	public String toString()
	{
		return "!(" + param +")";
	}
}
