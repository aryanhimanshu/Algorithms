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
struct node* insert(struct node* root, int data);
struct node* getnewnode(int data);
int finmin(struct node* root);
int findmax(struct node* root);

int main(void)
{
    int i,j,data,option,number;


    printf("Enter the number of operations you want to perform:\n");
    scanf("%d",&number);

    for(i=0;i<number;i++)
    {
        printf("1.Insert\n2.Find Minimum\n3.Find Maximum\n4.Inorder\n5.Postorder\n6.Preorder\n");
        scanf("%d",&option);

        switch(option)
        {
            case 1: printf("Enter the numbr to print:\n");
                    scanf("%d",&data);
                    root=insert(root,data);
                    break;
            case 2: data = findmin(root);
                    printf("MIN DATA:%d\n",data);
                    break;
            case 3: data = findmax(root);
                    printf("MAX DATA:%d\n",data);
                    break;
            case 4: inorder(root);
                    printf("\n");
                    break;
            case 5: postorder(root);
                    printf("\n");
                    break;
            case 6: preorder(root);
                    printf("\n");
                    break;
            default: printf("INVALID\n");
                     exit(0);
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
    struct node* newnode =(struct node* )malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=data;
    return newnode;
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

int findmin(struct node* root)
{
    struct node* current= root;

    while(current->left!=NULL)
    {
        current=current->left;
    }

    return current->data;
}

int findmax(struct node* root)
{
    struct node* current=root;

    while(current->right!=NULL)
    {
        current=current->right;
    }

    return current->data;
}
