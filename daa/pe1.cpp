#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int i,j,k1,k2,count=0;
	j=i=1;
	
	while(k1<1000 || k2<1000)
	{
		k1=i*3;
		if(k1<1000 )
		{
			
				i++;
				count=count+k1;
			
			
		}
		k2=j*5;
		if(k2<1000)
		{
			if(k2%3 !=0)
			{
				j++;
				count=count+k2;
			}
			else
			{
				j++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}		
		


		
