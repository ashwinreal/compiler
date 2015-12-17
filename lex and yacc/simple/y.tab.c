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

void free_ptr(ast *yylval);
void evaluate_ast(ast *root);
void print_symbols();

#line 82 "y.tab.c" /* yacc.c:339  */

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
    NEQ = 285
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
#define NEQ 285

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

#line 193 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  32
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  77

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

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
      35,    36,    33,    31,     2,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    53,    54,    54,    55,    69,    84,   103,
     124,   125,   139,   146,   151,   154,   159,   211,   261,   279,
     295,   311,   326,   343,   358,   389,   390,   415,   418,   419,
     423,   433,   443
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
  "MINUS", "MUL", "DIV", "SLIST", "EQ", "NEQ", "'+'", "'-'", "'*'", "'/'",
  "'('", "')'", "';'", "'['", "']'", "'='", "$accept", "pgm", "pgmdecl",
  "dlist", "dstmt", "pgmbody", "stmtlist", "stmt", "assign", "expr",
  "cond", "loop", YY_NULLPTR
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
     285,    43,    45,    42,    47,    40,    41,    59,    91,    93,
      61
};
# endif

#define YYPACT_NINF -29

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-29)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -4,    16,    14,     1,    21,    24,    39,    16,   -29,    10,
     -29,     9,    11,   -29,   -29,   -23,    -1,    -1,    42,    10,
     -29,   -29,   -29,   -29,    -1,   -29,    -1,    -1,    -1,    37,
     -29,   -29,   -29,    -1,     8,    84,   -29,   -29,    25,    35,
      52,    89,    -1,   114,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    15,    17,    22,   -29,    62,   -29,    49,   -28,
     -28,    38,    38,   -29,   -29,    58,   -29,   -29,    -1,   -29,
      10,   -29,   -29,   106,    64,   -29,   -29
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     5,     1,     0,
       2,     0,     0,     3,     4,     0,     0,     0,     0,    12,
      13,    14,    15,     6,     0,     7,     0,     0,     0,    26,
      27,    28,    29,     0,     0,     0,    10,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,    25,     0,    22,
      23,    18,    19,    20,    21,     0,     9,     8,     0,    24,
       0,    30,    32,     0,     0,    17,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -29,    70,   -29,   -29,    -7,   -29,   -29,   -17,
     -29,   -29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    10,    18,    19,    20,    34,
      21,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,     1,    29,    47,    48,    49,    50,    38,     9,    39,
      40,    41,    37,    15,     8,    27,    43,    28,    44,    16,
      30,    31,    32,    17,    11,    56,    45,    12,    59,    60,
      61,    62,    63,    64,    33,     4,     5,    58,    46,    47,
      48,    49,    50,    45,    65,    13,    23,    24,    25,    26,
      36,    73,    66,    45,    67,    46,    47,    48,    49,    50,
      70,    71,    68,    74,    52,    46,    47,    48,    49,    50,
      45,    49,    50,    72,    53,    42,    76,    14,     0,     0,
      45,     0,    46,    47,    48,    49,    50,     0,     0,     0,
       0,    54,    46,    47,    48,    49,    50,     0,    51,     0,
       0,    69,    45,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,    46,    47,    48,    49,    50,    46,
      47,    48,    49,    50,    45,     0,    55,     0,     0,     0,
       0,     0,    45,     0,     0,     0,    46,    47,    48,    49,
      50,     0,     0,    75,    46,    47,    48,    49,    50,     0,
      57
};

