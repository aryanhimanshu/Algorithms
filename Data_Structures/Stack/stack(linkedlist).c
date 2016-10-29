#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next; 
};

struct node* top;

void push(int data);
int pop();

int main(void)
{
    int i,j,k,n;
    
    printf("Enter the number of operations you want to perform:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter the operation you wan to perform:\n");
        printf("1.Push\n2.Pop\n");
        scanf("%d",&k);
        
        if(k==1)
        {
            printf("Enter the element you want to push:");
            scanf("%d",&j);
            push(j);
        }
        else if(k==2)
        {
            j=pop();
            printf("The popped value is:%d\n",j);
        }
        
        
    }
}

void push(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=top;
    top=temp;
}

int pop()
{
    struct node* temp;
    int data;
    if(top==NULL)
    {
        return -1;
    }
    else
    {
        temp=top;
        top=top->next;
        data=temp->data;
        free(top);   
        return data;
    }
}
