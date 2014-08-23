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
#line 1 "user.y"

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 int yylex(void);
 void yyerror(char *);
 int i;
 int var_type; //a global variable to keep track of type
 int error_flag=0;
 int yylineno;

 struct symbol_table
 {
  int type;
  int size;
  char *name;
  int *binding;
  struct symbol_table *next;
 };

 struct tree
	{	
		int num;
		struct symbol_table *loc;
		int d; 		//0->arithmetic,1->number,2->variable,3->read,4->write,5->if,6->while,7->void  
		int rettype;	//0->void stmt,1->bool expr/var,2->integer expr/var
		char op;
		struct tree *left,*right,*further;
		char *var_name;
	}; 
 
 struct symbol_table *head=NULL;
 struct symbol_table *hold,*back;		//for the linked list
 struct symbol_table *temp;			//for installation and lookup functions
					

 int calculate(struct tree *);
 struct tree* assign(struct tree *main,struct tree *left,struct tree *right,struct tree *further,int rettype);

 struct symbol_table* lookup(char *var_name);
 void install(int var_type,int var_size,char *var_name);



/* Line 268 of yacc.c  */
#line 117 "y.tab.c"

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
     VAR = 258,
     NUM = 259,
     reads = 260,
     writes = 261,
     ifs = 262,
     whiles = 263,
     IFEQ = 264,
     thens = 265,
     endifs = 266,
     dos = 267,
     endwhiles = 268,
     compile = 269,
     elses = 270,
     begins = 271,
     ends = 272,
     integer = 273,
     boolean = 274,
     decls = 275,
     enddecls = 276,
     mains = 277
   };
