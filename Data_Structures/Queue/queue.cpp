#include<iostream>

using namespace std;

struct node
{
	int data;
	node *next;
}*front,*rear;

void insert(int data)
{
	node *ptr= new node;

	if(!ptr)
		cout<<"Memory not available."<<endl;
	else{
		ptr->data=data;
		ptr->next=NULL;

		if(rear==NULL)
			front=rear=ptr;
		else{
			rear->next=ptr;
			rear=ptr;
		}
	}
}

void del()
{
	if(front==NULL)
		cout<<"Underflow"<<endl;
	else{	node *ptr;
			ptr=front;
		if(front==rear)
			front=rear=NULL;
		else front=front->next;
		delete ptr;
	}
}

bool isEmpty()
{
	if(front==NULL)
		return 1;
	else return 0;
}

void display()
{
	node *ptr;
	ptr=front;

	while(ptr!=NULL)
	{
		cout<<ptr->data<<"  ";
		ptr=ptr->next;
	}

	cout<<endl;
}

int main()
{
	front=rear=NULL;
	int data;

	char ch='y';

	while(ch=='y')
	{
		cout<<"Welcome\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 to check if Queue is empty\nEnter 4 to display the Queue"<<endl;
		int num;
		cin>>num;

		switch(num)
		{
			case 1:	cout<<"Enter data to be inserted"<<endl;
					int data;
					cin>>data;
					insert(data);
					break;
			case 2: del();
					break;
			case 3:	if(isEmpty())
					cout<<"Queue is empty"<<endl;
					else cout<<"Queue is not empty"<<endl;
					break;
			case 4: cout<<"Elements of Queue are: "<<endl;
					display();
					break;
			default : cout<<"Invalid operation"<<endl;
							break;

		}

		cout<<"Do you want to continue? (y/n)"<<endl;
		cin>>ch;
	}

	return 0;
}

