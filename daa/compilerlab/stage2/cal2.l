%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	void yyerror(char *s);
	
	struct treeNode{
			
			int nodeType;
			int value;
			char opr;
			struct treeNode *lc;
			struct treeNode *rc;
		};
%}


%%

[0-9]+		{yylval.val=atoi(yytext);
		return INT;
		}
		
		
[-+*/()\n]	{return (*yytext);}

[ \t]		;	/* skip whitespaces */

.		{yyerror("unknown character");}

%%




int yywrap(void)
{
	return 1;
}

		
