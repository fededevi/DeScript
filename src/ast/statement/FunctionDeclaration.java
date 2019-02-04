package ast.statement;

import ast.context.Context;

public class FunctionDeclaration extends Statement {
	public Identifier id;
	public FormalParameter parameters;
	public Statement statement;
	
	public FunctionDeclaration(Identifier id, FormalParameter p, Statement s)
	{
			this.id = id;
			this.parameters = p;
			this.statement = s;

	}

	@Override
	public void execute(Context c) {
		c.addFunction(this);
	


		if (next != null)
			next.execute(c);
	}
	
	public String toString()
	{
		String a = "function " + id + "(" + parameters +")\n{\n" + statement + "\n}\n";
		
		if (next != null)
			a += next;
		return a;
	}

}
