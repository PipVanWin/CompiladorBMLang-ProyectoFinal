
#ifndef BMLANG_NASM_H
#define BMLANG_NASM_H

#include "ast.h"  /* define Nodo. */

/* Recibe el árbol del programa e imprime el código ensamblador. */
/* Devuelve 0 si pudo escribirlo o 1 si hubo un error. */
int generarNASM(Nodo *programa);

#endif