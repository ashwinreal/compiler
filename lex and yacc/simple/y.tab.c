/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sil.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symtbl.h"
#include "astree.h"
#define MAX_SYMBOLS 100
tbl *symtbl[MAX_SYMBOLS];
int id_count=0;
int label_ctr=0;
int reg_ctr=0;
int var_mem=0;
void free_ptr(ast *yylval);
int evaluate_ast(ast *root);
void print_symbols();
int allocate_mem(int size);
int get_reg();
void free_reg();
int get_label();
FILE *fp;


#line 90 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,
    OPERATOR = 259,
    DECL = 260,
    ENDDECL = 261,
    BEG = 262,
    END = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    ENDIF = 267,
    WHILE = 268,
    DO = 269,
    ENDWHILE = 270,
    READ = 271,
    WRITE = 272,
    EQEQ = 273,
    BOOLEAN = 274,
    INTEGER = 275,
    NUM = 276,
    T = 277,
    F = 278,
    PLUS = 279,
    MINUS = 280,
    MUL = 281,
    DIV = 282,
    SLIST = 283,
    EQ = 284,
    DLIST = 285,
    NEQ = 286
  };
#endif
/* Tokens.  */
#define ID 258
#define OPERATOR 259
#define DECL 260
#define ENDDECL 261
#define BEG 262
#define END 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define READ 271
#define WRITE 272
#define EQEQ 273
#define BOOLEAN 274
#define INTEGER 275
#define NUM 276
#define T 277
#define F 278
#define PLUS 279
#define MINUS 280
#define MUL 281
#define DIV 282
#define SLIST 283
#define EQ 284
#define DLIST 285
#define NEQ 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  89

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      36,    37,    34,    32,     2,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    73,    77,    85,    88,   108,   126,   147,
     169,   174,   188,   195,   200,   203,   206,   207,   210,   233,
     253,   260,   312,   362,   380,   396,   412,   427,   444,   459,
     490,   491,   516,   519,   520,   524,   534,   544
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "OPERATOR", "DECL", "ENDDECL",
  "BEG", "END", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "READ", "WRITE", "EQEQ", "BOOLEAN", "INTEGER", "NUM", "T", "F", "PLUS",
  "MINUS", "MUL", "DIV", "SLIST", "EQ", "DLIST", "NEQ", "'+'", "'-'",
  "'*'", "'/'", "'('", "')'", "';'", "'['", "']'", "'='", "$accept", "pgm",
  "pgmdecl", "dlist", "dstmt", "pgmbody", "stmtlist", "stmt", "r", "w",
  "assign", "expr", "cond", "loop", YY_NULLPTR
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
     285,   286,    43,    45,    42,    47,    40,    41,    59,    91,
      93,    61
};
# endif

#define YYPACT_NINF -32

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-32)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,    -3,     9,    14,    46,    50,    48,    -3,   -32,   149,
     -32,   -20,   -15,   -32,   -32,   -31,     4,     4,    53,     4,
      47,   149,   -32,   -32,   -32,   -32,   -32,   -32,     4,   -32,
       4,     4,     4,    18,   -32,   -32,   -32,     4,    12,    95,
     -10,    83,   -32,   -32,    32,    42,    52,   101,     4,   122,
     149,     4,     4,     4,     4,     4,     4,   149,   -32,     4,
     -32,    20,    24,    27,   -32,    62,   -32,    21,   -29,   -29,
      17,    17,   -32,   -32,    44,    72,   -32,   -32,     4,   -32,
     149,   -32,   -32,    31,   113,    66,   -32,   -32,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     5,     1,     0,
       2,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,    12,    16,    17,    13,    14,    15,     6,     0,     7,
       0,     0,     0,    31,    32,    33,    34,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      20,     0,     0,     0,    21,     0,    30,     0,    27,    28,
      23,    24,    25,    26,     0,     0,     9,     8,     0,    29,
       0,    35,    37,     0,     0,     0,    18,    22,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,    74,   -32,   -32,    -9,   -32,   -32,   -32,
     -32,   -17,   -32,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    10,    20,    21,    22,    23,
      24,    38,    25,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,     1,    41,    53,    54,    55,    56,    33,    31,     8,
      32,    44,    43,    45,    46,    47,     4,     5,    27,    28,
      49,     9,    50,    29,    30,    34,    35,    36,    58,    59,
      51,    65,    80,    81,    68,    69,    70,    71,    72,    73,
      37,    67,    75,    52,    53,    54,    55,    56,    74,    11,
      51,    55,    56,    12,    13,    42,    40,    48,    76,    82,
      51,    84,    77,    52,    53,    54,    55,    56,    78,    86,
      51,    85,    61,    52,    53,    54,    55,    56,    88,     0,
      51,    14,    62,    52,    53,    54,    55,    56,     0,     0,
      51,     0,    63,    52,    53,    54,    55,    56,     0,     0,
       0,    51,    79,    52,    53,    54,    55,    56,     0,    57,
       0,     0,    83,    51,    52,    53,    54,    55,    56,    51,
       0,    60,     0,     0,     0,     0,    52,    53,    54,    55,
      56,    51,    52,    53,    54,    55,    56,     0,     0,    64,
      51,     0,     0,     0,    52,    53,    54,    55,    56,     0,
       0,    87,    15,    52,    53,    54,    55,    56,    16,    66,
       0,     0,    17,     0,     0,    18,    19
};

