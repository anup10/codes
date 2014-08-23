#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	long i,n,m,x,y,ans;
	
	cin>>n;
	cin>>m;
	char ip[n];
	long b1;
	long b2;
	cin>>ip;
	while(m>0)
	{
		b1=0;
		b2=0;
		ans=0;
		cin>>x;
		x=x-1;
		for(i=0;i<x;i++)
		{
			if(((ip[x]-48)-(ip[i]-48))>0)
			{
				b1+=((ip[x]-48)-(ip[i]-48));
				
			}
			if(((ip[x]-48)-(ip[i]-48))<0)
			{
				b2+=((ip[x]-48)-(ip[i]-48));
				
			}
		}
		
		ans=b1-b2;
		
		cout<<ans<<endl;
		m--;
	}
	return 0;
}
			
		





