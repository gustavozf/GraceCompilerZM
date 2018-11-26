/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "gczm.y" /* yacc.c:339  */

/* Declaracoes */
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include "./structs/exp.h"
#include "./structs/cmd.h"
#include "./structs/dec.h"
#include "./structs/prog.h"

using namespace std;

// Coisas do Flex que o Bison precisa
extern int yylex();
extern int yyparse();
extern FILE *yyin;

extern int num_linhas;
extern int num_carac;

// Tratar Erros (aparentemente obrigatorio)
void yyerror(const char *s);

list<Decl *> *raiz = nullptr;
Escopo *escopoAtual = new Escopo(nullptr);

#line 94 "gczm.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "gczm.tab.h".  */
#ifndef YY_YY_GCZM_TAB_H_INCLUDED
# define YY_YY_GCZM_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_BOOL = 258,
    T_INT = 259,
    T_STRING = 260,
    T_IF = 261,
    T_ELSE = 262,
    T_FOR = 263,
    T_WHILE = 264,
    T_WRITE = 265,
    T_READ = 266,
    T_DEF = 267,
    T_RETURN = 268,
    T_VAR = 269,
    T_SKIP = 270,
    T_STOP = 271,
    T_TRUE = 272,
    T_FALSE = 273,
    T_ABRE_PARENTESES = 274,
    T_FECHA_PARENTESES = 275,
    T_ABRE_COLCHETES = 276,
    T_FECHA_COLCHETES = 277,
    T_ABRE_CHAVES = 278,
    T_FECHA_CHAVES = 279,
    T_VIRGULA = 280,
    T_PONTO_VIRGULA = 281,
    T_ADICAO = 282,
    T_SUBTRACAO = 283,
    T_MULTIPLICACAO = 284,
    T_DIVISAO = 285,
    T_MODULO = 286,
    T_EQ_LOGICA = 287,
    T_DIF_LOGICA = 288,
    T_MAIOR = 289,
    T_MAIOR_IGUAL = 290,
    T_MENOR = 291,
    T_MENOR_IGUAL = 292,
    T_OR = 293,
    T_AND = 294,
    T_NOT = 295,
    T_ATRIBUICAO = 296,
    T_ATRIB_SOMA = 297,
    T_ATRIB_SUB = 298,
    T_ATRIB_MULT = 299,
    T_ATRIB_DIV = 300,
    T_ATRIB_MOD = 301,
    T_COND_OP_TER = 302,
    T_DOIS_PON = 303,
    T_ID = 304,
    T_NUM = 305,
    T_LIT_STRING = 306,
    T_NEG_UNAR = 307,
    T_THEN = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "gczm.y" /* yacc.c:355  */

	char *sval; // String
	
	// Nos AST
	TipoVar *tipoVar;
	Cmd *cmd;
	Exp *exp;
	Decl *decl;
	SpecVar *specVar;
	Param *param;
	SpecParam *specParam;

	// Listas
	list<Exp *> *cnjExp;
	list<Cmd *> *cnjCmd;
	list<SpecVar *> *cnjSpecVar;
	list<Param *> *cnjParam;
	list<SpecParam *> *cnjSpecParam;
	list<Decl *> *cnjDecl;

