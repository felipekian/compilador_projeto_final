#include <bits/stdc++.h>

#include "semantica.h"

using namespace std;


void setTokenParaAnaliseSemantica(char *lexema, int type, int line)
{
    TokenSematica t;

    t.setToken(lexema, type, line);

    cout << "SEMANTICA: " << t.getLexema() << endl;
}

bool analiseSemantica();