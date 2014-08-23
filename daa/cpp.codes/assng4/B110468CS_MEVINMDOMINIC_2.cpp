#include<iostream>
#include<cstring>

using namespace std;

struct node
 {
	char data;
	node *next;
	node *left;
	node *right;
 };

struct stack 
 {
	node *top;
 };

struct stack createstack()
 {
	stack s;
	s.top=NULL;
	return s;
 }

struct node *create_new_node(char c)
 {
	node *ptr=new node;
	if(!ptr)
	 {
		cout<<"\n MEMORY ERROR ";
	 }
	ptr->data=c;
	ptr->next=NULL;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
 }

void push(stack *s,node *ptr)
 {
	if(s->top==NULL)
		s->top=ptr;
	else
	 {
		ptr->next=s->top;
		s->top=ptr;
	 }
 }

int isempty(stack s)
 {
	return (s.top==NULL);
 }

node *pop(stack *s)
 {
	node *temp=new node;
	if(isempty(*s))
		return NULL; //...........EMPTY..........
	else
	 {
		temp=s->top;
		s->top=(s->top)->next;
		return temp;
	 }		
 }

struct node *Top(stack s)
 {
	if(isempty(s))
		return NULL;
	else
		return s.top;	
 }

struct node *buildtree(char postfix[])
 {
	stack s;
	for(int i=0;i<strlen(postfix);i++)
	 {
		if(postfix[i]!='^'&&postfix[i]!='*'&&postfix[i]!='/'&&postfix[i]!='+'&&postfix[i]!='-')
		 {
			node *ptr=new node;
			ptr=create_new_node(postfix[i]);
			push(&s,ptr);
		 }
		else
		 {
			node *ptr2=new node,*ptr1=new node;
			ptr2=pop(&s);
			ptr1=pop(&s);
			node *ptr=new node;
			ptr=create_new_node(postfix[i]);
			ptr->left=ptr1;
			ptr->right=ptr2;
			push(&s,ptr);
		 }
	 }
	
	return pop(&s);
 }

void print_in(node *x)
 {
	if(x!=NULL)
	 {
		if(!(isalpha(x->data)))
			cout<<"(";

		print_in(x->left);
		cout<<x->data;
		print_in(x->right);

		if(!(isalpha(x->data)))
			cout<<")";

	 }
 }

void print_pre(node *x)
 {
	if(x!=NULL)
	 {
		cout<<x->data;
		print_pre(x->left);
		print_pre(x->right);
	 }
 }

void print_post(node *x)
 {
	if(x!=NULL)
	 {		
		print_post(x->left);
		print_post(x->right);
		cout<<x->data;
	 }
 }

char * non_rec_in(node *x)
 {
	char *final=new char[100];
	int i=0;
	stack s=createstack();
	while(1)
	 {
		while(x!=NULL)
		 {
			x->next=NULL;
			if(!(isalpha(x->data)))
				final[i++]='(';
			push(&s,x);
			x=x->left;
		 }
		if(isempty(s))
		 {
			final[i]='\0';
			return final;
		 }

		x=pop(&s);
		final[i++]=x->data;
		x=x->right;

	 }
 }


void non_rec_pre(node *x)
 {
	stack s=createstack();
	while(1)
	 {
		while(x!=NULL)
		 {
			cout<<x->data;
			x->next=NULL;
			push(&s,x);
			x=x->left;
		 }
		if(isempty(s))
			break;
		x=pop(&s);
		x=x->right;
	 }
 }

void non_rec_post(node *x)
 {
	stack s=createstack();
	while(1)
	 {
		if(x!=NULL)
		 {
			x->next=NULL;
			push(&s,x);
			x=x->left;
		 }
		else
		 {
			if(isempty(s))
				break;
			else if((Top(s))->right==NULL)
			 {
				x=pop(&s);
				cout<<x->data;
				if(!isempty(s))
				 {
					if(x==(Top(s))->right)
					 {
						x=pop(&s);
						cout<<x->data;
						while(!isempty(s))
						 {
							if(x==(Top(s))->right)
							 {
								x=pop(&s);
								cout<<x->data;
							 }
							else
								break;
						 }
					 }
				 }
			 }
			
			if(!isempty(s))
				x=(Top(s))->right;
			else
				x=NULL;			
		 }
	 }
 }

int main()
 {
	int ctr=0,i,j;
	char postfix[]="abcd^*+e-",*final=new char[200],*res=new char[200];
	node *ptr=new node;
	ptr=buildtree(postfix);
	cout<<"\n RECURSIVE IN-ORDER ::: ";
	print_in(ptr);
	cout<<"\n";
	cout<<"\n RECURSIVE PRE-ORDER ::: ";
	print_pre(ptr);
	cout<<"\n";
	cout<<"\n RECURSIVE POST-ORDER ::: ";
	print_post(ptr);
	cout<<"\n";
	cout<<"\n non_RECURSIVE in-ORDER ::: ";
	final=non_rec_in(ptr);
	res[0]='(';
	for(i=1,j=1;i<strlen(final);i++)
	 {
		if(final[i]=='(')
		 {
			ctr++;
			res[j++]=final[i];
		 }
		else if(isalpha(final[i]))
		 {
			res[j++]=final[i];
			if(final[i-1]!='(')
			 {
				while(ctr!=0)
				 {
					res[j++]=')';
					ctr--;
				 }
			 }
		 }
		else
		 {
			res[j++]=final[i];
		 }
	 }
	res[j++]=')';
	res[j]='\0';

	if(strlen(final)==1)
	cout<<final;
	else
	cout<<res;

	cout<<"\n";
	cout<<"\n non_RECURSIVE pre-ORDER ::: ";
	non_rec_pre(ptr);
	cout<<"\n";
	cout<<"\n non_RECURSIVE post-ORDER ::: ";
	non_rec_post(ptr);
	cout<<"\n";
	return 0;
 }
