#include <iostream>

using namespace std;

int main()
{
	long n,i=0,p1,p2,q1,q2,len;
	long j;
	bool pent[1000000]={0};
	n=1;
	int flag=1;
	while(1)
	{
		i=(n*(3*n-1))/2;
		if(i>=1000000)
			break;
		else
			pent[i]=1;
		if(i<200)
		cout<<i<<endl;
		n++;
	}
	len=n-1;
	cout<<len<<endl;
	for( j=1;j<1000000;j++)
	{
		
		n=1;
		while((n+j)<len)
		{
			p1=(n*(3*n-1))/2;
			p2=((n+j)*(3*(n+j)-1))/2;
			if(p1>1000000 || p2>1000000)
				break;
			q1=p1+p2;
			q2=p2-p1;
			if((q1>=1000000) || (q2>=1000000))
				break;
			else if(pent[q1]==1 && pent[q2]==1)
			{
				
				flag=0;
				break;
			}
			n++;
		}
		if(flag==0)
			break;
	}
	cout<<j<<endl;
	cout<<p1<<endl;
	cout<<p2<<endl;
	cout<<q1<<endl;
	cout<<q2<<endl;
	return 0;
}
























