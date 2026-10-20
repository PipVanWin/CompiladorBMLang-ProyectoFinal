%code requires {
#include "ast.h"
}

%{
#include <stdio.h>

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

%type <nodo> expresion termino potenciacion factor

%%

inicio : MAIN LLAVE_ABRIR bloque LLAVE_CERRAR { printf("Cadena valida\n"); }
       ;

bloque : sentencia otraSentencia
       ;

otraSentencia : sentencia otraSentencia
              | vacio
              ;

sentencia : opciones PUNTOYCOMA
          | condicional
          | mientras
          | para
          ;

opciones : declaracion
         | lectura
         | escritura
         | asignacion
         ;

declaracion : DEC IDENTIFICADOR otraVariable
            ;

otraVariable : COMA IDENTIFICADOR otraVariable
             | vacio
             ;

lectura : READ IDENTIFICADOR
        ;

escritura : WRITE IDENTIFICADOR
          ;

asignacion : IDENTIFICADOR ASIGNACION expresion { printf("%s =>\n", $1); imprimirArbol($3, 1); }
           ;

condicional : IF PARENTESIS_ABRIR condicion PARENTESIS_CERRAR LLAVE_ABRIR bloque LLAVE_CERRAR otroElse
            ;

otroElse : ELSE LLAVE_ABRIR bloque LLAVE_CERRAR
         | ELSE condicional
         | vacio
         ;

mientras : WHILE PARENTESIS_ABRIR condicion PARENTESIS_CERRAR LLAVE_ABRIR bloque LLAVE_CERRAR
         ;

para : FOR PARENTESIS_ABRIR asignacion PUNTOYCOMA condicion PUNTOYCOMA asignacion PARENTESIS_CERRAR LLAVE_ABRIR bloque LLAVE_CERRAR
     ;

condicion : conjuncion otraCondicion
          ;

otraCondicion : OR conjuncion otraCondicion
              | vacio
              ;

conjuncion: comparacion otraConjuncion
              ;

otraConjuncion : AND comparacion otraConjuncion
              | vacio
              ;

comparacion : expresion operador expresion
            ;

operador : MENOR
         | MAYOR
         | MENORIGUAL
         | MAYORIGUAL
         | IGUAL
         | DIFERENTE
         ;

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
       ;

vacio : ;

%%

int main(){
    return yyparse();
}

void yyerror(char *mensaje){
    if(yychar == INVALIDO){
        printf("Error lexico en linea %d: %s\n", linea, yytext);
    }else{
        printf("Error de sintaxis en linea %d, cerca de: %s\n", linea, yytext);
    }
}
