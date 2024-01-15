#include <stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

int top=-1;
char stack[20];
int size=20;
//Function declaration
void push(char);
char pop();
char peek();
int precedence(char);
void postFix(char []);

int main()
{
	char inp[20];

	printf("Enter exp :");
	scanf("%s",inp);

	postFix(inp);

	printf("\nbye\n");
	
	return 0;
}

void postFix(char exp[])
{
	char ch;
	int index=0;

	printf("Output:\n");

	while(exp[index]!='\0')
	{

		ch=exp[index];

		if(ch>='a' && ch<'z')
		{
			printf("%c",ch);
		}

		else
		{
			while(precedence(peek())>=precedence(ch))             //stack >= current then pop
			{
				printf("%c",pop());

			}

			push(ch);

		}

		index++;
	}
	
	while(top!=-1)
	{
		printf("%c",pop());
	}
	

}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

void push(char ch)
{
	if(top==size-1)
	{
		printf("Stack is full\n");
		return;
	}

	top++;
	stack[top]=ch;

}

char pop()
{
	char ch;

	if(top==-1)
	{
		return -1;
	}

	ch=stack[top];
	top--;

	return ch;
}

char peek()
{
	char ch;

	if(top==-1)
	{
		return -1;
	}

	ch=stack[top];

	return ch;
}