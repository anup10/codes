#include<iostream>
#include<fstream>

using namespace std;

struct queue
 {
	int front,rear,capacity;
	int *array;
 };

struct queue *createqueue(int size)
 {
	queue *q=new queue;
	if(!q)
	 {
		cout<<"\n NO FREE MEMORY";
		return NULL;
	 }
	q->capacity=size;
	q->front=q->rear=-1;
	q->array=new int[q->capacity];
	if(!(q->array))
	 {
		cout<<"\n NO FREE MEMORY ";
		return NULL;
	 }
	return q;
 }

int isempty(queue *q)
 {
	return (q->front==-1);
 }

int isfull(queue *q)
 {
	return (q->front==(q->rear+1)%(q->capacity));
 }

int queuesize(queue *q)
 {
	return (q->capacity-q->front+q->rear+1)%q->capacity;
 }

void enqueue(queue *q,int data)
 {
	if(isfull(q))
		cout<<"OVERFLOW\n";
	else
	 {
		q->rear=(q->rear+1)%q->capacity;
		q->array[q->rear]=data;
		if(q->front==-1)
			q->front=q->rear;
	 }
 }

int dequeue(queue *q)
 {
	int data;
	if(isempty(q))
		return -1000000;
	else
	 {
		data=q->array[q->front];
		if(q->front==q->rear)
			q->front=q->rear=-1;
		else
			q->front=(q->front+1)%q->capacity;
	 }
	return data;
 }

int peek(queue *q)
 {
	if(isempty(q))
		return -1000000;
	else
		return q->array[q->front];
 }

void show(queue *q)
 {
	if(isempty(q))
		cout<<"EMPTY\n";
	else
		for(int i=q->front,j=0;j<queuesize(q);i++,j++)
			cout<<q->array[i%q->capacity]<<"\t";	
	cout<<endl;
 }

int main()
 {
	int c,i=0,t;

	fstream fin;
	fin.open("test2.txt",ios::in);
	fin>>c;


	int *content=new int[100];

	while(!fin.eof())
	 {
		fin>>content[i];
	 	i++;
	 }
	fin.close();
	queue *q=createqueue(c);
	
	
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
				break;
			default:
				cout<<"INVALID DATA\n";
				break;
	 	 }
	 }	
	return 0;
 }
