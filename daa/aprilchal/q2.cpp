#include <iostream>

using namespace std;




long long lca(long long a, long long b)
{
	long long temp;
	if(b>a)
	{
		temp=a;
		a=b;
		b=temp;
	}
	while(b!=a)
	{
		while(a>b)
		{
			a=a/2;
		}
		while(b>a)
		{
			b=b/2;
		}
	}
	return b;
}	
		
		
	



int main()
{
	long long i,j,n,l=0,r=0,temp,count=0,t;
	cin>>n;
	while(n>0)
	{
		count=0;
		cin>>i;
		cin>>j;
		temp=lca(i,j);
		while(i!=temp)
		{
			i=i/2;
			count++;
		}
		while(j!=temp)
		{
			j=j/2;
			count++;
		}
		cout<<count<<endl;
		n--;
	}
	return 0;
}
		
		
	
	
	
	
	
	
	
	
	
	
	