#line 209 "gczm.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GCZM_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "gczm.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   490

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   144,   144,   148,   149,   153,   156,   163,   168,   169,
     170,   171,   175,   176,   180,   181,   182,   183,   187,   188,
     192,   193,   194,   195,   200,   201,   205,   206,   210,   211,
     215,   216,   220,   224,   225,   229,   230,   235,   236,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   254,
     259,   260,   264,   265,   266,   267,   268,   273,   274,   278,
     282,   286,   290,   294,   299,   304,   305,   312,   313,   319,
     324,   330,   333,   336,   345,   349,   350,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   380,   381
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_BOOL", "T_INT", "T_STRING", "T_IF",
  "T_ELSE", "T_FOR", "T_WHILE", "T_WRITE", "T_READ", "T_DEF", "T_RETURN",
  "T_VAR", "T_SKIP", "T_STOP", "T_TRUE", "T_FALSE", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\",\"", "\";\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"%\"", "\"==\"", "\"!=\"", "\">\"", "\">=\"",
  "\"<\"", "\"<=\"", "\"||\"", "\"&&\"", "\"!\"", "\"=\"", "\"+=\"",
  "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"?\"", "\":\"", "T_ID",
  "T_NUM", "T_LIT_STRING", "T_NEG_UNAR", "T_THEN", "$accept", "programa",
  "declaracoes", "declaracao", "decVar", "tipo", "listaSpecVars",
  "specVar", "cnjExpr", "valor", "decSub", "decProc", "decFun",
  "listaParametros", "specParams", "specParamsN", "param", "comando",
  "cmdSimples", "cmdAtrib", "tiposAtrib", "atribAgreg", "cmdIf",
  "cmdWhile", "cmdFor", "atrib-ini", "atrib-passo", "cmdStop", "cmdSkip",
  "cmdReturn", "cmdChamadaProc", "cmdRead", "cmdWrite", "bloco",
  "blocoEnd", "comandos", "expressao", "variavel", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,    22,    48,   106,    24,   -83,   -83,   -83,   -83,   -83,
      94,    -4,     9,   -83,   -83,   -83,   -14,   166,   166,    48,
      99,     8,    93,    53,   -83,    40,   -83,   -83,   -83,   166,
     166,   166,     1,   -83,   -83,   -83,   261,   -83,   391,   -83,
     -83,   -83,    95,    89,   133,    99,   -83,    97,    41,    80,
      80,    99,   198,   391,   391,    50,   166,    90,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,    84,   -83,   111,   119,   131,   166,   103,    58,
     127,   129,    66,   112,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   163,   159,   134,
     -83,    99,   -83,   -83,   -83,   -83,   -83,   -83,    -1,   391,
     282,   135,   423,   423,   407,   407,   407,   -29,   -29,   443,
     443,   433,   433,   113,    34,   303,   140,   166,   114,   166,
     -18,   144,   141,   -83,   326,   -83,   -83,   171,   -83,   -83,
     163,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   166,
     -83,   -83,   134,   -83,   166,   -83,   166,   166,   -83,   219,
     125,   142,   240,   -83,   -83,   -83,   149,    71,   -83,   348,
     -83,   391,    69,   113,    17,   130,   166,    17,   -83,   151,
     -83,   -83,   174,   -83,   370,   -83,   -83,    17,   143,   -83,
     280,   173,   145,    17,   -83,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     6,    24,    25,
       0,    14,     0,    13,     1,     3,     0,     0,     0,     0,
       0,     0,    35,     0,    31,     0,    34,    20,    21,     0,
       0,     0,    98,    23,    22,    77,     0,    78,    15,    12,
       8,     9,    10,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,    76,    37,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    38,     0,     0,     0,
      36,     0,    26,    30,    33,    32,    79,    96,     0,    19,
       0,     0,    85,    86,    82,    83,    84,    91,    92,    89,
      90,    87,    88,    94,    93,     0,     0,     0,     0,     0,
       0,    98,     0,    65,     0,    64,    63,     0,    74,    71,
       0,    75,    72,    51,    55,    56,    54,    52,    53,     0,
      50,    29,     0,    97,     0,    99,     0,     0,    11,     0,
       0,     0,     0,    70,    69,    66,     0,     0,    73,     0,
      28,    18,     0,    95,     0,     0,     0,     0,    67,     0,
      49,    17,    57,    61,     0,    59,    68,     0,     0,    58,
       0,     0,     0,     0,    62,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   152,     0,   -83,   -40,   -83,   178,   -74,   -83,
     -83,   -83,   -83,   -83,   158,   -83,   148,   -82,   -83,   -83,
     -83,    18,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -19,   -81,   126,   -17,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    43,    12,    13,   108,    35,
       7,     8,     9,    23,    24,    25,    26,    84,    85,    86,
     149,   150,    87,    88,    89,   161,   191,    90,    91,    92,
      93,    94,    95,    96,   139,    97,   109,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    38,    46,   130,    15,    99,    21,   154,   163,    69,
      70,   105,    52,    53,    54,   141,   142,    17,    71,   153,
      55,    98,    56,    74,   154,    75,    76,    77,    78,   102,
      79,    44,    80,    81,    19,    22,     1,    18,     2,   110,
      44,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   132,    45,    20,   141,   168,
      98,   152,   134,   167,    44,    50,    82,    27,    28,    29,
     107,    10,    69,    48,    98,    27,    28,    29,    30,    49,
     151,    71,   172,    15,   133,   137,    30,    56,    51,   101,
      31,   179,   182,   181,   154,   185,   154,    11,    31,    32,
      33,    34,    40,    41,    42,   189,    14,    32,    33,    34,
     159,   195,   162,    16,    47,    73,    72,    98,    74,   100,
      75,    76,    77,    78,     1,    79,     2,    80,    81,    22,
     127,   111,   169,   170,   126,    44,   138,   171,   128,    74,
     173,    75,    76,    77,    78,     1,    79,     2,    80,    81,
     129,    98,   131,   135,    98,   136,    44,    44,   156,   184,
      71,    82,   158,   160,    98,    56,   175,   164,   176,    74,
      98,    75,    76,    77,    78,   178,    79,   186,    80,    81,
     183,   187,    82,    27,    28,    29,    44,   138,    27,    28,
      29,   166,   190,   193,    30,   194,    83,    39,   104,    30,
     143,   144,   145,   146,   147,   148,    31,   103,   192,   140,
       0,    31,    82,     0,     0,    32,    33,    34,   106,     0,
      32,    33,    34,     0,     0,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,   174,
       0,     0,     0,     0,     0,    71,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
     177,     0,     0,     0,     0,     0,    71,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,     0,    57,     0,     0,     0,    71,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,     0,   155,     0,     0,     0,    71,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,   144,   145,   146,   147,   148,     0,     0,    71,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,     0,     0,     0,     0,     0,
      71,   157,   165,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,     0,     0,
       0,     0,     0,    71,   180,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,     0,
       0,     0,     0,     0,     0,    71,   188,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,     0,     0,     0,    71,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,     0,    58,    59,     0,     0,    71,    63,
      64,    65,    66,    67,    68,    69,    70,     0,     0,     0,
       0,     0,     0,     0,    71,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,    63,    64,    65,    66,     0,
      71,    69,    70,     0,     0,    63,    64,     0,     0,     0,
      71,    69,    70,     0,     0,     0,     0,     0,     0,     0,
      71
};

