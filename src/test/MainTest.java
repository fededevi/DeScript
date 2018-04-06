package test;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.StringReader;
import java.nio.file.Files;
import java.nio.file.Path;

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
import ast.statement.Statement;
import parser.jj.DeoclaParser;
import parser.jj.DeoclaParserTokenManager;
import parser.jj.ParseException;

public class MainTest {
	public static void main(String[] args) throws FileNotFoundException
	{
		/*
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
		
		dec1.execute(new Context());*/
		//String program= new String(Files.readAllBytes(new Path()));
		String filePath = new File("").getAbsolutePath();
		System.out.println(filePath);
		DeoclaParser deoclaParser = new DeoclaParser(new FileReader(filePath+"\\bin\\test\\program.dol"));
				
				/*Files.rea
				    "var a = 6;"
				  + "    b = 6;"
				  + "var c = 6;"
				  + "    d = 32;"));
		*/
		
		try {
			Statement stat = deoclaParser.Start();
			System.out.println(stat);
			stat.execute(new Context());
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
