/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
#line 47 "user.y"

 struct tree *node;		



/* Line 2068 of yacc.c  */
#line 100 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