static const yytype_int8 yycheck[] =
{
      17,     5,    19,    32,    33,    34,    35,     3,    39,     0,
      41,    28,    21,    30,    31,    32,    19,    20,    38,    39,
      37,     7,    10,    38,    39,    21,    22,    23,    38,    39,
      18,    48,    11,    12,    51,    52,    53,    54,    55,    56,
      36,    50,    59,    31,    32,    33,    34,    35,    57,     3,
      18,    34,    35,     3,     6,     8,     3,    39,    38,    15,
      18,    78,    38,    31,    32,    33,    34,    35,    41,    38,
      18,    80,    40,    31,    32,    33,    34,    35,    12,    -1,
      18,     7,    40,    31,    32,    33,    34,    35,    -1,    -1,
      18,    -1,    40,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    18,    40,    31,    32,    33,    34,    35,    -1,    14,
      -1,    -1,    40,    18,    31,    32,    33,    34,    35,    18,
      -1,    38,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    18,    31,    32,    33,    34,    35,    -1,    -1,    38,
      18,    -1,    -1,    -1,    31,    32,    33,    34,    35,    -1,
      -1,    38,     3,    31,    32,    33,    34,    35,     9,    37,
      -1,    -1,    13,    -1,    -1,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    43,    44,    19,    20,    45,    46,     0,     7,
      47,     3,     3,     6,    45,     3,     9,    13,    16,    17,
      48,    49,    50,    51,    52,    54,    55,    38,    39,    38,
      39,    39,    41,     3,    21,    22,    23,    36,    53,    53,
       3,    53,     8,    48,    53,    53,    53,    53,    39,    53,
      10,    18,    31,    32,    33,    34,    35,    14,    38,    39,
      38,    40,    40,    40,    38,    53,    37,    48,    53,    53,
      53,    53,    53,    53,    48,    53,    38,    38,    41,    40,
      11,    12,    15,    40,    53,    48,    38,    38,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    46,    46,    46,
      47,    48,    48,    49,    49,    49,    49,    49,    50,    50,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    55
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     1,     3,     3,     6,     6,
       3,     2,     1,     1,     1,     1,     1,     1,     6,     3,
       3,     4,     7,     3,     3,     3,     3,     3,     3,     4,
       3,     1,     1,     1,     1,     5,     7,     5
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
#line 60 "sil.y" /* yacc.c:1646  */
    {
											printf("complete ast\n");

											evaluate_ast((yyvsp[-1]));       // declaration
											print_symbols();
											fprintf(fp, "START\n" );
											evaluate_ast((yyvsp[0]));				// body
											fprintf(fp, "HALT\n" );

											fclose(fp);

											exit(1);
										}
#line 1359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 73 "sil.y" /* yacc.c:1646  */
    {
								(yyval)=(yyvsp[-1]);

}
#line 1368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 77 "sil.y" /* yacc.c:1646  */
    {

										(yyval)=(ast *) malloc(sizeof(ast));
										(yyval)->node_type = DLIST;
										strcpy((yyval)->name,"dlist");
										(yyval)->ptr1=(yyvsp[-1]);
										(yyval)->ptr2=(yyvsp[0]);
										}
#line 1381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 85 "sil.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
				//printf("yoyoy %d\n",$$->node_type );
			}
