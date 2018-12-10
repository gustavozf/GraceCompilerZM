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

#define YYDEBUG 1
/* Declaracoes */
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <fstream>
#include "./structs/exp.h"
#include "./structs/cmd.h"
#include "./structs/dec.h"
#include "./structs/prog.h"

using namespace std;

// Coisas do Flex que o Bison precisa
extern int yylex();
extern int yyparse();
extern int yydebug;
extern FILE *yyin;

extern int num_linhas;
extern int num_carac;

// Tratar Erros (aparentemente obrigatorio)
void yyerror(const char *s);

Programa *raiz = nullptr;
Escopo *escopoAtual = new Escopo(nullptr, 0);
int countEscopos = 1;
stack<DeclSub *> *pilhaSubprog = new stack<DeclSub *>();
stack<Cmd *> *pilhaCmdRepet = new stack<Cmd *>();

string nomeSaida = "./compiledOutputs/graceOut.cpp";
ofstream saida(nomeSaida);

#line 103 "gczm.tab.c" /* yacc.c:339  */

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
# define YYDEBUG 1
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
#line 43 "gczm.y" /* yacc.c:355  */

	char *sval; // String
	
	// Nos AST
	TipoVar *tipoVar;
	Cmd *cmd;
	Exp *exp;
	VarExp* varExp;
	Decl *decl;
	SpecVar *specVar;
	Param *param;
	SpecParam *specParam;
	Programa *programa;
	Escopo *escopo;

	// Listas
	list<Exp *> *cnjExp;
	list<Cmd *> *cnjCmd;
	list<SpecVar *> *cnjSpecVar;
	list<Param *> *cnjParam;
	list<SpecParam *> *cnjSpecParam;
	list<Decl *> *cnjDecl;

<<<<<<< HEAD
#line 217 "gczm.tab.c" /* yacc.c:355  */
=======
#line 221 "gczm.tab.c" /* yacc.c:355  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GCZM_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

<<<<<<< HEAD
#line 234 "gczm.tab.c" /* yacc.c:358  */
=======
#line 238 "gczm.tab.c" /* yacc.c:358  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0

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
<<<<<<< HEAD
#define YYLAST   513
=======
#define YYLAST   488
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

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
<<<<<<< HEAD
       0,   158,   158,   167,   168,   172,   175,   182,   183,   187,
     188,   189,   190,   194,   195,   199,   200,   201,   202,   206,
     207,   211,   212,   213,   214,   219,   220,   224,   225,   229,
     230,   234,   235,   239,   243,   244,   248,   249,   254,   255,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     273,   274,   278,   279,   283,   284,   285,   286,   287,   292,
     293,   297,   301,   305,   309,   310,   314,   315,   319,   320,
     321,   322,   327,   328,   329,   330,   334,   335,   339,   340,
     345,   346,   347,   351,   359,   363,   364,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   394,   395,
     396
=======
       0,   161,   161,   179,   180,   184,   187,   194,   198,   199,
     200,   201,   205,   206,   210,   211,   212,   213,   217,   218,
     222,   223,   224,   225,   230,   231,   235,   236,   240,   241,
     245,   246,   250,   254,   255,   259,   260,   265,   266,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   284,
     288,   289,   293,   294,   295,   296,   297,   302,   303,   307,
     311,   315,   319,   323,   327,   328,   333,   334,   338,   342,
     347,   348,   349,   353,   361,   365,   366,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   396,   397
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
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
  "cmdWhile", "cmdFor", "cmdAtribFor", "cmdStop", "cmdSkip", "cmdReturn",
  "cmdChamadaProc", "cmdRead", "cmdWrite", "bloco", "blocoBegin",
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

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
      84,   -40,   -28,    33,    84,   -90,   -90,   -90,   -90,   -90,
      49,   -11,   -19,   -90,   -90,   -90,   -15,   271,   271,   -28,
      23,   -16,    48,    -3,   -90,    -7,   -90,   -90,   -90,   271,
     271,   271,    90,   -90,   -90,   -90,   366,   -90,   431,   -90,
     -90,   -90,    58,    37,   -90,    23,   -90,   238,    63,    16,
      46,    46,    23,   303,   -90,   -90,    53,   271,    59,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,    66,   -90,   -90,   102,   104,   105,   122,
     271,    94,   100,    73,    79,   101,   121,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     249,   175,   -90,    23,   -90,   -90,   -90,   -90,   -90,   -90,
      -1,   431,   154,   124,    47,    47,   -90,   -90,   -90,   476,
     476,   135,   135,    61,    61,   452,   465,   387,   126,   -90,
     271,    94,   271,    34,   131,    81,   -90,   -90,   176,   -90,
     -90,   -90,   -90,   275,   -90,   -90,   249,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,   271,   -90,   102,   -90,   271,
     -90,   -90,   271,   271,   -90,   324,   127,   175,   345,   -90,
     -90,   -90,   -90,   -90,   -90,    82,     0,   -90,   198,   -90,
     431,    12,   431,   268,   271,   271,   268,   -90,   -90,    86,
     -90,   -90,   -90,   147,   410,   431,   -90,   -90,   -90,   268,
      94,   -90,   136,   268,   -90
