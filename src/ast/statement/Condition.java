package ast.statement;
import ast.context.Context;
import ast.expression.DInteger;
import ast.expression.Expression;

public class Condition extends Statement {
	public Expression condition;
	public Statement thenStatement;
	public Statement elseStatement;
	
	@Override
	public void execute(Context c) {
		Expression e = condition.evaluate(c);
		
		if (! (e instanceof DInteger))
			return; //error
		
		DInteger i = (DInteger)e;
		
		Context localContext = new Context(c);
		if (i.value > 0)
		{
			thenStatement.execute(localContext);
		}else
		{
			elseStatement.execute(localContext);
		}
			
		if (next != null)
			next.execute(c);
	}
	
	public String toString()
	{
		String a = "If" + "(" + condition + ")\n" + thenStatement + "\nelse\n" + elseStatement;
		
		if (next != null)
			a += next;
		return a;
	}
}
