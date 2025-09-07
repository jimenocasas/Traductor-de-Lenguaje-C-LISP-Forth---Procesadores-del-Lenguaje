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
#line 6 "trad.y"
                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *mi_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

char temp [2048] ;
char *current_function = NULL;

// Tabla de variables locales
typedef struct local_var {
    char *name;
    struct local_var *next;
} t_local_var;

t_local_var *local_vars = NULL;

void add_local_var(char *name) {
    t_local_var *new_var = (t_local_var *)mi_malloc(sizeof(t_local_var));
    new_var->name = gen_code(name);
    new_var->next = local_vars;
    local_vars = new_var;
}

int is_local_var(char *name) {
    t_local_var *current = local_vars;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void clear_local_vars() {
    local_vars = NULL;
}

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;

// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr

#line 142 "trad.tab.c"

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

#include "trad.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_PUTS = 12,                      /* PUTS  */
  YYSYMBOL_PRINTF = 13,                    /* PRINTF  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_IGUAL = 17,                     /* IGUAL  */
  YYSYMBOL_DISTINTO = 18,                  /* DISTINTO  */
  YYSYMBOL_MENORIGUAL = 19,                /* MENORIGUAL  */
  YYSYMBOL_MAYORIGUAL = 20,                /* MAYORIGUAL  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_23_ = 23,                       /* '<'  */
  YYSYMBOL_24_ = 24,                       /* '>'  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '%'  */
  YYSYMBOL_UNARY_SIGN = 30,                /* UNARY_SIGN  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* '['  */
  YYSYMBOL_33_ = 33,                       /* ']'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '@'  */
  YYSYMBOL_40_ = 40,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_programa = 42,                  /* programa  */
  YYSYMBOL_declaracion_variables_globales = 43, /* declaracion_variables_globales  */
  YYSYMBOL_declaracion_variable_global = 44, /* declaracion_variable_global  */
  YYSYMBOL_lista_declaracion_global = 45,  /* lista_declaracion_global  */
  YYSYMBOL_funciones = 46,                 /* funciones  */
  YYSYMBOL_funcion_main = 47,              /* funcion_main  */
  YYSYMBOL_inicializacion_main = 48,       /* inicializacion_main  */
  YYSYMBOL_funcion = 49,                   /* funcion  */
  YYSYMBOL_inicializacion_funcion = 50,    /* inicializacion_funcion  */
  YYSYMBOL_parametros = 51,                /* parametros  */
  YYSYMBOL_lista_parametros = 52,          /* lista_parametros  */
  YYSYMBOL_parametro = 53,                 /* parametro  */
  YYSYMBOL_instrucciones = 54,             /* instrucciones  */
  YYSYMBOL_instruccion = 55,               /* instruccion  */
  YYSYMBOL_sentencia_simple = 56,          /* sentencia_simple  */
  YYSYMBOL_sentencia_bloque = 57,          /* sentencia_bloque  */
  YYSYMBOL_if_sin_else = 58,               /* if_sin_else  */
  YYSYMBOL_if_con_else = 59,               /* if_con_else  */
  YYSYMBOL_inicializacion = 60,            /* inicializacion  */
  YYSYMBOL_incremento = 61,                /* incremento  */
  YYSYMBOL_declaracion_variable = 62,      /* declaracion_variable  */
  YYSYMBOL_lista_declaracion = 63,         /* lista_declaracion  */
  YYSYMBOL_expresion = 64,                 /* expresion  */
  YYSYMBOL_termino = 65,                   /* termino  */
  YYSYMBOL_operando = 66,                  /* operando  */
  YYSYMBOL_argumentos = 67,                /* argumentos  */
  YYSYMBOL_lista_argumentos = 68,          /* lista_argumentos  */
  YYSYMBOL_lista_elementos = 69,           /* lista_elementos  */
  YYSYMBOL_elemento = 70                   /* elemento  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,    40,     2,     2,     2,    29,     2,     2,
      37,    38,    27,    25,    34,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      23,    21,    24,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    22,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   117,   118,   125,   129,   132,   136,   139,
     142,   145,   151,   152,   159,   167,   175,   194,   201,   202,
     206,   207,   213,   222,   223,   229,   230,   231,   236,   244,
     247,   250,   253,   263,   267,   278,   280,   282,   286,   294,
     305,   321,   324,   332,   338,   342,   346,   350,   354,   358,
     362,   369,   370,   373,   376,   379,   382,   385,   388,   391,
     394,   397,   400,   403,   406,   409,   412,   418,   419,   420,
     426,   436,   439,   440,   453,   454,   458,   459,   465,   466,
     471,   474
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "WHILE", "IF", "ELSE", "FOR", "PUTS",
  "PRINTF", "RETURN", "AND", "OR", "IGUAL", "DISTINTO", "MENORIGUAL",
  "MAYORIGUAL", "'='", "NOT", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UNARY_SIGN", "';'", "'['", "']'", "','", "'{'", "'}'", "'('",
  "')'", "'@'", "'!'", "$accept", "programa",
  "declaracion_variables_globales", "declaracion_variable_global",
  "lista_declaracion_global", "funciones", "funcion_main",
  "inicializacion_main", "funcion", "inicializacion_funcion", "parametros",
  "lista_parametros", "parametro", "instrucciones", "instruccion",
  "sentencia_simple", "sentencia_bloque", "if_sin_else", "if_con_else",
  "inicializacion", "incremento", "declaracion_variable",
  "lista_declaracion", "expresion", "termino", "operando", "argumentos",
  "lista_argumentos", "lista_elementos", "elemento", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -60,    21,    47,   -60,    -9,    26,    18,    11,   -60,   -60,
      12,     0,    33,    40,    -7,    51,    49,   -60,   190,   -60,
     190,    85,    57,    56,   -60,    89,    90,    94,   -60,   -10,
      95,    65,    66,    69,    74,    78,    13,    13,    52,   -60,
      87,   -60,   -60,   -60,    97,    96,   -60,   -60,    40,   -60,
     103,    -1,    13,    13,    13,     5,   104,    13,    13,    54,
     123,   133,   -60,     4,     6,     6,    13,    13,   310,   -60,
     -60,   310,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   137,
     138,   310,   255,   310,   105,   111,   139,   149,   152,   207,
     223,   132,   157,   136,   125,   134,    13,    13,   144,   -60,
     -60,   239,   -60,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,   -60,   145,   150,   -60,
      13,   -60,   148,     8,   142,   155,     6,   170,    13,   -60,
       9,   274,   154,   -60,   338,   325,   349,   349,    98,    98,
      98,    98,    55,    55,   164,   164,   -60,   -60,    13,   310,
     -60,   193,   202,   190,   190,   -60,     6,   293,   -60,   310,
      10,   -60,   -60,   -60,   310,   -60,   173,   108,   146,   -60,
     203,     9,   -60,   -60,   -60,   198,   188,   172,   -60,   177,
      13,   178,   190,   310,   190,   161,   175,   -60,   -60
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     2,    12,
       0,     0,     0,    18,     6,     5,     0,     4,     0,    13,
       0,     0,     0,    19,    20,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,    26,    35,    36,     0,     0,    22,    17,     0,     7,
       0,     9,     0,     0,    74,    45,    44,     0,     0,     0,
       0,     0,    71,    70,     0,     0,     0,     0,    32,    51,
      67,    29,    14,    24,    25,    27,    16,    21,     8,     0,
       0,    28,     0,    76,     0,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    70,    68,
      69,     0,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,    33,
       0,    46,     0,    48,     0,     0,     0,     0,     0,    30,
       0,     0,     0,    72,    62,    63,    58,    59,    60,    61,
      57,    56,    52,    53,    54,    55,    65,    11,     0,    77,
      47,     0,     0,     0,     0,    42,     0,     0,    81,    80,
       0,    78,    73,    66,    34,    49,     0,     0,     0,    41,
       0,     0,    31,    50,    37,    39,     0,     0,    79,     0,
       0,     0,     0,    43,     0,     0,     0,    40,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,   -60,   -60,   -60,   204,   -60,   -60,   -60,   -60,
     -60,   -60,   168,   -20,   -37,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -34,   -60,   -59,   120,   -60,   -60,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,    15,     8,     9,    10,    11,    12,
      22,    23,    24,    38,    39,    40,    41,    42,    43,    93,
     177,    44,    56,    83,    69,    70,    84,    85,   160,   161
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    73,    68,    71,     4,    99,   100,     6,    73,    62,
      98,    52,    62,    63,    25,   158,    62,    63,    81,    82,
      79,     3,    53,    89,    90,    26,    86,    54,    13,   151,
      14,    80,   101,   102,    64,    65,    96,    87,    64,    65,
     152,    97,    17,    66,   171,    21,    66,    18,   172,    67,
      66,     4,     5,    67,     6,    16,    29,    30,    91,    92,
      31,    32,   131,    33,    34,    35,    36,   155,    20,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   113,   114,   115,    27,   149,    28,    72,    46,
      48,    37,    49,    50,   157,    47,   159,   169,    51,    55,
      29,    30,    57,    58,    31,    32,    59,    33,    34,    35,
      36,    60,    29,    30,   164,    61,    31,    32,    74,    33,
      34,    35,    36,   111,   112,   113,   114,   115,    75,    94,
      73,    73,    76,   167,   168,    37,    78,   159,    88,    95,
     116,   117,   121,   119,   174,   120,   183,    37,    73,    73,
      29,    30,   122,   126,    31,    32,   123,    33,    34,    35,
      36,   127,   185,   129,   186,    29,    30,   128,   130,    31,
      32,   148,    33,    34,    35,    36,    96,   153,   147,    29,
      30,   150,   175,    31,    32,    37,    33,    34,    35,    36,
     154,   156,   163,   115,    29,    30,   165,   187,    31,    32,
      37,    33,    34,    35,    36,   166,   173,   176,   179,   180,
     181,   188,   182,   184,    37,    19,    77,   132,     0,   178,
       0,     0,   103,   104,   105,   106,   107,   108,     0,    37,
     109,   110,   111,   112,   113,   114,   115,     0,   103,   104,
     105,   106,   107,   108,     0,   124,   109,   110,   111,   112,
     113,   114,   115,     0,   103,   104,   105,   106,   107,   108,
       0,   125,   109,   110,   111,   112,   113,   114,   115,     0,
     103,   104,   105,   106,   107,   108,     0,   133,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,   118,   103,
     104,   105,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,   162,   103,   104,
     105,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,     0,   170,   103,   104,   105,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     103,     0,   105,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   105,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
      20,    38,    36,    37,     4,    64,    65,     7,    45,     3,
       4,    21,     3,     4,    21,     6,     3,     4,    52,    53,
      21,     0,    32,    57,    58,    32,    21,    37,    37,    21,
       4,    32,    66,    67,    25,    26,    32,    32,    25,    26,
      32,    37,    31,    37,    34,     5,    37,    35,    38,    40,
      37,     4,     5,    40,     7,    37,     4,     5,     4,     5,
       8,     9,    96,    11,    12,    13,    14,   126,    35,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    27,    28,    29,    34,   120,    38,    36,     4,
      34,    39,     3,     3,   128,    38,   130,   156,     4,     4,
       4,     5,    37,    37,     8,     9,    37,    11,    12,    13,
      14,    37,     4,     5,   148,    37,     8,     9,    31,    11,
      12,    13,    14,    25,    26,    27,    28,    29,    31,     6,
     167,   168,    36,   153,   154,    39,    33,   171,    34,     6,
       3,     3,     3,    38,    36,    34,   180,    39,   185,   186,
       4,     5,     3,    21,     8,     9,     4,    11,    12,    13,
      14,     4,   182,    38,   184,     4,     5,    31,    34,     8,
       9,    21,    11,    12,    13,    14,    32,    35,    33,     4,
       5,    33,    36,     8,     9,    39,    11,    12,    13,    14,
      35,    21,    38,    29,     4,     5,     3,    36,     8,     9,
      39,    11,    12,    13,    14,     3,    33,     4,    10,    21,
      38,    36,    35,    35,    39,    11,    48,    97,    -1,   171,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    39,
      23,    24,    25,    26,    27,    28,    29,    -1,    15,    16,
      17,    18,    19,    20,    -1,    38,    23,    24,    25,    26,
      27,    28,    29,    -1,    15,    16,    17,    18,    19,    20,
      -1,    38,    23,    24,    25,    26,    27,    28,    29,    -1,
      15,    16,    17,    18,    19,    20,    -1,    38,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    33,    15,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    33,    15,    16,
      17,    18,    19,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    15,    16,    17,    18,    19,
      20,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      15,    -1,    17,    18,    19,    20,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    17,    18,    19,    20,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    19,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,     4,     5,     7,    44,    46,    47,
      48,    49,    50,    37,     4,    45,    37,    31,    35,    46,
      35,     5,    51,    52,    53,    21,    32,    34,    38,     4,
       5,     8,     9,    11,    12,    13,    14,    39,    54,    55,
      56,    57,    58,    59,    62,    54,     4,    38,    34,     3,
       3,     4,    21,    32,    37,     4,    63,    37,    37,    37,
      37,    37,     3,     4,    25,    26,    37,    40,    64,    65,
      66,    64,    36,    55,    31,    31,    36,    53,    33,    21,
      32,    64,    64,    64,    67,    68,    21,    32,    34,    64,
      64,     4,     5,    60,     6,     6,    32,    37,     4,    66,
      66,    64,    64,    15,    16,    17,    18,    19,    20,    23,
      24,    25,    26,    27,    28,    29,     3,     3,    33,    38,
      34,     3,     3,     4,    38,    38,    21,     4,    31,    38,
      34,    64,    67,    38,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    33,    21,    64,
      33,    21,    32,    35,    35,    66,    21,    64,     6,    64,
      69,    70,    33,    38,    64,     3,     3,    54,    54,    66,
      31,    34,    38,    33,    36,    36,     4,    61,    70,    10,
      21,    38,    35,    64,    35,    54,    54,    36,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    45,    45,    45,    45,
      45,    45,    46,    46,    47,    48,    49,    50,    51,    51,
      52,    52,    53,    54,    54,    55,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    57,    58,
      59,    60,    60,    61,    62,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      66,    66,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     2,     1,     3,     4,     3,
       5,     6,     1,     2,     4,     3,     4,     4,     0,     1,
       1,     3,     2,     1,     2,     2,     1,     2,     3,     2,
       4,     6,     2,     4,     6,     1,     1,     7,    11,     7,
      11,     4,     3,     3,     2,     1,     3,     4,     3,     5,
       6,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     4,     1,     2,     2,
       1,     1,     3,     4,     0,     1,     1,     3,     1,     3,
       1,     1
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
  case 2: /* programa: declaracion_variables_globales funciones  */
#line 113 "trad.y"
                                                             { printf("%s\n%s\n", yyvsp[-1].code, yyvsp[0].code); }
#line 1355 "trad.tab.c"
    break;

  case 3: /* declaracion_variables_globales: %empty  */
#line 117 "trad.y"
                                 { yyval.code = gen_code(""); }
#line 1361 "trad.tab.c"
    break;

  case 4: /* declaracion_variables_globales: declaracion_variables_globales declaracion_variable_global ';'  */
#line 118 "trad.y"
                                                                                     {
                                                                                        sprintf(temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code);
                                                                                        yyval.code = gen_code(temp);
                                                                                    }
#line 1370 "trad.tab.c"
    break;

  case 5: /* declaracion_variable_global: INTEGER lista_declaracion_global  */
#line 125 "trad.y"
                                                     { yyval.code = yyvsp[0].code; }
#line 1376 "trad.tab.c"
    break;

  case 6: /* lista_declaracion_global: IDENTIF  */
#line 129 "trad.y"
                            { sprintf(temp, "(setq %s 0)", yyvsp[0].code); 
                                                yyval.code = gen_code(temp);
                                                }
#line 1384 "trad.tab.c"
    break;

  case 7: /* lista_declaracion_global: IDENTIF '=' NUMBER  */
#line 132 "trad.y"
                                         { sprintf(temp, "(setq %s %d)", 
                                                yyvsp[-2].code, yyvsp[0].value); 
                                                yyval.code = gen_code(temp);
                                                }
#line 1393 "trad.tab.c"
    break;

  case 8: /* lista_declaracion_global: IDENTIF '[' NUMBER ']'  */
#line 136 "trad.y"
                                             {  sprintf(temp, "(setq %s (make-array %d))", yyvsp[-3].code, yyvsp[-1].value);
                                                yyval.code = gen_code(temp);
                                                }
#line 1401 "trad.tab.c"
    break;

  case 9: /* lista_declaracion_global: lista_declaracion_global ',' IDENTIF  */
#line 139 "trad.y"
                                                           { sprintf(temp, "%s\n(setq %s 0)", yyvsp[-2].code, yyvsp[0].code); 
                                                            yyval.code = gen_code(temp);
                                                            }
#line 1409 "trad.tab.c"
    break;

  case 10: /* lista_declaracion_global: lista_declaracion_global ',' IDENTIF '=' NUMBER  */
#line 142 "trad.y"
                                                                      { sprintf(temp, "%s\n(setq %s %d)", yyvsp[-4].code, yyvsp[-2].code, yyvsp[0].value); 
                                                                        yyval.code = gen_code(temp);
                                                                        }
#line 1417 "trad.tab.c"
    break;

  case 11: /* lista_declaracion_global: lista_declaracion_global ',' IDENTIF '[' NUMBER ']'  */
#line 145 "trad.y"
                                                                          {  sprintf(temp, "(setq %s (make-array %d))", yyvsp[-5].code, yyvsp[-3].value);
                                                                                yyval.code = gen_code(temp);
                                                                                }
#line 1425 "trad.tab.c"
    break;

  case 12: /* funciones: funcion_main  */
#line 151 "trad.y"
                                                { yyval = yyvsp[0]; }
#line 1431 "trad.tab.c"
    break;

  case 13: /* funciones: funcion funciones  */
#line 152 "trad.y"
                                                { 
                                                    sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp); 
                                                    }