=======
      18,   -42,   -41,    20,    18,   -85,   -85,   -85,   -85,   -85,
       5,    39,   -20,   -85,   -85,   -85,   -16,   186,   186,   -41,
      34,   -14,     8,    -1,   -85,    -7,   -85,   -85,   -85,   186,
     186,   186,    88,   -85,   -85,   -85,   276,   -85,   406,   -85,
     -85,   -85,    14,    48,   -85,    34,   -85,   114,    43,   -12,
      19,    19,    34,   213,   -85,   -85,   162,   186,    51,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,    55,   -85,    90,   112,   113,   120,   186,
      84,   168,   122,   126,   100,    87,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   134,
      44,   -85,    34,   -85,   -85,   -85,   -85,   -85,   -85,     1,
     406,   297,   123,    86,    86,   -85,   -85,   -85,    42,    42,
     451,   451,   228,   228,   427,   440,   318,   131,   -85,   186,
      84,   186,    37,   135,   129,   -85,   341,   -85,   -85,   181,
     -85,   -85,   134,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   186,   -85,    90,   -85,   186,   -85,   186,   186,   -85,
     234,   136,    44,   255,   -85,   -85,   -85,   140,     2,   -85,
     363,   -85,   406,    57,   406,   161,   186,   186,   161,   -85,
     147,   -85,   -85,   154,   385,   406,   -85,   -85,   161,    84,
     -85,   155,   161,   -85
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     6,    25,    26,
       0,    15,     0,    14,     1,     3,     0,     0,     0,     0,
       0,     0,    36,     0,    32,     0,    35,    21,    22,     0,
       0,     0,   108,    24,    23,    88,     0,    87,    16,    13,
       9,    10,    11,     0,    83,     0,    28,     0,     0,     0,
       0,     0,     0,     0,    90,    91,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,    86,    38,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    39,
       0,     0,    37,     0,    27,    31,    34,    33,    89,   106,
       0,    20,     0,     0,    95,    96,    92,    93,    94,   101,
     102,    99,   100,    97,    98,   104,   103,     0,     0,    30,
       0,     0,     0,     0,   108,     0,    70,    68,     0,    67,
      66,    65,    64,     0,    84,    80,     0,    85,    81,    53,
      57,    58,    56,    54,    55,     0,    52,     0,   107,     0,
     110,   109,     0,     0,    12,     0,     0,     0,     0,    79,
      78,    77,    76,    71,    69,     0,     0,    82,     0,    29,
      19,     0,   105,     0,     0,     0,     0,    74,    72,     0,
      51,    50,    18,    59,     0,    63,    61,    75,    73,     0,
       0,    60,     0,     0,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
     -90,   -90,   110,    -2,   -90,   -37,   -90,   140,   -76,   -90,
     -90,   -90,   -90,   -90,   119,   -90,   109,   -89,   -90,   -90,
       6,   -90,   -90,   -90,   -90,   -21,   -90,   -90,   -90,   -90,
     -90,   -90,   -18,   -90,   -84,   108,   -17,   -25
=======
     -85,   -85,   141,    -2,   -85,   -35,   -85,   159,   -73,   -85,
     -85,   -85,   -85,   -85,   139,   -85,   142,   -84,   -85,   -85,
      29,   -85,   -85,   -85,   -85,     3,   -85,   -85,   -85,   -85,
     -85,   -85,   -18,   -85,   -83,   110,   -17,   -24
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    43,    12,    13,   110,    35,
       7,     8,     9,    23,    24,    25,    26,    87,    88,    89,
     155,   156,    90,    91,    92,   166,    93,    94,    95,    96,
      97,    98,    99,    47,   145,   100,   111,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
<<<<<<< HEAD
      36,    38,    15,    46,   133,    21,    19,    44,    76,    10,
      17,   147,    53,    54,    55,   107,   148,    49,    51,   158,
     189,    11,   101,    50,   159,   159,    40,    41,    42,    20,
      18,   104,    45,    14,    22,   169,   192,   159,    74,    44,
     112,    52,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   135,   147,   129,   159,
     170,   101,   177,    75,   103,   138,   157,   176,    16,    48,
      27,    28,    29,   109,   139,   101,    61,    62,    63,    73,
     141,    30,   171,   187,    15,   102,   181,   197,    59,    60,
      61,    62,    63,    31,   193,    22,     1,   196,     2,   140,
     113,   136,    32,    33,    34,   142,   167,   172,   188,    56,
     201,    57,   198,   165,   204,   168,   128,    27,    28,    29,
     143,   101,    57,   130,   131,    44,   137,    77,    30,    78,
      79,    80,    81,     1,    82,     2,    83,    84,   178,   179,
      31,   132,   180,   134,    44,   144,   182,   162,   164,    32,
      33,    34,    57,   184,   199,   160,   203,    86,   101,    39,
     106,   101,    59,    60,    61,    62,    63,   194,   195,   105,
      85,    68,    69,   185,   101,   167,   161,   173,   101,   202,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,   146,     0,     0,     0,     0,   190,
       0,    72,   174,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   149,   150,   151,   152,
     153,   154,     0,    72,   191,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
       0,     0,     0,     0,    77,    72,    78,    79,    80,    81,
       1,    82,     2,    83,    84,    77,     0,    78,    79,    80,
      81,    44,    82,     0,    83,    84,     0,     0,     0,     0,
       0,     0,    44,   144,    77,     0,    78,    79,    80,    81,
       0,    82,     0,    83,    84,     0,     0,    85,    27,    28,
      29,    44,    27,    28,    29,   175,     0,     0,    85,    30,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,    31,     0,    85,     0,     0,
      32,    33,    34,   108,    32,    33,    34,     0,     0,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,   183,     0,     0,     0,     0,     0,
