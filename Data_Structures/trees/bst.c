#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root;

void inorder(struct node* root);
void preorder(struct node* root);
void postorder(struct node* root);
struct node* insert(struct node* root,int data);
struct node* getnewnode(int data);
struct node* delete(struct node* root,int data);
struct node* findmin(struct node* root);

int main(void)
{
    int i,j,data,option,number;

    printf("Enter the number of operations you want to perform:\n");
    scanf("%d",&number);

    for(i=0;i<number;i++)
    {
        printf("1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n");
        scanf("%d",&option);

        switch(option)
        {
            case 1: printf("Enter the element you wnat to insert:\n");
                    scanf("%d",&data);
                    root=insert(root,data);
                    break;
            case 2: printf("Enter the element you  want to delete:\n");
                    scanf("%d",&data);
                    root=delete(root,data);
                    break;
            case 3: inorder(root);
                    printf("\n");
                    break;
            case 4: preorder(root);
                    printf("\n");
                    break;
            case 5: postorder(root);
                    printf("\n");
                    break;
        }
    }
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {   
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

struct node* getnewnode(int data)
{
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* delete(struct node* root, int data)
{
    if(root==NULL)
    {
        return root;
    }
    else
    {
        if(root->data>data)
        {
            root->left=delete(root->left,data);
        }
        else if(root->data<data)
        {
            root->right = delete(root->right,data);
        }
        else
        {
            if(root->left==NULL && root->right==NULL)         //no child
            {
                free(root);
                root=NULL;
                return root;
            }
            else if(root->left!=NULL && root->right==NULL)    //one child
            {
                struct node* temp=root;
                root=root->left;
                free(temp);
                return root;
            }
            else if(root->left==NULL && root->right!=NULL)
            {
                struct node* temp=root;
                root=root->right;
                free(temp);
                return root;
            }
            else if(root->left!=NULL && root->right!=NULL)
            {
                struct node* temp = findmin(root->right);
                root->data = temp->data;
                root->right = delete(root->right,temp->data);
                return root;
            }
            
        }
    }
}

struct node* insert(struct node* root, int data)
{
    if(root==NULL)
    {
        root=getnewnode(data);
        return root;
    }
    else
    {
        if(root->data>data)
        {
            root->left=insert(root->left,data);
        }
        else if(root->data<data)
        {
            root->right=insert(root->right,data);
        }
        return root;
    }
}

struct node* findmin(struct node* root)
{
    struct node* current = (struct node*)malloc(sizeof(struct node));

    while(current->left!=NULL)
    {
        current=current->left;
    }

    return current;
}
