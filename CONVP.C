#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100

void push(char item,char stack[], int *top)
{
	if(*top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		*top = *top+1;
		stack[*top] = item;
	}
}

char pop(char stack[], int *top)
{
	char item ;

	if(*top <0)
	{
		printf("Stack under flow: invalid infix expression");
		getch();
		return 0;
	}
	else
	{
		item = stack[*top];
		*top = *top-1;
		return item;
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


int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[],char stack[],int *top)
{
	int i, j;
	char item;
	char x;

	push('(',stack,top);
	strcat(infix_exp,")");

	i=0;
	j=0;
	item=infix_exp[i];

	while(item != '\0')
	{
		if(item == '(')
		{
			push(item,stack,top);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;
			j++;
		}
		else if(is_operator(item) == 1)
		{
			x=pop(stack,top);
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;
				j++;
				x = pop(stack,top);
			}
			push(x,stack,top);

			push(item,stack,top);
		}
		else if(item == ')')
		{
			x = pop(stack,top);
			while(x != '(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop(stack,top);
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");
			getch();
			exit(1);
		}
		i++;


		item = infix_exp[i];
	}
	if(*top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getch();
		exit(1);
	}

	postfix_exp[j] = '\0';

}


int main()
{
	char stack[SIZE];
	int top=-1;
	char infix[SIZE], postfix[SIZE];
	clrscr();
	printf("\nEnter Infix expression : ");
	gets(infix);

	InfixToPostfix(infix,postfix,stack,&top);
	printf("Postfix Expression: ");
	puts(postfix);
	getch();
	return 0;
}

