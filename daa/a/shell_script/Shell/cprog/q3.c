#include<stdio.h>
void heapsort(long *,int);
void build_max_heap(long* b,int n);
void max_heapify(long* b,int t,int hs);
int h;
void main()
{
int i,tc,j,n;
long sum=0;
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
	heapsort(array,n);
	
	for(i=n-1;i>=0;i--)
	{
		sum=sum+array[i];
	}
	for(i=n-1;i>=2;i--)
	{
		sum=sum-array[i];
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
void heapsort(long* b,int n)
{
 int i,j;
 long temp;
 build_max_heap(b,n);
 h=n-1;
 for(i=n-1;i>0;i--)
 {
  temp=*b;
  *b=*(b+i);
  *(b+i)=temp;
  h--;
  max_heapify(b,0,h);
 }

}
void build_max_heap(long* b,int n)
{
 int i,j;
 h=n-1;
 for(i=parent(n-1);i>=0;i--)
 {
 max_heapify(b,i,h);
 }

}
void max_heapify(long* b,int t,int hs)
{
 int l,r,largest;
 long i;
 l=left(t);
 r=right(t);
 if(l<=hs)
    {
      if(*(b+l)>*(b+t))
          {
           largest=l;
          }
      else{largest=t;}

     if(r<=hs)
          {
              if(*(b+r)>*(b+largest))
               {
                 largest=r;
               }

          }
     if(largest!=t)
     {
      i=*(b+largest);
      *(b+largest)=*(b+t);
      *(b+t)=i;
     max_heapify(b,largest,hs);
     }
   }
}
int left(int i)
{
 return(2*i+1);
}
int right(int i)
{
return(2*i+2);
}
int parent(int i)
{
if(i%2==0)
 return((i/2)-1);
else
 return(i/2);
}
