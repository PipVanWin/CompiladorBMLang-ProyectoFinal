#ifndef AST_H
#define AST_H

typedef enum {
    N_PROGRAMA, N_SENTENCIAS, N_DECLARACION, N_ASIGNACION,
    N_READ, N_WRITE, N_IF, N_WHILE, N_FOR,
    N_OR, N_AND, N_COMPARACION,
    N_OPBIN, N_NEGACION, N_NUMERO, N_VARIABLE
} TipoNodo;

typedef struct Nodo {
    TipoNodo tipo;
    int linea;
    int valor;
    char *nombre;
    int op;
    struct Nodo *a, *b, *c, *d;
    struct Nodo *sig;
} Nodo;

Nodo *crearNodo(TipoNodo tipo, Nodo *a, Nodo *b, Nodo *c, Nodo *d);

#endif

/* Todo esto hace que el archivo no se incluya dos veces y pueda dar error 
de redefinicion, se incluye en el .y, en el .c 
*/
