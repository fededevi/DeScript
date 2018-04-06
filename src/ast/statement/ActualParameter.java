package ast.statement;

import ast.expression.Expression;

public class ActualParameter {
	public Expression e;
	public ActualParameter next;
	
	public ActualParameter(Expression e)
	{
		this.e = e;
	}
	
	public String toString()
	{
		String a = e.toString();
		
		if (next != null)
			a += ","+next;
		return a;
	}
}
