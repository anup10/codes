%{
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 int yylex(void);
 void yyerror(char *);
 int i;
 int var_type; //a global variable to keep track of type
 int error_flag=0;
 int yylineno;

 struct symbol_table
 {
  int type;
  int size;
  char *name;
  int *binding;
  struct symbol_table *next;
 };

 struct tree
	{	
		int num;
		struct symbol_table *loc;
		int d; 		//0->arithmetic,1->number,2->variable,3->read,4->write,5->if,6->while,7->void  
		int rettype;	//0->void stmt,1->bool expr/var,2->integer expr/var
		char op;
		struct tree *left,*right,*further;
		char *var_name;
	}; 
 
 struct symbol_table *head=NULL;
 struct symbol_table *hold,*back;		//for the linked list
 struct symbol_table *temp;			//for installation and lookup functions
					

 int calculate(struct tree *);
 struct tree* assign(struct tree *main,struct tree *left,struct tree *right,struct tree *further,int rettype);

 struct symbol_table* lookup(char *var_name);
 void install(int var_type,int var_size,char *var_name);

%}

%union
{
 struct tree *node;		
}

%token <node> VAR NUM reads writes ifs whiles '+' '*' '=' IFEQ '>' '<'
%token thens endifs dos endwhiles compile elses begins ends integer boolean decls enddecls mains

%type <node> E Stmt Slist main_function function

%right '='
%left '>' '<' IFEQ
%left '+'
%left '*'


%%

 program :
	 declaration main_function compile		
	| main_function compile				
	;

main_function:	
		mains '(' ')' function			{
						 	if(error_flag==0)
								{calculate($4);exit(0);}
							else
								{printf("Errors In Program \n ABORT \n");
								 exit(0);}
							}
		;
function:	
		begins Slist ends			{$$=$2;}
		;
declaration :
		decls decl_list enddecls
		;
decl_list:
		decl_list type var_list ';'
		|type var_list ';'
		;
type:
		integer					{var_type=2;}
		|boolean				{var_type=1;}
		;

var_list: 	var_list ',' var_complex 
		| var_complex 
		;

var_complex:	VAR					{
							temp=lookup($1->var_name);
							//printf("%s",$1->var_name);
							if(temp==NULL)
								{
								 install(var_type,1,$1->var_name);
								 $1->rettype=var_type;}
							}

		| VAR '[' NUM ']'			{
							temp=lookup($1->var_name);
							if(temp==NULL)
								{install(var_type,$3->num,$1->var_name);
								 $1->rettype=var_type;}
		;					}
 Slist	:
	Slist Stmt				{
						 struct tree *stub = malloc(sizeof(struct tree));
						 stub->d = 7;
						 stub->left=$1;
						 stub->right=$2;
						 stub->rettype=0;
						 $$ = stub;
						}

	|Stmt					{
						$$=$1;
						}
	;

 Stmt 	:
	 VAR '=' E ';'  						{
									  temp=lookup($1->var_name);	
									  if(temp!=NULL)
									  {	
										$1->loc=temp;
										$1->rettype=temp->type;
										$$=assign($2,$1,$3,NULL,0);
									  }
									 else
									 {printf("VAR UNINITALIZED %s\n",$1->var_name);
									  error_flag=1;}
									}

	| reads '(' VAR ')' ';'  					{
									temp=lookup($3->var_name);	
									  if(temp!=NULL)
									  {	
										$3->loc=temp;
										$3->rettype=temp->type;
										$$=assign($1,$3,NULL,NULL,0);
									  }
									 else
									 {printf("VAR UNINITALIZED %s\n",$3->var_name);
									  error_flag=1;}
									}

	| VAR '[' E ']' '=' E ';'					{
									 temp=lookup($1->var_name);	
									  if(temp!=NULL)
									  {	
										$1->loc=temp;
										$1->left=$3;
										$1->rettype=temp->type;
										$$=assign($5,$1,$6,NULL,0);
									  }
									 else
									 {printf("VAR UNINITALIZED %s\n",$1->var_name);
									  error_flag=1;}
									}

	| reads '(' VAR '[' E ']' ')' ';'				{
									temp=lookup($3->var_name);	
									  if(temp!=NULL)
									  {	
										$3->loc=temp;
										$3->left=$5;
										$3->rettype=temp->type;
										$$=assign($1,$3,NULL,NULL,0);
									  }
									 else
									 {printf("VAR UNINITALIZED %s\n",$3->var_name);
									  error_flag=1;}
									}

	| writes '(' E ')' ';'						{$$=assign($1,$3,NULL,NULL,0);}
									
	| ifs '(' E ')' thens Slist elses Slist endifs ';'		{$$=assign($1,$3,$6,$8,1);}
									
	| ifs '(' E ')' thens Slist endifs ';'				{$$=assign($1,$3,$6,NULL,1);}
									
	| whiles '(' E ')' dos Slist endwhiles ';'			{$$=assign($1,$3,$6,NULL,1);}
	;

 E	:
	  E '+' E 		{$$=assign($2,$1,$3,NULL,2);}

	| E '*' E		{$$=assign($2,$1,$3,NULL,2);}

	| '(' E ')'		{$$=$2;}

	|  E IFEQ E 		{$$=assign($2,$1,$3,NULL,2);}

	|  E '>' E 		{$$=assign($2,$1,$3,NULL,2);} 

	|  E '<' E 		{$$=assign($2,$1,$3,NULL,2);}

	| VAR			{
				temp=lookup($1->var_name);
				if(temp!=NULL)
				{ 
					$1->loc=temp;
					$1->rettype=temp->type;
					$$=$1;
				}
				else
				{printf("VAR UNINITALIZED %s\n",$1->var_name);
				 error_flag=1;}
				}

	| VAR '[' E ']'		{
				temp=lookup($1->var_name);
				if(temp!=NULL)
				{ 
					$1->loc=temp;
					$1->rettype=temp->type;
					$1->left=$3;
					$$=$1;
				}
				else
				{printf("VAR UNINITALIZED %s\n",$1->var_name);
				 error_flag=1;}
				}

	| NUM			{$$=$1;}
	;
