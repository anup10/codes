#include <iostream>
#include <cmath>

using namespace std;

int is_prime(long num)
{
	long i;
	if(num<0)
	num*=-1;
	if(num==2 || num==3 || num==5)
	return 1;
	for(i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
		return 0;
	}
	return 1;
}

int main()
{
	int i,j;
	long max_prod,max=0,no_primes=0,num,n=0;
	for(i=-999;i<1000;i++)
	{
		
		no_primes=0;
		for(j=-999;j<1000;j++)
		{
			n=0;
			num=(pow(n,2)+(i*n)+j);
			no_primes=0;
			
			while(is_prime(num))
			{
				no_primes++;
				n++;
				num=(pow(n,2)+(i*n)+j);
			}
			if(no_primes>max)
			{
				max=no_primes;
				max_prod=i*j;
				
				
			}
			
		}
	}
	cout<<max_prod;
	cout<<endl<<max;
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	