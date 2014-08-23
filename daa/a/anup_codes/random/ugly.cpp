#include<iostream>
#include<cstdlib>

using namespace std;

int funct(int n);
int min(int a,int b);

int main()
{
 int n,l;
 cout<<"enter the nth no. "<<endl;
 cin>>n;
 l=funct(n);
 cout<<"the nth ugly no. is :	"<<funct(n)<<endl;
 
}


int funct(int n)
{
int array[n];
array[0]=1;
int x=0,y=0,z=0;
int k=1;
int min1;

while(k<n)
{
	min1=min(array[x]*2,min(array[y]*3,array[z]*5));
	array[k++]=min1;
	if(min1 == array[x]*2)
		x++;		
	if(min1 == array[y]*3)
		y++;
	if(min1 == array[z]*5)
		z++;
}
return (array[n-1]);
}


int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}








