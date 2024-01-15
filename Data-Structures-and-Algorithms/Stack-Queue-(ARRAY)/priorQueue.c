#include<stdio.h>
#include<stdlib.h>
struct queue 														//structure to store both priority and data  
{
	int ele;
	int pri;
};

void enqueue(struct queue *, int *, int *, int);
void dequeue(struct queue *, int *, int *);
void peep(struct queue *, int *, int *);
void display(struct queue *);
void isQueueEmpty(int *, int *);
void isQueueFull(int *, int *);
int priorAssign(int);


int main()
{
	struct queue q[5];
	int front = -1, rear = -1;					//initializing front and rear to -1 
	
	for(int i = 0; i < 5; i++)					//initialise entire queue by default value of 0
	{
		q[i].ele = 0;
		q[i].pri = 0;
	}
	
	int ch;
	int ele;
	while(1)
	{
		printf("Enter the Choice: \n");
		printf("1-> ENQUEUE\n2-> DEQUEUE\n3-> PEEP\n4-> DISPLAY QUEUE\n5-> IS QUEUE EMPTY?\n6-> IS QUEUE FULL?\n7-> EXIT\n");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
                printf("Enter a two-digit number for the Element: ");
                scanf("%d", &ele);

                if (ele >= 10 && ele <= 99)										//take value between 10 to 99 for filling queue
                {
                    enqueue(q, &front, &rear, ele);
                }
                else
                {
                    printf("Invalid input. Enter a two-digit number!\n");		//put user in menu if input is out of bounds
                }
                break;
			case 2:
				dequeue(q, &front, &rear);
				break;
			case 3:
				peep(q, &front, &rear);
				break;
			case 4:
				display(q);
				break;
			case 5:
				isQueueEmpty(&front, &rear);
				break;
			case 6:
				isQueueFull(&front, &rear);
				break;
			case 7:
				exit(1);
			default:
				printf("Enter a Valid Choice!\n");
		}
	}
}
void enqueue(struct queue *q, int *front, int *rear, int ele)
{
	if (*rear == 4)
    {
        printf("Queue is full!\n");
        return;
    }

    int priority = priorAssign(ele);

    int i = *rear;									//priority based input [the input will automatically be sorted in descending order when inputting new element]
    while (i >= *front && priority > q[i].pri)
    {
        q[i + 1] = q[i];
        i--;
    }

    q[i + 1].ele = ele;
    q[i + 1].pri = priority;

    if(*front == -1)								//initialise queue when enterring first element
	{
		*front = 0;
	}
    (*rear)++;
}
void dequeue(struct queue *q, int *front, int *rear)
{
	if (*front == *rear)								//check for queue empty condition
    {
        printf("Queue is empty!\n");
        return;
    }
    int item;
    item = q[*front].ele;
    
    for (int i = *front; i < *rear; i++)				//travel till least priority queue element while shifting each to left by one starting from the front of the queue
    {
        q[i] = q[i + 1];
    }
	q[*rear].ele = 0;									//make array element and its priority zero
    q[*rear].pri = 0;
    (*rear)--;											//decrease rear pointer (array index number) by one.

    printf("%d was dequeued from the queue!\n", item);
}
void peep(struct queue *q, int *front, int *rear)		//same as dequeue but instead of deleting element just display element next in line to be dequeued
{
	if (*front == *rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    
    int high = q[*front].pri;
    int high_prior = q[*front].ele;

    for (int i = *front + 1; i <= *rear; i++)
    {
        if (q[i].pri > high)
        {
            high = q[i].pri;
            high_prior = q[i].ele;
        }
    }
    printf("%d is at the end of the priority queue!\n", high_prior);
}
void display(struct queue *q)
{
	printf("|ELEMENT|PRIORITY|\n");
	for(int i = 0; i < 5; i++)
	{
		printf("|%d|%d|\t", q[i].ele, q[i].pri);
	}
	printf("\n");
}
void isQueueEmpty(int *front, int *rear)
{
	if (*front == *rear)
	{
        printf("Yes, Queue is empty.\n");
	}
    else
    {
        printf("No, Queue is not empty.\n");
    }
}
void isQueueFull(int *front, int *rear)
{
	if (*rear == 4)
	{
        printf("Yes, Queue is full.\n");
	}
    else
    {
        printf("No, Queue is not full.\n");	
    }
}
int priorAssign(int ele) 								//function to assign priority based on number of factors user defined number has
{
	int prio = 0;
    for (int i = 1; i <= ele; i++)
    {
        if (ele % i == 0)
        {
            prio++;
        }
    }
    return prio;
}