#line 1440 "trad.tab.c"
    break;

  case 14: /* funcion_main: inicializacion_main '{' instrucciones '}'  */
#line 159 "trad.y"
                                                              {
                                                        sprintf(temp, "(%s %s\n)", yyvsp[-3].code, yyvsp[-1].code);
                                                        yyval.code = gen_code(temp);
                                                        clear_local_vars();  
                                                    }
#line 1450 "trad.tab.c"
    break;

  case 15: /* inicializacion_main: MAIN '(' ')'  */
#line 167 "trad.y"
                                     {
                                        current_function = strdup("main");
                                        sprintf(temp, "defun main ()\n");
                                        yyval.code = gen_code(temp);
                        }
#line 1460 "trad.tab.c"
    break;

  case 16: /* funcion: inicializacion_funcion '{' instrucciones '}'  */
#line 175 "trad.y"
                                                                 {
                                                                            // Verificar si la última instrucción es un return
                                                                            char *last_instr = strrchr(yyvsp[-1].code, '\n');
                                                                            if (last_instr != NULL) last_instr++;
                                                                            else last_instr = yyvsp[-1].code;

                                                                            if (strstr(last_instr, "return") != NULL) {
                                                                                // Si termina con return, usamos el valor directamente
                                                                                sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code);
                                                                            } else {
                                                                                // Si no termina con return, agregamos nil al final
                                                                                sprintf(temp, "(%s %s\n)", yyvsp[-3].code, yyvsp[-1].code);
                                                                                    }
                                                                            yyval.code = gen_code(temp);
                                                                            free(current_function);
                                                                            }
