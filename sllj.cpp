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
	}*start,*nptr,*ptr,*rear,*temp;
	void create(int n)
	{
		ptr=new node;
		ptr->data=n;
		ptr->next=NULL;
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
			if(count==v-1)
			break;
			temp=temp->next;
		}
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
			temp->next=NULL;
			rear=temp;
		}
	}
	void delfrommiddle(int r)
	{
		node *save;
		nptr=start;
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data==r)
			{
				while(nptr->next!=temp)
				nptr=nptr->next;
				nptr->next=temp->next;
				save=temp;
				delete save;
				break;
			}
			temp=temp->next;
		}
	}
	node* search(int e)
	{
		int count=0;
		temp=start;
		while(temp!=NULL)
		{
			count++;
			if(temp->data==e)
			{
				break;
			}
			temp=temp->next;
		}
		return temp;
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
		nptr=rear;
		while(temp!=nptr)
		{
			if(temp->next==nptr)
			{
				nptr->next=temp;
				nptr=temp;
				temp=start;
				continue;
			}

			temp=temp->next;
		}
		if(nptr==start)
		temp->next=NULL;
		temp=start;
		start=rear;
		rear=temp;


	}
	void concatenate(node* a,node* b)
	{
		rear->next=a;
		rear=b;
		cout<<"linked lists concatenated successfully"<<endl;
	}
	~linkedlist()
	{   node* p;
		for(node *p; start!=NULL;)
		{
			p=start->next;
			delete start;
			start=p;
		}
		delete p;
	}

}obj,obj1,obj2;


int main()
{
    linkedlist::node* qptr;
	char ch1='y',ch2='y';
	int b,c,d,j,k,a=1,e;

	while(ch1=='y')
	{
		cout<<endl<<"------MENU------"<<endl;
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
				qptr=obj.search(k);
				if(qptr==NULL)
				cout<<"element NOT found";
				else
				cout<<"element is PRESENT in linked list";
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
			default:cout<<"select from 1-11"<<endl;
		}
		cout<<endl<<"enter y to go back to  menu"<<'\t';
		cin>>ch1;
	}
	getch();
}
