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

/* Line 2068 of yacc.c  */
#line 37 "u6.y"

	int iValue; 								/* integer value */
	struct symbol_table *sym_entry; 								/* symbol table index */
	struct nodeTypeEx *nPtr; 							/* node pointer */
	


/* Line 2068 of yacc.c  */
#line 110 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