=======
      36,    38,    15,    46,    21,    19,   132,    10,    11,    44,
      75,    44,    53,    54,    55,   143,   144,   106,    51,    49,
      14,   154,   180,   100,    16,    50,   155,   155,    20,    48,
       1,   103,     2,    22,    45,    73,   102,    40,    41,    42,
     111,    52,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   134,   128,   143,   169,
      17,   100,   155,   164,   136,   101,   168,   153,    22,    59,
      60,    61,    62,    63,    74,   100,    66,    67,    68,    69,
      18,   182,   155,    15,   173,   145,   146,   147,   148,   149,
     150,   183,   112,    76,   186,    77,    78,    79,    80,     1,
      81,     2,    82,    83,   190,   127,   162,    56,   193,    57,
      44,   140,   160,    44,   163,    61,    62,    63,   100,   139,
      76,    57,    77,    78,    79,    80,     1,    81,     2,    82,
      83,   129,   130,   133,   170,   171,    84,    44,   172,   131,
      76,   174,    77,    78,    79,    80,   157,    81,   137,    82,
      83,   100,   138,   159,   100,   165,    57,    44,   140,   184,
     185,   188,   176,    84,   100,   162,   179,    76,   100,    77,
      78,    79,    80,   187,    81,   192,    82,    83,    39,    27,
      28,    29,   108,    84,    44,    27,    28,    29,    85,   104,
      30,   177,   191,   105,   135,   142,    30,     0,    27,    28,
      29,   167,    31,    27,    28,    29,     0,     0,    31,    30,
      84,    32,    33,    34,    30,     0,     0,    32,    33,    34,
       0,    31,     0,     0,     0,     0,    31,     0,     0,     0,
      32,    33,    34,   107,     0,    32,    33,    34,     0,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,   175,    59,    60,    61,    62,    63,
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
      72,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,   186,     0,     0,     0,     0,
       0,    72,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,     0,    58,     0,
       0,     0,    72,    59,    60,    61,    62,    63,    64,    65,
<<<<<<< HEAD
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,     0,     0,    72,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,     0,
       0,     0,     0,     0,    72,   163,   200,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,     0,     0,     0,     0,     0,    72,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,     0,     0,     0,     0,     0,    72,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    71,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    59,    60,    61,    62,    63,     0,     0,
      66,    67,    68,    69
=======
      66,    67,    68,    69,    70,    71,     0,     0,     0,   156,
       0,     0,     0,    72,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,     0,
       0,     0,     0,     0,    72,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
       0,     0,     0,     0,     0,    72,   158,   166,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,     0,     0,     0,     0,     0,    72,   181,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,     0,     0,     0,     0,     0,
      72,   189,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,     0,     0,     0,
       0,     0,    72,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,     0,     0,    72,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,    71,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    59,    60,
      61,    62,    63,     0,     0,     0,     0,    68,    69
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
      17,    18,     4,    21,    80,    20,    25,    23,    45,    49,
      21,   100,    29,    30,    31,    52,   100,    20,    25,    20,
      20,    49,    47,    26,    25,    25,     3,     4,     5,    48,
      41,    49,    48,     0,    49,     1,    24,    25,     1,    23,
      57,    48,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    81,   146,    76,    25,
      26,    86,   146,    26,    48,    82,   103,   143,    19,    21,
      17,    18,    19,    20,     1,   100,    29,    30,    31,    21,
       1,    28,     1,     1,    86,    22,   162,     1,    27,    28,
      29,    30,    31,    40,   183,    49,    12,   186,    14,    26,
      41,     1,    49,    50,    51,    26,   131,    26,    26,    19,
     199,    21,    26,   130,   203,   132,    50,    17,    18,    19,
      19,   146,    21,    19,    19,    23,    26,     6,    28,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   155,   157,
      40,    19,   159,    49,    23,    24,   163,    23,    22,    49,
      50,    51,    21,    26,     7,     1,    20,    47,   183,    19,
      51,   186,    27,    28,    29,    30,    31,   184,   185,    50,
      49,    36,    37,   167,   199,   200,    22,     1,   203,   200,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    86,    -1,    -1,    -1,    -1,     1,
      -1,    47,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    41,    42,    43,    44,
      45,    46,    -1,    47,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    47,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     6,    -1,     8,     9,    10,
      11,    23,    13,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,     6,    -1,     8,     9,    10,    11,
      -1,    13,    -1,    15,    16,    -1,    -1,    49,    17,    18,
      19,    23,    17,    18,    19,    20,    -1,    -1,    49,    28,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    40,    -1,    49,    -1,    -1,
      49,    50,    51,    20,    49,    50,    51,    -1,    -1,    -1,
=======
      17,    18,     4,    21,    20,    25,    79,    49,    49,    23,
      45,    23,    29,    30,    31,    99,    99,    52,    25,    20,
       0,    20,    20,    47,    19,    26,    25,    25,    48,    21,
      12,    49,    14,    49,    48,    21,    48,     3,     4,     5,
      57,    48,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    80,    75,   142,   142,
      21,    85,    25,    26,    81,    22,   139,   102,    49,    27,
      28,    29,    30,    31,    26,    99,    34,    35,    36,    37,
      41,    24,    25,    85,   157,    41,    42,    43,    44,    45,
      46,   175,    41,     6,   178,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   188,    50,   130,    19,   192,    21,
      23,    24,   129,    23,   131,    29,    30,    31,   142,    19,
       6,    21,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    19,    19,    49,   151,   153,    49,    23,   155,    19,
       6,   158,     8,     9,    10,    11,    23,    13,    26,    15,
      16,   175,    26,    22,   178,    26,    21,    23,    24,   176,
     177,     7,    26,    49,   188,   189,    26,     6,   192,     8,
       9,    10,    11,    26,    13,    20,    15,    16,    19,    17,
      18,    19,    20,    49,    23,    17,    18,    19,    47,    50,
      28,   162,   189,    51,    26,    85,    28,    -1,    17,    18,
      19,    20,    40,    17,    18,    19,    -1,    -1,    40,    28,
      49,    49,    50,    51,    28,    -1,    -1,    49,    50,    51,
      -1,    40,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      49,    50,    51,    20,    -1,    49,    50,    51,    -1,    -1,
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    20,    27,    28,    29,    30,    31,
      47,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    47,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    47,    27,    28,    29,    30,    31,    32,    33,
