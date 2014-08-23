#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include<iomanip>
#include<ctime>

using namespace std;

void radixsort(int a[],int n)
 {
	int i,m=a[0],exp=1;
	int *b=new int[n];
	for(i=0;i<n;i++)
	 {
		if(a[i]>m)
			m=a[i];
	 }
	while((m/exp)>0)
	 {
		int bucket[10] ={0};
		for (i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;

    		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i-1];

		for (i = n - 1; i >= 0; i--)
		      b[--bucket[a[i] / exp % 10]] = a[i];

		for (i = 0; i < n; i++)
		      a[i] = b[i];

		exp *= 10;
	 }
	delete(b);
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
		ri=((rand())%4294967295)+1;
		fout<<endl<<hex<<ri;
	 }

	fout.close();


	fstream fin;
	fin.open(name,ios::in);
	fin>>n;
	int *a=new int[n];
	int index=0;
	while(!fin.eof())
	 {
		fin>>hex>>a[index];
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

	radixsort(a,n);

	t=clock()-t;

	cout<<"\nTHE SORTED ARRAY IS \n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	fout.open("output.txt",ios::out);
	for(int i=0;i<n;i++)
		fout<<hex<<a[i]<<endl;

	fout<<"RUNNING TIME : ";
	fout<<(float(t)/CLOCKS_PER_SEC);
	fout<<" SEC";
	fout.close();
	delete(a);
	return 0;
 }
