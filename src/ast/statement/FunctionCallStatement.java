package ast.statement;

import ast.context.Context;
import ast.expression.Expression;
import ast.expression.FunctionCallExpression;
import ast.statement.ActualParameter;
import ast.statement.Identifier;

public class FunctionCallStatement extends Statement implements FunctionCall {
	private FunctionCallExpression f;
	
	public FunctionCallStatement(Identifier i, ActualParameter p)
	{
		f = new FunctionCallExpression(i, p);
	}

	public String toString()
	{
		return f.identifier + "(" + f.parameters +")\n";
		
	}

	@Override
	public void execute(Context c) {

		f.evaluate(c); //Ignore return value
		
		if (next != null)
			next.execute(c);
	}

	@Override
	public void setReturnValue(Expression l) {
			//WE do not care about return value for procedures
		
	}
}
