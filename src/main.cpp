#include <bits/stdc++.h>
#include "menu.h"
#include "utils.h"

using namespace std;

char file_name[TAM_FILE] = "";



int main(int argc, char const *argv[])
{
    // caso não tenha passado o nome do arquivo.ce no parametro
    if (argc != 2)
    {
        error_arquivo();
        return EXIT_FAILURE;
    }

    // copia o nome do arquivo informado para uma variavel
    strcpy(file_name, argv[argc-1]);

    //valida se o nome do arquivo tem extensão .ce
    if(!validar_nome_arquivo(file_name)){
        error_arquivo();
        return EXIT_FAILURE;
    }
   



    return EXIT_SUCCESS;
}
