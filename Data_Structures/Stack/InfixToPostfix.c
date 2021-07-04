#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

//push operation

void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
//Pop operation
char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under-flow: Invalid expression");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

//Function to set priority of precedence of operators

int precedence(char operat)
{
	if(operat == '^')       // exponent operator, highest precedence
	{
		return(3);
	}
	else if(operat == '*' || operat == '/')
	{
		return(2);
	}
	else if(operat == '+' || operat == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;

	push('(');                               // push '(' onto stack
	strcat(infix_exp,")");                  // add ')' to infix expression

	i=0;
	j=0;
	item=infix_exp[i];

	while(item != '\0')        // run loop till end of infix expression
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              //Here  operand symbol is added to postfix expression
			j++;
		}
		else if(is_operator(item) == 1)
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  // pop all higher precedence operator
				j++;
				x = pop();                       // add them to postfix expression
			}
			push(x);

			push(item);                 // push current operator symbol onto stack
		}
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i];
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0';
}
int main()
{
	char infix[SIZE], postfix[SIZE];


	printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter Infix expression : ");
	gets(infix);
	InfixToPostfix(infix,postfix);                   /* call to convert */
	printf("Postfix Expression: ");
	puts(postfix);                     /* print postfix expression */
	return 0;
}

