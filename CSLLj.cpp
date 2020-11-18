#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class linkedlist
{
	public:
	struct node
	{
		int data;
		node *next;
	}*start,*nptr,*ptr,*rear,*temp, *p, *qptr;
	void create(int n)
	{
		ptr=new node;
		ptr->data=n;
		ptr->next=ptr;
	}
	void display()
	{
		if(start==NULL)
		cout<<"displaying your linked list->->->"<<'\t'<<" empty"<<endl;
		else
		{
			cout<<"displaying your linked list->->->"<<'\t';
			temp=start;
			do
			{
				cout<<temp->data<<'\t';
				temp=temp->next;
			}while(temp!=rear->next);
		}


	}
	linkedkist()
	{
		rear=NULL;
		start=NULL;
	}
	void insertatbeg()
	{
		if(start==NULL)
		start=rear=ptr;
		else
		{
			ptr->next=start;
			start=ptr;
			rear->next=start;
		}
	}
	void insertatend()
	{
		if(rear==NULL)
		start=rear=ptr;
		else
		{
			rear->next=ptr;
			rear=ptr;
			rear->next=start;
		}
	}
	void insertatmiddle(int v)
	{
		int count=0;
		temp=start;
		do
		{
			count=count+1;
			if(count==v-1)
			break;
			temp=temp->next;
		}while(temp!=start);
		ptr->next=temp->next;
		temp->next=ptr;
	}
	void delfrombeg()
	{
		if(start==NULL)
		cout<<"already empty"<<endl;
		else if(start==rear)
		{
			nptr=start;
			delete nptr;
			start=rear=NULL;
		}
		else
		{
			temp=start;
			start=temp->next;
			rear->next=start;
			delete temp;
		}
	}
	void delfromend()
	{
		if(rear==NULL)
		cout<<"already empty"<<endl;
		else if(start==rear)
		{
			nptr=start;
			delete nptr;
			start=rear=NULL;
		}
		else
		{
			temp=start;
			while(temp->next!=rear)
			temp=temp->next;
			temp->next=start;
			rear=temp;
		}
	}
	void concatenate(node* a,node* b)
	{
		rear->next=a;
		b->next=start;
		rear=b;
	}
	node* search(int e)
	{
		int count=0;
		temp=start;
		do
		{
			count++;
			if(temp->data==e)
			{
				break;
			}
			temp=temp->next;
		}while(temp!=start);
		return temp;
	}


	~linkedlist()
	{
		for(node *p;start!=rear; )
		{
			p=start->next;
			delete start;
			start=p;
		}
		p=start;
		delete p;

	}

}obj,obj1;

int main()
{

    linkedlist::node*qptr;
	char ch1='y',ch2='y';
	int b,c,d,j,k,e,a=1;

	while(ch1=='y')
	{
		cout<<endl<<"select"<<endl;
		cout<<"1.insert at beginning"<<endl<<"2.insert in middle"<<endl<<"3.insert at end"<<endl;
		cout<<"4.delete from beginning"<<endl<<"5.delete from end"<<endl<<"6.search an element"<<endl;
		cout<<"7.concatenate this linked list with another list"<<endl<<"enter choice"<<'\t';
		cin>>c;
		if(c==1||c==2||c==3)
		{
			cout<<"enter data for node to insert"<<'\t';
			cin>>b;
			obj.create(b);
		}
		switch(c)
		{
			case 1:	obj.insertatbeg();
				obj.display();
				break;
			case 2: cout<<"enter place at which you want to insert"<<'\t';
				cin>>d;
				obj.insertatmiddle(d);
				obj.display();
				break;
			case 3:	obj.insertatend();
				obj.display();
				break;
			case 4:	obj.delfrombeg();
				obj.display();
				break;
			case 5:	obj.delfromend();
				obj.display();
				break;
			case 6:	cout<<"enter the data of node you want to search"<<'\t';
				cin>>k;
				qptr=obj.search(k);
				if(qptr==NULL)
				cout<<"element NOT found";
				else
				cout<<"element is PRESENT in linked list";
				break;
			case 7:cout<<"======insert lined list 2======="<<endl;
				while(ch2=='y')
				{
					cout<<"enter data of node "<<a<<'\t';
					cin>>e;
					obj1.create(e);
					obj1.insertatend();
					a++;
					cout<<"add more?(y/n)"<<'\t';
					cin>>ch2;
				}
				obj.concatenate(obj1.start,obj1.rear);
				obj.display();
				break;
			default:cout<<"select from 1-10"<<endl;
		}
		cout<<endl<<"enter y to go back to  menu"<<'\t';
		cin>>ch1;
	}
	getch();
}