<<<<<<< HEAD
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    36,    37
=======
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    47,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    36,    37
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    14,    55,    56,    57,    58,    64,    65,    66,
      49,    49,    60,    61,     0,    57,    19,    21,    41,    25,
      48,    20,    49,    67,    68,    69,    70,    17,    18,    19,
      28,    40,    49,    50,    51,    63,    90,    91,    90,    61,
       3,     4,     5,    59,    23,    48,    86,    87,    21,    20,
      26,    25,    48,    90,    90,    90,    19,    21,    22,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
<<<<<<< HEAD
      38,    39,    47,    21,     1,    26,    59,     6,     8,     9,
      10,    11,    13,    15,    16,    49,    56,    71,    72,    73,
      76,    77,    78,    80,    81,    82,    83,    84,    85,    86,
      89,    91,    22,    48,    86,    68,    70,    59,    20,    20,
      62,    90,    90,    41,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    50,    86,
      19,    19,    19,    62,    49,    91,     1,    26,    90,     1,
      26,     1,    26,    19,    24,    88,    89,    71,    88,    41,
      42,    43,    44,    45,    46,    74,    75,    59,    20,    25,
       1,    22,    23,    48,    22,    90,    79,    91,    90,     1,
      26,     1,    26,     1,    26,    20,    62,    88,    90,    86,
      90,    62,    90,    20,    26,    74,    20,     1,    26,    20,
       1,    26,    24,    71,    90,    90,    71,     1,    26,     7,
      26,    71,    79,    20,    71
=======
      38,    39,    47,    21,    26,    59,     6,     8,     9,    10,
      11,    13,    15,    16,    49,    56,    71,    72,    73,    76,
      77,    78,    80,    81,    82,    83,    84,    85,    86,    89,
      91,    22,    48,    86,    68,    70,    59,    20,    20,    62,
      90,    90,    41,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    50,    86,    19,
      19,    19,    62,    49,    91,    26,    90,    26,    26,    19,
      24,    88,    89,    71,    88,    41,    42,    43,    44,    45,
      46,    74,    75,    59,    20,    25,    22,    23,    48,    22,
      90,    79,    91,    90,    26,    26,    26,    20,    62,    88,
      90,    86,    90,    62,    90,    20,    26,    74,    20,    26,
      20,    26,    24,    71,    90,    90,    71,    26,     7,    26,
      71,    79,    20,    71
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
<<<<<<< HEAD
       0,    54,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    62,
      62,    63,    63,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    76,
      76,    77,    78,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    87,    88,    89,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91
=======
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      59,    59,    60,    60,    61,    61,    61,    61,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    76,    76,    77,
      78,    79,    80,    81,    82,    82,    83,    83,    84,    85,
      86,    86,    86,    87,    88,    89,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     5,     5,     1,
       1,     1,     4,     3,     1,     1,     3,     4,     8,     3,
       1,     1,     1,     1,     1,     1,     1,     6,     5,     8,
       7,     3,     1,     3,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     5,
       7,     5,     9,     3,     2,     2,     2,     2,     2,     3,
       2,     3,     4,     5,     4,     5,     3,     3,     3,     3,
       3,     3,     4,     1,     1,     2,     1,     1,     1,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     3,     4,     1,     4,
       4
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
#line 161 "gczm.y" /* yacc.c:1646  */
    { (yyval.programa) = new Programa((yyvsp[0].cnjDecl), escopoAtual, num_linhas); 
				  raiz = (yyval.programa); 
				  cout << "\nPrograma reconhecido!\nRealizando Análise Semântica...\n";
				  raiz->eval();
				  cout << "Análise Semântica Realizada!\n";

				  cout << "Gerando código...\n";
				  raiz->codeGen(saida);
				  saida.close();

				  system((string("clang -S -emit-llvm ") + nomeSaida + string(" --output ./compiledOutputs/graceOut.ll")).c_str());
				  system("llc -filetype=obj ./compiledOutputs/graceOut.ll");
				  //system("gcc ./compiledOutputs/graceOut.o -fPIC -o ./compiledOutputs/graceOut");
				  system("g++ ./compiledOutputs/graceOut.cpp -o ./compiledOutputs/graceOut");
				}
<<<<<<< HEAD
#line 1528 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1526 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 3:
#line 179 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjDecl) = (yyvsp[-1].cnjDecl); (yyval.cnjDecl)->push_back((yyvsp[0].decl)); 					}
<<<<<<< HEAD
#line 1534 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1532 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 4:
#line 180 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjDecl) = new list<Decl *>(); (yyval.cnjDecl)->push_back((yyvsp[0].decl));	}
<<<<<<< HEAD
#line 1540 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1538 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 5:
#line 184 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); 
				  (yyval.decl)->addTabSimb(escopoAtual);
				}
