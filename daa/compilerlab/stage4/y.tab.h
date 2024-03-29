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
     reads = 258,
     writes = 259,
     DELIM = 260,
     IF = 261,
     THEN = 262,
     ENDIF = 263,
     WHILE = 264,
     DO = 265,
     ENDWHILE = 266,
     EQ = 267,
     ELSE = 268,
     IFX = 269,
     INT = 270,
     VAR = 271,
     UMINUS = 272
   };
#endif
/* Tokens.  */
#define reads 258
#define writes 259
#define DELIM 260
#define IF 261
#define THEN 262
#define ENDIF 263
#define WHILE 264
#define DO 265
#define ENDWHILE 266
#define EQ 267
#define ELSE 268
#define IFX 269
#define INT 270
#define VAR 271
#define UMINUS 272




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 21 "mod41.y"

	int iValue; 								/* integer value */
	char sIndex; 								/* symbol table index */
	struct nodeTypeEx *nPtr; 							/* node pointer */
	


/* Line 2068 of yacc.c  */
#line 92 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


