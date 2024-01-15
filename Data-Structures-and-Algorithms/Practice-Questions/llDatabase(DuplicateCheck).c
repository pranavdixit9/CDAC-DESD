#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

// Define a structure to represent a student node in the linked list
struct node 
{
    char name[30];
    int age;
    int rollno;
    char address[100];
    struct node *prev;
    struct node *next;
};

// Function declarations
void add(struct node **);
void search(struct node *);
void showAll(struct node *);
void delete(struct node **);
int checkDuplicate(struct node *, int);
void freeAll(struct node **);

int main() 
{
    struct node *head = NULL;                                                   // Initialize the linked list
    int choice, ele, count = 0;

    while (1) 
    {
        // Display the menu and receive user input
        printf("\nCurrently present: %d student's data\nMenu :\n1.Add data\n2.Search data\n3.Show All Data\n4.Delete particular data\n5.Exit\nEnter your option: ", count);
        scanf("%d", &choice);

        // Perform actions based on user's choice
        switch (choice) 
        {
            case 1:
                add(&head);                                                     // Add a new student
                count++;
                break;

            case 2:
                search(head);                                                   // Search for a student by Roll No.
                break;

            case 3:
                showAll(head);                                                  // Display all student data
                break;

            case 4:
                delete(&head);                                                  // Delete a student by Roll No.
                count--;
                break;

            case 5:
                exit(1);                                                        // Exit the program

            default:
                printf("Error: Please choose a valid option.\n");
                break;
        }
    }

    freeAll(&head);                                                             // Free the memory before exiting
    return 0;
}

// Function to add a new student to the sorted doubly linked list
void add(struct node **p) 
{
    struct node *t, *temp;
    int duplicate;

    temp = (struct node *)malloc(sizeof(struct node));                          // Allocate memory for a new student node
    if (temp == NULL) 
    {
        printf("Memory can't be allocated. Please try again.\n");               //NULL check for MALLOC
        return;
    }

    temp->next = NULL;                                                          // Initialize the new node
    temp->prev = NULL;


    // Check for duplicate Roll No. and input a unique one
    do 
    {
        printf("Enter Rollno: ");
        scanf("%d", &temp->rollno);
        duplicate = checkDuplicate(*p, temp->rollno);                           //call checkDuplicate function
    }while (duplicate);

     // Input student's name
    __fpurge(stdin);                                                            //clear input buffer
    printf("Enter name of Student: ");
    scanf("%[^\n]", temp->name);                                                //scan till "\n" received; until enter pressed
    __fpurge(stdin);


    // Input student's age
    __fpurge(stdin);
    printf("Enter Age: ");
    scanf("%d", &temp->age);

    // Input student's address
    __fpurge(stdin);
    printf("Enter Address: ");
    scanf("%[^\n]", temp->address);

    // Insert the new node into the sorted linked list
    if (*p == NULL)                                                         //initialize new DLL
    {
        *p = temp;
    } else if ((*p)->rollno > temp->rollno)                                 //insert at begining if first node roll number greater than entered roll number
    {
        temp->next = *p;                                                    
        (*p)->prev = temp;                                               
        *p = temp;
    } else 
    {
        t = *p;                                                             //t = head pointer
        while (t->next != NULL && (t->next->rollno < temp->rollno))         //t traverses until entered roll number is lower than entered roll number
        {
            t = t->next;
        }

        temp->next = t->next;                                               //temp->next = address of data after t
        temp->prev = t;                                                     //temp->prev = t
        if (t->next != NULL)    
        {
            t->next->prev = temp; //element after t gets address of temp as its previous, if condition is to check if there is actually aa node after t
        }
        t->next = temp;                                                     //t->next = temp = node to be added
    }
}

// Function to search for a student by Roll No.
void search(struct node *p) 
{
    int num;
    printf("Enter Roll no. to search: ");
    scanf("%d", &num);

    while (p != NULL)                                                       //traverse DLL and print and return if found
    {
        if (p->rollno == num) 
        {
            printf("\nData Found!!!!!!\n");
            printf("\nName: %s\n", p->name);
            printf("Roll No.: %d\n", p->rollno);
            printf("Age: %d\n", p->age);
            printf("Address: %s\n", p->address);
            return;
        }
        p = p->next;
    }
    printf("Data not found\n");
}

// Function to display all student data in the linked list
void showAll(struct node *p) 
{
    if (p == NULL)                                                      //check for DLL initialization
    {
        printf("No data to show\n");
        return;
    } else 
    {
        while (p != NULL)                                               //traverse and print each node
        {
            // Display student information
            printf("\nName: %s\n", p->name);
            printf("Roll No.: %d\n", p->rollno);
            printf("Age: %d\n", p->age);
            printf("Address: %s\n", p->address);
            printf("prev = %p\n", p->prev);
            printf("next = %p\n", p->next);
            p = p->next;
        }
    }
}

// Function to delete a student by Roll No.
void delete(struct node **p) 
{
    struct node *t, *temp;
    int ele;
    t = *p;

    printf("Enter Roll no. to be deleted: ");
    scanf("%d", &ele);

    if (*p == NULL)                                                       //check for DLL initialization
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // Handle the case where the first node should be deleted
    if (t->rollno == ele)                                               //delete at begining of DLL
    {
        *p = t->next;
        if (t->next != NULL) 
        {
            t->next->prev = NULL;
        }
        free(t);
        printf("Element %d is deleted\n", ele);
        return;
    }

    // Traverse the list to find the node to be deleted
    while (t->next != NULL && t->next->rollno != ele)                   //t traverses until entered t -> next ->roll number is not user entered ele
    {
        t = t->next;
    }

    if (t->next == NULL)                                                //element not found conditon
    {
        printf("Element %d not found. Nothing to delete.\n", ele);
        return;
    }

    temp = t->next;                                                     //temp = node to be deleted
    t->next = temp->next;                                               //t connected to node after temp

    if (temp->next != NULL)                                             //if temp is last node, connect t to first node by giving adress of t to prev of first node
    {
        temp->next->prev = t;
    }

    free(temp);
    printf("Element %d is deleted\n", ele);
}

// Function to check for duplicate Roll No.
int checkDuplicate(struct node *p, int rollno) 
{
    struct node *t = p;

    while (t != NULL)                                           //t becomes NULL at last node, so traverse till then
    {
        if (t->rollno == rollno) 
        {
            printf("Enter a unique Roll no.\n");                //if even once found equal value it will return 1 and return function
            return 1;
        }

        t = t->next;                                            //traverse DLL
    }

    return 0;
}

// Function to free memory for all nodes in the linked list
void freeAll(struct node **p) 
{
    struct node *t, *temp;
    t = *p;

    while (t != NULL)                                           //traverse and free node side by side
    {
        temp = t;
        t = t->next;
        free(temp);
    }
    free(t);
}
