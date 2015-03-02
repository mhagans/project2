#if !defined(_SA_)
#define _SA_

#include <iostream>
#include <string>
#include "LexicalAnalyzer.hpp"
#include "cstdlib"

using namespace std;

enum{EMPTY};

class SyntaxAnalyzer {
    public:
    void syntax();
    void setNewInput(string
    in);
    SyntaxAnalyzer(string
    in);
    virtual ~SyntaxAnalyzer();

    string
    exitString = "Incorrect Syntax Exiting Program";
    int emptyTest;


    private:
    void program();
    void declarationList();
    void declarationListPrime();
    void declaration();
    void declarationPrime();
    void declarationPrimeFactor();
    void typeSpecific();
    void params();
    void paramsPrime();
    void paramListPrime();
    void param();
    void paramPrime();
    void compoundStmt();
    void localDeclarations();
    void localDeclarationsPrime();
    void statementList();
    void staementListPrime();
    void statement();
    void expressionStmt();
    void selectionStmt();
    void selectionStmtPrime();
    void iterationStmt();
    void returnStmt();
    void returnStmtPrime();
    void expression();
    void expressionFactor();
    void expressionPrime();
    void simpleExpressionPrime();
    void relop();
    void additiveExpression();
    void additiveExpressionPrime();
    void addop();
    void term();
    void termPrime();
    void mulop();
    void factor();
    void factorPrime();
    void args();
    void argsPrime();



    private:
    LexicalAnalyzer
    LA;
    int nextToken;
    int tempToken;
    string currentToken;
};

#endif