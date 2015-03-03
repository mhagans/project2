#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
#if !defined(P1)

#include <iostream>
#include <fstream>
#include "LexicalAnalyzer.hpp"
#include "SyntaxAnalyzer.hpp"

using namespace std;

int main(int argc, char **argv) {
    string filename;
    string fileLine;

    if(argc < 2){
        cout << "Invalid number of arugments entered"<<endl;
        return 0;
    }else{
        filename = argv[1];
    }

    cout<<"*********** Syntax Analyzer*************"<<endl;

    int token = SPACE;

   ifstream FILE(filename.c_str());
    getline(FILE, fileLine);
    SyntaxAnalyzer SA(fileLine);
    if(FILE.is_open()){

        do {
            if (SA.currentToken.compare("")) {
                SA.LA.lex();
            }
            SA.syntax();
            getline(FILE, fileLine);

            SA.setNewInput(fileLine);
            token = SPACE;

        }while(!FILE.eof());

    }else{
        cout << "Unable to open " << filename <<endl;
    }

    return 0;
}

#endif
#pragma clang diagnostic pop