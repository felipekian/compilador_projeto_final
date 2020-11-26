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

using namespace std;

void analisadorLexico()
{
    char c;
    char currentWord[200] = "";
    int line = 0;
    int state = 0;

    do
    {
        c = getNextChar();
        strcat(currentWord, (&c));
        cout << "PALAVRA CORRENTE: " << currentWord << endl;

        switch (state)
        {
        case 0:
            if (isSimbolFormatatiton(c))
            {
                if (isBreakLine(c))
                {
                    line++;
                }
                state = 0;
            }
            else if (isDubleDot(c))
            {
                state = 1;
            }
            else if (isFinalExpression(c))
            {
                state = 7;
            }
            else if (isNumber(c))
            {
                state = 3;
            }
            else if (isCaractere(c))
            {
                state = 4;
            }
            else if (isOperator(c))
            {
                state = 6;
            }
            else
            {
                state = -1;
            }

            break;
        case 1:
            if (isIquals(c))
            {
                state = 2;
            }
            else
            {
                state = -1;
            }

            break;
        case 2:

            break;
        case 3:
            if (isNumber(c))
            {
                state = 3;
            }
            else if (isDot(c))
            {
                state = 5;
            }
            else
            {
                state = -1;
            }

            break;
        case 4:
            if (isNumber(c) || isCaractere(c))
            {
                state = 4;
            }
            else
            {
                state = -1;
            }
            break;
        case 5:
            if (isNumber(c))
            {
                state = 8;
            }
            else
            {
                state = -1;
            }
            break;
        case 6:

            break;
        case 7:
            state = -1;
            break;
        case 8:
            if (isNumber(c))
            {
                state = 8;
            }
            else
            {
                state = -1;
            }

            break;
        default:
            error_letter_not_gramatical(c, currentWord, line);
            exit(EXIT_FAILURE);
        }
    } while (c != '\0');
}

void setListTokens(char *word, int type)
{
    // criar um vector para tratar as entradas categorizadas na analise lexica
}

bool isSimbolFormatatiton(char c)
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