#line 1481 "trad.tab.c"
    break;

  case 17: /* inicializacion_funcion: IDENTIF '(' parametros ')'  */
#line 194 "trad.y"
                                                   {
                                                    current_function = yyvsp[-3].code;
                                                    sprintf(temp, "defun %s (%s)\n", yyvsp[-3].code, yyvsp[-1].code);
                                                    yyval.code = gen_code(temp);
                        }
#line 1491 "trad.tab.c"
    break;

  case 18: /* parametros: %empty  */
#line 201 "trad.y"
                                 { yyval.code = gen_code(""); }
#line 1497 "trad.tab.c"
    break;

  case 19: /* parametros: lista_parametros  */
#line 202 "trad.y"
                                       { yyval.code = yyvsp[0].code; }
#line 1503 "trad.tab.c"
    break;

  case 20: /* lista_parametros: parametro  */
#line 206 "trad.y"
                              { yyval.code = yyvsp[0].code; }
#line 1509 "trad.tab.c"
    break;

  case 21: /* lista_parametros: lista_parametros ',' parametro  */
#line 207 "trad.y"
                                                     { sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[0].code);
                                                        yyval.code = gen_code(temp); 
                                                        }
#line 1517 "trad.tab.c"
    break;

  case 22: /* parametro: INTEGER IDENTIF  */
