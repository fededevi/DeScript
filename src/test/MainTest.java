package test;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import ast.context.Context;
import ast.context.SystemContext;
import ast.statement.Statement;
import parser.jj.DeoclaParser;
import parser.jj.ParseException;

public class MainTest {
	public static void main(String[] args) throws FileNotFoundException
	{
		String filePath = new File("").getAbsolutePath();
		System.out.println(filePath);
		DeoclaParser deoclaParser = new DeoclaParser(new FileReader(filePath+"\\bin\\test\\program.dol"));
		
		try {
			Statement stat = deoclaParser.Start();
			System.out.println(stat);
			stat.execute(new SystemContext());
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}
}
