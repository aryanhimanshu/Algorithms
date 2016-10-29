#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    long int data;
    struct node* left;
    struct node* right;
};

struct node* root;

struct node* insert(struct node* root, long int data);
long int search(struct node* root,long int data);
struct node* getnewnode(long int data);


int main(void)
{
    long int i,j,k,n,t;
    
    printf("Enter the number of operations:");
    scanf("%ld",&t);
    
    for(i=0;i<t;i++)
    {
        printf("Enter the operation:\n1.Insert\n2.Search\n3.Exit\n");
        scanf("%ld",&k);
        
        switch(k)
        {
            case 1: printf("Enter the number to insert:");
                    scanf("%ld",&n);
                    root=insert(root,n);
                    break;
            
            case 2: printf("Enter the number to search:");
                    scanf("%ld",&n);
                    j=search(root,n);
                    if(j==0)
                    {
                        printf("Found\n");
                        break;
                    }
                    else if(j==1)
                    {
                        printf("Not Found\n");
                        break;
                    }
                    
            
            case 3: exit(0);
                   
        }
    }
}

long int search(struct node* root,long int data)
{   
    long int j;
    if(root==NULL)
    {   
        j=1;
        return j;
    }
    else if(root->data>data)
    {
        j=search(root->left,data);
    }
    else if(root->data<data)
    {
        j=search(root->right,data);
    }
    else
    {
        j=0;
        return j;
    }
}

struct node* getnewnode(long int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

struct node* insert(struct node* root, long int data)
{
    if(root==NULL)
    {
        root=getnewnode(data);
    }
    else if(root->data>data)
    {
        root->left=insert(root->left,data);
    }
    else if(root->data<data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}