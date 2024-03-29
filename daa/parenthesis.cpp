#include<iostream>
#include<fstream>

using namespace std;

int recursive(int dimen[],int i,int j)
{
	int c=0,cost;
	if(i>=j) return 0;
	else
	{
		cost=2147483646;
		for(int k=i;k<j;k++)
			{
			c= (recursive(dimen,i,k) + dimen[i-1]*dimen[k]*dimen[j]+ recursive(dimen,k+1,j));
			if(c<cost)
				cost=c;
			}
		return(cost);
	}
}
			
int main()
{
	int size,cost;
	cout<<"Enter the length of matrices\n";
	cin>>size;
	int dimen[size+1];
	cout<<"Enter the dimensions of the matrices : \n";
	for (int i=0;i<size+1;i++)
		cin>>dimen[i];
	

	cost=recursive(dimen,1,size);
	cout<<"the minimum cost of scalar multiplication is :"<<cost;
	return 0;
}
