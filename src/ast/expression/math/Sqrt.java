package ast.expression.math;

import ast.context.Context;
import ast.expression.DInteger;
import ast.expression.Expression;
import ast.expression.Unary;

public class Sqrt extends Unary {


	public Sqrt(Expression p)
	{
		param = p;
	}
	
	public Expression evaluate(Context c) {

		Expression l = param.evaluate(c);
		
		if (l instanceof DInteger)
		{
			int result = (int) Math.sqrt(((DInteger)l).value());
			return new DInteger(result);
		}
		else
		{
			//error
			return null;
		}
	}


	public String toString()
	{
		return "sqrt(" + param +")";
	}
}
