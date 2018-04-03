package ast.expression;

import ast.context.Context;

public abstract class Expression {
	Expression next;
	
	public abstract Expression evaluate(Context c);


}
