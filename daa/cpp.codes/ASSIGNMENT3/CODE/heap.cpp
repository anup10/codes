#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include<ctime>

using namespace std;

int n;

struct heap
 {
	int data;
	int priority;
 }h;

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
		h=a[i];
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

void increase_priority(heap a[],int e,int nwp)
 {
	int i;
	for(i=0;i<n;i++)
		if(a[i].data==e)
		 {
			if(a[i].priority<nwp)
			 {
				cout<<"\n THE NEW PRIORITY IS LESS THAN THE ORIGINAL PRIORITY ";
				return;
			 }
			else
				a[i].priority=nwp;

			break;
		 }

	build_min_heap(a);
 }

void insert(heap a[],heap e)
 {
	a[n++]=e;
	build_min_heap(a);
 }

int peek(heap a[])
 {
	if(n==0)
		return -1000000;
	else
	 {
		cout<<a[0].data<<" ("<<a[0].priority<<")"<<endl;	
		return 1;
	 }
 }

int remove(heap a[])
 {
	if(n==0)
		return -1000000;
	else
	 {
		cout<<a[0].data<<" ("<<a[0].priority<<")"<<endl;
		h=a[0];
		a[0]=a[n-1];
		n--;
		min_heapify(a,0);
		return 1;
	 }	
 }

int main()
 {
	n=0;
	heap *a=new heap[10000];
	int el,pr,i=0,t;
	/*h.data=45;
	h.priority=5;
	insert(a,h);
	h.data=65;
	h.priority=9;
	insert(a,h);
	h.data=74;
	h.priority=7;
	insert(a,h);
	h.data=25;
	h.priority=2;
	insert(a,h);
	h.data=98;
	h.priority=3;
	insert(a,h);
	cout<<peek(a);
	increase_priority(a,74,1);
	cout<<peek(a);
	cout<<remove(a);
	cout<<peek(a);*/

	fstream fin;
	fin.open("test4.txt",ios::in);

	int *content=new int[100];

	while(!fin.eof())
	 {
		fin>>content[i];
	 	i++;
	 }
	fin.close();
	
	for(int j=0;j<i-2;j++)
	 {
		switch(content[j])
		 {
			case 0:
				return 0;
			case 1:
				h.data=content[++j];
				h.priority=content[++j];
				insert(a,h);
				cout<<endl;
				break;
			case 2:
				t=remove(a);
				if(t==-1000000)
					cout<<"EMPTY\n";
				break;
			case 3:
				if(peek(a)==-1000000)
					cout<<"EMPTY\n";
				break;
			case 4:
				el=content[++j];
				pr=content[++j];
				increase_priority(a,el,pr);
				cout<<endl;
				break;
			default:
				cout<<"INVALID DATA\n";
				break;
	 	 }
	 }


	delete(a);	
	return 0;
 }
