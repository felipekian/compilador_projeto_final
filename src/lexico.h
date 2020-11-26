/**
 * 
 * Analisador Léxico
 * 
 */


#define TK_ATRIBUITE 0
#define TK_CONST_FLOAT 1
#define TK_CONST_INT 2
#define TK_ID 3
#define TK_OPERATION 4
#define TK_FINAL_EXPRESSION 5


void analisadorLexico();

void setListTokens(char* word, int type);

bool isSpace(char c);

bool isBreakLine(char c);

bool isCaractere(char c);

bool isNumber(char c);

bool isOperator(char c);

bool isBar(char c);

bool isDot(char c);

bool isDubleDot(char c);

bool isIquals(char c);

bool isFinalExpression(char c);

