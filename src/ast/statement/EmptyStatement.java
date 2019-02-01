package ast.statement;

import ast.context.Context;

public class EmptyStatement extends Statement {

	@Override
	public void execute(Context c) {

		if (next != null)
			next.execute(c);
	}
	
	public String toString()
	{
		String a =  "noop;\n";
		
		if (next != null)
			a += next;
		return a;
	}

}
