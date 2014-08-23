#include <iostream>

using namespace std;

int min(int a,int b)
{
	return (a<b ? a : b);
}

int main()
{
	int range,i,j,n,test;
	cin>>n;
	long ip[n],no;
	long c[n][n],count;
	
	for(int k=0;k<n;k++)
	cin>>ip[k];
	for(int p=0;p<n;p++)
	c[p][p]=ip[p];
	for(range=1;range<n;range++)
	{
		for(i=0;i<n-range;i++)
		{
			j=i+range;
			c[i][j]=min(c[i][j-1],c[i+1][j]);
		}
	}
	cin>>test;
	while(test>0)
	{
		cin>>no;
		count=0;
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(c[i][j]==no)
				count++;
			}
		}
		test--;
		cout<<count<<endl;
	}
	return 0;
}
	















