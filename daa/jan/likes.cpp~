#include <iostream>

using namespace std;

int main()
{
	long long l,d,s,c,t,di,flag,i;
	cin>>t;
	while(t>0)
	{
		flag=0;
		cin>>l;
		cin>>d;
		cin>>s;
		cin>>c;
		d--;
		di=s;
		for( i=d;i>0;i--)
		{
			di=di+di*c;
			if(di>=l)
			{
				flag=1;
				break;
			}
		}
		if(flag==1 || di>=l)
		cout<<"ALIVE AND KICKING\n";
		else
		cout<<"DEAD AND ROTTING\n";
		t--;
	}
	
	return 0;
}
	
