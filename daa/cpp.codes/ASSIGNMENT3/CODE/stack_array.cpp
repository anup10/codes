#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

struct stack
 {
	int top;
	int capacity;
	int *array;
 };

struct stack *createstack(int cpty)
 {
	stack *s=new stack;;
	s->capacity=cpty;
	s->top=-1;
	s->array=new int[s->capacity];
	return s;
 }

int isempty(stack *s)
 {
	return (s->top==-1);
 }

int isfull(stack *s)
 {
	return (s->top==s->capacity-1);
 }

void push(stack *s,int data)
 {
	if(isfull(s))
		cout<<"OVERFLOW\n"; 
	else
	 {
		cout<<endl;
		s->array[++s->top]=data;
	 }
 }

int pop(stack *s)
 {
	if(isempty(s))
		return -1000000;
	else
		return (s->array[s->top--]);
 }

int peek(stack *s)
 {
	if(isempty(s))
		return -1000000;
	else
		return s->array[s->top];
 }

void show(stack *s)
 {
	if(isempty(s))
		cout<<"EMPTY\n";
	else
		for(int i=s->top;i>=0;i--)
			cout<<s->array[i]<<"\t";
 }

int main()
 {
	int c,i=0,t;

	fstream fin;
	fin.open("test1.txt",ios::in);
	fin>>c;

	int *content=new int[100];
	while(!fin.eof())
	 {
		fin>>content[i];
	 	i++;
	 }
	fin.close();
	stack *s=createstack(c);
	
	for(int j=0;j<i-1;j++)
	 {
		switch(content[j])
		 {
			case 0:
				return 0;
			case 1:
				push(s,content[++j]);
				break;
			case 2:
				t=pop(s);
				if(t!=-1000000)
					cout<<t<<endl;
				else
					cout<<"EMPTY\n";
				break;
			case 3:
				if(peek(s)!=-1000000)
					cout<<peek(s)<<endl;
				else
					cout<<"EMPTY\n";
				break;
			case 4:
				show(s);
				cout<<endl;
				break;
	 	 }
	 }

	delete(s);
	delete(content);
	return 0;
 }
