#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define size 100

double stack[size];
void push(double val);
double pop();
double evaluation(char []);
int top = -1;

int main()
{
    double result;
    printf("Assumption: Evaluation of a postfix expression containing numbers only\n ");
    char exp[size];
    printf("Enter postfix expression: ");
    gets(exp);
     result = evaluation(exp);
    printf("Result = %.3lf\n",result);      //to print upto 3 decimal of precision
    return 0;
}
double evaluation(char exp[])
{
    int i = 0;
    double n1,n2,value;
    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            printf("value of pushed = %lf\n",(double)(exp[i] -'0'));
            push((double)(exp[i]- '0'));    //Character of expression is converted into char to int first
            i++;                            //by subtracting with ascii value of 0 and then typecasting it into double
        }
        else{
            n1 = pop();
            printf("Value of n1 and top = %lf and %d\n",n1,top);
            n2 = pop();
            printf("Value of n1 and n2 = %lf and %d\n",n1,top);
            switch(exp[i])
            {
            case '+':
                value = n1 + n2;    break;
            case '-':
                value = n1 - n2;    break;
            case '*':
                value = n1 * n2;    break;
            case '/':
                value = n1 / n2;    break;
            case '%':
                value = (int)n1 % (int)n2;    break;    //Modulus operator need integer as argument
            case '^':
                value =  pow(n1,n2);    break;
            }
            push(value);
            i++;
        }

    }
    return (pop());
}
void push(double val)
{
    if(top == size - 1)
    {
        printf("\nStack overflow, Invalid expression OR Increase the size of stack\n");
    }
    else
    {
        printf("\nPu1.value of top = %d\n",top);
        top++;
        stack[top] = val;
    }
     printf("\nPu2.value of top and value pushed = %d and %lf\n",top,val);
}
double pop()
{
    double val1;
    if(top == -1)
    {
        printf("\nStack underflow, invalid Expression");
    }
    else{
            printf("\po1.nvalue of top = %d\n",top);
        val1 = stack[top--];
    }
     printf("\p02.nvalue of top and value popped= %dand %lf\n",top,val1);
    return val1;
}
