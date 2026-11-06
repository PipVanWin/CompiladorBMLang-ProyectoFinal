%code requires {
#include "ast.h"
}

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tac.h"
#include "nasm.h"

int yylex();
void yyerror(char *mensaje);
extern int linea;
extern int registrarTokens;
extern char *yytext;
extern int yychar;

%}

%union {
    int valor;
    char *nombre;
    Nodo *nodo;
}

%token MAIN DEC READ WRITE IF ELSE WHILE FOR
%token <nombre> IDENTIFICADOR
%token <valor> NUMERO
%token MENORIGUAL MAYORIGUAL IGUAL DIFERENTE
%token AND OR MENOR MAYOR MAS MENOS POR DIVIDIR POTENCIA
%token PARENTESIS_ABRIR PARENTESIS_CERRAR LLAVE_ABRIR LLAVE_CERRAR COMA PUNTOYCOMA INVALIDO ASIGNACION

%type <nodo> bloque otraSentencia sentencia opciones
%type <nodo> declaracion otraVariable lectura escritura asignacion
%type <nodo> condicional otroElse mientras para
%type <nodo> condicion conjuncion comparacion
%type <nodo> expresion termino potenciacion factor
%type <valor> operador

%%

inicio : MAIN LLAVE_ABRIR bloque LLAVE_CERRAR
           {
               raiz = crearNodo(N_PROGRAMA, $3, NULL, NULL, NULL);
           }
       ;

/* Bloque: lista de sentencias enlazadas con sig */
bloque : sentencia otraSentencia   { $1->sig = $2; $$ = $1; }
       ;

otraSentencia : sentencia otraSentencia   { $1->sig = $2; $$ = $1; }
              | vacio                     { $$ = NULL; }
              ;

sentencia : opciones PUNTOYCOMA   { $$ = $1; }
          | condicional           { $$ = $1; }
          | mientras              { $$ = $1; }
          | para                  { $$ = $1; }
          ;

opciones : declaracion   { $$ = $1; }
         | lectura       { $$ = $1; }
         | escritura     { $$ = $1; }
         | asignacion    { $$ = $1; }
         ;

declaracion : DEC IDENTIFICADOR otraVariable
                {
                    Nodo *v = nodoVariable($2);
                    v->sig = $3;
                    $$ = crearNodo(N_DECLARACION, v, NULL, NULL, NULL);
                }
            ;

otraVariable : COMA IDENTIFICADOR otraVariable
                 {
                     Nodo *v = nodoVariable($2);
                     v->sig = $3;
                     $$ = v;
                 }
             | vacio   { $$ = NULL; }
             ;

lectura : READ IDENTIFICADOR
            { $$ = crearNodo(N_READ, nodoVariable($2), NULL, NULL, NULL); }
        ;

escritura : WRITE IDENTIFICADOR
              { $$ = crearNodo(N_WRITE, nodoVariable($2), NULL, NULL, NULL); }
          ;

asignacion : IDENTIFICADOR ASIGNACION expresion
               { $$ = crearNodo(N_ASIGNACION, nodoVariable($1), $3, NULL, NULL); }
           ;

condicional : IF PARENTESIS_ABRIR condicion PARENTESIS_CERRAR LLAVE_ABRIR bloque LLAVE_CERRAR otroElse
                { $$ = crearNodo(N_IF, $3, $6, $8, NULL); }
            ;

otroElse : ELSE LLAVE_ABRIR bloque LLAVE_CERRAR   { $$ = $3; }
         | ELSE condicional                       { $$ = $2; }
         | vacio                                  { $$ = NULL; }
         ;

mientras : WHILE PARENTESIS_ABRIR condicion PARENTESIS_CERRAR LLAVE_ABRIR bloque LLAVE_CERRAR
             { $$ = crearNodo(N_WHILE, $3, $6, NULL, NULL); }
         ;

para : FOR PARENTESIS_ABRIR asignacion PUNTOYCOMA condicion PUNTOYCOMA asignacion PARENTESIS_CERRAR LLAVE_ABRIR bloque LLAVE_CERRAR
         { $$ = crearNodo(N_FOR, $3, $5, $7, $10); }
     ;

