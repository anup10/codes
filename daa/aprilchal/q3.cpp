#include <iostream>

using namespace std;

int main()
{
    long  n,m,x,y,z,i,j;
    long  curr,b1,b2;
    long  count[10]={0};
    cin>>n;
    cin>>m;
    char ip[n];
    long  ans[n];
    cin>>ip;
    for(i=0;i<n;i++)
    {
        b1=0;
        b2=0;
        curr=(ip[i]-48);
        for(j=0;j<curr;j++)
        {
        	if(count[j]>0)
            b1+=((count[j]*curr)-(count[j]*j));
         }
         for(j=curr+1;j<10;j++)
         {
         	if(count[j]>0)
            b2+=((count[j]*j)-(count[j]*curr));
         }
         ans[i]=b1+b2;
         count[curr]++;
     }
     
     while(m>0)
     {
        cin>>x;
        x=x-1;
        cout<<ans[x]<<endl;
        m--;
     }
     
     return 0;
}
        













