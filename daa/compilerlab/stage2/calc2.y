%{
	#include <stdio.h>
	void yyerror(char *s);
	int yylex(void);
%}


%token INT
%left '+' '-'
%left '*' '/'

%%

program:
	program expr '\n'	{printf("%d \n",$2);}
	|
	;


expr:
	INT			
	|expr '+' expr		{$$=$1+$3;}
	|expr '-' expr		{$$=$1-$3;}
	|expr '*' expr		{$$=$1*$3;}
	|expr '/' expr		{$$=$1/$3;}
	|'(' expr ')'		{$$=$2;}
	;

%%

void yyerror(char *s)
{
	fprintf(stderr,"%s",s);
}

int main(void)
{
	yyparse();
	return 0;
}	
