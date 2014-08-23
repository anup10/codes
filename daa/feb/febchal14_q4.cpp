#include<bits/stdc++.h> 

using namespace std;
inline void fastRead(int *a)
{
 register char c=0;
 while (c<33) c=getchar_unlocked();
 *a=0;
 while (c>33)
 {
    *a=*a*10+c-'0';
     c=getchar_unlocked();
 }
}

int main()
{
	int T,n,m,k;
	int i,j,x,temp,temp1,temp2,temp3,tempi=0,al,xval,val,len;
	int arr[1000],gain[1000][1000],loss[1000][1000],max[1000];
	long int res;
	fastRead(&T);
	while(T--)
	{
		fastRead(&n);
		fastRead(&m);
		fastRead(&k);
		res=0;
		for(i=0;i<n;i++)
		{
			fastRead(&arr[i]);
			max[i]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				fastRead(&gain[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				fastRead(&loss[i][j]);
				temp=gain[i][j]-loss[i][j];
				if(temp>max[i])
				{
					max[i]=temp;
				}				
			}
		}
		vector<pair<int,int> > chk;
		for(i=0;i<n;i++)
		{
			temp=arr[i]-1;
			temp1=max[i]-gain[i][temp];
			chk.push_back(make_pair(temp1,i));
			
		}
		//cout<<endl;	
		sort(chk.begin(),chk.end());
		len=chk.size();
		//cout<<len<<endl;
		if(k<=len)
		{
			i=len-1;
			al=k;
			while(al>0)
			{
				temp=chk[i].second;
				temp1=arr[temp];
				temp2=gain[temp][temp1-1];
				res=res+temp2+chk[i].first;
				i--;
				al--;
				//cout<<"1: "<<res<<endl;
			}
			while(i>=0)
			{
				temp=chk[i].second;
				temp1=arr[temp];
				temp2=gain[temp][temp1-1];
				res=res+temp2;
				i--;
				//cout<<"2: "<<res<<endl;
			}
		}
		else
		{
			for(i=len-1;i>=0;i--)
			{
				temp=chk[i].second;
				temp1=arr[temp];
				temp2=gain[temp][temp1-1];
				res=res+temp2+chk[i].first;
			}
		}
		
		cout<<res<<endl;
	}
	return 0;
}
