#include<stdio.h>
void main()
{
 	int T,N,i,j;
 	long long sum=0;
 	scanf("%d",&T);
 	while(T>0)
 	{
 		sum=0;
 		scanf("%d",&N);
 		long long A[N];
 		for(i=0;i<N;i++)
 			scanf("%llu",&A[i]);
 			
 		long long mat[N+1][N+1];
 		for(i=0;i<N+1;i++)
 			mat[0][i]=0;
 		for(i=0;i<N+1;i++)
 			mat[i][0]=0;
 		for(i=1;i<N+1;i++)
 			mat[1][i]=A[i-1];
 		 			
 		for(j=2;j<N+1;j++)
 		{
 			for(i=j;i<N+1;i++)
 				mat[j][i]=mat[j-1][i-1]+mat[j-1][i];
		}
		
		
		
		for(j=1;j<N+1;j++)
 		{
 			for(i=j;i<N+1;i++)
 				sum+=mat[j][i];
		}			
 		printf("%llu",sum);
 		T--;	
 	}	
}
