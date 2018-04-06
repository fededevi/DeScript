DeOcLa (DOL): a Java / javacc interpreted language

Main components:
A lexer and parser based on javacc fon in the package  parser.jj, the language grammar is defined in deocla.jj file
An abstract syntax tree written in Java
An interpreter: basically the execut and evaluate methods inside the AST nodes.

In order to build the parser you eed to preprocess the deocl.jj file with javacc and put the output files in the parser.jj package.
The just call: (see MainTest.java)
DeoclaParser deoclaParser = new DeoclaParser(new FileReader("\\path\\to\\your\\program.dol"));
Statement stat = deoclaParser.Start(); //Parse program and create the AST, returns the first statement of the program
stat.execute(new SystemContext()); //Run the program with a context containing a println() function to print stuff.
