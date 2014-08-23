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
	char tp,ch,ip[1500];
	int t,len;
	stack *s=Createstack();
	cin>>t;
	while(t>0)
	{
		cin>>ip;
		len=strlen(ip);
		for(int i=0;i<len;i++)
		{
			ch=ip[i];
			if(ch>96 && ch<123)
				cout<<ch;
			else
			{
				switch(ch)
				{
					case '(' :
						Push(s,ch);
						break;
						
					case ')' :
					
						while(!IsEmpty(s))
						{
							tp=Pop(s);
							if(tp=='(' )
								break;
							cout<<tp;
						}
						break;
						
					case '^' :
						Push(s,ch);
						break;
						
					case '/' :
						tp=Peek(s);
						while(tp=='^')
						{
							tp=Pop(s);
							if(tp!='(' )
							cout<<tp;
							tp=Peek(s);
						}
						Push(s,ch);
						break;
						
					case '*' :
						tp=Peek(s);
						while(tp=='/' || tp == '^')
						{
							tp=Pop(s);
							if(tp!='(' )
							cout<<tp;
							tp=Peek(s);
						}
						Push(s,ch);
						break;
						
					case '-' :
						tp=Peek(s);
						while(tp=='/' || tp == '^' || tp=='*')
						{
							tp=Pop(s);
							if(tp!='(' )
							cout<<tp;
							tp=Peek(s);
						}
						Push(s,ch);
						break;
						
					case '+' :
						tp=Peek(s);
						while(tp=='/' || tp == '^' || tp=='*' || tp=='-')
						{
							tp=Pop(s);
							if(tp!='(' )
							cout<<tp;
							tp=Peek(s);
						}
						Push(s,ch);
						break;
				}
			}
		}
		while(!IsEmpty(s))
		{
			tp=Pop(s);
			if(tp!='(' )
			cout<<tp;
		}
		t--;
		cout<<endl;
	}
	
	return 0;
}
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


