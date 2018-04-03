package ast.expression;

import ast.context.Context;
import ast.statement.Identifier;

public class Variable extends Expression {
	Identifier id;
	
	public Variable(Identifier id)
	{
		this.id =id;
	}
	
	@Override
	public Expression evaluate(Context c) {
		if (c.contains(id))
		{
			return c.value(id);
		} else
		{
			//error;
			return null;
		}
	}
	


	public String toString()
	{
		return ""+id;
	}

}
