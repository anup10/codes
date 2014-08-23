#include<iostream>
#include<fstream>

using namespace std;

int mod(int x,int y)
{
	if(x>y)
	return(x-y);
	else
	return(y-x);
}

int main()
{
	int n,sumo=0,sumt=0;
	cout<<"Enter the size of array : \n";
	cin>>n;
	int orig[n],trans[n],dec[n];
	for(int i=0;i<n;i++)
	{
		dec[i]=0;
	}
	cout<<"Enter the original array : \n";
	for(int i=0;i<n;i++)
	{
		cin>>orig[i];
	}
	cout<<"Enter the final array : \n";
	for(int i=0;i<n;i++)
	{
		cin>>trans[i];
	}
	for(int i=0;i<n;i++)
	{
		sumo=sumo+orig[i];
	}
	for(int i=0;i<n;i++)
	{
		sumt=sumt+trans[i];
	}	
	if(n==1)
	{
		cout<<"number of dec op on orig i/p is:"<<(orig[0]-trans[0])<<endl;
	}
	if(n==2)
	{
		if((orig[0]-trans[0])!=(trans[1]-orig[1]) || ((trans[0]-orig[0])!=(orig[1]-trans[1])))
		{
			cout<<"Solution is not possible!!\n";
			return 0;
		}
		else
		{
			int b;
			if(orig[0]>trans[0])
			{
				b=1;
				dec[b]=orig[0]-trans[0];
			}
			else
			{
				b=0;
				dec[b]=orig[1]-trans[1];
			}
			cout<<"no. of dec operation applied on digit "<<b<<", i.e,  : "<<orig[b]<<" is:		";
			cout<<dec[b]<<endl;
		}
	}
	else
	{
	int a=(n-2);
	if(((sumt-sumo)%a) != 0)
	{
		cout<<"Solution is not possible!!\n";
		return 0;
	}
	else
	{
		int steps,diff;
		steps=(sumt-sumo)/a;
		for(int i=0;i<n;i++)
		{
			diff=mod(orig[i],trans[i]);
			if(diff>steps)
			{
				cout<<"Solution is not possible!!\n";
				return 0;
			}
			else
			{
				dec[i]=(((orig[i]-trans[i])+steps)/2);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<"no. of dec operation applied on digit "<<i<<", i.e,  : "<<orig[i]<<" is:		";
		cout<<dec[i]<<endl;
	}
	}
			
return 0;
}















