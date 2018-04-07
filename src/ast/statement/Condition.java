package ast.statement;
import ast.context.Context;
import ast.expression.Expression;
import ast.expression.literal.BooleanLiteral;
import ast.expression.literal.IntegerLiteral;

public class Condition extends Statement {
	public Expression condition;
	public Statement thenStatement;
	public Statement elseStatement;

	public Condition(Expression condition, Statement thenStatement, Statement elseStatement)
	{
		this.condition = condition;
		this.thenStatement = thenStatement;
		this.elseStatement = elseStatement;
	}
	
	public void execute(Context c) {
		Expression e = condition.evaluate(c);
		
		BooleanLiteral i = (BooleanLiteral)e;
		
		Context localContext;
		if (i.value)
		{
			localContext = new Context(c);
			thenStatement.execute(localContext);
		}else
		{
			localContext = new Context(c);
			elseStatement.execute(localContext);
		}
			
		if (next != null)
			next.execute(c);
	}
	
	public String toString()
	{
		String a = "If" + "(" + condition + ")\n" + thenStatement + "else\n" + elseStatement;
		
		if (next != null)
			a += next;
		return a;
	}
}
