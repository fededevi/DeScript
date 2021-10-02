/* AlpiScript.cc */
#include "AlpiScript.h"
#include "TokenMgrError.h"

  /** Constructor with user supplied TokenManager. */




Statement AlpiScript::Start() {Statement s = new EmptyStatement();
    if (!hasError) {
    if (!hasError) {
    s = multiStatement();
    }
    }
    if (!hasError) {
    jj_consume_token(0);
    }
return s;
assert(false);
}


Statement AlpiScript::multiStatement() {Statement initial = new EmptyStatement();
        Statement last = initial;
        Statement next = null;
    if (!hasError) {
    while (!hasError) {
      if (jj_2_1(2)) {
        ;
      } else {
        goto end_label_1;
      }
      if (!hasError) {
      next = statementParse();
      }
      if (!hasError) {
last.next = next;
                last = next;
      }
    }
    end_label_1: ;
    }
return initial;
assert(false);
}


Statement AlpiScript::statementParse() {Statement s = null;
    if (!hasError) {
    if (jj_2_2(2)) {
      if (!hasError) {
      s = declarationParse();
      }
    } else if (jj_2_3(2)) {
      if (!hasError) {
      s = assignmenParse();
      }
    } else if (jj_2_4(2)) {
      if (!hasError) {
      s = conditionParse();
      }
    } else if (jj_2_5(2)) {
      if (!hasError) {
      s = loopParse();
      }
    } else if (jj_2_6(2)) {
      if (!hasError) {
      s = functionDeclarationParse();
      }
    } else if (jj_2_7(2)) {
      if (!hasError) {
      s = returnParse();
      }
    } else if (jj_2_8(2)) {
      if (!hasError) {
      s = functionCallStatementParse();
      }
    } else {
      jj_consume_token(-1);
      errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
    }
    }
return s;
assert(false);
}


FunctionCallStatement AlpiScript::functionCallStatementParse() {ActualParameter ap = null;
        Identifier id;
    if (!hasError) {
    if (!hasError) {
    id = identifierParse();
    }
    if (!hasError) {
    jj_consume_token(LP);
    }
    if (!hasError) {
    ap = actualParameterParseMulti();
    }
    if (!hasError) {
    jj_consume_token(RP);
    }
    if (!hasError) {
    jj_consume_token(40);
    }
    }
return new FunctionCallStatement(id,ap);
assert(false);
}


Return AlpiScript::returnParse() {Expression e;
  Return r;
    if (!hasError) {
    jj_consume_token(RETURN);
    }
    if (!hasError) {
    e = expressionParse();
    }
    if (!hasError) {
    jj_consume_token(40);
    }
return new Return(e);
assert(false);
}


FunctionDeclaration AlpiScript::functionDeclarationParse() {Identifier i;
  FormalParameter fp;
  Statement s;
    if (!hasError) {
    jj_consume_token(FUNCTION);
    }
    if (!hasError) {
    i = identifierParse();
    }
    if (!hasError) {
    jj_consume_token(LP);
    }
    if (!hasError) {
    fp = multiFormalParameter();
    }
    if (!hasError) {
    jj_consume_token(RP);
    }
    if (!hasError) {
    jj_consume_token(LGP);
    }
    if (!hasError) {
    s = multiStatement();
    }
    if (!hasError) {
    jj_consume_token(RGP);
    }
return new FunctionDeclaration(i, fp, s);
assert(false);
}


FormalParameter AlpiScript::multiFormalParameter() {FormalParameter initial = null;
  FormalParameter last = null;
  FormalParameter next = null;
    if (!hasError) {
    if (jj_2_10(2)) {
      if (!hasError) {
      last = formalParameterParse();
      }
      if (!hasError) {
      while (!hasError) {
        if (jj_2_9(2)) {
          ;
        } else {
          goto end_label_2;
        }
        if (!hasError) {
        jj_consume_token(41);
        }
        if (!hasError) {
        next = formalParameterParse();
        }
      }
      end_label_2: ;
      }
      if (!hasError) {
if (initial == null)
                                        initial = last;
                                last.next = next;
                                last = next;
      }
    } else {
      ;
    }
    }
return initial;
assert(false);
}


FormalParameter AlpiScript::formalParameterParse() {Identifier i= null;
    if (!hasError) {
    i = identifierParse();
    }
return new FormalParameter( i);
assert(false);
}


