package ast.expression.bool;

import ast.context.Context;
import ast.expression.Expression;
import ast.expression.Unary;
import ast.expression.literal.IntegerLiteral;

public class Not extends Unary {


	public Not(Expression p)
	{
		param = p;
	}
	
	public Expression evaluate(Context c) {

		Expression l = param.evaluate(c);
		
		if (l instanceof IntegerLiteral)
		{
			int result = (int) Math.sqrt(((IntegerLiteral)l).value());
			return new IntegerLiteral(result);
		}
		else
		{
			//error
			return null;
		}
	}


	public String toString()
	{
		return "!(" + param +")";
	}
}
