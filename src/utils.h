
#define TRUE 1
#define FALSE 0
#define TAM_FILE 200

/**
 *  limpa a tela da aplicação
 */
void limpar_tela();

/**
 * pausa o programa
 */
void pausar_sistema();


/**
 * mostrar error do arquivo informado
 */
void error_arquivo();

/**
 *  validar nome do arquivo passado como parametro
 */
int validar_nome_arquivo(char *arquivo);