static const yytype_int8 yycheck[] =
{
      17,     5,     3,    31,    32,    33,    34,    24,     7,    26,
      27,    28,    19,     3,     0,    38,    33,    40,    10,     9,
      21,    22,    23,    13,     3,    42,    18,     3,    45,    46,
      47,    48,    49,    50,    35,    19,    20,    44,    30,    31,
      32,    33,    34,    18,    51,     6,    37,    38,    37,    38,
       8,    68,    37,    18,    37,    30,    31,    32,    33,    34,
      11,    12,    40,    70,    39,    30,    31,    32,    33,    34,
      18,    33,    34,    15,    39,    38,    12,     7,    -1,    -1,
      18,    -1,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    39,    30,    31,    32,    33,    34,    -1,    14,    -1,
      -1,    39,    18,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    30,
      31,    32,    33,    34,    18,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    -1,    -1,    37,    30,    31,    32,    33,    34,    -1,
      36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    42,    43,    19,    20,    44,    45,     0,     7,
      46,     3,     3,     6,    44,     3,     9,    13,    47,    48,
      49,    51,    52,    37,    38,    37,    38,    38,    40,     3,
      21,    22,    23,    35,    50,    50,     8,    47,    50,    50,
      50,    50,    38,    50,    10,    18,    30,    31,    32,    33,
      34,    14,    39,    39,    39,    37,    50,    36,    47,    50,
      50,    50,    50,    50,    50,    47,    37,    37,    40,    39,
      11,    12,    15,    50,    47,    37,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    45,    45,    45,    45,
      46,    47,    47,    48,    48,    48,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     1,     3,     3,     6,     6,
       3,     2,     1,     1,     1,     1,     4,     7,     3,     3,
       3,     3,     3,     3,     4,     3,     1,     1,     1,     1,
       5,     7,     5
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
#line 52 "sil.y" /* yacc.c:1646  */
    {printf("complete\n");print_symbols();exit(1);}
#line 1332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 53 "sil.y" /* yacc.c:1646  */
    {}
#line 1338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 54 "sil.y" /* yacc.c:1646  */
    {}
#line 1344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 55 "sil.y" /* yacc.c:1646  */
    {
						int index_id=check_exist((yyvsp[-1]));
						if(index_id!=-1)
							printf("error : name %s already exists\n", (yyvsp[-1])->name);
						tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
						strcpy(temp_symb->var_name,(yyvsp[-1])->name);
						temp_symb->size=0;
					  strcpy(temp_symb->data_type,"boolean");
						temp_symb->store.f=(bool *)malloc(sizeof(bool));
						*(temp_symb->store.f)=false;
						symtbl[id_count++]=temp_symb;
						free_ptr((yyvsp[-1]));
						//printf("declaration %s",yylval->data_type);
					}
#line 1363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 69 "sil.y" /* yacc.c:1646  */
    {
				int index_id=check_exist((yyvsp[-1]));
				if(index_id!=-1)
					printf("error : name %s already exists\n", (yyvsp[-1])->name);
				tbl *temp_symb = (tbl *) malloc(sizeof(tbl));
				strcpy(temp_symb->var_name,(yyvsp[-1])->name);
				temp_symb->size=0;
				strcpy(temp_symb->data_type,"integer");

				temp_symb->store.i=(int *)malloc(sizeof(int));
				*(temp_symb->store.i)=0;
				symtbl[id_count++]=temp_symb;
				free_ptr((yyvsp[-1]));
				//	printf("declaration %s",yylval->data_type);
		}
#line 1383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 84 "sil.y" /* yacc.c:1646  */
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

				temp_symb->store.i=(int *)malloc((yyvsp[-2])->int_value*sizeof(int));
				memset(temp_symb->store.i,0,(yyvsp[-2])->int_value);
				symtbl[id_count++]=temp_symb;
				free_ptr((yyvsp[-4]));

		}
