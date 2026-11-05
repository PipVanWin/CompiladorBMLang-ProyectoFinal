#ifndef TAC_H
#define TAC_H
 
#include <stdio.h>
#include "ast.h"
 
/* Verifica las variables del programa y escribe su codigo de tres direcciones
   en salida. Devuelve 0 si todo salio bien, o 1 si hubo errores semanticos
   (en ese caso se reportan con su linea y no se escribe nada en salida). */
int generarTAC(Nodo *programa, FILE *salida);
 
#endif
 