condicion : condicion OR conjuncion   { $$ = crearNodo(N_OR, $1, $3, NULL, NULL); }
          | conjuncion                { $$ = $1; }
          ;

conjuncion : conjuncion AND comparacion   { $$ = crearNodo(N_AND, $1, $3, NULL, NULL); }
           | comparacion                  { $$ = $1; }
           ;

comparacion : expresion operador expresion
                { $$ = nodoComparacion($2, $1, $3); }
            | PARENTESIS_ABRIR condicion PARENTESIS_CERRAR
                { $$ = $2; }   /* condicion agrupada: IF (($a == 1) && ($b == 2)) */
            ;

operador : MENOR        { $$ = OP_MENOR; }
         | MAYOR        { $$ = OP_MAYOR; }
         | MENORIGUAL   { $$ = OP_MENORIGUAL; }
         | MAYORIGUAL   { $$ = OP_MAYORIGUAL; }
         | IGUAL        { $$ = OP_IGUAL; }
         | DIFERENTE    { $$ = OP_DIFERENTE; }

expresion : expresion MAS termino      { $$ = nodoOp('+', $1, $3); }
          | expresion MENOS termino    { $$ = nodoOp('-', $1, $3); }
          | termino                    { $$ = $1; }
          ;

termino : termino POR potenciacion     { $$ = nodoOp('*', $1, $3); }
        | termino DIVIDIR potenciacion { $$ = nodoOp('/', $1, $3); }
        | potenciacion                 { $$ = $1; }
        ;

potenciacion : factor POTENCIA potenciacion { $$ = nodoOp(':', $1, $3); }
             | factor                       { $$ = $1; }
             ;

factor : IDENTIFICADOR   { $$ = nodoVariable($1); }
       | NUMERO          { $$ = nodoNumero($1); }
       | MENOS factor    { $$ = crearNodo(N_NEGACION, $2, NULL, NULL, NULL); }
       | PARENTESIS_ABRIR expresion PARENTESIS_CERRAR { $$ = $2; }

vacio : %empty ;

%%

 /* Entrada del programa y mensajes de error */

/* Todo el programa fuente. Lo guardamos entero para poder mostrar,
   cuando hay un error, el texto de la linea donde ocurrio. */
static char *fuente = NULL;

/* Funcion de Flex que hace que el lexer lea de un texto en memoria
   en lugar de leer directamente de la entrada estandar. */
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char *cadena);

static char *leerTodo(FILE *f) {
    size_t capacidad = 4096, n = 0, leidos;
    char *buf = malloc(capacidad);
    while ((leidos = fread(buf + n, 1, capacidad - n - 1, f)) > 0) {
        n += leidos;
        if (capacidad - n < 2) {            /* poco espacio: duplicar */
            capacidad *= 2;
            buf = realloc(buf, capacidad);
        }
    }
    buf[n] = '\0';
    return buf;
}

/* Devuelve el texto de la linea n (la primera es la 1), sin salto de linea. */
static const char *textoLinea(int n) {
    static char buf[512];
    const char *p = fuente;
    int i = 0;
    if (p == NULL || n < 1) return "";
    while (--n > 0) {                        /* avanzar hasta la linea n */
        p = strchr(p, '\n');
        if (p == NULL) return "";
        p++;
    }
    while (p[i] != '\0' && p[i] != '\n' && p[i] != '\r' && i < (int)sizeof(buf) - 1) {
        buf[i] = p[i];
        i++;
    }
    buf[i] = '\0';
    return buf;
}

static void mostrarLinea(int n) {
    printf("  %4d | %s\n", n, textoLinea(n));
}

/* Ultima linea con codigo antes de la linea n (ignora lineas vacias y
   comentarios). Devuelve 0 si no hay ninguna. */
static int lineaPrevia(int n) {
    for (int i = n - 1; i >= 1; i--) {
        const char *t = textoLinea(i);
        while (*t == ' ' || *t == '\t') t++;
        if (*t != '\0' && strncmp(t, "#!", 2) != 0) return i;
    }
    return 0;
}

