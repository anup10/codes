#include<iostream>
#include<cstdlib>

using namespace std;


void exchange(int array[],int i,int j)
{
	int temp;
	temp=array[j];
	array[j]=array[i];
	array[i]=temp;
}

int main()
{
	int n;
	cout<<"enter the size of array"<<endl;
	cin>>n;
	int array[n];
	cout<<"enter the elements"<<endl;
	for(int i=0;i<n;i++)
	cin>>array[i];
	int index_0=0,index_1=0,index_2=0;
	for(int i=0;i<n;i++)
	{
		if(array[i]==0)
		{
			exchange(array,i,index_0);
			index_0++;
		}
	}
	index_1=index_0;
	for(int i=index_1;i<n;i++)
	{
		if(array[i]==1)
		{
			exchange(array,i,index_1);
			index_1++;
		}
	}
	for(int i=0;i<n;i++)
	cout<<array[i]<<endl;
}	
