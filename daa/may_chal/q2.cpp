#include <iostream>

using namespace std;

int main()
{
	long long k,max=0,max1=0;
	long n;
	cin>>n;
	cin>>k;
	long long ip[n],ip1[n];
	for(long i=0;i<n;i++)
	{
		cin>>ip[i];
		if(ip[i]>max)
			max=ip[i];
	}
	if(k==0)
	{
		for(long i=0;i<n;i++)
		{
			cout<<ip[i]<<" ";
		}
	}
	else
	{
		for(long i=0;i<n;i++)
		{
			ip1[i]=max-ip[i];
			if(ip1[i]>max1)
				max1=ip1[i];
		}
		if(k%2==1)
		{
			for(long i=0;i<n;i++)
			{
				cout<<ip1[i]<<" ";
			}
		}
		else
		{
			for(long i=0;i<n;i++)
			{
				ip[i]=max1-ip1[i];
				cout<<ip[i]<<" ";
			}
		}
	}
	
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		













