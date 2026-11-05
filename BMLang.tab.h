/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BMLANG_TAB_H_INCLUDED
# define YY_YY_BMLANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "BMLang.y"

#include "ast.h"

#line 53 "BMLang.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MAIN = 258,                    /* MAIN  */
    DEC = 259,                     /* DEC  */
    READ = 260,                    /* READ  */
    WRITE = 261,                   /* WRITE  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    WHILE = 264,                   /* WHILE  */
    FOR = 265,                     /* FOR  */
    IDENTIFICADOR = 266,           /* IDENTIFICADOR  */
    NUMERO = 267,                  /* NUMERO  */
    MENORIGUAL = 268,              /* MENORIGUAL  */
    MAYORIGUAL = 269,              /* MAYORIGUAL  */
    IGUAL = 270,                   /* IGUAL  */
    DIFERENTE = 271,               /* DIFERENTE  */
    AND = 272,                     /* AND  */
    OR = 273,                      /* OR  */
    MENOR = 274,                   /* MENOR  */
    MAYOR = 275,                   /* MAYOR  */
    MAS = 276,                     /* MAS  */
    MENOS = 277,                   /* MENOS  */
    POR = 278,                     /* POR  */
    DIVIDIR = 279,                 /* DIVIDIR  */
    POTENCIA = 280,                /* POTENCIA  */
    PARENTESIS_ABRIR = 281,        /* PARENTESIS_ABRIR  */
    PARENTESIS_CERRAR = 282,       /* PARENTESIS_CERRAR  */
    LLAVE_ABRIR = 283,             /* LLAVE_ABRIR  */
    LLAVE_CERRAR = 284,            /* LLAVE_CERRAR  */
    COMA = 285,                    /* COMA  */
    PUNTOYCOMA = 286,              /* PUNTOYCOMA  */
    INVALIDO = 287,                /* INVALIDO  */
    ASIGNACION = 288               /* ASIGNACION  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "BMLang.y"

    int valor;
    char *nombre;
    Nodo *nodo;

#line 109 "BMLang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BMLANG_TAB_H_INCLUDED  */
