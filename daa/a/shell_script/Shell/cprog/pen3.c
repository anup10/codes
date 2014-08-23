#include<stdio.h>
#define p(n) printf("%d ",n)
#define pn printf("\n")

int max(int m,int n)
{
	return (m>n)?m:n;
}

void main()
{
int T;
scanf("%d",&T);

while(T--)
{
	int n,i,j;
	scanf("%d",&n);
	int w;
	scanf("%d",&w);
int c[n],p[n],t[n];
for(i=0;i<n;i++)
scanf("%d%d%d",&c[i],&p[i],&t[i]);

for(i=0;i<n;i++)
	c[i]*=p[i];

int r[n+1][w+1];
for(i=0;i<w+1;i++)
	r[0][i]=0;
for(i=0;i<n+1;i++)
	r[i][0]=0;
for(i=1;i<n+1;i++){
	for(j=1;j<w+1;j++)
	{
		if(t[i-1]>j)
			r[i][j]=r[i-1][j];
		else
			r[i][j]=max(r[i-1][j],c[i-1]+r[i-1][j-t[i-1]]);
	}
}

p(r[n][w]);pn;


}}
