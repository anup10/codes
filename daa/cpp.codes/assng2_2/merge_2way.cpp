#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

struct student
{char name[100];
 int sub1,sub2,sub3,total;
 }s;

int off=sizeof(s);

int main()
{double runtime;
 clock_t start=clock();
 
 void create_bin_file(int& size); 
 void write_file(int size);
 void merge_sort(int beg,int end);
 void merge(int beg,int mid,int end);
 
 int size=0;
 
 create_bin_file(size);
 merge_sort(0,size-1);
 write_file(size);
 
 
 clock_t ends=clock();
 runtime=(double)(ends-start)/CLOCKS_PER_SEC;
 ofstream out_file;
 out_file.open("O.txt",ios::app);
 out_file<<"Running time: "<<runtime<<" sec";
 out_file.close();
 return 0;
 } 

void create_bin_file(int& size)
{ifstream in;
 ofstream out;

 in.open("1.txt");
 out.open("STBIN.bin",ios::binary);
 in>>size;
 char name[100];
 int i=0;
 while(i<size)
 {
	in>>s.name>>s.sub1>>s.sub2>>s.sub3;
	s.total=s.sub1+s.sub2+s.sub3;
	out.write((char*)&s,sizeof(s));
	i++;

 }

 out.close();
 in.close();
}   


void merge_sort(int beg,int end)
{void merge(int beg,int mid,int end);
 if(beg<end) 
	{int mid=(beg+end)/2;
	 merge_sort(beg,mid);
  	 merge_sort(mid+1,end);
	 merge(beg,mid,end);  
	}
}
 
void merge(int beg,int mid,int end)
{student s1,s2,s_max={"MIN",0,0,0,0};
 int n1,n2,i,j;
 fstream t1,t2,file;
 n1=mid-beg+1;
 n2=end-mid;
 t1.open("temp1.bin",ios::out|ios::binary);
 t2.open("temp2.bin",ios::out|ios::binary);
 file.open("STBIN.bin",ios::in|ios::out|ios::binary|ios::ate);
 
 file.seekg(beg*off,ios::beg);
 for(i=0;i<n1;++i)
{file.read((char*)&s,sizeof(s));
 t1.write((char*)&s,sizeof(s));
}
t1.write((char*)&s_max,sizeof(s));
 
 for(i=0;i<n2;++i)
{file.read((char*)&s,sizeof(s));
 t2.write((char*)&s,sizeof(s));
}
t2.write((char*)&s_max,sizeof(s));

t1.close();
t2.close();

t1.open("temp1.bin",ios::in|ios::binary);
t2.open("temp2.bin",ios::in|ios::binary);

file.seekg(beg*off,ios::beg);

t1.read((char*)&s1,sizeof(s));
t2.read((char*)&s2,sizeof(s));
for(i=0;i<n1+n2;++i)
{if(s1.total==s2.total)
	{if(strcmp(s1.name,s2.name)<0)
		{file.write((char*)&s1,sizeof(s));
	 	 t1.read((char*)&s1,sizeof(s));
		 }
 	  else 
	        {file.write((char*)&s2,sizeof(s));
                 t2.read((char*)&s2,sizeof(s));
		 }
         }

 else if(s1.total>s2.total)
	   {file.write((char*)&s1,sizeof(s));
	    t1.read((char*)&s1,sizeof(s));
	    }
 else 
	   {file.write((char*)&s2,sizeof(s));
            t2.read((char*)&s2,sizeof(s));
	    }
 }
t1.close();
t2.close();
remove("temp1.bin");
remove("temp2.bin");
}

void write_file(int size)
{
 ofstream out_file;
 out_file.open("O.txt");
 ifstream file;
 file.open("STBIN.bin",ios::binary);
 for(int i=0;i<size;++i)
  {file.read((char*)&s,sizeof(s));
   out_file<<s.name<<' '<<s.sub1<<' '<<s.sub2<<' '<<s.sub3<<"\n";
   }
 file.close();
 out_file.close();
 remove("STBIN.bin");
}