%%

int calculate(struct tree *root)
{
 int temp_index;
 if(root)
 {
   int toret;
   if(root->d==0)
   {
     //operator
     	if(root->op=='+')
     	{
	  toret=calculate(root->left)+calculate(root->right);
     	}
     	if(root->op=='*')
     	{
	 toret=calculate(root->left)*calculate(root->right);
     	}
	if(root->op=='=')
     	{
		if(root->left->left!=NULL)
	 	{
		temp_index=calculate(root->left->left);
     		root->left->loc->binding[temp_index]=calculate(root->right);
		//printf("%d \n",root->left->loc->binding[temp_index]);
		}
		else
		{root->left->loc->binding[0]=calculate(root->right);
		//printf("%d \n",root->left->loc->binding[0]);
		}
     	}
	if(root->op=='>')
     	{
	 if(calculate(root->left)>calculate(root->right))
		return 1;
	 else
		return 0;
     	}
     	if(root->op=='<')
     	{	
	 if(calculate(root->left)<calculate(root->right))
		return 1;
	 else
		return 0;
     	}
	if(root->op=='!')
     	{
	 if(calculate(root->left)==calculate(root->right))
		return 1;
	 else
		return 0;
     	}
   }
  if(root->d==1)
   {
     //integer
     toret=root->num;
   }
  if(root->d==2)
   {
 	//variable
    

    if(root->left!=NULL)
	{
		temp_index=calculate(root->left);

		if(root->loc->binding[temp_index]==-1)
    		{
 		printf("VARIABLE '%s' NOT INITALIZED  \n",root->var_name);
		exit(0);
 		}	
		
     		toret=root->loc->binding[temp_index];	
	}
    else
     {
	if(root->loc->binding[0]==-1)
    	{
 	printf("VARIABLE '%s' NOT INITALIZED  \n",root->var_name);
	exit(0);
    	}
		toret=root->loc->binding[0];
    }
   }
  if(root->d==3)
   {
	printf("ENTER NO: \n");
	//reads
	if(root->left->left!=NULL)
	{
		temp_index=calculate(root->left->left);
     		scanf("%d",&(root->left->loc->binding[temp_index]));
	}
	else
		scanf("%d",&(root->left->loc->binding[0]));
   }		
  if(root->d==4)
   {
	//writes
	printf("%d \n",calculate(root->left));
   }
  if(root->d==5)
   {
	//ifs
	if(calculate(root->left))
		calculate(root->right);
	else if(root->further)
		calculate(root->further);
   }
  if(root->d==6)
   {
	//whiles
	while(calculate(root->left))
		calculate(root->right);
   }	
  if(root->d==7)
   {
	//a null node to group together independent statements
	calculate(root->left);
	calculate(root->right);
   }
  return toret;
 }
 else
 {
  return 0;
 }
}

struct tree* assign(struct tree *main,struct tree *l,struct tree *r,struct tree *f,int returntype)
{
 if(returntype==1)
 {
 	if(l!=NULL && l->rettype!=1)
	{printf("%d-NOT A BOOLEAN EXPR \n",yylineno);error_flag=1;}
 }
 if(returntype==2)
 {
	if(l!=NULL && l->rettype!=2)
	{printf("%d-INVALID OPERAND - BOOLEAN DETECTED \n",yylineno);error_flag=1;}
	if(r!=NULL && r->rettype!=2)
	{printf("%d-INVALID OPERAND - BOOLEAN DETECTED \n",yylineno);error_flag=1;}
 }
 struct tree *node=malloc(sizeof(struct tree));
 node=main;
 node->left=l;
 node->right=r;
 node->further=f;
 return(node);
}

struct symbol_table* lookup(char *var_name)
{
 hold=head;
 while(hold!=NULL)
 {
  if(strcmp(hold->name,var_name)==0)
	break; 
  hold=hold->next;	 
 }
 return(hold);
}

void install(int var_type,int var_size,char *var_name)
{
 int i;
 struct symbol_table *new=malloc(sizeof(struct symbol_table));
 new->name=malloc(sizeof(char)*50);
 new->type=var_type;
 //printf("%d",new->type);
 new->size=var_size;
 //printf("%d",new->size);
 strcpy(new->name,var_name);
 new->next = NULL;
 new->binding = (int*)malloc(sizeof(int)*var_size);
 for(i=0;i<var_size;i++)
	new->binding[i]=-1;
 if(head==NULL)
 {
  head=new;
  back = new;
 }
 else
 {
  back->next=new;
  back=back->next;
 }

}

void yyerror( char *s)
{
 fprintf(stderr,"%s",s);
}

int main(void)
{
 yyparse(); 
 return 0;
}
