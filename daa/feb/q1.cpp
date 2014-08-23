#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	long small[26],cap[26],dig[10],len;
	int test,ind;
	long count=0,j;
	
	char ip[10000];
	cin>>test;
	
	while(test>0)
	{
		
		for(int i=0;i<26;i++)
		{
			small[i]=cap[i]=0;
			if(i<10)
			dig[i]=0;
		}	
		count=0;
		cin>>ip;
		len=strlen(ip);
		j=0;
		while(j<len)
		{
				
			if(97<=ip[j] && ip[j]<=122)
			{
				ind=ip[j]-97;
				small[ind]++;
			}
			if(65<=ip[j] && ip[j]<=90)
			{
				ind=ip[j]-65;
				cap[ind]++;
				
			}
			if(48<=ip[j] && ip[j]<=57)
			{
				ind=ip[j]-48;
				dig[ind]++;
				
			}
			j++;
			
		}
		cin>>ip;
		len=strlen(ip);
		j=0;
		while(j<len)
		{
			
			if(97<=ip[j] && ip[j]<=122)
			{
				ind=ip[j]-97;
				if(small[ind]!=0)
				{
					small[ind]--;
					count++;
				}
			}
			if(65<=ip[j] && ip[j]<=90)
			{
				ind=ip[j]-65;
				if(cap[ind]!=0)
				{
					cap[ind]--;
					count++;
				}
				
			}
			if(48<=ip[j] && ip[j]<=57)
			{
				ind=ip[j]-48;
				if(dig[ind]!=0)
				{
					dig[ind]--;
					count++;
				}
				
			}
			j++;
		}
		cout<<count<<endl;
		test--;
	}
	return 0;
}	

			
		
	
	
	
	
	
	
	
	
	
	
	
	
	
