#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;

int sort_func(const void *a,const void *b)
{
	char *a1,*b1;
	a1=((char *)a);
	b1=((char *)b);
	return (strcmp(a1,b1));
}

int main() {
	char str[5163] [20];
	ifstream infile;
	infile.open("names.txt");
	for(int i=0;i<5163;i++)
	infile>>str[i];
	qsort(str[][20],5163,20,sort_func);
	//for(int i=0;i<5163;i++)
	//cout<<str[i];
	cout<<str[0]<<"\t"<<str[1]<<"\t"<<str[2];
		return 0;
}
