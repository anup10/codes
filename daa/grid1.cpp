#include <iostream>

using namespace std;

long left(int grid[][20],int i,int j)
{
	if(j-3<0)
	return 0;
	else
	return (grid[i][j]*grid[i][j-1]*grid[i][j-2]*grid[i][j-3]);
}

long right(int grid[][20],int i,int j)
{
	if(j+3>19)
	return 0;
	else
	return (grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3]);
}

long up(int grid[][20],int i,int j)
{
	if(i-3<0)
	return 0;
	else
	return (grid[i][j]*grid[i-1][j]*grid[i-2][j]*grid[i-3][j]);
}

long down(int grid[][20],int i,int j)
{
	if(j+3>19)
	return 0;
	else 
	return (grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j]);
}

long max(long ans[],int num)
{
	long max=ans[0];
	for(int i=0;i<num;i++)
	{
		if(max<ans[i])
		max=ans[i];
	}
	return max;
}

long diagonal(int grid[][20],int i,int j)
{
	long ne,nw,se,sw,x,ans[4];
	if(i-3<0 || j+3>19)
	ne=0;
	else
	ne=(grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3]);
	ans[0]=ne;
	if(i-3<0 || j-3<0)
	nw=0;
	else
	nw=(grid[i][j]*grid[i-1][j-1]*grid[i-2][j-2]*grid[i-3][j-3]);
	ans[1]=nw;
	if(i+3>19 || j-3<0)
	sw=0;
	else
	sw=(grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3]);
	ans[2]=sw;
	if(i+3>19 || j+3>19)
	se=0;
	else
	se=(grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3]);
	ans[3]=se;
	x=max(ans,4);
	return x;
}


int main()
{
	int grid[20][20],i,j;
	long l,r,u,d,dg,maxprod=0,x,ans[5];
	grid[20][20]={
	
	#include "data.inc"
	};
	
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			
			l=left(grid,i,j);
			r=right(grid,i,j);
			u=up(grid,i,j);
			d=down(grid,i,j);
			dg=diagonal(grid,i,j);
			
			
			ans[0]=l;
			ans[1]=r;
			ans[2]=u;
			ans[3]=d;
			ans[4]=dg;
			x=max(ans,5);
			if(x>maxprod)
			maxprod=x;
		}
	}
	
	cout<<maxprod;
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
