#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>

using namespace std;


int top=-1;
int capacity=0;

int isempty()
 {
	return (top==-1);
 }

int isfull()
 {
	return (top==capacity-1);
 }

void push(char array[],int data)
 {
	if(isfull())
		cout<<"OVERFLOW\n"; 
	else
	 {
		array[++top]=data;
	 }
 }

int pop(char array[])
 {
	if(isempty())
		return -1000000;
	else
		return (array[top--]);
 }

int peek(char array[])
 {
	if(isempty())
		return -1000000;
	else
		return array[top];
 }

int precedence(char ch)
 {
	switch(ch)
	 {
		case '^':
			return 5;
		case '*':
			return 4;
		case '/':
			return 4;
		case '+':
			return 3;
		case '-':
			return 3;
		default:
			return 0;
	 }
 }

int main()
 {
	fstream fin;
	fin.open("1.txt",ios::in);

	while(!fin.eof())
	 {

		char re[100],infix[100],postfix[100],popped,nxt,stktop;
		int pren,pres;
		infix[0]='(';
		fin>>re;

		int c=strlen(re);
		capacity=c;
		int i=0,j=1;
		for(;i<strlen(re);i++,j++)
			infix[j]=re[i];
		infix[j]=')';
		infix[(j+1)]='\0';

		char array[capacity];
		j=0;
		for(int i=0;infix[i]!='\0';i++)
		 {
			if(infix[i]!='('&&infix[i]!=')'&&infix[i]!='^'&&infix[i]!='*'&&infix[i]!='/'&&infix[i]!='+'&&infix[i]!='-')
				postfix[j++]=infix[i];	
			else if(infix[i]=='(')
				push(array,infix[i]);
			else if(infix[i]==')')
			 {
				while((popped=pop(array))!='(')
				 {
					postfix[j++]=popped;
				 }
			 }
			else
			 {
				nxt=infix[i];
				pren=precedence(nxt);
				stktop=peek(array);
				pres=precedence(stktop);
				if(pren>pres)
					push(array,nxt);
				else
				 {
					while(pres>=pren)
					 {
						popped=pop(array);
						postfix[j++]=popped;
						stktop=peek(array);
						pres=precedence(stktop);
					 }
					push(array,nxt);
				 }
			 }
		 }
		postfix[j]='\0';
		puts(postfix);

	 }	
	return 0;
 }
