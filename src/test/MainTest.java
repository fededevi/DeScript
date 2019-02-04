package test;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import ast.context.SystemContext;
import ast.statement.Statement;
import parser.jj.DeoclaParser;
import parser.jj.ParseException;

public class MainTest {
	public static void main(String[] args) throws Exception
	{		
		runFile("\\src\\test\\test.dol");
		//runFile("\\bin\\test\\program.dol");
	}
	
	public static void runFile(String path) throws FileNotFoundException, ParseException
	{
		String filePath = new File("").getAbsolutePath();
		//System.out.println(filePath);
		DeoclaParser deoclaParser;
		deoclaParser = new DeoclaParser(new FileReader(filePath+path));
		Statement stat = deoclaParser.Start();
		System.out.println(stat);
		stat.execute(new SystemContext());
	};
}
