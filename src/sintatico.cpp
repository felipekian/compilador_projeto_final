#include <bits/stdc++.h>

#include "lexico.h"
#include "sintatico.h"
#include "semantica.h"
#include "errors.h"

using namespace std;

Tokens t;
char msg[100];
bool flag = false;

void addTokenParaSemantica()
{
    setTokenParaAnaliseSemantica(t.getLexema(), t.getType(), t.getLine());
}

void valid(int v)
{
    if (v == FINAL_LIST && flag)
    {
        cout << "FIM ANALISE SINTATICA" << endl;
        exit(EXIT_SUCCESS);
    }else if(v == FINAL_LIST && !flag){
        strcpy(msg, "Esperado ;");
        error_sintaxe(t.getLexema(), msg, t.getLine());
        exit(EXIT_FAILURE);
    }
}

void E()
{
    TL();
    I();
    T();
    EL();
}

void TL()
{
    t = getTokens();

    valid(t.getType());

    if (t.getType() != TK_ID)
    {
        strcpy(msg, "Esperado uma variável de atribuicao");
        error_sintaxe(t.getLexema(), msg, t.getLine());
        exit(EXIT_FAILURE);
    }

    addTokenParaSemantica();
}

void I()
{
    t = getTokens();

    valid(t.getType());

    if (t.getType() != TK_ATRIBUITE)
    {
        strcpy(msg, "Esperado :=");
        error_sintaxe(t.getLexema(), msg, t.getLine());
        exit(EXIT_FAILURE);
    }

    addTokenParaSemantica();
}

void T()
{
    t = getTokens();

    valid(t.getType());

    if (t.getType() != TK_ID && t.getType() != TK_NUMBER)
    {
        strcpy(msg, "Esperado termo variável ou numero");
        error_sintaxe(t.getLexema(), msg, t.getLine());
        exit(EXIT_FAILURE);
    }

    addTokenParaSemantica();
}

void EL()
{
    t = getTokens();
    FE();
    OP();
    T();
    flag = false;
    EL();
}

void OP()
{
    if (t.getType() != TK_OPERATION)
    {
        strcpy(msg, "Esperado algum operador matematico");
        error_sintaxe(t.getLexema(), msg, t.getLine());
        exit(EXIT_FAILURE);
    }

    addTokenParaSemantica();
}

void FE()
{

    if (t.getType() == TK_FINAL_EXPRESSION)
    {
        cout << "Reconhecido expressao" << endl;
        flag = true;
        addTokenParaSemantica();
        analiseSemantica();
        E();
    }
}
