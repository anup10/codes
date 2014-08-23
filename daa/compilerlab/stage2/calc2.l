%{
	#include "y.tab.h"
	#include <stdlib.h>
	void yyerror(char *s);
%}


%%

[0-9]+		{yylval=atoi(yytext);
		 return (INT);
		 }
		 
[-+*/()\n]	{return (*yytext);
		}

[ \t]		;/*skip whitespaces*/

.		{yyerror("unknown character");
		}
		
%%



int yywrap(void)
{
	return 1;
}

			



