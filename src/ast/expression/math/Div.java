package ast.expression.math;

import ast.context.Context;
import ast.expression.Binary;
import ast.expression.DInteger;
import ast.expression.Expression;

public class Div extends Binary {
	public Div(Expression l, Expression r) {
		super(l, r);
		// TODO Auto-generated constructor stub
	}

	@Override
	public Expression evaluate(Context c) {

		Expression l = left.evaluate(c);
		Expression r = right.evaluate(c);
		
		if (l instanceof DInteger && r instanceof DInteger)
		{
			int result = ((DInteger)l).value()/((DInteger)r).value();
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
		return "("+left + "/" + right+")";
	}
}
