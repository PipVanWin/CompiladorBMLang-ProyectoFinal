%code requires {
#include "ast.h"
}

%{
#include <stdio.h>
#include <string.h>
#include "tac.h"

int yylex();
void yyerror(char *mensaje);
extern int linea;
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
               printf("Cadena valida\n");
           }
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

vacio : ;

%%

int main(int argc, char **argv){
    int r = yyparse();
    if (r != 0) return r;
    if (argc > 1 && strcmp(argv[1], "--ast") == 0) {
        imprimirArbol(raiz, 0);
    } else if (argc > 1 && strcmp(argv[1], "--tac") == 0) {
        return generarTAC(raiz, stdout);
    }
    return 0;
}

void yyerror(char *mensaje){
    if(yychar == INVALIDO){
        printf("Error lexico en linea %d: %s\n", linea, yytext);
    }else{
        printf("Error de sintaxis en linea %d, cerca de: %s\n", linea, yytext);
    }
}
