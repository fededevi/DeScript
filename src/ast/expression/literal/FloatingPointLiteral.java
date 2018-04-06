package ast.expression.literal;

import ast.context.Context;
import ast.expression.Expression;

public class FloatingPointLiteral extends Comparable {
	
	public double value;
	
	public FloatingPointLiteral( double value)
	{
		this.value = value;
	}

	@Override
	public Expression evaluate(Context c) {
		return this;
	}
	
	public double value()
	{
		return value;
	}
	
	public String toString()
	{
		return "" + value;
	}

	@Override
	public int compare(Comparable c) {
		return (value - ((FloatingPointLiteral) c).value) > 0 ? 1 :-1;
	}

	@Override
	public boolean equal(Equatable e) {
		return value == ((FloatingPointLiteral) e).value;
	}
}
