/**
 * 
 * Analisador Lexico e Tabela de Tokens
 * Autor: Felipe Derkian
 * Data: 27/11/2020
 * 
 */

#include <bits/stdc++.h>

#include "errors.h"
#include "scannerFile.h"
#include "lexico.h"

using namespace std;


queue<Tokens> tabela_simbolos;

char c;
char currentWord[200] = "";
char spected[200] = "";
int line = 1;
int state = 0;
bool _back = false;

void analisadorLexico()
{

    while (true)
    {
        if (!_back)
        {
            c = getNextChar();

            if (c == '\n')
                line++;
        }
        else
        {
            _back = false;
        }

        if (eof_file(c))
            break;

        switch (state)
        {
        case 0:
            // estado 0 não tem nada
            clear_current();

            if (isFinalExpression(c))
            {
                state = 1;
                copy_current();
            }
            else if (isNumber(c))
            {
                state = 2;
                copy_current();
            }
            else if (isChar(c))
            {
                state = 3;
                copy_current();
            }
            else if (isOperator(c))
            {
                state = 4;
                copy_current();
            }
            else if (isDubleDot(c))
            {
                state = 5;
                copy_current();
            }
            else if (isSpace(c) || isBreakLine(c))
            {
                state = 0;
                if (eof_file(c))
                    break;
            }
            else
            {
                state = INVALID_TOKEN;
            }
            break;

        case 1:
            setListTokens(currentWord, TK_FINAL_EXPRESSION, line);
            back();
            break;

        case 2:
            if (isNumber(c))
            {
                state = 2;
                copy_current();
            }
            else
            {
                setListTokens(currentWord, TK_NUMBER, line);
                strcpy(spected, "numero");
                back();
            }
            break;

        case 3:
            if (isNumber(c) || isChar(c))
            {
                state = 3;
                copy_current();
            }
            else
            {
                setListTokens(currentWord, TK_ID, line);
                strcpy(spected, "numero ou caractere");
                back();
            }
            break;

        case 4:
            setListTokens(currentWord, TK_OPERATION, line);
            back();
            break;

        case 5:
            if (isIquals(c))
            {
                state = 6;
                copy_current();
            }
            else
            {
                _back = true;
                state = INVALID_TOKEN;
                strcpy(spected, "=");
            }
            break;

        case 6:
            setListTokens(currentWord, TK_ATRIBUITE, line);
            back();
            break;

        default:
            error_letter_not_gramatical(c, currentWord, spected, line);
            exit(EXIT_FAILURE);
        }
    }

    cout << "FIM ANALISE LEXICA" << endl;
}

void setListTokens(char word[], int type, int line)
{
    Tokens token;
    token.setToken(word, type, line);
    tabela_simbolos.push(token);
}

Tokens getLexemaSobDemanda()
{
    Tokens t;

    if (!tabela_simbolos.empty())
    {
        t = tabela_simbolos.front();
        tabela_simbolos.pop();
    }

    return t;
}

void back()
{
    _back = true;
    state = 0;
    clear_current();
}

void copy_current()
{
    strcat(currentWord, (&c));
}

void clear_current()
{
    strcpy(currentWord, "");
}

bool eof_file(char c)
{
    return (c == '\0');
}

bool isSpace(char c)
{
    return (c == '\t' || c == ' ');
}

bool isBreakLine(char c)
{
    return (c == '\n' || c == '\r');
    line++;
}

bool isChar(char c)
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

void getNameTypeLexema(int identifyToken)
{
    if (identifyToken == TK_ATRIBUITE)
        cout << "TK_ATRIBUITE\n";

    else if (identifyToken == TK_NUMBER)
        cout << "TK_NUMBER\n";

    else if (identifyToken == TK_ID)
        cout << "TK_ID\n";

    else if (identifyToken == TK_OPERATION)
        cout << "TK_OPERATION\n";

    else if (identifyToken == TK_FINAL_EXPRESSION)
        cout << "TK_FINAL_EXPRESSION\n";
}
