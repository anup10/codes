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
	struct nodeTypeEx*id(struct symbol_table *entry,struct nodeTypeEx *ind);
	struct nodeTypeEx*con(int value);
	void install(struct symbol_table *entry);
	void install_a(struct symbol_table *entry,int size1);
	
	int ex(struct nodeTypeEx*p);
	int yylex(void);
	void yyerror(char *s);
	
	struct symbol_table *head;
	struct symbol_table *tail;
	struct symbol_table *temp=NULL;
	struct symbol_table *lookup(char *name1);
	
	int g_index;

	
								
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
		declaration main_function COMPILE				{ex($2);exit(0);}
		|main_function 	COMPILE						{ex($1);exit(0);}
		;
		
	main_function:
		INTEGER MAIN '(' ')' '\n' '{' '\n' function '}' '\n'		{$$=$8;}//freeNode($2);}
		|INTEGER MAIN '(' ')' '{' '\n' function '}' '\n'		{$$=$7;}
		;
		
	function:
		BEGINS '\n' slist END '\n'					{$$=$3;}
		;
		
	declaration:
		DECL '\n' decl_list ENDDECL '\n'
		;
	
	decl_list:
		 decl_list type vars 
		|type vars 
		;
		
	vars:
		VAR ',' vars					{install($1);}
								
		|VAR '[' INT ']' ',' vars			{install_a($1,$3);}
		
		|VAR DELIM '\n'					{install($1);}
		
		|VAR '[' INT ']' DELIM	'\n'			{install_a($1,$3);}
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
									printf("variable %s not declared\n",$1->name);
									else
									$$=opr('=',2,id($1,con(0)),$3);}
									
		|VAR '[' INT ']' '=' expr DELIM '\n'			{temp=lookup($1->name);
									if(!temp)
									printf("variable %s not declared\n",$1->name);
									else
									$$=opr('=',2,id($1,con($3)),$6);}
									
		|READ '(' VAR ')' DELIM	'\n'				{temp=lookup($3->name);
									if(!temp)
									printf("variable %s not declared\n",$3->name);
									else
									$$=opr(READ,1,id($3,con(0)));}
									
		|READ '(' VAR '[' INT ']' ')' DELIM '\n'		{temp=lookup($3->name);
									if(!temp)
									printf("varialbe %s not declared\n",$3->name);
									else
									$$=opr(READ,1,id($3,con($5)));}
									
		|READ '(' VAR '[' VAR ']' ')' DELIM '\n'		{temp=lookup($5->name);
									if(!temp)
									printf("varialbe %s not declared\n",$5->name);
									else
									{
									temp=lookup($3->name);
									if(!temp)
									printf("varialbe %s not declared\n",$3->name);
									else
									$$=opr(READ,1,id($3,id($5,con(0))));
									}}
									
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
							printf("variable %s not declared\n",$1->name);
							else
							$$=id($1,con(0));}
							
		|VAR '[' INT ']' 			{temp=lookup($1->name);
							if(!temp)
							printf("variable %s not declared\n",$1->name);
							else
							$$=id($1,con($3));}
							
		|VAR '[' VAR ']'			{temp=lookup($3->name);
							if(!temp)
							printf("variable %s not declared\n",$3->name);
							else
							{
							temp=lookup($1->name);
							if(!temp)
							printf("varialbe %s not declared\n",$1->name);
							else
							$$=id($1,id($3,con(0)));}
							}
							
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





struct nodeTypeEx *id(struct symbol_table *index,struct nodeTypeEx *ind)
{
	struct nodeTypeEx *p;
	p=malloc(sizeof(struct nodeTypeEx));
	
	if(p==NULL)
	yyerror("out of memory");
	
	else
	{
		temp=lookup(index->name);
		p->type=idType;
		p->id.entry=temp;
		p->id.indx=ind;
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
	temp=lookup(entry->name);
	temp->size=1;
	
	temp->binding=malloc(sizeof(int)*temp->size);
	
	
	
	}
		
void install_a(struct symbol_table *entry,int size1){
	temp=lookup(entry->name);
	temp->size=size1;
	
	temp->binding=malloc(sizeof(int)*entry->size);
	
	
	}
	
	
struct symbol_table *lookup(char *name1){
	struct symbol_table *temp1;
	temp1=head;
	while((strcmp(temp1->name,name1)) && temp1!=NULL)
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
		case conType:				{return (p->con.value);}
			
		case idType:				{temp=lookup(p->id.entry->name);
							if(temp->binding==NULL)
							printf("unassinged variable \n");
							else
							{return (*((temp->binding)+ex(p->id.indx)));}}
		
		case oprType:
		{
			switch(p->opr.oper)
			{
				case ';':		{ex(p->opr.pr[0]);return(ex(p->opr.pr[1]));}
				
				case '=':		{temp=lookup(p->opr.pr[0]->id.entry->name);
							*((temp->binding)+(ex(p->opr.pr[0]->id.indx)))=ex(p->opr.pr[1]);
							
							return 0;}
				
				
						
				case READ:		{
							temp=lookup(p->opr.pr[0]->id.entry->name);
							scanf("%d",((temp->binding)+(ex(p->opr.pr[0]->id.indx))));
							return 0;}
							
				
				
				case WRITE:		{
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
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
