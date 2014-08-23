/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "u6.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include "usrin.h"
	/* prototypes */
	
									/* symbol table */
	FILE *fp;
	//fp=fopen("out.txt","w");
	int reg_count=-1,label_count=-1;
	int sym[26];
	
	struct nodeTypeEx*opr(int oper, int nops, ...);	
	struct nodeTypeEx*id(struct symbol_table *entry,struct nodeTypeEx *ind);
	struct nodeTypeEx*con(int value);
	void install(struct symbol_table *entry);
	void install_a(struct symbol_table *entry,int size1);
	
	int ex(struct nodeTypeEx*p);
	int yylex(void);
	void yyerror(char *s);
	
	struct symbol_table *head;
	struct symbol_table *tail;
	struct symbol_table *temp=NULL;
	struct symbol_table *lookup(char *name1);
	
	int g_index;

	
								


/* Line 268 of yacc.c  */
#line 107 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     READ = 258,
     WRITE = 259,
     DELIM = 260,
     EQ = 261,
     IF = 262,
     THEN = 263,
     ELSE = 264,
     IFX = 265,
     ENDIF = 266,
     WHILE = 267,
     DO = 268,
     ENDWHILE = 269,
     DECL = 270,
     BOOLEAN = 271,
     INTEGER = 272,
     ENDDECL = 273,
     MAIN = 274,
     BEGINS = 275,
     END = 276,
     COMPILE = 277,
     ASSNG = 278,
     INT = 279,
     VAR = 280,
     UMINUS = 281
   };
#endif
/* Tokens.  */
#define READ 258
#define WRITE 259
#define DELIM 260
#define EQ 261
#define IF 262
#define THEN 263
#define ELSE 264
#define IFX 265
#define ENDIF 266
#define WHILE 267
#define DO 268
#define ENDWHILE 269
#define DECL 270
#define BOOLEAN 271
#define INTEGER 272
#define ENDDECL 273
#define MAIN 274
#define BEGINS 275
#define END 276
#define COMPILE 277
#define ASSNG 278
#define INT 279
#define VAR 280
#define UMINUS 281




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 37 "u6.y"

	int iValue; 								/* integer value */
	struct symbol_table *sym_entry; 								/* symbol table index */
	struct nodeTypeEx *nPtr; 							/* node pointer */
	


