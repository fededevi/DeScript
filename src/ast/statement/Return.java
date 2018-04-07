package ast.statement;

import ast.context.Context;
import ast.expression.Expression;

public class Return extends Statement {
	private Expression e;
	
	public Return(Expression e)
	{
		this.e = e;
	}
	
	@Override
	public void execute(Context c) {
		FunctionCall f = Context.callStack.peek();
		f.setReturnValue(e.evaluate(c));
		
		return;
		//Do not call next, this is a return :)
	}
	
	public String toString()
	{
		String a = "return " + e;
		
		if (next != null)
			a += next;
		return a;
	}
	
}
