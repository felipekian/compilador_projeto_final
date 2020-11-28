/**
 * 
 * Analisador Sintático - CompilerExpressions
 * Autor: Felipe Derkian
 * Disciplina de Compiladores
 * Data: 29/11/2020
 * 
 */


/**
 * 
 * Gramática G
 * 
 * E  -> T' I (E OP T | T) FE
 * T' -> id
 * T  -> id | numero
 * OP -> + | - | * | /
 * I  -> :=
 * FE -> ;
 * 
 * 
 * 
 * Gramática G' LL(1)
 * 
 * 1) E  -> T' I T E' FE
 * 2) E' -> OP T E'
 * 3) T  -> id | numero
 * 4) OP -> + | - | * | /
 * 5) T' -> id
 * 6) I  -> :=
 * 7) FE -> ;
 * 
 */


void E();

void TL();

void I();

void T();

void EL();

void FE();

void OP();

