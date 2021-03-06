#include <bits/stdc++.h>

#include "scannerFile.h"
#include "errors.h"
#include "lexico.h"
#include "sintatico.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // valida as entradas quanto a quantidade de parametros informados
    if (argc == 1)
    {
        error_file_not_information();
        exit(EXIT_FAILURE);
    }
    if (argc > 2)
    {
        error_not_extends_params();
        exit(EXIT_FAILURE);
    }
    if (!setNameFile(argv[argc - 1]))
        exit(EXIT_FAILURE);

    // Função do analisador Lexico
    analisadorLexico();

    // Analisador Sintático LL(1)
    E();

    return 0;
}
