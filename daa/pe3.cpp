#include <iostream>
using namespace std;

int is_prime(long long int i)
{	
	int flag=0;
	for(long long int j=3;j<=(i/2);j++)
	{
		if(i%j==0)
		{
			flag=1;
			cout<<"exit"<<endl;
			break;
			
		}
	}
	if(flag==1)
	return 0;
	else
	return 1;
}

int main() {
	long long int ip=600851475143;
	long long int ip1=ip/2;
	long long int i;
	for( i=ip1;i>=11;i--)
	{
		if(i%2 !=0)
		{
			if(ip%i==0)
			{
				if(is_prime(i))
				break;
			}
		}
	}
	cout<<i;
	return 0;
}