static const yytype_int16 yycheck[] =
{
      17,    18,    21,    77,     4,    45,    20,    25,    26,    38,
      39,    51,    29,    30,    31,    97,    97,    21,    47,    20,
      19,    44,    21,     6,    25,     8,     9,    10,    11,    48,
      13,    23,    15,    16,    25,    49,    12,    41,    14,    56,
      23,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    78,    48,    48,   140,   140,
      83,   101,    79,   137,    23,    25,    49,    17,    18,    19,
      20,    49,    38,    20,    97,    17,    18,    19,    28,    26,
      99,    47,   156,    83,    26,    19,    28,    21,    48,    48,
      40,    20,   174,    24,    25,   177,    25,    49,    40,    49,
      50,    51,     3,     4,     5,   187,     0,    49,    50,    51,
     127,   193,   129,    19,    21,    26,    21,   140,     6,    22,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    49,
      19,    41,   149,   152,    50,    23,    24,   154,    19,     6,
     157,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      19,   174,    49,    26,   177,    26,    23,    23,    23,   176,
      47,    49,    22,    49,   187,    21,    41,    26,    26,     6,
     193,     8,     9,    10,    11,    26,    13,    26,    15,    16,
      50,     7,    49,    17,    18,    19,    23,    24,    17,    18,
      19,    20,    49,    20,    28,    50,    44,    19,    50,    28,
      41,    42,    43,    44,    45,    46,    40,    49,   190,    83,
      -1,    40,    49,    -1,    -1,    49,    50,    51,    20,    -1,
      49,    50,    51,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    47,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    47,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    47,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    22,    -1,    -1,    -1,    47,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    42,    43,    44,    45,    46,    -1,    -1,    47,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    27,    28,    -1,    -1,    47,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    32,    33,    34,    35,    -1,
      47,    38,    39,    -1,    -1,    32,    33,    -1,    -1,    -1,
      47,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    14,    55,    56,    57,    58,    64,    65,    66,
      49,    49,    60,    61,     0,    57,    19,    21,    41,    25,
      48,    20,    49,    67,    68,    69,    70,    17,    18,    19,
      28,    40,    49,    50,    51,    63,    90,    91,    90,    61,
       3,     4,     5,    59,    23,    48,    87,    21,    20,    26,
      25,    48,    90,    90,    90,    19,    21,    22,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    47,    21,    26,     6,     8,     9,    10,    11,    13,
      15,    16,    49,    56,    71,    72,    73,    76,    77,    78,
      81,    82,    83,    84,    85,    86,    87,    89,    91,    59,
      22,    48,    87,    68,    70,    59,    20,    20,    62,    90,
      90,    41,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    50,    19,    19,    19,
      62,    49,    91,    26,    90,    26,    26,    19,    24,    88,
      89,    71,    88,    41,    42,    43,    44,    45,    46,    74,
      75,    87,    59,    20,    25,    22,    23,    48,    22,    90,
      49,    79,    90,    26,    26,    26,    20,    62,    88,    90,
      87,    90,    62,    90,    20,    41,    26,    20,    26,    20,
      26,    24,    71,    50,    90,    71,    26,     7,    26,    71,
      49,    80,    75,    20,    50,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      59,    59,    60,    60,    61,    61,    61,    61,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    76,    76,    77,
      78,    79,    80,    81,    82,    83,    83,    84,    84,    85,
      86,    87,    87,    87,    88,    89,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     5,     1,     1,
       1,     4,     3,     1,     1,     3,     4,     8,     3,     1,
       1,     1,     1,     1,     1,     1,     6,     5,     8,     7,
       3,     1,     3,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     5,     7,     5,
       9,     3,     3,     2,     2,     2,     3,     4,     5,     3,
       3,     3,     3,     4,     1,     2,     1,     1,     1,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     3,     4,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 144 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjDecl) = (yyvsp[0].cnjDecl); raiz = (yyval.cnjDecl); cout << "Programa Reconhecido!" << endl; }
