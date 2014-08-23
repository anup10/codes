#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>


using namespace std;

int CheckPanDigital(int a,int b,int c)
{	
	//stringstream ss;
	long ans;
	int chk[10]={0};
	int i,len=0;
	chk[0]=1;
	//ss<<a<<b<<c;
	//string s;
	//s=ss.str();
	//if(s.length()==9)
	//{
	//	ans=stol(s);
		while(a>=1)
		{
			i=a%10;
			a=a/10;	
			if(chk[i]==1)
				return 0;
			chk[i]=1;
			len++;
		}
		while(b>=1)
		{
			i=b%10;
			b=b/10;	
			if(chk[i]==1)
				return 0;
			chk[i]=1;
			len++;
		}
		while(c>=1)
		{
			i=c%10;
			c=c/10;	
			if(chk[i]==1)
				return 0;
			chk[i]=1;
			len++;
		}
		if(len==9)
			return 1;
	//}
	return 0;
}

int main()
{
	bool primes[10001]={0};
	int i,j,k,flag=0;
	long ans=0;
	primes[0]=1;
	primes[1]=1;
	/*for(i=2;i<10001;i++)
	{
		if(primes[i]==0)
		{
			j=2*i;
			while(j<10001)
			{
				primes[j]=1;
				j+=i;
			}
		}
	}*/
	
	for( i=100;i<10000;i++)
	{
		for(j=2;j<(i/2+1);j++)
		{
			if(i%j==0)
			{
				flag=CheckPanDigital(i,j,i/j);
					if(flag==1)
					{
						ans+=i;
						cout<<i<<endl;
						cout<<j<<endl;
						cout<<i/j<<endl;
						
						break;
					}
					
				
			}
			if(flag==1)
				break;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
