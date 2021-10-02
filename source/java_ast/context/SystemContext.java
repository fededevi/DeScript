package ast.context;

import ast.expression.literal.Literal;
import ast.statement.FormalParameter;
import ast.statement.FunctionDeclaration;
import ast.statement.Identifier;
import ast.statement.Statement;

public class SystemContext extends Context {
	
	public SystemContext()
	{
		super();
		
		//ADD PRINTLN
		Identifier i = new Identifier("println");
		Identifier p =  new Identifier("literal");
		FormalParameter fp = new FormalParameter(p);
		Statement s = new Statement() {

			@Override
			public void execute(Context c) {
				Literal l = c.value(p);
				System.out.print(l+ "\n");
			}
				
		};
		
		this.addFunction(new FunctionDeclaration(i, fp, s));
		
	}
	
}
