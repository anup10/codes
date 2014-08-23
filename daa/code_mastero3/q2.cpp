#include <iostream>
#include <cstdlib>

using namespace std;


void PrintPre(long array[],int str, int end)
{
	
	int mid;
	if(str>end)
		return;
	if(str==end)
	{
		cout<<array[str]<<" ";
		return;
	}
	mid=(str+end)/2;
	cout<<array[mid]<<" ";
	PrintPre(array,str,mid-1);
	PrintPre(array,mid+1,end);
	return ;
}




int main()
{
	long t,n;
	long *array;
	cin>>t;
	while(t>0)
	{
		cin>>n;
		array= new long[n];
		for(int i=0;i<n;i++)
			cin>>array[i];
		PrintPre(array,0,n-1);
		cout<<endl;
		t--;
	}
	return 0;
}
