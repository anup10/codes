#include<iostream>
#include<fstream>
#include<climits>
#include<cstring>

using namespace std;

int n_v;
int n_e;
int tim;

struct vertex
 {
	char color[20];
	int d,f,predecessor;
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



void DFS_VISIT(graph *G,int u)
 {
	cout<<u<<"	";
	tim++;
	G->V[u].d=tim;
	strcpy(G->V[u].color,"gray");
	for(int i=0;i<n_v;i++)
	 {
		if(i!=u&&G->weight[u][i]!=0)
		 {
			if(strcmp(G->V[i].color,"white")==0)
			 {
				G->V[i].predecessor=u;
				DFS_VISIT(G,i);
			 }
		 }
	 }
	
	strcpy(G->V[u].color,"black");
	tim++;
	G->V[u].f=tim;
 }

void DFS(graph *G)
 {
	int s;
	cout<<"\n ENTER THE SOURCE VERTEX  :  ";
	cin>>s;

	for(int i=0;i<n_v;i++)
	 {
		strcpy(G->V[i].color,"white");
		G->V[i].predecessor=INT_MIN;
	 }
	
	tim=0;


	DFS_VISIT(G,s);

	for(int i=0;i<n_v;i++)
	 {
		if(strcmp(G->V[i].color,"white")==0)
			DFS_VISIT(G,i);
	 }
 }

int main()
 {
	int u,v,w;
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

	DFS(&G);
	cout<<endl;
	return 0;
 }
