#include<iostream>
#include<fstream>

using namespace std;

struct node
 {
	int data;
	node *next;
 };


struct node *createstack()
 {
	return NULL;
 }

struct node *create_new_node(int n)
 {
	node *ptr=new node;
	if(!ptr)
	 {
		cout<<"\n MEMORY ERROR ";
	 }
	ptr->data=n;
	ptr->next=NULL;
	return ptr;
 }

void push(node **top,int n)
 {
	node *ptr=create_new_node(n);
	if(*top==NULL)
		*top=ptr;
	else
	 {
		ptr->next=*top;
		*top=ptr;
	 }
 }

int isempty(node *top)
 {
	return (top==NULL);
 }

int pop(node **top)
 {
	int data;
	node *temp=new node;
	if(isempty(*top))
		return -1000000;
	else
	 {
		temp=*top;
		*top=(*top)->next;
		data=temp->data;
		delete temp;
		return data;
	 }		
 }

int peek(node *top)
 {
	if(isempty(top))
		return -1000000;
	else
		return (top)->data;	
 }

void show(node *top)
 {
	node *temp=new node;
	temp=top;
	if(isempty(top))
		cout<<"EMPTY\n";
	while((temp)!=NULL)
	 {
		cout<<temp->data<<"\t";
		temp=temp->next;
	 }
	cout<<"\n";
	delete temp;
 }

int main()
 {
	int c,i=0,t;

	fstream fin;
	fin.open("test.txt",ios::in);

	int *content=new int[100];
	while(!fin.eof())
	 {
		fin>>content[i];
	 	i++;
	 }
	fin.close();
	node *top=createstack();

	for(int j=0;j<i;j++)
	 {
		switch(content[j])
		 {
			case 0:
				return 0;
			case 1:
				cout<<endl;
				push(&top,content[++j]);
				break;
			case 2:
				t=pop(&top);
				if(t!=-1000000)
					cout<<t<<endl;
				else
					cout<<"EMPTY\n";
				break;
			case 3:
				if(peek(top)!=-1000000)
					cout<<peek(top)<<endl;
				else
					cout<<"EMPTY\n";
				break;
			case 4:
				show(top);
				break;
			default:
				cout<<"INVALID DATA\n";
				break;
	 	 }
	 }



	delete top;
	return 0;
 }

