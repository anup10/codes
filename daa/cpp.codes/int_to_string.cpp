#include<iostream>
#include<sstream>	//String Stream
#include<cstring>
#include<cstdio>

using namespace std;
int main()
 {
	char st[20];
	int num=123;
	string s;
	ostringstream streamobj;	//Creating an object of the Stream used for conversion
	streamobj<<num;
	s=streamobj.str();
	cout<<"\nPRINTING IN STRING FORMAT : "<<s<<"\n";
	int i; 
	for(i=0;i<s.length();i++)
		st[i]=s[i];
	st[i]='\0';	
	cout<<"PRINTING IN CHARACTER ARRAY FORMAT : ";
	puts(st);
	return 0;
 }
