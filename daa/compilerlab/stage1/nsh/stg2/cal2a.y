%{
    #include <stdio.h>
    //#include "cal2a.h"
    int yylex(void);
    void yyerror(char *);
    
	    struct expr_tree
	{
		int node_type;
		int val;
		char op;
		struct expr_tree *lt;
		struct expr_tree *rt;
	};

	struct expr_tree* makeLeafNode(int val);

	struct expr_tree* makeNode(char oprt,struct expr_tree *l,struct expr_tree *r);

	void inorder(struct expr_tree *node);
%}

%union {
	struct expr_tree *ptr;
	int val;
	};
	
%type <ptr> EXPR
%token <val> num
%left '+'
%left '*'

%%
PRGM:
        PRGM EXPR '\n'         { inorder($2); printf("\n");}
        |PRGM '\n'
        | 
        ;
        

EXPR:
        num			{ $$=makeLeafNode($1); }
        | EXPR '+' EXPR         { $$=makeNode('+',$1,$3); }
        | EXPR '*' EXPR 	{ $$=makeNode('*',$1,$3); }
        | '(' EXPR ')'		          
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}

struct expr_tree* makeLeafNode(int value)
{
  struct expr_tree *leafnode=(struct expr_tree*) malloc(sizeof(struct expr_tree));
  leafnode->node_type = 0;
  leafnode->val = value;
  leafnode->lt = NULL;
  leafnode->rt = NULL;
  return leafnode;
}

struct expr_tree* makeNode(char oprt,struct expr_tree *l,struct expr_tree *r)
{
  struct expr_tree *node=(struct expr_tree*) malloc(sizeof(struct expr_tree));
  node->node_type = 1;
  node->lt=l;
  node->rt=r;
  node->op=oprt;
  return node;
}

void inorder(struct expr_tree *node)
{
	if(node->node_type==1 )
	{
		
		inorder(node->lt);
		printf("%c",node->op);
		inorder(node->rt);
	}
	else
	{
		printf("%d",node->val);
	}
}

