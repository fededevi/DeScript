/* AlpiScriptTokenManager.cc */
#include "AlpiScriptTokenManager.h"
#include "TokenMgrError.h"
static const int jjnextStates[] = {
   5, 6, 7, 8, 10, 11, 
};
static JJChar jjstrLiteralChars_0[] = {0};
static JJChar jjstrLiteralChars_1[] = {0};
static JJChar jjstrLiteralChars_2[] = {0};
static JJChar jjstrLiteralChars_3[] = {0};
static JJChar jjstrLiteralChars_4[] = {0};
static JJChar jjstrLiteralChars_5[] = {0};

static JJChar jjstrLiteralChars_6[] = {0x72, 0x65, 0x74, 0x75, 0x72, 0x6e, 0};
static JJChar jjstrLiteralChars_7[] = {0x76, 0x61, 0x72, 0};

static JJChar jjstrLiteralChars_8[] = {0x69, 0x66, 0};
static JJChar jjstrLiteralChars_9[] = {0x65, 0x6c, 0x73, 0x65, 0};

static JJChar jjstrLiteralChars_10[] = {0x77, 0x68, 0x69, 0x6c, 0x65, 0};

static JJChar jjstrLiteralChars_11[] = {0x66, 0x75, 0x6e, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0};
static JJChar jjstrLiteralChars_12[] = {0x74, 0x72, 0x75, 0x65, 0};

static JJChar jjstrLiteralChars_13[] = {0x66, 0x61, 0x6c, 0x73, 0x65, 0};
static JJChar jjstrLiteralChars_14[] = {0x28, 0};

static JJChar jjstrLiteralChars_15[] = {0x29, 0};
static JJChar jjstrLiteralChars_16[] = {0x7b, 0};

static JJChar jjstrLiteralChars_17[] = {0x7d, 0};
static JJChar jjstrLiteralChars_18[] = {0x5b, 0};

static JJChar jjstrLiteralChars_19[] = {0x5d, 0};
static JJChar jjstrLiteralChars_20[] = {0x2b, 0};

static JJChar jjstrLiteralChars_21[] = {0x2d, 0};
static JJChar jjstrLiteralChars_22[] = {0x2a, 0};

static JJChar jjstrLiteralChars_23[] = {0x2f, 0};
static JJChar jjstrLiteralChars_24[] = {0x25, 0};

static JJChar jjstrLiteralChars_25[] = {0x3c, 0};
static JJChar jjstrLiteralChars_26[] = {0x3c, 0x3d, 0};

static JJChar jjstrLiteralChars_27[] = {0x3e, 0x3d, 0};
static JJChar jjstrLiteralChars_28[] = {0x3e, 0};

static JJChar jjstrLiteralChars_29[] = {0x3d, 0x3d, 0};
static JJChar jjstrLiteralChars_30[] = {0x21, 0x3d, 0};

static JJChar jjstrLiteralChars_31[] = {0x26, 0x26, 0};
static JJChar jjstrLiteralChars_32[] = {0x7c, 0x7c, 0};

static JJChar jjstrLiteralChars_33[] = {0x21, 0};
static JJChar jjstrLiteralChars_34[] = {0};
static JJChar jjstrLiteralChars_35[] = {0};
static JJChar jjstrLiteralChars_36[] = {0};
static JJChar jjstrLiteralChars_37[] = {0};
static JJChar jjstrLiteralChars_38[] = {0};
static JJChar jjstrLiteralChars_39[] = {0};

static JJChar jjstrLiteralChars_40[] = {0x3b, 0};
static JJChar jjstrLiteralChars_41[] = {0x2c, 0};

