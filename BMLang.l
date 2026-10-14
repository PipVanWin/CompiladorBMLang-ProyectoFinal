%{
#include "BMLang.tab.h"
#include <stdio.h>

int linea = 1;
%}

%%

"MAIN"                 { return MAIN; }
"DEC"                  { return DEC; }
"READ"                 { return READ; }
"WRITE"                { return WRITE; }
"IF"                   { return IF; }
"ELSE"                 { return ELSE; }
"WHILE"                { return WHILE; }
"FOR"                  { return FOR; }
"=>"                   { return ASIGNACION; }
"<="                   { return MENORIGUAL; }
">="                   { return MAYORIGUAL; }
"=="                   { return IGUAL; }
"<>"                   { return DIFERENTE; }
"&&"                   { return AND; }
"||"                   { return OR; }
"<"                    { return MENOR; }
">"                    { return MAYOR; }
"+"                    { return MAS; }
"-"                    { return MENOS; }
"*"                    { return POR; }
"/"                    { return DIVIDIR; }
":"                    { return POTENCIA; }
"("                    { return PARENTESIS_ABRIR; }
")"                    { return PARENTESIS_CERRAR; }
"{"                    { return LLAVE_ABRIR; }
"}"                    { return LLAVE_CERRAR; }
","                    { return COMA; }
";"                    { return PUNTOYCOMA; }
"#!"[^\n]*"!#"    { }
"$"[a-zA-Z][a-zA-Z0-9]* { return IDENTIFICADOR; }
[0-9]+                 { return NUMERO; }
[ \t\r]                { }
\n                     { linea++; }
.                      { return INVALIDO; }

%%

int yywrap(){
    return 1;
}
