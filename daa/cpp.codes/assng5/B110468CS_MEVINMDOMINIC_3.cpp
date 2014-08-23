#include<iostream>
#include<fstream>
#include<climits>
#include<cstring>

using namespace std;

int n_v;
int n_e;

struct vertex
 {
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

//*************************************************************************************************************************************
// CODE FOR MIN-PRIORITY QUEUE DIRECTLY USED FROM ASSIGNMENT_2, with remove() function changed to EXTRACT_MIN()

int n;

struct heap
 {
	int data;
	int priority;
 };

int parent(int i)
 {
	return (i/2);
 }

int right(int i)
 {
	return (2*i+1);
 }

int left(int i)
 {
	return (2*i);
 }

void min_heapify(heap a[],int i)
 {	
	int t,smallest;
	int l=left(i);
	int r=right(i);
	if((l<n)&&(a[l].priority<a[i].priority))
		smallest=l;
	else
		smallest=i;
	if((r<n)&&(a[r].priority<a[smallest].priority))
		smallest=r;
	if(smallest!=i)
	 {
		heap h=a[i];
		a[i]=a[smallest];
		a[smallest]=h;
		min_heapify(a,smallest);
	 }
	 		
 }

void build_min_heap(heap a[])
 {
	for(int i=(n/2);i>=0;i--)
		min_heapify(a,i);
 }


void insert(heap a[],heap e)
 {
	a[n++]=e;
	build_min_heap(a);
 }

int EXTRACT_MIN(heap a[])
 {
	int temp;
	heap h=a[0];
	temp=a[0].data;
	a[0]=a[n-1];
	n--;
	min_heapify(a,0);
	if(n>1)
	 {
		for(int i=0;i<n-1;i++)
		 {
			if(a[i].priority==a[i+1].priority)
			 {
				h=a[i];
				a[i]=a[i+1];
				a[i+1]=h;
			 }
		 }
	 }

	return temp;	
 }

//**************************************************************************************************************************************

void INITIALIZE(graph *G,int &s)
 {
	for(int i=0;i<n_v;i++)
	 {
		G->V[i].distance=INT_MAX;
		G->V[i].predecessor=INT_MIN;
	 }
	G->V[s].distance=0;
 }

void RELAX(graph *G,int a,int b,heap ar[])
 {
	if( (G->V[b].distance) > (G->V[a].distance)+(G->weight[a][b]) )
	 {
		(G->V[b].distance) = (G->V[a].distance)+(G->weight[a][b]);
		G->V[b].predecessor=a;
	 }
	for(int i=0;i<n;i++)
	 {
		if(ar[i].data==b)
		 {
			ar[i].priority=G->V[b].distance;
			build_min_heap(ar);
			break;
		 }
	 }
 }


void DIJKSTRA(graph *G,int s)
 {
	INITIALIZE(G,s);	
	int S[n_v];
	for(int i=0;i<n_v;i++)
		S[i]=0;
	
	heap *a=new heap[n_v];
	heap h;
	for(int i=0;i<n_v;i++)
	 {
		h.data=i;
		h.priority=G->V[i].distance;
		insert(a,h);
	 }
	while(n!=0)	//QUEUE NOT-EMPTY CONDITION
	 {
		int x=EXTRACT_MIN(a);
		cout<<x<<"	";
		S[x]=1;
		for(int i=0;i<n_v;i++)
		 {
			if(i!=x&&G->weight[x][i]!=0)
				RELAX(G,x,i,a);
		 }
	 }	
 }


int main()
 {
	n=0;
	int u,v,w,s;
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
	
	DIJKSTRA(&G,s);
	cout<<endl;
	return 0;
 }
