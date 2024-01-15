/*
Using singly linked list, implement a queue of max depth of 10, implement enqueue,
dequeue and delete queue functions for the same.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void enqueue(struct node**,struct node **,int);
int dequeue(struct node **,struct node **);
int peek(struct node *,struct node *);
void display(struct node *,struct node *);
void freeAllNode(struct node **);

int main() {
    struct node* front;
    struct node* rear;
    front = rear = NULL;

    int choice, ret, ele;
    int maxSize = 10; // Maximum size of the queue
    int currentSize = 0; // Current size of the queue

    while (1) {
        printf("Menu: 1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (currentSize < maxSize) {
                printf("Enter ele: ");
                scanf("%d", &ele);
                enqueue(&front, &rear, ele);
                currentSize++;
            } else {
                printf("Queue is full. Cannot enqueue.\n");
            }
            break;

        case 2:
            if (currentSize > 0) {
                ret = dequeue(&front, &rear);
                printf("Dequeued Ele: %d\n", ret);
                currentSize--;
            } else {
                printf("Queue is empty. Cannot dequeue.\n");
            }
            break;

        case 3:
            ret = peek(front, rear);
            if (currentSize > 0) {
                printf("Peek: %d\n", ret);
            } else {
                printf("Queue is empty. Cannot peek.\n");
            }
            break;

        case 4:
            display(front, rear);
            break;

        case 5:
            freeAllNode(&front);
            exit(1);

        default:
            printf("Enter a valid choice\n");
            break;
        }
    }
    return 0;
}
// Function to add an element to the rear of the queue
void enqueue(struct node** front, struct node** rear, int ele) {
    struct node* temp, * t;
    temp = (struct node*)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    t = *front;
    temp->data = ele;
    temp->next = NULL;

    if (*front == NULL) {
        // If the queue is empty, make the new node both the front and rear
        *front = temp;
        *rear = temp;
    } else {
        t = *rear;
        // Add the new node at the end of the queue and update the rear pointer
        t->next = temp;
        *rear = temp;
    }
}

// Function to remove and return an element from the front of the queue
int dequeue(struct node** front, struct node** rear) {
    struct node* t, * temp;
    int ele;

    if (*front == NULL) {
        printf("Queue is Empty\n");
        return 0;
    } else {
        t = *front;
        temp = *front;
        *front = t->next;
        ele = t->data;
        printf("First element is deleted\n");
        free(temp); // Free the memory of the dequeued node
    }
    return ele;
}

// Function to return the data of the front element without removing it
int peek(struct node* front, struct node* rear) {
    int ele;

    if (front == NULL) {
        printf("Queue is Empty\n");
        return 0;
    } else {
        ele = front->data;
    }
    return ele;
}

// Function to display all elements in the queue
void display(struct node* front, struct node* rear) {
    struct node* t;

    t = front;
    printf("front");
    while (t != rear) {
        printf("--->||%d||", t->data);
        t = t->next;
    }
    printf("--->||%d||---->rear\n", t->data);
}

// Function to free the memory of all nodes in the queue
void freeAllNode(struct node** front) {
    struct node* t, * temp;

    t = *front;

    while (t->next != NULL) {
        temp = t;
        t = t->next;
        free(temp);
    }
}


