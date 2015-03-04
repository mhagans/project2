#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
#if !defined(P1)

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include "LexicalAnalyzer.hpp"
#include "SyntaxAnalyzer.hpp"

using namespace std;

string tokenConverter(int t);

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



    if(FILE.is_open()){
        LexicalAnalyzer LA(fileLine);
        string build;
        do {

            while(token != STOP){
                token = LA.lex();
                if(token == STOP){
                }else{
                    /*if(token == ID){
                        cout << tokenConverter(token) <<":\t" <<LA.lexenum<< " DEPTH: " << LA.depth << endl;
                    }else{
                        cout << tokenConverter(token) <<":\t" <<LA.lexenum<< endl;
                    }*/

                    stringstream convert;
                    convert << token;

                    LA.array.push_back(LA.lexenum + " " + convert.str());
                }

            }

            getline(FILE, fileLine);

            LA.setNewInput(fileLine);
            token = SPACE;

        }while(!FILE.eof());
        FILE.close();

        LA.array.push_back("$");

        /*for (int i = 0; i < LA.array.size(); ++i) {
            cout<< LA.array[i] << endl;
        }*/

        SyntaxAnalyzer SA(LA.array);
        SA.syntax();

    }else{
        cout << "Unable to open " << filename <<endl;
    }

    return 0;
}
string tokenConverter(int t){
    switch (t){
        case SPACE:
            return "SPACE";
        case LETTER:
            return "LETTER";
        case DIGIT:
            return "DIGIT";
        case ID:
            return "ID";
        case INT:
            return "INT";
        case ERROR:
            return "ERROR";
        case STOP:
            return "STOP";
        case FLOAT:
            return "FLOAT";
        case SYMBOL:
            return "SYMBOL";
        case KEYWORD:
            return "KEYWORD";

        default:
            return "UNKOWN";
    }
    return 0;
}


#endif
#pragma clang diagnostic pop