#include<stdio.h>
#include<stdlib.h>

#define max 5

void enqueue(int *, int *, int *);
int dequeue(int *, int *, int *);
int peep(int *, int *);
void display(int *);
int main()
{
	int arr[max];
	for(int i = 0; i < max; i++) 							//initialise entire queue by default value of -99
	{
		arr[i] = -99;
	}
	int front = -1, rear = -1;
	int ch, item, item2;

	while(1)
	{
		printf("----SELECT OPTION----\n");
		printf("1-> ENQUEUE\n2-> DEQUEUE\n3->PEEP\n4-> DISPLAY QUEUE STATUS\n5-> EXIT\n");
		scanf("%d", &ch);
		printf("\n");

		switch(ch)
		{
			case 1:
				enqueue(arr, &front, &rear);
				break;
			case 2:
				item = dequeue(arr, &front, &rear);
				if(item == -1)														//return from queue empty check
					{
						printf("QUEUE is empty\n");
					}else
					{
						printf("%d was dequeued from the queue!\n", item);	
					}
				break;
			case 3:
				item2 = peep(arr, &front);
				if(item2 == -1)
					{
						printf("QUEUE is empty\n");									//return from queue empty check
					}else
					{
						printf("%d is at the beginning of the queue!\n", item2);
					}
				break;
			case 4:
				display(arr);
				break;
			case 5:
				exit(1);
		}
	}
	return 0;
}

void enqueue(int *arr, int *front, int *rear)
{
	int ele;
	printf("ENTER THE ELEMENT TO ENQUEUE: ");
	scanf("%d", &ele);

	if(*rear == max-1)									//check for queue full condition
	{
		printf("QUEUE IS FULL!\n");
		return;
	}

	(*rear)++;											//increase rear pointer(array index number) by one
	arr[(*rear)] = ele;									//add element to end of queue
	if(*front == -1)									//condition to initilise front pointer(array index number) when addaing first ever element in queue
	{
		*front = 0;
	}
}

int dequeue(int *arr, int *front, int *rear)
{
	if(*front == -1) 									//check for queue empty condition
	{
		return -1;
	}
	int item = arr[*front];								//copied item to local variable
	arr[*front] = -99;									//reinitialized array element to default value
	if(*front == *rear)									
	{
		*front = -1;									//reinitialize entire queue if front == rear; that is when queueu becomes fully empty
		*rear = -1;
	}
	else
	{
		(*front)++;										//increase front pointer(array index number) by one
	}
	return item;										//return popped item
}

int peep(int *arr, int *front)
{
	if(*front == -1)									//check for queue empty condition
	{
		return -1;
	}
	int i = arr[*front];								//copied item to local variable		
	
	return i;											//return peeped item
}

void display(int *arr)
{
	for(int i = 0; i < max; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}