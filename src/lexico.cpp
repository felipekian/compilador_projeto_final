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
    bool back = false;

    do
    {
        if (!back)
        {
            c = getNextChar();
            strcat(currentWord, (&c));
            //cout << "PALAVRA CORRENTE: " << currentWord << endl;
        }
        else
        {
            back = !back;
            state = 0;
            strcpy(currentWord, "");
        }

        cout << "LETRA ATUAL: " << c << "  :  Estado :" << state << endl;

        switch (state)
        {
        case 0:

        break;
        
        default:
            error_letter_not_gramatical(c, currentWord, line);
            return;
        }
    } while (c != '\0');
}

void setListTokens(char *word, int type)
{
    // criar um vector para tratar as entradas categorizadas na analise lexica
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