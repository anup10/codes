#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

struct node
{
	int data;
	node *next;
};

struct queue
{
	node *front;
	node *rear;
};


int isempty(queue *q)
{
	return (q->front==NULL);
}


queue *createqueue()
{
	queue *q=new queue;
	q->front=NULL;
	q->rear=NULL;
	return q;
}

node *createnode(int num)
{
	node *nod=new node;
	nod->data=num;
	nod->next=NULL;
	return nod;
}

void enqueue(queue *q,int num)
{
	node *temp=createnode(num);
	
	if(isempty(q))
	{	
		
		q->rear=q->front=temp;
	}
	else
	{	
		q->rear->next=temp;
		q->rear=temp;
	}
}


int dequeue(queue *q)
{
	int b;
	if(q->front==q->rear)
	{
		b=q->front->data;
		q->front=q->rear=NULL;
		return b;
	}
	else
	{
		b=q->front->data;
		q->front=q->front->next;
		return b;
	}
}


int peek(queue *q)
{
	return (q->front->data);
}


void show(queue *q)
{
	node *temp;
	temp=q->front;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}


int main()
{
	int a,b,c,d;
	fstream fin("3.txt");
	queue *q=createqueue();
	while(!fin.eof())
	{
		fin>>a;
		switch(a)
		{
			case 0:
			exit(1);


			case 1:
			fin>>b;
			enqueue(q,b);
			cout<<"\n";
			break;
		

			case 2:
			if(!isempty(q))
			{
				b=dequeue(q);
				cout<<b<<"\n";
			}
			else
			{
				cout<<"underflow\n";
			}
			break;


			case 3:
			if(!isempty(q))
			{
				b=peek(q);
				cout<<b<<"\n";
			}
			else
			{
				cout<<"empty queue,peek\n";
			}
			break;


			case 4:
			if(!isempty(q))
			{
				show(q);
				cout<<"\n";
			}
			else
			{
				cout<<"empty queue,show\n";
			}
			break;
		}
	}
}		

























































		




























