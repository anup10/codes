#include<iostream>
#include<fstream>

using namespace std;

struct ll
 {
	int data;
	struct ll *next;
 };




void insert(ll **top,int data)
 {
	ll *nw=new ll;
	nw->next=NULL;
	nw->data=data;
	if(*top==NULL)
		*top=nw;
	else
	 {
		nw->next=*top;
		*top=nw;
	 }
		
 }

void show(ll *top)
 {
	ll *temp=new ll;
	temp=top;
	while(temp!=NULL)
	 {
		cout<<temp->data<<"  ";
		temp=temp->next;
	 }
	delete(temp);
 }

int del(ll **top,int pos)
 {      
	int k=1;
	int t;
	ll *p=new ll;
	ll *q=new ll;

	if(*top==NULL)
	 {
		cout<<"\n LIST EMPTY ";
		return -1000000;
	 }

	p=*top;
	if(pos==1)
	 {
		p=*top;
		*top=(*top)->next;
		t=p->data;
		delete p;
		return t;
	 }
	else
	 {
		while((p!=NULL)&&(k<pos))
		 {
			k++;
			q=p;
			p=p->next;
		 }
		if(p==NULL)
		 {
			cout<<"\n POSITION DOESNT EXIST ";
			return -1000000;
		 }
		else
		 {
			t=p->data;
			q->next=p->next;
			delete p;
			return t;
		 }
	 }

	
 }

void insert_into_ll(ll **top,int data,int pos)
 {
	ll *nw=new ll;
	nw->data=data;
	nw->next=NULL;
	int k=1;
	ll *p,*q;

	p=*top;
	if(pos==1)
	 {
		nw->next=p;
		*top=nw;
	 }
	else
	 {
		while((p!=NULL)&&(k<pos))
		 {
			k++;
			q=p;
			p=p->next;
		 }
		if(p==NULL)
		 {
			q->next=nw;
			nw->next=NULL;
		 }
		else
		 {
			nw->next=p;
			q->next=nw;
		 }
	 }

	
 }

void swap(ll **top,int i,int j)
 {
	int t1,t2;
	t1=del(top,j);
	t2=del(top,i);
	if(t1==-1000000||t2==-1000000)
	 {
		cout<<"\nPROBLEM";
		return;
	 }
 
	insert_into_ll(top,t1,i);
	insert_into_ll(top,t2,j);
 }

void sort(ll **top)
 {
	ll *tempi=new ll;
	ll *tempj=new ll;

	int i=1,small,j,t,smallpos;
	tempi=*top;

	while(tempi->next!=NULL)
	 {
		smallpos=i;
		small=tempi->data;
		j=i+1;
		tempj=tempi->next;
		while(tempj!=NULL)
		 {
			int t=tempj->data;
			if(t<small)
			 {
				smallpos=j;
				small=tempj->data;
			 }
		
			tempj=tempj->next;
			j++;	
		 }
		if(smallpos!=i)
			swap(top,i,smallpos);

		tempi=tempi->next;
		i++;
	 }

 }

int main()
 {
	int total,read;
	ll *sll=new ll;
	sll=NULL;
	fstream fin;
	fin.open("5.txt",ios::in);
	fin>>total;
	int *content=new int[100];
	for(int i=0;i<total;i++)
		fin>>content[i];
	for(int i=0;i<total;i++)
		insert(&sll,content[i]);	
	cout<<"\n THE ORIGINAL LINKED LIST IS : "<<endl;
	show(sll);
	cout<<endl;
	sort(&sll);
	cout<<"\n THE SORTED LINKED LIST IS : "<<endl;
	show(sll);
	cout<<endl;

	delete(sll);
	return 0;
 }
