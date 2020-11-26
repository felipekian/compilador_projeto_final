/**
 * 
 *  Arquivo com as mensagens de erros
 * 
 */

// erro lançado quando o usuário não informa o nome do arquivo
void error_file_not_information();

// erro lançado quando o usuário não informa a extensão do arquivo 
void error_extension_invalid();

// erro lançado quando o usuário informa parametros não esperados
void error_not_extends_params();

// erro lançado quando o usuário informa um arquivo não encontrado
void error_file_not_found();

// erro de caractere não pertencente a gramática
void error_letter_not_gramatical(char c, char* currentWord, int line);
