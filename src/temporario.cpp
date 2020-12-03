/**
 * 
 * GERA AS VARIÁVEIS TEMPORARIAS PARA GERAÇÂO DE CÓDIGO
 * Autor: Felipe Derkian
 * Data: 30/11/2020
 * 
 */

#include <bits/stdc++.h>

#include "temporario.h"

using namespace std;

int contTemp = 0;
char temp[10];
char str_int[10];


char *getNextTemp()
{
    strcpy(temp, "$");
    sprintf(str_int, "%d", contTemp);
    strcat(temp, str_int);
    contTemp++; 
    return temp;
}