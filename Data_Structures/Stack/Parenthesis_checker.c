#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define stack_size 50   //Stack size is taken in such a way that it should not be less than expression size
int top=-1;
int stk[stack_size];
void push(char);
char pop();

int main()
{
    char exp[stack_size],temp;
    int i,flag=1;
    printf(" \t- - - - - - - Parenthesis Checker tool - - - - - - \n");
    printf("\nEnter an expression: ");
    gets(exp);
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            push(exp[i]);
        if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
            if(top==-1)
                flag=0;
            else
            {
            temp=pop();
            if(exp[i]==')'&&(temp=='{'||temp=='['))
                flag=0;
            if(exp[i]=='}'&&(temp=='('||temp=='['))
                flag=0;
            if(exp[i]==']'&&(temp=='('||temp=='{'))
                flag=0;
        }
        }
        if(top>=0)
            flag=0;
        if(flag==1)
            printf("\nValid Expression!!!\n");
        else
            printf("\n! ! ! Invalid Expression.\n");

    return 0;
}
void push(char c)
{
    if(top==(stack_size-1))
        printf("\nStack Overflow ! ! !\n");
    else{
        top=top+1;
        stk[top]=c;
    }
}
char pop()
{
    if(top==-1)
        printf("\nStack Underflow! ! !\n");
    else
        return (stk[top--]);
}
