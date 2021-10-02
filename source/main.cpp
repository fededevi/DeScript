#include "javacc/generated/Parser.h"
#include "javacc/generated/ParseException.h"
#include "javacc/generated/CharStream.h"
#include "javacc/generated/ParserTokenManager.h"
#include "javacc/generated/ParserTokenManager.h"

#include "visitors/alpiscriptwriter.h"

using namespace AlpiScript;


int main(int argc, char** argv) {
    cout << "Reading from standard input..." << endl;
    std::string s = "1 + (2 * 3) % 4 - as / 3 \n";
    try {
        CharStream stream(s.c_str(), s.size() - 1, 1, 1);
        ParserTokenManager *scanner = new ParserTokenManager(&stream);
        Parser parser(scanner);

        SimpleNode* n = parser.parse();
        /*n->dump("");*/

        cout << "dumping base node:" << endl;
        AlpiScriptVisitor visitor;
        n->jjtAccept(&visitor, nullptr);
    } catch (const ParseException& e) {
        cout << "ERROR..." << e.tokenImage << endl;

    }
    return 0;
}

