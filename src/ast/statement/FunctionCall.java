package ast.statement;

import ast.context.Context;
import ast.expression.Expression;
import ast.expression.literal.Literal;

public class FunctionCall extends Expression {
	public  Identifier identifier;
	public  ActualParameter parameters;
	
	public FunctionCall(Identifier i, ActualParameter p)
	{
		this.identifier = i;
		this.parameters = p;
	}

	@Override
	public Expression evaluate(Context c) {
		//Get function declaration from implementation from this context
		FunctionDeclaration fc = c.getFunction(identifier);
		
		//Create new empty context for execution of the function statement
		Context functionContext = new Context();
		
		//Insert actual parameters in context
		FormalParameter fp = fc.parameters;
		ActualParameter ap = parameters;
		
		//Copy all parameters (will fail if wrong number of parameters (only if less actually))
		while (fp != null)
		{
			functionContext.addNew(fp.i, (Literal) ap.e.evaluate(c));
			fp = fp.next;
			ap = ap.next;
		}
		
		//Finally execute function with the proper context
		fc.statement.execute(functionContext);
		
		return functionContext.returnValue();
	}
	
	public String toString()
	{
		return identifier + "(" + parameters.e +")\n";
		
	}
}
