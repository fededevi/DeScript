package ast.expression.literal;

import ast.context.Context;
import ast.expression.Expression;

public class BooleanLiteral  extends Literal {
		
		public boolean value;
		
		public BooleanLiteral( boolean value)
		{
			this.value = value;
		}

		@Override
		public Expression evaluate(Context c) {
			return this;
		}
		
		public boolean value()
		{
			return value;
		}
		
		public String toString()
		{
			return "" + value;
		}
	}