<<<<<<< HEAD
#line 1548 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1546 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 6:
#line 187 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); 
				  (yyval.decl)->addTabSimb(escopoAtual);
				}
<<<<<<< HEAD
#line 1556 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1554 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 7:
#line 194 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclVar((yyvsp[-3].cnjSpecVar), (yyvsp[-1].tipoVar)); }
<<<<<<< HEAD
#line 1562 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 183 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclVar((yyvsp[-3].cnjSpecVar), (yyvsp[-1].tipoVar)); yyerrok;}
#line 1568 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 187 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new BoolTipoVar();	 }
#line 1574 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 188 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new IntTipoVar();		 }
#line 1580 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 189 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new StringTipoVar();   }
#line 1586 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 190 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new StringTipoVar((yyvsp[-1].sval)); }
#line 1592 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 194 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecVar) = (yyvsp[-2].cnjSpecVar); (yyval.cnjSpecVar)->push_back((yyvsp[0].specVar)); 					 }
#line 1598 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 195 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecVar) = new list<SpecVar *>(); (yyval.cnjSpecVar)->push_back((yyvsp[0].specVar)); }
#line 1604 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 199 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarSimples((yyvsp[0].sval), num_linhas); 		   }
#line 1610 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 200 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarSimples((yyvsp[-2].sval), (yyvsp[0].exp), num_linhas); 	   }
#line 1616 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 201 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarArranjo((yyvsp[-3].sval), (yyvsp[-1].exp), num_linhas);	   }
#line 1622 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 202 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarArranjo((yyvsp[-7].sval), (yyvsp[-5].exp), (yyvsp[-1].cnjExp), num_linhas); }
#line 1628 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 206 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjExp) = (yyvsp[-2].cnjExp); (yyval.cnjExp)->push_back((yyvsp[0].exp)); 			   }
#line 1634 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 207 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjExp) = new list<Exp *>(); (yyval.cnjExp)->push_back((yyvsp[0].exp)); }
#line 1640 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1560 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 198 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new BoolTipoVar();	 }
#line 1566 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 199 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new IntTipoVar();		 }
#line 1572 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 200 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new StringTipoVar();   }
#line 1578 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 201 "gczm.y" /* yacc.c:1646  */
    {(yyval.tipoVar) = new StringTipoVar((yyvsp[-1].sval)); }
#line 1584 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 205 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecVar) = (yyvsp[-2].cnjSpecVar); (yyval.cnjSpecVar)->push_back((yyvsp[0].specVar)); 					 }
#line 1590 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 206 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecVar) = new list<SpecVar *>(); (yyval.cnjSpecVar)->push_back((yyvsp[0].specVar)); }
#line 1596 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 210 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarSimples((yyvsp[0].sval), num_linhas); 		   }
#line 1602 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 211 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarSimples((yyvsp[-2].sval), (yyvsp[0].exp), num_linhas); 	   }
#line 1608 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 212 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarArranjo((yyvsp[-3].sval), (yyvsp[-1].exp), num_linhas);	   }
#line 1614 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 213 "gczm.y" /* yacc.c:1646  */
    { (yyval.specVar) = new SpecVarArranjo((yyvsp[-7].sval), (yyvsp[-5].exp), (yyvsp[-1].cnjExp), num_linhas); }
#line 1620 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 217 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjExp) = (yyvsp[-2].cnjExp); (yyval.cnjExp)->push_back((yyvsp[0].exp)); 			   }
#line 1626 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 218 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjExp) = new list<Exp *>(); (yyval.cnjExp)->push_back((yyvsp[0].exp)); }
#line 1632 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 222 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "bool", num_linhas);   }
#line 1638 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 21:
#line 223 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "bool", num_linhas);   }
<<<<<<< HEAD
#line 1646 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 212 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "bool", num_linhas);   }
#line 1652 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 213 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "string", num_linhas); }
#line 1658 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 214 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "int", num_linhas);	 }
#line 1664 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1644 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 224 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "string", num_linhas); }
#line 1650 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 225 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new ValExp((yyvsp[0].sval), "int", num_linhas);	 }
#line 1656 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 230 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); }
#line 1662 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 25:
#line 231 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); }
<<<<<<< HEAD
#line 1670 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 220 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); }
#line 1676 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 224 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-4].sval), (yyvsp[-2].cnjSpecParam), (yyvsp[0].cmd), pilhaSubprog); }
#line 1682 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 225 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-3].sval), (yyvsp[0].cmd), pilhaSubprog); }
#line 1688 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 229 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-6].sval), (yyvsp[-4].cnjSpecParam), (yyvsp[-1].tipoVar), (yyvsp[0].cmd), pilhaSubprog); }
#line 1694 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 230 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-5].sval), (yyvsp[-1].tipoVar), (yyvsp[0].cmd), pilhaSubprog); }
#line 1700 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 234 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecParam) = (yyvsp[-2].cnjSpecParam); (yyval.cnjSpecParam)->push_back((yyvsp[0].specParam));					   }
#line 1706 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 235 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecParam) = new list<SpecParam *>(); (yyval.cnjSpecParam)->push_back((yyvsp[0].specParam)); }
#line 1712 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 239 "gczm.y" /* yacc.c:1646  */
    { (yyval.specParam) = new SpecParam((yyvsp[-2].cnjParam), (yyvsp[0].tipoVar)); }
