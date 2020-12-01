/**
 * 
 * Geração de código
 * Autor: Felipe Derkian
 * Data: 30/11/2020 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

class TokensGeracaoCodigo
{
private:
    char operador[10];
    char result[200];
    char arg1[200];
    char arg2[200];

public:
    TokensGeracaoCodigo()
    {
        strcpy(this->operador, "");
        strcpy(this->result, "");
        strcpy(this->arg1, "");
        strcpy(this->arg2, "");
    }

    void setToken(char *operador, char *resultado, char *argumento1, char *argumento2)
    {
        strcpy(this->operador, operador);
        strcpy(this->result, resultado);
        strcpy(this->arg1, argumento1);
        strcpy(this->arg2, argumento2);
    }

    char *getOperador()
    {
        return this->operador;
    }

    char *getResultado()
    {
        return this->result;
    }

    char *getArgumento1()
    {
        return this->arg1;
    }

    char *getArgumento2()
    {
        return this->arg2;
    }

    void setArq1(char *arg)
    {
        strcpy(this->arg1, arg);
    }

    void setArq2(char *arg)
    {
        strcpy(this->arg2, arg);
    }
};

void setDataTokenGeracaoCodigo(char *resultado, char *operador, char *argumento1, char *argumento2);

void geracaoDeCodigo();

void otimizationGenerationCode();

void printCodifoOtimizado();

void injetarCodigoParaArquiteturaMIPS();