static JJChar jjstrLiteralChars_42[] = {0x3d, 0};
static JJChar jjstrLiteralChars_43[] = {0x22, 0};
static const JJString jjstrLiteralImages[] = {
jjstrLiteralChars_0, 
jjstrLiteralChars_1, 
jjstrLiteralChars_2, 
jjstrLiteralChars_3, 
jjstrLiteralChars_4, 
jjstrLiteralChars_5, 
jjstrLiteralChars_6, 
jjstrLiteralChars_7, 
jjstrLiteralChars_8, 
jjstrLiteralChars_9, 
jjstrLiteralChars_10, 
jjstrLiteralChars_11, 
jjstrLiteralChars_12, 
jjstrLiteralChars_13, 
jjstrLiteralChars_14, 
jjstrLiteralChars_15, 
jjstrLiteralChars_16, 
jjstrLiteralChars_17, 
jjstrLiteralChars_18, 
jjstrLiteralChars_19, 
jjstrLiteralChars_20, 
jjstrLiteralChars_21, 
jjstrLiteralChars_22, 
jjstrLiteralChars_23, 
jjstrLiteralChars_24, 
jjstrLiteralChars_25, 
jjstrLiteralChars_26, 
jjstrLiteralChars_27, 
jjstrLiteralChars_28, 
jjstrLiteralChars_29, 
jjstrLiteralChars_30, 
jjstrLiteralChars_31, 
jjstrLiteralChars_32, 
jjstrLiteralChars_33, 
jjstrLiteralChars_34, 
jjstrLiteralChars_35, 
jjstrLiteralChars_36, 
jjstrLiteralChars_37, 
jjstrLiteralChars_38, 
jjstrLiteralChars_39, 
jjstrLiteralChars_40, 
jjstrLiteralChars_41, 
jjstrLiteralChars_42, 
jjstrLiteralChars_43, 
};

/** Lexer state names. */
static const JJChar lexStateNames_arr_0[] = 
{0x44, 0x45, 0x46, 0x41, 0x55, 0x4c, 0x54, 0};
static const JJString lexStateNames[] = {
lexStateNames_arr_0, 
};
static const unsigned long long jjtoToken[] = {
   0xfcfffffffc1ULL, 
};
static const unsigned long long jjtoSkip[] = {
   0x3eULL, 
};

  void  AlpiScriptTokenManager::setDebugStream(FILE *ds){ debugStream = ds; }

 int AlpiScriptTokenManager::jjStopStringLiteralDfa_0(int pos, unsigned long long active0){
   switch (pos)
   {
      case 0:
         if ((active0 & 0x3fc0ULL) != 0L)
         {
            jjmatchedKind = 39;
            return 3;
         }
         return -1;
      case 1:
         if ((active0 & 0x100ULL) != 0L)
            return 3;
         if ((active0 & 0x3ec0ULL) != 0L)
         {
            jjmatchedKind = 39;
            jjmatchedPos = 1;
            return 3;
         }
         return -1;
      case 2:
         if ((active0 & 0x80ULL) != 0L)
            return 3;
         if ((active0 & 0x3e40ULL) != 0L)
         {
            jjmatchedKind = 39;
            jjmatchedPos = 2;
            return 3;
         }
         return -1;
      case 3:
         if ((active0 & 0x1200ULL) != 0L)
            return 3;
         if ((active0 & 0x2c40ULL) != 0L)
         {
            jjmatchedKind = 39;
            jjmatchedPos = 3;
            return 3;
         }
         return -1;
      case 4:
         if ((active0 & 0x840ULL) != 0L)
         {
            jjmatchedKind = 39;
            jjmatchedPos = 4;
            return 3;
         }
         if ((active0 & 0x2400ULL) != 0L)
            return 3;
         return -1;
      case 5:
         if ((active0 & 0x800ULL) != 0L)
         {
            jjmatchedKind = 39;
            jjmatchedPos = 5;
            return 3;
         }
         if ((active0 & 0x40ULL) != 0L)
            return 3;
         return -1;
      case 6:
         if ((active0 & 0x800ULL) != 0L)
         {
            jjmatchedKind = 39;
            jjmatchedPos = 6;
            return 3;
         }
         return -1;
      default :
         return -1;
   }
}

