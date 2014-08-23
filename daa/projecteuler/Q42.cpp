#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	char ip[100];
	bool record[1000000]={0};
	int sum=0,len,value;
	ifstream infile;
	infile.open("words.txt");
	long n=1,ans=0;
	while((n*(n+1))/2<1000000)
	{
		record[(n*(n+1))/2]=1;
		n++;
	}
		
	if(infile.is_open())
	{
		
		while(!infile.eof())
		{
			sum=0;
			infile>>ip;
			cout<<ip<<endl;
			len=strlen(ip);
			for(int i=0;i<len;i++)
			{
				value=ip[i]-64;
				sum+=value;
			}		
			if(record[sum]==1)
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}












