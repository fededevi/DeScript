package ast.expression.bool;

import ast.context.Context;
import ast.expression.Binary;
import ast.expression.Expression;
import ast.expression.literal.BooleanLiteral;
import ast.expression.literal.Comparable;

public class LessThan extends Binary {

	public LessThan(Expression l, Expression r) {
		super(l, r);
	}

	@Override
	public Expression evaluate(Context c) {
		Comparable l = (Comparable)left.evaluate(c);
		Comparable r = (Comparable)right.evaluate(c);
	
		return new BooleanLiteral(l.compare(r) < 0);
	}

	public String toString() {
		return "(" + left + "<" + right + ")";
	}

}
