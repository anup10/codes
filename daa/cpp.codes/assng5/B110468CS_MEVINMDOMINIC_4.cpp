#include<iostream>
#include<fstream>
#include<climits>
#include<cstring>

using namespace std;

int n_v;
int n_e;
int n=0;
int xip=0;
struct vertex
 {
	char color[20];
	int distance;
	int predecessor;
 };

struct edge
 {
	int a,b;
	int weight;
 };

struct graph
 {
	vertex *V;
	edge *E;
	int (*weight)[100];
 };
struct node
 {
	int data;
	int rank;
	node *parent;
 };

struct tree
 {
	node *root;
 };

tree *forest=new tree[100];

struct node * make_set(int x)
 {
	node *ptr=new node;
	ptr->data=x;
	ptr->rank=0;
	ptr->parent=ptr;
	tree *t=new tree;
	t->root=ptr;
	return t->root;
 }


node * find(int x)
 {
	int i;
	for( i=0;i<n_v;i++)
		if((forest[i].root)->data==x)
		 {
			node *ptr=new node;
			ptr=forest[i].root;
			while(ptr->parent!=ptr)
				ptr=ptr->parent;

			return ptr;
		 }
 }

void UNION(int a,int b)
 {
	if(find(a)!=find(b))
	 {
		node *x=new node;
		node *y=new node;
		int i;
		x=find(a);
		y=find(b);

		if(x->rank>y->rank)
			y->parent=x;
		else
		 {
			x->parent=y;
			if(x->rank==y->rank)
				y->rank++;
		 }
	 }	
 }

edge * KRUSKAL(graph *G)
 {
	edge *A=new edge[100];
	for(int i=0;i<n_v;i++)
	   forest[i].root=make_set(i);
	
//SORTING...............................
	for(int i=0;i<n_e-1;i++)
	   for(int j=i+1;j<n_e;j++)
	    {
		if( (G->E[j].weight) < (G->E[i].weight) )
		 {
			edge e=G->E[j];
			G->E[j]=G->E[i];
			G->E[i]=e;
		 }
	    }
//.......................................
	for(int i=0,j=0;i<n_e;i++)
	 {
		if((find(G->E[i].a))!=(find(G->E[i].b)))
		 {
			A[j++]=G->E[i];
			UNION(G->E[i].a,G->E[i].b);
			xip++;
		 }
	 }
	cout<<endl;
	return A;
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
		G.E[i].weight=w;
	 }
	edge *A=new edge;
	A=KRUSKAL(&G);
	int final_tree[100][100];
	int cost=0;
	for(int i=0;i<n_v;i++)
	   for(int j=0;j<n_v;j++)
		final_tree[i][j]=0;
	for(int i=0;i<xip;i++)
	 {
		final_tree[A[i].a][A[i].b]=1;
		final_tree[A[i].b][A[i].a]=1;
		cost+=A[i].weight;
	 }


	cout<<cost;
	for(int i=0;i<n_v;i++)
	 {
		cout<<endl;
	 	for(int j=0;j<n_v;j++)
	  	 {
			cout<<final_tree[i][j];		
	  	 }
	 }
	cout<<endl;
	return 0;
 }
