#include<iostream>
#include<fstream>

using namespace std;



int main()
{
	fstream fin("inp.txt");
	int ip[3],len=0,range,i,j=0,x;
	
	
	while(!fin.eof())
	{
		fin>>(ip[len]);
		len++;
	}
	cout<<len<<endl;
	int cost[len-1][len-1];
	int last[len-1][len-1];
	
	for(int k=0;k<len-1;k++)
	{
		cost[k][k]=1;
		last[k][k]=k;
		
	}
	for(range=1;range<len-1;range++)
	{
		for(i=0;i<len-range-1;i++)
		{
			j=i+range;
			if((ip[j])<=(ip[last[i][j-1]])) 
			{
				cost[i][j]=cost[i][j-1];
				last[i][j]=last[i][j-1];
			}
			else
			{
				cost[i][j]=cost[i][j-1]+1;
				last[i][j]=j;
			}
		}
	}
	x=len-2;
	while(x>=0&&last[0][x]>=0)
	{
		cout<<(ip[last[0][x]])<<endl;
		if(x==0)
			break;
		x=(last[0][(last[0][x])-1]);
	}

	
	return 0;
}
