%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include "simin.h"
	/* prototypes */
	
									/* symbol table */
	FILE *fp;
	//fp=fopen("out.txt","w");
	int reg_count=-1,label_count=-1;
	int sym[26];
	
	struct nodeTypeEx*opr(int oper, int nops, ...);	
	struct nodeTypeEx*id(int i);
	struct nodeTypeEx*con(int value);
	
	int ex(struct nodeTypeEx*p);
	int yylex(void);
	void yyerror(char *s);
	
								
%}


%union {
	int iValue; 								/* integer value */
	char sIndex; 								/* symbol table index */
	struct nodeTypeEx *nPtr; 							/* node pointer */
	};

%token READ WRITE DELIM IF THEN ENDIF WHILE DO ENDWHILE ELSE EQ IFX


%token <iValue> INT VAR

%type  <nPtr> slist stmnt expr
%left  EQ '>' '<'
%right '='
%left '+'
%left '*'
%nonassoc UMINUS





%%

	

	program:
		program slist '\n'				{fprintf(fp,"START\n");
								ex($2);
								fprintf(fp,"HALT\n");fclose(fp);
								exit(0);}//freeNode($2);}
		|
		;

	slist:
		 slist stmnt 					{$$=opr(';',2,$1,$2);}
		|stmnt						{$$=$1;}
		;


	stmnt:
		DELIM						{$$=opr(';',2,NULL,NULL);}
		|VAR '=' expr DELIM				{$$=opr('=',2,id($1),$3);}
		|READ '(' VAR ')' DELIM				{$$=opr(READ,1,id($3));}
		|WRITE '(' expr ')' DELIM 			{$$=opr(WRITE,1,$3);}
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

int label()
{
	return(++label_count);
}


	
	
void getreg()
{
	if(reg_count<7)
	reg_count++;
	else
	{
	printf("REGISTER MEMORY FULL-ABORT\n");
	exit(0);
	}
}

void freereg()
{
	reg_count--;
}

int consta(struct nodeTypeEx *p)
{
	getreg();
	fprintf(fp,"MOV R%d, %d\n",reg_count,p->con.value);
	freereg();
	return (p->con.value);
}

int var(struct nodeTypeEx *p)
{
	
	
	int k;
	char c=(p->id.i+97);
	k= sym[p->id.i];
	if(k==-100)
	{
		printf("varible %c not initialised\n",c);
		exit(0);
	}
	else
	{
		getreg();
		fprintf(fp,"MOV R%d, [%d]\n",reg_count,p->id.i);
		freereg();
	}
	
	return 0;
}

int ip(struct nodeTypeEx *p)
{
	getreg();
	fprintf(fp,"IN R%d\n",reg_count);
	fprintf(fp,"MOV [%d], R%d\n",p->opr.pr[0]->id.i,reg_count);
	freereg();
	return 0;
}
	
	

int add(struct nodeTypeEx *p)
{
	int c;
	
	if(p->opr.pr[0]->type==conType)
	{
		
		getreg();						//register to keep constant value
		fprintf(fp,"MOV R%d, %d\n",reg_count,p->opr.pr[0]->con.value);
		c=ex(p->opr.pr[1]);
		freereg();
	}
	else if(p->opr.pr[0]->type==idType)
	{
		
		getreg();						//register to keep varible value
		
		fprintf(fp,"MOV R%d, [%d]\n",reg_count,p->opr.pr[0]->id.i);
		
		c=ex(p->opr.pr[1]);
		
		freereg();
	}
	else
	{
		
		ex(p->opr.pr[0]);
		getreg();						//register to keep exp at [0] value
		ex(p->opr.pr[1]);
		freereg();
	}
	fprintf(fp,"ADD R%d, R%d\n",reg_count+1,reg_count+2);
	return 0;
}

int mul(struct nodeTypeEx *p)
{
	int c;
	if(p->opr.pr[0]->type==conType)
	{
		getreg();						//register to keep constant value
		fprintf(fp,"MOV R%d, %d\n",reg_count,p->opr.pr[0]->con.value);
		c=ex(p->opr.pr[1]);
		freereg();
	}
	else if(p->opr.pr[0]->type==idType)
	{
		getreg();						//register to keep varinle value
		fprintf(fp,"MOV R%d, [%d]\n",reg_count,p->opr.pr[0]->id.i);
		c=ex(p->opr.pr[1]);
		freereg();
	}
	else
	{
		
		c=ex(p->opr.pr[0]);
		getreg();						//register to keep value at exp[0]
		c=ex(p->opr.pr[1]);
		freereg();
	}
	fprintf(fp,"MUL R%d, R%d\n",reg_count+1,reg_count+2);
	return 0;
}

int lt(struct nodeTypeEx *p)
{
	if(p->opr.pr[0]->type==conType)
	{
		getreg();						//register to keep constant value
		fprintf(fp,"MOV R%d, %d\n",reg_count,p->opr.pr[0]->con.value);
		ex(p->opr.pr[1]);
		freereg();
	}
	else if(p->opr.pr[0]->type==idType)
	{
		getreg();						//register to keep varinle value
		fprintf(fp,"MOV R%d, [%d]\n",reg_count,p->opr.pr[0]->id.i);
		ex(p->opr.pr[1]);
		freereg();
	}
	else
	{
		ex(p->opr.pr[0]);
		getreg();						//register to keep value at exp[0]
		ex(p->opr.pr[1]);
		freereg();
	}
	fprintf(fp,"LT R%d, R%d\n",reg_count+1,reg_count+2);
	return 0;
}
	

