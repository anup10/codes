%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include "include1.h"
	/* prototypes */
	struct nodeTypeEx*opr(int oper, int nops, ...);	
	struct nodeTypeEx*id(int i);
	struct nodeTypeEx*con(int value);
	
	int ex(struct nodeTypeEx*p);
	int yylex(void);
	void yyerror(char *s);
	int sym[26];
	int i;
								/* symbol table */
%}


%union {
	int iValue; 								/* integer value */
	char sIndex; 								/* symbol table index */
	struct nodeTypeEx *nPtr; 							/* node pointer */
	};

%token reads writes DELIM IF THEN ENDIF WHILE DO ENDWHILE EQ ELSE IFX


%token <iValue> INT VAR

%type  <nPtr> slist stmnt expr
%left  EQ '>' '<'
%right '='
%left '+'
%left '*'
%nonassoc UMINUS





%%

	

	program:
		program slist '\n'					{ex($2);exit(0);}//freeNode($2);}
		|
		;

	slist:
		 slist stmnt 					{$$=opr(';',2,$1,$2);}
		|stmnt						{$$=$1;}
		;


	stmnt:
		DELIM						{$$=opr(';',2,NULL,NULL);}
		|VAR '=' expr DELIM				{$$=opr('=',2,id($1),$3);}
		|reads '(' VAR ')' DELIM			{$$=opr(reads,1,id($3));}
		|writes '(' expr ')' DELIM 			{$$=opr(writes,1,$3);}
		|IF '(' expr ')' THEN slist ENDIF DELIM		{$$=opr(IF,2,$3,$6);}
		|IF '(' expr ')' THEN slist ELSE slist ENDIF DELIM	{$$=opr(IFX,3,$3,$6,$8);}
		|WHILE '(' expr ')' DO slist ENDWHILE DELIM	{$$=opr(WHILE,2,$3,$6);}
		|expr DELIM					{$$=$1;}
		;	


	expr:
		INT 					{$$=con($1);}
		|VAR					{$$=id($1);}
		|expr '+' expr				{$$=opr('+',2,$1,$3);}
		|expr '*' expr				{$$=opr('*',2,$1,$3);}
		|'(' expr ')'				{$$=$2;}
		|expr '<' expr				{$$=opr('<',2,$1,$3);}
		|expr '>' expr				{$$=opr('>',2,$1,$3);}
		|expr EQ expr				{$$=opr(EQ,2,$1,$3);}
		;
		
		
		
%%


struct nodeTypeEx *con(int val)
{
	struct nodeTypeEx *p;
	
	if((p=malloc(sizeof(struct nodeTypeEx)))==NULL)
	yyerror("out of memory");
	
	else
	{
		p->type = conType;
		p->con.value = val;
		return p;
	}
}



struct nodeTypeEx *id(int index)
{
	struct nodeTypeEx *p;
	
	if((p=malloc(sizeof(struct nodeTypeEx)))==NULL)
	yyerror("out of memory");
	
	else
	{
		p->type=idType;
		p->id.i=index;
		return p;
	}
}



struct nodeTypeEx *opr(int oper,int nops, ...)
{
	va_list ap;
	struct nodeTypeEx *p;
	int i;
	
	if((p=malloc(sizeof(struct nodeTypeEx)))==NULL)
	yyerror("out of memory");
	
	if((p->opr.pr=malloc(nops*sizeof(struct nodeTypeEx)))==NULL)
	yyerror("out of memory");

	else
	{
		p->type=oprType;
		p->opr.oper=oper;
		p->opr.nops=nops;
		va_start(ap,nops);
		for(i=0;i<nops;i++)
			p->opr.pr[i]=va_arg(ap,struct nodeTypeEx*);
		va_end(ap);
		return p;
	}
}



void freeNode(struct nodeTypeEx *p) 
{
	int i;
	if (!p) return;
	if (p->type == oprType)
	{
		for (i = 0; i < p->opr.nops; i++)
			freeNode(p->opr.pr[i]);
		free(p->opr.pr);
	}
	free (p);
}

int ex(struct nodeTypeEx *p)
{
	if(!p) return 0;
	
	switch(p->type)
	{
		case conType:				{return p->con.value;}
			
		case idType:				{int k;char c=(p->id.i+97);k= sym[p->id.i];if(k==-100){printf("varible %c not initialised\n",c);exit(0);}else{return (sym[p->id.i]);}}
		
		case oprType:
		{
			switch(p->opr.oper)
			{
				case ';':		{ex(p->opr.pr[0]);return(ex(p->opr.pr[1]));}
				
				case '=':		{return (sym[p->opr.pr[0]->id.i]=ex(p->opr.pr[1]));}
				
				case reads:		{scanf("%d",&sym[p->opr.pr[0]->id.i]);return 0;}
				
				case writes:		{printf("%d\n",ex(p->opr.pr[0]));return 0;}
				
				case IF:		{if(ex(p->opr.pr[0]))
								ex(p->opr.pr[1]);
							return 0;}
							
				case IFX:		{if(ex(p->opr.pr[0]))
								ex(p->opr.pr[1]);
							else
								ex(p->opr.pr[2]);
							return 0;
							}
								
				case WHILE:		{while(ex(p->opr.pr[0]))
								ex(p->opr.pr[1]);
							return 0;}
								
				case '+':		{return (ex(p->opr.pr[0])+ex(p->opr.pr[1]));}
				
				case '*':		{return (ex(p->opr.pr[0])*ex(p->opr.pr[1]));}
				
				case '<':		{return (ex(p->opr.pr[0])<ex(p->opr.pr[1]));}
				
				case '>':		{return (ex(p->opr.pr[0])>ex(p->opr.pr[1]));}
				
				case EQ:		{return (ex(p->opr.pr[0])==ex(p->opr.pr[1]));}
					
			}
		}
	}
	
	return 0;
}








void yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);
	
}

int main(void)
{
	for( i=0;i<26;i++)
	sym[i]=-100; 
	yyparse();
	return 0;
}		
		

















		
		
		
		
		
		
