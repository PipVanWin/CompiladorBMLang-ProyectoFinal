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

Nodo *nodoNumero(int valor) {
    Nodo *n = crearNodo(N_NUMERO, NULL, NULL, NULL, NULL);
    n->valor = valor;
    return n;
}

Nodo *nodoVariable(char *nombre) {
    Nodo *n = crearNodo(N_VARIABLE, NULL, NULL, NULL, NULL);
    n->nombre = nombre;
    return n;
}

Nodo *nodoOp(int op, Nodo *izq, Nodo *der) {
    Nodo *n = crearNodo(N_OPBIN, izq, der, NULL, NULL);
    n->op = op;
    return n;
}

void imprimirArbol(Nodo *n, int nivel) {
    if (n == NULL) return;
    for (int i = 0; i < nivel; i++) printf("  ");
    switch (n->tipo) {
        case N_NUMERO:   printf("Numero(%d)\n", n->valor); break;
        case N_VARIABLE: printf("Variable(%s)\n", n->nombre); break;
        case N_NEGACION: printf("Negacion\n"); break;
        case N_OPBIN:    printf("Op(%c)\n", n->op); break;
        default:         printf("Nodo(tipo %d)\n", n->tipo); break;
    }
    imprimirArbol(n->a, nivel + 1);
    imprimirArbol(n->b, nivel + 1);
    imprimirArbol(n->c, nivel + 1);
    imprimirArbol(n->d, nivel + 1);
}

/* En int linea, la linea la define el .l 
que es calloc? se usa para que deje todo en 0, en otras palabras,
si no se usa un hijo del arbol sya se vuelve NULL sin que tengamos que configurar algo 
n ->linea = linea sirve para guardar en cada nodo en que linea estaba, o sea, para que diga:
variable tal no esta declarada en la linea tal
*/ 
