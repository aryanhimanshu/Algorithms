#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *prev;
	int value;
	struct Node *next;
}*head =  NULL, *tail = NULL;

void insertionAtBegining(int data) {
	struct Node *current =  head;
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode-> value = data;
	if (current == NULL){
		newNode->prev = NULL;
		newNode->next = NULL;
		head = newNode;
		tail = newNode;	
	}else{
		newNode->prev = NULL;
		newNode-> next = head;
		head->prev = newNode;
		head =  newNode;
	}
}

void insertionAtTail(int data){
	struct Node *current =  head;
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode-> value = data;
	if (current == NULL){
		newNode->prev = NULL;
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}while(current->next != NULL){
		current = current->next;	
	}
	current->next = newNode;
	newNode->prev = current;
	newNode->next = NULL;
	tail = newNode;
}

void insertBetween(int data, int location){
	struct Node *current =  head;
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode-> value = data;
	if (current == NULL){
		newNode->prev = NULL;
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}else{
		struct Node *previousNode;
		int i=1;
		while (i<location-1 && current != NULL){
			current = current->next;
			i++;
		}
		newNode->next = current->next;
		newNode->prev = current;
		if (current->next != NULL){
			current->next->prev = newNode;
		}
		current->next = newNode;
	}
}

void deltionAtBegining(){
	if(head == NULL && tail == NULL){
		printf("LIST IS EMPTY");
	}
	struct Node *current = head;
	head =  current->next;
	current->next->prev = NULL;
	free(current);
}

void deletionAtTail(){
	if(head == NULL && tail == NULL){
		printf("LIST IS EMPTY");
	}else if(head == tail){
		free(head);
		head = NULL;
		tail = NULL;
	}
	else{
		struct Node *current = head;
		while(current->next != NULL){
			current = current->next;	
		}
		current->prev->next = NULL;
		tail = current->prev;
		free(current);	
	}
	

}

void deleteSpecific(int position){
	struct Node *current = head;
	if(head == NULL && tail == NULL){
		printf("LIST IS EMPTY");
	}else{	
		for(int i=1; i<position && current!=NULL; i++){
			current = current->next;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(current);
	}

}
void printList(){
	struct Node *current = head;
	printf("head--> %p \n",head);
	while (current != NULL ){
		printf("%p --->",current->prev);
		printf("%d --->",current->value);
		printf("%p ",current->next);
		printf("\n");
		current = current->next;
	}
	printf("tail--> %p\n", tail);
}

void display(){
	struct Node *current = head;
	printf("head--> %d \n",head->value);
	while (current != NULL ){
		printf("%d <--->",current->value);
		current = current->next;
	}
	printf("NULL\n");	
	printf("tail--> %d\n", tail->value);
}
void reverse(){
	struct Node *temp;
	struct Node *current = head;
	while(current != NULL){
		temp = current->next;
		current->next = current->prev;
		current->prev =  temp;
		current= temp;
	}
	temp = head;
	head = tail;
	tail=temp;
}

void main(){
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
					case 1:  insertionAtBegining(value);
					break;
					case 2:  insertionAtTail(value);
					break;
					case 3:  printf("Enter the location where you wanto insert: ");
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
			case 3:  printf("How do you want to Delete: \n1. From Beginning\n2. From End\n3. Specific\nEnter your choice: ");
			scanf("%d",&choice1);
			switch(choice1)
			{
				case 1:  deltionAtBegining();
				break;
				case 2:  deletionAtTail(value);
				break;
				case 3:  printf("Enter the value which you want to delete: ");
				scanf("%d",&loc2);
				deleteSpecific(loc2);
				break;
				default:    printf("\nWrong Input!! Try again!!!\n\n");
				goto mainMenu;
			}
			break;
			case 4:
			reverse();
			display();
			goto mainMenu;
			case 5:  exit(0);
			default: printf("\nWrong input!!! Try again!!\n\n");
		}
	}
}