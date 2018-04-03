package test;

import ast.context.Context;
import ast.expression.DInteger;
import ast.expression.Variable;
import ast.expression.math.Add;
import ast.expression.math.Mul;
import ast.expression.math.Sqrt;
import ast.expression.math.Sub;
import ast.statement.Assignment;
import ast.statement.Declaration;
import ast.statement.Identifier;
import ast.statement.Loop;

public class MainTest {
	public static void main(String[] args)
	{
		System.out.println("Start");

		Identifier a = new Identifier("a");
		Identifier b = new Identifier("b");
		
		Declaration dec1 = new Declaration(b, new Mul(new DInteger(5), new DInteger(5)));

		Declaration dec2 = new Declaration(a, new Add(new DInteger(3), new Sqrt(new Variable(b))));
		
		dec1.next = dec2;
		
		Assignment loopStatement = new Assignment(a, new Sub(new Variable(a), new DInteger(1)));
		loopStatement.next = new Assignment(b, new Add(new Variable(b),new Mul(new Variable(a), new Variable(a))));
		
		dec2.next = new Loop(new Variable(a), loopStatement);

		
		System.out.println(dec1);
		
		dec1.execute(new Context());
	}
}