#line 213 "trad.y"
                                    { 
                                        sprintf(temp, "%s", yyvsp[0].code);
                                        yyval.code = gen_code(temp);
                                        }
#line 1526 "trad.tab.c"
    break;

  case 23: /* instrucciones: instruccion  */
#line 222 "trad.y"
                                { yyval = yyvsp[0]; }
#line 1532 "trad.tab.c"
    break;

  case 24: /* instrucciones: instrucciones instruccion  */
#line 223 "trad.y"
                                                { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1540 "trad.tab.c"
    break;

  case 25: /* instruccion: sentencia_simple ';'  */
#line 229 "trad.y"
                                           { yyval = yyvsp[-1]; }
#line 1546 "trad.tab.c"
    break;

  case 26: /* instruccion: sentencia_bloque  */
#line 230 "trad.y"
                                             { yyval = yyvsp[0]; }
#line 1552 "trad.tab.c"
    break;

  case 27: /* instruccion: declaracion_variable ';'  */
#line 231 "trad.y"
                                               { yyval = yyvsp[-1]; }
#line 1558 "trad.tab.c"
    break;

  case 28: /* sentencia_simple: IDENTIF '=' expresion  */
#line 236 "trad.y"
                                          { 
                                            if(is_local_var(yyvsp[-2].code)) {
                                                sprintf(temp, "(setf %s_%s %s)", current_function, yyvsp[-2].code, yyvsp[0].code);
                                            } else {
                                                sprintf(temp, "(setf %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                            }
                                            yyval.code = gen_code(temp); 
                                            }
#line 1571 "trad.tab.c"
    break;

  case 29: /* sentencia_simple: '@' expresion  */
#line 244 "trad.y"
                                                      { sprintf(temp, "(print %s)", yyvsp[0].code);
                                                        yyval.code = gen_code(temp); 
                                                        }
#line 1579 "trad.tab.c"
    break;

  case 30: /* sentencia_simple: PUTS '(' STRING ')'  */
#line 247 "trad.y"
                                                      { sprintf(temp, "(print \"%s\")", yyvsp[-1].code);
                                                        yyval.code = gen_code(temp); 
                                                        }
#line 1587 "trad.tab.c"
    break;

  case 31: /* sentencia_simple: PRINTF '(' STRING ',' lista_elementos ')'  */
#line 250 "trad.y"
                                                                {
                                                                    yyval.code = yyvsp[-1].code;
                                                                    }
#line 1595 "trad.tab.c"
    break;

  case 32: /* sentencia_simple: RETURN expresion  */
#line 253 "trad.y"
                                      {
                                        if (current_function != NULL) {
                                            if (is_local_var(yyvsp[0].code)) {
                                                sprintf(temp, "(return-from %s %s_%s)", current_function, current_function, yyvsp[0].code);
                                            } else {
                                                sprintf(temp, "(return-from %s %s)", current_function, yyvsp[0].code);
                                            }
                                        }
                                        yyval.code = gen_code(temp);
                                        }
#line 1610 "trad.tab.c"
    break;

  case 33: /* sentencia_simple: IDENTIF '(' argumentos ')'  */
#line 263 "trad.y"
                                                 {  // Llamada a función como sentencia
                                                    sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1619 "trad.tab.c"
    break;

  case 34: /* sentencia_simple: IDENTIF '[' expresion ']' '=' expresion  */
#line 267 "trad.y"
                                                              {
                                                            if(is_local_var(yyvsp[-5].code)) {
                                                                sprintf(temp, "(setf (aref %s_%s %s) %s)", current_function, yyvsp[-5].code, yyvsp[-3].code, yyvsp[0].code);
                                                            } else {
                                                                sprintf(temp, "(setf (aref %s %s) %s)", yyvsp[-5].code, yyvsp[-3].code, yyvsp[0].code);
                                                            }
                                                            yyval.code = gen_code(temp); 
                                                            }
#line 1632 "trad.tab.c"
    break;

  case 37: /* sentencia_bloque: WHILE '(' expresion ')' '{' instrucciones '}'  */
#line 282 "trad.y"
                                                                    {sprintf(temp, "(loop while %s do\n%s)", yyvsp[-4].code, yyvsp[-1].code);
                                                                      yyval.code = gen_code(temp);
                                                                      }
#line 1640 "trad.tab.c"
    break;

  case 38: /* sentencia_bloque: FOR '(' inicializacion ';' expresion ';' incremento ')' '{' instrucciones '}'  */
#line 286 "trad.y"
                                                                                                    {sprintf(temp, "%s\n(loop while %s do\n%s\n%s)", 
                                                                                                        yyvsp[-8].code, yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code);
                                                                                                        yyval.code = gen_code(temp);
                                                                                                    }
#line 1649 "trad.tab.c"
    break;

  case 39: /* if_sin_else: IF '(' expresion ')' '{' instrucciones '}'  */
#line 294 "trad.y"
                                                              {
                                                                if (strchr(yyvsp[-1].code, '\n') != NULL) {
                                                                    sprintf(temp, "(if %s\n(progn %s))", yyvsp[-4].code, yyvsp[-1].code);
                                                                } else {
                                                                    sprintf(temp, "(if %s\n%s)", yyvsp[-4].code, yyvsp[-1].code);
                                                                }
                                                                yyval.code = gen_code(temp);
                                                                }
#line 1662 "trad.tab.c"
    break;

  case 40: /* if_con_else: IF '(' expresion ')' '{' instrucciones '}' ELSE '{' instrucciones '}'  */
#line 305 "trad.y"
                                                                                          {
                                                                                            if (strchr(yyvsp[-5].code, '\n') != NULL && strchr(yyvsp[-1].code, '\n') != NULL) {
                                                                                            sprintf(temp, "(if %s\n(progn\n%s)\n(progn\n%s))", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code);
                                                                                            } else if (strchr(yyvsp[-5].code, '\n') != NULL) {
                                                                                            sprintf(temp, "(if %s\n(progn\n%s)\n%s)", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code);
                                                                                            } else if (strchr(yyvsp[-1].code, '\n') != NULL) {
                                                                                            sprintf(temp, "(if %s\n%s\n(progn\n%s))", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code);
                                                                                            } else {
                                                                                            sprintf(temp, "(if %s\n%s\n%s\n)", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code);
                                                                                            }
                                                                                            yyval.code = gen_code(temp);
                                                                                            }
#line 1679 "trad.tab.c"
    break;

  case 41: /* inicializacion: INTEGER IDENTIF '=' operando  */
#line 321 "trad.y"
                                                 {sprintf(temp, "(setq %s_%s %s)", current_function, yyvsp[-3].code, yyvsp[-1].code);
                                           yyval.code = gen_code(temp);
                                           }
#line 1687 "trad.tab.c"
    break;

  case 42: /* inicializacion: IDENTIF '=' operando  */
#line 324 "trad.y"
                                           {sprintf(temp, "(setf %s_%s %s)",current_function, yyvsp[-2].code,  yyvsp[0].code);
                                           yyval.code = gen_code(temp);
                                           }
#line 1695 "trad.tab.c"
    break;

  case 43: /* incremento: IDENTIF '=' expresion  */
#line 332 "trad.y"
                                          {sprintf(temp, "(setf %s_%s %s)",  current_function, yyvsp[-2].code, yyvsp[0].code);
                                            yyval.code = gen_code(temp);
                                            }
#line 1703 "trad.tab.c"
    break;

  case 44: /* declaracion_variable: INTEGER lista_declaracion  */
#line 338 "trad.y"
                                                { yyval.code = yyvsp[0].code; }
#line 1709 "trad.tab.c"
    break;

  case 45: /* lista_declaracion: IDENTIF  */
#line 342 "trad.y"
                            {add_local_var(yyvsp[0].code);
                            sprintf(temp, "(setq %s_%s 0)", current_function, yyvsp[0].code);
                            yyval.code = gen_code(temp); 
                            }
#line 1718 "trad.tab.c"
    break;

  case 46: /* lista_declaracion: IDENTIF '=' NUMBER  */
#line 346 "trad.y"
                                         {add_local_var(yyvsp[-2].code);
                                            sprintf(temp, "(setq %s_%s %d)", current_function, yyvsp[-2].code, yyvsp[0].value);
                                            yyval.code = gen_code(temp); 
                                            }
#line 1727 "trad.tab.c"
    break;

  case 47: /* lista_declaracion: IDENTIF '[' NUMBER ']'  */
#line 350 "trad.y"
                                             {add_local_var(yyvsp[-3].code);
                                                sprintf(temp, "(setq %s_%s (make-array %d))",current_function, yyvsp[-3].code, yyvsp[-1].value);
                                                yyval.code = gen_code(temp);
                                                }
#line 1736 "trad.tab.c"
    break;

  case 48: /* lista_declaracion: lista_declaracion ',' IDENTIF  */
#line 354 "trad.y"
                                                    {add_local_var(yyvsp[0].code);
                                                    sprintf(temp, "%s\n(setq %s_%s 0)", yyvsp[-2].code, current_function, yyvsp[0].code);
                                                    yyval.code = gen_code(temp); 
                                                    }
#line 1745 "trad.tab.c"
    break;

  case 49: /* lista_declaracion: lista_declaracion ',' IDENTIF '=' NUMBER  */
#line 358 "trad.y"
                                                               {add_local_var(yyvsp[-2].code);
                                                                sprintf(temp, "%s\n(setq %s_%s %d)", yyvsp[-4].code, current_function, yyvsp[-2].code, yyvsp[0].value);
                                                                yyval.code = gen_code(temp); 
                                                                }
#line 1754 "trad.tab.c"
    break;

  case 50: /* lista_declaracion: lista_declaracion ',' IDENTIF '[' NUMBER ']'  */
#line 362 "trad.y"
                                                                   {add_local_var(yyvsp[-3].code);
                                                                    sprintf(temp, "(setq %s_%s (make-array %d))", current_function,yyvsp[-5].code, yyvsp[-3].value);
                                                                    yyval.code = gen_code(temp);
                                                                    }
#line 1763 "trad.tab.c"
    break;

  case 51: /* expresion: termino  */
#line 369 "trad.y"
                                              { yyval = yyvsp[0]; }
#line 1769 "trad.tab.c"
    break;

  case 52: /* expresion: expresion '+' expresion  */
#line 370 "trad.y"
                                                  { sprintf(temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1777 "trad.tab.c"
    break;

  case 53: /* expresion: expresion '-' expresion  */
#line 373 "trad.y"
                                                  { sprintf(temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1785 "trad.tab.c"
    break;

  case 54: /* expresion: expresion '*' expresion  */
#line 376 "trad.y"
                                                  { sprintf(temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1793 "trad.tab.c"
    break;

  case 55: /* expresion: expresion '/' expresion  */
#line 379 "trad.y"
                                                  { sprintf(temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1801 "trad.tab.c"
    break;

  case 56: /* expresion: expresion '>' expresion  */
#line 382 "trad.y"
                                                  { sprintf(temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1809 "trad.tab.c"
    break;

  case 57: /* expresion: expresion '<' expresion  */
#line 385 "trad.y"
                                                  { sprintf(temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1817 "trad.tab.c"
    break;

  case 58: /* expresion: expresion IGUAL expresion  */
#line 388 "trad.y"
                                                     { sprintf(temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1825 "trad.tab.c"
    break;

  case 59: /* expresion: expresion DISTINTO expresion  */
#line 391 "trad.y"
                                                     { sprintf(temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1833 "trad.tab.c"
    break;

  case 60: /* expresion: expresion MENORIGUAL expresion  */
#line 394 "trad.y"
                                                     { sprintf(temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1841 "trad.tab.c"
    break;

  case 61: /* expresion: expresion MAYORIGUAL expresion  */
#line 397 "trad.y"
                                                     { sprintf(temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1849 "trad.tab.c"
    break;

  case 62: /* expresion: expresion AND expresion  */
#line 400 "trad.y"
                                                 { sprintf(temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                yyval.code = gen_code(temp);
                                                }
#line 1857 "trad.tab.c"
    break;

  case 63: /* expresion: expresion OR expresion  */
#line 403 "trad.y"
                                                 { sprintf(temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                yyval.code = gen_code(temp);
                                                }
#line 1865 "trad.tab.c"
    break;

  case 64: /* expresion: '!' expresion  */
#line 406 "trad.y"
                                                     { sprintf(temp, "(not %s)", yyvsp[0].code);
                                                        yyval.code = gen_code(temp);
                                                        }
#line 1873 "trad.tab.c"
    break;

  case 65: /* expresion: expresion '%' expresion  */
#line 409 "trad.y"
                                                { sprintf(temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                }
#line 1881 "trad.tab.c"
    break;

  case 66: /* expresion: IDENTIF '(' argumentos ')'  */
#line 412 "trad.y"
                                                { sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code);
                                                yyval.code = gen_code(temp);
                                                }
#line 1889 "trad.tab.c"
    break;

  case 67: /* termino: operando  */
#line 418 "trad.y"
                                              { yyval = yyvsp[0]; }
#line 1895 "trad.tab.c"
    break;

  case 68: /* termino: '+' operando  */
#line 419 "trad.y"
                                                    { yyval = yyvsp[0]; }
#line 1901 "trad.tab.c"
    break;

  case 69: /* termino: '-' operando  */
#line 420 "trad.y"
                                                    { sprintf(temp, "(- %s)", yyvsp[0].code);
                                                    yyval.code = gen_code(temp); 
                                                    }
#line 1909 "trad.tab.c"
    break;

  case 70: /* operando: IDENTIF  */
#line 426 "trad.y"
                            {
                                if(current_function != NULL && is_local_var(yyvsp[0].code)) {
                                    // Variable local o parámetro
                                    sprintf(temp, "%s_%s", current_function, yyvsp[0].code);
                                } else {
                                    // Variable global
                                    sprintf(temp, "%s", yyvsp[0].code);
                                }
                                yyval.code = gen_code(temp); 
                            }
#line 1924 "trad.tab.c"
    break;

  case 71: /* operando: NUMBER  */
#line 436 "trad.y"
                                { sprintf(temp, "%d", yyvsp[0].value);
                                  yyval.code = gen_code(temp);
                                  }
#line 1932 "trad.tab.c"
    break;

  case 72: /* operando: '(' expresion ')'  */
#line 439 "trad.y"
                                                  { yyval = yyvsp[-1]; }
#line 1938 "trad.tab.c"
    break;

  case 73: /* operando: IDENTIF '[' expresion ']'  */
#line 440 "trad.y"
                                                {
                                                if(current_function != NULL && is_local_var(yyvsp[-3].code)) {
                                                    // Variable local o parámetro
                                                    sprintf(temp, "(aref %s_%s %s)", current_function, yyvsp[-3].code, yyvsp[-1].code);
                                                } else {
                                                    // Variable global
                                                    sprintf(temp, "(aref %s %s)", yyvsp[-3].code, yyvsp[-1].code);
                                                }
                                                yyval.code = gen_code(temp);
                                            }
#line 1953 "trad.tab.c"
    break;

  case 74: /* argumentos: %empty  */
#line 453 "trad.y"
                                 { yyval.code = gen_code(""); }
#line 1959 "trad.tab.c"
    break;

  case 75: /* argumentos: lista_argumentos  */
#line 454 "trad.y"
                                       { yyval.code = yyvsp[0].code; }
#line 1965 "trad.tab.c"
    break;

  case 76: /* lista_argumentos: expresion  */
#line 458 "trad.y"
                              { yyval.code = yyvsp[0].code; }
#line 1971 "trad.tab.c"
    break;

  case 77: /* lista_argumentos: lista_argumentos ',' expresion  */
#line 459 "trad.y"
                                                     { sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1979 "trad.tab.c"
    break;

  case 78: /* lista_elementos: elemento  */
#line 465 "trad.y"
                             { yyval.code = yyvsp[0].code; }
#line 1985 "trad.tab.c"
    break;

  case 79: /* lista_elementos: lista_elementos ',' elemento  */
#line 466 "trad.y"
                                                   { sprintf(temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code);
                                                    yyval.code = gen_code(temp);
                                                    }
#line 1993 "trad.tab.c"
    break;

  case 80: /* elemento: expresion  */
#line 471 "trad.y"
                              { sprintf(temp, "(princ %s)", yyvsp[0].code);
                                 yyval.code = gen_code(temp);
                                 }
#line 2001 "trad.tab.c"
    break;

  case 81: /* elemento: STRING  */
#line 474 "trad.y"
                             { sprintf(temp, "(princ \"%s\")", yyvsp[0].code);
                                 yyval.code = gen_code(temp);
                                 }
#line 2009 "trad.tab.c"
    break;


#line 2013 "trad.tab.c"

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

#line 481 "trad.y"
                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *mi_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "if",          IF,
    "else",        ELSE,
    "while",       WHILE,
    "puts",        PUTS,
    "printf",      PRINTF,
    "==",          IGUAL,
    "!=",          DISTINTO,
    "<=",          MENORIGUAL,
    ">=",          MAYORIGUAL,
    "&&",          AND,
    "||",          OR,
    "for",         FOR, 
    "return",       RETURN,
    NULL,          0               // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) mi_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return ( symbol ->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}

int main() {
    yyparse();
    return 0;
}
