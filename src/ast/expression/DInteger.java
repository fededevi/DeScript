package ast.expression;

import ast.context.Context;

public class DInteger extends Literal {
	
	public int value;
	
	public DInteger( int value)
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
