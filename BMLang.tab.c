/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "BMLang.y"

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


#line 88 "BMLang.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "BMLang.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAIN = 3,                       /* MAIN  */
  YYSYMBOL_DEC = 4,                        /* DEC  */
  YYSYMBOL_READ = 5,                       /* READ  */
  YYSYMBOL_WRITE = 6,                      /* WRITE  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_IDENTIFICADOR = 11,             /* IDENTIFICADOR  */
  YYSYMBOL_NUMERO = 12,                    /* NUMERO  */
  YYSYMBOL_MENORIGUAL = 13,                /* MENORIGUAL  */
  YYSYMBOL_MAYORIGUAL = 14,                /* MAYORIGUAL  */
  YYSYMBOL_IGUAL = 15,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 16,                 /* DIFERENTE  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_MENOR = 19,                     /* MENOR  */
  YYSYMBOL_MAYOR = 20,                     /* MAYOR  */
  YYSYMBOL_MAS = 21,                       /* MAS  */
  YYSYMBOL_MENOS = 22,                     /* MENOS  */
  YYSYMBOL_POR = 23,                       /* POR  */
  YYSYMBOL_DIVIDIR = 24,                   /* DIVIDIR  */
  YYSYMBOL_POTENCIA = 25,                  /* POTENCIA  */
  YYSYMBOL_PARENTESIS_ABRIR = 26,          /* PARENTESIS_ABRIR  */
  YYSYMBOL_PARENTESIS_CERRAR = 27,         /* PARENTESIS_CERRAR  */
  YYSYMBOL_LLAVE_ABRIR = 28,               /* LLAVE_ABRIR  */
  YYSYMBOL_LLAVE_CERRAR = 29,              /* LLAVE_CERRAR  */
  YYSYMBOL_COMA = 30,                      /* COMA  */
  YYSYMBOL_PUNTOYCOMA = 31,                /* PUNTOYCOMA  */
  YYSYMBOL_INVALIDO = 32,                  /* INVALIDO  */
  YYSYMBOL_ASIGNACION = 33,                /* ASIGNACION  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_inicio = 35,                    /* inicio  */
  YYSYMBOL_bloque = 36,                    /* bloque  */
  YYSYMBOL_otraSentencia = 37,             /* otraSentencia  */
  YYSYMBOL_sentencia = 38,                 /* sentencia  */
  YYSYMBOL_opciones = 39,                  /* opciones  */
  YYSYMBOL_declaracion = 40,               /* declaracion  */
  YYSYMBOL_otraVariable = 41,              /* otraVariable  */
  YYSYMBOL_lectura = 42,                   /* lectura  */
  YYSYMBOL_escritura = 43,                 /* escritura  */
  YYSYMBOL_asignacion = 44,                /* asignacion  */
  YYSYMBOL_condicional = 45,               /* condicional  */
  YYSYMBOL_otroElse = 46,                  /* otroElse  */
  YYSYMBOL_mientras = 47,                  /* mientras  */
  YYSYMBOL_para = 48,                      /* para  */
  YYSYMBOL_condicion = 49,                 /* condicion  */
  YYSYMBOL_conjuncion = 50,                /* conjuncion  */
  YYSYMBOL_comparacion = 51,               /* comparacion  */
  YYSYMBOL_operador = 52,                  /* operador  */
  YYSYMBOL_expresion = 53,                 /* expresion  */
  YYSYMBOL_termino = 54,                   /* termino  */
  YYSYMBOL_potenciacion = 55,              /* potenciacion  */
  YYSYMBOL_factor = 56,                    /* factor  */
  YYSYMBOL_vacio = 57                      /* vacio  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    44,    44,    51,    54,    55,    58,    59,    60,    61,
      64,    65,    66,    67,    70,    78,    84,    87,    91,    95,
      99,   103,   104,   105,   108,   112,   116,   117,   120,   121,
     124,   126,   130,   131,   132,   133,   134,   135,   137,   138,
     139,   142,   143,   144,   147,   148,   151,   152,   153,   154,
     156
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAIN", "DEC", "READ",
  "WRITE", "IF", "ELSE", "WHILE", "FOR", "IDENTIFICADOR", "NUMERO",
  "MENORIGUAL", "MAYORIGUAL", "IGUAL", "DIFERENTE", "AND", "OR", "MENOR",
  "MAYOR", "MAS", "MENOS", "POR", "DIVIDIR", "POTENCIA",
  "PARENTESIS_ABRIR", "PARENTESIS_CERRAR", "LLAVE_ABRIR", "LLAVE_CERRAR",
  "COMA", "PUNTOYCOMA", "INVALIDO", "ASIGNACION", "$accept", "inicio",
  "bloque", "otraSentencia", "sentencia", "opciones", "declaracion",
  "otraVariable", "lectura", "escritura", "asignacion", "condicional",
  "otroElse", "mientras", "para", "condicion", "conjuncion", "comparacion",
  "operador", "expresion", "termino", "potenciacion", "factor", "vacio", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      18,   -11,    50,    69,   -76,    47,    53,    55,    41,    42,
      43,    38,    22,    69,    46,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,    54,   -76,   -76,    -4,    -4,    72,     8,   -76,
     -76,    69,   -76,   -76,    74,   -76,   -76,   -76,   -76,     8,
      -4,    10,    71,   -76,    40,   -10,   -76,    61,    30,    58,
       8,    14,   -76,    54,   -76,    45,    25,    -4,    62,    -4,
     -76,   -76,   -76,   -76,   -76,   -76,     8,     8,     8,     8,
       8,     8,    63,    -4,    60,   -76,   -76,   -76,    71,    69,
     -76,   -10,   -10,    14,   -76,   -76,   -76,    69,    11,    64,
      65,    72,    84,   -76,    68,    -1,   -76,   -76,    70,    69,
     -76,    69,    67,    73,   -76,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    10,    11,    12,    13,     7,
       8,     9,    50,    17,    18,     0,     0,     0,     0,     2,
       3,    50,     5,     6,     0,    14,    16,    46,    47,     0,
       0,     0,    27,    29,     0,    40,    43,    45,     0,     0,
       0,    19,     4,    50,    48,     0,     0,     0,     0,     0,
      34,    35,    36,    37,    32,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    31,    49,    26,     0,
      28,    38,    39,    30,    41,    42,    44,     0,     0,     0,
       0,     0,    50,    24,     0,     0,    20,    23,     0,     0,
      22,     0,     0,     0,    21,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -75,    66,    -8,   -76,   -76,    48,   -76,   -76,
     -26,     4,   -76,   -76,   -76,   -24,    49,    44,   -76,   -25,
     -34,   -60,    75,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    12,    30,    13,    14,    15,    35,    16,    17,
      18,    19,    96,    20,    21,    41,    42,    43,    68,    44,
      45,    46,    47,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    49,    48,    51,    89,    31,     8,    37,    38,    84,
      85,    86,    90,    69,    70,    56,    55,     3,    39,    37,
      38,     1,    40,    31,   102,    74,   103,    99,    57,    57,
      39,    36,    81,    82,    50,    66,    67,    58,    60,    61,
      62,    63,    91,    83,    64,    65,    66,    67,    57,    88,
       4,    29,    77,    60,    61,    62,    63,    72,    22,    64,
      65,    66,    67,    57,    23,    94,    24,    25,    26,    27,
      97,    28,    76,     5,     6,     7,     8,    33,     9,    10,
      11,    66,    67,    11,    34,    53,    71,    77,    59,    73,
      79,    87,    95,    92,    93,    98,   104,    52,   101,   100,
       0,    75,   105,    80,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,    54
};

static const yytype_int8 yycheck[] =
{
      22,    27,    26,    28,    79,    13,     7,    11,    12,    69,
      70,    71,    87,    23,    24,    40,    40,    28,    22,    11,
      12,     3,    26,    31,    99,    50,   101,    28,    18,    18,
      22,    53,    66,    67,    26,    21,    22,    27,    13,    14,
      15,    16,    31,    68,    19,    20,    21,    22,    18,    73,
       0,    29,    27,    13,    14,    15,    16,    27,    11,    19,
      20,    21,    22,    18,    11,    91,    11,    26,    26,    26,
      92,    33,    27,     4,     5,     6,     7,    31,     9,    10,
      11,    21,    22,    11,    30,    11,    25,    27,    17,    31,
      28,    28,     8,    29,    29,    27,    29,    31,    28,    95,
      -1,    53,    29,    59,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    35,    28,     0,     4,     5,     6,     7,     9,
      10,    11,    36,    38,    39,    40,    42,    43,    44,    45,
      47,    48,    11,    11,    11,    26,    26,    26,    33,    29,
      37,    38,    57,    31,    30,    41,    57,    11,    12,    22,
      26,    49,    50,    51,    53,    54,    55,    56,    49,    44,
      26,    53,    37,    11,    56,    49,    53,    18,    27,    17,
      13,    14,    15,    16,    19,    20,    21,    22,    52,    23,
      24,    25,    27,    31,    53,    41,    27,    27,    50,    28,
      51,    54,    54,    53,    55,    55,    55,    28,    49,    36,
      36,    31,    29,    29,    44,     8,    46,    57,    27,    28,
      45,    28,    36,    36,    29,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    37,    37,    38,    38,    38,    38,
      39,    39,    39,    39,    40,    41,    41,    42,    43,    44,
      45,    46,    46,    46,    47,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    52,    52,    53,    53,
      53,    54,    54,    54,    55,    55,    56,    56,    56,    56,
      57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     2,     2,     3,
       8,     4,     2,     1,     7,    11,     3,     1,     3,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     2,     3,
       0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* inicio: MAIN LLAVE_ABRIR bloque LLAVE_CERRAR  */
