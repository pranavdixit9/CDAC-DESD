#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct node 
{
    int data;
    struct node *next;
};                                          

void push(struct node **, int);
int pop(struct node **);
void display(struct node *);
void freeNode(struct node **);
int listNodeCount(struct node *);
void delete(struct node **);

int main() {
    struct node *head;

    head = NULL;                                                            //head = stack top pointer

    int choice, ele, ret;

    while (1) {
        printf("\nMenu: \n1. Push\n2. Pop\n3. Display\n4. Exit\nChoose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Element to push onto the stack: ");
                scanf("%d", &ele);
                push(&head, ele);
                break;

            case 2:
                ret = pop(&head);
                if (ret != -1) {
                    printf("Popped data: %d\n", ret);
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;

            case 3:
                display(head);
                break;

            case 4:
                exit(1);

            default:
                printf("Enter a valid choice\n");
                break;
        }
    }

    freeNode(&head);                                    // Free the memory allocated for the nodes when exiting
    
    return 0;
}

// Function to push an element onto the stack
void push(struct node **p, int ele) 
{
    struct node *temp;                                  // adding new element on stack
    
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp=NULL)                                       // null check for malloc
    {
        prinrf("Memory not allocated\n");
        return;
    }
    
    temp->data = ele;
    temp->next = *p;                                     // give address of previous stack top to temp->next to connect new element to stack
    *p = temp;                                           // Make the newly added node the new stack top pointer
}

// Function to pop an element from the stack
int pop(struct node **p) 
{
    struct node *t, *temp;
    int data;
    if (*p == NULL) 
    {
        return -1;                                       // If the list is empty, return -1
    } else 
    {
        t = *p;                                         // t and temp store address of first element, t to update stack top pointer by next data and temp to free data 
        temp = *p;
        data = temp->data;                              // copy data to local variable to return to main function
        *p = t->next;                                   // Move the stack top pointer to the next node
        free(temp);                                     // Free the memory of the deleted node
    }
    return data;
}

// Function to display the elements in the stack
void display(struct node *p) 
{
    struct node *t;

    if (p == NULL)                                       // check for empty queue
    {
        printf("No list present\n");
        return;
    }

    t = p;                                              // t = stack top pointer to traverse the stack 

    printf("Stack: ");
    while (t != NULL) {
        printf("%d ", t->data);                          // Print the data of each node in the list
        t = t->next;
    }
    printf("\n");
}

// Function to free all nodes in the linked list
void freeNode(struct node **p) 
{
    struct node *t1, *t2;
    int i = listNodeCount(*p);                              // i = number of nodes/stacks in stack
    
    t1 = *p;                                                // t1 = stack top pointer and t2 = address of next element
    t2 = t1->next;

    while (i)                                               //loop to traverse the stack and delete(POP) elements one by one
    {
        t2 = t1->next;
        delete(&t1);
        t1 = t2;
        i--;
    }
}

// Function to delete the first element in the linked list
void delete(struct node **p) 
{
    struct node *t, *temp;
    if (*p == NULL) 
    {
        return;                                                 // If the list is empty, do nothing
    } else 
    {
        t = *p;
        temp = *p;
        *p = t->next;                                           // Move the stack top pointer to the next node
        free(temp);                                             // Free the memory of the deleted node
    }
}

// Function to count the number of nodes in the linked list
int listNodeCount(struct node *p) 
{
    struct node *t;
    int count = 1;
    t = p;
    while (t->next != NULL)                                     //loop to traverse the stack and increment counter variable until last element reached
    {
        count++;
        t = t->next;
    }
    return count;
}
