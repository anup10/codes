#include <iostream>
#include <cstring>

using namespace std;


int top;


int isEmpty()
{
	return (top==-1);
}

void push()
{
	++top;
}

void pop()
{
	top--;
}

int main()
{
	long t,len,ans;
	char ip[1000000],ch;
	
	cin>>t;
	while(t>0)
	{
		cin>>ip;
		len=strlen(ip);
		ans=0;
		top=-1;
		for(long i=0;i<len;i++)
		{
			ch=ip[i];
			if(ch=='>' && isEmpty())
				break;
			
			else if(ch=='<')
				push();
				
			else if(ch=='>')
			{
				pop();
				if(isEmpty())
				{
					ans=i+1;
				}
			}
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
				

















