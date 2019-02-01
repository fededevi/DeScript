package ast.statement;

import ast.context.Context;

public abstract class Statement  {
	public Statement next;
	
	public abstract void execute( Context c);
}
