powershell -Command "Remove-Item generated -Recurse -Force -Confirm:$false"
java -cp javacc.jar jjtree  grammar.jjt
java -cp javacc.jar javacc generated/grammar.jj 