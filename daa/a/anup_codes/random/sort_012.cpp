#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main()
{
	int size,count_0=0,count_1=0,count_2=0;
	int j=0;
	cout<<"enter the size of array"<<endl;
	cin>>size;
	int in_array[size],out_array[size];
	cout<<"give the input array"<<endl;
	
	for(int i=0;i<size;i++)
	in_array[i]=0;

	for(int i=0;i<size;i++)
	out_array[i]=0;

	for(int i=0;i<size;i++)
	cin>>in_array[i];
	
	for(int i=0;i<size;i++)
	{
		if(in_array[i]==0)
		count_0++;

		if(in_array[i]==1)
		count_1++;
		
		if(in_array[i]==2)
		count_2++;
	}
	

	while(count_0>0)
	{
		out_array[j++]=0;
		count_0--;
	}
	while(count_1>0)
	{
		out_array[j++]=1;
		count_1--;
	}
	while(count_2>0)
	{
		out_array[j++]=2;
		count_2--;
	}
	cout<<"sorted output is :"<<endl;
	for(int i=0;i<size;i++)
	cout<<out_array[i]<<endl;
}






















	
