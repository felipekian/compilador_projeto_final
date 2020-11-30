#include <bits/stdc++.h>

using namespace std;

class TokenSematica
{
public:
    int type;
    int line;
    char lexema[200];

    TokenSematica()
    {
        strcpy(this->lexema, "");
        this->type = -1;
        this->line = -1;
    }

    void setToken(char *lexema, int type, int line)
    {
        this->line = line;
        this->type = type;
        strcpy(this->lexema, lexema);
    }

    char *getLexema()
    {
        return this->lexema;
    }

    int getType()
    {
        return this->type;
    }

    int getLine()
    {
        return this->line;
    }
};


void setTokenParaAnaliseSemantica(char *lexema, int type, int line);

bool analiseSemantica();