#line 1718 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 243 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjParam) = (yyvsp[-2].cnjParam); (yyval.cnjParam)->push_back((yyvsp[0].param));				   }
#line 1724 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 244 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjParam) = new list<Param *>(); (yyval.cnjParam)->push_back((yyvsp[0].param)); }
#line 1730 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 248 "gczm.y" /* yacc.c:1646  */
    { (yyval.param) = new Param((yyvsp[0].sval), false); }
#line 1736 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 249 "gczm.y" /* yacc.c:1646  */
    { (yyval.param) = new Param((yyvsp[-2].sval), true); }
#line 1742 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1668 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 235 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-4].sval), (yyvsp[-2].cnjSpecParam), (yyvsp[0].cmd), pilhaSubprog); }
#line 1674 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 236 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-3].sval), (yyvsp[0].cmd), pilhaSubprog); }
#line 1680 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 240 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-6].sval), (yyvsp[-4].cnjSpecParam), (yyvsp[-1].tipoVar), (yyvsp[0].cmd), pilhaSubprog); }
#line 1686 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 241 "gczm.y" /* yacc.c:1646  */
    { (yyval.decl) = new DeclSub((yyvsp[-5].sval), (yyvsp[-1].tipoVar), (yyvsp[0].cmd), pilhaSubprog); }
#line 1692 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 245 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecParam) = (yyvsp[-2].cnjSpecParam); (yyval.cnjSpecParam)->push_back((yyvsp[0].specParam));					   }
#line 1698 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 246 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjSpecParam) = new list<SpecParam *>(); (yyval.cnjSpecParam)->push_back((yyvsp[0].specParam)); }
#line 1704 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 250 "gczm.y" /* yacc.c:1646  */
    { (yyval.specParam) = new SpecParam((yyvsp[-2].cnjParam), (yyvsp[0].tipoVar)); }
#line 1710 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 254 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjParam) = (yyvsp[-2].cnjParam); (yyval.cnjParam)->push_back((yyvsp[0].param));				   }
#line 1716 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 255 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjParam) = new list<Param *>(); (yyval.cnjParam)->push_back((yyvsp[0].param)); }
#line 1722 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 259 "gczm.y" /* yacc.c:1646  */
    { (yyval.param) = new Param((yyvsp[0].sval), false); }
#line 1728 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 260 "gczm.y" /* yacc.c:1646  */
    { (yyval.param) = new Param((yyvsp[-2].sval), true); }
#line 1734 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 265 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = (yyvsp[0].cmd); }
#line 1740 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 38:
#line 266 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = (yyvsp[0].cmd); }
<<<<<<< HEAD
#line 1748 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 255 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = (yyvsp[0].cmd); }
#line 1754 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1746 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 270 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1752 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 40:
#line 271 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
<<<<<<< HEAD
#line 1760 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1758 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 41:
#line 272 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
<<<<<<< HEAD
#line 1766 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1764 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 42:
#line 273 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
<<<<<<< HEAD
#line 1772 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1770 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 43:
#line 274 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
<<<<<<< HEAD
#line 1778 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1776 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 44:
#line 275 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
<<<<<<< HEAD
#line 1784 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1782 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 45:
#line 276 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
<<<<<<< HEAD
#line 1790 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1788 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 46:
#line 277 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
<<<<<<< HEAD
#line 1796 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1794 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 47:
#line 278 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
<<<<<<< HEAD
#line 1802 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1800 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 48:
#line 279 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
<<<<<<< HEAD
#line 1808 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 268 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = (yyvsp[0].cmd);}
#line 1814 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 273 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new AtribCmd((yyvsp[-3].exp), (yyvsp[-2].sval), (yyvsp[-1].exp), num_linhas);}
#line 1820 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 274 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new AtribCmd((yyvsp[-3].exp), (yyvsp[-2].sval), (yyvsp[-1].exp), num_linhas); yyerrok;}
#line 1826 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 278 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1832 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 279 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1838 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1806 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 284 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new AtribCmd((yyvsp[-3].exp), (yyvsp[-2].sval), (yyvsp[-1].exp), num_linhas);}
#line 1812 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 288 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1818 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 289 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1824 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 293 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1830 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 294 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1836 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 54:
#line 295 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
<<<<<<< HEAD
#line 1844 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1842 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 55:
#line 296 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
<<<<<<< HEAD
#line 1850 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1848 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
    break;

  case 56:
