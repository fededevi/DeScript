package ast.expression.math;

import ast.context.Context;
import ast.expression.Binary;
import ast.expression.Expression;
import ast.expression.literal.IntegerLiteral;

public class Mul extends Binary {
	public Mul(Expression l, Expression r) {
		super(l, r);
		// TODO Auto-generated constructor stub
	}

	@Override
	public Expression evaluate(Context c) {
		IntegerLiteral l = (IntegerLiteral)left.evaluate(c);
		IntegerLiteral r = (IntegerLiteral)right.evaluate(c);
		
		return new IntegerLiteral( l.value()*r.value());
	}


	public String toString()
	{
		return "("+left + "*" + right+")";
	}
}
