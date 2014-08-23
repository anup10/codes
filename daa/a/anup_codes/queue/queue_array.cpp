#include<iostream>
#include<fstream>
#include<cstdlib>


using namespace std;

struct queue
{
	int rear;
	int front;
	int capacity;
	int *array;
};

int isempty(queue *q)
{
	return (q->front==-1);
}

queue *createqueue(int cap)
{
	queue *q=new queue;
	q->front=q->rear=-1;
	q->capacity=cap;
	q->array=new int[cap];
	for(int i=0;i<cap;i++)
	{
		q->array[i]=0;
	}
	return q;
}

int isfull(queue *q)
{
	return (((q->front-(q->rear+1))%q->capacity)==0);
}

void enqueue(queue *q,int num)
{
	if(isempty(q))
	{
		q->array[(q->rear+1)%q->capacity]=num;
		(q->rear)++;
		(q->front)++;
	}
	else
	{
		q->array[(q->rear+1)%q->capacity]=num;
		q->rear=(q->rear+1)%q->capacity;
	}
}


int dequeue(queue *q)
{	
	int a;
	if(q->front==q->rear)
	{
		a=q->array[q->front];
		q->front=q->rear=-1;
		return a;
	}
	else
	{
		a=q->array[q->front];
		q->front=(q->front+1)%q->capacity;
		return a;
	}
}


int peek(queue *q)
{
	
	return (q->array[q->front]);
}

int qsize(queue *q)
{
	return ((q->rear-q->front+1+q->capacity)%q->capacity);
}


void show(queue *q)
{
	int a=q->front,b=(qsize(q)),i;
	for(i=1;i<=b;i++)
	{
		cout<<q->array[a]<<"\t";
		a=(a+1)%q->capacity;
	}
}



int main()
{
	int a,b,c;
	fstream fin("3.txt");
	cout<<"eneter the size of queue array \n";
	cin>>c;
	queue *q=createqueue(c);
	while(!fin.eof())
	{
		fin>>a;
		switch(a)
		{
			case 0:
			exit (1);


			case 1:
			if(!isfull(q))
			{
				fin>>b;
				enqueue(q,b);
				cout<<"\n";
			}
			else
			{
				cout<<"overflow\n";
			}
			break;


			case 2:
			if(!isempty(q))
			{
				b=dequeue(q);
				cout<<b;
				cout<<"\n";
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
				cout<<"empty queue\n";
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
				cout<<"empty queue,show \n";
			}

		}
	}
}













































	