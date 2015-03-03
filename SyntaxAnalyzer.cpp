#include "SyntaxAnalyzer.hpp"
#include <iostream>

#include "string"

using namespace std;

SyntaxAnalyzer::SyntaxAnalyzer(string in) {
    LA.setNewInput(in);
    cout <<"INPUT: " << in << endl;
    nextToken == LA.lex();
    currentToken = LA.lexenum;

}

SyntaxAnalyzer::~SyntaxAnalyzer() {
}

void SyntaxAnalyzer::setNewInput(string in) {
    LA.setNewInput(in);
    cout <<"INPUT: " << in << endl;
    nextToken = LA.lex();
    currentToken = LA.lexenum;
}

void SyntaxAnalyzer::syntax() {
    program();
    if(nextToken == STOP){
        cout << "Syntax is correct" <<endl;
    }else{
        cout << exitString << endl;
        exit(1);
    }

}
void SyntaxAnalyzer::program(){
    declarationList();

}
void SyntaxAnalyzer::declarationList(){
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
    typeSpecific();
    if(nextToken == ID){
        nextToken = LA.lex();
        currentToken = LA.lexenum;
        declarationPrime();
    }else {
        if (emptyTest == EMPTY) {

        }
        cout << exitString << endl;
    }

}
void SyntaxAnalyzer::declarationListPrime(){
    declaration();
    if (nextToken == EMPTY) {
        ;
    }else {
        declarationListPrime();
    }

}
void SyntaxAnalyzer::declarationPrime() {
    declarationPrimeFactor();
    if (nextToken == EMPTY) {
        if (currentToken.compare("(")) {
            nextToken = LA.lex();
            currentToken = LA.lexenum;
            params();
            if (currentToken.compare(")")) {
                nextToken = LA.lex();
                currentToken = LA.lexenum;
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
        nextToken = LA.lex();
        currentToken = LA.lexenum;
    }else{
        if(currentToken.compare("[")){
            nextToken = LA.lex();
            currentToken = LA.lexenum;
            if (nextToken == INT) {
                nextToken = LA.lex();
                currentToken = LA.lexenum;
                if (currentToken.compare("]")) {
                    nextToken = LA.lex();
                    currentToken = LA.lexenum;
                    if (currentToken.compare(";")) {
                        nextToken = LA.lex();
                        currentToken = LA.lexenum;
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
    if(currentToken.compare("int") || currentToken.compare("float") || currentToken.compare("void")){
        nextToken = LA.lex();
        currentToken = LA.lexenum;
    }else {
        // Set Empty variable
        emptyTest = EMPTY;
    }

}
void SyntaxAnalyzer::params() {
    if (currentToken.compare("int")) {
        nextToken = LA.lex();
        currentToken = LA.lexenum;
        if (nextToken == ID) {
            nextToken = LA.lex();
            currentToken = LA.lexenum;

        } else {
            cout << exitString << endl;
        }
    }else {
        if (currentToken.compare("void")) {

        }else {
            if(currentToken.compare("float"))
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


