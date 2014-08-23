#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<cstdio>

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



void quicksort(int a[],int p,int r)
 {
	if(p<r)
	 {
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
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



	int p=0;
	int r=n-1;

	clock_t t;
	t=clock();


	quicksort(a,p,r);

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
