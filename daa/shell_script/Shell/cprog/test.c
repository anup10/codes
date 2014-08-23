#include<stdio.h>
void quickSort(long array[],int i,int j);

void main()
{
int i,tc,j,n;
long long sum=0;
scanf("%d",&tc);
while(tc>0)
{
	sum=0;
	scanf("%d",&n);
	long array[n];
	for(i=0;i<n;i++)
	{
		scanf("%lu",&array[i]);
	}	
	quickSort(array,0,n-1);
	
	for(i=n-1;i>=0;i--)
	{
		sum=sum+array[i];
	}
	for(i=n-1;i>=2;i--)
	{
		sum=sum-(long long)array[i];
		if(array[i]<sum)
		{
			break;
		}
	}
	if(i<=1)
	{
		i=-1;
	}
	else
	{
		i=i+1;
	}
	printf("%d\n",i);
	tc--;
}
}
void quickSort(long array[],int i,int j)
	{
		if(i<j)
		{
			int k=quickPart(array,i,j);
			quickSort(array,i,k-1);
			quickSort(array,k+1,j);	
		}
	}
	
 int quickPart(long array[],int i,int j)
	{
		long a=array[j];
		int k=i;
		long temp;
		int pos=i-1;
		while(k<j)
		{
			if(array[k]<=a)
			{
				pos++;
				temp=array[pos];
				array[pos]=array[k];
				array[k]=temp;
			}
			k++;
		}
		pos++;
		temp=array[pos];
		array[pos]=array[k];
		array[k]=temp;
		return pos;
	}
