#include<iostream>
#include<fstream>
#include<climits>
#include<cstring>

using namespace std;

int n_v;
int n_e;
struct vertex
 {
	char color[20];
	int distance;
	int predecessor;
 };

struct edge
 {
	int a,b;
 };

struct graph
 {
	vertex *V;
	edge *E;
	int (*weight)[100];
 };

struct queue
 {
	int front,rear,capacity;
	int *array;
 };

struct queue createqueue(int size)
 {
	queue q;
	q.capacity=size;
	q.front=q.rear=-1;
	q.array=new int[q.capacity];
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

void BFS(graph *G,int s)
 {
	for(int i=0;i<n_v;i++)
	 {
		if(i!=s)
		 {
			strcpy(G->V[i].color,"white");
			G->V[i].distance=INT_MAX;
			G->V[i].predecessor=INT_MIN;
		 }
	 }
	strcpy(G->V[s].color,"gray");
	G->V[s].distance=0;
	G->V[s].predecessor=INT_MIN;
	int c=n_v;
	queue q=createqueue(c);
	enqueue(&q,s);
	while(!isempty(&q))
	 {
		int x=dequeue(&q);
		for(int i=0;i<n_v;i++)
		 {
			if(i!=x&&G->weight[x][i]!=0)
			 {
				if(strcmp(G->V[i].color,"white")==0)
				 {
					strcpy(G->V[i].color,"gray");
					G->V[i].distance=G->V[x].distance+1;
					G->V[i].predecessor=x;
					enqueue(&q,i);
				 }
			 }
		 }
		cout<<x<<"	";
		strcpy(G->V[x].color,"black");
	 }
 }

void PRINT_PATH(graph G,int s,int d)
 {
	if(s==d)
	  cout<<s<<"	";
	else if(G.V[d].predecessor==INT_MIN)
	  cout<<"\n NO PATH FROM "<<s<<" TO "<<d<<" EXISTS ";
	else
	 {
		PRINT_PATH(G,s,G.V[d].predecessor);
		cout<<d<<"	";
	 }
 }

int main()
 {
	int u,v,w,s,des;
	fstream fin;
	fin.open("graph2.txt");
	if(!fin)
	 {
		cout<<"\n ERROR ";
		return 0;
	 }

	fin>>n_v;
	fin>>n_e;
	graph G;
	G.V=new vertex[n_v];
	G.E=new edge[n_e];
	G.weight=new int[n_v][100];
	for(int i=0;i<n_v;i++)
	   for(int j=0;j<n_v;j++)
		G.weight[i][j]=0;
	
	for(int i=0;i<n_e;i++)
	 {
		fin>>u>>v>>w;
		G.weight[u][v]=w;
		G.weight[v][u]=w;
		G.E[i].a=u;
		G.E[i].b=v;
	 }

	cout<<"\n ENTER THE SOURCE VERTEX : ";
	cin>>s;
	cout<<"\n THE  VERTICES ARE TRAVERSED IN THE ORDER : ";
	BFS(&G,s);
	cout<<"\n ENTER THE DESTINATION, FOR PRINTING THE SHORTEST PATH FROM THE SOURCE TO THE CORRESPONDING DESTINATION : ";
	cin>>des;
	cout<<endl<<"THE SHORTEST PATH TO THE DESTINATION VERTEX FROM THE PREVIOUSLY ENTERED SOURCE VERTEX IS : ";
	PRINT_PATH(G,s,des);
	cout<<endl;
	return 0;
 }
