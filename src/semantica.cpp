#include <bits/stdc++.h>

#include "lexico.h"
#include "semantica.h"
#include "errors.h"

using namespace std;

// vetor com a expressão a ser analisada
vector<TokenSematica> tabela_semantica;
vector<TokenSematica> poolVariaveis;
char msgSemantica[200];



// add os lexemas validados no vetor tabela semantica para ser analisado apos confirmação que a expressão é valida
void setTokenParaAnaliseSemantica(char *lexema, int type, int line)
{
    TokenSematica t;
    t.setToken(lexema, type, line);
    tabela_semantica.push_back(t);
}



// trata a mensagem de erro e encerra o programa
void tratar_error_semantico(TokenSematica t)
{
    strcpy(msgSemantica, "variavel não declarada");
    error_semantica(msgSemantica, t.getLexema(), t.getLine());
    exit(EXIT_FAILURE);
}



/**
 * Para as variáveis de atribuição procura se esta na pool de variáveis, 
 * caso contrario add pois ainda não foram inicializadas
 */
void findOrAddTokenAtribuiteInPool(TokenSematica t)
{
    int i;

    // verifica se esta na pool
    for (i = 0; i < poolVariaveis.size(); i++)
    {
        if (strcmp(poolVariaveis[i].getLexema(), t.getLexema()) == 0)
            return;
    }

    poolVariaveis.push_back(t);
}



// para as variáveis que estão dentro da função verifica-se se já foram inicializadas ou utilizadas
void findTokenInPool(TokenSematica t)
{
    int i;

    // verifica se esta na pool
    for (i = 0; i < poolVariaveis.size(); i++)
    {
        if (strcmp(poolVariaveis[i].getLexema(), t.getLexema()) == 0)
            return;
    }

    tratar_error_semantico(t);
}



// imprime uma mensagem de fim da analise semantica
void fim_analise_semantica_msg()
{
    cout << "FIM DA ANALISE SEMANTICA DA EXPRESSAO: ";
    for (int i = 0; i < tabela_semantica.size(); i++)
    {
        cout << " " << tabela_semantica[i].getLexema();
    }
    cout << endl
         << endl;
}



// faz a analise semantica
bool analiseSemantica()
{

    for (int i = 0; i < tabela_semantica.size(); i++)
    {
        // verifica se tem variável de atribuição na pool ou add
        if (i == 0)
        {
            findOrAddTokenAtribuiteInPool(tabela_semantica[i]);
        }
        else if (tabela_semantica[i].getType() == TK_ID)
        {
            findTokenInPool(tabela_semantica[i]);
        }
    }

    fim_analise_semantica_msg();
    tabela_semantica.clear();

    return true;
}

