#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;


int z=0;

int search(int in_order[],int pr,int j)
{
	for(int i=0;i<=j;i++)
	{
		if(in_order[i]==pr)
		return i;
	}
}

void insert_post(int post_order[],int z,int pr)
{
	post_order[z]=pr;
	
}








void into_post(int in_order[],int pre_order[],int post_order[],int i,int j)
{
	int pr,k;
	static int a=0;
	pr=pre_order[a];
	a++;
	k=search(in_order,pr,j);
	
	if(i==j)
	{
		insert_post(post_order,z,pr);
		z++;
		return;
		
	}
	if(i>j)
	{
		//insert_post(post_order,z,pr);
		//z++;
		return;
	}
	else
	{
			if(k>=0)
			into_post(in_order,pre_order,post_order,i,k-1);
		
		
			if(j-k>=0)
			into_post(in_order,pre_order,post_order,k+1,j);
		
			
	}
	insert_post(post_order,z,pr);
	z++;
	return;
	
}












int main()
{	
		
	int size,i,j,z=0;
	cout<<"enter the size of inorder and preorder array"<<endl;
	cin>>size;
	j=size;
	i=0;
	int in_order[size],pre_order[size],post_order[size];
	for(int p=0;p<size;p++)
	{
		in_order[p]=post_order[p]=pre_order[p]=0;
	}
	cout<<"enter the inorder array"<<endl;
	for(int p=0;p<size;p++)
	cin>>in_order[p];
	cout<<"enter the preorder array"<<endl;
	for(int q=0;q<size;q++)
	cin>>pre_order[q];
	into_post(in_order,pre_order,post_order,i,j-1);
	for(int r=0;r<size;r++)
	cout<<post_order[r];
	return 0;
}
