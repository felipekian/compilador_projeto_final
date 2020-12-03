/**
 * 
 * GERAÇÃO DE CÓDIGO NA ARQUITETURA MIPS
 * Autor: Felipe Derkian
 * Data: 1/12/2020
 * 
 */

#include <bits/stdc++.h>

#include "temporario.h"

using namespace std;

class CodigoMIPS
{
private:
    char resultado[200];
    char operador[200];
    char arg1[200];
    char arg2[200];
    char resp_variavel[200];

    void setOperador(char *op)
    {
        if (strcmp(op, "+") == 0)
        {
            strcpy(this->operador, "add");
        }
        else if (strcmp(op, "-") == 0)
        {
            strcpy(this->operador, "sub");
        }
        else if (strcmp(op, "*") == 0)
        {
            strcpy(this->operador, "mult");
        }
        else if (strcmp(op, "/") == 0)
        {
            strcpy(this->operador, "div");
        }
        else if (strcmp(op, ":=") == 0)
        {
            strcpy(this->operador, "addi");
        }
    }

    void setResultado(char *res)
    {
        strcpy(this->resultado, this->verificarVariavel(res));
    }

    void setArgumento1(char *arg)
    {
        strcpy(this->arg1, this->verificarVariavel(arg));
    }

    void setArgumento2(char *arg)
    {
        strcpy(this->arg2, this->verificarVariavel(arg));
    }

    char *verificarVariavel(char *v)
    {

        strcpy(this->resp_variavel, "");

        if (strlen(v) == 0)
        {
            strcpy(this->resp_variavel, "0");
        }

        else if (v[0] == '$')
        {
            strcpy(this->resp_variavel, v);
        }

        else if (v[0] >= '0' && v[0] <= '9')
        {
            strcpy(this->resp_variavel, v);
        }
        else
        {
            strcpy(this->resp_variavel, getNextTemp());
        }

        return this->resp_variavel;
    }

public:
    CodigoMIPS()
    {
        strcpy(this->arg1, "");
        strcpy(this->arg2, "");
        strcpy(this->resultado, "");
        strcpy(this->operador, "");
    }

    void setInstrucao(char op[], char res[], char arg1[], char arg2[])
    {
        this->setArgumento1(arg1);
        this->setArgumento2(arg2);
        this->setResultado(res);
        this->setOperador(op);
    }

    char *getOperador()
    {
        return this->operador;
    }

    char *getArg1()
    {

        return this->arg1;
    }

    char *getArg2()
    {
        return this->arg2;
    }

    char *getResultado()
    {
        return this->resultado;
    }
};

void setInstrucoesOtimizadasGeracaoCodigoMIPS(char *resultado, char *operador, char *argumento1, char *argumento2);

void gerarArquivoFinalMIPS();