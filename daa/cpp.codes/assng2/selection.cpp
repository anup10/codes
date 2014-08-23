#include<iostream>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;
void sort(char a[][100],int n)
 {
	char temp[50];
	int pos;
	
	for(int i=0;i<n-1;i++)
	 {
		pos=i;
		for(int j=i+1;j<n;j++)
			if(strcmp(a[pos],a[j])>0)
				pos=j;
		if(pos!=i)
		 {
			strcpy(temp,a[i]);
			strcpy(a[i],a[pos]);
			strcpy(a[pos],temp);
		 }
	 }

 }
int main()
 {
	fstream fin;
	int n;
	fin.open("input.txt",ios::in);
	fin>>n;
	char a[n][100];
	int i=0;
	while(!fin.eof())
	 {
		fin>>a[i];
		i++;
	 }
	fin.close();
	cout<<"THE DATA FROM THE INPUT FILE IS : \n";
	for(i=0;i<n;i++)
		cout<<a[i]<<endl;
	clock_t t;
	t=clock();
	sort(a,n);
	t=clock()-t;
	fstream fout;
	fout.open("output.txt",ios::out);
	for(i=0;i<n;i++)
		fout<<a[i]<<endl;
	fout<<"RUNNING TIME : ";
	fout<<(float(t)/CLOCKS_PER_SEC);
	fout<<" SEC";
	fout.close();
		
	return 0;
 }
