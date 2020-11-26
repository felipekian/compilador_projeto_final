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

#define INVALID 1000

using namespace std;

void analisadorLexico()
{
    char c;
    char currentWord[200] = "";
    int line = 0;
    int state = 0;
    bool back = false;

    do
    {
        if (back)
        {
            back = false;
            strcpy(currentWord, "");
        }
        else
        {
            c = getNextChar();
            strcat(currentWord, (&c));
        }

        switch (state)
        {
        case 0:
            if (isSpace(c))
                state = 0;
            else if (isDubleDot(c))
                state = 1;
            else if (isNumber(c))
                state = 3;
            else if (isCaractere(c))
                state = 6;
            else if (isOperator(c))
                state = 7;
            else if (isFinalExpression(c))
                state = 9;
            
            break;

        case 1:
            if (isIquals(c))
            {
                state = 2;
            }
            
            break;

        case 2:
            // atribuicao :=
            setListTokens(currentWord, TK_ATRIBUITE);
            state = 0;

            break;

        case 3:
            if (isNumber(c))
                state = 3;
            else if (isDot(c))
                state = 4;
            else
            {
                setListTokens(currentWord, TK_CONST_INT);
                state = 0;
            }

            break;

        case 4:
            if (isNumber(c))
                state = 5;
            else
            {
                state = INVALID;
            }
            break;

        case 5:
            if (isNumber(c))
                state = 5;
            else
            {
                setListTokens(currentWord, TK_CONST_FLOAT);
                state = 0;
            }
            break;

        case 6:
            if (isCaractere(c) || isNumber(c))
                state = 6;
            else
            {
                setListTokens(currentWord, TK_ID);
                state = 0;
            }
            break;

        case 7:
            if (isBar(c))
                state = 8;
            else
            {
                // + - * / -> operações
                setListTokens(currentWord, TK_OPERATION);
                state = 0;
            }
            break;

        case 8:
            if (isBreakLine(c))
            {
                state = 0;
            }
            else
                state = 8;
            break;

        case 9:
            setListTokens(currentWord, TK_FINAL_EXPRESSION);
            state = 0;
            break;

        default:
            error_letter_not_gramatical(c, currentWord, line);
            exit(EXIT_FAILURE);
            break;
        }

    } while (c != '\0');
}

void setListTokens(char *word, int type)
{
    cout << "WORD: " << word << endl << endl;
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