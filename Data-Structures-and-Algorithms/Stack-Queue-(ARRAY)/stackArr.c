#include<stdio.h>
#include<stdlib.h>
#define max 5
void push(int *, int *);
int pop(int *, int *);
int peep(int *, int *);
void display(int *);
int main()
{
	int arr[max];
	for(int i = 0; i < max; i++)				//initialize stack to default value of -99
	{
		arr[i] = -99;
	}
	int top = -1;								//initialize stack top to default value of -1
	int ch, pop_item, peep_item;

	while(1)
	{
		printf("----SELECT OPTION----\n");
		printf("1-> PUSH\n2-> POP\n3-> DISPLAY STACK STATUS\n5->PEEP\n5-> EXIT\n");
		scanf("%d", &ch);
		printf("\n");

		switch(ch)
		{
			case 1:
				push(arr, &top);
				break;
			case 2:
				pop_item = pop(arr, &top);
				printf("%d was popped from the stack!\n", pop_item);
				break;
			case 3:
				display(arr);
				break;
			case 4:
				peep_item = pop(arr, &top);
				printf("%d is on the stack top!\n", peep_item);

				break;
			case 5:
				exit(1);
		}
	}
	return 0;
}
void push(int *arr, int *top)
{
	int ele;
	printf("ENTER THE ELEMENT TO PUSH: ");
	scanf("%d", &ele);

	if(*top == max-1)							//check for stack full condition
	{
		printf("STACK IS FULL\n");
		return;
	}
	(*top)++;									//increase pointer(array index number) by one, pointer to stack top
	arr[(*top)] = ele;							// add elemnent to top of stack
}

int pop(int *arr, int *top)
{
	if(*top == -1)
	{
		printf("STACK IS EMPTY\n");				// check for stack empty condition
		return -1;
	}
	int item = arr[*top];						//copy element on top of stack to local variable
	arr[*top] = -99;							//reinitialized stack top to default value
	(*top)--;									//decrease pointer(array index number) by one, pointer to stack top
	return item;								//return popped item value
}

int peep(int *arr, int *top)
{
	if(*top == -1)
	{
		printf("STACK IS EMPTY\n");				// check for stack empty condition
		return -1;
	}
	int item = arr[*top];						//copy element on top of stack to local variable
	return item;								//return popped item value
}

void display(int *arr)
{
	for(int i = max-1; i >= 0; i--)				//normal array dispaly approach by itteration
	{
		printf("|\t%d\t|\n", arr[i]);
	}
	printf("\n");
}
