#include <iostream>


using namespace std;

long max(long a,long b)
{
	return (a>b ? a:b);
}

long min(long a,long b)
{
	return (a<b ? a:b);
}

int main()
{
	long hash[1000000]={0};
	long n,k,t,mid,rem,ans=1000000,ans1=-1;
	cin>>n;
	cin>>k;
	long ip[n];
	if(n%2==0)
	mid=n/2;
	else
	mid=(n/2)+1;
	for(long i=0;i<n;i++)
	{
		cin>>t;
		ip[i]=t;
		if((i+1)<=mid)
		{
			if(hash[t-1]!=0)
			hash[t-1]=hash[t-1];
			else
			hash[t-1]=i+1;
		}
		else
		{
			if(hash[t-1]!=0)
			hash[t-1]=min(n-i,hash[t-1]);
			else
			hash[t-1]=n-i;
		}
	}
	for(long i=0;i<n;i++)
	{
		t=ip[i];
		rem=k-t;
		if(rem>0 && hash[rem-1]!=0 && rem!=t)
		{
			ans=min(ans,(max(hash[t-1],hash[rem-1])));
		}
	}
	if(ans==1000000)
	cout<<ans1;
	else
	cout<<ans;
	return 0;
}
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