#line 297 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
<<<<<<< HEAD
#line 1856 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 286 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1862 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 287 "gczm.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].sval);}
#line 1868 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 292 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new IfCmd((yyvsp[-2].exp), (yyvsp[0].cmd), num_linhas);     }
#line 1874 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 293 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new IfCmd((yyvsp[-4].exp), (yyvsp[-2].cmd), (yyvsp[0].cmd), num_linhas); }
#line 1880 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 297 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new WhileCmd((yyvsp[-2].exp), (yyvsp[0].cmd), pilhaCmdRepet, num_linhas);}
#line 1886 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 301 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new ForCmd((yyvsp[-6].cmd), (yyvsp[-4].exp), (yyvsp[-2].cmd), (yyvsp[0].cmd), pilhaCmdRepet, num_linhas);}
#line 1892 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 305 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new AtribCmd((yyvsp[-2].exp), (yyvsp[-1].sval), (yyvsp[0].exp), num_linhas); }
#line 1898 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 309 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new StopSkipCmd((yyvsp[-1].sval), pilhaCmdRepet, num_linhas);}
#line 1904 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 310 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new StopSkipCmd((yyvsp[-1].sval), pilhaCmdRepet, num_linhas); yyerrok;}
#line 1910 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 314 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new StopSkipCmd((yyvsp[-1].sval), pilhaCmdRepet, num_linhas);}
#line 1916 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 315 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new StopSkipCmd((yyvsp[-1].sval), pilhaCmdRepet, num_linhas); yyerrok;}
#line 1922 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 319 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new RetCmd(pilhaSubprog, num_linhas);}
#line 1928 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 320 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new RetCmd((yyvsp[-1].exp), pilhaSubprog, num_linhas);}
#line 1934 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 321 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new RetCmd(pilhaSubprog, num_linhas); yyerrok;}
#line 1940 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 322 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new RetCmd((yyvsp[-1].exp), pilhaSubprog, num_linhas); yyerrok;}
#line 1946 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 327 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ProcCmd((yyvsp[-3].sval), escopoAtual, num_linhas);     }
#line 1952 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 328 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ProcCmd((yyvsp[-4].sval), (yyvsp[-2].cnjExp), escopoAtual, num_linhas); }
#line 1958 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 329 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ProcCmd((yyvsp[-3].sval), escopoAtual, num_linhas); yyerrok; }
#line 1964 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 330 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ProcCmd((yyvsp[-4].sval), (yyvsp[-2].cnjExp), escopoAtual, num_linhas); yyerrok;}
#line 1970 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 334 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ReadCmd((yyvsp[-1].exp), num_linhas); }
#line 1976 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 335 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new ReadCmd((yyvsp[-1].exp), num_linhas); yyerrok;}
#line 1982 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 339 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new WriteCmd((yyvsp[-1].cnjExp)); }
#line 1988 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 340 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new WriteCmd((yyvsp[-1].cnjExp)); yyerrok;}
#line 1994 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 345 "gczm.y" /* yacc.c:1646  */
    {	(yyval.cmd) = new BlocoCmd((yyvsp[-1].cnjDecl), (yyvsp[-2].escopo));		}
#line 2000 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 346 "gczm.y" /* yacc.c:1646  */
    {	(yyval.cmd) = new BlocoCmd((yyvsp[-1].cnjCmd), (yyvsp[-2].escopo));		}
#line 2006 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 347 "gczm.y" /* yacc.c:1646  */
    {	(yyval.cmd) = new BlocoCmd((yyvsp[-2].cnjDecl), (yyvsp[-1].cnjCmd), (yyvsp[-3].escopo));	}
#line 2012 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 351 "gczm.y" /* yacc.c:1646  */
    { 
			escopoAtual = new Escopo(escopoAtual, countEscopos);
			countEscopos++;
			(yyval.escopo) = escopoAtual;
		}
#line 2022 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 359 "gczm.y" /* yacc.c:1646  */
    {escopoAtual = escopoAtual->getPai(); }
#line 2028 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 363 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjCmd) = (yyvsp[-1].cnjCmd); (yyval.cnjCmd)->push_back((yyvsp[0].cmd)); 				 }
#line 2034 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 364 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjCmd) = new list<Cmd *>(); (yyval.cnjCmd)->push_back((yyvsp[0].cmd)); }
#line 2040 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 370 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = (yyvsp[0].exp);											}
#line 2046 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 371 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = (yyvsp[0].exp);											}
#line 2052 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 372 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = (yyvsp[-1].exp);											}
#line 2058 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 373 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new NegUnExp((yyvsp[0].exp), num_linhas);		  			}
#line 2064 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 374 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new NegExp((yyvsp[0].exp), num_linhas);					}
#line 2070 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 375 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2076 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 376 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);		 	}
#line 2082 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 377 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);		 	}
#line 2088 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 378 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);		 	}
#line 2094 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 379 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);		 	}
#line 2100 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 380 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2106 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 381 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2112 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 382 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2118 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 383 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2124 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 384 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new IgExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);				}
#line 2130 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 385 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new IgExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);				}
#line 2136 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 386 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new LogExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2142 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 387 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new LogExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2148 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 388 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new TerExp((yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp), num_linhas);			}
#line 2154 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 389 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new FuncExp((yyvsp[-2].sval), escopoAtual, num_linhas); 		}
#line 2160 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 390 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new FuncExp((yyvsp[-3].sval), (yyvsp[-1].cnjExp), escopoAtual, num_linhas);  }
#line 2166 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 394 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new VarExp((yyvsp[0].sval), escopoAtual, num_linhas);     }
#line 2172 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 395 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new VarExp((yyvsp[-3].sval), (yyvsp[-1].exp), escopoAtual, num_linhas); }
#line 2178 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 396 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new VarExp((yyvsp[-3].sval), (yyvsp[-1].exp), escopoAtual, num_linhas); yyerrok;}
#line 2184 "gczm.tab.c" /* yacc.c:1646  */
    break;


