#include<stdio.h>
void quickSort(long array[],int i,int j);

void main()
{
int i,tc,j,n,m,v1,v2,max;
int count[11]={0};

scanf("%d",&tc);
while(tc>0)
{
	max=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		char array[m+1];
		scanf("%s",array);
		v1=getMaxPal(array,m);
		v2=getMaxKMP(array,m);
		if(v1>v2)
		{
			count[v1]++;
		}
		else
		{
			count[v2]++;
		}
	}
	for(i=0;i<11;i++)
	{
		if(max<count[i]*i)
		{
			max=count[i]*i;
		}
	}
	printf("%d\n",max);
	tc--;
}
}

int getMaxPal(char array[],int m)
{
	int i,len,k,range=1,max=0;
	len=m;
	
		int j=0;
		int n=m;
		while(range<n-1)
		{
			for(j=0;j<n-range;j++)
			{
				if(isPal(array,j,j+range-1))
				{
					if(max<(range+1))
					{
						if((range+1)%2!=0)
							max=(range+1)/2+1;
						else
							max=(range+1)/2;	
					}
				}
			}
			range++;
		}
		
	return max;
}

int isPal(char array[],int i,int j)
{
	int k=i,flag=1;
	while(k<j && flag==1)
	{
		if(array[k]!=array[j])
		{
			flag=0;
		}
		else
		{
			j--;
		}
		k++;
	}
	
	return flag;
} 

int getMaxKMP(char array[],int m)
{
	return (compute_pi(array,m));
}

int compute_pi(char pat[],int len)
{
	
	int s=-1,k,max=-9999;
	int pi[len];
	pi[0]=-1;
	
	for(k=1;k<len;k++)
		{
		if(pat[s+1]==pat[k])
			s=s+1;
		else
		{	while(s>0 && pat[s+1]!=pat[k])
				s=pi[s];
			if(s>0)
				s=s+1;
		}
		
		pi[k]=s;
		if(pi[k]>max)
			max=pi[k];
		}
	return max;
}
