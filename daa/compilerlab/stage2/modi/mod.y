%{
 #include<stdio.h>
 #include<stdlib.h>
 int yylex(void);
 void yyerror(char *);

 struct tree
 {
  float num;
  int d;
  char op;
  struct tree *left,*right;
 };

 void inorder(struct tree *);
 void preorder(struct tree *);
 void postorder(struct tree *);
 float calculate(struct tree *);

%}

%union
{
  struct tree *node;
}

%token <node> NUM '+' '*'

%type <node> expr 

%left '+'
%left '*'

%%
 program :
	program expr '\n'	{ printf("%f \n",calculate($2));
				  printf("INORDER \n");inorder($2);printf("\n");
				  printf("PREORDER \n");preorder($2);printf("\n");
				  printf("POSTORDER \n");postorder($2);printf("\n"); }
	|
	;

 expr :
	NUM			{ $$=$1;}
	| expr '+' expr		{ $$=$2;
				  $$->left=$1;
				  $$->right=$3;}
	| expr '*' expr		{ $$=$2;
				  $$->left=$1;
				  $$->right=$3; }
	| '(' expr ')'		{
				  $$=$2;
				}
	;
%%


void inorder(struct tree *root)
 {
	if(!root)
		return;
	else
	 {
		inorder(root->left);
		if(root->d==0)
			printf("%c",root->op);
		else
			printf("%f",root->num);
		inorder(root->right);
	 }
 }

void preorder(struct tree *root)
 {
	if(!root)
		return;
	else
	 {
		if(root->d==0)
			printf("%c",root->op);
		else
			printf("%f",root->num);
		preorder(root->left);
		preorder(root->right);
	 }
 }

void postorder(struct tree *root)
 {
	if(!root)
		return;
	else
	 {
		postorder(root->left);
		postorder(root->right);
		if(root->d==0)
			printf("%c",root->op);
		else
			printf("%f",root->num);
		
	 }
 }

float calculate(struct tree *root)
{
	if(root->d==0)
	{
		if(root->op=='+')
		return ((calculate(root->left))+(calculate(root->right)));
		if(root->op=='*')
		return ((calculate(root->left))*(calculate(root->right)));
	}
	
	if(root->d==1)
		return root->num;
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
