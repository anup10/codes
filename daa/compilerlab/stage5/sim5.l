

%{
	#include <stdlib.h>
	#include "y.tab.h"
	#include "simin.h"
	void yyerror(char *s);
	
%}


%%

[a-z]		{yylval.iValue= *yytext - 'a';
		return VAR;
		}
		
"read"		{return READ;}

"write"		{return WRITE;}

[0-9]+		{ yylval.iValue=atoi(yytext);
		return INT;
		}
		
[+*()=<>\n{}]	{
		return *yytext;
		}
		

"=="		return EQ;

"while" 	return WHILE;
"do"		return DO;
"endwhile"	return ENDWHILE;
"if" 		return IF;
"then" 		return THEN;
"endif"		return ENDIF;
"else"		return ELSE;

		
[;]		{return DELIM;}
			
[ \t]           ;/* skip whitespace */
			
.		{
		yyerror("unknown character");
		}
%%

int yywrap(void)
{
	return 1;
}
	
