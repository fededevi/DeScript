package ast.expression.literal;

import ast.context.Context;
import ast.expression.Expression;

public class BooleanLiteral  extends Equatable {
		
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

		@Override
		public boolean equal(Equatable e) {
			
			return value == ((BooleanLiteral) e).value;
		}
	}


