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
vector<int> removerLines;

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

void otimizationGenerationCode()
{

    cout << "Gerando otimização de codigo" << endl;

    for (int i = 0; i < quadrupla.size() - 1; i++)
    {
        if (strcmp(quadrupla[i].getArgumento2(), "") == 0 && strcmp(quadrupla[i].getOperador(), ":=") == 0)
        {
            for (int j = i + 1; j < quadrupla.size(); j++)
            {
                if (strcmp(quadrupla[i].getResultado(), quadrupla[j].getArgumento1()) == 0)
                {
                    quadrupla[j].setArq1(quadrupla[i].getArgumento1());
                    removerLines.push_back(i);
                    break;
                }
                else if (strcmp(quadrupla[i].getResultado(), quadrupla[j].getArgumento2()) == 0)
                {
                    quadrupla[j].setArq2(quadrupla[i].getArgumento1());
                    removerLines.push_back(i);
                    break;
                }
            }
        }
    }

    // remover dados depois da otimização
    for (int i = 0; i < removerLines.size(); i++)
    {
        quadrupla.erase(quadrupla.begin() + removerLines[i]);
        
        for (int j = i + 1; j < removerLines.size(); j++)
        {
            removerLines[j]--;
        }
    }

    printCodifoOtimizado();
}

void printCodifoOtimizado()
{
    cout << "\nCODIGO OTIMIZADO\n"
         << endl;
    for (int i = 0; i < quadrupla.size(); i++)
    {
        cout << quadrupla[i].getResultado() << " " << quadrupla[i].getArgumento1() << " " << quadrupla[i].getOperador() << " " << quadrupla[i].getArgumento2() << endl;
    }
}