Loop AlpiScript::loopParse() {Expression condition = null;
  Statement statement = new EmptyStatement();
    if (!hasError) {
    if (!hasError) {
    jj_consume_token(WHILE);
    }
    if (!hasError) {
    jj_consume_token(LP);
    }
    if (!hasError) {
    condition = expressionParse();
    }
    if (!hasError) {
    jj_consume_token(RP);
    }
    if (!hasError) {
    jj_consume_token(LGP);
    }
    if (!hasError) {
    statement = multiStatement();
    }
    if (!hasError) {
    jj_consume_token(RGP);
    }
    }
return new Loop(condition,statement);
assert(false);
}


Condition AlpiScript::conditionParse() {Expression condition = null;
  Statement thenStatement = new EmptyStatement();
  Statement elseStatement = new EmptyStatement();
    if (!hasError) {
    if (!hasError) {
    jj_consume_token(IF);
    }
    if (!hasError) {
    jj_consume_token(LP);
    }
    if (!hasError) {
    condition = expressionParse();
    }
    if (!hasError) {
    jj_consume_token(RP);
    }
    if (!hasError) {
    jj_consume_token(LGP);
    }
    if (!hasError) {
    thenStatement = multiStatement();
    }
    if (!hasError) {
    jj_consume_token(RGP);
    }
    if (!hasError) {
    if (jj_2_11(2)) {
      if (!hasError) {
      jj_consume_token(ELSE);
      }
      if (!hasError) {
      jj_consume_token(LGP);
      }
      if (!hasError) {
      elseStatement = multiStatement();
      }
      if (!hasError) {
      jj_consume_token(RGP);
      }
    } else {
      ;
    }
    }
    }
return new Condition(condition,thenStatement,elseStatement);
assert(false);
}


Assignment AlpiScript::assignmenParse() {Identifier i;
  Expression e;
    if (!hasError) {
    i = identifierParse();
    }
    if (!hasError) {
    jj_consume_token(42);
    }
    if (!hasError) {
    e = expressionParse();
    }
    if (!hasError) {
    jj_consume_token(40);
    }
return new Assignment(i,e);
assert(false);
}


Declaration AlpiScript::declarationParse() {Identifier i;
  Expression e;
    if (!hasError) {
    jj_consume_token(VAR);
    }
    if (!hasError) {
    i = identifierParse();
    }
    if (!hasError) {
    jj_consume_token(42);
    }
    if (!hasError) {
    e = expressionParse();
    }
    if (!hasError) {
    jj_consume_token(40);
    }
return new Declaration(i,e);
assert(false);
}


Identifier AlpiScript::identifierParse() {Token t;
    if (!hasError) {
    t = jj_consume_token(NAME);
    }
return new Identifier(t.image);
assert(false);
}


Expression AlpiScript::expressionParse() {Expression e;
    if (!hasError) {
    if (!hasError) {
    e = additiveExpressionParse();
    }
    }
return e;
assert(false);
}


Expression AlpiScript::additiveExpressionParse() {Expression left;
        Expression right;
    if (!hasError) {
    left = multiplicativeExpressionParse();
    }
    if (!hasError) {
    while (!hasError) {
      if (jj_2_12(2)) {
        ;
      } else {
        goto end_label_3;
      }
      if (jj_2_13(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(ADD);
        }
        if (!hasError) {
        right = multiplicativeExpressionParse();
        }
        }
        if (!hasError) {
left = new Add(left,right);
        }
      } else if (jj_2_14(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(SUB);
        }
        if (!hasError) {
        right = multiplicativeExpressionParse();
        }
        }
        if (!hasError) {
left = new Sub(left,right);
        }
      } else {
        jj_consume_token(-1);
        errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
      }
    }
    end_label_3: ;
    }
return left;
assert(false);
}


Expression AlpiScript::multiplicativeExpressionParse() {Expression left;
        Expression right;
    if (!hasError) {
    left = comparativeExpressionParseOr();
    }
    if (!hasError) {
    while (!hasError) {
      if (jj_2_15(2)) {
        ;
      } else {
        goto end_label_4;
      }
      if (jj_2_16(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(MUL);
        }
        if (!hasError) {
        right = comparativeExpressionParseOr();
        }
        }
        if (!hasError) {
left = new Mul(left,right);
        }
      } else if (jj_2_17(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(DIV);
        }
        if (!hasError) {
        right = comparativeExpressionParseOr();
        }
        }
        if (!hasError) {
left = new Div(left,right);
        }
      } else if (jj_2_18(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(MOD);
        }
        if (!hasError) {
        right = comparativeExpressionParseOr();
        }
        }
        if (!hasError) {
left = new Mod(left,right);
        }
      } else {
        jj_consume_token(-1);
        errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
      }
    }
    end_label_4: ;
    }
return left;
assert(false);
}


