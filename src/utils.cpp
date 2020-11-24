#include <bits/stdc++.h>
#include "menu.h"
#include "utils.h"

using namespace std;

void limpar_tela()
{
    system("cls");
}

void pausar_sistema()
{
    cout << ">> precione para continuar...";
    getchar();
}

void error_arquivo()
{
    cout << "\n\n----------------------- COMPILER EXPRESS -----------------------\n" << endl;
    cout << " >> Informe no paramentro o nome do arquivo com extensao .ce" << endl;
    cout << "\n----------------------------------------------------------------\n" << endl;
}

int validar_nome_arquivo(char *arquivo)
{
    int t_arq = strlen(arquivo);

    if (!(arquivo[t_arq - 3] == '.' &&
          arquivo[t_arq - 2] == 'c' &&
          arquivo[t_arq - 1] == 'e'))
    {
        return FALSE;
    }

    return TRUE;
}