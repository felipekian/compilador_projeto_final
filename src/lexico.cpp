/**
 * 
 * Faltam tratar os casos onde é final = -1;
 *  
 * setar na tabela de simbolos os valores reconhecidos
 * 
 * tratar a entrada do nextCaractere
 * 
 */

#include <bits/stdc++.h>

#include "errors.h"
#include "scannerFile.h"
#include "lexico.h"

#define INVALIDO 100

char c;
char currentWord[200] = "";
int line = 0;
int state = 0;

using namespace std;

void analisadorLexico()
{

    while (c != '\0')
    {
        c = getNextChar();
        strcpy(currentWord, (&c));
    }
}

void setListTokens(char *word, int type)
{
    cout << "WORD: " << word << endl;
    cout << "TYPE: " << type << endl;
    cout << "LINE: " << line << endl;
    cout << "STATE: " << state << endl;
    cout << endl;
}

bool isSpace(char c)
{
    return (c == '\t' || c == '\r' || c == '\n' || c == ' ');
}

bool isBreakLine(char c)
{
    return (c == '\n');
}

bool isCaractere(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isNumber(char c)
{
    return (c >= '0' && c <= '9');
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isBar(char c)
{
    return (c == '/');
}

bool isDot(char c)
{
    return (c == '.');
}

bool isDubleDot(char c)
{
    return (c == ':');
}

bool isIquals(char c)
{
    return (c == '=');
}

bool isFinalExpression(char c)
{
    return (c == ';');
}