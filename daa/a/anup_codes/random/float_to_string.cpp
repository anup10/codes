#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main()
{	
	float a,deci;
	int b=0,c,sig=0,t,p,con;
	
	cout<<"enter the floating point number upto 4 decimal places"<<endl;
	cin>>a;
	con=(int)a;
	
	//cout<<deci;

	if(a<0)
	{
		sig=1;
		c=-a;
		deci=-(a+con);
	}
	else
	{
		c=a;
		deci=a-con;
	}
	int i=10,j,length;
	while(c>0)
	{			
		c=c/10;
		b++;
	}
	char str[b];
	char str1[5];
	//c=a;
	if(a<0)
	{
		sig=1;
		c=-a;
		
	}
	else
	{
		c=a;
	}
	t=b-1;
	for(j=t;j>=0;j--)
	{
		p=c%10;
		
		c=c/10;
		str[j]=p+48;
	}
	cout<<"the int in string format is:"<<endl;
	if(sig==1)
	cout<<"-";

	for(j=0;j<b;j++)
	{
		cout<<str[j];
	}
	str1[0]='.';
	for(j=1;j<=4;j++)
	{
		p=(int)(deci*10);
		//cout<<endl<<p;
		deci=deci*10-p;
		str1[j]=p+48;
	}
	for(j=0;j<=4;j++)
	cout<<str1[j];

	return 0;
}
		

