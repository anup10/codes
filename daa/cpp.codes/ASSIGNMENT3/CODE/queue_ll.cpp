#include<iostream>
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
	node *q=createqueue();
	enqueue(q,5);
	enqueue(q,6);
	enqueue(q,7);
	enqueue(q,8);
	cout<<dequeue(q);
	cout<<dequeue(q);
	cout<<peek(q);
	show(q);
	delete q;
	return 0;
 }
