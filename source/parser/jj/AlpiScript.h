#ifndef ALPISCRIPT_H
#define ALPISCRIPT_H
#include "JavaCC.h"
#include "CharStream.h"
#include "Token.h"
#include "TokenManager.h"
#include "AlpiScriptConstants.h"
#include "ErrorHandler.h"
  struct JJCalls {
    int        gen;
    int        arg;
    JJCalls*   next;
    Token*     first;
    ~JJCalls() { if (next) delete next; }
     JJCalls() { next = nullptr; arg = 0; gen = -1; first = nullptr; }
  };

class AlpiScript {
public:
Statement Start();
Statement multiStatement();
Statement statementParse();
FunctionCallStatement functionCallStatementParse();
Return returnParse();
FunctionDeclaration functionDeclarationParse();
FormalParameter multiFormalParameter();
FormalParameter formalParameterParse();
Loop loopParse();
Condition conditionParse();
Assignment assignmenParse();
Declaration declarationParse();
Identifier identifierParse();
Expression expressionParse();
Expression additiveExpressionParse();
Expression multiplicativeExpressionParse();
Expression comparativeExpressionParseOr();
Expression comparativeExpressionParseAnd();
Expression comparativeExpressionParseComparisons();
Expression comparativeExpressionParseNot();
Expression unaryExpressionParse();
FunctionCallExpression functionCallExpressionParse();
ActualParameter actualParameterParseMulti();
ActualParameter actualParameterParse();
Expression variableParse();
Literal literalParse();
IntegerLiteral integerLiteralParse();
BooleanLiteral booleanLiteralParse();
StringLiteral stringLiteralParse();
FloatingPointLiteral floatingPointLiteralParse();
 inline bool jj_2_1(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_1() || jj_done);
 { jj_save(0, xla); }
  }

 inline bool jj_2_2(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_2() || jj_done);
 { jj_save(1, xla); }
  }

 inline bool jj_2_3(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_3() || jj_done);
 { jj_save(2, xla); }
  }

 inline bool jj_2_4(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_4() || jj_done);
 { jj_save(3, xla); }
  }

 inline bool jj_2_5(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_5() || jj_done);
 { jj_save(4, xla); }
  }

 inline bool jj_2_6(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_6() || jj_done);
 { jj_save(5, xla); }
  }

 inline bool jj_2_7(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_7() || jj_done);
 { jj_save(6, xla); }
  }

 inline bool jj_2_8(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_8() || jj_done);
 { jj_save(7, xla); }
  }

 inline bool jj_2_9(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_9() || jj_done);
 { jj_save(8, xla); }
  }

 inline bool jj_2_10(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_10() || jj_done);
 { jj_save(9, xla); }
  }

 inline bool jj_2_11(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_11() || jj_done);
 { jj_save(10, xla); }
  }

 inline bool jj_2_12(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_12() || jj_done);
 { jj_save(11, xla); }
  }

 inline bool jj_2_13(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_13() || jj_done);
 { jj_save(12, xla); }
  }

 inline bool jj_2_14(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_14() || jj_done);
 { jj_save(13, xla); }
  }

 inline bool jj_2_15(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_15() || jj_done);
 { jj_save(14, xla); }
  }

 inline bool jj_2_16(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_16() || jj_done);
 { jj_save(15, xla); }
  }

 inline bool jj_2_17(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_17() || jj_done);
 { jj_save(16, xla); }
  }

 inline bool jj_2_18(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_18() || jj_done);
 { jj_save(17, xla); }
  }

 inline bool jj_2_19(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_19() || jj_done);
 { jj_save(18, xla); }
  }

 inline bool jj_2_20(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_20() || jj_done);
 { jj_save(19, xla); }
  }

 inline bool jj_2_21(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_21() || jj_done);
 { jj_save(20, xla); }
  }

 inline bool jj_2_22(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_22() || jj_done);
 { jj_save(21, xla); }
  }

 inline bool jj_2_23(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_23() || jj_done);
 { jj_save(22, xla); }
  }

 inline bool jj_2_24(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_24() || jj_done);
 { jj_save(23, xla); }
  }

 inline bool jj_2_25(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_25() || jj_done);
 { jj_save(24, xla); }
  }

 inline bool jj_2_26(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_26() || jj_done);
 { jj_save(25, xla); }
  }

 inline bool jj_2_27(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_27() || jj_done);
 { jj_save(26, xla); }
  }

 inline bool jj_2_28(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_28() || jj_done);
 { jj_save(27, xla); }
  }

 inline bool jj_2_29(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_29() || jj_done);
 { jj_save(28, xla); }
  }

 inline bool jj_2_30(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_30() || jj_done);
 { jj_save(29, xla); }
  }

 inline bool jj_2_31(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_31() || jj_done);
 { jj_save(30, xla); }
  }

 inline bool jj_2_32(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_32() || jj_done);
 { jj_save(31, xla); }
  }

 inline bool jj_2_33(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_33() || jj_done);
 { jj_save(32, xla); }
  }

 inline bool jj_2_34(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_34() || jj_done);
 { jj_save(33, xla); }
  }

 inline bool jj_2_35(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_35() || jj_done);
 { jj_save(34, xla); }
  }

 inline bool jj_2_36(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_36() || jj_done);
 { jj_save(35, xla); }
  }

 inline bool jj_2_37(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_37() || jj_done);
 { jj_save(36, xla); }
  }

 inline bool jj_2_38(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_38() || jj_done);
 { jj_save(37, xla); }
  }

 inline bool jj_2_39(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_39() || jj_done);
 { jj_save(38, xla); }
  }

 inline bool jj_2_40(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_40() || jj_done);
 { jj_save(39, xla); }
  }

 inline bool jj_2_41(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_41() || jj_done);
 { jj_save(40, xla); }
  }

 inline bool jj_3R_actualParameterParse_465_9_28()
 {
    if (jj_done) return true;
    if (jj_3R_expressionParse_301_3_27()) return true;
    return false;
  }

 inline bool jj_3_20()
 {
    if (jj_done) return true;
    if (jj_scan_token(AND)) return true;
    if (jj_3R_comparativeExpressionParseComparisons_381_3_21()) return true;
    return false;
  }

 inline bool jj_3_35()
 {
    if (jj_done) return true;
    if (jj_3R_actualParameterParse_465_9_28()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3_34()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_assignmenParse_266_9_11()
 {
    if (jj_done) return true;
    if (jj_3R_identifierParse_289_9_33()) return true;
    if (jj_scan_token(42)) return true;
    return false;
  }

 inline bool jj_3R_comparativeExpressionParseAnd_366_3_20()
 {
    if (jj_done) return true;
    if (jj_3R_comparativeExpressionParseComparisons_381_3_21()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3_20()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_returnParse_168_11_15()
 {
    if (jj_done) return true;
    if (jj_scan_token(RETURN)) return true;
    if (jj_3R_expressionParse_301_3_27()) return true;
    return false;
  }

 inline bool jj_3_11()
 {
    if (jj_done) return true;
    if (jj_scan_token(ELSE)) return true;
    if (jj_scan_token(LGP)) return true;
    return false;
  }

 inline bool jj_3_19()
 {
    if (jj_done) return true;
    if (jj_scan_token(OR)) return true;
    if (jj_3R_comparativeExpressionParseAnd_366_3_20()) return true;
    return false;
  }

 inline bool jj_3R_floatingPointLiteralParse_535_9_29()
 {
    if (jj_done) return true;
    if (jj_scan_token(FLOAT)) return true;
    return false;
  }

 inline bool jj_3R_comparativeExpressionParseOr_351_3_19()
 {
    if (jj_done) return true;
    if (jj_3R_comparativeExpressionParseAnd_366_3_20()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3_19()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_functionCallStatementParse_154_9_16()
 {
    if (jj_done) return true;
    if (jj_3R_identifierParse_289_9_33()) return true;
    if (jj_scan_token(LP)) return true;
    return false;
  }

 inline bool jj_3R_conditionParse_246_9_12()
 {
    if (jj_done) return true;
    if (jj_scan_token(IF)) return true;
    if (jj_scan_token(LP)) return true;
    return false;
  }

 inline bool jj_3R_stringLiteralParse_527_10_31()
 {
    if (jj_done) return true;
    if (jj_scan_token(43)) return true;
    if (jj_scan_token(NAME)) return true;
    return false;
  }

 inline bool jj_3R_functionCallExpressionParse_431_9_25()
 {
    if (jj_done) return true;
    if (jj_3R_identifierParse_289_9_33()) return true;
    if (jj_scan_token(LP)) return true;
    return false;
  }

 inline bool jj_3_9()
 {
    if (jj_done) return true;
    if (jj_scan_token(41)) return true;
    if (jj_3R_formalParameterParse_215_9_17()) return true;
    return false;
  }

 inline bool jj_3_18()
 {
    if (jj_done) return true;
    if (jj_scan_token(MOD)) return true;
    if (jj_3R_comparativeExpressionParseOr_351_3_19()) return true;
    return false;
  }

 inline bool jj_3_8()
 {
    if (jj_done) return true;
    if (jj_3R_functionCallStatementParse_154_9_16()) return true;
    return false;
  }

 inline bool jj_3_17()
 {
    if (jj_done) return true;
    if (jj_scan_token(DIV)) return true;
    if (jj_3R_comparativeExpressionParseOr_351_3_19()) return true;
    return false;
  }

 inline bool jj_3_33()
 {
    if (jj_done) return true;
    if (jj_scan_token(LP)) return true;
    if (jj_3R_expressionParse_301_3_27()) return true;
    return false;
  }

 inline bool jj_3_7()
 {
    if (jj_done) return true;
    if (jj_3R_returnParse_168_11_15()) return true;
    return false;
  }

 inline bool jj_3_16()
 {
    if (jj_done) return true;
    if (jj_scan_token(MUL)) return true;
    if (jj_3R_comparativeExpressionParseOr_351_3_19()) return true;
    return false;
  }

 inline bool jj_3_15()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3_16()) {
    jj_scanpos = xsp;
    if (jj_3_17()) {
    jj_scanpos = xsp;
    if (jj_3_18()) return true;
    }
    }
    return false;
  }

 inline bool jj_3_32()
 {
    if (jj_done) return true;
    if (jj_3R_variableParse_478_9_26()) return true;
    return false;
  }

 inline bool jj_3_6()
 {
    if (jj_done) return true;
    if (jj_3R_functionDeclarationParse_182_11_14()) return true;
    return false;
  }

 inline bool jj_3_31()
 {
    if (jj_done) return true;
    if (jj_3R_functionCallExpressionParse_431_9_25()) return true;
    return false;
  }

 inline bool jj_3_5()
 {
    if (jj_done) return true;
    if (jj_3R_loopParse_227_9_13()) return true;
    return false;
  }

 inline bool jj_3_41()
 {
    if (jj_done) return true;
    if (jj_scan_token(FALSE)) return true;
    return false;
  }

 inline bool jj_3_4()
 {
    if (jj_done) return true;
    if (jj_3R_conditionParse_246_9_12()) return true;
    return false;
  }

 inline bool jj_3R_booleanLiteralParse_518_9_30()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3_40()) {
    jj_scanpos = xsp;
    if (jj_3_41()) return true;
    }
    return false;
  }

 inline bool jj_3R_multiplicativeExpressionParse_334_3_18()
 {
    if (jj_done) return true;
    if (jj_3R_comparativeExpressionParseOr_351_3_19()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3_15()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3_40()
 {
    if (jj_done) return true;
    if (jj_scan_token(TRUE)) return true;
    return false;
  }

 inline bool jj_3_3()
 {
    if (jj_done) return true;
    if (jj_3R_assignmenParse_266_9_11()) return true;
    return false;
  }

 inline bool jj_3_30()
 {
    if (jj_done) return true;
    if (jj_3R_literalParse_493_9_24()) return true;
    return false;
  }

 inline bool jj_3_39()
 {
    if (jj_done) return true;
    if (jj_3R_integerLiteralParse_510_9_32()) return true;
    return false;
  }

 inline bool jj_3R_loopParse_227_9_13()
 {
    if (jj_done) return true;
    if (jj_scan_token(WHILE)) return true;
    if (jj_scan_token(LP)) return true;
    return false;
  }

 inline bool jj_3_38()
 {
    if (jj_done) return true;
    if (jj_3R_stringLiteralParse_527_10_31()) return true;
    return false;
  }

 inline bool jj_3_37()
 {
    if (jj_done) return true;
    if (jj_3R_booleanLiteralParse_518_9_30()) return true;
    return false;
  }

 inline bool jj_3R_integerLiteralParse_510_9_32()
 {
    if (jj_done) return true;
    if (jj_scan_token(INTEGER)) return true;
    return false;
  }

 inline bool jj_3_2()
 {
    if (jj_done) return true;
    if (jj_3R_declarationParse_278_9_10()) return true;
    return false;
  }

 inline bool jj_3R_unaryExpressionParse_414_9_23()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3_30()) {
    jj_scanpos = xsp;
    if (jj_3_31()) {
    jj_scanpos = xsp;
    if (jj_3_32()) {
    jj_scanpos = xsp;
    if (jj_3_33()) return true;
    }
    }
    }
    return false;
  }

 inline bool jj_3R_statementParse_133_3_9()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3_2()) {
    jj_scanpos = xsp;
    if (jj_3_3()) {
    jj_scanpos = xsp;
    if (jj_3_4()) {
    jj_scanpos = xsp;
    if (jj_3_5()) {
    jj_scanpos = xsp;
    if (jj_3_6()) {
    jj_scanpos = xsp;
    if (jj_3_7()) {
    jj_scanpos = xsp;
    if (jj_3_8()) return true;
    }
    }
    }
    }
    }
    }
    return false;
  }

 inline bool jj_3_14()
 {
    if (jj_done) return true;
    if (jj_scan_token(SUB)) return true;
    if (jj_3R_multiplicativeExpressionParse_334_3_18()) return true;
    return false;
  }

 inline bool jj_3_13()
 {
    if (jj_done) return true;
    if (jj_scan_token(ADD)) return true;
    if (jj_3R_multiplicativeExpressionParse_334_3_18()) return true;
    return false;
  }

 inline bool jj_3_12()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3_13()) {
    jj_scanpos = xsp;
    if (jj_3_14()) return true;
    }
    return false;
  }

 inline bool jj_3_29()
 {
    if (jj_done) return true;
    if (jj_3R_unaryExpressionParse_414_9_23()) return true;
    return false;
  }

 inline bool jj_3_36()
 {
    if (jj_done) return true;
    if (jj_3R_floatingPointLiteralParse_535_9_29()) return true;
    return false;
  }

 inline bool jj_3R_additiveExpressionParse_317_3_34()
 {
    if (jj_done) return true;
    if (jj_3R_multiplicativeExpressionParse_334_3_18()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3_12()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_formalParameterParse_215_9_17()
 {
    if (jj_done) return true;
    if (jj_3R_identifierParse_289_9_33()) return true;
    return false;
  }

 inline bool jj_3_1()
 {
    if (jj_done) return true;
    if (jj_3R_statementParse_133_3_9()) return true;
    return false;
  }

 inline bool jj_3_10()
 {
    if (jj_done) return true;
    if (jj_3R_formalParameterParse_215_9_17()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3_9()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_literalParse_493_9_24()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3_36()) {
    jj_scanpos = xsp;
    if (jj_3_37()) {
    jj_scanpos = xsp;
    if (jj_3_38()) {
    jj_scanpos = xsp;
    if (jj_3_39()) return true;
    }
    }
    }
    return false;
  }

 inline bool jj_3_28()
 {
    if (jj_done) return true;
    if (jj_scan_token(NOT)) return true;
    if (jj_3R_unaryExpressionParse_414_9_23()) return true;
    return false;
  }

 inline bool jj_3_34()
 {
    if (jj_done) return true;
    if (jj_scan_token(41)) return true;
    if (jj_3R_actualParameterParse_465_9_28()) return true;
    return false;
  }

 inline bool jj_3R_comparativeExpressionParseNot_400_3_22()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3_28()) {
    jj_scanpos = xsp;
    if (jj_3_29()) return true;
    }
    return false;
  }

 inline bool jj_3R_expressionParse_301_3_27()
 {
    if (jj_done) return true;
    if (jj_3R_additiveExpressionParse_317_3_34()) return true;
    return false;
  }

 inline bool jj_3R_identifierParse_289_9_33()
 {
    if (jj_done) return true;
    if (jj_scan_token(NAME)) return true;
    return false;
  }

 inline bool jj_3_27()
 {
    if (jj_done) return true;
    if (jj_scan_token(NE)) return true;
    if (jj_3R_comparativeExpressionParseNot_400_3_22()) return true;
    return false;
  }

 inline bool jj_3R_variableParse_478_9_26()
 {
    if (jj_done) return true;
    if (jj_3R_identifierParse_289_9_33()) return true;
    return false;
  }

 inline bool jj_3_26()
 {
    if (jj_done) return true;
    if (jj_scan_token(EQ)) return true;
    if (jj_3R_comparativeExpressionParseNot_400_3_22()) return true;
    return false;
  }

 inline bool jj_3_25()
 {
    if (jj_done) return true;
    if (jj_scan_token(GT)) return true;
    if (jj_3R_comparativeExpressionParseNot_400_3_22()) return true;
    return false;
  }

 inline bool jj_3_24()
 {
    if (jj_done) return true;
    if (jj_scan_token(GE)) return true;
    if (jj_3R_comparativeExpressionParseNot_400_3_22()) return true;
    return false;
  }

 inline bool jj_3_23()
 {
    if (jj_done) return true;
    if (jj_scan_token(LE)) return true;
    if (jj_3R_comparativeExpressionParseNot_400_3_22()) return true;
    return false;
  }

 inline bool jj_3_21()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3_22()) {
    jj_scanpos = xsp;
    if (jj_3_23()) {
    jj_scanpos = xsp;
    if (jj_3_24()) {
    jj_scanpos = xsp;
    if (jj_3_25()) {
    jj_scanpos = xsp;
    if (jj_3_26()) {
    jj_scanpos = xsp;
    if (jj_3_27()) return true;
    }
    }
    }
    }
    }
    return false;
  }

 inline bool jj_3_22()
 {
    if (jj_done) return true;
    if (jj_scan_token(LT)) return true;
    if (jj_3R_comparativeExpressionParseNot_400_3_22()) return true;
    return false;
  }

 inline bool jj_3R_comparativeExpressionParseComparisons_381_3_21()
 {
    if (jj_done) return true;
    if (jj_3R_comparativeExpressionParseNot_400_3_22()) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3_21()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_functionDeclarationParse_182_11_14()
 {
    if (jj_done) return true;
    if (jj_scan_token(FUNCTION)) return true;
    if (jj_3R_identifierParse_289_9_33()) return true;
    return false;
  }

 inline bool jj_3R_declarationParse_278_9_10()
 {
    if (jj_done) return true;
    if (jj_scan_token(VAR)) return true;
    if (jj_3R_identifierParse_289_9_33()) return true;
    return false;
  }


public: 
  void setErrorHandler(ErrorHandler *eh) {
    if (errorHandler) delete errorHandler;
    errorHandler = eh;
  }

  TokenManager *token_source = nullptr;
  CharStream   *jj_input_stream = nullptr;
  /** Current token. */
  Token        *token = nullptr;
  /** Next token. */
  Token        *jj_nt = nullptr;

private: 
  int           jj_ntk;
  JJCalls       jj_2_rtns[42];
  bool          jj_rescan;
  int           jj_gc;
  Token        *jj_scanpos, *jj_lastpos;
  int           jj_la;
  /** Whether we are looking ahead. */
  bool          jj_lookingAhead;
  bool          jj_semLA;
  int           jj_gen;
  int           jj_la1[1];
  ErrorHandler *errorHandler = nullptr;

protected: 
  bool          hasError;

  Token *head; 
public: 
  AlpiScript(TokenManager *tokenManager);
  virtual ~AlpiScript();
void ReInit(TokenManager* tokenManager);
void clear();
Token * jj_consume_token(int kind);
bool  jj_scan_token(int kind);
Token * getNextToken();
Token * getToken(int index);
int jj_ntk_f();
private:
  int jj_kind;
  int **jj_expentries;
  int *jj_expentry;
  void jj_add_error_token(int kind, int pos);
protected:
  /** Generate ParseException. */
  virtual void  parseError();
private:
  int  indent;	// trace indentation
  bool trace = false; // trace enabled if true

public:
  bool trace_enabled();
  void enable_tracing();
  void disable_tracing();
  void jj_rescan_token();
  void jj_save(int index, int xla);
package parser.jj;

import ast.expression.*;
import ast.expression.math.*;
import ast.expression.bool.*;
import ast.expression.literal.*;
import ast.statement.*;

public class DeoclaParser {

        public static void main(String args[]) throws ParseException, TokenMgrError, NumberFormatException {
                DeoclaParser parser = new DeoclaParser(System.in);
                //parser.Input();
        }

        Statement lastStatement;

}

private:
  bool jj_done;
};
#endif
