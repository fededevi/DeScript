#include "javacc/generated/Parser.h"
#include "javacc/generated/ParseException.h"
#include "javacc/generated/CharStream.h"
#include "javacc/generated/ParserTokenManager.h"
#include "javacc/generated/ParserTokenManager.h"

using namespace std;
using namespace AlpiScript;

JAVACC_STRING_TYPE ReadFileFully(char *file_name) {
    return "(stat1)(stat21122sd)(stat3);\n";
}

int main(int argc, char** argv) {
    cout << "Reading from standard input..." << endl;
    JAVACC_STRING_TYPE s = ReadFileFully(argv[1]);
    try {
        CharStream *stream = new CharStream(s.c_str(), s.size() - 1, 1, 1);
        ParserTokenManager *scanner = new ParserTokenManager(stream);
        Parser parser(scanner);
        SimpleNode* n = parser.parseProgram();
        n->dump("");
        cout << "Thank you." << endl;
    } catch (const ParseException& e) {
        cout << "ERROR..." << e.tokenImage << endl;

    }
    return 0;
}

