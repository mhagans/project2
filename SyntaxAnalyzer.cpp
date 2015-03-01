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
        cout << "Error" << endl;
        exit(1);
    }

}
void SyntaxAnalyzer::program(){
    declarationList();

}
void SyntaxAnalyzer::declarationList(){
    declaration();
    declarationListPrime();

}
void SyntaxAnalyzer::declarationListPrime(){

}
void SyntaxAnalyzer::declaration(){
    typeSpecific();
    if(nextToken == ID){
        nextToken = LA.lex();
        currentToken = LA.lexenum;
        declarationPrime();
    }

}
void SyntaxAnalyzer::declarationPrime(){

}
void SyntaxAnalyzer::declarationPrimeFactor(){

}
void SyntaxAnalyzer::typeSpecific(){
    if(currentToken.compare("int") || currentToken.compare("float") || currentToken.compare("void")){
        nextToken = LA.lex();
        currentToken = LA.lexenum;
    }

}
void SyntaxAnalyzer::params(){

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


