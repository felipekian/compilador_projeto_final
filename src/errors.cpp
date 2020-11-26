#include <bits/stdc++.h>
#include <stdlib.h>

#include "errors.h"

using namespace std;

void error_file_not_information()
{
    cout << "\nInforme o nome do arquivo com extensão .txt\n"
         << endl;
}

void error_extension_invalid()
{
    cout << "\nO arquivo informado é inválido.\nEle deve possuir a extensão .txt para ser analisado\n"
         << endl;
}

void error_not_extends_params()
{
    cout << "\nForam informado parametros inválidos" << endl;
    error_file_not_information();
}

void error_file_not_found()
{
    cout << "\nArquivo informado não foi encontrado\n"
         << endl;
}

void error_letter_not_gramatical(char c, char *currentWord, int line)
{
    cout << "\nErro lexico: Caractere não pertencente a gramática: " << endl;
    cout << "Linha: " << line << endl;
    cout << "Caractere: " << c << endl;
    cout << "Palavra Invalida: " << currentWord << endl;
}