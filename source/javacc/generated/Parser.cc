/* Parser.cc */
#include "Parser.h"
#include "TokenMgrError.h"
#include "SimpleNode.h"
namespace AlpiScript {
  unsigned int jj_la1_0[] = {
0x4000,};
  unsigned int jj_la1_1[] = {
0x0,};

  /** Constructor with user supplied TokenManager. */



ASTStart        * Parser::parseProgram() {
    JJEnter<std::function<void()>> jjenter([this]() {trace_call  ("parseProgram"); });
    JJExit <std::function<void()>> jjexit ([this]() {trace_return("parseProgram"); });
    try {

      multiStatement();
      jj_consume_token(40);
return jjtn000;
    } catch(...) { }
assert(false);
}


void Parser::multiStatement() {
    JJEnter<std::function<void()>> jjenter([this]() {trace_call  ("multiStatement"); });
    JJExit <std::function<void()>> jjexit ([this]() {trace_return("multiStatement"); });
    try {

      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case LP:{
          ;
          break;
          }
        default:
          jj_la1[0] = jj_gen;
          goto end_label_1;
        }
        statementParse();
      }
      end_label_1: ;
    } catch(...) { }
}


Statement         * Parser::statementParse() {
    JJEnter<std::function<void()>> jjenter([this]() {trace_call  ("statementParse"); });
    JJExit <std::function<void()>> jjexit ([this]() {trace_return("statementParse"); });
    try {

      jj_consume_token(LP);
      jj_consume_token(NAME);
      jj_consume_token(RP);

    } catch(...) { }
assert(false);
}


  Parser::Parser(TokenManager *tokenManager){
    head = nullptr;
    ReInit(tokenManager);
}
Parser::~Parser()
{
  clear();
}

void Parser::ReInit(TokenManager* tokenManager){
    clear();
    errorHandler = new ErrorHandler();
    hasError = false;
    token_source = tokenManager;
    head = token = new Token();
    token->kind = 0;
    token->next = nullptr;
    jj_lookingAhead = false;
    jj_rescan = false;
    jj_done = false;
    jj_scanpos = jj_lastpos = nullptr;
    jj_gc = 0;
    jj_kind = -1;
    indent = 0;
    trace = true;
    jj_ntk = -1;
    jjtree.reset();
    jj_gen = 0;
    for (int i = 0; i < 1; i++) jj_la1[i] = -1;
  }


void Parser::clear(){
  //Since token manager was generate from outside,
  //parser should not take care of deleting
  //if (token_source) delete token_source;
  if (head) {
    Token *next, *t = head;
    while (t) {
      next = t->next;
      delete t;
      t = next;
    }
  }
  if (errorHandler) {
    delete errorHandler, errorHandler = nullptr;
  }
}


Token * Parser::jj_consume_token(int kind)  {
    Token *oldToken;
    if ((oldToken = token)->next != nullptr) token = token->next;
    else token = token->next = token_source->getNextToken();
    jj_ntk = -1;
    if (token->kind == kind) {
      jj_gen++;
      trace_token(token, "");
      return token;
    }
    token = oldToken;
    jj_kind = kind;
    JJString image = kind >= 0 ? tokenImage[kind] : tokenImage[0];
    errorHandler->handleUnexpectedToken(kind, image.substr(1, image.size() - 2), getToken(1), this);
    hasError = true;
    return token;
  }


/** Get the next Token. */

Token * Parser::getNextToken(){
    if (token->next != nullptr) token = token->next;
    else token = token->next = token_source->getNextToken();
    jj_ntk = -1;
    jj_gen++;
      trace_token(token, " (in getNextToken)");
    return token;
  }

/** Get the specific Token. */

Token * Parser::getToken(int index){
    Token *t = token;
    for (int i = 0; i < index; i++) {
      if (t->next != nullptr) t = t->next;
      else t = t->next = token_source->getNextToken();
    }
    return t;
  }


int Parser::jj_ntk_f(){
    if ((jj_nt=token->next) == nullptr)
      return (jj_ntk = (token->next=token_source->getNextToken())->kind);
    else
      return (jj_ntk = jj_nt->kind);
  }


 void  Parser::parseError()   {
      fprintf(stderr, "Parse error at: %d:%d, after token: %s encountered: %s\n", token->beginLine, token->beginColumn, addUnicodeEscapes(token->image).c_str(), addUnicodeEscapes(getToken(1)->image).c_str());
   }


  bool Parser::trace_enabled()  {
    return trace;
  }


  void Parser::enable_tracing(){
    trace = true;
}


  void Parser::disable_tracing(){
    trace = false;
}


  void Parser::trace_call(const char *s)  {
    if (trace_enabled()) {
      for (int i = 0; i < indent; i++) { printf(" "); }
      printf("Call:   %s\n", s);
    }
    indent = indent + 2;
  }


  void Parser::trace_return(const char *s)  {
    indent = indent - 2;
    if (trace_enabled()) {
      for (int i = 0; i < indent; i++) { printf(" "); }
      printf("Return: %s\n", s);
    }
  }


  void Parser::trace_token(Token *t, const char *where)  {
    if (trace_enabled()) {
      for (int i = 0; i < indent; i++) { printf(" "); }
      printf("Consumed token: <kind: %d(%s), \"%s\"", t->kind, addUnicodeEscapes(tokenImage[t->kind]).c_str(), addUnicodeEscapes(t->image).c_str());
      printf(" at line %d column %d> %s\n", t->beginLine, t->beginColumn, where);
    }
  }


  void Parser::trace_scan(Token *t1, int t2)  {
    if (trace_enabled()) {
      for (int i = 0; i < indent; i++) { printf(" "); }
      printf("Visited token: <Kind: %d(%s), \"%s\"", t1->kind, addUnicodeEscapes(tokenImage[t1->kind]).c_str(), addUnicodeEscapes(t1->image).c_str());
      printf(" at line %d column %d>; Expected token: %s\n", t1->beginLine, t1->beginColumn, addUnicodeEscapes(tokenImage[t2]).c_str());
    }
  }


}
