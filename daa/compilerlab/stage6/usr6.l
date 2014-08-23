

%{
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	#include "usrin.h"
	void yyerror(char *s);
	int type=-1;				//0-boolean,1-int
	
	struct symbol_table *head=NULL;
	struct symbol_table *tail=NULL;
	
	struct symbol_table *Ginstall(char *name1,int type1)
	{
		struct symbol_table *node=malloc(sizeof(struct symbol_table));
		node->name=malloc(sizeof(char)*50);
		
		if(head==NULL)
		{
			
			strcpy(node->name,name1);
			//node->name=name1;
			
			node->type=type1;
			head=tail=node;
			node->next=NULL;
		}
		else
		{
			strcpy(node->name,name1);
			node->type=type1;
			tail->next=node;
			tail=node;
			node->next=NULL;
		}
		return (node);
	}	
%}


%%



"integer"		{
			type=1;
			return INTEGER;
		}
		
"boolean"	{
			type=0;
			return BOOLEAN;
		}
		
"read"		{return READ;}

"write"		{return WRITE;}
		
"decl"		return DECL;

"enddecl"		return ENDDECL;

"begin"		return BEGINS;

"end"		return END;

"main"		return MAIN;

"while" 	return WHILE;

"do"		return DO;

"endwhile"	return ENDWHILE;

"if" 		return IF;

"then" 		return THEN;

"endif"		return ENDIF;

"else"		return ELSE;

"compile"	return COMPILE;

[a-z]+([0-9]|[a-z])*		{
				yylval.sym_entry= Ginstall(yytext,type);
				return VAR;
				}
		


[0-9]+		{ 
		yylval.iValue=atoi(yytext);
		return INT;
		}
		
[,+*()=<>\n{}]	{
		return *yytext;
		}
		
"["		return *yytext;

"]"		return *yytext;
		

"=="		return EQ;
		
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
	
