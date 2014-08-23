#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int size,range,i,j,k,c;
	cout<<"Enter the length of matrices\n";
	cin>>size;
	int dimen[size+1];
	cout<<"Enter the dimensions of the matrices : \n";
	for (int i=0;i<size+1;i++)
		cin>>dimen[i];
	int cost[size+1][size+1],brk[size+1][size+1];
	for (int i=0;i<size+1;i++)
	{
		for (int j=0;j<size;j++)
		{
			cost[i][j]=999999999;
			brk[i][j]=0;
		}
	}
	for(int i=1; i<size+1;i++)
		cost[i][i]=0;	
	for(range=1;range<size;range++)
	{
		for(i=1;i<=size-range;i++)
		{
			j=i+range;
			for(k=i;k<j;k++)
			{
				c=cost[i][k]+dimen[i-1]*dimen[k]*dimen[j]+cost[k+1][j];
				if(c<cost[i][j])
				{
					cost[i][j]=c;
					brk[i][j]=k;
				}
			}
		}
	}
	cout<<endl<<cost[1][size];
	return 0;
}
