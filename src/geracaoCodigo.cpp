/**
 * 
 * Geração de código
 * Autor: Felipe Derkian
 * Data: 30/11/2020 
 * 
 */

#include <bits/stdc++.h>

#include "geracaoCodigo.h"

using namespace std;

vector<TokensGeracaoCodigo> quadrupla;

void setDataTokenGeracaoCodigo(char *resultado, char *operador, char *argumento1, char *argumento2)
{
    TokensGeracaoCodigo tokengeracao;
    tokengeracao.setToken(operador, resultado, argumento1, argumento2);
    quadrupla.push_back(tokengeracao);
}

void geracaoDeCodigo()
{

    cout << "\nGERACAO DE CODIDO" << endl
         << endl;

    for (int i = 0; i < quadrupla.size(); i++)
    {
        cout << quadrupla[i].getResultado() << endl;
        cout << quadrupla[i].getOperador() << endl;
        cout << quadrupla[i].getArgumento1() << endl;
        cout << quadrupla[i].getArgumento2() << endl
             << endl;
    }
}

/**
 * 
 * da quadrupla tem que otimizar o código bruto geral em uma funçao para otimizar
 * 
 */