Expression AlpiScript::comparativeExpressionParseOr() {Expression left;
        Expression right;
    if (!hasError) {
    left = comparativeExpressionParseAnd();
    }
    if (!hasError) {
    while (!hasError) {
      if (jj_2_19(2)) {
        ;
      } else {
        goto end_label_5;
      }
      if (!hasError) {
      if (!hasError) {
      jj_consume_token(OR);
      }
      if (!hasError) {
      right = comparativeExpressionParseAnd();
      }
      }
      if (!hasError) {
left = new Or(left,right);
      }
    }
    end_label_5: ;
    }
return left;
assert(false);
}


Expression AlpiScript::comparativeExpressionParseAnd() {Expression left;
        Expression right;
    if (!hasError) {
    left = comparativeExpressionParseComparisons();
    }
    if (!hasError) {
    while (!hasError) {
      if (jj_2_20(2)) {
        ;
      } else {
        goto end_label_6;
      }
      if (!hasError) {
      if (!hasError) {
      jj_consume_token(AND);
      }
      if (!hasError) {
      right = comparativeExpressionParseComparisons();
      }
      }
      if (!hasError) {
left = new And(left,right);
      }
    }
    end_label_6: ;
    }
return left;
assert(false);
}


Expression AlpiScript::comparativeExpressionParseComparisons() {Expression left;
        Expression right;
    if (!hasError) {
    left = comparativeExpressionParseNot();
    }
    if (!hasError) {
    while (!hasError) {
      if (jj_2_21(2)) {
        ;
      } else {
        goto end_label_7;
      }
      if (jj_2_22(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(LT);
        }
        if (!hasError) {
        right = comparativeExpressionParseNot();
        }
        }
        if (!hasError) {
left = new LessThan(left,right);
        }
      } else if (jj_2_23(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(LE);
        }
        if (!hasError) {
        right = comparativeExpressionParseNot();
        }
        }
        if (!hasError) {
left = new LessEqual(left,right);
        }
      } else if (jj_2_24(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(GE);
        }
        if (!hasError) {
        right = comparativeExpressionParseNot();
        }
        }
        if (!hasError) {
left = new GreaterEqual(left,right);
        }
      } else if (jj_2_25(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(GT);
        }
        if (!hasError) {
        right = comparativeExpressionParseNot();
        }
        }
        if (!hasError) {
left = new GreaterThan(left,right);
        }
      } else if (jj_2_26(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(EQ);
        }
        if (!hasError) {
        right = comparativeExpressionParseNot();
        }
        }
        if (!hasError) {
left = new Equal(left,right);
        }
      } else if (jj_2_27(2)) {
        if (!hasError) {
        if (!hasError) {
        jj_consume_token(NE);
        }
        if (!hasError) {
        right = comparativeExpressionParseNot();
        }
        }
        if (!hasError) {
left = new NotEqual(left,right);
        }
      } else {
        jj_consume_token(-1);
        errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
      }
    }
    end_label_7: ;
    }
return left;
assert(false);
}


Expression AlpiScript::comparativeExpressionParseNot() {Expression left = null;
    if (!hasError) {
    if (jj_2_28(2)) {
      if (!hasError) {
      jj_consume_token(NOT);
      }
      if (!hasError) {
      left = unaryExpressionParse();
      }
      if (!hasError) {
left = new Not(left);
      }
    } else if (jj_2_29(2)) {
      if (!hasError) {
      left = unaryExpressionParse();
      }
    } else {
      jj_consume_token(-1);
      errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
    }
    }
return left;
assert(false);
}


Expression AlpiScript::unaryExpressionParse() {Expression e;
    if (!hasError) {
    if (jj_2_30(2)) {
      if (!hasError) {
      e = literalParse();
      }
    } else if (jj_2_31(2)) {
      if (!hasError) {
      e = functionCallExpressionParse();
      }
    } else if (jj_2_32(2)) {
      if (!hasError) {
      e = variableParse();
      }
    } else if (jj_2_33(2)) {
      if (!hasError) {
      jj_consume_token(LP);
      }
      if (!hasError) {
      e = expressionParse();
      }
      if (!hasError) {
      jj_consume_token(RP);
      }
    } else {
      jj_consume_token(-1);
      errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
    }
    }
return e;
assert(false);
}


FunctionCallExpression AlpiScript::functionCallExpressionParse() {ActualParameter ap = null;
        Identifier id;
    if (!hasError) {
    if (!hasError) {
    id = identifierParse();
    }
    if (!hasError) {
    jj_consume_token(LP);
    }
    if (!hasError) {
    ap = actualParameterParseMulti();
    }
    if (!hasError) {
    jj_consume_token(RP);
    }
    }
return new FunctionCallExpression(id,ap);
assert(false);
}


