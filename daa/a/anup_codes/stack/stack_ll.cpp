#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

struct node
{
	int data;
	node *next;
};

struct stack
{
	node *top;
};

stack *createstack()
{	
	stack *stk = new stack;
	stk->top=NULL;
	return stk;
}

node *createnode(int num)
{
	node *nod=new node;
	nod->data=num;
	return nod;
}

int isempty(stack *stk)
{
	return (stk->top==NULL);
}

void push(stack *stk,int num)
{
	node *temp=createnode(num);
	temp->next=stk->top;
	stk->top=temp;
}


int pop(stack *stk)
{
	if(!isempty(stk))
		{
		int a=stk->top->data;
		stk->top=stk->top->next;
		return a;
		}
	else
		return -100;
}



int peek(stack *stk)
{
	if(!isempty(stk))
		return (stk->top->data);
	
	else
		return -100;
}


void show(stack *stk)
{
	node *temp;
	temp=stk->top;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}


int main()
{
	int a,b,c;
	stack *stk=createstack();
	fstream fin;
	fin.open("3.txt",ios::in);
	while(!fin.eof())
	{
		fin>>a;
		switch(a)
		{
			case 0:
			exit(1);

	
			case 1:
			fin>>b;
			push(stk,b);
			cout<<endl;
			break;


			case 2:
			c=pop(stk);
			if(c!=-100)
			cout<<c<<endl;
			else
			cout<<"empty stack,pop not possible"<<endl;			
			break;

			case 3:
			c=peek(stk);
			if(c!=-100)
			cout<<c<<endl;
			else
			cout<<"empty stack,peek not possible"<<endl;
			break;

			case 4:
			if(!isempty(stk))
			{
				show(stk);
				cout<<endl;
			}
			else
			cout<<"stack is empty"<<endl;
			break;

		}
	}
	fin.close();
}










































	

















































