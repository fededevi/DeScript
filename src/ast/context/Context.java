package ast.context;

import java.util.HashMap;

import ast.expression.Literal;
import ast.statement.Identifier;

public class Context
{
	HashMap<Identifier, Literal> data = new HashMap<>();
	Context parent;
	
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
			return; //error;

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

	public boolean contains(Identifier id) {
		if (parent == null)
			return data.containsKey(id);
		
		if (data.containsKey(id))
			return true;

		return parent.contains(id);		
	}
}
