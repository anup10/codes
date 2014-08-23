#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include<ctime>

using namespace std;

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
void max_heapify(int a[],int i,int n)
 {	
	int t,largest;
	int l=left(i);
	int r=right(i);
	if((l<n)&&(a[l]>a[i]))
		largest=l;
	else
		largest=i;
	if((r<n)&&(a[r]>a[largest]))
		largest=r;
	if(largest!=i)
	 {
		t=a[i];
		a[i]=a[largest];
		a[largest]=t;
		max_heapify(a,largest,n);
	 }
	 		
 }
void build_max_heap(int a[],int n)
 {
	for(int i=(n/2);i>=0;i--)
		max_heapify(a,i,n);
 }
void heapsort(int a[],int n)
 {
	int t;
	build_max_heap(a,n);
	for(int i=n-1;i>=1;i--)
	 {
		t=a[0];
		a[0]=a[i];
		a[i]=t;
		n--;
		max_heapify(a,0,n);
	 }
 }
int main()
 {

	fstream fout;
	int n;
	char name[50];
	cout<<"\n ENTER THE NAME OF THE FILE : ";
	gets(name);
	fout.open(name,ios::out);

	cout<<"\n ENTER THE SIZE  : ";
	cin>>n;
	fout<<n;

	int ri;
	srand((unsigned)time(0));
	for(int i=0;i<n;i++)
	 {
		ri=rand();
		fout<<endl<<ri;
	 }

	fout.close();
	
	fstream fin;
	fin.open(name,ios::in);
	fin>>n;
	int *a=new int[n];
	int index=0;
	while(!fin.eof())
	 {
		fin>>a[index];
		index++;
	 }

	fin.close();
	cout<<"\n THE INPUT TO FROM THE FILE IS \n";
	for(int i=0;i<n;i++)
	 {
		cout<<a[i]<<endl;
	 }

	clock_t t;
	t=clock();

	heapsort(a,n);

	t=clock()-t;

	cout<<"\nTHE SORTED ARRAY IS \n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	fout.open("output.txt",ios::out);
	for(int i=0;i<n;i++)
		fout<<a[i]<<endl;

	fout<<"RUNNING TIME : ";
	fout<<(float(t)/CLOCKS_PER_SEC);
	fout<<" SEC";
	fout.close();
	delete(a);
	
	return 0;
 }