int gt(struct nodeTypeEx *p)
{
	if(p->opr.pr[0]->type==conType)
	{
		getreg();							//register to keep constant value
		fprintf(fp,"MOV R%d, %d\n",reg_count,p->opr.pr[0]->con.value);
		ex(p->opr.pr[1]);
		freereg();
	}
	else if(p->opr.pr[0]->type==idType)
	{
		getreg();							//register to keep varinle value
		fprintf(fp,"MOV R%d, [%d]\n",reg_count,p->opr.pr[0]->id.i);
		ex(p->opr.pr[1]);
		freereg();
	}
	else
	{
		ex(p->opr.pr[0]);
		getreg();							//register to keep value at exp[0]
		ex(p->opr.pr[1]);
		freereg();
	}
	fprintf(fp,"GT R%d, R%d\n",reg_count+1,reg_count+2);
	return 0;
}

int eq1(struct nodeTypeEx *p)
{
	sym[p->opr.pr[0]->id.i]=ex(p->opr.pr[1]);
	fprintf(fp,"MOV [%d], R%d\n",p->opr.pr[0]->id.i,reg_count+1);
	return 0;
}	

int eq(struct nodeTypeEx *p)
{
	if(p->opr.pr[0]->type==conType)
	{
		getreg();							//register to keep constant value
		fprintf(fp,"MOV R%d, %d\n",reg_count,p->opr.pr[0]->con.value);
		ex(p->opr.pr[1]);
		freereg();
	}
	else if(p->opr.pr[0]->type==idType)
	{
		getreg();							//register to keep varinle value
		fprintf(fp,"MOV R%d, [%d]\n",reg_count,p->opr.pr[0]->id.i);
		ex(p->opr.pr[1]);
		freereg();
	}
	else
	{
		ex(p->opr.pr[0]);
		getreg();							//register to keep value at exp[0]
		ex(p->opr.pr[1]);
		freereg();
	}
	fprintf(fp,"EQ R%d, R%d\n",reg_count+1,reg_count+2);
	return 0;
}


int if1(struct nodeTypeEx *p)
{
	int l1=label();
	ex(p->opr.pr[0]);
	
	//if condition is false
	fprintf(fp,"JZ R%d, L%d\n",reg_count+1,l1);
	
	ex(p->opr.pr[1]);
	
	//else statements
	fprintf(fp,"L%d :\n",l1);
	return 0;
}

int if2(struct nodeTypeEx *p)
{
	int l1=label();
	//evaluate th condition
	ex(p->opr.pr[0]);
	fprintf(fp,"JZ R%d, L%d\n",reg_count+1,l1);			//if it is false jump to taken label
	
	//exe if condi true
	ex(p->opr.pr[1]);
	
	//for not executing else part
	int l2=label();
	fprintf(fp,"JMP L%d\n",l2);
	
	
	//label for else
	fprintf(fp,"L%d :\n",l1);
	ex(p->opr.pr[2]);
	
	
	//label fr statements aftr else
	
	fprintf(fp,"L%d :\n",l2);
	
	
	return 0;
}	
	 

int while1(struct nodeTypeEx *p)
{
	int l1=label();
	
	//label for statements exe whn condi true
	fprintf(fp,"L%d :\n",l1);
	ex(p->opr.pr[0]);
	int l2=label();
	fprintf(fp,"JZ R%d, L%d\n",reg_count+1,l2);
	ex(p->opr.pr[1]);
	
	
	//unconditional jump to the testing condition
	fprintf(fp,"JMP L%d\n",l1);
	
	//label for statements after while loop
	
	fprintf(fp,"L%d :\n",l2);
	
	
	return 0;
}





int ex(struct nodeTypeEx *p)
{
	if(!p) return 0;
	
	switch(p->type)
	{
		case conType:				{return (consta(p));}
			
		case idType:				{return (var(p));}
		
		case oprType:
		{
			switch(p->opr.oper)
			{
				case ';':		{ex(p->opr.pr[0]);return(ex(p->opr.pr[1]));}
				
				case '=':		{return eq1(p);}
				
				case READ:		{return (ip(p));}
				
				case WRITE:		{ex(p->opr.pr[0]);fprintf(fp,"OUT R0\n");return 0;}
				
				case IF:		{return (if1(p));}
							
				case IFX:		{return (if2(p));}
								
				case WHILE:		{return (while1(p));}
								
				case '+':		{return(add(p));}
				
				case '*':		{return(mul(p));}
				
				case '<':		{return(lt(p));}
				
				case '>':		{return(gt(p));}
				
				case EQ:		{return(eq(p));}
					
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
	int i;
	for( i=0;i<26;i++)
	sym[i]=-100;
	fp=fopen("out.txt","w"); 
	yyparse();
	return 0;
}		
		

















		
		
		
		
		
		
