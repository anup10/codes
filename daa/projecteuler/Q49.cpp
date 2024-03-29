#include <iostream>

using namespace std;

int hasSameDigits(int i,int k)
{
	int a1[10]={0};
	int a2[10]={0};
	int a;
	while(i>=1)
	{
		a=i%10;
		a1[a]=1;
		i/=10;
		
	}
	
	while(k>=1)
	{
		a=k%10;
		a2[a]=1;
		k/=10;
		
	}
	for(int a=0;a<10;a++)
	{
		if(a1[a]!=a2[a])
			return 0;
	}
	return 1;
}
		
int hasSequence(int i,int j,int k)
{
	return ((k-j)==(j-i));
}

int main()
{
	bool primes[10000]={0};
	int count=0;
	long j,i,k,l;
	int ans[12],r,q,a=0,flag=0;
	primes[0]=primes[1]=1;
	for(int i=2;i<10000;i++)
	{
		if(primes[i]==0)
		{
			j=2*i;	
			while(j<10000)
			{
				primes[j]=1;
				j+=i;
			}
			
		}
	}
	
	for( i=1000;i<10000;i++)
	{
		if(primes[i]==0 && i!=1487)
		{
			//cout<<i<<endl;
			for( k=i+1;k<10000;k++)
			{
				if(primes[k]==0 && hasSameDigits(i,k))
				{
					for( l=k+1;l<10000;l++)
					{
						if(primes[l]==0 && hasSameDigits(k,l))
						{
							if(hasSequence(i,k,l))
							{
								flag=1;
								break;
							}
						}
					}
					if(flag==1)
						break;
				}
			}
			if(flag==1)
				break;
		}
	}
	cout<<i<<endl;
	cout<<k<<endl;
	cout<<l<<endl;
	ans[a++]=i/1000;
	i=i%1000;
	ans[a++]=i/100;
	i=i%100;
	ans[a++]=i/10;
	i=i%10;
	ans[a++]=i;
		
	
	ans[a++]=k/1000;
	k=k%1000;
	ans[a++]=k/100;
	k=k%100;
	ans[a++]=k/10;
	k=k%10;
	ans[a++]=k;
	
	
	ans[a++]=l/1000;
	l=l%1000;
	ans[a++]=l/100;
	l=l%100;
	ans[a++]=l/10;
	l=l%10;
	ans[a++]=l;
						
	for(int i=0;i<12;i++)
	cout<<ans[i];
	cout<<endl;
	
	return 0;
}					
						
						
						
						
						
						
						
						
						
						
						
						















