ActualParameter AlpiScript::actualParameterParseMulti() {ActualParameter initial = null;
        ActualParameter last = null;
        ActualParameter next = null;
    if (!hasError) {
    if (!hasError) {
    if (jj_2_35(2)) {
      if (!hasError) {
      last = actualParameterParse();
      }
      if (!hasError) {
      while (!hasError) {
        if (jj_2_34(2)) {
          ;
        } else {
          goto end_label_8;
        }
        if (!hasError) {
        jj_consume_token(41);
        }
        if (!hasError) {
        next = actualParameterParse();
        }
      }
      end_label_8: ;
      }
      if (!hasError) {
if (initial == null)
                                        initial = last;
                                last.next = next;
                                last = next;
      }
    } else {
      ;
    }
    }
    }
return initial;
assert(false);
}


ActualParameter AlpiScript::actualParameterParse() {Expression e;
    if (!hasError) {
    if (!hasError) {
    e = expressionParse();
    }
    }
return new ActualParameter(e);
assert(false);
}


Expression AlpiScript::variableParse() {Identifier id;
    if (!hasError) {
    if (!hasError) {
    id = identifierParse();
    }
    }
return new Variable(id);
assert(false);
}


Literal AlpiScript::literalParse() {Literal l;
    if (!hasError) {
    if (jj_2_36(2)) {
      if (!hasError) {
      l = floatingPointLiteralParse();
      }
    } else if (jj_2_37(2)) {
      if (!hasError) {
      l = booleanLiteralParse();
      }
    } else if (jj_2_38(2)) {
      if (!hasError) {
      l = stringLiteralParse();
      }
    } else if (jj_2_39(2)) {
      if (!hasError) {
      l = integerLiteralParse();
      }
    } else {
      jj_consume_token(-1);
      errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
    }
    }
return l;
assert(false);
}


IntegerLiteral AlpiScript::integerLiteralParse() {Token t;
    if (!hasError) {
    t = jj_consume_token(INTEGER);
    }
return new IntegerLiteral(Integer.parseInt(t.image));
assert(false);
}


BooleanLiteral AlpiScript::booleanLiteralParse() {Token t;
    if (jj_2_40(2)) {
      if (!hasError) {
      t = jj_consume_token(TRUE);
      }
      if (!hasError) {
return new BooleanLiteral(true);
      }
    } else if (jj_2_41(2)) {
      if (!hasError) {
      t = jj_consume_token(FALSE);
      }
      if (!hasError) {
return new BooleanLiteral(false);
      }
    } else {
      jj_consume_token(-1);
      errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
    }
assert(false);
}


StringLiteral AlpiScript::stringLiteralParse() {Token t;
    if (!hasError) {
    jj_consume_token(43);
    }
    if (!hasError) {
    t = jj_consume_token(NAME);
    }
    if (!hasError) {
    jj_consume_token(43);
    }
return new StringLiteral(t.image);
assert(false);
}


FloatingPointLiteral AlpiScript::floatingPointLiteralParse() {Token t;
    if (!hasError) {
    t = jj_consume_token(FLOAT);
    }
return new FloatingPointLiteral( Double.parseDouble(t.image));
assert(false);
}


  AlpiScript::AlpiScript(TokenManager *tokenManager){
    head = nullptr;
    ReInit(tokenManager);
}
AlpiScript::~AlpiScript()
{
  clear();
}

void AlpiScript::ReInit(TokenManager* tokenManager){
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
    trace = false;
    jj_ntk = -1;
    jj_gen = 0;
  }


