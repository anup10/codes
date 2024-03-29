%{
 #include<stdlib.h>
 #include<string.h>
 #include "y.tab.h"
 void yyerror(char *);
 
struct symbol_table
 {
  int type;
  int size;
  char *name;	//location of name
  int *binding;	//location of contents of varialbe
  struct symbol_table *next;
 };

	struct tree
	{	
		int num;
		struct symbol_table *loc;	//location in symbol table
		int d; 				//0->arith_Op,1->no:,2->var,3->read,4->write,5->if,6->while,7->void  
		int rettype;			//0->stmt,1->bool,2->var for tokens & 1->if/while 2->operators
		char op;
		struct tree *left,*right,*further;
		char *var_name;			//to hold variable name;
	}; 

 

struct tree* create(int number,int determinant,int returntype,char operator)
{
 struct tree *node=malloc(sizeof(struct tree));
 node->num=number;
 node->d=determinant;
 node->rettype=returntype;
 node->op=operator;

 node->left=NULL;
 node->right=NULL;
 node->further=NULL;
 node->loc = NULL;
 return(node);
}

%}


%%

decl		{return decls;}

enddecl		{return enddecls;}

begin		{return begins;}

end		{return ends;}

main		{return mains;}

integer		{return integer;}

boolean		{return boolean;}

do		return dos;

endwhile	return endwhiles;

then		return thens;

endif		return endifs;

else 		return elses;	

read 		{	
			yylval.node=create(0,3,0,'0');
			return reads;
		}

write	   	{	
			yylval.node=create(0,4,0,'0');
			return writes;
		}

if		{	
			yylval.node=create(0,5,0,'0');
			return ifs;
		}

while		{	
			yylval.node=create(0,6,0,'0');
			return whiles;
		}

compile		{return compile;}


[0-9]+		{
		 	yylval.node=create(atoi(yytext),1,2,'0');
			return NUM;
		}



[+*=,]		{ 	
			yylval.node=create(0,0,2,*yytext);
			return(*yytext);
		}

[<>]		{
			yylval.node=create(0,0,1,*yytext);
			return(*yytext);
		}

"=="		{
			yylval.node=create(0,0,1,'!');
			return IFEQ;	
		}

"["		{return *yytext;}

"]"		{return *yytext;}	

[a-z]([a-z]|[0-9])*		{
	  	 		yylval.node=create(0,2,2,'0');
		 		yylval.node->var_name=malloc(sizeof(char)*50);
		 		strcpy(yylval.node->var_name,yytext);
			 	//printf("%s %s",yylval.node->var_name,yytext);
		 		return VAR;
				}

[();]		return *yytext;

[ \n]		;

.		yyerror("INVALID CHARACTER");

%%

int yywrap(void)
{
 return 1;
}
