#include <stdio.h>
#include <stdlib.h>

struct node 																//queue element
{
	int data;
	struct node *next;
};

void enqueue(struct node**,struct node **,int);
int dequeue(struct node **,struct node **);
int peek(struct node *,struct node *);
void display(struct node *,struct node *);
void freeAllNode(struct node **);

int main()
{
	struct node *front; 												//front pointer
	struct node *rear;													//rear pointer

	front=rear=NULL;

	int choice,ret,ele;
	while(1){
		printf("Menu : 1.Enqueue\t2.Dequeue\t3.Peek\t4.Display\t5.Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter ele :");
				scanf("%d",&ele);
				enqueue(&front,&rear,ele);
				break;

			case 2:
				ret=dequeue(&front,&rear);
				if(ret==0)
				{
					printf("The Queue is empty");
				}else
				{
					printf("Dequeued Ele : %d\n",ret);	
				}
				break;

			case 3:
				ret=peek(front,rear);
				if(ret==0)
				{
					printf("The Queue is empty");
				}else
				{
					printf("Peek :%d\n",ret);
				}
				
				break;

			case 4:
				display(front,rear);
				break;

			case 5:
				exit(1);

			default:
				printf("Enter Valid Choice\n");
				break;
		}
	}

	freeAllNode(&front);										//free all nodes before exiting the program
	return 0;
}

void enqueue(struct node **front,struct node **rear,int ele)
{
	struct node* temp, *t;
   	temp = (struct node*)malloc(sizeof(struct node));

	if(temp==NULL){
		printf("memory allocation failed\n");
		return ;
	}

	t = *front;

	temp->data = ele;											//temp = data (data to be added)
	temp->next = NULL;

	if (*front == NULL) 
	{
	  *front = temp;
	  *rear=temp; 											// If the list is empty, make the new node the starting point
	  
	} else 
	{
		t= *rear;
	      t->next = temp; 										// Add the new node at the end
	      *rear=temp;
	}
}

int dequeue(struct node **front,struct node **rear)
{
	struct node *t, *temp;
	int ele;

	if (*front == NULL) 
	{
		return 0; 											// If the list is empty, return 0
	} else 
	{
		t = *front;											//t = front = store first elemnt
		temp = *front;										//temp = front = store first elemnt
		*front = t->next;										//front = t->next; that is front will now point to second element
		ele=t->data;										//ele = data of element to be dequeued
		printf("First element is deleted\n");
		free(temp); 										// Free the memory of the deleted node
	}

	return ele;
}

int peek(struct node *front,struct node *rear)
{
	struct node *t;
	int ele;

	t = rear;

	if (front == NULL) 
	{
	  return 0; 											// If the list is empty, do nothing
	} else 
	{
	  ele=t->data;											//ele = data of element to be peeked
	}

	return ele;
}

void display(struct node *front,struct node *rear)
{
	struct node *t;

	t=front;
	printf("front");
	while(t!=rear)											//traverse until t which is equal to front does not reach the rear
	{
		printf("--->||%d||",t->data);								//print data of each node
		t=t->next;											//t updated with address of next node 
	}

	printf("--->||%d||---->rear\n",t->data);							//while loop goes till t!=rear so last node will not be printed, thus manually print it
}

void freeAllNode(struct node **front)
{

	struct node *t,*temp;

	t=*front;

	while(t->next!=NULL)										//start from front to last element(last element next will be NULL)
	{
		temp=t;											//temp = t = current first element
		t=t->next;											//t updated with address of next node 
		free(temp);											
	}
}