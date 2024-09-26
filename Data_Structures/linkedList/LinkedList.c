#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*head = NULL;

void insertAtBeginning(int value)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	if(head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	printf("\nOne node inserted!!!\n");
}
void insertAtEnd(int value) {
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	if(head == NULL)
		head = newNode;
	else
	{
		struct Node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	printf("\nOne node inserted!!!\n");
}
void insertBetween(int value, int loc1) {
	struct Node *temp;
	struct Node *allocate;
	allocate = (struct Node*)malloc(sizeof(struct Node));
	allocate->data = value;
	if(head == NULL)
	{
		allocate->next = head;
		head = allocate;
	}
	else
		temp = head;
	{
		for (int i = 0; i < loc1-2; i++)
		{
			temp = temp->next;
		}
		allocate->next = temp->next;
		temp->next = allocate;
	}
	printf("\nOne node inserted!!!\n");
}

void removeBeginning() {
	if(head == NULL)
		printf("\n\nList is Empty!!!");
	else
	{
		struct Node *temp = head;
		if(head->next == NULL)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			head = temp->next;
			free(temp);
			printf("\nOne node deleted!!!\n\n");
		}
	}
}
void removeEnd(){
	if(head == NULL)
	{
		printf("\nList is Empty!!!\n");
	}
	else
	{
		struct Node *temp1 = head,*temp2;
		if(head->next == NULL)
			head = NULL;
		else
		{
			while(temp1->next != NULL)
			{
				temp2 = temp1;
				temp1 = temp1->next;
			}
			temp2->next = NULL;
		}
		free(temp1);
		printf("\nOne node deleted!!!\n\n");
	}
}
void removeSpecific(int delValue) {
	struct Node *temp1 = head, *temp2;
	while(temp1->data != delValue)
	{
		if(temp1 -> next == NULL){
			printf("\nGiven node not found in the list!!!"); 
		}
		temp2 = temp1;
		temp1 = temp1 -> next;
	}
	temp2 -> next = temp1 -> next;
	free(temp1);
	printf("\nOne node deleted!!!\n\n");
}

void display() {
	if(head == NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		struct Node *temp = head;
		printf("\n\nList elements are - \n");
		while(temp->next != NULL)
		{
			printf("%d --->",temp->data);
			temp = temp->next;
		}
		printf("%d --->NULL",temp->data);
	}

}

void reverse(){
	struct Node *p1,*p2,*p3,*ptr;
	p1=head;
	p2=p1->next;
	p3=p2->next;
	p1->next=NULL;
	p2->next=p1;
	while(p3!=NULL){
		p1=p2;
		p2=p3;
		p3=p3->next;
		p2->next=p1;
	}
	head=p2;
	display();
}

void main() {
	int choice,value,choice1,loc1,loc2;
	while(1){
		printf("\n\nThis is created by Prayas Jain of CSE3 (LE)\n");
		mainMenu: printf("****** MENU ******\n1. Insert\n2. Display\n3. Delete\n4. Reverse\n5. Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:  printf("Enter the value to be insert: ");
			scanf("%d",&value);
			while(1){
				printf("Where you want to insert: \n1. At Beginning\n2. At End\n3. Between\nEnter your choice: ");
				scanf("%d",&choice1);
				switch(choice1)
				{
					case 1:  insertAtBeginning(value);
					break;
					case 2:  insertAtEnd(value);
					break;
					case 3:      printf("Enter the location where you wanto insert: ");
					scanf("%d",&loc1);
					insertBetween(value,loc1);
					break;
					default:    printf("\nWrong Input!! Try again!!!\n\n");
				}
				goto subMenuEnd;
			}
			subMenuEnd:
			case 2:  display();
			break;
			case 3:  printf("How do you want to Delete: \n1. From Beginning\n2. From End\n3. Spesific\nEnter your choice: ");
			scanf("%d",&choice1);
			switch(choice1)
			{
				case 1:  removeBeginning();
				break;
				case 2:  removeEnd(value);
				break;
				case 3:      printf("Enter the value which you want to delete: ");
				scanf("%d",&loc2);
				removeSpecific(loc2);
				break;
				default:    printf("\nWrong Input!! Try again!!!\n\n");
				goto mainMenu;
			}
			break;
			case 4:
			reverse();
			goto mainMenu;
			case 5:  exit(0);
			default: printf("\nWrong input!!! Try again!!\n\n");
		}
	}
}