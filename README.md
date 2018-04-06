
# DeOcLa (DOL) 
#### a Java / javacc -very basic- interpreted language

#### Main components:
A lexer and parser based on **javacc**, the language grammar is defined in file: **deocla.jj**
An **abstract syntax tree** written in Java
An **interpreter**: basically the **execute** and **evaluate** methods inside the **AST** nodes.


#### Howto:
In order to build the parser you need to preprocess the deocl.jj file with javacc and put the output files in the parser.jj package.
Download javacc from javacc.org, then just call:

```batch
java -cp javacc.jar javacc deocla.jj
```
This will generate a bunch of .java files including the parser class.

Examples:
```java
DeoclaParser p= new DeoclaParser(new FileReader("\\path\\to\\your\\program.dol"));
//Parse program and create the AST, returns the first statement of the program.
Statement stat = p.Start();
//Run the program with a context containing a println() function to print stuff. 
stat.execute(new SystemContext());
```
If you want to just parse expressions then:

```java
DeoclaParser p = new DeoclaParser(new StringReader("5 / 2"));
Expression exp = p.expressionParse();
exp = exp.evaluate(new Context());
System.out.println(exp);
```
