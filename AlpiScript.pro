QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    source/javacc/buildParser.bat \
    source/javacc/generated/grammar.jj \
    source/javacc/grammar.jjt
    source/javacc/buildParser.bat \

HEADERS += \
    source/ast/expression.h \
    source/ast/expressionevaluator.h \
    source/ast/expressionvisitor.h \
    source/ast/expressionwriter.h \
    source/javacc/generated/ASTAdd.h \
    source/javacc/generated/ASTDivision.h \
    source/javacc/generated/ASTExpression.h \
    source/javacc/generated/ASTFloat.h \
    source/javacc/generated/ASTIdentifier.h \
    source/javacc/generated/ASTInteger.h \
    source/javacc/generated/ASTModule.h \
    source/javacc/generated/ASTMult.h \
    source/javacc/generated/ASTSub.h \
    source/javacc/generated/CharStream.h \
    source/javacc/generated/ErrorHandler.h \
    source/javacc/generated/JJTParserState.h \
    source/javacc/generated/JavaCC.h \
    source/javacc/generated/Node.h \
    source/javacc/generated/ParseException.h \
    source/javacc/generated/Parser.h \
    source/javacc/generated/ParserConstants.h \
    source/javacc/generated/ParserTokenManager.h \
    source/javacc/generated/ParserTree.h \
    source/javacc/generated/ParserTreeConstants.h \
    source/javacc/generated/ParserVisitor.h \
    source/javacc/generated/SimpleNode.h \
    source/javacc/generated/Token.h \
    source/javacc/generated/TokenManager.h \
    source/javacc/generated/TokenMgrError.h \
    source/visitors/astconverter.h

SOURCES += \
    source/ast/expression.cpp \
    source/ast/expressionevaluator.cpp \
    source/ast/expressionvisitor.cpp \
    source/ast/expressionwriter.cpp \
    source/javacc/generated/ASTAdd.cc \
    source/javacc/generated/ASTDivision.cc \
    source/javacc/generated/ASTExpression.cc \
    source/javacc/generated/ASTFloat.cc \
    source/javacc/generated/ASTIdentifier.cc \
    source/javacc/generated/ASTInteger.cc \
    source/javacc/generated/ASTModule.cc \
    source/javacc/generated/ASTMult.cc \
    source/javacc/generated/ASTSub.cc \
    source/main.cpp \
    source/javacc/generated/CharStream.cc \
    source/javacc/generated/JJTParserState.cc \
    source/javacc/generated/ParseException.cc \
    source/javacc/generated/Parser.cc \
    source/javacc/generated/ParserTokenManager.cc \
    source/javacc/generated/SimpleNode.cc \
    source/javacc/generated/Token.cc \
    source/javacc/generated/TokenMgrError.cc \
    source/visitors/astconverter.cpp
    source/main.cpp \
