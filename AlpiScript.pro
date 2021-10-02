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
    source/javacc/generated/grammar.jj
    source/javacc/buildParser.bat \

HEADERS += \
    source/ast/statement/astnode.h \
    source/ast/statement/statement.h \
    source/javacc/generated/ASTProgram.h \
    source/javacc/generated/ASTStatement.h \
    source/visitors/alpiscriptwriter.h \
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
    source/javacc/generated/TokenMgrError.h

SOURCES += \
        source/ast/statement/astnode.cpp \
        source/ast/statement/statement.cpp \
    source/javacc/generated/ASTProgram.cc \
    source/javacc/generated/ASTStatement.cc \
        source/main.cpp \
    source/visitors/alpiscriptwriter.cpp \
    source/javacc/generated/CharStream.cc \
    source/javacc/generated/JJTParserState.cc \
    source/javacc/generated/ParseException.cc \
    source/javacc/generated/Parser.cc \
    source/javacc/generated/ParserTokenManager.cc \
    source/javacc/generated/SimpleNode.cc \
    source/javacc/generated/Token.cc \
    source/javacc/generated/TokenMgrError.cc
