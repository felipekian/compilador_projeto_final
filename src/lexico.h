/**
 * 
 * Analisador Léxico
 * 
 */


#define TK_ATRIBUITE 0
#define TK_CONST 1
#define TK_ID 2
#define TK_OPERARION 3
#define TK_FINAL_EXPRESSION 4


void analisadorLexico();

void setListTokens(char* word, int type);

void setListTokens(char *word, int type);

bool isSimbolFormatatiton(char c);

bool isBreakLine(char c);

bool isCaractere(char c);

bool isNumber(char c);

bool isOperator(char c);

bool isDot(char c);

bool isDubleDot(char c);

bool isIquals(char c);

bool isFinalExpression(char c);

