package ast.statement;
import ast.context.Context;
import ast.expression.Expression;
import ast.expression.literal.Literal;

public class Declaration extends Statement{
	Identifier identifier;
	Expression value;
	
	public Declaration(Identifier i, Expression e)
	{
		this.identifier = i;
		this.value = e;
	}
	
	@Override
	public void execute(Context c) {

		Literal l = (Literal) value.evaluate(c);
		c.addNew(identifier, l);
		
		if (next != null)
			next.execute(c);
	}
	


	public String toString()
	{
		String a =  "var " +identifier +" := " + value + ";\n";
		
		if (next != null)
			a += next;
		return a;
	}
}
