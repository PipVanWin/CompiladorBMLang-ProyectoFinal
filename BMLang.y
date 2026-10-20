%{
#include <stdio.h>

int yylex();
void yyerror(char *mensaje);
extern int linea;
extern char *yytext;
extern int yychar;
%}

%token MAIN DEC READ WRITE IF ELSE WHILE FOR
%token IDENTIFICADOR NUMERO MENORIGUAL MAYORIGUAL IGUAL DIFERENTE
%token AND OR MENOR MAYOR MAS MENOS POR DIVIDIR POTENCIA
%token PARENTESIS_ABRIR PARENTESIS_CERRAR LLAVE_ABRIR LLAVE_CERRAR COMA PUNTOYCOMA INVALIDO ASIGNACION

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
         | potencia
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

asignacion : IDENTIFICADOR ASIGNACION expresion
           ;

potencia : IDENTIFICADOR POTENCIA expresion
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

expresion : termino otraExpresion
          ;

otraExpresion : MAS termino otraExpresion
              | MENOS termino otraExpresion
              | vacio
              ;

termino : potenciacion otroTermino
        ;

otroTermino : POR potenciacion otroTermino
            | DIVIDIR potenciacion otroTermino
            | vacio
            ;

potenciacion : factor restoPotencia
             ;

restoPotencia : POTENCIA potenciacion
              | vacio
              ;

factor : IDENTIFICADOR
       | NUMERO
       | MENOS NUMERO
       | PARENTESIS_ABRIR expresion PARENTESIS_CERRAR
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
