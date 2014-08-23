#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

struct stack
{
	int top;
	int capacity;
	int *array;
};


struct stack *create_stack(int cpcty)
{
	stack *stck= new stack;
	stck->top=-1;
	stck->capacity=cpcty;
	stck->array=new int[stck->capacity];
	return stck;
}

 
int isfull(stack *stck)
{
	return(stck->top==(stck->capacity-1));
}

int isempty(stack *stck)
{
	return(stck->top==-1);
}

int pop(stack *stck)
{	
	if(!isempty(stck))
	{

		int a= stck->array[stck->top];
		stck->top=stck->top-1;
		return (a);	
	}
	else
	{
	cout<<"stcak is empty,pop operation is not possible"<<endl;
	return -100;
	}	
}


void push(stack *stck,int element)
{
	if(!isfull(stck))
	{
		stck->array[++stck->top]=element;
	}
	else
	{
	cout<<"stack is full,push operation is not possible"<<endl;
	
	}	
}


int peek(stack *stck)
{
	if(!isempty(stck))
	return(stck->array[stck->top]);
	
	else
	{
	cout<<"empty stack"<<endl;
	return -100;
	}
}

void show(stack *stck)
{
	if(!isempty(stck))
	{
		for(int i=stck->top;i>=0;i--)
			{
			cout<<stck->array[i]<<"\t";
			}
	}
	
	else
	cout<<"empty stack show"<<endl;
}
	

int main()
{	
	int c,temp,temp1,t;
	fstream fin ("1.txt");
	//or fin.open("1.txt",ios::in)

	cout<<"eneter the size of stack"<<endl;
	cin>>c;
	stack *stk=create_stack(c);
	while(!fin.eof())
	{
		fin>>c;
		switch(c)
		{
			case 0:
			exit(1);

		
			case 1:
			fin>>temp;
			push(stk,temp);
			cout<<endl;
			break;


			case 2:
			t=pop(stk);
			if(t!=-100)
				cout<<t<<endl;
			break;


			case 3:
			t=peek(stk);
			if(t!=-100)
				cout<<t<<endl;
			break;

			case 4:
			show(stk);
			cout<<endl;
			break;
		}
	}
}
	
			
































