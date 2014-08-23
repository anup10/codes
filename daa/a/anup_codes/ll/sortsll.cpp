#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

struct node
{
	int data;
	 node *next;
};

struct lnd
{
	node *top;
};

lnd *createll()
{
	lnd *ll =new lnd;
	ll->top=NULL;
	return ll;
}

int isempty(lnd *ll)
{
	return (ll->top==NULL);
}


void insert(lnd *ll,int num)
{
	node *temp=new node;
	temp->data=num;
	temp->next=NULL;
	if(ll->top==NULL)
	{
		ll->top=temp;
	}
	else
	{
		temp->next=ll->top;
		ll->top=temp;
	}
}


int del(lnd *ll,int pos)
{
	node *y=new node;
	y=ll->top;
	node *x=new node;
	int i=1,a;
	if(ll->top==NULL)
	{
		cout<<"empty list\n";
		return -1001;
	}
	else if(pos==1)
	{
		x=ll->top;
		ll->top=ll->top->next;
		a =x->data;
		delete x;
		return a;
	}
	else
	{
		while((y!=NULL) && (i<pos))
		{
		x=y;
		y=y->next;
		i++;
		}
		if(y==NULL)
		{
			cout<<"position for delete out of range \n";
			return -1001;
		}
		else
		{
			x->next=y->next;
			 a=y->data;
			delete y;
			return a;
		}	
	}
}


void show(lnd *ll)
{
	node *x=new node;
	x=ll->top;
	while(x)
	{
		cout<<x->data<<"\t";
		x=x->next;
	}
	delete x;
}



void insert_at(lnd *ll,int num,int pos) 
{
	node *temp =new node;
	temp->data=num;
	temp->next=NULL;
	node *y=new node ;
	y=ll->top;
	node *x=new node;
	int i=1;
	while((y!=NULL) && (i<pos))
	{
		x=y;
		y=y->next;
		i++;
	}
	if(y==NULL)
	{
		x->next=temp;
		//cout<<"inserted at the last position,as pos given was out of range\n";
	}
	else if (y==ll->top)
	{
		temp->next=y;
		ll->top=temp;
	}
	else
	{
		x->next=temp;
		temp->next=y;
	}
}


void swap(lnd *ll,int i,int j)
{
	node *x=new node ;
	node *y=new node;
	y=ll->top;
	int a,b;
	a=del(ll,j);
	b=del(ll,i);
	if(a==-1001||b==-1001)
	{
		cout<<"deletion position out of range\n";
		return;
	}
	insert_at(ll,a,i);
	insert_at(ll,b,j);
}
	
	
void sort(lnd *ll)
{
	int i=1,j,small,smallpos,t;
	node *y=new node;
	y=ll->top;
	node *x=new node;
	
	while(y)
	{
		small=y->data;
		smallpos=i;
		j=i+1;
		x=y->next;
		while(x)
		{
			t=x->data;
			if(t<small)
			{
				small=t;
				smallpos=j;
			}
			x=x->next;
			j++;
		}
		if(smallpos!=i)
		{
			swap(ll,i,smallpos);
		}
		i++;
		y=y->next;
	}
}


int main()
{	
	int size,i,j,k;
	fstream fin("6.txt");
	fin>>size;
	lnd *ll =new lnd;
	ll=createll();
	while(!fin.eof())
	{
		fin>>i;
		insert(ll,i);
	}
	cout<<"original linked list is:"<<endl;
	show(ll);
	cout<<endl;
	sort(ll);
	cout<<"sorted linked list is:"<<endl;
	show(ll);
	cout<<endl;
	delete ll;
	return 0;
}














































