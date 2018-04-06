package ast.statement;

import ast.context.Context;

public class FunctionDeclaration extends Statement {
	public Identifier id;
	public FormalParameter parameters;
	public Statement statement;
	
	public FunctionDeclaration(Identifier id, FormalParameter p, Statement s)
	{
			this.parameters = p;
			this.statement = s;
	}

	@Override
	public void execute(Context c) {
		c.addFunction(this);
	


		if (next != null)
			next.execute(c);
	}

}
