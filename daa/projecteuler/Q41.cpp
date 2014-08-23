#include <iostream>

using namespace std;

int Length(long a)
{
	int i=0;
	while(a>=1)
	{
		a=a/10;		 
		i++;
	}
	return i;
}
int isPan(long a, int len)
{
	bool chk[10]={0};
	chk[0]=1;
	int i;
	for(int j=len+1;j<10;j++)
		chk[j]=1;
	while(a>=1)
		{
			i=a%10;
			a=a/10;	
			if(chk[i]==1)
				return 0;
			chk[i]=1;
		}
	return 1;
}	


int main()
{
	bool primes[7654322]={0},flag=0;
	primes[0]=1;
	primes[1]=1;
	int len;
	long j,ans=0;
	for(long i=2;i<7654322;i++)
	{
		if(primes[i]==0)
		{
			len=Length(i);
			flag=isPan(i,len);
		
			if(flag==1 && ans<i)
				ans=i;
			j=2*i;
			while(j<7654322)
			{
				primes[j]=1;
				j+=i;
			}
		}
	}
	/*for(long i=123456;i<7654322;i++)
	{
		flag=0;
		for(j=2;j<(i/2+1);j++)
		{
			if( i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(ans<i && flag==0)
		{
			ans=i;
		}
	}*/
	cout<<ans<<endl;
	return 0;
}
			
			
		