/* Ultimo caracter de una linea, sin contar espacios ni un comentario #! ... !# */
static char ultimoCaracter(const char *t) {
    int largo = (int)strlen(t);
    const char *comentario = strstr(t, "#!");
    if (comentario != NULL) largo = (int)(comentario - t);
    while (largo > 0 && (t[largo - 1] == ' ' || t[largo - 1] == '\t')) largo--;
    return largo > 0 ? t[largo - 1] : '\0';
}

/* Verdadero si el token con el que fallo el parser es lo primero de su linea. */
static int primeroEnLinea(int n, const char *token) {
    const char *t = textoLinea(n);
    while (*t == ' ' || *t == '\t') t++;
    return strncmp(t, token, strlen(token)) == 0;
}

/* Cuando el error aparece al inicio de una linea, casi siempre la causa
   esta al final de la linea anterior: falta un ';' o una '{'. */
static void sugerencia(int lineaError) {
    int p = lineaPrevia(lineaError);
    char copia[512];
    const char *inicio;
    char ultimo;
    int esControl;

    if (p == 0) return;
    strncpy(copia, textoLinea(p), sizeof(copia) - 1);
    copia[sizeof(copia) - 1] = '\0';
    ultimo = ultimoCaracter(copia);
    if (ultimo == ';' || ultimo == '{' || ultimo == '}') return;   /* termino bien */

    inicio = copia;
    while (*inicio == ' ' || *inicio == '\t') inicio++;
    esControl = strncmp(inicio, "IF", 2) == 0 || strncmp(inicio, "WHILE", 5) == 0
             || strncmp(inicio, "FOR", 3) == 0;

    if (ultimo == ')' && esControl) {
        printf("Sugerencia: puede faltar '{' al final de la linea %d\n", p);
        mostrarLinea(p);
    } else if (isalnum((unsigned char)ultimo) || ultimo == ')') {
        printf("Sugerencia: puede faltar ';' al final de la linea %d\n", p);
        mostrarLinea(p);
    }
}

int main(int argc, char **argv){
    const char *archivo = NULL;
    int verArbol = 0, verTAC = 0;
    int verNASM = 0;
    FILE *entrada = stdin;
    int r;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--ast") == 0) {
            verArbol = 1;
        } else if (strcmp(argv[i], "--tac") == 0) {
            verTAC = 1;
        } else if (strcmp(argv[i], "--nasm") == 0) {
            verNASM = 1;
        } else {
            archivo = argv[i];
        }
}

    if (archivo != NULL) {
        entrada = fopen(archivo, "rb");
        if (entrada == NULL) {
            printf("No se pudo abrir el archivo %s\n", archivo);
            return 2;
        }
    }
    fuente = leerTodo(entrada);
    if (entrada != stdin) fclose(entrada);

    yy_scan_string(fuente);                 
    r = yyparse();
    if (r != 0) return r;
    if (verNASM) {
    return generarNASM(raiz);
    return 0;
   
}

        if (!verArbol && !verTAC) printf("Cadena valida\n");

if (verArbol) {
    imprimirArbol(raiz, 0);   /* modo --ast: lo usa la pestana AST del IDE */
}

if (verTAC) {
    return generarTAC(raiz, stdout);
}



return 0;

   
}

/* Bison llama a esta funcion cuando el programa no sigue la gramatica.
   yychar es el token con el que fallo, yytext su texto y linea la linea actual. */
void yyerror(char *mensaje){
    (void)mensaje;
    if (yychar == INVALIDO) {
        printf("Error lexico en linea %d: caracter no reconocido '%s'\n", linea, yytext);
        mostrarLinea(linea);
    } else if (yychar == YYEOF) {
        int ultima = lineaPrevia(linea + 1);
        if (ultima == 0) {
            printf("Error de sintaxis: el programa esta vacio o incompleto\n");
        } else {
            printf("Error de sintaxis en linea %d: el programa termino antes de tiempo "
                   "(falta cerrar un '}' o un ')')\n", ultima);
            mostrarLinea(ultima);
        }
    } else {
        printf("Error de sintaxis en linea %d: no se esperaba '%s'\n", linea, yytext);
        mostrarLinea(linea);
        if (primeroEnLinea(linea, yytext)) sugerencia(linea);
    }
}
