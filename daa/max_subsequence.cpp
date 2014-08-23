#include<iostream>
#include<fstream>

using namespace std;

int max2[2];

int *max(int inp[],int size)
{
	int max1=-99999;
	for(int i=1;i<size+1;i++)
	{
		if(max1<inp[i])
		{	max1=inp[i];
			max2[0]=inp[i];
			max2[1]=i;
		}
	}
	return max2;
}


	



void max_sub(int inp[],int size)
{
	int Sum=-99999999,range,i,j,sum1,*sum4;
	int initial=1,final=1;
	int sum[size+1][size+1];
	for(int i=1;i<size+1;i++)
	{
		for(int j=1;j<size+1;j++)
		{
			sum[i][j]=-9999999;
		}
	}
	for(int i=1;i<size+1;i++)
		sum[i][i]=inp[i];
	sum4=max(inp,size);
	Sum=*sum4;
	initial=final=*(sum4+1);
	cout<<Sum<<endl<<initial;
	for(range=1;range<size;range++)
	{
		for(i=1;i<=size-range;i++)
		{
			j=i+range;
			
			sum1= sum[i][j-1]+inp[j];
			if(sum1>sum[i][j-1])
			{
				
				sum[i][j]=sum1;
				
				if(sum1>Sum)
				{
					initial=i;
					final=j;
					Sum=sum1;
				}
			}	
			else
			{
				sum[i][j]=sum1;
				
			}
		}
	}
	cout<<"The subsequence starts at :"<<initial<<endl;
	cout<<"The subsequence ends at : "<<final<<endl;
	cout<<"The max sum of any subsequence is : "<<Sum<<endl;
}
	




int main()
{	
	int size;
	cout<<"Enter the length of i/p no. sequence :\n";
	cin>>size;
	int inp[size+1];
	cout<<"Enter the np. sequence :\n";
	for(int i=1;i<size+1;i++)
		cin>>inp[i];
	max_sub(inp,size);
	return 0;
}






	
