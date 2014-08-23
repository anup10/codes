
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<ctime>
#include<fstream>


using namespace std;

int binary(int ar[],int p,int q,int e)
{
int mid;


if(ar[p]>e)
return p;


mid=(p+q)/2;

if(ar[mid]<=e&&ar[mid+1]>=e)
return (mid+1);
else
if(ar[mid]<e)
binary(ar,mid+1,q,e);
else if (ar[mid]>e)
binary(ar,p,mid-1,e);


}

void sort(int a[],int n)
 {
	int j;

	for(int i=1;i<n;i++)                             //MODIFIED INSERTION SORT
	 {
		int temp=a[i];
		int f=0;
		int l=i-1;
		int flag=0;
		int pos=binary(a,0,i-1,temp);
	

			for(j=i-1;j>=pos;j--)
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
		ri=rand()%(n+1)-rand()%(n+1);
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
