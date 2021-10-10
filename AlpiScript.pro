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
    source/ast/basetypes.h \
    source/ast/context.h \
    source/ast/datatype.h \
    source/ast/expression.h \
    source/ast/expressionevaluator.h \
    source/ast/expressionvisitor.h \
    source/ast/expressionwriter.h \
    source/ast/visitormacros.h \
    source/javacc/generated/ASTAdd.h \
    source/javacc/generated/ASTAnd.h \
    source/javacc/generated/ASTBoolean.h \
    source/javacc/generated/ASTDivision.h \
    source/javacc/generated/ASTEqual.h \
    source/javacc/generated/ASTFloat.h \
    source/javacc/generated/ASTGreaterEqual.h \
    source/javacc/generated/ASTGreaterThan.h \
    source/javacc/generated/ASTIdentifier.h \
    source/javacc/generated/ASTInteger.h \
    source/javacc/generated/ASTLessEqual.h \
    source/javacc/generated/ASTLessThan.h \
    source/javacc/generated/ASTModule.h \
    source/javacc/generated/ASTMult.h \
    source/javacc/generated/ASTNegative.h \
    source/javacc/generated/ASTNot.h \
    source/javacc/generated/ASTNotEqual.h \
    source/javacc/generated/ASTOr.h \
    source/javacc/generated/ASTStart.h \
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
    source/ast/basetypes.cpp \
    source/ast/context.cpp \
    source/ast/datatype.cpp \
    source/ast/expression.cpp \
    source/ast/expressionevaluator.cpp \
    source/ast/expressionwriter.cpp \
    source/javacc/generated/ASTAdd.cc \
    source/javacc/generated/ASTAnd.cc \
    source/javacc/generated/ASTBoolean.cc \
    source/javacc/generated/ASTDivision.cc \
    source/javacc/generated/ASTEqual.cc \
    source/javacc/generated/ASTFloat.cc \
    source/javacc/generated/ASTGreaterEqual.cc \
    source/javacc/generated/ASTGreaterThan.cc \
    source/javacc/generated/ASTIdentifier.cc \
    source/javacc/generated/ASTInteger.cc \
    source/javacc/generated/ASTLessEqual.cc \
    source/javacc/generated/ASTLessThan.cc \
    source/javacc/generated/ASTModule.cc \
    source/javacc/generated/ASTMult.cc \
    source/javacc/generated/ASTNegative.cc \
    source/javacc/generated/ASTNot.cc \
    source/javacc/generated/ASTNotEqual.cc \
    source/javacc/generated/ASTOr.cc \
    source/javacc/generated/ASTStart.cc \
    source/javacc/generated/ASTSub.cc \
    source/javacc/generated/CharStream.cc \
    source/javacc/generated/JJTParserState.cc \
    source/javacc/generated/ParseException.cc \
    source/javacc/generated/Parser.cc \
    source/javacc/generated/ParserTokenManager.cc \
    source/javacc/generated/SimpleNode.cc \
    source/javacc/generated/Token.cc \
    source/javacc/generated/TokenMgrError.cc \
    source/main.cpp \
    source/visitors/astconverter.cpp