#endif
/* Tokens.  */
#define VAR 258
#define NUM 259
#define reads 260
#define writes 261
#define ifs 262
#define whiles 263
#define IFEQ 264
#define thens 265
#define endifs 266
#define dos 267
#define endwhiles 268
#define compile 269
#define elses 270
#define begins 271
#define ends 272
#define integer 273
#define boolean 274
#define decls 275
#define enddecls 276
#define mains 277




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 47 "user.y"

 struct tree *node;		



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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  33
/* YYNRULES -- Number of states.  */
#define YYNSTATES  98

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,    10,     9,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
      14,    11,    13,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,    12,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    15,    19,    23,    28,    32,
      34,    36,    40,    42,    44,    49,    52,    54,    59,    65,
      73,    82,    88,    99,   108,   117,   121,   125,   129,   133,
     137,   141,   143,   148
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    38,    36,    19,    -1,    36,    19,    -1,
      27,    28,    29,    37,    -1,    21,    43,    22,    -1,    25,
      39,    26,    -1,    39,    40,    41,    30,    -1,    40,    41,
      30,    -1,    23,    -1,    24,    -1,    41,    31,    42,    -1,
      42,    -1,     3,    -1,     3,    32,     4,    33,    -1,    43,
      44,    -1,    44,    -1,     3,    11,    45,    30,    -1,     5,
      28,     3,    29,    30,    -1,     3,    32,    45,    33,    11,
      45,    30,    -1,     5,    28,     3,    32,    45,    33,    29,
      30,    -1,     6,    28,    45,    29,    30,    -1,     7,    28,
      45,    29,    15,    43,    20,    43,    16,    30,    -1,     7,
      28,    45,    29,    15,    43,    16,    30,    -1,     8,    28,
      45,    29,    17,    43,    18,    30,    -1,    45,     9,    45,
      -1,    45,    10,    45,    -1,    28,    45,    29,    -1,    45,
      12,    45,    -1,    45,    13,    45,    -1,    45,    14,    45,
      -1,     3,    -1,     3,    32,    45,    33,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    66,    70,    79,    82,    85,    86,    89,
      90,    93,    94,    97,   106,   113,   122,   128,   141,   154,
     168,   182,   184,   186,   188,   192,   194,   196,   198,   200,
     202,   204,   217,   231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "NUM", "reads", "writes", "ifs",
  "whiles", "'+'", "'*'", "'='", "IFEQ", "'>'", "'<'", "thens", "endifs",
  "dos", "endwhiles", "compile", "elses", "begins", "ends", "integer",
  "boolean", "decls", "enddecls", "mains", "'('", "')'", "';'", "','",
  "'['", "']'", "$accept", "program", "main_function", "function",
  "declaration", "decl_list", "type", "var_list", "var_complex", "Slist",
  "Stmt", "E", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,    43,
      42,    61,   264,    62,    60,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,    40,    41,
      59,    44,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    35,    36,    37,    38,    39,    39,    40,
      40,    41,    41,    42,    42,    43,    43,    44,    44,    44,
      44,    44,    44,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     4,     3,     3,     4,     3,     1,
       1,     3,     1,     1,     4,     2,     1,     4,     5,     7,
       8,     5,    10,     8,     8,     3,     3,     3,     3,     3,
       3,     1,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     9,    10,     0,     0,
       0,     1,     3,     0,     6,     0,    13,     0,    12,     0,
       2,     0,     0,     8,     0,     0,     4,     7,     0,    11,
       0,     0,     0,     0,     0,     0,    16,    14,     0,     0,
       0,     0,     0,     0,     5,    15,    31,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
      27,    25,    26,    28,    29,    30,     0,    18,     0,    21,
       0,     0,    32,     0,     0,     0,     0,    19,     0,     0,
       0,     0,    20,    23,     0,    24,     0,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    26,     5,     8,     9,    17,    18,    35,
      36,    49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
      -9,    11,   -26,    44,    29,    31,   -67,   -67,    77,    66,
      47,   -67,   -67,    63,   -67,    66,    67,    61,   -67,    81,
     -67,    88,    80,   -67,    66,   124,   -67,   -67,    95,   -67,
      22,    82,   109,   110,   111,    90,   -67,   -67,     3,     3,
     133,     3,     3,     3,   -67,   -67,   112,   -67,     3,    33,
      -1,    51,    52,    58,    65,     3,    76,     3,     3,     3,
       3,     3,   -67,   129,   113,     3,   115,   126,   130,    16,
     -67,   132,   -67,   125,   125,   125,     3,   -67,    27,   -67,
     124,   124,   -67,    43,   119,   101,   108,   -67,   116,   120,
     124,   121,   -67,   -67,   117,   -67,   122,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   144,   -67,   -67,   -67,   145,   139,   131,   -66,
     -35,   -38
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      45,    50,    10,    52,    53,    54,    46,    47,    57,    58,
      56,    59,    60,    61,    85,    86,     1,    69,     2,    71,
      72,    73,    74,    75,    94,    57,    58,    78,    59,    60,
      61,    48,    63,    38,     6,     7,    57,    58,    83,    59,
      60,    61,    57,    58,    11,    59,    60,    61,    12,    82,
      45,    45,    57,    58,    39,    59,    60,    61,     2,    45,
      84,    57,    58,    62,    59,    60,    61,    57,    58,    16,
      59,    60,    61,    87,    57,    58,    19,    59,    60,    61,
      64,    66,    20,    65,    28,    57,    58,    67,    59,    60,
      61,    23,    24,    30,    68,    31,    32,    33,    34,    22,
       6,     7,    25,    14,    30,    70,    31,    32,    33,    34,
      40,    30,    44,    31,    32,    33,    34,    89,    27,    24,
      30,    90,    31,    32,    33,    34,    91,    30,    37,    31,
      32,    33,    34,    96,    57,    58,    51,    41,    42,    43,
      76,    80,    58,    77,    55,    79,    92,    81,    88,    13,
      93,    95,    97,    15,    21,    29
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-67))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      35,    39,    28,    41,    42,    43,     3,     4,     9,    10,
      48,    12,    13,    14,    80,    81,    25,    55,    27,    57,
      58,    59,    60,    61,    90,     9,    10,    65,    12,    13,
      14,    28,    33,    11,    23,    24,     9,    10,    76,    12,
      13,    14,     9,    10,     0,    12,    13,    14,    19,    33,
      85,    86,     9,    10,    32,    12,    13,    14,    27,    94,
      33,     9,    10,    30,    12,    13,    14,     9,    10,     3,
      12,    13,    14,    30,     9,    10,    29,    12,    13,    14,
      29,    29,    19,    32,     4,     9,    10,    29,    12,    13,
      14,    30,    31,     3,    29,     5,     6,     7,     8,    32,
      23,    24,    21,    26,     3,    29,     5,     6,     7,     8,
      28,     3,    22,     5,     6,     7,     8,    16,    30,    31,
       3,    20,     5,     6,     7,     8,    18,     3,    33,     5,
       6,     7,     8,    16,     9,    10,     3,    28,    28,    28,
      11,    15,    10,    30,    32,    30,    30,    17,    29,     5,
      30,    30,    30,     8,    15,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    27,    35,    36,    38,    23,    24,    39,    40,
      28,     0,    19,    36,    26,    40,     3,    41,    42,    29,
      19,    41,    32,    30,    31,    21,    37,    30,     4,    42,
       3,     5,     6,     7,     8,    43,    44,    33,    11,    32,
      28,    28,    28,    28,    22,    44,     3,     4,    28,    45,
      45,     3,    45,    45,    45,    32,    45,     9,    10,    12,
      13,    14,    30,    33,    29,    32,    29,    29,    29,    45,
      29,    45,    45,    45,    45,    45,    11,    30,    45,    30,
      15,    17,    33,    45,    33,    43,    43,    30,    29,    16,
      20,    18,    30,    30,    43,    30,    16,    30
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
        case 4:

/* Line 1806 of yacc.c  */
#line 70 "user.y"
    {
						 	if(error_flag==0)
								{calculate((yyvsp[(4) - (4)].node));exit(0);}
							else
								{printf("Errors In Program \n ABORT \n");
								 exit(0);}
							}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 79 "user.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 89 "user.y"
    {var_type=2;}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 90 "user.y"
    {var_type=1;}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 97 "user.y"
    {
							temp=lookup((yyvsp[(1) - (1)].node)->var_name);
							//printf("%s",$1->var_name);
							if(temp==NULL)
								{
								 install(var_type,1,(yyvsp[(1) - (1)].node)->var_name);
								 (yyvsp[(1) - (1)].node)->rettype=var_type;}
							}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 106 "user.y"
    {
							temp=lookup((yyvsp[(1) - (4)].node)->var_name);
							if(temp==NULL)
								{install(var_type,(yyvsp[(3) - (4)].node)->num,(yyvsp[(1) - (4)].node)->var_name);
								 (yyvsp[(1) - (4)].node)->rettype=var_type;}
		;					}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 113 "user.y"
    {
						 struct tree *stub = malloc(sizeof(struct tree));
						 stub->d = 7;
						 stub->left=(yyvsp[(1) - (2)].node);
						 stub->right=(yyvsp[(2) - (2)].node);
						 stub->rettype=0;
						 (yyval.node) = stub;
						}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 122 "user.y"
    {
						(yyval.node)=(yyvsp[(1) - (1)].node);
						}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 128 "user.y"
    {
									  temp=lookup((yyvsp[(1) - (4)].node)->var_name);	
									  if(temp!=NULL)
									  {	
										(yyvsp[(1) - (4)].node)->loc=temp;
										(yyvsp[(1) - (4)].node)->rettype=temp->type;
										(yyval.node)=assign((yyvsp[(2) - (4)].node),(yyvsp[(1) - (4)].node),(yyvsp[(3) - (4)].node),NULL,0);
									  }
									 else
									 {printf("VAR UNINITALIZED %s\n",(yyvsp[(1) - (4)].node)->var_name);
									  error_flag=1;}
									}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 141 "user.y"
    {
									temp=lookup((yyvsp[(3) - (5)].node)->var_name);	
									  if(temp!=NULL)
									  {	
										(yyvsp[(3) - (5)].node)->loc=temp;
										(yyvsp[(3) - (5)].node)->rettype=temp->type;
										(yyval.node)=assign((yyvsp[(1) - (5)].node),(yyvsp[(3) - (5)].node),NULL,NULL,0);
									  }
									 else
									 {printf("VAR UNINITALIZED %s\n",(yyvsp[(3) - (5)].node)->var_name);
									  error_flag=1;}
									}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 154 "user.y"
    {
									 temp=lookup((yyvsp[(1) - (7)].node)->var_name);	
									  if(temp!=NULL)
									  {	
										(yyvsp[(1) - (7)].node)->loc=temp;
										(yyvsp[(1) - (7)].node)->left=(yyvsp[(3) - (7)].node);
										(yyvsp[(1) - (7)].node)->rettype=temp->type;
										(yyval.node)=assign((yyvsp[(5) - (7)].node),(yyvsp[(1) - (7)].node),(yyvsp[(6) - (7)].node),NULL,0);
									  }
									 else
									 {printf("VAR UNINITALIZED %s\n",(yyvsp[(1) - (7)].node)->var_name);
									  error_flag=1;}
									}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 168 "user.y"
    {
									temp=lookup((yyvsp[(3) - (8)].node)->var_name);	
									  if(temp!=NULL)
									  {	
										(yyvsp[(3) - (8)].node)->loc=temp;
										(yyvsp[(3) - (8)].node)->left=(yyvsp[(5) - (8)].node);
										(yyvsp[(3) - (8)].node)->rettype=temp->type;
										(yyval.node)=assign((yyvsp[(1) - (8)].node),(yyvsp[(3) - (8)].node),NULL,NULL,0);
									  }
									 else
									 {printf("VAR UNINITALIZED %s\n",(yyvsp[(3) - (8)].node)->var_name);
									  error_flag=1;}
									}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 182 "user.y"
    {(yyval.node)=assign((yyvsp[(1) - (5)].node),(yyvsp[(3) - (5)].node),NULL,NULL,0);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 184 "user.y"
    {(yyval.node)=assign((yyvsp[(1) - (10)].node),(yyvsp[(3) - (10)].node),(yyvsp[(6) - (10)].node),(yyvsp[(8) - (10)].node),1);}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 186 "user.y"
    {(yyval.node)=assign((yyvsp[(1) - (8)].node),(yyvsp[(3) - (8)].node),(yyvsp[(6) - (8)].node),NULL,1);}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 188 "user.y"
    {(yyval.node)=assign((yyvsp[(1) - (8)].node),(yyvsp[(3) - (8)].node),(yyvsp[(6) - (8)].node),NULL,1);}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 192 "user.y"
    {(yyval.node)=assign((yyvsp[(2) - (3)].node),(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL,2);}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 194 "user.y"
    {(yyval.node)=assign((yyvsp[(2) - (3)].node),(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL,2);}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 196 "user.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 198 "user.y"
    {(yyval.node)=assign((yyvsp[(2) - (3)].node),(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL,2);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 200 "user.y"
    {(yyval.node)=assign((yyvsp[(2) - (3)].node),(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL,2);}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 202 "user.y"
    {(yyval.node)=assign((yyvsp[(2) - (3)].node),(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),NULL,2);}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 204 "user.y"
    {
				temp=lookup((yyvsp[(1) - (1)].node)->var_name);
				if(temp!=NULL)
				{ 
					(yyvsp[(1) - (1)].node)->loc=temp;
					(yyvsp[(1) - (1)].node)->rettype=temp->type;
					(yyval.node)=(yyvsp[(1) - (1)].node);
				}
				else
				{printf("VAR UNINITALIZED %s\n",(yyvsp[(1) - (1)].node)->var_name);
				 error_flag=1;}
				}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 217 "user.y"
    {
				temp=lookup((yyvsp[(1) - (4)].node)->var_name);
				if(temp!=NULL)
				{ 
					(yyvsp[(1) - (4)].node)->loc=temp;
					(yyvsp[(1) - (4)].node)->rettype=temp->type;
					(yyvsp[(1) - (4)].node)->left=(yyvsp[(3) - (4)].node);
					(yyval.node)=(yyvsp[(1) - (4)].node);
				}
				else
				{printf("VAR UNINITALIZED %s\n",(yyvsp[(1) - (4)].node)->var_name);
				 error_flag=1;}
				}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 231 "user.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;



/* Line 1806 of yacc.c  */
#line 1790 "y.tab.c"
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
#line 233 "user.y"


int calculate(struct tree *root)
{
 int temp_index;
 if(root)
 {
   int toret;
   if(root->d==0)
   {
     //operator
     	if(root->op=='+')
     	{
	  toret=calculate(root->left)+calculate(root->right);
     	}
     	if(root->op=='*')
     	{
	 toret=calculate(root->left)*calculate(root->right);
     	}
	if(root->op=='=')
     	{
		if(root->left->left!=NULL)
	 	{
		temp_index=calculate(root->left->left);
     		root->left->loc->binding[temp_index]=calculate(root->right);
		//printf("%d \n",root->left->loc->binding[temp_index]);
		}
		else
		{root->left->loc->binding[0]=calculate(root->right);
		//printf("%d \n",root->left->loc->binding[0]);
		}
     	}
	if(root->op=='>')
     	{
	 if(calculate(root->left)>calculate(root->right))
		return 1;
	 else
		return 0;
     	}
     	if(root->op=='<')
     	{	
	 if(calculate(root->left)<calculate(root->right))
		return 1;
	 else
		return 0;
     	}
	if(root->op=='!')
     	{
	 if(calculate(root->left)==calculate(root->right))
		return 1;
	 else
		return 0;
     	}
   }
  if(root->d==1)
   {
     //integer
     toret=root->num;
   }
  if(root->d==2)
   {
 	//variable
    

    if(root->left!=NULL)
	{
		temp_index=calculate(root->left);

		if(root->loc->binding[temp_index]==-1)
    		{
 		printf("VARIABLE '%s' NOT INITALIZED  \n",root->var_name);
		exit(0);
 		}	
		
     		toret=root->loc->binding[temp_index];	
	}
    else
     {
	if(root->loc->binding[0]==-1)
    	{
 	printf("VARIABLE '%s' NOT INITALIZED  \n",root->var_name);
	exit(0);
    	}
		toret=root->loc->binding[0];
    }
   }
  if(root->d==3)
   {
	printf("ENTER NO: \n");
	//reads
	if(root->left->left!=NULL)
	{
		temp_index=calculate(root->left->left);
     		scanf("%d",&(root->left->loc->binding[temp_index]));
	}
	else
		scanf("%d",&(root->left->loc->binding[0]));
   }		
  if(root->d==4)
   {
	//writes
	printf("%d \n",calculate(root->left));
   }
  if(root->d==5)
   {
	//ifs
	if(calculate(root->left))
		calculate(root->right);
	else if(root->further)
		calculate(root->further);
   }
  if(root->d==6)
   {
	//whiles
	while(calculate(root->left))
		calculate(root->right);
   }	
  if(root->d==7)
   {
	//a null node to group together independent statements
	calculate(root->left);
	calculate(root->right);
   }
  return toret;
 }
 else
 {
  return 0;
 }
}

struct tree* assign(struct tree *main,struct tree *l,struct tree *r,struct tree *f,int returntype)
{
 if(returntype==1)
 {
 	if(l!=NULL && l->rettype!=1)
	{printf("%d-NOT A BOOLEAN EXPR \n",yylineno);error_flag=1;}
 }
 if(returntype==2)
 {
	if(l!=NULL && l->rettype!=2)
	{printf("%d-INVALID OPERAND - BOOLEAN DETECTED \n",yylineno);error_flag=1;}
	if(r!=NULL && r->rettype!=2)
	{printf("%d-INVALID OPERAND - BOOLEAN DETECTED \n",yylineno);error_flag=1;}
 }
 struct tree *node=malloc(sizeof(struct tree));
 node=main;
 node->left=l;
 node->right=r;
 node->further=f;
 return(node);
}

struct symbol_table* lookup(char *var_name)
{
 hold=head;
 while(hold!=NULL)
 {
  if(strcmp(hold->name,var_name)==0)
	break; 
  hold=hold->next;	 
 }
 return(hold);
}

void install(int var_type,int var_size,char *var_name)
{
 int i;
 struct symbol_table *new=malloc(sizeof(struct symbol_table));
 new->name=malloc(sizeof(char)*50);
 new->type=var_type;
 //printf("%d",new->type);
 new->size=var_size;
 //printf("%d",new->size);
 strcpy(new->name,var_name);
 new->next = NULL;
 new->binding = (int*)malloc(sizeof(int)*var_size);
 for(i=0;i<var_size;i++)
	new->binding[i]=-1;
 if(head==NULL)
 {
  head=new;
  back = new;
 }
 else
 {
  back->next=new;
  back=back->next;
 }

}

void yyerror( char *s)
{
 fprintf(stderr,"%s",s);
}

int main(void)
{
 yyparse(); 
 return 0;
}