#line 1502 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 148 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjDecl) = (yyvsp[-1].cnjDecl); (yyval.cnjDecl)->push_back((yyvsp[0].decl)); 					}
#line 1508 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 149 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjDecl) = new list<Decl *>(); (yyval.cnjDecl)->push_back((yyvsp[0].decl));	}
#line 1514 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 153 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); 
				  (yyval.decl)->addTabSimb(escopoAtual);
				}
#line 1522 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 156 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); 
				  (yyval.decl)->addTabSimb(escopoAtual);
				}
#line 1530 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 163 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclVar((yyvsp[-3].cnjSpecVar), (yyvsp[-1].tipoVar)); }
#line 1536 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 168 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new BoolTipoVar();	 }
#line 1542 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 169 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new IntTipoVar();		 }
#line 1548 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 170 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new StringTipoVar();   }
#line 1554 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 171 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new StringTipoVar((yyvsp[-1].sval)); }
#line 1560 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 175 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecVar) = (yyvsp[-2].cnjSpecVar); (yyval.cnjSpecVar)->push_back((yyvsp[0].specVar)); 					 }
#line 1566 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 176 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecVar) = new list<SpecVar *>(); (yyval.cnjSpecVar)->push_back((yyvsp[0].specVar)); }
#line 1572 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 180 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarSimples((yyvsp[0].sval)); 		   }
#line 1578 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 181 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarSimples((yyvsp[-2].sval), (yyvsp[0].exp)); 	   }
#line 1584 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 182 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarArranjo((yyvsp[-3].sval), (yyvsp[-1].exp));	   }
#line 1590 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 183 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarArranjo((yyvsp[-7].sval), (yyvsp[-5].exp), (yyvsp[-1].cnjExp)); }
#line 1596 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 187 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjExp) = (yyvsp[-2].cnjExp); (yyval.cnjExp)->push_back((yyvsp[0].exp)); 			   }
#line 1602 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 188 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjExp) = new list<Exp *>(); (yyval.cnjExp)->push_back((yyvsp[0].exp)); }
#line 1608 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 192 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "bool");   }
#line 1614 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 193 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "bool");   }
#line 1620 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 194 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "string"); }
#line 1626 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 195 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "int");	 }
#line 1632 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 200 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); }
#line 1638 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 201 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); }
#line 1644 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 205 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-4].sval), (yyvsp[-2].cnjSpecParam), (yyvsp[0].cmd)); }
#line 1650 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 206 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-3].sval), (yyvsp[0].cmd)); }
#line 1656 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 210 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-6].sval), (yyvsp[-4].cnjSpecParam), (yyvsp[-1].tipoVar), (yyvsp[0].cmd)); }
#line 1662 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 211 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-5].sval), (yyvsp[-1].tipoVar), (yyvsp[0].cmd)); }
#line 1668 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 215 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecParam) = (yyvsp[-2].cnjSpecParam); (yyval.cnjSpecParam)->push_back((yyvsp[0].specParam));					   }
#line 1674 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 216 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecParam) = new list<SpecParam *>(); (yyval.cnjSpecParam)->push_back((yyvsp[0].specParam)); }
#line 1680 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 220 "gczm.y" /* yacc.c:1646  */
    { (yyval.specParam) = new SpecParam((yyvsp[-2].cnjParam), (yyvsp[0].tipoVar)); }
