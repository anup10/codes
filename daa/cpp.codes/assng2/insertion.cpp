
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<ctime>
#include<fstream>


using namespace std;

void sort(int a[],int n)
 {
	int j;

	for(int i=1;i<n;i++)                             //MODIFIED INSERTION SORT
	 {
		int temp=a[i];
		int f=0;
		int l=i-1;
		int pos=i;
		while(f<=l) 
		 {
			int mid=(f+l)/2;
			if (a[mid]>temp)
			 {
				if(a[mid-1]<temp)
				 {
					pos=mid;
					break;	
				 }
				else
					l=mid-1;
			 }
			else
				f=mid+1;
		 }
			if(pos!=i)
			 {
				for(j=i-1;j>=pos;j--)
					a[j+1]=a[j];
				a[j+1]=temp;
			 }

			
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

	fout.open("output2.txt",ios::out);
	for(int i=0;i<n;i++)
		fout<<a[i]<<endl;
	fout<<"RUNNING TIME : ";
	fout<<(float(t)/CLOCKS_PER_SEC);
	fout<<" SEC";
	fout.close();
	return 0;
 }
