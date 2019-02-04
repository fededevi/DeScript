package ast.expression.literal;

import ast.context.Context;
import ast.expression.Expression;

public class StringLiteral extends Comparable {
	String data;
	
	public StringLiteral(String data)
	{
		this.data =data;
	}

	@Override
	public int compare(Comparable c) {
		StringLiteral s = (StringLiteral) c;
		return this.data.compareTo(s.data);
	}

	@Override
	public boolean equal(Equatable e) {
		StringLiteral s = (StringLiteral) e;
		return this.data.equals(s.data);
	}

	@Override
	public Expression evaluate(Context c) {
		return this;
	}

	  public String toString() 
	  { 
	    return  data; 
	  } 
}
