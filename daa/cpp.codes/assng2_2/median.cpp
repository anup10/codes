#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<fstream>

using namespace std;

int partition(int a[],int p,int r)
 {
	int t;
	int x=a[r];
	int i=p-1;
	for(int j=p;j<=(r-1);j++)
	 {	
		if(a[j]<x)
		 {
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		 }
	 }
		t=a[i+1];
		a[i+1]=a[r];
		a[r]=t;
			
	return i+1;
		
 }

int randomized_partition(int a[],int p,int r)
 {
	int i,t;
	srand((unsigned)time(0));
	i=(rand()%r)+1;
	if(i<p)
		i+=p;
	t=a[i];
	a[i]=a[r];
	a[r]=t;
	return partition(a,p,r);	
 }



int randomized_select(int a[],int p,int r,int i)
 {

	static int ctr=0;
	ctr++;
	if(p==r)
		{cout<<ctr;
		return a[p];}
	int q=randomized_partition(a,p,r);
	int k=q-p+1;
	if(i==k)
		{cout<<ctr;return a[q];}
	else if(i<k)
		return randomized_select(a,p,q-1,i);
	else
		return randomized_select(a,q+1,r,i-k);
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

	int result=randomized_select(a,0,n-1,(n/2)+1);

	t=clock()-t;

	cout<<"\n THE MEDIAN ELEMENT IS : "<<result;
	cout<<"\n THE RUNNING TIME IS "<<(float(t)/CLOCKS_PER_SEC)<<" SEC";
	delete a;
	return 0;
 }
