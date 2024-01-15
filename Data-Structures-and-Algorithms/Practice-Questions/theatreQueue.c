/*

Q3: Write a program to implement a queue for management of crowd at a movie
counter which has a capacity of 8 customer at a time. Implement add in queue()
function for enqueue operation. If the number of customers are more than 8 then a
warning of "Limit exceeded" should be displayed.

● Write a function remove customer() to remove the customer from the front end of
the queue when he/she gets the ticket (dequeue() functionality).
● Write a function for counter closed() with the functionality that no customer
should be present at the counter (Exit( ) functionality).

*/



#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 8

void display(int *);
void enqueue(int *, int *, int *, int);
int dequeue(int *, int *, int *);
void counterClosed(int *, int *, int *);

int main() 
{
    int queue[MAX_CAPACITY];
    int choice, ele;

    int front = -1;
    int rear = -1;

    for (int i = 0; i < MAX_CAPACITY; i++) 
    {
        queue[i] = -99;                                                                 // Initialize the array elements to a initial value (-99).
    }

    while (1) 
    {
        printf("Select:\n1. Add Customer\n2. Remove Customer\n3. Counter Closed\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear - front < MAX_CAPACITY - 1) 
                {
                    printf("Enter customer ID: ");
                    scanf("%d", &ele);
                    enqueue(queue, &front, &rear, ele);
                } else 
                {
                    printf("Limit exceeded. Queue is full.\n");
                }
                break;

            case 2:
                ele = dequeue(queue, &front, &rear);
                if (ele != -1) 
                {
                    printf("Customer with ID %d got the ticket and was removed from the queue.\n", ele);
                }
                break;

            case 3:
                counterClosed(queue, &front, &rear);
                printf("Counter is closed. All customers have been removed from the queue.\n");
                break;

            case 4:
                display(queue);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}

void display(int *q) 
{
    for (int i = 0; i < MAX_CAPACITY; i++) 
    {
        printf("%d\t", q[i]);
    }
    printf("\n\n");
}

void enqueue(int *q, int *f, int *r, int ele) 
{
    if (*r == MAX_CAPACITY - 1)                             //Queue full check
    {
        printf("Queue is full. Cannot add more customers.\n");
        return;
    }

    if (*f == -1)                                           //initialize queue the very first time
    {
        *f = 0;
    }

    (*r)++;                                                 //rear++
    q[*r] = ele;                                            //add element to end of queue    
}

int dequeue(int *q, int *f, int *r) 
{
    if (*f == -1)                                           //Queue empty check 
    {
        printf("Queue is empty. No customers to remove.\n");
        return -1;
    }

    int ele = q[*f];                                        //local variable = dequeued element
    q[*f] = -99;

    if (*f == *r)                                           //reset queue if last element dequeued
    {
        *f = -1;
        *r = -1;
    } else                                                  //else front++
    {
        (*f)++;
    }

    return ele;
}

void counterClosed(int *q, int *f, int *r)                  //dequeue all and reset queue
{
    for (int i = 0; i < MAX_CAPACITY; i++) 
    {
        q[i] = -99;
    }
    *f = -1;
    *r = -1;
}
