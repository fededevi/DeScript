package ast.expression;

import ast.context.Context;

public class DString extends Literal{
	String value;
	
	public DString(String value)
	{
		this.value=value;
	}

	@Override
	public Expression evaluate(Context c) {
		return this;
	}
	


	public String toString()
	{
		return "" + value;
	}
}
