#include "SyntaxAnalyzer.hpp"
#include <iostream>
#include <sstream>
#include "string"

using namespace std;



SyntaxAnalyzer::SyntaxAnalyzer(vector<string> input) {
    tokenArray = input;
    index = 0;

    for (int i = 0; i < tokenArray.size(); ++i) {
        cout << tokenArray[i] << endl;
    }
}
SyntaxAnalyzer::~SyntaxAnalyzer() {
}
void SyntaxAnalyzer::setNewInput(string in) {


}
void SyntaxAnalyzer::syntax() {
    Splitter();
    program();
    cout << currentToken << ": " << "in program call"<<endl;
    if(currentToken =="$"){
        cout << "Syntax is correct" <<endl;
    }

}



void SyntaxAnalyzer::program(){
    cout << "inside program call"<< endl;
    declarationList();

}
void SyntaxAnalyzer::declarationList(){
    cout << "inside declarationList call"<< endl;
    declaration();
    if (currentClass == EMPTY) {
        cout << exitString << endl;
        exit(1);

    }
    declarationListPrime();
    if (currentClass == EMPTY){
        ;
    }

}
void SyntaxAnalyzer::declaration(){
    cout<<"inside declaration call"<<endl;
    cout <<"tokens: " << currentToken << " " << currentClass<< endl;
    typeSpecific();
    if (currentClass != EMPTY) {
        cout <<"tokens: " << currentToken << " " << currentClass<< endl;
        if(currentClass == ID) {
            cout<< "inside declaratoin ID check"<<endl;
            Splitter();
            cout <<"tokens: " << currentToken << " " << currentClass<< endl;
            declarationPrime();
        }else {
            cout<<"inside declartion fail ID check"<<endl;
            cout << exitString << endl;
        }
    }


}
void SyntaxAnalyzer::declarationListPrime(){
    cout<<"inside declarationListPrime call"<<endl;
    tempToken = currentToken;
    tempClass = currentClass;

    declaration();
    if (currentClass == EMPTY) {
        currentClass = tempClass;
        currentToken = tempToken;

    }else {

        declarationListPrime();

    }

}
void SyntaxAnalyzer::declarationPrime() {
    cout<<"inside declarationPrime call"<<endl;
    declarationPrimeFactor();
    if (currentToken.compare("@")) {
        if (currentToken =="(") {
            Splitter();
            params();
            if (currentToken ==")") {
                Splitter();
                compoundStmt();
            }
        }
    } else {
        cout << exitString << endl;
        exit(1);
    }

}
void SyntaxAnalyzer::declarationPrimeFactor() {
    cout<< "inside declarationPrimeFactor"<<endl;
    cout <<"tokens: " << currentToken << " " << currentClass<< endl;
    if (currentToken == ";") {
        Splitter();
    }else{
        cout <<"inside declarationPrimeFactor else statement"<<endl;
        if(currentToken == "[") {
            Splitter();
            cout <<"tokens: " << currentToken << " " << currentClass<< endl;
            if (currentClass == INT) {
                cout << "inside declarationPrimeFactor NUM check"<<endl;
                Splitter();
                if (currentToken == "]") {
                    cout <<"tokens: " << currentToken << " " << currentClass<< endl;
                    Splitter();
                    if (currentToken == ";") {
                        cout <<"tokens: " << currentToken << " " << currentClass<< endl;
                        Splitter();
                        cout <<"tokens: " << currentToken << " " << currentClass<< endl;
                    }else {
                        cout << exitString << endl;
                        exit(1);
                    }
                } else {
                    cout << exitString << endl;
                    exit(1);
                }
            } else {
                cout << exitString << endl;
                exit(1);
            }
        } else {
            currentToken = EMPTY;
        }
    }

}
void SyntaxAnalyzer::typeSpecific(){
    cout << "inside typeSpecific call"<<endl;

    cout <<"tokens: " << currentToken << currentClass<< endl;
    if(currentToken == "int"){
        cout<< "inside typeSpecific if statement"<<endl;
        Splitter();
        cout <<"tokens: " << currentToken << currentClass<< endl;
    }else {
        if(currentToken == "float") {
            cout<< "inside typeSpecific if statement"<<endl;
            Splitter();
            cout <<"tokens: " << currentToken << currentClass<< endl;
        } else {
            if(currentToken == "void") {
                cout<< "inside typeSpecific if statement"<<endl;
                Splitter();
                cout <<"tokens: " << currentToken << currentClass<< endl;
            }else {
                // Set Empty variable
                cout<<"inside typeSpecific else statement"<<endl;
                cout <<"tokens: " << currentToken << currentClass<< endl;
                currentClass = EMPTY;
            }
        }

    }

}
void SyntaxAnalyzer::params() {
    if (currentToken.compare("int")) {
        Splitter();
        if (currentClass == ID) {
            Splitter();
            paramPrime();
            paramListPrime();

        } else {
            cout << exitString << endl;
            exit(1);
        }
    }else {
        if (currentToken.compare("void")) {
            Splitter();
            paramsPrime();


        }else {
            if(currentToken.compare("float")) {
                if (currentClass == ID) {
                    Splitter();
                    paramPrime();
                    paramListPrime();
                }else {
                    cout << exitString << endl;
                    exit(1);
                }
            }
        }
    }
}

