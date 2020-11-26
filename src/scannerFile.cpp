#include <bits/stdc++.h>
#include <string.h>

#include "scannerFile.h"
#include "errors.h"

using namespace std;


//nome do arquivo informado
char fileName[100] = "";

// armazena os caracteres lidos para serem analisados sob demanda
queue <char> fila_caracteres;


bool setNameFile(const char *file)
{
    int tam_file_name = strlen(file);

    if(!(file[tam_file_name - 4] == '.' &&
            file[tam_file_name - 3] == 't' &&
            file[tam_file_name - 2] == 'x' &&
            file[tam_file_name - 1] == 't'))
        {
            error_extension_invalid();
            return false;
        }

    strcpy(fileName, file);

    read_file();
    return true;
}



void read_file()
{
    FILE *arq = fopen(fileName, "r");
    char c;
    
    if(!arq){
        error_file_not_found();
        exit(EXIT_FAILURE);
        
    }

    while (!feof(arq))
    {
        fscanf(arq, "%c" , &c);
        fila_caracteres.push(c);
    }
    fila_caracteres.push('\0');

    fclose(arq);
}

char getNextChar()
{
    char c = fila_caracteres.front();
    fila_caracteres.pop();
    return c;
}

