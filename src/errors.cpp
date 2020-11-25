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