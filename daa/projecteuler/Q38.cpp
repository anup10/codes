#include <iostream>
#include <cstdlib>

using namespace std;

int isPan(int a,int b)
{	
	//stringstream ss;
	long ans;
	int chk[10]={0};
	int i,len=0;
	chk[0]=1;
	//ss<<a<<b<<c;
	//string s;
	//s=ss.str();
	//if(s.length()==9)
	//{
	//	ans=stol(s);
		while(a>=1)
		{
			i=a%10;
			a=a/10;	
			if(chk[i]==1)
				return 0;
			chk[i]=1;
			len++;
		}
		while(b>=1)
		{
			i=b%10;
			b=b/10;	
			if(chk[i]==1)
				return 0;
			chk[i]=1;
			len++;
		}
		if(len==9)
			return 1;
}


int main()
{
	int i,j;
	int a1,a2,a3,a4,a5,len,flag;
	long ans=0;
	i=9234;
	for(i=9234;i<9488;i++)
	{
		a1=i;
		
		a2=i*2;
		flag=isPan(a1,a2);
		if(flag==1)
		{
			
			if(ans<a1*100000+a2)
			{
				ans=a1*100000+a2;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}





















