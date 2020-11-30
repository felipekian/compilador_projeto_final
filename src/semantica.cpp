/**
 * 
 * ANALISE SEMANTICA
 * Autor: Felipe Derkian
 * Data: 30/11/2020 
 * 
 */

#include <bits/stdc++.h>
#include <stdlib.h>

#include "lexico.h"
#include "semantica.h"
#include "geracaoCodigo.h"
#include "temporario.h"
#include "errors.h"

using namespace std;


// vetor com a expressão a ser analisada
vector<TokenSematica> tabela_semantica;
vector<TokenSematica> poolVariaveis;
char msgSemantica[200];
char p[5] = "";
char nextTemp[10] = "";
char nextTempBK[10] = "";



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

void sendTokensGenerationCode()
{

    int tam_tabela = tabela_semantica.size();

    cout << "TAM: " << tam_tabela << endl;

    // apenas atribuição de variável
    if (tam_tabela == 4)
    {
        // ex: a := 9;
        setDataTokenGeracaoCodigo(tabela_semantica[0].getLexema(),
                                  tabela_semantica[1].getLexema(),
                                  tabela_semantica[2].getLexema(),
                                  p);
    }
    else
    {
        // ex: a := a + b * c;

        for (int i = tam_tabela - 2; i > 1;)
        {
            if (i == tam_tabela - 2)
            {
                strcpy(nextTemp, getNextTemp());
                setDataTokenGeracaoCodigo(nextTemp,
                                          tabela_semantica[i - 1].getLexema(),
                                          tabela_semantica[i - 2].getLexema(),
                                          tabela_semantica[i].getLexema());
                i -= 3;
            }
            else
            {
                strcpy(nextTempBK, nextTemp);
                strcpy(nextTemp, getNextTemp());
                setDataTokenGeracaoCodigo(nextTemp,
                                          tabela_semantica[i].getLexema(),
                                          tabela_semantica[i - 1].getLexema(),
                                          nextTempBK);

                i -= 2;
            }
        }

        setDataTokenGeracaoCodigo(tabela_semantica[0].getLexema(),
                                  tabela_semantica[1].getLexema(),
                                  nextTemp,
                                  p);
    }

    // for (int i = tabela_semantica.size()-1; i >=0; i--)
    // {
    //     cout << " " << tabela_semantica[i].getLexema();
    // }
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


    // PARTE DO GERADOR DE CÓDIGO
    sendTokensGenerationCode();
    geracaoDeCodigo();
    fim_analise_semantica_msg();
    tabela_semantica.clear();

    return true;
}