int  AlpiScriptTokenManager::jjStartNfa_0(int pos, unsigned long long active0){
   return jjMoveNfa_0(jjStopStringLiteralDfa_0(pos, active0), pos + 1);
}

 int  AlpiScriptTokenManager::jjStopAtPos(int pos, int kind){
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   return pos + 1;
}

 int  AlpiScriptTokenManager::jjMoveStringLiteralDfa0_0(){
   switch(curChar)
   {
      case 13:
         jjmatchedKind = 4;
         return jjMoveStringLiteralDfa1_0(0x20ULL);
      case 33:
         jjmatchedKind = 33;
         return jjMoveStringLiteralDfa1_0(0x40000000ULL);
      case 34:
         return jjStopAtPos(0, 43);
      case 37:
         return jjStopAtPos(0, 24);
      case 38:
         return jjMoveStringLiteralDfa1_0(0x80000000ULL);
      case 40:
         return jjStopAtPos(0, 14);
      case 41:
         return jjStopAtPos(0, 15);
      case 42:
         return jjStopAtPos(0, 22);
      case 43:
         return jjStopAtPos(0, 20);
      case 44:
         return jjStopAtPos(0, 41);
      case 45:
         return jjStopAtPos(0, 21);
      case 47:
         return jjStopAtPos(0, 23);
      case 59:
         return jjStopAtPos(0, 40);
      case 60:
         jjmatchedKind = 25;
         return jjMoveStringLiteralDfa1_0(0x4000000ULL);
      case 61:
         jjmatchedKind = 42;
         return jjMoveStringLiteralDfa1_0(0x20000000ULL);
      case 62:
         jjmatchedKind = 28;
         return jjMoveStringLiteralDfa1_0(0x8000000ULL);
      case 91:
         return jjStopAtPos(0, 18);
      case 93:
         return jjStopAtPos(0, 19);
      case 101:
         return jjMoveStringLiteralDfa1_0(0x200ULL);
      case 102:
         return jjMoveStringLiteralDfa1_0(0x2800ULL);
      case 105:
         return jjMoveStringLiteralDfa1_0(0x100ULL);
      case 114:
         return jjMoveStringLiteralDfa1_0(0x40ULL);
      case 116:
         return jjMoveStringLiteralDfa1_0(0x1000ULL);
      case 118:
         return jjMoveStringLiteralDfa1_0(0x80ULL);
      case 119:
         return jjMoveStringLiteralDfa1_0(0x400ULL);
      case 123:
         return jjStopAtPos(0, 16);
      case 124:
         return jjMoveStringLiteralDfa1_0(0x100000000ULL);
      case 125:
         return jjStopAtPos(0, 17);
      default :
         return jjMoveNfa_0(0, 0);
   }
}

 int  AlpiScriptTokenManager::jjMoveStringLiteralDfa1_0(unsigned long long active0){
   if (input_stream->endOfInput()) {
      jjStopStringLiteralDfa_0(0, active0);
      return 1;
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 10:
         if ((active0 & 0x20ULL) != 0L)
            return jjStopAtPos(1, 5);
         break;
      case 38:
         if ((active0 & 0x80000000ULL) != 0L)
            return jjStopAtPos(1, 31);
         break;
      case 61:
         if ((active0 & 0x4000000ULL) != 0L)
            return jjStopAtPos(1, 26);
         else if ((active0 & 0x8000000ULL) != 0L)
            return jjStopAtPos(1, 27);
         else if ((active0 & 0x20000000ULL) != 0L)
            return jjStopAtPos(1, 29);
         else if ((active0 & 0x40000000ULL) != 0L)
            return jjStopAtPos(1, 30);
         break;
      case 97:
         return jjMoveStringLiteralDfa2_0(active0, 0x2080ULL);
      case 101:
         return jjMoveStringLiteralDfa2_0(active0, 0x40ULL);
      case 102:
         if ((active0 & 0x100ULL) != 0L)
            return jjStartNfaWithStates_0(1, 8, 3);
         break;
      case 104:
         return jjMoveStringLiteralDfa2_0(active0, 0x400ULL);
      case 108:
         return jjMoveStringLiteralDfa2_0(active0, 0x200ULL);
      case 114:
         return jjMoveStringLiteralDfa2_0(active0, 0x1000ULL);
      case 117:
         return jjMoveStringLiteralDfa2_0(active0, 0x800ULL);
      case 124:
         if ((active0 & 0x100000000ULL) != 0L)
            return jjStopAtPos(1, 32);
         break;
      default :
         break;
   }
   return jjStartNfa_0(0, active0);
}

 int  AlpiScriptTokenManager::jjMoveStringLiteralDfa2_0(unsigned long long old0, unsigned long long active0){
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(0, old0);
   if (input_stream->endOfInput()) {
      jjStopStringLiteralDfa_0(1, active0);
      return 2;
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 105:
         return jjMoveStringLiteralDfa3_0(active0, 0x400ULL);
      case 108:
         return jjMoveStringLiteralDfa3_0(active0, 0x2000ULL);
      case 110:
         return jjMoveStringLiteralDfa3_0(active0, 0x800ULL);
      case 114:
         if ((active0 & 0x80ULL) != 0L)
            return jjStartNfaWithStates_0(2, 7, 3);
         break;
      case 115:
         return jjMoveStringLiteralDfa3_0(active0, 0x200ULL);
      case 116:
         return jjMoveStringLiteralDfa3_0(active0, 0x40ULL);
      case 117:
         return jjMoveStringLiteralDfa3_0(active0, 0x1000ULL);
      default :
         break;
   }
   return jjStartNfa_0(1, active0);
}

 int  AlpiScriptTokenManager::jjMoveStringLiteralDfa3_0(unsigned long long old0, unsigned long long active0){
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(1, old0);
   if (input_stream->endOfInput()) {
      jjStopStringLiteralDfa_0(2, active0);
      return 3;
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 99:
         return jjMoveStringLiteralDfa4_0(active0, 0x800ULL);
      case 101:
         if ((active0 & 0x200ULL) != 0L)
            return jjStartNfaWithStates_0(3, 9, 3);
         else if ((active0 & 0x1000ULL) != 0L)
            return jjStartNfaWithStates_0(3, 12, 3);
         break;
      case 108:
         return jjMoveStringLiteralDfa4_0(active0, 0x400ULL);
      case 115:
         return jjMoveStringLiteralDfa4_0(active0, 0x2000ULL);
      case 117:
         return jjMoveStringLiteralDfa4_0(active0, 0x40ULL);
      default :
         break;
   }
   return jjStartNfa_0(2, active0);
}

 int  AlpiScriptTokenManager::jjMoveStringLiteralDfa4_0(unsigned long long old0, unsigned long long active0){
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(2, old0);
   if (input_stream->endOfInput()) {
      jjStopStringLiteralDfa_0(3, active0);
      return 4;
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 101:
         if ((active0 & 0x400ULL) != 0L)
            return jjStartNfaWithStates_0(4, 10, 3);
         else if ((active0 & 0x2000ULL) != 0L)
            return jjStartNfaWithStates_0(4, 13, 3);
         break;
      case 114:
         return jjMoveStringLiteralDfa5_0(active0, 0x40ULL);
      case 116:
         return jjMoveStringLiteralDfa5_0(active0, 0x800ULL);
      default :
         break;
   }
   return jjStartNfa_0(3, active0);
}

 int  AlpiScriptTokenManager::jjMoveStringLiteralDfa5_0(unsigned long long old0, unsigned long long active0){
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(3, old0);
   if (input_stream->endOfInput()) {
      jjStopStringLiteralDfa_0(4, active0);
      return 5;
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 105:
         return jjMoveStringLiteralDfa6_0(active0, 0x800ULL);
      case 110:
         if ((active0 & 0x40ULL) != 0L)
            return jjStartNfaWithStates_0(5, 6, 3);
         break;
      default :
         break;
   }
   return jjStartNfa_0(4, active0);
}

 int  AlpiScriptTokenManager::jjMoveStringLiteralDfa6_0(unsigned long long old0, unsigned long long active0){
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(4, old0);
   if (input_stream->endOfInput()) {
      jjStopStringLiteralDfa_0(5, active0);
      return 6;
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 111:
         return jjMoveStringLiteralDfa7_0(active0, 0x800ULL);
      default :
         break;
   }
   return jjStartNfa_0(5, active0);
}

 int  AlpiScriptTokenManager::jjMoveStringLiteralDfa7_0(unsigned long long old0, unsigned long long active0){
   if (((active0 &= old0)) == 0L)
      return jjStartNfa_0(5, old0);
   if (input_stream->endOfInput()) {
      jjStopStringLiteralDfa_0(6, active0);
      return 7;
   }
   curChar = input_stream->readChar();
   switch(curChar)
   {
      case 110:
         if ((active0 & 0x800ULL) != 0L)
            return jjStartNfaWithStates_0(7, 11, 3);
         break;
      default :
         break;
   }
   return jjStartNfa_0(6, active0);
}

