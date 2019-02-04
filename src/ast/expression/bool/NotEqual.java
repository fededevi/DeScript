package ast.expression.bool;

import ast.context.Context;
import ast.expression.Binary;
import ast.expression.Expression;
import ast.expression.literal.BooleanLiteral;
import ast.expression.literal.Equatable;

public class NotEqual extends Binary {
	
	public NotEqual(Expression l, Expression r) {
		super(l, r);
	}

	@Override
	public Expression evaluate(Context c) {
		Equatable l = (Equatable)left.evaluate(c);
		Equatable r = (Equatable)right.evaluate(c);
	
		return new BooleanLiteral(!l.equal(r));
	}

	public String toString()
	{
		return "("+left + "!=" + right+")";
	}

}
