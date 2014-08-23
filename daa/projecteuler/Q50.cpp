#include <iostream>

using namespace std;

int main()
{
	bool primes[1000000]={0};
	
	primes[0]=primes[1]=1;
	for(long i=2;i<1000000;i++)
	{
		if(primes[i]==0)
		{
			j=2*i;	
			while(j<1000000)
			{
				primes[j]=1;
				j+=i;
			}
			
		}
	}

	for(long i=999999;i>0;i--)
	{
		if(primes[i]==0)
		{
			sum=0;
			for(long j=i-1;j>0;j--)
			{
				if(primes[j]==0 && sum<i)
				{
					sum+=j;
					if(sum




















