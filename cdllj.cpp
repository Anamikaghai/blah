#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class linkedlist
{
	public:
	struct node
	{
		node *previous;
		int data;
		node *next;
	}*start,*nptr,*ptr,*rear,*temp, *p;
	void create(int n)
	{
		ptr=new node;
		ptr->data=n;
		ptr->next=NULL;
		ptr->previous=NULL;
	}
	void display()
	{
		if(start==NULL)
		cout<<"linked list is empty"<<endl;
		else
		{
			cout<<"displaying your linked list->->->"<<'\t';
			temp=start;
			while(temp!=NULL)
			{
				cout<<temp->data<<'\t';
				temp=temp->next;
			}
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
			start->previous=ptr;
			start=ptr;
		}
	}
	void insertatend()
	{
		if(rear==NULL)
		start=rear=ptr;
		else
		{
			rear->next=ptr;
			ptr->previous=rear;
			rear=ptr;
		}
	}
	void insertatmiddle(int v)
	{
		int count=0;
		temp=start;
		while (temp!=NULL)
		{
			count=count+1;
			if(count = v-1)

			temp=temp->next;
		}
		ptr->next=temp->next;
		ptr->previous=temp;
		temp->next->previous=ptr;
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
			start->previous=NULL;
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
			temp=rear;
			rear=temp->previous;
			rear->next=NULL;
			delete temp;
		}
	}
	void delfrommiddle(int r)
	{
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data==r)
			{
				temp->previous->next=temp->next;
				temp->next->previous=temp->previous;
			}
			temp=temp->next;
		}
	}
	void search(int e)
	{
		int count=0;
		temp=start;
		while(temp!=NULL)
		{
			count++;
			if(temp->data==e)
			{
				cout<<"this node is at position:"<<'\t'<<count;
				break;
			}
			temp=temp->next;
		}
		if(count==0||temp==NULL)
		cout<<"node does not exist";
	}
	void count()
	{
		int count=0;
		temp=start;
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
		cout<<"no.of nodes:"<<'\t'<<count;
	}
	void reverse()
	{
		node *save;
		temp=start;
		if(start==rear)
		cout<<"linked list only have one node"<<endl;
		else
		{
			do
			{
				save=temp->next;
				temp->next=temp->previous;
				temp->previous=save;
				temp=temp->previous;
			}while(temp->previous!=NULL);
			save=start;
			start=rear;
			rear=save;
			delete save;
		}
	}
	void concatenate(node* a,node* b)
	{
		rear->next=a;
		a->previous=rear;
		rear=b;
	}
	~linkedlist()
	{
		for(node *p;start!=NULL;)
		{
			p=start->next;
			delete start;
			start=p;
		}
		delete p;
	}
}obj,obj1;


int main()
{

	char ch1='y',ch2='y';
	int b,c,d,j,k,e,a=1;

	while(ch1=='y')
	{
		cout<<endl<<"select"<<endl;
		cout<<"1.insert at beginning"<<endl<<"2.insert at end"<<endl<<"3.insert at middle"<<endl;
		cout<<"4.delete from beginning"<<endl<<"5.delete from end"<<endl<<"6.delete from middle"<<endl;
		cout<<"7.search a node"<<endl<<"8.count no. of nodes"<<endl<<"9.reverse linked list"<<endl;
		cout<<"10.display linked list"<<endl<<"11.concatenate this linked list with another list"<<endl;
		cout<<"enter choice"<<'\t';
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
			case 2:	obj.insertatend();
				obj.display();
				break;
			case 3: cout<<"enter place at which you want to insert"<<'\t';
				cin>>d;
				obj.insertatmiddle(d);
				obj.display();
				break;
			case 4:	obj.delfrombeg();
				obj.display();
				break;
			case 5:	obj.delfromend();
				obj.display();
				break;
			case 6:	cout<<endl<<"enter data of node you want to delete"<<'\t';
				cin>>j;
				obj.delfrommiddle(j);
				obj.display();
				break;
			case 7:	cout<<"enter the data of node you want to search"<<'\t';
				cin>>k;
				obj.search(k);
				break;
			case 8:	obj.count();
				break;
			case 9:	obj.reverse();
				obj.display();
				break;
			case 10:obj.display();
				break;
			case 11:cout<<"======insert lined list 2======="<<endl;
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
