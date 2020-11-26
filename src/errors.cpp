#include <bits/stdc++.h>
#include <stdlib.h>

#include "errors.h"

using namespace std;

void error_file_not_information()
{
    cout << "\nInforme o nome do arquivo com extensao .txt\n"
         << endl;
}

void error_extension_invalid()
{
    cout << "\nO arquivo informado e invalido.\nEle deve possuir a extensao .txt para ser analisado\n"
         << endl;
}

void error_not_extends_params()
{
    cout << "\nForam informado parametros invalidos" << endl;
    error_file_not_information();
}

void error_file_not_found()
{
    cout << "\nArquivo informado nao foi encontrado\n"
         << endl;
}

void error_letter_not_gramatical(char c, char *currentWord, int line)
{
    cout << "\nErro lexico: Caractere nao pertencente a gramatica: " << endl;
    cout << "Linha: " << line << endl;
    cout << "Caractere: " << c << endl;
    cout << "Palavra Invalida: " << currentWord << endl;
}