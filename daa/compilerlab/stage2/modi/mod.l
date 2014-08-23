%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.h"
	void yerror(char *);

	struct tree
	{	
		float num;
		int d;
		char op;
		struct tree *left,*right;
	};

%}

%%


[0-9]("."[0-9]+)?		{
			yylval.node=malloc(sizeof(struct tree));
			yylval.node->num=atof(yytext);
			yylval.node->d=1;
			yylval.node->left=NULL;
			yylval.node->right=NULL;
			return NUM;
			}

[+*]		{
			yylval.node=malloc(sizeof(struct tree));
			yylval.node->op=*yytext;
			yylval.node->d=0;
			yylval.node->left=NULL;
			yylval.node->right=NULL;
			return(*yytext);	
		}

[\n()]		{
			return *yytext;
		}

[ \t]		;

. 		yyerror("Invalid character");

%%

int yywrap(void)
{
 return 1;
}
