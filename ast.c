#include <stdlib.h>
#include "ast.h"

extern int linea; 

Nodo *crearNodo(TipoNodo tipo, Nodo *a, Nodo *b, Nodo *c, Nodo *d) {
    Nodo *n = calloc(1, sizeof(Nodo));
    n->tipo = tipo;
    n->linea = linea;
    n->a = a; n->b = b; n->c = c; n->d = d;
    return n;
}

/* En int linea, la linea la define el .l 
que es calloc? se usa para que deje todo en 0, en otras palabras,
si no se usa un hijo del arbol sya se vuelve NULL sin que tengamos que configurar algo 
n ->linea = linea sirve para guardar en cada nodo en que linea estaba, o sea, para que diga:
variable tal no esta declarada en la linea tal
*/ 
