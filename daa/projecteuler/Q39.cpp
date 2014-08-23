#include <iostream>

using namespace std;

int main()
{
	int numberOfSolution,max=0;
	long ans;
	for(long p=3;p<1001;p++)
	{
		numberOfSolution=0;
		for(long a=1;a<p/3;a++)
		{
			if((p*(p-2*a))%(2*(p-a))==0)
			{
				numberOfSolution++;
			}
		}
		if(numberOfSolution>max)
		{
			max=numberOfSolution;
			ans=p;
		}
	}
	cout<<max<<endl;
	cout<<ans<<endl;
	return 0;
}
	
