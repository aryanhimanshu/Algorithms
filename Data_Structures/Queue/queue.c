#include<stdio.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1;
void Insert_Element();
void Delete_Element();
void Display_Queue();
void Empty_Queue();

int main()
{
	int option;
	printf(">>> c program to implement queue operations <<<");
	do
	{
		printf("\n\n 1.Insert an element");
		printf("\n 2.Delete an element");
		printf("\n 3.Display queue");
		printf("\n 4.Empty queue");
		printf("\n 5.Exit");
		printf("\n Enter your choice: ");
		scanf("%d", &option);
		switch (option)
		{
			case 1: Insert_Element();
				break;
			case 2: Delete_Element();
				break;
			case 3: Display_Queue();
				break;
			case 4: Empty_Queue();
				break;
			case 5: return 0; /*program ends*/
		}

	} while (option != 5);
}

void Insert_Element()
{
	int num;
	if (rear < MAX - 1)
	{
		if (front == -1)
			/*when queue is initially empty */
			front = 0;
		printf("\n Enter the number to be inserted: ");
		scanf("%d", &num);
		rear = rear + 1;
		queue[rear] = num;
	}
	else
	{
		printf("\n Queue OverFlow Occured");
	}
}

void Delete_Element()
{
	int element;

	if (front == -1 || front > rear)
	{
		printf("\n Queue Underflow occured.\n");
		return;
	}
	else
	{
		element = queue[front];
		printf("\n Element deleted from queue is : %d", element);
		front = front + 1;
	}
}

void Display_Queue()
{
	int i;
	if (front == -1 || front > rear)
		printf("\n No elements to display");
	else
	{
		printf("\n The queue elements are:\n ");
		for (i = front; i <= rear; i++)
		{
			printf("\t %d", queue[i]);
		}
	}
}

void Empty_Queue()
{
	/*Reset queue or Creates Empty queue*/
	front = -1;
	rear = -1;
	printf("\n New Queue created successfully.");
}


