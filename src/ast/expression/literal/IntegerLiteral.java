package ast.expression.literal;

import ast.context.Context;
import ast.expression.Expression;

public class IntegerLiteral extends Comparable {
	
	public int value;
	
	public IntegerLiteral( int value)
	{
		this.value = value;
	}

	@Override
	public Expression evaluate(Context c) {
		return this;
	}
	
	public int value()
	{
		return value;
	}
	
	public String toString()
	{
		return "" + value;
	}

	@Override
	public int compare(Comparable c) {
		return value - ((IntegerLiteral) c).value;
	}

	@Override
	public boolean equal(Equatable e) {
		return value == ((IntegerLiteral) e).value;
	}
}
