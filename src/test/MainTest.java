package test;

import java.io.StringReader;

import ast.context.Context;
import ast.expression.DInteger;
import ast.expression.Variable;
import ast.expression.math.Add;
import ast.expression.math.Mul;
import ast.expression.math.Sqrt;
import ast.expression.math.Sub;
import ast.statement.Assignment;
import ast.statement.Condition;
import ast.statement.Declaration;
import ast.statement.EmptyStatement;
import ast.statement.Identifier;
import ast.statement.Loop;
import parser.jj.DeoclaParser;
import parser.jj.DeoclaParserTokenManager;
import parser.jj.ParseException;

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
		Assignment assignB =new Assignment(b, new Add(new Variable(b),new Mul(new Variable(a), new Variable(a))));
		loopStatement.next = assignB;
		Assignment increaseB = new Assignment(b, new Add(new Variable (b), new DInteger(1)));
		Condition c = new Condition(new Sub(new Variable(b), new DInteger(150)),increaseB,new EmptyStatement());
		assignB.next = c;
		dec2.next = new Loop(new Variable(a), loopStatement);

		
		System.out.println(dec1);
		
		dec1.execute(new Context());
		
		DeoclaParser deoclaParser = new DeoclaParser(new StringReader("var a = 6.5;\n\u001a"));
		try {
			deoclaParser.Start();
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
