#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int size,range,i,j,k,length=1,initial=1,final=1;
	cout<<"Enter the size of given list of numbers\n";
	cin>>size;
	int inp[size+1],len[size+1][size+1];
	cout<<"Enter the i/p\n";
	for(int i=1;i<size+1;i++)
	{
		cin>>inp[i];
		len[i][i]=1;
	}
	
	for(range=1;range<size;range++)
	{
		for(i=1;i<=size-range;i++)
		{
			j=i+range;
			if(len[i][j-1]==0)
			{
				len[i][j]=0;
			}
			else if(inp[j-1]<inp[j])
			{
				len[i][j]=len[i][j-1]+1;
				if(length<len[i][j])
				{
					length=len[i][j];
					initial=i;
					final=j;
				}
			}
			else
			{
				len[i][j]=0;
			}
		}
	}
	
	cout<<"The subsequence starts at : "<<initial<<endl;
	cout<<"The subsequence ends at : "<<final<<endl;
	cout<<"The length of longest subsequence is : "<<length<<endl;

	return 0;
}



















				