#line 1389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 88 "sil.y" /* yacc.c:1646  */
    {
						int index_id=check_exist((yyvsp[-1]));
						if(index_id!=-1)
							printf("error : name %s already exists\n", (yyvsp[-1])->name);
						tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
						strcpy(temp_symb->var_name,(yyvsp[-1])->name);
						temp_symb->size=0;
					  strcpy(temp_symb->data_type,"boolean");
						symtbl[id_count++]=temp_symb;
						free_ptr((yyvsp[-1]));
						//printf("declaration %s",yylval->data_type);

						(yyval)=(ast *) malloc(sizeof(ast));
						(yyval)->node_type=BOOLEAN;
						(yyval)->entry = id_count-1;




					}
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 108 "sil.y" /* yacc.c:1646  */
    {

				int index_id=check_exist((yyvsp[-1]));
				if(index_id!=-1)
					printf("error : name %s already exists\n", (yyvsp[-1])->name);
				tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
				strcpy(temp_symb->var_name,(yyvsp[-1])->name);
				temp_symb->size=0;
				strcpy(temp_symb->data_type,"integer");
				symtbl[id_count++]=temp_symb;
				free_ptr((yyvsp[-1]));
				//	printf("declaration %s",yylval->data_type);


				(yyval)=(ast *) malloc(sizeof(ast));
				(yyval)->node_type= INTEGER;
				(yyval)->entry = id_count-1;
		}
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "sil.y" /* yacc.c:1646  */
    {
		//	printf("array of integer\n" );
			int index_id=check_exist((yyvsp[-4]));
			if(index_id!=-1)
				printf("error : name %s already exists\n", (yyvsp[-4])->name);
			if(strcmp((yyvsp[-2])->data_type,"boolean")==0)
				printf("error: inside [] must be an int\n" );

				tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
				strcpy(temp_symb->var_name,(yyvsp[-4])->name);
				temp_symb->size=(yyvsp[-2])->int_value;
				strcpy(temp_symb->data_type,"integer");
				symtbl[id_count++]=temp_symb;
				free_ptr((yyvsp[-4]));

				(yyval)=(ast *) malloc(sizeof(ast));
				(yyval)->node_type= INTEGER;
				(yyval)->entry = id_count-1;
				(yyval)->ptr1 = (yyvsp[-2]);

		}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 147 "sil.y" /* yacc.c:1646  */
    {
			//printf("array of bool\n" );
			int index_id=check_exist((yyvsp[-4]));
			if(index_id!=-1)
				printf("error : name %s already exists\n", (yyvsp[-4])->name);
			if(strcmp((yyvsp[-2])->data_type,"boolean")==0)
				printf("error: inside [] must be an int\n" );
			tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
			strcpy(temp_symb->var_name,(yyvsp[-4])->name);
			temp_symb->size=(yyvsp[-2])->int_value;
			strcpy(temp_symb->data_type,"boolean");
			symtbl[id_count++]=temp_symb;
			free_ptr((yyvsp[-4]));

			(yyval)=(ast *) malloc(sizeof(ast));
			(yyval)->node_type= BOOLEAN;
			(yyval)->entry = id_count-1;
			(yyval)->ptr1 = (yyvsp[-2]);
		}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 169 "sil.y" /* yacc.c:1646  */
    {
														(yyval)=(yyvsp[-1]);
														//	printf("evaluating the ast\n");
														//	evaluate_ast($2);
		}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 174 "sil.y" /* yacc.c:1646  */
    {
													ast *temp = (ast *)malloc(sizeof(ast));
													(yyval)=temp;
													strcpy(temp->data_type,"void");
													(yyval)->node_type = SLIST;

													(yyval)->ptr1 = (yyvsp[-1]);
													(yyval)->ptr2 = (yyvsp[0]);





}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 188 "sil.y" /* yacc.c:1646  */
    {

												(yyval)=(yyvsp[0]);



			}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 195 "sil.y" /* yacc.c:1646  */
    {
												(yyval)=(yyvsp[0]);


}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 200 "sil.y" /* yacc.c:1646  */
    {
												(yyval)=(yyvsp[0]);
	}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 203 "sil.y" /* yacc.c:1646  */
    {
												(yyval)=(yyvsp[0]);
	}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 206 "sil.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 207 "sil.y" /* yacc.c:1646  */
    { (yyval)= (yyvsp[0]); }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 210 "sil.y" /* yacc.c:1646  */
    {
		int index_id=check_exist((yyvsp[-4]));
		if( index_id !=-1)
			{

				(yyval)=(ast*)malloc(sizeof(ast));
				strcpy((yyval)->data_type,symtbl[index_id]->data_type);
				strcpy((yyvsp[-4])->name, "read_array");
				(yyval)->entry = index_id;
				(yyval)->node_type=READ;
				if(strcmp((yyvsp[-2])->data_type,"boolean")==0)
					printf("error: inside [] must be an int\n" );



					(yyval)->ptr1=(yyvsp[-2]);


			}
			else
					printf("error not declared\n" );

	}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 233 "sil.y" /* yacc.c:1646  */
    {
			int index_id=check_exist((yyvsp[-1]));
			if( index_id !=-1)
				{

					(yyval)=(ast*)malloc(sizeof(ast));
					strcpy((yyval)->data_type,symtbl[index_id]->data_type);
					strcpy((yyval)->name, "read");
					(yyval)->entry = index_id;
					(yyval)->node_type=READ;

					(yyval)->ptr1=NULL;


				}
				else
						printf("error not declared\n" );

		}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 253 "sil.y" /* yacc.c:1646  */
    {
			(yyval)=(ast*)malloc(sizeof(ast));
			strcpy((yyval)->data_type,(yyvsp[-1])->data_type);
			strcpy((yyval)->name, "write");
			(yyval)->node_type=WRITE;
			(yyval)->ptr1=(yyvsp[-1]);
}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 260 "sil.y" /* yacc.c:1646  */
    {
													//	printf("in id = expr\n");
														(yyval) = (ast*)malloc(sizeof(ast));
														strcpy((yyval)->name,"assign");

														(yyval)->node_type = EQ;
														strcpy((yyval)->data_type,"boolean");
														int index_id=check_exist((yyvsp[-3]));

														printf("%d\n",index_id );

														//printf("%s\n",$3->data_type );
														//printf("%s %s\n",symtbl[index_id]->data_type,symtbl[index_id]->var_name);
														//printf("%d\n",check_dtype(symtbl[index_id],$3->data_type) );
														if( index_id !=-1 && strcmp(symtbl[index_id]->data_type,(yyvsp[-1])->data_type)==0)
															{

/*

																if(strcmp(symtbl[index_id]->data_type,"boolean"))
																{
																	printf("expr evaluated to %d \n",$3->int_value);
																	*(symtbl[index_id]->store.f)=$3->bool_value;


																}
																else
																{
																		printf("expr evaluated to %d \n",$3->bool_value);
																		*(symtbl[index_id]->store.i)=$3->int_value;

																}
*/
																(yyval)->bool_value = true;




															}
														else
															{
																printf("kya error  cannot evaluate unmatching dtypes %s ... %s\n",symtbl[index_id]->data_type,(yyvsp[-1])->data_type);
																(yyval)->bool_value = false;
														}

														(yyval)->ptr1= (yyvsp[-3]);
														(yyval)->ptr1->entry = index_id;               //we need this
														strcpy((yyval)->ptr1->data_type,(yyvsp[-1])->data_type);
														(yyval)->ptr2= (yyvsp[-1]);


													}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 312 "sil.y" /* yacc.c:1646  */
    {

					//	printf("in id = expr[]\n");
						(yyval) = (ast*)malloc(sizeof(ast));
						strcpy((yyval)->name,"assign");

						if(strcmp((yyvsp[-4])->data_type,"boolean")==0)
							printf("error: inside [] must be an int\n" );
						(yyval)->node_type = EQ;

						strcpy((yyval)->data_type,"boolean");
						int index_id=check_exist((yyvsp[-6]));
					//	printf("%d\n",index_id );
						(yyval)->entry = index_id;
					//printf("the datatype is %s\n", $6->data_type);
						if( index_id !=-1 && strcmp(symtbl[index_id]->data_type,(yyvsp[-1])->data_type)==0)
							{
/*
								if(strcmp(symtbl[index_id]->data_type,"boolean"))
								{
									printf("expr evaluated to %d \n",$6->bool_value);
									*(symtbl[index_id]->store.f  + ($3->int_value))=($6->bool_value );
								}
								else{
									printf("expr evaluated to %d \n",$6->int_value);
									*(symtbl[index_id]->store.i + ($3->int_value))=($6->int_value);

								}
*/

								((yyval)->bool_value) = true;


							}
						else
							{printf("kya error  cannot evaluate2!\n");

							((yyval)->bool_value) = false;
						}

						(yyval)->ptr1= (yyvsp[-6]);
						(yyval)->ptr1->entry = index_id;               //we need this
						strcpy((yyval)->ptr1->data_type,(yyvsp[-4])->data_type);
						(yyval)->ptr2= (yyvsp[-4]);
						(yyval)->ptr3= (yyvsp[-1]);


					}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 362 "sil.y" /* yacc.c:1646  */
    {
												if(strcmp((yyvsp[-2])->data_type,(yyvsp[0])->data_type)==0 && check_dtype((yyvsp[-2]),"integer"))
												{
													(yyval) = (ast*)malloc(sizeof(ast));
													strcpy((yyval)->name,"plus");

													(yyval)->node_type=PLUS;
													strcpy((yyval)->data_type,"integer");

												}else printf("error: conflicting data types or not integer data types %s %s\n",(yyvsp[-2])->data_type,(yyvsp[0])->data_type);

												(yyval)->ptr1=(yyvsp[-2]);
												(yyval)->ptr2=(yyvsp[0]);




}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 380 "sil.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-2])->data_type,(yyvsp[0])->data_type)==0 && check_dtype((yyvsp[-2]),"integer"))
		{
			(yyval) = (ast*)malloc(sizeof(ast));
			strcpy((yyval)->name,"minus");

			(yyval)->node_type=MINUS;
			strcpy((yyval)->data_type,"integer");

		}else printf("error: conflicting data types or not integer data types\n");

		(yyval)->ptr1=(yyvsp[-2]);
		(yyval)->ptr2=(yyvsp[0]);


	}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 396 "sil.y" /* yacc.c:1646  */
    {

		if(strcmp((yyvsp[-2])->data_type,(yyvsp[0])->data_type)==0 && check_dtype((yyvsp[-2]),"integer"))
		{
			(yyval) = (ast*)malloc(sizeof(ast));
			strcpy((yyval)->name,"mul");

			(yyval)->node_type=MUL;
			strcpy((yyval)->data_type,"integer");

		}else printf("error: conflicting data types or not integer data types\n");

		(yyval)->ptr1=(yyvsp[-2]);
		(yyval)->ptr2=(yyvsp[0]);

	}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 412 "sil.y" /* yacc.c:1646  */
    {

		if(strcmp((yyvsp[-2])->data_type,(yyvsp[0])->data_type)==0 && check_dtype((yyvsp[-2]),"integer"))
		{
			(yyval) = (ast*)malloc(sizeof(ast));
			strcpy((yyval)->name,"div");

			(yyval)->node_type=DIV;
			strcpy((yyval)->data_type,"integer");

		}else printf("error: conflicting data types or not integer data types\n");

		(yyval)->ptr1=(yyvsp[-2]);
		(yyval)->ptr2=(yyvsp[0]);
	}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 427 "sil.y" /* yacc.c:1646  */
    {

		if(strcmp((yyvsp[-2])->data_type,(yyvsp[0])->data_type)==0)
		{
			(yyval) = (ast*)malloc(sizeof(ast));
			strcpy((yyval)->name,"eqeq");

			(yyval)->node_type=EQEQ;
			strcpy((yyval)->data_type,"boolean");


		}else printf("error: conflicting data types\n");
		(yyval)->ptr1=(yyvsp[-2]);
		(yyval)->ptr2=(yyvsp[0]);


	}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 444 "sil.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-2])->data_type,(yyvsp[0])->data_type)==0)
		{
			(yyval) = (ast*)malloc(sizeof(ast));
			strcpy((yyval)->name,"neq");

			(yyval)->node_type=NEQ;
			strcpy((yyval)->data_type,"boolean");


		}else printf("error: conflicting data types\n");
		(yyval)->ptr1=(yyvsp[-2]);
		(yyval)->ptr2=(yyvsp[0]);

	}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 459 "sil.y" /* yacc.c:1646  */
    {
	//	printf("id[]\n");
		int index_id=check_exist((yyvsp[-3]));
		if( index_id !=-1)
			{


				strcpy((yyvsp[-3])->data_type,symtbl[index_id]->data_type);
				strcpy((yyvsp[-3])->name, "id_array");
				(yyvsp[-3])->entry = index_id;
				(yyvsp[-3])->node_type=ID;
				if(strcmp((yyvsp[-1])->data_type,"boolean")==0)
					printf("error: inside [] must be an int\n" );


					(yyval)=(yyvsp[-3]);
					(yyval)->ptr1=(yyvsp[-1]);


			}
			else
					printf("error not declared\n" );


	//	printf("the datatype is %s name is %s\n",$1->data_type,$1->name );


	//	free_ptr($3);


	}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 490 "sil.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 491 "sil.y" /* yacc.c:1646  */
    {
		//	printf("id\n");
			int index_id=check_exist((yyvsp[0]));
			if( index_id !=-1)
				{


					strcpy((yyvsp[0])->data_type,symtbl[index_id]->data_type);
					strcpy((yyvsp[0])->name, "id");
					(yyvsp[0])->entry = index_id;
					(yyvsp[0])->node_type=ID;

					(yyvsp[0])->ptr1 = NULL;

						(yyval)=(yyvsp[0]);


				}
				else
						printf("error not declared\n" );


		//	printf("id :the datatype is %s name is %s\n",$1->data_type,$1->name );

		}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 516 "sil.y" /* yacc.c:1646  */
    {
		(yyval)=(yyvsp[0]);
	}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 519 "sil.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 520 "sil.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 524 "sil.y" /* yacc.c:1646  */
    {

				(yyval)=(ast*)malloc(sizeof(ast));
				strcpy((yyval)->name,"if");
				(yyval)->node_type=IF;
				(yyval)->ptr1=(yyvsp[-3]);
				(yyval)->ptr2=(yyvsp[-1]);
				(yyval)->ptr3=NULL;

}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 534 "sil.y" /* yacc.c:1646  */
    {
		(yyval)=(ast*)malloc(sizeof(ast));
		strcpy((yyval)->name,"ifelse");
		(yyval)->node_type=IF;
		(yyval)->ptr1=(yyvsp[-5]);
		(yyval)->ptr2=(yyvsp[-3]);
		(yyval)->ptr3=(yyvsp[-1]);

	}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 544 "sil.y" /* yacc.c:1646  */
    {
	(yyval)=(ast*)malloc(sizeof(ast));
	strcpy((yyval)->name,"while");
	(yyval)->node_type=WHILE;
	(yyval)->ptr1=(yyvsp[-3]);
	(yyval)->ptr2=(yyvsp[-1]);
	(yyval)->ptr3=NULL;



}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2008 "y.tab.c" /* yacc.c:1646  */
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
#line 559 "sil.y" /* yacc.c:1906  */


