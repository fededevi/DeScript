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
		c.setReturnValue(e.evaluate(c));

		//Do not call next, this is a return :)
	}

}