#line 1407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 103 "sil.y" /* yacc.c:1646  */
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

			temp_symb->store.f=(bool *)malloc((yyvsp[-2])->int_value*sizeof(bool));
			memset(temp_symb->store.f,false,(yyvsp[-2])->int_value);
			symtbl[id_count++]=temp_symb;
			free_ptr((yyvsp[-4]));

		}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 124 "sil.y" /* yacc.c:1646  */
    {printf("evaluating the ast\n"); ;evaluate_ast((yyvsp[-1]));}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 125 "sil.y" /* yacc.c:1646  */
    {
													ast *temp = (ast *)malloc(sizeof(ast));
													(yyval)=temp;
													strcpy(temp->data_type,"void");
													(yyval)->node_type = SLIST;

													(yyval)->ptr1 = (yyvsp[-1]);
													(yyval)->ptr2 = (yyvsp[0]);





}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 139 "sil.y" /* yacc.c:1646  */
    {

												(yyval)=(yyvsp[0]);



			}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 146 "sil.y" /* yacc.c:1646  */
    {
												(yyval)=(yyvsp[0]);


}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 151 "sil.y" /* yacc.c:1646  */
    {
												(yyval)=(yyvsp[0]);
	}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 154 "sil.y" /* yacc.c:1646  */
    {
												(yyval)=(yyvsp[0]);
	}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 159 "sil.y" /* yacc.c:1646  */
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
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 211 "sil.y" /* yacc.c:1646  */
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
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 261 "sil.y" /* yacc.c:1646  */
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
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 279 "sil.y" /* yacc.c:1646  */
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
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 295 "sil.y" /* yacc.c:1646  */
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
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 311 "sil.y" /* yacc.c:1646  */
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
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 326 "sil.y" /* yacc.c:1646  */
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
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 343 "sil.y" /* yacc.c:1646  */
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
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 358 "sil.y" /* yacc.c:1646  */
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
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 389 "sil.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 390 "sil.y" /* yacc.c:1646  */
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
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 415 "sil.y" /* yacc.c:1646  */
    {
		(yyval)=(yyvsp[0]);
	}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 418 "sil.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 419 "sil.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 423 "sil.y" /* yacc.c:1646  */
    {

				(yyval)=(ast*)malloc(sizeof(ast));
				strcpy((yyval)->name,"if");
				(yyval)->node_type=IF;
				(yyval)->ptr1=(yyvsp[-3]);
				(yyval)->ptr2=(yyvsp[-1]);
				(yyval)->ptr3=NULL;

}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 433 "sil.y" /* yacc.c:1646  */
    {
		(yyval)=(ast*)malloc(sizeof(ast));
		strcpy((yyval)->name,"ifelse");
		(yyval)->node_type=IF;
		(yyval)->ptr1=(yyvsp[-5]);
		(yyval)->ptr2=(yyvsp[-3]);
		(yyval)->ptr3=(yyvsp[-1]);

	}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 443 "sil.y" /* yacc.c:1646  */
    {
	(yyval)=(ast*)malloc(sizeof(ast));
	strcpy((yyval)->name,"while");
	(yyval)->node_type=WHILE;
	(yyval)->ptr1=(yyvsp[-3]);
	(yyval)->ptr2=(yyvsp[-1]);
	(yyval)->ptr3=NULL;



}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1871 "y.tab.c" /* yacc.c:1646  */
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
#line 458 "sil.y" /* yacc.c:1906  */


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
	printf("error\n");
	return;
}
void evaluate_ast(ast *root)
{
	if(root==NULL)
		{printf("should not print its NULLLLLLLLLL\n");return;}
	if(root->node_type==SLIST)
	{
		printf("SLIST\n" );
		evaluate_ast(root->ptr1); // stmnt
		evaluate_ast(root->ptr2); // slist
	}
	else if(root->node_type== EQ)
	{
		printf("EQ\n" );
		evaluate_ast(root->ptr2);
		printf("id_ind : %d  name: %s rhs: %d  dt: %s\n ",root->ptr1->entry,root->ptr1->name,root->ptr2->int_value,root->ptr1->data_type );

		if(symtbl[root->ptr1->entry]->size==0)
		{
			printf("in eq not array\n" );

			if(strcmp(root->ptr1->data_type,"integer")==0)
			{

					*(symtbl[root->ptr1->entry]->store.i)= root->ptr2->int_value;
				//	print_symbols();
			}
			else
				*(symtbl[root->ptr1->entry]->store.f)= root->ptr2->bool_value;
		}else // array
		{

			evaluate_ast(root->ptr3);
			if(strcmp(root->ptr1->data_type,"integer")==0)
				*(symtbl[root->ptr1->entry]->store.i + root->ptr2->int_value )= root->ptr3->int_value;
			else
				*(symtbl[root->ptr1->entry]->store.f + root->ptr2->int_value )= root->ptr3->bool_value;
		}
		//print_symbols();
	}
	else if(root->node_type== PLUS)
	{
		printf("PLUS\n" );
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		root->int_value=root->ptr1->int_value + root->ptr2->int_value;
	}
	else if(root->node_type== MINUS)
	{
		printf("MINUS\n" );
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		root->int_value=root->ptr1->int_value - root->ptr2->int_value;
	}
	else if(root->node_type== MUL)
	{
		printf("MUL\n" );
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		root->int_value=root->ptr1->int_value - root->ptr2->int_value;
	}
	else if(root->node_type== DIV)
	{
		printf("DIV\n");
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		root->int_value=root->ptr1->int_value / root->ptr2->int_value;
	}
	else if(root->node_type== EQEQ)
	{
		printf("EQEQ\n" );
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		if(strcmp(root->ptr1->data_type,"integer")==0)
			root->bool_value=root->ptr1->int_value == root->ptr2->int_value;
		else
			root->bool_value=root->ptr1->bool_value == root->ptr2->bool_value;
	}
	else if(root->node_type== NEQ)
	{
		printf("NEQ\n" );
		evaluate_ast(root->ptr1);
		evaluate_ast(root->ptr2);
		if(strcmp(root->ptr1->data_type,"integer")==0)
			root->bool_value=root->ptr1->int_value != root->ptr2->int_value;
		else
			root->bool_value=root->ptr1->bool_value != root->ptr2->bool_value;
	}
	else if(root->node_type== ID)
	{
		printf("ID\n" );
		if(root->ptr1==NULL) // not array
		{
			printf("not array id_ind: %d\n",root->entry);
			if(strcmp(root->data_type,"integer")==0)
				root->int_value = *(symtbl[root->entry]->store.i);
			else
				root->bool_value = *(symtbl[root->entry]->store.f);
		}
		else //array
		{
			evaluate_ast(root->ptr1);
			if(strcmp(root->data_type,"integer")==0)
				root->int_value = *(symtbl[root->entry]->store.i + root->ptr1->int_value);
			else
				root->bool_value = *(symtbl[root->entry]->store.f + root->ptr1->int_value);
		}

	}
	else if(root->node_type== IF)
	{
		printf("IF\n");
		evaluate_ast(root->ptr1);
		printf("bool val: %d\n",root->ptr1->bool_value );
		if(root->ptr1->bool_value)
			evaluate_ast(root->ptr2);
		else
			{
				if(root->ptr3!=NULL)  // else
				evaluate_ast(root->ptr3);
			}
	}
	else if(root->node_type == WHILE)
	{
		printf("WHILE\n" );
		while(1)
		{
			evaluate_ast(root->ptr1);
			if(root->ptr1->bool_value==false)
				break;
			evaluate_ast(root->ptr2);
		}
	}
	else if(root->node_type == NUM || root->node_type == T || root->node_type == F)
	{
		printf("NUM/T/F %d\n",root->int_value );
			return;
	}
	else
	{
		printf("shit...%s!! \n", root->name );
	}

}

void print_symbols()
{
	int i;
	printf("\n");
	for(i=0;i<id_count;i++)
	{
		if(symtbl[i]->size == 0){
		printf("%s   ", symtbl[i]->var_name);
		printf("%d\n", *(symtbl[i]->store.i));
	}
	else{
		printf("%s   ", symtbl[i]->var_name);
		int j;
		for(j=0;j<symtbl[i]->size;j++)
			printf("%d ", *(symtbl[i]->store.i + j));
		printf("\n");
	}
	}
}

main()
{
	yyparse();
	return 1;
}
