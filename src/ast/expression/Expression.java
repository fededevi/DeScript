package ast.expression;

import ast.context.Context;
import ast.statement.ASTNode;

public abstract class Expression extends ASTNode {

	
	public abstract Expression evaluate(Context c);


}
