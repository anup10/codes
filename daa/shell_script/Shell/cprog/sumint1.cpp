#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
int T;
long N,Q,sum,L,R,i,j;
scanf("%d",&T);
vector<int> abc(100000,0);
vector<vector<int> > mat(100000,abc);

while(T>0)
{
	scanf("%lu",&N);
	scanf("%lu",&Q);
	int A[N];
   		
	
	for(i=0;i<N;i++)
		scanf("%d",&A[i]);
	
	for(i=0;i<N+1;i++)
 		mat[0][i]=0;
 	for(i=0;i<N+1;i++)
 		mat[i][0]=0;
 	for(i=1;i<N+1;i++)
 		mat[1][i]=A[i-1];
 		
 	for(i=2;i<N+1;i++)
 	{
 		for(j=i;j<N+1;j++)
 			mat[i][j]=mat[i-1][j-1]+A[j-1];
 	}
 	
 	for(i=0;i<N+1;i++)
 	{
 		for(j=0;j<N+1;j++)
 			printf("%d ",mat[i][j]);
 		printf("\n");
 	}
 	
	while(Q>0)
	{
		scanf("%lu",&L);
		scanf("%lu",&R);
		sum=mat[R-L+1][R+1];
		printf("%ld",sum);
		printf("\n");
		Q--;
	}
	T--;
}
return 0;
}
