#include <iostream>
#define PRIME_SIZE 781251
#define FACTORS_SIZE 1562501

using namespace std;

int main()
{
	
	long factors[FACTORS_SIZE];
	long index[118540];
	long long ans;
	bool primes[FACTORS_SIZE]={0};
	long i,t,n,count,count1,k,curr_prime,dum,fact_count;
	//to find all primes upto fators_size
	primes[0]=1;
	primes[1]=1;
	
	for(long i=2;i<FACTORS_SIZE;i++)
	{
		if(primes[i]==0)
		{
			count++;
			for(long curr_prime=i*2;curr_prime<FACTORS_SIZE;curr_prime=curr_prime+i)
			{
				primes[curr_prime]=1;
			}
		}
		
	}
	
	//kepping track of the indices of the prime factors
	
	factors[0]=0;
	factors[1]=1;
	//possible no of matrices for a given product i is given by factors[i-1]
	for(long i=2;i<FACTORS_SIZE;i++)
	{
		curr_prime=2;
		fact_count=0;
		count1=0;
		if(primes[i]==0)
		{
			factors[i]=factors[i-1]+2;
		}
		else
		{
			dum=i;
			while(primes[dum]==1 && dum!=1)
			{
				if(dum%curr_prime==0)
				{
					while(dum%curr_prime==0)
					{
						count1++;
						dum=dum/curr_prime;
					}
					index[fact_count]=count1;
					
				}
				k=curr_prime+1;
				while(k<PRIME_SIZE && primes[k]!=0)
				{
					k++;
				}
				curr_prime=k;
				count1=0;
				fact_count++;
			}
					
			if(primes[dum]==0)
			{
				index[fact_count]=1;
				fact_count++;
			}
			count1=1;
			for(long j=0;j<fact_count;j++)
			{
				count1*=(index[j]+1);
				index[j]=0;
			}
			factors[i]=factors[i-1]+count1;
		}
	}
					
	cin>>t;
	while(t>0)
	{
		cin>>n;
		ans=0;
		
		for(i=1;i<=n/2;i++)
		{
			if((n-i)!=i)
			ans+= factors[((n-i)*i-1)]*2;
			else
			ans+=factors[((n-i)*i-1)];
		}
		cout<<ans<<endl;
		t--;
	}
	
	return 0;
}
			
	















