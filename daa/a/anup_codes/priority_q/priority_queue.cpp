#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

struct node
{
	int data;
	int priority;
};

struct ptq
{	
	int last;
	int capacity;
	node **heap;
};

ptq *createpq(int num)
{	
	
	ptq *pq = new ptq;
	pq->last=-1;
	pq->capacity=num;
	pq->heap=new node*[num];
	return pq;
}

int isfull(ptq *pq)
{
	return(pq->last==(pq->capacity-1));
}


int left(int i)
{
	return (2*i+1);
}


int right(int i)
{
	return (2*i+2);
}


int isempty(ptq *pq)
{
	return (pq->last==-1);
}


node *createnode(int num,int pri)
{
	node *nod=new node;
	nod->data=num;
	nod->priority=pri;
	return nod;
}


void min_heapify(ptq *pq,int i)
{
	int min;
	node *temp,*temp1,*temp2,*temp3;
	if(left(i)<=pq->last)
	{	
		temp1=(pq->heap[left(i)]);
		temp3=pq->heap[i];
		if(temp1->priority<temp3->priority)
		{
			min=left(i);
		}
		else
		{
			min=i;
		}
		if(right(i)<=pq->last)
		{
			temp2=pq->heap[min];
			temp3=pq->heap[right(i)];
			if(temp3->priority<temp2->priority)
			min=right(i);
		}
	
		if(min!=i)
		{
			temp=pq->heap[i];
			pq->heap[i]=pq->heap[min];
			pq->heap[min]=temp;
			min_heapify(pq,min);
		}
	}
}


void build_min_heap(ptq *pq)
{
	int i;
	if(pq->last%2==0)
		i=pq->last/2-1;
	else
		i=pq->last/2;
	while(i>=0)
	{
		min_heapify(pq,i);
		i--;
	}
}


void insert(ptq *pq,node *temp)
{
	pq->heap[++(pq->last)]=temp;
	build_min_heap(pq);
}


int remove(ptq *pq)
{
	if(isempty(pq))
	{
		return -100;
	}
	else
	{	
		int a;
		a=pq->heap[0]->data;
		pq->heap[0]=pq->heap[pq->last];
		pq->last--;
		min_heapify(pq,0);
		return a;
	}
}
				

int peek(ptq *pq)
{
	if(isempty(pq))
	{
		return -100;
	}
	else
	{
		int a;
		a=pq->heap[0]->data;
		return a;
	}
}


node *search(ptq *pq,int find)
{
	int i;
	for(i=0;i<=pq->last;i++)
	{
		if(pq->heap[i]->data==find)
		return (pq->heap[i]);
	}
}


void increase_priority(ptq *pq,int temp,int newpr)
{
	node *temp1=search(pq,temp);
	temp1->priority=newpr;
	build_min_heap(pq);
}


int main()
{
	int a,b,c,size;
	node *temp;
	fstream fin("1.txt");
	cout<<"enter the size of priority queue"<<endl;
	cin>>size;
	if(!fin)
	{
		cout<<"cannot open input file"<<endl;
	}
	else
	{
		ptq *pq= createpq(size);
		
		while(!fin.eof())
		{
		fin>>a;
		switch(a)
		{
			case 0:
			exit(1);


			case 1:
			if(isfull (pq))
			{
				cout<<"overflow of data"<<endl;
			}
			else
			{
				fin>>b;
				fin>>c;
				temp=createnode(b,c);				
				insert(pq,temp);
				cout<<endl;
			}
			break;



			case 2:
			b=remove(pq);
			if(b==-100)
			{
				cout<<"empty queue"<<endl;
			}
			else
			{
				cout<<b<<endl;
			}
			break;


			case 3:
			b=peek(pq);
			if(b==-100)
			{
				cout<<"empty queue,peek"<<endl;
			}
			else
			{
				cout<<b<<endl;
			}
			break;


			case 4:
			fin>>b;
			fin>>c;
			increase_priority(pq,b,c);
			break;
		}
		}
	}
}
















































				
	

















































