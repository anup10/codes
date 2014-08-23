#include<stdio.h>
void main()
{
int C,N,M,T,time;
scanf("%d",&C);
while(C>0)
{
	scanf("%d",&N);
	scanf("%d",&M);
	scanf("%d",&T);

	int x=N/M;
	int y=N%M;
	if(y==0)
	{
		time=x*T*2;
	}
	else
	{
		time=(x+1)*2*T;
	}
	printf("%d\n",time);
	C--;
}
}
