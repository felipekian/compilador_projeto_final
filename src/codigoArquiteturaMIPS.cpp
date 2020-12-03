/**
 * 
 * GERAÇÃO DE CÓDIGO NA ARQUITETURA MIPS
 * Autor: Felipe Derkian
 * Data: 1/12/2020
 * 
 */

#include <bits/stdc++.h>

#include "codigoArquiteturaMIPS.h"

using namespace std;

// fila para o processamento das instruções para gerar o código final
queue<CodigoMIPS> tabela_arquitetura_MIPS;

// add o código gerado para transformar para MIPS
void setInstrucoesOtimizadasGeracaoCodigoMIPS(char *resultado, char *operador, char *argumento1, char *argumento2)
{
    CodigoMIPS instrucaoMIPS;
    instrucaoMIPS.setInstrucao(operador, resultado, argumento1, argumento2);
    tabela_arquitetura_MIPS.push(instrucaoMIPS);
}

// processa a fila de instruções
void gerarArquivoFinalMIPS()
{

    // cout << "GERANDO ARQUIVO FINAL ARQUITETURA 4 ENDERECOS" << endl;

    FILE *f = NULL;
    char nameFile[30] = "MIPS.txt";
    f = fopen(nameFile, "w");

    fprintf(f, "%s", "## FELIPE DERKIAN - COMPILER EXPRESSIONS - ARQUITETURA MIPS ##\n\n");

    fprintf(f, "%s", ".TEXT\n");

    while (!tabela_arquitetura_MIPS.empty())
    {
        if (strcmp(tabela_arquitetura_MIPS.front().getOperador(), "mult") == 0 ||
            strcmp(tabela_arquitetura_MIPS.front().getOperador(), "div") == 0)
        {
            fprintf(f, "%s %s, %s\n", "li", tabela_arquitetura_MIPS.front().getResultado(), tabela_arquitetura_MIPS.front().getArg1());

            fprintf(f, "%s %s, %s\n", tabela_arquitetura_MIPS.front().getOperador(), tabela_arquitetura_MIPS.front().getResultado(), tabela_arquitetura_MIPS.front().getArg2());
        }
        else
        {

            fprintf(f, "%s %s, %s, %s\n", tabela_arquitetura_MIPS.front().getOperador(),
                    tabela_arquitetura_MIPS.front().getResultado(),
                    tabela_arquitetura_MIPS.front().getArg1(),
                    tabela_arquitetura_MIPS.front().getArg2());
        }
        tabela_arquitetura_MIPS.pop();
    }

    fclose(f);
}
