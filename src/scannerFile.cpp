#include <bits/stdc++.h>
#include <string.h>

#include "scannerFile.h"
#include "errors.h"

using namespace std;


#define TAM_FILE_NAME 100 

//nome do arquivo informado
char fileName[TAM_FILE_NAME] = "";

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
    return true;
}