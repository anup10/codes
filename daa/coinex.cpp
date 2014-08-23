#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int amount,value;
	int num;
	cout << "Enter the no of coin types available \n";
	cin >>num;
	cout << "Enter the amount you want to get exchanged \n";
	cin >>amount;
	int coins[num];
	int ex_no[num];
	for(int i=0;i<num;i++)
	{
		ex_no[i]=0;
	}
	cout << "Enter all different coin denominations in decreasing order: \n";
	for(int i=0;i<num;i++)
	{
		cin>>coins[i];
	}
	int amount1=amount;
	int k=0;
	//for(i=)
	while(amount1>0)
	{
		
		value=coins[k];
		
		
		if(value>amount1)
		{
			ex_no[k]=0;
		}
		else
		{
			ex_no[k]=(int ) (amount1/value);
			
			amount1=amount1-(ex_no[k]*value);
			
		}
		k++;
	}
	for(int i=0;i<num;i++)
	{
		cout<<"coin of denom.";
		cout<<coins[i]<<"is :	";
		cout<<ex_no[i]<<endl;
	}
return 0;
}
		
			
