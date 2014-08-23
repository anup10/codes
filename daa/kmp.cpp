#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;



int *compute_pi(char pat[],int len,int pi[])
{
	
	int s=-1;
	pi[0]=-1;
	for(int k=1;k<len;k++)
		{
		if(pat[s+1]==pat[k])
			s=s+1;
		else
		{	while(s>0 && pat[s+1]!=pat[k])
				s=pi[s];
			if(s>0)
				s=s+1;
		}
		
		pi[k]=s;
		}
	return pi;
}


int main()
{
	char pat[20],ip[50],ch;
	int i,len,len2,j,s=-1;
	int *pi_;
	int pi[20];
	i=0;
	cout<< "enter the pattern :";
	cin>>pat;
	len=strlen(pat);
	pi_=compute_pi(pat,len,pi);
	for(int j=0;j<len;j++)
		cout<< *(pi_+j);
	
	cout<< "enter the ip text";
	cin>>ip;
	len2=strlen(ip);
	for( j=0;j<len2;j++)
		cout<<s<<endl;
		while((s>-1) && pat[s+1]!= ip[j])
			s=*(pi_+s);
		if(pat[s+1]==ip[j])
			s=s+1;
		if(s==(len-1))
		{
			cout<<"valid shift at : ";
			cout<<j-(len-1);
			s=*(pi_+s);
		}	
		
	
	
}
