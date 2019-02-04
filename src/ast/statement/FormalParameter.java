package ast.statement;

public class FormalParameter {
	public Identifier i;
	public FormalParameter next;
	
	public FormalParameter(Identifier i)
	{
		this.i = i;
	}
	
	public String toString()
	{
		String a = i.toString();
		
		if (next != null)
			a += ","+next;
		return a;
	}
}