int check_exist(ast *yylval)
{
	int i;
	for(i=0;i<id_count;i++ )
		if(strcmp(symtbl[i]->var_name,yylval->name)==0)
			break;

	if(i!=id_count )
		return i;
	return -1;

}
int check_dtype(ast *yylval,char *b)
{
//	printf("yoyoy...%s %s\n",yylval->data_type ,yylval->name);
	//printf("%s\n", b);
	if( strcmp(yylval->data_type,b)==0)
		return 1;
	return 0;

}
void free_ptr(ast *yylval)
{

	if(yylval==NULL)
	{
		printf("cannot free NULL ptr\n");
		return;
	}
	free(yylval);
	yylval =NULL;
}
yyerror()
{
	printf("yyerror\n");
	return;
}









int evaluate_ast(ast *root)
{

	if(root==NULL)
		{

			printf("should not print its NULLLLLLLLLL\n");
			return -1;
		}
	if(root->node_type==SLIST)
	{
		printf("SLIST\n" );
		fprintf(fp, "\n");
		int p1= evaluate_ast(root->ptr1); // stmnt
		int p2 = evaluate_ast(root->ptr2); // slist
		return -1;
	}
	else if(root->node_type == EQ)
	{
		fprintf(fp, "\n");
		printf("EQ\n" );
		printf("%d\n",root->ptr2->node_type );
		int p2 = evaluate_ast(root->ptr2);
		//printf("%d\n",p2);

		if(symtbl[root->ptr1->entry]->size==0)
		{
		//	printf("in eq not array\n" );


				int id_add = symtbl[root->ptr1->entry]->store;
				int reg = get_reg();
				fprintf(fp, "MOV R%d, %d\n",reg,id_add );
				fprintf(fp, "MOV [R%d], R%d\n",reg,p2 );

				free_reg();
				free_reg();

					//*(symtbl[root->ptr1->entry]->store.i)= root->ptr2->int_value;
				//	print_symbols();

		}else // array
		{

				int p3=evaluate_ast(root->ptr3);

				//int id_add = symtbl[root->ptr1->entry]->store + root->ptr2->int_value  ; wrong
				int reg = get_reg();
				fprintf(fp, "MOV R%d, %d\n",reg,symtbl[root->ptr1->entry]->store);
				fprintf(fp, "ADD R%d, R%d\n",reg,p2 );
				fprintf(fp, "MOV [R%d], R%d\n",reg,p3);

				free_reg();
				free_reg();
				free_reg();


		}
		//print_symbols();

		return -1;
	}
	else if(root->node_type== PLUS)
	{
		fprintf(fp, "\n");
		printf("PLUS\n" );
		int p1=evaluate_ast(root->ptr1);
		int p2=evaluate_ast(root->ptr2);



		fprintf(fp, "ADD R%d, R%d\n",p1,p2 );
		free_reg();
		return p1;


		//root->int_value=root->ptr1->int_value + root->ptr2->int_value;
	}
	else if(root->node_type== MINUS)
	{
		fprintf(fp, "\n");
		printf("MINUS\n" );
		int p1 =evaluate_ast(root->ptr1);
		int p2=evaluate_ast(root->ptr2);



	//	root->int_value=root->ptr1->int_value - root->ptr2->int_value;
	}
	else if(root->node_type== MUL)
	{
		fprintf(fp, "\n");
		printf("MUL\n" );
		int p1=evaluate_ast(root->ptr1);
		int p2=evaluate_ast(root->ptr2);


	//	root->int_value=root->ptr1->int_value - root->ptr2->int_value;
	}
	else if(root->node_type== DIV)
	{
		fprintf(fp, "\n");
		printf("DIV\n");
		int p1=evaluate_ast(root->ptr1);
		int p2=evaluate_ast(root->ptr2);



	//	root->int_value=root->ptr1->int_value / root->ptr2->int_value;
	}
	else if(root->node_type== EQEQ)
	{
		fprintf(fp, "\n");
		printf("EQEQ\n" );
		int r1=evaluate_ast(root->ptr1);
		int r2=evaluate_ast(root->ptr2);





				fprintf(fp, "EQ R%d, R%d\n",r1,r2 );
				free_reg();  // free r2
				return r1;



	}
	else if(root->node_type== NEQ)
	{
		fprintf(fp, "\n");
		printf("NEQ\n" );
		int r1=evaluate_ast(root->ptr1);
		int r2=evaluate_ast(root->ptr2);



				fprintf(fp, "NE R%d, R%d\n",r1,r2 );
				free_reg();  // free r2
				return r1;


	}
	else if(root->node_type== ID)
	{
		fprintf(fp, "\n");
		printf("ID\n" );
		if(root->ptr1==NULL) // not array
		{
			printf("not array id_ind: %d\n",root->entry);

			int r1 = get_reg();
			int r2 = get_reg();
			fprintf(fp, "MOV R%d, %d\n",r2,symtbl[root->entry]->store );
			fprintf(fp, "MOV R%d, [R%d]\n",r1,r2 );
			free_reg();
			return r1;
		}
		else //array
		{
		//	printf("array id_ind: %d\n",root->entry );

			int r1 = get_reg();
			int r2 = get_reg();
			int p1 =evaluate_ast(root->ptr1);
			fprintf(fp, "MOV R%d, %d\n",r2,symtbl[root->entry]->store);
			fprintf(fp, "ADD R%d, R%d\n",r2,p1 );
			fprintf(fp, "MOV R%d, [R%d]\n",r1,r2 );
			free_reg();
			free_reg();


			return r1;
		}

	}
	else if(root->node_type== IF)
	{
		fprintf(fp, "\n");
		printf("IF\n");
		int p1=evaluate_ast(root->ptr1);


		int l1=get_label();
		fprintf(fp, "IF%d:\n",l1);
		fprintf(fp, "JZ R%d, ELSE%d\n",p1,l1 );
		int p2=evaluate_ast(root->ptr2);
		fprintf(fp, "JMP ENDIF%d\n",l1 );
		fprintf(fp, "ELSE%d:\n",l1 );
		int p3 = evaluate_ast(root->ptr3);

		fprintf(fp, "ENDIF%d:\n",l1);
	}
	else if(root->node_type == WHILE)
	{
		fprintf(fp, "\n");
		printf("WHILE\n" );

		int l1=get_label();
		fprintf(fp, "LOOP%d:\n",l1);
			int p1=evaluate_ast(root->ptr1);
			fprintf(fp, "JZ R%d, ENDLOOP%d\n",p1,l1 );

			int p3=evaluate_ast(root->ptr2);
		fprintf(fp, "JMP LOOP%d\n",l1 );

		fprintf(fp, "ENDLOOP%d:\n",l1);


	}
	else if(root->node_type == NUM || root->node_type == T || root->node_type == F)
	{
		fprintf(fp, "\n");
		printf("NUM/T/F %d\n",root->int_value );
			int r=get_reg();
			fprintf(fp, "MOV R%d,%d\n",r,root->int_value );
			return r;
	}
	else if(root->node_type == READ)
	{
		fprintf(fp, "\n");
		printf("READ\n" );
		int r1 = get_reg();
		fprintf(fp, "IN R%d\n",r1 );
		int r2= get_reg();

		if(symtbl[root->entry]->size==0)
		{
			fprintf(fp, "MOV R%d, %d\n",r2,symtbl[root->entry]->store );
			fprintf(fp, "MOV [R%d], R%d\n",r2,r1 );

			free_reg();
			free_reg();


		}
		else
		{
			int p1=evaluate_ast(root->ptr1);
			fprintf(fp, "MOV R%d, %d\n",r2,symtbl[root->entry]->store );
			fprintf(fp, "ADD R%d, R%d\n",r2,p1 );
			fprintf(fp, "MOV [R%d], R%d\n",r2,r1 );

			free_reg();
			free_reg();
			free_reg();

		}

		printf("read over\n" );
	}
	else if(root->node_type == WRITE)
	{
		fprintf(fp, "\n");
		printf("WRITE\n");
		int p1=evaluate_ast(root->ptr1);

		fprintf(fp, "OUT R%d\n",p1 );
		free_reg();

	}
	else if(root->node_type == DLIST)
	{
		printf("..DLIST\n");
		printf("%s\n",root->name );
		printf("%d %d\n",root->ptr1->node_type, root->ptr1->entry );
		printf("%d \n",root->ptr2->node_type );

		int p1=evaluate_ast(root->ptr1);
		int p2=evaluate_ast(root->ptr2);
	}
	else if(root->node_type == INTEGER ||  root->node_type == BOOLEAN)
	{
		printf("INTEGER\n");
		if(symtbl[root->entry]->size==0)
		{
			symtbl[root->entry]->store=allocate_mem(1);
		//	fprintf(fp,"%s\n", );

		}
		else{
			symtbl[root->entry]->store=allocate_mem(symtbl[root->entry]->size);
		}
	}
	else
	{
		printf("shit...%s!! \n", root->name );
	}

}










void print_symbols()
{
	int i;
	for(i=0;i<id_count;i++)
		printf("%s %d\n",symtbl[i]->var_name,symtbl[i]->store);
}
int get_reg()
{
	return reg_ctr++;
}
void free_reg()
{
	reg_ctr--;
}
int get_label()
{
	return label_ctr++;
}
int allocate_mem(int size)
{
	int r=var_mem;
	var_mem = var_mem + size;
	return r;
}
main()
{
	fp=fopen("op.sil","w+");
	yyparse();
	return 1;
}