#line 1686 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 224 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjParam) = (yyvsp[-2].cnjParam); (yyval.cnjParam)->push_back((yyvsp[0].param));				   }
#line 1692 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 225 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjParam) = new list<Param *>(); (yyval.cnjParam)->push_back((yyvsp[0].param)); }
#line 1698 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 229 "gczm.y" /* yacc.c:1646  */
    { (yyval.param) = new Param((yyvsp[0].sval), false); }
#line 1704 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 230 "gczm.y" /* yacc.c:1646  */
    { (yyval.param) = new Param((yyvsp[-2].sval), true); }
#line 1710 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 235 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = (yyvsp[0].cmd); }
#line 1716 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 236 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = (yyvsp[0].cmd); }
#line 1722 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 240 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1728 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 241 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1734 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 242 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1740 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 243 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1746 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 244 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1752 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 245 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1758 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 246 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1764 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 247 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1770 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 248 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1776 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 249 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1782 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 254 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new AtribCmd((yyvsp[-3].exp), (yyvsp[-2].sval), (yyvsp[-1].exp));}
#line 1788 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 259 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1794 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 260 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1800 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 264 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1806 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 265 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1812 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 266 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1818 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 267 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1824 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 268 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1830 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 273 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new IfCmd((yyvsp[-2].exp), (yyvsp[0].cmd));     }
#line 1836 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 274 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new IfCmd((yyvsp[-4].exp), (yyvsp[-2].cmd), (yyvsp[0].cmd)); }
#line 1842 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 278 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new WhileCmd((yyvsp[-2].exp), (yyvsp[0].cmd));}
#line 1848 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 282 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new ForCmd((yyvsp[-6].exp), (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].cmd));}
#line 1854 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 286 "gczm.y" /* yacc.c:1646  */
    {(yyval.exp) = new AtribFor((yyvsp[-2].sval), (yyvsp[0].sval));}
