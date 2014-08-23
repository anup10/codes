#include<iostream>
#include<fstream>

using namespace std;

int m;
struct node
 {
	int data;
	node *next;
 };

struct htable
 {
	node *head;	
 };

node *create_node(int x)
 {
	node *ptr=new node;
	ptr->data=x;
	ptr->next=NULL;
	return ptr;
 }

void insert_into(node **head,int key)
 {
	node *ptr=new node;
	ptr=create_node(key);
	if(*head==NULL)
		*head=ptr;
	else
	 {
		ptr->next=*head;
		*head=ptr;
	 }
 }

int search_into(node *head,int key)
 {
	while(head!=NULL)
	 {
		if(head->data==key)
			return 1;
		else
			head=head->next;
	 }
	return 0;
 }

int h(int key)
 {
	return (key%m);
 }

void insert(htable t[],int key)
 {
	insert_into(&((t[h(key)]).head),key);
	cout<<h(key);
 }

void search(htable t[],int key)
 {
	int x=search_into((t[h(key)]).head,key);
	if(x==1)
		cout<<h(key)<<" FOUND ";
	else
		cout<<h(key)<<" NOT FOUND ";
 }
int main()
 {
	int i=0;
	fstream fin;
	fin.open("input.txt",ios::in);
	fin>>m;


	int *content=new int[100];

	while(!fin.eof())
	 {
		fin>>content[i];
		if(content[i]==0)
			break;
	 	i++;
	 }
	fin.close();

	htable T[m];
	for(int i=0;i<m;i++)
		T[i].head=NULL;

	for(int j=0;j<=i;j++)
	 {
		switch(content[j])
		 {
			case 0:
				return 0;
			case 1:
				insert(T,content[++j]);
				cout<<endl;
				break;
			case 2:
				search(T,content[++j]);
				cout<<endl;
				break;
			default:
				cout<<"INVALID DATA\n";
				break;
	 	 }
	 }	


	cout<<"\n ENTER THE NUMBER OF ELEMENTS TO BE INSERTED : ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 {
		int j;
		cout<<"\nenter:";
		cin>>j;
		insert(T,j);
	 }
	cout<<"\n ENTER THE NUMBER OF ELEMENTS TO BE searched : ";
	cin>>n;
	for(int i=0;i<n;i++)
	 {
		int j;
		cout<<"\nenter:\n";
		cin>>j;
		search(T,j);
	 }
	
	return 0;
 }
