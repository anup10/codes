

%{
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *s);
%}


%%

[0-9]+		{ yylval=atoi(yytext);
		return INT;
		}
		
[+*()\n]	{
		return *yytext;
		}
			
[ \t]           ;/* skip whitespace */
			
.		{
		yyerror("unknown character");
		}
%%

int yywrap(void)
{
	return 1;
}
	
