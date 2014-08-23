#include<stdio.h>
void main()
{
int T;
long q=0;
long N,Q,sum,L,R,i,m,mi;
scanf("%d",&T);
while(T>0)
{
	scanf("%lu",&N);
	scanf("%lu",&Q);
	long A[N];	
	q=0;
	
	for(i=0;i<N;i++)
		scanf("%ld",&A[i]);
	
	long l[Q],r[Q],s[Q];	
	while(Q>0)
	{
		sum=0;
		scanf("%lu",&L);
		scanf("%lu",&R);
		l[q]=L;
		r[q]=R;
		
		m=l[0];
		mi=0;
		if(q!=0)
		{
			for(i=0;i<q;i++)
			{
				if(l[i]>=L && r[i]<=R)
				{
					if(m>l[i])
						m=l[i];
					mi=i;
				}
			}
			sum=sum+s[mi];
			for(i=L;i<l[mi];i++)
				sum=sum+A[i];
			for(i=r[mi]+1;i<=R;i++)
				sum=sum+A[i];
		}
		else
		{
			for(i=L;i<=R;i++)
				sum=sum+A[i];
		}
		
		s[q]=sum;
		printf("%ld",sum);
		printf("\n");
		Q--;
		q++;
	}
	T--;
}
}
