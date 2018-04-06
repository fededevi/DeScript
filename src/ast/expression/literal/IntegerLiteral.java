package ast.expression.literal;

import ast.context.Context;
import ast.expression.Expression;

public class IntegerLiteral extends Literal {
	
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
}
