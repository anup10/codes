#include<iostream>
#include<fstream>

using namespace std;

int mod(int i,int j)
{
	if(i>j)
	return (i-j);
	else
	return (j-i);
}



int main()
{
	int size,range,i,j,k,s,sub;
	cout<<"Enter the size of i/p sequence :\n";
	cin>>size;
	int inp[size+1],sum[size+1][size+1],brk;
	cout<<"enter the inp sequence :\n";
	for(int i=1;i<size+1;i++)
	{
		cin>>inp[i];
		sum[i][i]=inp[i];
	}
	for(range=1;range<size;range++)
	{
		for(i=1;i<=size-range;i++)
		{
			
			j=i+range;
			sum[i][j]=sum[i][j-1]+inp[j];
			
		}
	}
	sub=99999;		
	for(k=1;k<size+1;k++)
	{
		s=mod(sum[1][k],sum[k+1][size]);
		if(s<=sub)
		{
			sub=s;
			brk=k;
		}
	}

	cout<<"partition occurs at : "<<brk<<endl;
	cout<<"sum of part1 is : "<<sum[1][brk]<<endl;
	cout<<"sum of part2 is : "<<sum[brk+1][size]<<endl;
	cout<<"|S1-S2|="<<sub<<endl;
	return 0;
}
		
				
					










