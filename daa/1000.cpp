#include <iostream>

using namespace std;

int main()
{
	int a[1000]={0};
	int b[1000]={0};
	int num[1000]={0};
	int carry=0,sum=0,i=0;
	int count=12;
	a[2]=1;
	a[1]=4;
	a[0]=4;
	b[1]=8;
	b[0]=9;
	cout<<num[999];
	while(num[999]==0)
		{
			count++;
			i=0;
			sum=0;
			carry=0;
			
			for(i=0;i<1000;i++)
			{
				
				sum = a[i]+b[i];
				sum += carry;
				carry=sum/10;
				num[i]=(sum%10);
			
				sum=0;
				
				
				
			}
		
			
			if(num[999]==0)
			{
			for(int p=0;p<=i;p++)
			b[p]=a[p];
			for(int q=0;q<=i;q++)
			{
			a[q]=num[q];
			num[1000]=0;
			}
			
			}
		}
		
	cout<<count<<endl;
	
	return 0;
}
		
		


