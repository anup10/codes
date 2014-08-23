%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include "usrin.h"
	/* prototypes */
	
									/* symbol table */
	FILE *fp;
	//fp=fopen("out.txt","w");
	int reg_count=-1,label_count=-1;
	int sym[26];
	
	struct nodeTypeEx*opr(int oper, int nops, ...);	
	struct nodeTypeEx*id(int i);
	struct nodeTypeEx*con(int value);
	void install(struct symbol_table *entry);
	void install_a(struct symbol_table *entry,int size1);
	
	int ex(struct nodeTypeEx*p);
	int yylex(void);
	void yyerror(char *s);
	
	extern struct symbol_table *head;
	extern struct symbol_table *tail;
	struct symbol_table *temp=NULL;
	struct symbol_table *lookup(char *name1);
	
	

	
								
%}


%union {
	int iValue; 								/* integer value */
	struct symbol_table *sym_entry; 								/* symbol table index */
	struct nodeTypeEx *nPtr; 							/* node pointer */
	};
	
	
%token READ WRITE DELIM EQ IF THEN ELSE IFX ENDIF WHILE DO ENDWHILE DECL BOOLEAN INTEGER ENDDECL MAIN BEGINS END COMPILE ASSNG

%token <iValue> INT

%token <sym_entry> VAR

%type  <nPtr> slist stmnt expr function main_function
%left  EQ '>' '<'
%right '='
%left '+'
%left '*'
%nonassoc UMINUS
	
	
	
%%

	

	program:
		declaration main_function COMPILE		
		|main_function 	COMPILE				
		;
		
	main_function:
		INTEGER MAIN '(' ')' '{' function '}'		{
								ex($6);
								exit(0);
								}//freeNode($2);}
		;
		
	function:
		BEGINS slist END					{$$=$2;}
		;
		
	declaration:
		DECL decl_list ENDDECL
		;
	
	decl_list:
		 decl_list type vars 
		|type vars 
		;
		
	vars:
		VAR ',' vars					{install($1);}
								
		|VAR '[' INT ']' ',' vars			{install_a($1,$3);}
		
		|VAR DELIM					{install($1);}
		
		|VAR '[' INT ']' DELIM				{install_a($1,$3);}
		;
	
	type:
		INTEGER
		|BOOLEAN
		;

	slist:
		 slist stmnt 					{$$=opr(';',2,$1,$2);}
		|stmnt						{$$=$1;}
		;


	stmnt:
		DELIM '\n'						{$$=opr(';',2,NULL,NULL);}
		|VAR '=' expr DELIM '\n'				{temp=lookup($1->name);
									if(!temp)
									$$=opr('=',2,id(temp,0),$3);
									else
									printf("variable not declared\n");}
		|VAR '[' INT ']' '=' expr DELIM '\n'			{temp=lookup($1->name);
									if(!temp)
									$$=opr('=',2,id(temp,$3),$6);
									else
									printf("variable not declared\n");}
		|READ '(' VAR ')' DELIM	'\n'				{temp=lookup($3->name);
									if(!temp)
									$$=opr(READ,1,id(temp,0));
									else
									printf("variable not declared\n");}
		|READ '(' VAR '[' INT ']' ')' DELIM '\n'		{temp=lookup($3->name);
									if(!temp)
									$$=opr(READ,1,id(temp,$5));
									else
									printf("varialbe not declared\n");}
		|WRITE '(' expr ')' DELIM '\n'				{$$=opr(WRITE,1,$3);}
		|IF '(' expr ')' THEN slist ENDIF DELIM '\n'		{$$=opr(IF,2,$3,$6);}
		|IF '(' expr ')' THEN slist ELSE slist ENDIF DELIM '\n'	{$$=opr(IFX,3,$3,$6,$8);}
		|WHILE '(' expr ')' DO slist ENDWHILE DELIM '\n'	{$$=opr(WHILE,2,$3,$6);}
		|expr DELIM '\n'					{$$=$1;}
		;	


	expr:
		INT 					{$$=con($1);}
		|VAR					{temp=lookup($1->name);
							if(!temp)
							$$=id(temp,0);
							else
							printf("variable not declared\n");}
		|VAR '[' INT ']' 			{temp=lookup($1->name);
							if(!temp)
							$$=id(temp,$3);
							else
							printf("variable not declared\n");}
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





struct nodeTypeEx *id1(struct symbol_table *index,int ind)
{
	struct nodeTypeEx *p;
	
	if((p=malloc(sizeof(struct nodeTypeEx)))==NULL)
	yyerror("out of memory");
	
	else
	{
		p->type=idType;
		p->id.entry=index;
		p->id.it=ind;
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
		{
			p->opr.pr[i]=va_arg(ap,struct nodeTypeEx*);
			
		}
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


void install(struct symbol_table *entry){
	entry->size=1;
	
	entry->binding=malloc(sizeof((sizeof(int))*(entry->size)));
	}
		
void install_a(struct symbol_table *entry,int size1){
	entry->size=size1;
	
	entry->binding=malloc(sizeof((sizeof(int))*(entry->size)));
	}
	
	
struct symbol_table *lookup(char *name1){
	struct symbol_table *temp1;
	temp1=head;
	while((!strcmp(temp1->name,name1)) && temp1!=NULL)
	{
		temp1=temp1->next;
	}
	if(temp1!=NULL)
	return temp1;
	else
	return NULL;
	}	






int ex(struct nodeTypeEx *p)
{
	if(!p) return 0;
	
	switch(p->type)
	{
		case conType:				{return p->con.value;}
			
		case idType:				{if(p->id.entry->binding==NULL)
							printf("unassinged variable \n");
							else
							return *(p->id.entry->*(binding+p->id.it));}
		
		case oprType:
		{
			switch(p->opr.oper)
			{
				case ';':		{ex(p->opr.pr[0]);return(ex(p->opr.pr[1]));}
				
				case '=':		{return (p->opr.pr[0]->id.entry->*(binding+p->opr.pr[0]->id.it)=ex(p->opr.pr[1]));}
				
				
						
				case READ:		{
							scanf("%d",p->opr.pr[0]->id.entry->*(binding+p->opr.pr[0]->id.it));
							return 0;}
							
				
				
				case WRITE:		{if(p->opr.pr[0]->type==idType)
							printf("%d\n",ex(p->opr.pr[0]->id.entry->*(binding+p->opr.pr[0]->id.it)));
							else
							printf("%d\n",ex(p->opr.pr[0]));
							return 0;}
				
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








void yyerror (char *s)
{
	fprintf(stderr,"%s\n",s);
	
}

int main (void)
{
	int i;
	for( i=0;i<26;i++)
	sym[i]=-100;
	
	yyparse();
	return 0;
}		
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