#line 2188 "gczm.tab.c" /* yacc.c:1646  */
=======
#line 1854 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 302 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new IfCmd((yyvsp[-2].exp), (yyvsp[0].cmd), num_linhas);     }
#line 1860 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 303 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new IfCmd((yyvsp[-4].exp), (yyvsp[-2].cmd), (yyvsp[0].cmd), num_linhas); }
#line 1866 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 307 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new WhileCmd((yyvsp[-2].exp), (yyvsp[0].cmd), pilhaCmdRepet, num_linhas);}
#line 1872 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 311 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new ForCmd((yyvsp[-6].cmd), (yyvsp[-4].exp), (yyvsp[-2].cmd), (yyvsp[0].cmd), pilhaCmdRepet, num_linhas);}
#line 1878 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 315 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new AtribCmd((yyvsp[-2].exp), (yyvsp[-1].sval), (yyvsp[0].exp), num_linhas); }
#line 1884 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 319 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new StopSkipCmd((yyvsp[-1].sval), pilhaCmdRepet, num_linhas);}
#line 1890 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 323 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new StopSkipCmd((yyvsp[-1].sval), pilhaCmdRepet, num_linhas);}
#line 1896 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 327 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new RetCmd(pilhaSubprog, num_linhas);}
#line 1902 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 328 "gczm.y" /* yacc.c:1646  */
    {(yyval.cmd) = new RetCmd((yyvsp[-1].exp), pilhaSubprog, num_linhas);}
#line 1908 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 333 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ProcCmd((yyvsp[-3].sval), escopoAtual, num_linhas);     }
#line 1914 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 334 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ProcCmd((yyvsp[-4].sval), (yyvsp[-2].cnjExp), escopoAtual, num_linhas); }
#line 1920 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 338 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new ReadCmd((yyvsp[-1].exp), num_linhas); }
#line 1926 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 342 "gczm.y" /* yacc.c:1646  */
    { (yyval.cmd) = new WriteCmd((yyvsp[-1].cnjExp)); }
#line 1932 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 347 "gczm.y" /* yacc.c:1646  */
    {	(yyval.cmd) = new BlocoCmd((yyvsp[-1].cnjDecl), (yyvsp[-2].escopo));		}
#line 1938 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 348 "gczm.y" /* yacc.c:1646  */
    {	(yyval.cmd) = new BlocoCmd((yyvsp[-1].cnjCmd), (yyvsp[-2].escopo));		}
#line 1944 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 349 "gczm.y" /* yacc.c:1646  */
    {	(yyval.cmd) = new BlocoCmd((yyvsp[-2].cnjDecl), (yyvsp[-1].cnjCmd), (yyvsp[-3].escopo));	}
#line 1950 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 353 "gczm.y" /* yacc.c:1646  */
    { 
			escopoAtual = new Escopo(escopoAtual, countEscopos);
			countEscopos++;
			(yyval.escopo) = escopoAtual;
		}
#line 1960 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 361 "gczm.y" /* yacc.c:1646  */
    {escopoAtual = escopoAtual->getPai(); }
#line 1966 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 365 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjCmd) = (yyvsp[-1].cnjCmd); (yyval.cnjCmd)->push_back((yyvsp[0].cmd)); 				 }
#line 1972 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 366 "gczm.y" /* yacc.c:1646  */
    { (yyval.cnjCmd) = new list<Cmd *>(); (yyval.cnjCmd)->push_back((yyvsp[0].cmd)); }
#line 1978 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 372 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = (yyvsp[0].exp);											}
#line 1984 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 373 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = (yyvsp[0].exp);											}
#line 1990 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 374 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = (yyvsp[-1].exp);											}
#line 1996 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 375 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new NegUnExp((yyvsp[0].exp), num_linhas);		  			}
#line 2002 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 376 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new NegExp((yyvsp[0].exp), num_linhas);					}
#line 2008 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 377 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2014 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 378 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);		 	}
#line 2020 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 379 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);		 	}
#line 2026 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 380 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);		 	}
#line 2032 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 381 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new AritmExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);		 	}
#line 2038 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 382 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2044 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 383 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2050 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 384 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2056 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 385 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new RelExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2062 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 386 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new IgExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);				}
#line 2068 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 387 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new IgExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);				}
#line 2074 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 388 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new LogExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2080 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 389 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new LogExp((yyvsp[-2].exp), (yyvsp[0].exp), (yyvsp[-1].sval), num_linhas);			}
#line 2086 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 390 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new TerExp((yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp), num_linhas);			}
#line 2092 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 391 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new FuncExp((yyvsp[-2].sval), escopoAtual, num_linhas); 		}
#line 2098 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 392 "gczm.y" /* yacc.c:1646  */
    {	(yyval.exp) = new FuncExp((yyvsp[-3].sval), (yyvsp[-1].cnjExp), escopoAtual, num_linhas);  }
#line 2104 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 396 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new VarExp((yyvsp[0].sval), escopoAtual, num_linhas);     }
#line 2110 "gczm.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 397 "gczm.y" /* yacc.c:1646  */
    { (yyval.exp) = new VarExp((yyvsp[-3].sval), (yyvsp[-1].exp), escopoAtual, num_linhas); }
#line 2116 "gczm.tab.c" /* yacc.c:1646  */
    break;


#line 2120 "gczm.tab.c" /* yacc.c:1646  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0
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
<<<<<<< HEAD
#line 399 "gczm.y" /* yacc.c:1906  */
=======
#line 400 "gczm.y" /* yacc.c:1906  */
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0


/* Codificacao C++ */
int main(int argc, char *argv[]){
	yydebug = 0;

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

	fclose(entrada);

	return 0;
}

<<<<<<< HEAD
void yyerror(char const *s){
	cout<< "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): "<< s <<"\n";
=======
void yyerror(const char *s){
	cout<< "Erro Sintático (l: "<<num_linhas<< ", c: "<<num_carac<<"): "<< s <<"\n";
>>>>>>> e481a7e1a17f221d6f58d5c2743d6919c65accf0

	//exit(-1);
}
