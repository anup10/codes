#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int x,y,z,t,i,a,j,ans;
	int primes[2004]={0};
	primes[0]=primes[1]=1;
	
	for(i=2;i<2004;i++)
	{
		if(primes[i]==0)
		{
			a=2*i;
			while(a<2004)
			{
				primes[a]=1;
				a=a+i;
			}
		}
	}
	
	cin>>t;
	while(t>0)
	{
		cin>>x;
		cin>>y;
		i=x+y;
		j=i+1;
		while(primes[j]!=0)
		{
			j++;
		}
		ans=j-i;
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
