#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "tinyrexxLexer.h"
#include "tinyrexxParser.h"

using namespace std;
using namespace antlr4;

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cout << "Usage: syncheck filename.rexx" << endl;
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
        cout << errors << " syntax errors found." << endl;
        return 1;
    } 
    cout << "No syntax errors found." << endl;   
    return 0;
}
