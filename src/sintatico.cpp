#include <bits/stdc++.h>

#include "lexico.h"
#include "sintatico.h"
#include "errors.h"

using namespace std;


void E()
{
    TL();
    I();
    T();
    EL();
    FE();

    cout << "FIM ANALISE SINTATICA" << endl;
}

void EL()
{
    Tokens t = getTokens();    
    if(t.getType() != TK_OPERATION) return;
    if(t.getType() == -1) return;

    OP();
    T();
    EL();
}

void T()
{
    Tokens t = getTokens();    
    if(t.getType()) return;
    if(t.getType() == -1) return;

    if (!t.getType() == TK_ID && !t.getType() == TK_NUMBER)
    {
        char msg[] = "Esperado uma variável ou numero";
        error_sintaxe(t.getLexema(), msg, t.getLine());
    }
}

void TL()
{
    Tokens t = getTokens();    
    if(t.getType() == -1) return;

    if (!t.getType() == TK_ID)
    {
        char msg[] = "Esperado uma variável";
        error_sintaxe(t.getLexema(), msg, t.getLine());
    }
}

void I()
{
    Tokens t = getTokens();
    
    if(t.getType() == -1) return;

    if (!t.getType() == TK_ATRIBUITE)
    {
        char msg[] = "Esperado atribuição";
        error_sintaxe(t.getLexema(), msg, t.getLine());
    }
}

void FE()
{
    Tokens t = getTokens();
    
    if(t.getType() == -1) return;

    if (!t.getType() == TK_FINAL_EXPRESSION)
    {
        char msg[] = "Esperado final de expressão";
        error_sintaxe(t.getLexema(), msg, t.getLine());
    }
}

void OP()
{
    Tokens t = getTokens();
    
    if(t.getType() == -1) return;

    if (!t.getType() == TK_OPERATION)
    {
        char msg[] = "Esperado operador matemático";
        error_sintaxe(t.getLexema(), msg, t.getLine());
    }
}

