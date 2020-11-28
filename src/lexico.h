/**
 * 
 * Analisador Lexico e Tabela de Tokens
 * Autor: Felipe Derkian
 * Data: 27/11/2020
 * 
 */

#include <bits/stdc++.h>

#define INVALID_TOKEN -1


#define TK_ATRIBUITE        0
#define TK_NUMBER           1
#define TK_ID               2
#define TK_OPERATION        3
#define TK_FINAL_EXPRESSION 4


class Tokens
{
public:
    int type;
    int line;
    char lexema[200];

    Tokens()
    {
        strcpy(this->lexema, "");
        this->type = -1;
        this->line = -1;
    }

    void setToken(char *lexema, int type, int line)
    {
        this->line = line;
        this->type = type;
        strcpy(this->lexema, lexema);
    }

    char *getLexema()
    {
        return this->lexema;
    }

    int getType()
    {
        return this->type;
    }

    int getLine()
    {
        return this->line;
    }
};

void getNameTypeLexema(int identifyToken);

Tokens getLexemaSobDemanda();

void analisadorLexico();

void setListTokens(char* word, int type, int linha);

void back();

void copy_current();

void clear_current();

bool eof_file(char c);

bool isSpace(char c);

bool isBreakLine(char c);

bool isChar(char c);

bool isNumber(char c);

bool isOperator(char c);

bool isBar(char c);

bool isDot(char c);

bool isDubleDot(char c);

bool isIquals(char c);

bool isFinalExpression(char c);

