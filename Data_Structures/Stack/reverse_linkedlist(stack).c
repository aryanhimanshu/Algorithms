#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top;



void push(int data);
int  pop();

int main(void)
{
    int i,j,k,n,x;
    
    printf("Enter the number of elements in the list:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter the element:");
        scanf("%d",&x);
        push(x);
    }    
    
        
    for(j=0;j<n;j++)
    {
        k=pop();
        printf("%d ",k);
        
    }
    printf("\n");
}

void push(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=top;
    
    top=temp;   
    
}

int  pop()
{   
    int data;
    struct node* temp;
    if(top==NULL)
    {
        return -1;
    }
    else
    {
        temp=top;
        top=top->next;
        data=temp->data;
        free(temp);
        return data;
    }
}