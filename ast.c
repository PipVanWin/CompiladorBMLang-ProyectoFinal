#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int linea; 

Nodo *raiz = NULL;

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

Nodo *nodoComparacion*(int op, Nodo *izq, Nodo *der) {
    Nodo *n = crearNodo(N_COMPARACION, izq, der, NULL, NULL);
    n ->op = op;
    return n;
}
static const char *nombreOpRel[] = { "<", ">", "<=", ">=", "==", "<>" };
 
static void sangria(int nivel) {
    for (int i = 0; i < nivel; i++) printf("  ");
}
 
static void hijo(const char *etiqueta, Nodo *h, int nivel) {
    if (h == NULL) return;
    sangria(nivel);
    printf("%s:\n", etiqueta);
    imprimirArbol(h, nivel + 1);
}
 
void imprimirArbol(Nodo *n, int nivel) {
    for (; n != NULL; n = n->sig) {      /* recorre toda la lista */
        sangria(nivel);
        switch (n->tipo) {
            case N_PROGRAMA:    printf("Programa\n");
                                imprimirArbol(n->a, nivel + 1); break;
            case N_DECLARACION: printf("Declaracion\n");
                                imprimirArbol(n->a, nivel + 1); break;
            case N_ASIGNACION:  printf("Asignacion\n");
                                imprimirArbol(n->a, nivel + 1);
                                imprimirArbol(n->b, nivel + 1); break;
            case N_READ:        printf("Read\n");
                                imprimirArbol(n->a, nivel + 1); break;
            case N_WRITE:       printf("Write\n");
                                imprimirArbol(n->a, nivel + 1); break;
            case N_IF:          printf("If\n");
                                hijo("condicion", n->a, nivel + 1);
                                hijo("cuerpo",    n->b, nivel + 1);
                                hijo("else",      n->c, nivel + 1); break;
            case N_WHILE:       printf("While\n");
                                hijo("condicion", n->a, nivel + 1);
                                hijo("cuerpo",    n->b, nivel + 1); break;
            case N_FOR:         printf("For\n");
                                hijo("inicio",    n->a, nivel + 1);
                                hijo("condicion", n->b, nivel + 1);
                                hijo("paso",      n->c, nivel + 1);
                                hijo("cuerpo",    n->d, nivel + 1); break;
            case N_OR:          printf("Or\n");
                                imprimirArbol(n->a, nivel + 1);
                                imprimirArbol(n->b, nivel + 1); break;
            case N_AND:         printf("And\n");
                                imprimirArbol(n->a, nivel + 1);
                                imprimirArbol(n->b, nivel + 1); break;
            case N_COMPARACION: printf("Comparacion(%s)\n", nombreOpRel[n->op]);
                                imprimirArbol(n->a, nivel + 1);
                                imprimirArbol(n->b, nivel + 1); break;
            case N_OPBIN:       printf("Op(%c)\n", n->op);
                                imprimirArbol(n->a, nivel + 1);
                                imprimirArbol(n->b, nivel + 1); break;
            case N_NEGACION:    printf("Negacion\n");
                                imprimirArbol(n->a, nivel + 1); break;
            case N_NUMERO:      printf("Numero(%d)\n", n->valor); break;
            case N_VARIABLE:    printf("Variable(%s)\n", n->nombre); break;
        }
    }
}

/* En int linea, la linea la define el .l 
que es calloc? se usa para que deje todo en 0, en otras palabras,
si no se usa un hijo del arbol sya se vuelve NULL sin que tengamos que configurar algo 
n ->linea = linea sirve para guardar en cada nodo en que linea estaba, o sea, para que diga:
variable tal no esta declarada en la linea tal
*/ 
