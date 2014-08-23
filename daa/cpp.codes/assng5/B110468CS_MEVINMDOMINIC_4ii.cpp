#include<iostream>
#include<fstream>

using namespace std;

struct node
 {
	int data;
	node *parent;
 };

struct tree
 {
	node *root;
 };

tree *st=new tree[100];
int n=0;

struct node * make_set(int x)
 {
	node *ptr=new node;
	ptr->data=x;
	ptr->parent=ptr;
	tree *t=new tree;
	t->root=ptr;
	return t->root;
 }

node * FIND_PC(node *x)
 {
	if(x!=x->parent)
		x->parent=FIND_PC(x->parent);
	return x->parent;
 }

node * find(int x)
 {
	int i;
	for( i=0;i<n;i++)
		if((st[i].root)->data==x)
		 {
			node *ptr=new node;
			ptr=st[i].root;
			while(ptr->parent!=ptr)
				ptr=ptr->parent;

			return (FIND_PC(ptr));
		 }
 }

void UNION(int a,int b)
 {
	if(find(a)!=find(b))
	 {
		node *x=new node;
		node *y=new node;
		int i;
		x=find(a);
		y=find(b);

		y->parent=x;
	 }	
 }

int main()
 {
	int i=0,a1,a2;
	node *p=new node;
	for(int j=0;j<100;j++)
		st[j].root=NULL;
	/*st[0].root=make_set(10);
	st[1].root=make_set(20);
	st[2].root=make_set(30);
	n=3;
	cout<<find(20)->data;
	UNION(10,20);
	cout<<find(20)->data;*/
	fstream fin;
	fin.open("dinput.txt");
	int *content=new int[200];
	while(!fin.eof())
	 {
		fin>>content[i];
		if(content[i]==0)
			break;
		i++;
	 }

	for(int j=0,k=0;j<=i;j++)
	 {
		switch(content[j])
		 {
			case 0:
				return 0;
			case 1:
				st[k++].root=make_set(content[++j]);
				n++;
				cout<<endl;
				break;
			case 2:
				p=find(content[++j]);
				cout<<p->data;
				cout<<endl;
				break;
			case 3:
				a1=content[++j];
				a2=content[++j];
				UNION(a1,a2);
				cout<<endl;
				break;
			default:
				cout<<" INVALID DATA\n";
		 }
	 }
	return 0;
 }
