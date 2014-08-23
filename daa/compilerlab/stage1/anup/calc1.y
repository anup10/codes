%{
	#include <stdlib.h>
	#include "y.tab.h"
	int yylex(void);
%}

%token INT

%left '+'
%left '*'

%%
	program:
		program expr '\n'	{printf ("\n");}
		|
		;
		
	expr:
		INT			{ printf ("%d",$1);}
		| expr '+' expr		{ printf ("+");}
		| expr '*' expr		{ printf ("*");}
		| '(' expr ')'
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
