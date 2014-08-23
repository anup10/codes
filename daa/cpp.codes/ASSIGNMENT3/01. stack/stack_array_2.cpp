#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>

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

void push(int array[],int data)
 {
	if(isfull())
		cout<<"OVERFLOW\n"; 
	else
	 {
		cout<<endl;
		array[++top]=data;
	 }
 }

int pop(int array[])
 {
	if(isempty())
		return -1000000;
	else
		return (array[top--]);
 }

int peek(int array[])
 {
	if(isempty())
		return -1000000;
	else
		return array[top];
 }

void show(int array[])
 {
	if(isempty())
		cout<<"EMPTY\n";
	else
	 {
		for(int i=top;i>=0;i--)
			cout<<array[i]<<"\t";
		cout<<endl;
	 }
 }

int main()
 {
	int c,i=0,t;

	fstream fin;
	fin.open("test1.txt",ios::in);
	fin>>c;
	capacity=c;

	int *content=new int[100];

	while(!fin.eof())
	 {
		fin>>content[i];
	 	i++;
	 }
	fin.close();
	int array[c];
	
	for(int j=0;j<i-1;j++)
	 {
		switch(content[j])
		 {
			case 0:
				return 0;
			case 1:
				push(array,content[++j]);
				break;
			case 2:
				t=pop(array);
				if(t!=-1000000)
					cout<<t<<endl;
				else
					cout<<"EMPTY\n";
				break;
			case 3:
				if(peek(array)!=-1000000)
					cout<<peek(array)<<endl;
				else
					cout<<"EMPTY\n";
				break;
			case 4:
				show(array);
				break;
			default:
				cout<<"INVALID DATA\n";
				break;
	 	 }
	 }

	
	return 0;
 }
