#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "tinyrexxLexer.h"
#include "tinyrexxParser.h"
#include "MyListener.h"

using namespace std;
using namespace antlr4;

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cout << "Usage: translate filename.rexx" << endl;
        return 1;
    }
    ifstream tinyrexxFile(argv[1]);
    if(tinyrexxFile.fail()){
        //Errore nell'apertura del file
        cout << "Error while reading file " << argv[1] << endl;
        return 1;
    }
    ANTLRInputStream input(tinyrexxFile);
    tinyrexxLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tinyrexxParser parser(&tokens);    
    tree::ParseTree *tree = parser.program();
    int errors = parser.getNumberOfSyntaxErrors();
    if(errors > 0) {
        cout << errors << " syntax errors found, aborting." << endl;
        return 1;
    } 
    // create set of IDs
    tokens.fill();
    std::set<std::string> ids;
    for (auto token : tokens.getTokens()) {
        if(token->getType() == parser.ID) {
            ids.insert(token->getText());
        }
    }

    MyListener listener(ids);
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    return 0;
}
