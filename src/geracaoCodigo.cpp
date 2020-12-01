/**
 * 
 * Geração de código
 * Autor: Felipe Derkian
 * Data: 30/11/2020 
 * 
 */

#include <bits/stdc++.h>

#include "geracaoCodigo.h"
#include "codigoArquiteturaMIPS.h"

using namespace std;

vector<TokensGeracaoCodigo> quadrupla;
vector<int> removerLines;

void setDataTokenGeracaoCodigo(char *resultado, char *operador, char *argumento1, char *argumento2)
{
    TokensGeracaoCodigo tokengeracao;
    tokengeracao.setToken(operador, resultado, argumento1, argumento2);
    quadrupla.push_back(tokengeracao);
}

void insertRemove(int v)
{

    for (int i = 0; i < removerLines.size(); i++)
    {
        if (removerLines[i] == v)
            return;
    }

    removerLines.push_back(v);
}

/**
 * 
 * da quadrupla tem que otimizar o código bruto geral em uma funçao para otimizar
 * 
 */
void otimizationGenerationCode()
{
    // cout << "Gerando otimização de codigo" << endl;

    for (int i = 0; i < quadrupla.size() - 1; i++)
    {
        if (strcmp(quadrupla[i].getArgumento2(), "") == 0 && strcmp(quadrupla[i].getOperador(), ":=") == 0)
        {
            for (int j = i + 1; j < quadrupla.size(); j++)
            {
                if (strcmp(quadrupla[i].getResultado(), quadrupla[j].getArgumento1()) == 0)
                {
                    quadrupla[j].setArq1(quadrupla[i].getArgumento1());
                    insertRemove(i);
                }
                else if (strcmp(quadrupla[i].getResultado(), quadrupla[j].getArgumento2()) == 0)
                {
                    quadrupla[j].setArq2(quadrupla[i].getArgumento1());
                    insertRemove(i);
                }
            }
        }
    }
}

void printCodifoOtimizado()
{
    // cout << "\nCODIGO OTIMIZADO GERADO" << endl;

    for (int i = 0; i < quadrupla.size(); i++)
    {
        bool imprimir = true;
        for (int j = 0; j < removerLines.size(); j++)
        {
            if (removerLines[j] == i)
            {
                imprimir = false;
                break;
            }
        }

        if (imprimir == true)
            cout << quadrupla[i].getResultado() << " " << quadrupla[i].getArgumento1() << " " << quadrupla[i].getOperador() << " " << quadrupla[i].getArgumento2() << endl;
    }
}

void injetarCodigoParaArquiteturaMIPS()
{
    // cout << "\nINJETANDO O CODIGO OTIMIZADO\n" << endl;

    for (int i = 0; i < quadrupla.size(); i++)
    {
        bool injectCode = true;
        for (int j = 0; j < removerLines.size(); j++)
        {
            if (removerLines[j] == i)
            {
                injectCode = false;
                break;
            }
        }

        if (injectCode == true)
        {
            setInstrucoesOtimizadasGeracaoCodigoMIPS(quadrupla[i].getResultado(), quadrupla[i].getOperador(), quadrupla[i].getArgumento1(), quadrupla[i].getArgumento2());
        }
    }

    gerarArquivoFinalMIPS();
}