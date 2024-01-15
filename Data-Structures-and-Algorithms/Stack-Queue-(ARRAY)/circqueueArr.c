#include<stdio.h>
#include<stdlib.h>
#define max 5
void enqueue(int *, int *, int *);
int dequeue(int *, int *, int *);
void display(int *);
int peep(int *, int *);
void isQueueFull(int *, int *);
void isQueueEmpty(int *);
int main()
{
	int arr[max];
	for(int i = 0; i < max; i++)									//initialise entire queue by default value of -99
	{
		arr[i] = -99;
	}
	int front = -1, rear = -1;
	int ch, item, pip;

	while(1)
	{
		printf("----SELECT OPTION----\n");
		printf("1-> ENQUEUE\n2-> DEQUEUE\n3-> DISPLAY QUEUE STATUS\n4-> PEEP\n5-> IS QUEUE IS FULL?\n6-> IS QUEUE EMPTY?\n7-> EXIT\n");
		scanf("%d", &ch);
		printf("\n");

		switch(ch)
		{
			case 1:
				enqueue(arr, &front, &rear);
				break;
			case 2:
				item = dequeue(arr, &front, &rear);
				printf("%d was dequeued from the queue!\n", item);
				break;
			case 3:
				display(arr);
				break;
			case 4:
				pip = peep(arr, &front);
				break;
			case 5:
				isQueueFull(&front, &rear);
				break;
			case 6:
				isQueueEmpty(&front);
				break;
			case 7:
				exit(1);
			default:
				printf("ENTER A VALID CHOICE!\n");
		}
	}
	return 0;
}

void enqueue(int *arr, int *front, int *rear)
{
	int ele;
	printf("ENTER THE ELEMENT TO ENQUEUE: ");
	scanf("%d", &ele);

	if((*front == 0) && (*rear == max-1) || (*rear+1 == *front))			//check queue full condition
	{
		printf("QUEUE IS FULL!\n");
		return;
	}
	if(*rear == max-1)														//check if rear is at final position, if so rotate it to first position
	{
		*rear = 0;
	}
	else																	//if not, increment it by one
	{
		(*rear)++;	
	}
	arr[(*rear)] = ele;														//put user given data in queue at position pointed by rear
	if(*front == -1)														//when initializing queue for the very first time
	{
		*front = 0;
	}
}

int dequeue(int *arr, int *front, int *rear)
{
	if(*front == -1)														//check for queue empty condition, return -1 if so
	{
		printf("QUEUE IS EMPTY!\n");
		return -1;
	}
	int item = arr[*front];													//copy data to local variable to display later
	arr[*front] = -99;														// make data position data to default value of -99
	if(*front == max - 1 && *rear != max - 1)								//check if it is last element was dequeued, if so shift front to first address of queue
	{
		*front = 0;
	}
	else																	//if front and rear become equal, reset queue
	{
		if(*front == *rear)
		{
			*front = -1;
			*rear = -1;
		}
		else																//incrememnt front by one 
		{
			(*front)++;
		}	
	}
	return item;															//return copied value
}

void display(int *arr)
{
	for(int i = 0; i < max; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

int peep(int *arr, int *front)												//same as pop but just displays last element data rather than changing it to default value and incrementing front
{
	if(*front == -1)
	{
		printf("QUEUE IS EMPTY!\n");
		return -1;
	}
	int item = arr[*front];
	
	return item;
}
void isQueueFull(int *front, int *rear)
{
	if((*front == 0) && (*rear == max-1) || (*rear+1 == *front))
	{
		printf("QUEUE IS FULL!\n");
	}
	else
	{
		printf("QUEUE IS NOT FULL!\n");
	}
}
void isQueueEmpty(int *front)
{
	if(*front == -1)
	{
		printf("QUEUE IS EMPTY!\n");
	}
	else
	{
		printf("QUEUE IS NOT EMPTY!\n");
	}
}