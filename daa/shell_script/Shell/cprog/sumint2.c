#include<stdio.h>
void main()
{
int T;
long N,Q,sum,L,R,i;
scanf("%d",&T);
while(T>0)
{
	scanf("%lu",&N);
	scanf("%lu",&Q);
	long A[N];
	
	for(i=0;i<N;i++)
		scanf("%ld",&A[i]);
	
		
	while(Q>0)
	{
		sum=0;
		scanf("%lu",&L);
		scanf("%lu",&R);
		
		while(L<=R)
		{
			sum=sum+A[L];
			L++;
		}
		printf("%ld",sum);
		printf("\n");
		Q--;
	}
	T--;
}
}
