%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	int yylex(void);
	void yyerror(char *s);
	int sym[26];
	
%}



%token INT VAR reads writes END ;  

%right '='
%left '+'
%left '*'

%%
	
	slist:
		slist stmnt END			{exit(0);}
		|slist stmnt 			
		|
		;
		
	stmnt:
		VAR '=' expr ';'		{sym[$1]=$3;}
		|reads '(' VAR ')' ';'		{scanf("%d",&sym[$3]);}
		|writes '(' expr ')' ';' 	{printf("%d\n",$3);}
		|expr ';'
		;	
		
	expr:
		INT 			{$$=$1;}
		|VAR			{$$=sym[$1];}
		|expr '+' expr		{$$=$1+$3;}
		|expr '*' expr		{$$=$1*$3;}
		|'(' expr ')'		{$$=$2;}
		;
		
%%

void yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);
}

int main(void)
{
	yyparse();
	return 0;
}
