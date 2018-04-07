package ast.statement;
import ast.context.Context;
import ast.expression.Expression;
import ast.expression.literal.BooleanLiteral;

public class Loop extends Statement {
	Expression condition;
	Statement statement;
	
	public Loop(Expression condition, Statement statement)
	{
		this.condition = condition;
		this.statement = statement;		
	}
	
	
	@Override
	public void execute(Context c) {
			
		while (((BooleanLiteral)condition.evaluate(c)).value() )
		{
			Context localContext = new Context(c);
			statement.execute(localContext);
		}
		

		if (next != null)
			next.execute(c);
	}
	
	public String toString()
	{
		String a = "while" + "(" + condition + ")\n{\n" + statement + "}";
		
		if (next != null)
			a += next;
		return a;
	}
}
