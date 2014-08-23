#include<stdio.h>
#define p(n) printf("%d",n)
#define pn printf("\n")

void main()
{
int T,i,j,k;
long long L,R,sum=0;
scanf("%d",&T);

while(T>0)
{
	sum=0;
	scanf("%llu",&L);
	scanf("%llu",&R);
	
	while(L<=R)
	{
		k=findDigits(L);
		sum=sum+L*k;
		L++;
	}
	T--;
	printf("%llu",sum);
	pn;
}

}
int findDigits(long long k)
{
int dig=0;
while(k)
{
	k=k/10;
	dig++;
}
return dig;
}
