/**
 * 
 * Analisador Léxico
 * 
 */


#define TK_ATRIBUITE        0
#define TK_NUMBER           1
#define TK_ID               2
#define TK_OPERATION        3
#define TK_FINAL_EXPRESSION 4


#define INVALID_TOKEN -1

void getNameTypeLexema(int identifyToken);

void print_lexemas();

void analisadorLexico();

void setListTokens(char* word, int type, int linha);

void back();

void copy_current();

void clear_current();

bool eof_file(char c);

bool isSpace(char c);

bool isBreakLine(char c);

bool isChar(char c);

bool isNumber(char c);

bool isOperator(char c);

bool isBar(char c);

bool isDot(char c);

bool isDubleDot(char c);

bool isIquals(char c);

bool isFinalExpression(char c);

