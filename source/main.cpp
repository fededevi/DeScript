 #include "source/ast/expression.h"

int main(int , char** ) {

    ExpressionUPtr e = ExpressionUPtr(Expression::parse("6 + 34 * 3 + as"));
}

