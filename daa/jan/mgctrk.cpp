#include <iostream>

using namespace std;

int main(){
	int tc,len,k;
	long long a,b,c,temp;
	cin>>tc;
	while(tc>0){
	
		cin>>len;
		
		long long arr[len];
		char ch;
		for(int i=0;i<len;i++)
			cin>>arr[i];
		cin>>a;
		cin>>b;
		cin>>c;
		for(int i=0;i<len;i++){
			cin>>ch;
			k=len-1;
			switch(ch){
				case 'A':
					for(int j=i;j<len;j++){
					arr[j]+=a;
					}
					break;
					
				case 'M':
					for(int j=i;j<len;j++){
					arr[j]*=b;
					}
					break;
					
				case 'R':
					
					for(int j=i;j<=((i+(len-1))/2);j++){
					temp=arr[k];
					arr[k]=arr[j];
					arr[j]=temp;
					k--;
					}
					break;
			}
		}
		
		for(int i=0;i<len;i++){
		arr[i]%=c;
		cout<<arr[i]<<" ";
		}
		cout<<endl;
		tc--;
		
	}
	return 0;
}