/* Line 293 of yacc.c  */
#line 203 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 215 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    30,    29,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    28,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    21,    31,    37,    43,    47,
      50,    54,    61,    65,    72,    74,    76,    79,    81,    84,
      90,    99,   106,   116,   126,   133,   143,   155,   165,   169,
     171,   173,   178,   183,   187,   191,   195,   199,   203
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    44,    42,    22,    -1,    42,    22,    -1,
      17,    19,    32,    33,    34,    35,    34,    43,    36,    34,
      -1,    17,    19,    32,    33,    35,    34,    43,    36,    34,
      -1,    20,    34,    48,    21,    34,    -1,    15,    34,    45,
      18,    34,    -1,    45,    47,    46,    -1,    47,    46,    -1,
      25,    37,    46,    -1,    25,    38,    24,    39,    37,    46,
      -1,    25,     5,    34,    -1,    25,    38,    24,    39,     5,
      34,    -1,    17,    -1,    16,    -1,    48,    49,    -1,    49,
      -1,     5,    34,    -1,    25,    28,    50,     5,    34,    -1,
      25,    38,    24,    39,    28,    50,     5,    34,    -1,     3,
      32,    25,    33,     5,    34,    -1,     3,    32,    25,    38,
      24,    39,    33,     5,    34,    -1,     3,    32,    25,    38,
      25,    39,    33,     5,    34,    -1,     4,    32,    50,    33,
       5,    34,    -1,     7,    32,    50,    33,     8,    48,    11,
       5,    34,    -1,     7,    32,    50,    33,     8,    48,     9,
      48,    11,     5,    34,    -1,    12,    32,    50,    33,    13,
      48,    14,     5,    34,    -1,    50,     5,    34,    -1,    24,
      -1,    25,    -1,    25,    38,    24,    39,    -1,    25,    38,
      25,    39,    -1,    50,    29,    50,    -1,    50,    30,    50,
      -1,    32,    50,    33,    -1,    50,    27,    50,    -1,    50,
      26,    50,    -1,    50,     6,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    65,    69,    70,    74,    78,    82,    83,
      87,    89,    91,    93,    97,    98,   102,   103,   108,   110,
     116,   122,   128,   134,   146,   148,   150,   152,   154,   159,
     161,   167,   173,   185,   187,   189,   191,   193,   195
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "READ", "WRITE", "DELIM", "EQ", "IF",
  "THEN", "ELSE", "IFX", "ENDIF", "WHILE", "DO", "ENDWHILE", "DECL",
  "BOOLEAN", "INTEGER", "ENDDECL", "MAIN", "BEGINS", "END", "COMPILE",
  "ASSNG", "INT", "VAR", "'>'", "'<'", "'='", "'+'", "'*'", "UMINUS",
  "'('", "')'", "'\\n'", "'{'", "'}'", "','", "'['", "']'", "$accept",
  "program", "main_function", "function", "declaration", "decl_list",
  "vars", "type", "slist", "stmnt", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    62,    60,    61,    43,
      42,   281,    40,    41,    10,   123,   125,    44,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    44,    45,    45,
      46,    46,    46,    46,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,    10,     9,     5,     5,     3,     2,
       3,     6,     3,     6,     1,     1,     2,     1,     2,     5,
       8,     6,     9,     9,     6,     9,    11,     9,     3,     1,
       1,     4,     4,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     1,     3,
       0,    15,    14,     0,     0,     0,     2,     0,     0,     0,
       9,     0,     7,     8,     0,     0,     0,     0,     0,    12,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    11,     0,     0,     0,     0,     0,
       0,    29,    30,     0,     0,    17,     0,     5,     4,     0,
       0,    18,     0,     0,     0,     0,    30,     0,     0,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,     6,    28,    38,    37,    36,
      33,    34,     0,     0,     0,     0,     0,     0,    31,    32,
       0,     0,     0,     0,     0,     0,     0,    19,     0,    31,
      21,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    22,
      23,     0,    25,    27,     0,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    37,     5,    13,    20,    14,    54,    55,
      56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const yytype_int16 yypact[] =
{
     -10,   -31,    12,    18,    17,    34,    26,    15,   -91,   -91,
      37,   -91,   -91,    87,    48,    29,   -91,    47,    48,    -3,
     -91,    20,   -91,   -91,    54,    48,    73,    67,    78,   -91,
     -91,    76,   102,   125,    -1,   125,   113,   110,   114,    48,
     115,    86,   116,   -91,   -91,   120,   117,   127,   123,   130,
     133,   -91,    30,    51,    45,   -91,   108,   -91,   -91,   141,
      51,   -91,    51,    51,    51,    70,   129,    11,   124,   -91,
     135,    51,    51,    51,    51,    51,   -24,    90,    95,   100,
     126,   131,   132,    84,   -91,   -91,   -91,   112,   112,   112,
     138,   -91,   167,   119,   168,   166,   162,   142,   149,   -91,
     139,   145,   143,   144,   146,    86,    86,   -91,    51,   -91,
     -91,   148,   151,   -91,    21,    60,   134,   180,   181,    86,
     182,   183,   155,   156,   157,    75,   158,   159,   -91,   -91,
     -91,   189,   -91,   -91,   161,   -91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   191,   163,   -91,   -91,   -12,   184,   -90,   -54,
     -52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      69,    67,    24,     6,    38,     1,    23,     2,    77,    92,
      78,    79,    80,    30,    93,   114,   115,    71,     8,    87,
      88,    89,    90,    91,    46,    47,    48,    44,    49,   125,
     119,     7,   120,    50,    25,    26,    39,    72,    73,     9,
      74,    75,    11,    12,    84,    51,    52,    15,    46,    47,
      48,     2,    49,    53,    27,    28,   116,    50,    64,    16,
      69,    69,    21,    46,    47,    48,    68,    49,    65,    51,
      52,    69,    50,    19,   121,    51,    66,    53,    46,    47,
      48,    22,    49,    53,    51,    52,   131,    50,    29,    46,
      47,    48,    53,    49,    81,    82,    71,    31,    50,    51,
      52,    71,    32,    11,    12,    17,    71,    53,   100,    82,
      51,    52,    33,    70,    71,    34,    72,    73,    53,    74,
      75,    72,    73,    94,    74,    75,    72,    73,    95,    74,
      75,    97,    71,    96,    72,    73,    35,    74,    75,   122,
      71,    74,    75,   102,   103,    36,    42,    41,    43,    59,
      57,    45,    72,    73,    58,    74,    75,    61,    85,    60,
      72,    73,    62,    74,    75,    63,    76,    83,    75,    86,
      98,    99,   101,   104,   105,   106,   107,   108,   109,   110,
     113,   117,   111,   112,   118,   123,   124,   126,   127,   128,
     129,   130,   132,   133,   134,   135,    10,    18,    40
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-91))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      54,    53,     5,    34,     5,    15,    18,    17,    60,    33,
      62,    63,    64,    25,    38,   105,   106,     6,     0,    71,
      72,    73,    74,    75,     3,     4,     5,    39,     7,   119,
       9,    19,    11,    12,    37,    38,    37,    26,    27,    22,
      29,    30,    16,    17,    33,    24,    25,    32,     3,     4,
       5,    17,     7,    32,    34,    35,   108,    12,    28,    22,
     114,   115,    33,     3,     4,     5,    21,     7,    38,    24,
      25,   125,    12,    25,    14,    24,    25,    32,     3,     4,
       5,    34,     7,    32,    24,    25,    11,    12,    34,     3,
       4,     5,    32,     7,    24,    25,     6,    24,    12,    24,
      25,     6,    35,    16,    17,    18,     6,    32,    24,    25,
      24,    25,    34,     5,     6,    39,    26,    27,    32,    29,
      30,    26,    27,    33,    29,    30,    26,    27,    33,    29,
      30,     5,     6,    33,    26,    27,    34,    29,    30,     5,
       6,    29,    30,    24,    25,    20,    36,    34,    34,    32,
      34,    36,    26,    27,    34,    29,    30,    34,    34,    32,
      26,    27,    32,    29,    30,    32,    25,    38,    30,    34,
      39,    39,     5,     5,     8,    13,    34,    28,    39,    34,
      34,    33,    39,    39,    33,     5,     5,     5,     5,    34,
      34,    34,    34,    34,     5,    34,     5,    13,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    17,    41,    42,    44,    34,    19,     0,    22,
      42,    16,    17,    45,    47,    32,    22,    18,    47,    25,
      46,    33,    34,    46,     5,    37,    38,    34,    35,    34,
      46,    24,    35,    34,    39,    34,    20,    43,     5,    37,
      43,    34,    36,    34,    46,    36,     3,     4,     5,     7,
      12,    24,    25,    32,    48,    49,    50,    34,    34,    32,
      32,    34,    32,    32,    28,    38,    25,    50,    21,    49,
       5,     6,    26,    27,    29,    30,    25,    50,    50,    50,
      50,    24,    25,    38,    33,    34,    34,    50,    50,    50,
      50,    50,    33,    38,    33,    33,    33,     5,    39,    39,
      24,     5,    24,    25,     5,     8,    13,    34,    28,    39,
      34,    39,    39,    34,    48,    48,    50,    33,    33,     9,
      11,    14,     5,     5,     5,    48,     5,     5,    34,    34,
      34,    11,    34,    34,     5,    34
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 64 "u6.y"
    {ex((yyvsp[(2) - (3)].nPtr));exit(0);}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 65 "u6.y"
    {ex((yyvsp[(1) - (2)].nPtr));exit(0);}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 69 "u6.y"
    {(yyval.nPtr)=(yyvsp[(8) - (10)].nPtr);}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 70 "u6.y"
    {(yyval.nPtr)=(yyvsp[(7) - (9)].nPtr);}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 74 "u6.y"
    {(yyval.nPtr)=(yyvsp[(3) - (5)].nPtr);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 87 "u6.y"
    {install((yyvsp[(1) - (3)].sym_entry));}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 89 "u6.y"
    {install_a((yyvsp[(1) - (6)].sym_entry),(yyvsp[(3) - (6)].iValue));}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 91 "u6.y"
    {install((yyvsp[(1) - (3)].sym_entry));}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 93 "u6.y"
    {install_a((yyvsp[(1) - (6)].sym_entry),(yyvsp[(3) - (6)].iValue));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 102 "u6.y"
    {(yyval.nPtr)=opr(';',2,(yyvsp[(1) - (2)].nPtr),(yyvsp[(2) - (2)].nPtr));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 103 "u6.y"
    {(yyval.nPtr)=(yyvsp[(1) - (1)].nPtr);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 108 "u6.y"
    {(yyval.nPtr)=opr(';',2,NULL,NULL);}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 110 "u6.y"
    {temp=lookup((yyvsp[(1) - (5)].sym_entry)->name);
									if(!temp)
									printf("variable %s not declared\n",(yyvsp[(1) - (5)].sym_entry)->name);
									else
									(yyval.nPtr)=opr('=',2,id((yyvsp[(1) - (5)].sym_entry),con(0)),(yyvsp[(3) - (5)].nPtr));}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 116 "u6.y"
    {temp=lookup((yyvsp[(1) - (8)].sym_entry)->name);
									if(!temp)
									printf("variable %s not declared\n",(yyvsp[(1) - (8)].sym_entry)->name);
									else
									(yyval.nPtr)=opr('=',2,id((yyvsp[(1) - (8)].sym_entry),con((yyvsp[(3) - (8)].iValue))),(yyvsp[(6) - (8)].nPtr));}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 122 "u6.y"
    {temp=lookup((yyvsp[(3) - (6)].sym_entry)->name);
									if(!temp)
									printf("variable %s not declared\n",(yyvsp[(3) - (6)].sym_entry)->name);
									else
									(yyval.nPtr)=opr(READ,1,id((yyvsp[(3) - (6)].sym_entry),con(0)));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 128 "u6.y"
    {temp=lookup((yyvsp[(3) - (9)].sym_entry)->name);
									if(!temp)
									printf("varialbe %s not declared\n",(yyvsp[(3) - (9)].sym_entry)->name);
									else
									(yyval.nPtr)=opr(READ,1,id((yyvsp[(3) - (9)].sym_entry),con((yyvsp[(5) - (9)].iValue))));}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 134 "u6.y"
    {temp=lookup((yyvsp[(5) - (9)].sym_entry)->name);
									if(!temp)
									printf("varialbe %s not declared\n",(yyvsp[(5) - (9)].sym_entry)->name);
									else
									{
									temp=lookup((yyvsp[(3) - (9)].sym_entry)->name);
									if(!temp)
									printf("varialbe %s not declared\n",(yyvsp[(3) - (9)].sym_entry)->name);
									else
									(yyval.nPtr)=opr(READ,1,id((yyvsp[(3) - (9)].sym_entry),id((yyvsp[(5) - (9)].sym_entry),con(0))));
									}}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 146 "u6.y"
    {(yyval.nPtr)=opr(WRITE,1,(yyvsp[(3) - (6)].nPtr));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 148 "u6.y"
    {(yyval.nPtr)=opr(IF,2,(yyvsp[(3) - (9)].nPtr),(yyvsp[(6) - (9)].nPtr));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 150 "u6.y"
    {(yyval.nPtr)=opr(IFX,3,(yyvsp[(3) - (11)].nPtr),(yyvsp[(6) - (11)].nPtr),(yyvsp[(8) - (11)].nPtr));}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 152 "u6.y"
    {(yyval.nPtr)=opr(WHILE,2,(yyvsp[(3) - (9)].nPtr),(yyvsp[(6) - (9)].nPtr));}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 154 "u6.y"
    {(yyval.nPtr)=(yyvsp[(1) - (3)].nPtr);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 159 "u6.y"
    {(yyval.nPtr)=con((yyvsp[(1) - (1)].iValue));}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 161 "u6.y"
    {temp=lookup((yyvsp[(1) - (1)].sym_entry)->name);
							if(!temp)
							printf("variable %s not declared\n",(yyvsp[(1) - (1)].sym_entry)->name);
							else
							(yyval.nPtr)=id((yyvsp[(1) - (1)].sym_entry),con(0));}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 167 "u6.y"
    {temp=lookup((yyvsp[(1) - (4)].sym_entry)->name);
							if(!temp)
							printf("variable %s not declared\n",(yyvsp[(1) - (4)].sym_entry)->name);
							else
							(yyval.nPtr)=id((yyvsp[(1) - (4)].sym_entry),con((yyvsp[(3) - (4)].iValue)));}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 173 "u6.y"
    {temp=lookup((yyvsp[(3) - (4)].sym_entry)->name);
							if(!temp)
							printf("variable %s not declared\n",(yyvsp[(3) - (4)].sym_entry)->name);
							else
							{
							temp=lookup((yyvsp[(1) - (4)].sym_entry)->name);
							if(!temp)
							printf("varialbe %s not declared\n",(yyvsp[(1) - (4)].sym_entry)->name);
							else
							(yyval.nPtr)=id((yyvsp[(1) - (4)].sym_entry),id((yyvsp[(3) - (4)].sym_entry),con(0)));}
							}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 185 "u6.y"
    {(yyval.nPtr)=opr('+',2,(yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 187 "u6.y"
    {(yyval.nPtr)=opr('*',2,(yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 189 "u6.y"
    {(yyval.nPtr)=(yyvsp[(2) - (3)].nPtr);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 191 "u6.y"
    {(yyval.nPtr)=opr('<',2,(yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 193 "u6.y"
    {(yyval.nPtr)=opr('>',2,(yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 195 "u6.y"
    {(yyval.nPtr)=opr(EQ,2,(yyvsp[(1) - (3)].nPtr),(yyvsp[(3) - (3)].nPtr));}
    break;



/* Line 1806 of yacc.c  */
#line 1814 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 200 "u6.y"



struct nodeTypeEx *con(int val)
{
	struct nodeTypeEx *p;
	
	if((p=malloc(sizeof(struct nodeTypeEx)))==NULL)
	yyerror("out of memory");
	
	else
	{
		p->type = conType;
		p->con.value = val;
		return p;
	}
}





struct nodeTypeEx *id(struct symbol_table *index,struct nodeTypeEx *ind)
{
	struct nodeTypeEx *p;
	p=malloc(sizeof(struct nodeTypeEx));
	
	if(p==NULL)
	yyerror("out of memory");
	
	else
	{
		temp=lookup(index->name);
		p->type=idType;
		p->id.entry=temp;
		p->id.indx=ind;
		return p;
	}
}


struct nodeTypeEx *opr(int oper,int nops, ...)
{
	va_list ap;
	struct nodeTypeEx *p;
	int i;
	
	if((p=malloc(sizeof(struct nodeTypeEx)))==NULL)
	yyerror("out of memory");
	
	if((p->opr.pr=malloc(nops*sizeof(struct nodeTypeEx)))==NULL)
	yyerror("out of memory");

	else
	{
		p->type=oprType;
		p->opr.oper=oper;
		p->opr.nops=nops;
		va_start(ap,nops);
		for(i=0;i<nops;i++)
		{
			p->opr.pr[i]=va_arg(ap,struct nodeTypeEx*);
			
		}
		va_end(ap);
		return p;
	}
}



void freeNode(struct nodeTypeEx *p) 
{
	int i;
	if (!p) return;
	if (p->type == oprType)
	{
		for (i = 0; i < p->opr.nops; i++)
			freeNode(p->opr.pr[i]);
		free(p->opr.pr);
	}
	free (p);
}


void install(struct symbol_table *entry){
	temp=lookup(entry->name);
	temp->size=1;
	
	temp->binding=malloc(sizeof(int)*temp->size);
	
	
	
	}
		
void install_a(struct symbol_table *entry,int size1){
	temp=lookup(entry->name);
	temp->size=size1;
	
	temp->binding=malloc(sizeof(int)*entry->size);
	
	
	}
	
	
struct symbol_table *lookup(char *name1){
	struct symbol_table *temp1;
	temp1=head;
	while((strcmp(temp1->name,name1)) && temp1!=NULL)
	{
		temp1=temp1->next;
	}
	if(temp1!=NULL)
	return temp1;
	else
	return NULL;
	}	






int ex(struct nodeTypeEx *p)
{
	if(!p) return 0;
	
	switch(p->type)
	{
		case conType:				{return (p->con.value);}
			
		case idType:				{temp=lookup(p->id.entry->name);
							if(temp->binding==NULL)
							printf("unassinged variable \n");
							else
							{return (*((temp->binding)+ex(p->id.indx)));}}
		
		case oprType:
		{
			switch(p->opr.oper)
			{
				case ';':		{ex(p->opr.pr[0]);return(ex(p->opr.pr[1]));}
				
				case '=':		{temp=lookup(p->opr.pr[0]->id.entry->name);
							*((temp->binding)+(ex(p->opr.pr[0]->id.indx)))=ex(p->opr.pr[1]);
							
							return 0;}
				
				
						
				case READ:		{
							temp=lookup(p->opr.pr[0]->id.entry->name);
							scanf("%d",((temp->binding)+(ex(p->opr.pr[0]->id.indx))));
							return 0;}
							
				
				
				case WRITE:		{
							printf("%d\n",ex(p->opr.pr[0]));
							return 0;}
				
				case IF:		{if(ex(p->opr.pr[0]))
								ex(p->opr.pr[1]);
							return 0;}
							
				case IFX:		{if(ex(p->opr.pr[0]))
								ex(p->opr.pr[1]);
							else
								ex(p->opr.pr[2]);
							return 0;
							}
								
				case WHILE:		{while(ex(p->opr.pr[0]))
								ex(p->opr.pr[1]);
							return 0;}
								
				case '+':		{return (ex(p->opr.pr[0])+ex(p->opr.pr[1]));}
				
				case '*':		{return (ex(p->opr.pr[0])*ex(p->opr.pr[1]));}
				
				case '<':		{return (ex(p->opr.pr[0])<ex(p->opr.pr[1]));}
				
				case '>':		{return (ex(p->opr.pr[0])>ex(p->opr.pr[1]));}
				
				case EQ:		{return (ex(p->opr.pr[0])==ex(p->opr.pr[1]));}
					
			}
		}
	}
	
	return 0;
}








void yyerror (char *s)
{
	fprintf(stderr,"%s\n",s);
	
}

int main (void)
{
	int i;
	for( i=0;i<26;i++)
	sym[i]=-100;
	
	
	yyparse();
	return 0;
}		
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

