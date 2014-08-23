

%{
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *s);
%}


%%

[a-z]		{yylval= *yytext - 'a';
		return VAR;
		}
		
reads		{return reads;}

writes		{return writes;}

[0-9]+		{ yylval=atoi(yytext);
		return INT;
		}
		
[+*()=;]	{
		return *yytext;
		}
		
[\n]		{return END;}
			
[ \t]           ;/* skip whitespace */
			
.		{
		yyerror("unknown character");
		}
%%

int yywrap(void)
{
	return 1;
}
	