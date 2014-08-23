#include<iostream>
#include<climits>
#include<fstream>

using namespace std;

struct node
 {
	int data;
	node *left;
	node *right;
	node *parent;
 };

struct tree
 {
	node  *root;
 };

struct tree createbst()
 {
	tree t;
	t.root=NULL;
	return t;
 }

struct node *createnode(int d)
 {
	node *nw=new node;
	nw->data=d;
	nw->right=nw->left=nw->parent=NULL;
	return nw;
 }

void insert(tree *t,node *e)
 {
	node *x=new node;
	node *y=new node;
	if(t->root==NULL)
	 {
		t->root=e;
	 }
	else
	 {
		x=t->root;
		while(x!=NULL)
		 {
			y=x;
			if(e->data>x->data)
				x=x->right;
			else
				x=x->left;
		 }

		e->parent=y;

		if(y->data>e->data)
			y->left=e;
		else
			y->right=e;
	 }
 }

struct node *search(tree t,int k)
 {
	node *x=new node;
	x=t.root;
	if(x==NULL||x->data==k)
		return x;
	else if(k<x->data)
	 {
		t.root=x->left;
		search(t,k);
	 }
	else
	 {
		t.root=x->right;
		search(t,k);
	 }
 }

int findMin(tree t)
 {
	if(t.root==NULL)
		return INT_MIN;
	else
	 {
		node *x=new node;
		x=t.root;
		while(x->left!=NULL)
			x=x->left;
		return x->data;
	 }
 }

int findMax(tree t)
 {
	if(t.root==NULL)
		return INT_MIN;
	else
	 {
		node *x=new node;
		x=t.root;
		while(x->right!=NULL)
			x=x->right;
		return x->data;
	 }
 }

int successor(tree t,node *e)
 {
	if(t.root==NULL)
		return -1000000;
	else
	 {
		node *x=new node;
		x=t.root;
		while((x->data!=e->data)&&(x!=NULL))
		 {
			if(e->data>x->data)
				x=x->right;
			else
				x=x->left;
		 }
		if(x==NULL)
			return -1000000;		//NOT-FOUND
		else
		 {
			if(x->right!=NULL)
			 {
				t.root=x->right;
				return findMin(t);
			 }
			node *y=new node;
			y=x->parent;
			while((y!=NULL)&&(x==y->right))
			 {
				x=y;
				y=x->parent;
			 }
			if(y==NULL)
				return -2000000;	//NIL---DOESN'T EXIST
			else
				return y->data;
		
		 }
	 }
 }

int predecessor(tree t,node *e)
 {
	if(t.root==NULL)
		return -1000000;
	else
	 {
		node *x=new node;
		x=t.root;
		while((x->data!=e->data)&&(x!=NULL))
		 {
			if(e->data>x->data)
				x=x->right;
			else
				x=x->left;
		 }
		if(x==NULL)
			return -1000000;		//NOT-FOUND
		else
		 {
			if(x->left!=NULL)
			 {
				t.root=x->left;
				return findMax(t);
			 }
			node *y=new node;
			y=x->parent;
			while((y!=NULL)&&(x==y->left))
			 {
				x=y;
				y=x->parent;
			 }
			if(y==NULL)
				return -2000000;	//NIL---DOESN'T EXIST
			else
				return y->data;
		 }
	 }
 }

void print_in(node *x)
 {
	if(x!=NULL)
	 {
		print_in(x->left);
		cout<<x->data<<"  ";
		print_in(x->right);
	 }
 }

void del(tree *t,node *e)
 {
	node *x=new node;
	node *y=new node;
	x=t->root;
	y=x;
	while((x->data!=e->data)&&(x!=NULL))
	 {
		y=x;
		if(e->data>x->data)
			x=x->right;
		else
			x=x->left;
	 }


	if((x==t->root)&&(x->left==NULL)&&(x->right==NULL))
		t->root=NULL;
	else
	 {
		if(x->right==NULL&&x->left==NULL)
		 {
			if(x==y->left)
				y->left=NULL;
			else
				y->right=NULL;

			delete x;
		 }
		else if(x->right==NULL&&x->left!=NULL)
		 {
			if(x==t->root)
			 {
				t->root=x->left;
				t->root->parent=NULL;
			 }
			else if(x==y->left)
			 {
				x->left->parent=y;
				y->left=x->left;
			 }
			else
			 {
				x->left->parent=y;
				y->right=x->left;
			 }

			delete x;
		
		 }
		else if(x->right!=NULL&&x->left==NULL)
		 {
			if(x==t->root)
			 {
				t->root=x->right;
				t->root->parent=NULL;
			 }
			else if(x==y->left)
			 {
				x->right->parent=y;
				y->left=x->right;
			 }
			else
			 {
				x->right->parent=y;
				y->right=x->right;
			 }

			delete x;
		 }
		else
		 {
			tree t1;
			t1.root=x->right;
			int newdata=findMin(t1);
			x->data=newdata;
			y=x;
			x=x->right;
			while(x->left!=NULL)
			 {
				y=x;
				x=x->left;
			 }
			if(x->right==NULL)
			 {
				if(x==y->left)
					y->left=NULL;
				else
					y->right=NULL;
				delete x;
			 }
			else
			 {
				if(x==y->left)
				 {
					x->right->parent=y;
					y->left=x->right;
				 }
				else
				 {
					x->right->parent=y;
					y->right=x->right;
				 }

				delete x;
			 }
			
		 }
	 }
 }


int main()
 {
	tree t=createbst();

	int i=0,x;
	node *ptr=new node;
	fstream fin;
	fin.open("input.txt",ios::in);

	int *content=new int[100];

	while(!fin.eof())
	 {
		fin>>content[i];
		if(content[i]==0)
			break;
	 	i++;
	 }
	fin.close();

	for(int j=0;j<=i;j++)
	 {
		switch(content[j])
		 {
			case 0:
				return 0;
			case 1:
				insert(&t,createnode(content[++j]));
				//print_in(t.root);
				cout<<endl;
				break;
			case 2:
				ptr=search(t,content[++j]);
				if(ptr==NULL)
					cout<<"NOT FOUND";
				else
					cout<<"FOUND";

				cout<<endl;
				break;
			case 3:
				x=findMin(t);
				if(x==INT_MIN)
					cout<<"NIL";
				else
					cout<<x;

				cout<<endl;
				break;			
			case 4:
				x=findMax(t);
				if(x==INT_MIN)
					cout<<"NIL";
				else
					cout<<x;

				cout<<endl;
				break;		
			case 5:
				x=predecessor(t,createnode(content[++j]));
				if(x==-1000000)
					cout<<"NOT FOUND";
				else if(x==-2000000)
					cout<<"NIL";
				else
					cout<<x;
				cout<<endl;
				break;		
			case 6:
				x=successor(t,createnode(content[++j]));
				if(x==-1000000)
					cout<<"NOT FOUND";
				else if(x==-2000000)
					cout<<"NIL";
				else
					cout<<x;
				cout<<endl;
				break;	
			case 7:
				del(&t,createnode(content[++j]));
				//print_in(t.root);
				cout<<endl;
				break;	

			default:
				cout<<"INVALID DATA\n";
				break;
	 	 }
	 }	
	
	return 0;
 }
