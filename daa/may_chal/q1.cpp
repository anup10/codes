#include <iostream>

using namespace std;

int main()
{
	long long ip,t;
	cin>>ip;
	if(ip%3==0)
	{
		cout<<"yes"<<endl;	
	}
	else 
	{
		t=ip%6;
		if(t==1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
