#include "SyntaxAnalyzer.hpp"
#include <iostream>

#include "string"

using namespace std;

SyntaxAnalyzer::SyntaxAnalyzer(string in) {
    LA.setNewInput(in);
    cout <<"INPUT: " << in << endl;
    nextToken = LA.lex();
    currentToken = LA.lexenum;
    cout << currentToken << endl;
    while (currentToken.compare("")) {
        nextToken = LA.lex();
        currentToken = LA.lexenum;
    }
    cout << currentToken << endl;

}

SyntaxAnalyzer::~SyntaxAnalyzer() {
}

void SyntaxAnalyzer::setNewInput(string in) {
    LA.setNewInput(in);
    cout <<"INPUT: " << in << endl;
    nextToken = LA.lex();
    currentToken = LA.lexenum;
    cout << currentToken << endl;
    while (currentToken.compare("")) {
        moveToken();
    }
    cout << currentToken << endl;
}

void SyntaxAnalyzer::syntax() {
    cout<<currentToken<<endl;
    while(currentToken.compare("")) {
        moveToken();
    }
    cout << "inside syntrax call"<<endl;
    program();
    cout << currentToken << ": " << "in program call"<<endl;
    if(nextToken == STOP){
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
    if (nextToken == EMPTY) {
        cout << exitString << endl;
        exit(1);

    }
    declarationListPrime();
    if (nextToken == EMPTY) {
        ;
    }

}
void SyntaxAnalyzer::declaration(){
    cout<<"inside declaration call"<<endl;
    cout<<currentToken<<endl;
    typeSpecific();
    cout<<currentToken<<endl;

    if(nextToken == ID) {
        moveToken();
        cout<<currentToken<<endl;
        declarationPrime();
    }else {
        if (emptyTest == EMPTY) {

        }
        cout << exitString << endl;
    }

}
void SyntaxAnalyzer::declarationListPrime(){
    cout<<"inside declarationListPrime call"<<endl;
    tempToken = nextToken;
    declaration();
    if (nextToken == EMPTY) {
        nextToken = tempToken;
    }else {
        tempToken = nextToken;
        declarationListPrime();
        if (nextToken == EMPTY) {
            nextToken = tempToken;
        }
    }

}
void SyntaxAnalyzer::declarationPrime() {
    cout<<"inside declarationPrime call"<<endl;
    declarationPrimeFactor();
    if (nextToken == EMPTY) {
        if (currentToken.compare("(")) {
            moveToken();
            params();
            if (currentToken.compare(")")) {
                moveToken();
                compoundStmt();
            }
        }
    } else {
        cout << exitString << endl;
        exit(1);
    }

}
void SyntaxAnalyzer::declarationPrimeFactor() {
    if (currentToken.compare(";")) {
        moveToken();
    }else{
        if(currentToken.compare("[")) {
            moveToken();
            if (nextToken == INT) {
                moveToken();
                if (currentToken.compare("]")) {
                    moveToken();
                    if (currentToken.compare(";")) {
                        moveToken();
                    } else {
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
            nextToken = EMPTY;
        }
    }

}
void SyntaxAnalyzer::typeSpecific(){
    cout << "inside typeSpecific call"<<endl;
    cout<<currentToken<<endl;
    if(currentToken.compare("int") || currentToken.compare("float") || currentToken.compare("void")){
        moveToken();
        cout<<currentToken<<endl;
        system("pause>nul");
    }else {
        // Set Empty variable
        cout<<currentToken<<endl;
        emptyTest = EMPTY;
    }

}
void SyntaxAnalyzer::params() {
    if (currentToken.compare("int")) {
        moveToken();
        if (nextToken == ID) {
            moveToken();
            paramPrime();
            paramListPrime();

        } else {
            cout << exitString << endl;
            exit(1);
        }
    }else {
        if (currentToken.compare("void")) {
            moveToken();
            paramsPrime();


        }else {
            if(currentToken.compare("float")) {
                if (nextToken == ID) {
                    moveToken();
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

void SyntaxAnalyzer::moveToken() {
    nextToken = LA.lex();
    currentToken = LA.lexenum;
}

void SyntaxAnalyzer::paramsPrime(){

}
void SyntaxAnalyzer::paramListPrime(){

}
void SyntaxAnalyzer::param(){

}
void SyntaxAnalyzer::paramPrime(){
    if(currentToken.compare("[")) {
        moveToken();
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


