%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
%}

%token INT
%token CHAR

%left '+'
%left '*'


%%
	program:
		program expr '\n'		{printf("\n");
						}
		|
		;
		
	expr:
		INT			
		| expr '+' expr		{ printf ("+ %d %d", $1,$3);}
		| expr '*' expr  	{ printf ("* %d %d", $1,$3);}
		| '(' expr ')'		
		;
		
		
%%

void yyerror( char *s)
{
	fprintf(stderr,"%s\n",s);
}

int main(void)
{
	yyparse();
	return 0;
}
