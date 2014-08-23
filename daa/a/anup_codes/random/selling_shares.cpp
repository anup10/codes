#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int n,k=0,sum_o=0,sum_n=0,sum=0,len=0,len_f,first_o=0,first_n=0,last_o=0,last_n=0;
	cout<<"enter the size of array"<<endl;
	cin>>n;
	int array[n];
	cout<<"enter the elements"<<endl;
	while(k<n)
	{
		cin>>array[k++];
	}
	for(int i=0;i<n;i++)
	{
		sum_n=sum_n + array[i];
		
		if(sum_n<sum)
		{
			sum_n=sum_n - array[i];
			if(sum_n<sum_o)
			{
				sum_n=sum=0;
				len=0;
				first_n=i+1;
				
			}
			else
			{
				sum_o=sum_n;
				sum_n=sum=0;
				first_o=first_n;
				first_n=i+1;
				last_o=i-1;
				len_f=len;
				len=0;
			}
		}
		else
		{
			sum=sum_n;
			len++;
			
		}
	}

	cout<<"geratest continous is :"<<sum_o<<endl;
	cout<<"starting index of the best case is: "<<first_o<<endl;
	cout<<"last index of the best case is :"<<last_o<<endl;
	cout<<"length of the best case is :"<<len_f<<endl;
}











	
