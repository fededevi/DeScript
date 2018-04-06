package ast.context;

import java.util.HashMap;

import ast.expression.Expression;
import ast.expression.Literal;
import ast.statement.FunctionDeclaration;
import ast.statement.Identifier;

public class Context
{
	HashMap<Identifier, Literal> data = new HashMap<>();
	HashMap<Identifier, FunctionDeclaration> functions = new HashMap<>();
	
	Context parent;
	private Expression returnValue = null;
	
	public Literal value(Identifier id)
	{
		if (parent == null)
			return data.get(id);
		
		if (data.containsKey(id))
			return data.get(id);
		
		return parent.value(id);
	}
	
	public void addNew(Identifier i, Literal l)
	{
		if (data.containsKey(i))
		{
			return; //error;
		}
		
		System.out.println("Declaring " + i + " as " + l);
		data.put(i, l);
	}
	
	public void assign(Identifier i, Literal l)
	{
		if (data.containsKey(i))
		{
			System.out.println("Assigning " + l + " to " + i);
			data.put(i, l);
			return;
		}
		
		if (parent != null)
		{
			parent.assign(i, l);
			return;
		}
		
		//error
		return;
	}
	
	public Context()
	{
		
	}
	public Context(Context parent)
	{
		this.parent = parent;
	}

	public void addFunction(FunctionDeclaration functionDeclaration) {
		if (functions.containsKey(functionDeclaration.id))
		{
			return; //error;
		}
		
		System.out.println("Declaring " + functionDeclaration.id + " as " + "function");
		functions.put(functionDeclaration.id, functionDeclaration);
		
	}

	public FunctionDeclaration getFunction(Identifier identifier) {
		if (parent == null)
			return functions.get(identifier);
		
		if (data.containsKey(identifier))
			return functions.get(identifier);
		
		return parent.getFunction(identifier);
	}

	public Expression returnValue() {
		return returnValue ;
	}

	public void setReturnValue(Expression evaluate) {
		returnValue = evaluate;
	}
}