int AlpiScriptTokenManager::jjStartNfaWithStates_0(int pos, int kind, int state){
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   if (input_stream->endOfInput()) { return pos + 1; }
   curChar = input_stream->readChar();
   return jjMoveNfa_0(state, pos + 1);
}

int AlpiScriptTokenManager::jjMoveNfa_0(int startState, int curPos){
   int startsAt = 0;
   jjnewStateCnt = 12;
   int i = 1;
   jjstateSet[0] = startState;
   int kind = 0x7fffffff;
   for (;;)
   {
      if (++jjround == 0x7fffffff)
         ReInitRounds();
      if (curChar < 64)
      {
         unsigned long long l = 1ULL << curChar;
         (void)l;
         do
         {
            switch(jjstateSet[--i])
            {
               case 0:
                  if ((0x3ff000000000000ULL & l) != 0L)
                  {
                     if (kind > 34)
                        kind = 34;
                     { jjCheckNAddStates(0, 5); }
                  }
                  else if ((0x280000000000ULL & l) != 0L)
                  {
                     if (kind > 38)
                        kind = 38;
                  }
                  else if (curChar == 46)
                     { jjCheckNAdd(1); }
                  break;
               case 1:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 35)
                     kind = 35;
                  { jjCheckNAdd(1); }
                  break;
               case 2:
                  if ((0x280000000000ULL & l) != 0L)
                     kind = 38;
                  break;
               case 4:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 34)
                     kind = 34;
                  { jjCheckNAddStates(0, 5); }
                  break;
               case 5:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 34)
                     kind = 34;
                  { jjCheckNAdd(5); }
                  break;
               case 6:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 35)
                     kind = 35;
                  { jjCheckNAdd(6); }
                  break;
               case 7:
                  if ((0x3ff000000000000ULL & l) != 0L)
                     { jjCheckNAddTwoStates(7, 8); }
                  break;
               case 8:
                  if (curChar == 46)
                     { jjCheckNAdd(9); }
                  break;
               case 9:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 35)
                     kind = 35;
                  { jjCheckNAdd(9); }
                  break;
               case 10:
                  if ((0x3ff000000000000ULL & l) != 0L)
                     { jjCheckNAddTwoStates(10, 11); }
                  break;
               case 11:
                  if (curChar == 46 && kind > 35)
                     kind = 35;
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else if (curChar < 128)
      {
         unsigned long long l = 1ULL << (curChar & 077);
         (void)l;
         do
         {
            switch(jjstateSet[--i])
            {
               case 0:
               case 3:
                  if ((0x7fffffe07fffffeULL & l) == 0L)
                     break;
                  kind = 39;
                  { jjCheckNAdd(3); }
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else
      {
         int i2 = (curChar & 0xff) >> 6;
         unsigned long long l2 = 1ULL << (curChar & 077);
         do
         {
            switch(jjstateSet[--i])
            {
               default : break;
            }
         } while(i != startsAt);
      }
      if (kind != 0x7fffffff)
      {
         jjmatchedKind = kind;
         jjmatchedPos = curPos;
         kind = 0x7fffffff;
      }
      ++curPos;
      if ((i = jjnewStateCnt), (jjnewStateCnt = startsAt), (i == (startsAt = 12 - startsAt)))
         return curPos;
      if (input_stream->endOfInput()) { return curPos; }
      curChar = input_stream->readChar();
   }
}

/** Token literal values. */

Token * AlpiScriptTokenManager::jjFillToken(){
   Token *t;
   JJString curTokenImage;
   int beginLine   = -1;
   int endLine     = -1;
   int beginColumn = -1;
   int endColumn   = -1;
   JJString im = jjstrLiteralImages[jjmatchedKind];
   curTokenImage = (im.length() == 0) ? input_stream->GetImage() : im;
   if (input_stream->getTrackLineColumn()) {
     beginLine = input_stream->getBeginLine();
     beginColumn = input_stream->getBeginColumn();
     endLine = input_stream->getEndLine();
     endColumn = input_stream->getEndColumn();
   }
   t = Token::newToken(jjmatchedKind, curTokenImage);
   t->specialToken = nullptr;
   t->next = nullptr;

   if (input_stream->getTrackLineColumn()) {
   t->beginLine = beginLine;
   t->endLine = endLine;
   t->beginColumn = beginColumn;
   t->endColumn = endColumn;
   }

   return t;
}
const int defaultLexState = 0;
/** Get the next Token. */

Token * AlpiScriptTokenManager::getNextToken(){
  Token *matchedToken = nullptr;
  int curPos = 0;

  for (;;)
  {
   EOFLoop: 
   if (input_stream->endOfInput())
   {
      jjmatchedKind = 0;
      jjmatchedPos = -1;
      matchedToken = jjFillToken();
      return matchedToken;
   }
   curChar = input_stream->BeginToken();

   { input_stream->backup(0);
      while (curChar <= 32 && (0x100000600ULL & (1ULL << curChar)) != 0L)
   {
   if (input_stream->endOfInput()) { goto EOFLoop; }
   curChar = input_stream->BeginToken();
   }
   }
   jjmatchedKind = 0x7fffffff;
   jjmatchedPos = 0;
   curPos = jjMoveStringLiteralDfa0_0();
   if (jjmatchedKind != 0x7fffffff)
   {
      if (jjmatchedPos + 1 < curPos)
         input_stream->backup(curPos - jjmatchedPos - 1);
      if ((jjtoToken[jjmatchedKind >> 6] & (1ULL << (jjmatchedKind & 077))) != 0L)
      {
         matchedToken = jjFillToken();
         return matchedToken;
      }
      else
      {
         goto EOFLoop;
      }
   }
   int error_line = input_stream->getEndLine();
   int error_column = input_stream->getEndColumn();
   JJString error_after;
   bool EOFSeen = false;
   if (input_stream->endOfInput()) {
      EOFSeen = true;
      error_after = curPos <= 1 ? EMPTY : input_stream->GetImage();
      if (curChar == '\n' || curChar == '\r') {
         error_line++;
         error_column = 0;
      }
      else
         error_column++;
   }
   if (!EOFSeen) {
      error_after = curPos <= 1 ? EMPTY : input_stream->GetImage();
   }
   errorHandler->lexicalError(EOFSeen, curLexState, error_line, error_column, error_after, curChar, this);
  }
}

  /** Reinitialise parser. */
  void AlpiScriptTokenManager::ReInit(JAVACC_CHARSTREAM *stream, int lexState) {
    clear();
    jjmatchedPos = jjnewStateCnt = 0;
    curLexState = lexState;
    input_stream = stream;
    ReInitRounds();
    debugStream = stdout; // init
    SwitchTo(lexState);
    errorHandler = new TokenManagerErrorHandler();
  }

  void AlpiScriptTokenManager::ReInitRounds() {
    int i;
    jjround = 0x80000001;
    for (i = 12; i-- > 0;)
      jjrounds[i] = 0x80000000;
  }

  /** Switch to specified lex state. */
  void AlpiScriptTokenManager::SwitchTo(int lexState) {
    if (lexState >= 1 || lexState < 0) {
      JJString message;
#ifdef WIDE_CHAR
      message += L"Error: Ignoring invalid lexical state : ";
      message += lexState; message += L". State unchanged.";
#else
      message += "Error: Ignoring invalid lexical state : ";
      message += lexState; message += ". State unchanged.";
#endif
      throw new TokenMgrError(message, INVALID_LEXICAL_STATE);
    } else
      curLexState = lexState;
  }

  /** Constructor. */
  AlpiScriptTokenManager::AlpiScriptTokenManager (JAVACC_CHARSTREAM *stream, int lexState)
  {
    input_stream = nullptr;
    ReInit(stream, lexState);
  }

  // Destructor
  AlpiScriptTokenManager::~AlpiScriptTokenManager () {
    clear();
  }

  // clear
  void AlpiScriptTokenManager::clear() {
    //Since input_stream was generated outside of TokenManager
    //TokenManager should not take care of deleting it
    //if (input_stream) delete input_stream;
    if (errorHandler) delete errorHandler, errorHandler = nullptr;    
  }


