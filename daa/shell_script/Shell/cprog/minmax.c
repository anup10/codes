#include<stdio.h>
void main()
{
int T,N;
scanf("%d",&T);
while(T>0)
{
	scanf("%d",&N);
	long A[N],max,min;
	int i;
	
	for(i=0;i<N;i++)
		scanf("%lu",&A[i]);
		
	max=A[0];
	min=A[0];
	for(i=1;i<N;i++)
	{
		if(A[i]<min)
			min=A[i];
		if(A[i]>max)
			max=A[i];
	}
	
	printf("%lu %lu",min,max);
	printf("\n");
	T--;
}
}
