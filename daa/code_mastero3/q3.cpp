#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

struct stack
{
	int top;
	int capacity;
	char *array;
};

struct stack *Createstack()
 {
	stack *s=new stack;;
	s->capacity=1500;
	s->top=-1;
	s->array=new char[s->capacity];
	return s;
 }
	
int IsEmpty(stack *s)
{
	return (s->top==-1);
}

int IsFull(stack *s)
 {
	return (s->top==s->capacity-1);
 }	

void Push(stack *s, char data)
{
	
		s->array[++s->top]=data;
	
 }	
	
char Pop(stack *s)
 {
	return (s->array[s->top--]);
 }

char Peek(stack *s)
{
	if(IsEmpty(s))
		return '!';
	else
	return (s->array[s->top]);
}


int main()
{
	char ip[1000],t;
	int n,i,j,count;
	stack *s=Createstack();
	cin>>ip;
	cin>>n;
	while(n>0)
	{
		cin>>i;
		cin>>j;
		count=0;
		for(int k=i-1;k<=j-1;k++)
		{
			if(ip[k]=='(' )
				Push(s,'(');
				
			if(ip[k]==')')
			{	
				if(!IsEmpty(s))
				{
					t=Pop(s);
					count++;
				}
			}
		}
		while(!IsEmpty(s))
			t=Pop(s);
		cout<<(count*2)<<endl;
		n--;
	}
	return 0;
}




