void SyntaxAnalyzer::paramsPrime(){

}
void SyntaxAnalyzer::paramListPrime(){

}
void SyntaxAnalyzer::param(){

}
void SyntaxAnalyzer::paramPrime(){
    if(currentToken.compare("[")) {
        Splitter();
        if (currentToken.compare("]")) {

        } else {
            cout << exitString << endl;
        }
    }

}
void SyntaxAnalyzer::compoundStmt(){

}
void SyntaxAnalyzer::localDeclarations(){

}
void SyntaxAnalyzer::localDeclarationsPrime(){

}
void SyntaxAnalyzer::statementList(){

}
void SyntaxAnalyzer::staementListPrime(){

}
void SyntaxAnalyzer::statement(){

}
void SyntaxAnalyzer::expressionStmt(){

}
void SyntaxAnalyzer::selectionStmt(){

}
void SyntaxAnalyzer::selectionStmtPrime(){

}
void SyntaxAnalyzer::iterationStmt(){

}
void SyntaxAnalyzer::returnStmt(){

}
void SyntaxAnalyzer::returnStmtPrime(){

}
void SyntaxAnalyzer::expression(){

}
void SyntaxAnalyzer::expressionFactor(){

}
void SyntaxAnalyzer::expressionPrime(){

}
void SyntaxAnalyzer::simpleExpressionPrime(){

}
void SyntaxAnalyzer::relop(){

}
void SyntaxAnalyzer::additiveExpression(){

}
void SyntaxAnalyzer::additiveExpressionPrime(){

}
void SyntaxAnalyzer::addop(){

}
void SyntaxAnalyzer::term(){

}
void SyntaxAnalyzer::termPrime(){

}
void SyntaxAnalyzer::mulop(){

}
void SyntaxAnalyzer::factor(){

}
void SyntaxAnalyzer::factorPrime(){

}
void SyntaxAnalyzer::args(){

}
void SyntaxAnalyzer::argsPrime(){

}
void SyntaxAnalyzer::Splitter() {
    string buf;
    stringstream ss(tokenArray[index]);
    vector<string> splitToken;



    while (ss >> buf) {
        splitToken.push_back(buf);
    }

    if (splitToken.size()> 1) {
        stringstream convert(splitToken[1]);
        currentToken = splitToken[0];
        convert >> currentClass;
        //cout << "Split Tokens: " << currentToken << " " << currentClass <<endl;
    } else {
        currentToken = splitToken[0];

    }
    index++;
}

