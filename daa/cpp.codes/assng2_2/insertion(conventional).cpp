
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<ctime>
#include<fstream>
#include<ctime>

using namespace std;

void sort(int a[],int n)
 {
	fstream fout;
	int j;

	for(int i=1;i<n;i++)                             //NORMAL INSERTION SORT
	 {
		int temp=a[i];
		for(j=i-1;j>=0&&a[j]>temp;j--)
				a[j+1]=a[j];
		
		a[j+1]=temp;
		
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
	int a[n];
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

	sort(a,n);

	t=clock()-t;



	cout<<"\nTHE SORTED ARRAY IS \n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;

	fout.open("output1.txt",ios::out);
	for(int i=0;i<n;i++)
		fout<<a[i]<<endl;
	fout<<"RUNNING TIME : ";
	fout<<(float(t)/CLOCKS_PER_SEC);
	fout<<" SEC";
	fout.close();
	return 0;
 }
