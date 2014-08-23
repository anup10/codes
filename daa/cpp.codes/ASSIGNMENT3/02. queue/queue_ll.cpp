#include<iostream>
#include<fstream>

using namespace std;


struct node
 { 
	int data;
	node *next;
 }*front,*rear;



struct node *createqueue()
 {
	front=rear=NULL;
	return NULL;
 }

int isempty(node *q)
 {
	return (front==NULL);
 }

void enqueue(node *q,int data)
 {
	node *nw=new node;
	if(!nw)
	 {
		cout<<"\n NO FREE MEMORY ";
	 }
	nw->next=NULL;
	nw->data=data;
	

	if(front==NULL)
		front=rear=nw;
	else
	 {
		rear->next=nw;
		rear=nw;
	 }
 }

int dequeue(node *q)
 {
	int data;
	node *temp=new node;
	if(isempty(q))
		return -1000000;
	else
	 {
		temp=front;
		data=front->data;
		front=front->next;
		delete temp;
		return data;
	 }
 }

int peek(node *q)
 {
	if(isempty(q))
		return -1000000;
	else
		return front->data;
 }

void show(node *q)
 {
	if(isempty(q))
		cout<<"EMPTY\n";
	else
	 {
		node *temp=new node;
		temp=front;
		while(temp!=NULL)
		 {
			cout<<temp->data<<"\t";
			temp=temp->next;
		 }
	 }		
		
 }

int main()
 {

	int c,i=0,t;

	fstream fin;
	fin.open("1.txt",ios::in);


	int *content=new int[100];

	while(!fin.eof())
	 {
		fin>>content[i];
	 	i++;
	 }
	fin.close();
	node *q=createqueue();
	
	
	for(int j=0;j<i-1;j++)
	 {
		switch(content[j])
		 {
			case 0:
				return 0;
			case 1:
				enqueue(q,content[++j]);
				cout<<endl;
				break;
			case 2:
				t=dequeue(q);
				if(t!=-1000000)
					cout<<t<<endl;
				else
					cout<<"EMPTY\n";
				break;
			case 3:
				if(peek(q)!=-1000000)
					cout<<peek(q)<<endl;
				else
					cout<<"EMPTY\n";
				break;
			case 4:
				show(q);
				cout<<endl;
				break;
			default:
				cout<<"INVALID DATA\n";
				break;
	 	 }
	 }

	delete q;
	return 0;
 }
