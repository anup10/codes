#include<iostream>
#include<climits>
#include<fstream>
#include<cmath>

using namespace std;

int m;
int h(int key,int i)
 {
	return ((key+i+(int(pow(i,2))))%m);
 }

int insert(int T[],int key)
 {
	int i=0;
	int j;
	while(i!=m)
	 {
		j=h(key,i);
		if(T[j]==INT_MIN)
		 {
			T[j]=key;
			return j;
		 }
		else
		 {
			cout<<j<<"  ";
			i++;
		 }
	 }
	return INT_MIN;
 }

int search(int T[],int key)
 {
	int i=0,f=0;
	int j=h(key,i);
	while(i!=m&&T[j]!=INT_MIN)
	 {
		f=1;
		j=h(key,i);
		if(T[j]==key)
			return j;
		else
		 {
			cout<<j<<"  ";
			i++;
		 }
	 }
	if(f==0)
		cout<<j;
	return INT_MIN;
 }

int main()
 {
	int i=0;
	fstream fin;
	fin.open("input.txt",ios::in);
	fin>>m;


	int *content=new int[100];

	while(!fin.eof())
	 {
		fin>>content[i];
		if(content[i]==0)
			break;
	 	i++;
	 }
	fin.close();

	int T[m],x;
	for(int k=0;k<m;k++)
	 {
		T[k]=INT_MIN;
	 }

	
	for(int j=0;j<=i;j++)
	 {
		switch(content[j])
		 {
			case 0:
				return 0;
			case 1:
				x=insert(T,content[++j]);

				if(x==INT_MIN)
					cout<<"\nHASH-TABLE OVERFLOW";
				else
					cout<<x;
				cout<<endl;
				break;
			case 2:
				x=search(T,content[++j]);
				if(x==INT_MIN)
					cout<<" NOT FOUND ";
					else
					cout<<x<<" FOUND ";
				cout<<endl;
				break;
			default:
				cout<<"INVALID DATA\n";
				break;
	 	 }
	 }	

	return 0;
 }
