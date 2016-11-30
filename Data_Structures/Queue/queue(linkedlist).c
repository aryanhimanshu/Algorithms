#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;
struct node* tail=NULL;

void enqueue(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=data;
    
    if(head==NULL && tail==NULL)
    {
        head=tail=temp;
        return;
    }
    
    tail->next=temp;
    tail=temp;
    
}

int dequeue()
{   
    int x;
    struct node* temp=head;
    if(head==NULL)
    {   
        printf("\n");
        return -1;
    }
    else if(head==tail)
    {
        head=tail=NULL;
    }
    else
    {
        head=head->next;
    }
    x=temp->data;
    free(temp);
    return x; 
}

int main(void)
{
    int i,j,k,n;
    
    printf("Enter the number of operations you want to perform:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter 1.Enqueue or 2.Dequeue\n");
        scanf("%d",&k);
        
        if(k==1)
        {
            printf("Enter the element to enqueue:");
            scanf("%d",&j);
            enqueue(j);
        }
        if(k==2)
        {
            j=dequeue();
            printf("Element dequeued is %d\n",j);
        }
    }
}