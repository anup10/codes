%{
	#include <stdio.h>
	void yyerror(char *s);
	int yylex(void);
	
	struct treeNode{
			
			int nodeType;
			int value;
			char opr;
			struct treeNode *lc;
			struct treeNode *rc;
		};
	
	struct treeNode* makeNode(char opr1, struct treeNode *lc1, struct treeNode *rc1);
	
	struct treeNode* makeLeaf(int num);
	
	struct treeNode* makeUnary(char opr, struct treeNode *sc);
	
	int inOrder(struct treeNode *root);
		
%}

%union{
	struct treeNode *nptr;
	int val;
};


%type <nptr> expr
%token <val> INT
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS


%%

program:
	program expr '\n'	{printf("%d\n",inOrder($2));
				}
	|
	;
	
expr:
	INT			{$$=makeLeaf($1);}
	|expr '+' expr		{$$=makeNode('+',$1,$3);}
	|expr '*' expr		{$$=makeNode('*',$1,$3);}
	|'(' expr ')'		{$$=$2;}
	|'-' expr %prec UMINUS	{$$=makeUnary('-',$2);}
	;
	
%%

void yyerror(char *s)
{
	fprintf(stderr,"%s",s);
}

int main(void)
{
	yyparse();
	return 0;
}

struct treeNode *makeNode(char opr1, struct treeNode *lc1, struct treeNode *rc1)
{
	struct treeNode *node=(struct treeNode *) malloc(sizeof(struct treeNode));
	node->nodeType=0;
	node->opr=opr1;
	node->lc=lc1;
	node->rc=rc1;
	
	return node;
}


struct treeNode *makeLeaf(int num)
{
	struct treeNode *leaf=(struct treeNode *)malloc(sizeof(struct treeNode));
	leaf->nodeType=1;
	leaf->value=num;
	leaf->lc=NULL;
	leaf->rc=NULL;
	
	return leaf;
}


struct treeNode *makeUnary(char opr1, struct treeNode *sc)
{
	struct treeNode *node=(struct treeNode *)malloc(sizeof(struct treeNode));
	node->nodeType=2;
	node->opr=opr1;
	node->lc=NULL;
	node->rc=sc;
	
	return node;
}


int inOrder(struct treeNode *root)
{
	if(root->nodeType==0)
	{
		if(root->opr=='+')
		return ((inOrder(root->lc))+(inOrder(root->rc)));
		if(root->opr=='*')
		return ((inOrder(root->lc))*(inOrder(root->rc)));
	}
	
	if(root->nodeType==1)
	{
		return root->value;
	}
	
	if(root->nodeType==2)
	{
		root->value= -(inOrder(root->rc));
		return root->value;
	}
}
	
		























	

















	
