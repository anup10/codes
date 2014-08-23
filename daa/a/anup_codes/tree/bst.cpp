#include<iostream>
#include<fstream>
#include<cstdlib>

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
	node *root ;
};

tree *create_tree()
{
	tree *tr=new tree;
	tr->root=NULL;
	return tr;
}

void insert(tree *tr,int num)
{
	node *temp=new node;
	temp->data=num;
	temp->right=NULL:
	temp->left=NULL;
	node *temp1=new node;
	temp1=tr->root;
	node *temp2=new node;
	temp2=NULL;
	while(temp1)
	{
		temp2=temp1;
		if(num>temp1->data)
			temp1=temp1->right;
		if(num<temp1->data)
			temp1=temp1->left;
	}
	temp->parent=temp2;
	if(temp2==NULL)
		tr->root=temp;
	else
	{
		if(temp2->data>num)
			temp2->left=temp;
		else
			temp2->right=temp;
	}
}


void search(tree *tr,int num)
{
	node *temp=new node;
	temp=tr->root;
	while(temp && temp->data!=num)
	{
		if(num>temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}
	if(temp==NULL)
		cout<<"not found"<<endl;
	else
		cout<<"found"<<endl;
} 


int tree_min(tree *tr)
{
	node *temp=new node;
	temp=tr->root;
	while(temp && temp->left)
	{
		temp=temp->left;
	}
	if(!temp)
	{
		return -1001;
	}
	else
	{
		return (temp->data);
	}
}


int tree_max(tree *tr)
{
	node *temp=new node;
	temp=tr->root;
	while(temp && temp->right)
	{
		temp=temp->right;
	}
	if(!temp)
	{
		return -1001;
	}
	else
	{
		return (temp->data);
	}
}

int tree_successor(node *x)
{	
	int a;
	node *temp=new node;
	if(x->right)
	{
		tree *sub_tr=new tree;
		sub_tr->root=x->right;
		a=tree_min(sub_tr);
		return a;
	}
	else
	{
		temp=x->parent;
		while(temp && x==temp->right)
		{
			x=temp;
			temp=x->parent;
		}
		if(!temp)
			return -1001;
		else
			return (temp->data);
	}
}


int tree_predecessor(node *x)
{
	int a;
	node *temp=new node;
	if(x->left)
	{
		





























