void AlpiScript::clear(){
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


Token * AlpiScript::jj_consume_token(int kind)  {
    Token *oldToken;
    if ((oldToken = token)->next != nullptr) token = token->next;
    else token = token->next = token_source->getNextToken();
    jj_ntk = -1;
    if (token->kind == kind) {
      jj_gen++;
      if (++jj_gc > 100) {
        jj_gc = 0;
        for (int i = 0; i < 41; i++) {
          JJCalls *c = &jj_2_rtns[i];
          while (c != nullptr) {
            if (c->gen < jj_gen) c->first = nullptr;
            c = c->next;
          }
        }
      }
      return token;
    }
    token = oldToken;
    jj_kind = kind;
    JJString image = kind >= 0 ? tokenImage[kind] : tokenImage[0];
    errorHandler->handleUnexpectedToken(kind, image.substr(1, image.size() - 2), getToken(1), this);
    hasError = true;
    return token;
  }


bool  AlpiScript::jj_scan_token(int kind){
    if (jj_scanpos == jj_lastpos) {
      jj_la--;
      if (jj_scanpos->next == nullptr) {
        jj_lastpos = jj_scanpos = jj_scanpos->next = token_source->getNextToken();
      } else {
        jj_lastpos = jj_scanpos = jj_scanpos->next;
      }
    } else {
      jj_scanpos = jj_scanpos->next;
    }
    if (jj_rescan) {
      int i = 0; Token *tok = token;
      while (tok != nullptr && tok != jj_scanpos) { i++; tok = tok->next; }
      if (tok != nullptr) jj_add_error_token(kind, i);
    }
    if (jj_scanpos->kind != kind) return true;
    if (jj_la == 0 && jj_scanpos == jj_lastpos) { return jj_done = true; }
    return false;
  }


/** Get the next Token. */

Token * AlpiScript::getNextToken(){
    if (token->next != nullptr) token = token->next;
    else token = token->next = token_source->getNextToken();
    jj_ntk = -1;
    jj_gen++;
    return token;
  }

/** Get the specific Token. */

Token * AlpiScript::getToken(int index){
    Token *t = token;
    for (int i = 0; i < index; i++) {
      if (t->next != nullptr) t = t->next;
      else t = t->next = token_source->getNextToken();
    }
    return t;
  }


int AlpiScript::jj_ntk_f(){
    if ((jj_nt=token->next) == nullptr)
      return (jj_ntk = (token->next=token_source->getNextToken())->kind);
    else
      return (jj_ntk = jj_nt->kind);
  }


  void AlpiScript::jj_add_error_token(int kind, int pos)  {
  }


 void  AlpiScript::parseError()   {
      fprintf(stderr, "Parse error at: %d:%d, after token: %s encountered: %s\n", token->beginLine, token->beginColumn, addUnicodeEscapes(token->image).c_str(), addUnicodeEscapes(getToken(1)->image).c_str());
   }


  bool AlpiScript::trace_enabled()  {
    return trace;
  }


  void AlpiScript::enable_tracing()  {
  }

  void AlpiScript::disable_tracing()  {
  }


  void AlpiScript::jj_rescan_token(){
    jj_rescan = true;
    for (int i = 0; i < 41; i++) {
      JJCalls *p = &jj_2_rtns[i];
      do {
        if (p->gen > jj_gen) {
          jj_la = p->arg; jj_lastpos = jj_scanpos = p->first;
          switch (i) {
            case 0: jj_3_1(); break;
            case 1: jj_3_2(); break;
            case 2: jj_3_3(); break;
            case 3: jj_3_4(); break;
            case 4: jj_3_5(); break;
            case 5: jj_3_6(); break;
            case 6: jj_3_7(); break;
            case 7: jj_3_8(); break;
            case 8: jj_3_9(); break;
            case 9: jj_3_10(); break;
            case 10: jj_3_11(); break;
            case 11: jj_3_12(); break;
            case 12: jj_3_13(); break;
            case 13: jj_3_14(); break;
            case 14: jj_3_15(); break;
            case 15: jj_3_16(); break;
            case 16: jj_3_17(); break;
            case 17: jj_3_18(); break;
            case 18: jj_3_19(); break;
            case 19: jj_3_20(); break;
            case 20: jj_3_21(); break;
            case 21: jj_3_22(); break;
            case 22: jj_3_23(); break;
            case 23: jj_3_24(); break;
            case 24: jj_3_25(); break;
            case 25: jj_3_26(); break;
            case 26: jj_3_27(); break;
            case 27: jj_3_28(); break;
            case 28: jj_3_29(); break;
            case 29: jj_3_30(); break;
            case 30: jj_3_31(); break;
            case 31: jj_3_32(); break;
            case 32: jj_3_33(); break;
            case 33: jj_3_34(); break;
            case 34: jj_3_35(); break;
            case 35: jj_3_36(); break;
            case 36: jj_3_37(); break;
            case 37: jj_3_38(); break;
            case 38: jj_3_39(); break;
            case 39: jj_3_40(); break;
            case 40: jj_3_41(); break;
          }
        }
        p = p->next;
      } while (p != nullptr);
    }
    jj_rescan = false;
  }


  void AlpiScript::jj_save(int index, int xla){
    JJCalls *p = &jj_2_rtns[index];
    while (p->gen > jj_gen) {
      if (p->next == nullptr) { p = p->next = new JJCalls(); break; }
      p = p->next;
    }
    p->gen = jj_gen + xla - jj_la; p->first = token; p->arg = xla;
  }


