package ast.statement;

public class FormalParameter {
	public Identifier i;
	public FormalParameter next;
	
	public FormalParameter(Identifier i)
	{
		this.i = i;
	}
}