#line 1860 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 290 "gczm.y" /* yacc.c:1646  */
    {(yyval.exp) = new AtribFor((yyvsp[-2].sval), (yyvsp[-1].sval), (yyvsp[0].sval));}
#line 1866 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 294 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new StopSkipCmd((yyvsp[-1].sval));}
#line 1872 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 299 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new StopSkipCmd((yyvsp[-1].sval));}
#line 1878 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 304 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new RetCmd();}
#line 1884 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 305 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new RetCmd((yyvsp[-1].exp));}
#line 1890 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 312 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ProcCmd((yyvsp[-3].sval)); 	}
#line 1896 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 313 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ProcCmd((yyvsp[-4].sval), (yyvsp[-2].cnjExp)); }
#line 1902 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 319 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ReadCmd((yyvsp[-1].exp)); }
#line 1908 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 324 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new WriteCmd((yyvsp[-1].cnjExp)); }
#line 1914 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 330 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new BlocoCmd((yyvsp[-1].cnjDecl)); 
	  												  escopoAtual = new Escopo(escopoAtual);
	  												}
#line 1922 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 333 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new BlocoCmd((yyvsp[-1].cnjCmd)); 
													  escopoAtual = new Escopo(escopoAtual);
													}
#line 1930 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 336 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new BlocoCmd((yyvsp[-2].cnjDecl), (yyvsp[-1].cnjCmd)); 
													  escopoAtual = new Escopo(escopoAtual);
													}
#line 1938 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 345 "gczm.y" /* yacc.c:1646  */
    { escopoAtual = escopoAtual->getPai(); }
#line 1944 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 349 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjCmd) = (yyvsp[-1].cnjCmd); (yyval.cnjCmd)->push_back((yyvsp[0].cmd)); 				 }
#line 1950 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 350 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjCmd) = new list<Cmd *>(); (yyval.cnjCmd)->push_back((yyvsp[0].cmd)); }
#line 1956 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 356 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = (yyvsp[0].exp);						}
#line 1962 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 357 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = (yyvsp[0].exp);						}
#line 1968 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 358 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = (yyvsp[-1].exp);						}
#line 1974 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 359 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new NegUnExp((yyvsp[0].exp));		  	}
#line 1980 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 360 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new NegExp((yyvsp[0].exp));			}
#line 1986 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 361 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval)); 	}
#line 1992 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 362 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval)); 	}
#line 1998 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 363 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval)); 	}
#line 2004 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 364 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval)); 	}
#line 2010 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 365 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval)); 	}
#line 2016 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 366 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval));	}
#line 2022 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 367 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval));	}
#line 2028 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 368 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval));	}
#line 2034 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 369 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval));	}
#line 2040 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 370 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new IgExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval));		}
#line 2046 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 371 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new IgExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval));		}
#line 2052 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 372 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new LogExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval));	}
#line 2058 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 373 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new LogExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval));	}
#line 2064 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 374 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new TerExp((yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp));	}
#line 2070 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 375 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new FuncExp((yyvsp[-2].sval)); 			}
#line 2076 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 376 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new FuncExp((yyvsp[-3].sval), (yyvsp[-1].cnjExp)); 		}
#line 2082 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 380 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new VarExp((yyvsp[0].sval));     }
#line 2088 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 381 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new VarExp((yyvsp[-3].sval), (yyvsp[-1].exp)); }
#line 2094 "gczm.tab.c" /* yacc.c:1646  */
    break;


#line 2098 "gczm.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 384 "gczm.y" /* yacc.c:1906  */


/* Codificacao C++ */
int main(int argc, char *argv[]){
	if(argc < 2){
		cout << "ERRO: Eh necessario passar o nome do arquivo de entrada!\n";

		return 0;
	}

	FILE *entrada = fopen(argv[1], "r");

	if (!entrada) {
		cout << "Erro ao abrir o arquivo: '" << argv[1] << "'!\n";
		return -1;
	}

	yyin = entrada;

    yyparse();

	return 0;
}

void yyerror(const char *s){
	cout<< "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): "<< s <<"\n";

	exit(-1);
}