#line 45 "BMLang.y"
           {
               raiz = crearNodo(N_PROGRAMA, (yyvsp[-1].nodo), NULL, NULL, NULL);
           }
#line 1202 "BMLang.tab.c"
    break;

  case 3: /* bloque: sentencia otraSentencia  */
#line 51 "BMLang.y"
                                   { (yyvsp[-1].nodo)->sig = (yyvsp[0].nodo); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1208 "BMLang.tab.c"
    break;

  case 4: /* otraSentencia: sentencia otraSentencia  */
#line 54 "BMLang.y"
                                          { (yyvsp[-1].nodo)->sig = (yyvsp[0].nodo); (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1214 "BMLang.tab.c"
    break;

  case 5: /* otraSentencia: vacio  */
#line 55 "BMLang.y"
                                          { (yyval.nodo) = NULL; }
#line 1220 "BMLang.tab.c"
    break;

  case 6: /* sentencia: opciones PUNTOYCOMA  */
#line 58 "BMLang.y"
                                  { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1226 "BMLang.tab.c"
    break;

  case 7: /* sentencia: condicional  */
#line 59 "BMLang.y"
                                  { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1232 "BMLang.tab.c"
    break;

  case 8: /* sentencia: mientras  */
#line 60 "BMLang.y"
                                  { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1238 "BMLang.tab.c"
    break;

  case 9: /* sentencia: para  */
#line 61 "BMLang.y"
                                  { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1244 "BMLang.tab.c"
    break;

  case 10: /* opciones: declaracion  */
#line 64 "BMLang.y"
                         { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1250 "BMLang.tab.c"
    break;

  case 11: /* opciones: lectura  */
#line 65 "BMLang.y"
                         { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1256 "BMLang.tab.c"
    break;

  case 12: /* opciones: escritura  */
#line 66 "BMLang.y"
                         { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1262 "BMLang.tab.c"
    break;

  case 13: /* opciones: asignacion  */
#line 67 "BMLang.y"
                         { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1268 "BMLang.tab.c"
    break;

  case 14: /* declaracion: DEC IDENTIFICADOR otraVariable  */
#line 71 "BMLang.y"
                {
                    Nodo *v = nodoVariable((yyvsp[-1].nombre));
                    v->sig = (yyvsp[0].nodo);
                    (yyval.nodo) = crearNodo(N_DECLARACION, v, NULL, NULL, NULL);
                }
#line 1278 "BMLang.tab.c"
    break;

  case 15: /* otraVariable: COMA IDENTIFICADOR otraVariable  */
#line 79 "BMLang.y"
                 {
                     Nodo *v = nodoVariable((yyvsp[-1].nombre));
                     v->sig = (yyvsp[0].nodo);
                     (yyval.nodo) = v;
                 }
#line 1288 "BMLang.tab.c"
    break;

  case 16: /* otraVariable: vacio  */
#line 84 "BMLang.y"
                       { (yyval.nodo) = NULL; }
#line 1294 "BMLang.tab.c"
    break;

  case 17: /* lectura: READ IDENTIFICADOR  */
#line 88 "BMLang.y"
            { (yyval.nodo) = crearNodo(N_READ, nodoVariable((yyvsp[0].nombre)), NULL, NULL, NULL); }
#line 1300 "BMLang.tab.c"
    break;

  case 18: /* escritura: WRITE IDENTIFICADOR  */
#line 92 "BMLang.y"
              { (yyval.nodo) = crearNodo(N_WRITE, nodoVariable((yyvsp[0].nombre)), NULL, NULL, NULL); }
#line 1306 "BMLang.tab.c"
    break;

  case 19: /* asignacion: IDENTIFICADOR ASIGNACION expresion  */
#line 96 "BMLang.y"
               { (yyval.nodo) = crearNodo(N_ASIGNACION, nodoVariable((yyvsp[-2].nombre)), (yyvsp[0].nodo), NULL, NULL); }
#line 1312 "BMLang.tab.c"
    break;

  case 20: /* condicional: IF PARENTESIS_ABRIR condicion PARENTESIS_CERRAR LLAVE_ABRIR bloque LLAVE_CERRAR otroElse  */
#line 100 "BMLang.y"
                { (yyval.nodo) = crearNodo(N_IF, (yyvsp[-5].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL); }
#line 1318 "BMLang.tab.c"
    break;

  case 21: /* otroElse: ELSE LLAVE_ABRIR bloque LLAVE_CERRAR  */
#line 103 "BMLang.y"
                                                  { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1324 "BMLang.tab.c"
    break;

  case 22: /* otroElse: ELSE condicional  */
#line 104 "BMLang.y"
                                                  { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1330 "BMLang.tab.c"
    break;

  case 23: /* otroElse: vacio  */
#line 105 "BMLang.y"
                                                  { (yyval.nodo) = NULL; }
#line 1336 "BMLang.tab.c"
    break;

  case 24: /* mientras: WHILE PARENTESIS_ABRIR condicion PARENTESIS_CERRAR LLAVE_ABRIR bloque LLAVE_CERRAR  */
#line 109 "BMLang.y"
             { (yyval.nodo) = crearNodo(N_WHILE, (yyvsp[-4].nodo), (yyvsp[-1].nodo), NULL, NULL); }
#line 1342 "BMLang.tab.c"
    break;

  case 25: /* para: FOR PARENTESIS_ABRIR asignacion PUNTOYCOMA condicion PUNTOYCOMA asignacion PARENTESIS_CERRAR LLAVE_ABRIR bloque LLAVE_CERRAR  */
#line 113 "BMLang.y"
         { (yyval.nodo) = crearNodo(N_FOR, (yyvsp[-8].nodo), (yyvsp[-6].nodo), (yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 1348 "BMLang.tab.c"
    break;

  case 26: /* condicion: condicion OR conjuncion  */
#line 116 "BMLang.y"
                                      { (yyval.nodo) = crearNodo(N_OR, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL); }
#line 1354 "BMLang.tab.c"
    break;

  case 27: /* condicion: conjuncion  */
#line 117 "BMLang.y"
                                      { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1360 "BMLang.tab.c"
    break;

  case 28: /* conjuncion: conjuncion AND comparacion  */
#line 120 "BMLang.y"
                                          { (yyval.nodo) = crearNodo(N_AND, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL); }
#line 1366 "BMLang.tab.c"
    break;

  case 29: /* conjuncion: comparacion  */
#line 121 "BMLang.y"
                                          { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1372 "BMLang.tab.c"
    break;

  case 30: /* comparacion: expresion operador expresion  */
#line 125 "BMLang.y"
                { (yyval.nodo) = nodoComparacion((yyvsp[-1].valor), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1378 "BMLang.tab.c"
    break;

  case 31: /* comparacion: PARENTESIS_ABRIR condicion PARENTESIS_CERRAR  */
#line 127 "BMLang.y"
                { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1384 "BMLang.tab.c"
    break;

  case 32: /* operador: MENOR  */
#line 130 "BMLang.y"
                        { (yyval.valor) = OP_MENOR; }
#line 1390 "BMLang.tab.c"
    break;

  case 33: /* operador: MAYOR  */
#line 131 "BMLang.y"
                        { (yyval.valor) = OP_MAYOR; }
#line 1396 "BMLang.tab.c"
    break;

  case 34: /* operador: MENORIGUAL  */
#line 132 "BMLang.y"
                        { (yyval.valor) = OP_MENORIGUAL; }
#line 1402 "BMLang.tab.c"
    break;

  case 35: /* operador: MAYORIGUAL  */
#line 133 "BMLang.y"
                        { (yyval.valor) = OP_MAYORIGUAL; }
#line 1408 "BMLang.tab.c"
    break;

  case 36: /* operador: IGUAL  */
#line 134 "BMLang.y"
                        { (yyval.valor) = OP_IGUAL; }
#line 1414 "BMLang.tab.c"
    break;

  case 37: /* operador: DIFERENTE  */
#line 135 "BMLang.y"
                        { (yyval.valor) = OP_DIFERENTE; }
#line 1420 "BMLang.tab.c"
    break;

  case 38: /* expresion: expresion MAS termino  */
#line 137 "BMLang.y"
                                       { (yyval.nodo) = nodoOp('+', (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1426 "BMLang.tab.c"
    break;

  case 39: /* expresion: expresion MENOS termino  */
#line 138 "BMLang.y"
                                       { (yyval.nodo) = nodoOp('-', (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1432 "BMLang.tab.c"
    break;

  case 40: /* expresion: termino  */
#line 139 "BMLang.y"
                                       { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1438 "BMLang.tab.c"
    break;

  case 41: /* termino: termino POR potenciacion  */
#line 142 "BMLang.y"
                                       { (yyval.nodo) = nodoOp('*', (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1444 "BMLang.tab.c"
    break;

  case 42: /* termino: termino DIVIDIR potenciacion  */
#line 143 "BMLang.y"
                                       { (yyval.nodo) = nodoOp('/', (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1450 "BMLang.tab.c"
    break;

  case 43: /* termino: potenciacion  */
#line 144 "BMLang.y"
                                       { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1456 "BMLang.tab.c"
    break;

  case 44: /* potenciacion: factor POTENCIA potenciacion  */
#line 147 "BMLang.y"
                                            { (yyval.nodo) = nodoOp(':', (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1462 "BMLang.tab.c"
    break;

  case 45: /* potenciacion: factor  */
#line 148 "BMLang.y"
                                            { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1468 "BMLang.tab.c"
    break;

  case 46: /* factor: IDENTIFICADOR  */
#line 151 "BMLang.y"
                         { (yyval.nodo) = nodoVariable((yyvsp[0].nombre)); }
#line 1474 "BMLang.tab.c"
    break;

  case 47: /* factor: NUMERO  */
#line 152 "BMLang.y"
                         { (yyval.nodo) = nodoNumero((yyvsp[0].valor)); }
#line 1480 "BMLang.tab.c"
    break;

  case 48: /* factor: MENOS factor  */
#line 153 "BMLang.y"
                         { (yyval.nodo) = crearNodo(N_NEGACION, (yyvsp[0].nodo), NULL, NULL, NULL); }
#line 1486 "BMLang.tab.c"
    break;

  case 49: /* factor: PARENTESIS_ABRIR expresion PARENTESIS_CERRAR  */
#line 154 "BMLang.y"
                                                      { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1492 "BMLang.tab.c"
    break;


#line 1496 "BMLang.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 158 "BMLang.y"


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
