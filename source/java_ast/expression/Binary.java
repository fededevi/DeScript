package ast.expression;

public abstract class Binary extends Operator {
	protected Expression left;
	protected Expression right;
	
	public Binary(Expression l, Expression r)
	{
		this.left=l;
		this.right=r;
	}
}
