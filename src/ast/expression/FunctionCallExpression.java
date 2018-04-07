package ast.expression;

import ast.context.Context;
import ast.expression.literal.Literal;
import ast.statement.ActualParameter;
import ast.statement.FormalParameter;
import ast.statement.FunctionCall;
import ast.statement.FunctionDeclaration;
import ast.statement.Identifier;

public class FunctionCallExpression extends Expression implements FunctionCall {
	public  Identifier identifier;
	public  ActualParameter parameters;
	public  Expression returnValue;
	
	public FunctionCallExpression(Identifier i, ActualParameter p)
	{
		this.identifier = i;
		this.parameters = p;
	}

	@Override
	public Expression evaluate(Context c) {
		//Get function declaration from implementation from this context
		FunctionDeclaration fc = c.getFunction(identifier);
		
		if (fc == null)
		{
			try {
				throw new Exception ("Function Declaration not found: " + identifier);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		//Create new empty context for execution of the function statement
		Context functionContext = new Context(c);
		
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
		Context.callStack.push(this);
		fc.statement.execute(functionContext);
		Context.callStack.pop();
		
		return returnValue;
	}
	
	public String toString()
	{
		return identifier + "(" + parameters +")";
		
	}

	@Override
	public void setReturnValue(Expression l) {
		// TODO Auto-generated method stub
		returnValue = l;
	}
}
