/*
Write a Menu-driven Linked List Program in C language to store Flat Owner
information's with mentioned below functionalities.
● A Linked list node contains following fields for Flat owner
○ Owner_name,
○ building_name (eg ABCD)
○ flat_number (a four digit number: eg 1101, 0203, whereas first 2 digits indicates floor number)
○ society_name
○ pin_code (a six digit mumber) 
● Function-User can Add. Display, Search and Display Flat owner info Search and
Delete flat owner by flat_number 
● Design Men Driven Program (Using Switch-cases) 
● Write appropriate comments
*/
#include<stdlib.h>
#include<stdio_ext.h>
#include <stdio.h>
#include <string.h>

struct node
{   
    	char name[20];
   	char b_name[5];
	int num;
	char s_name[20];
	char pin[7];
	struct node *next;
};

//Function decalaration
void add(struct node **);
void search(struct node **	);
void showAll(struct node *);
void delete(struct node **);

int main() 
{
    struct node *head = NULL;                                                   // Initialize the linked list
    int choice, ele, count = 0;

    while (1) 
    {
        printf("\nCurrently present: %d owner's data\n", count);				//shows how many inputs were guven until now
        printf("Menu :\n1.Add data\n2.Search data\n3.Show All Data\n4.Delete particular data\n5.Exit\n");
        printf("Enter your option: ");
        scanf("%d", &choice);

        // Perform actions based on user's choice
        switch (choice) 
        {
            case 1:
                add(&head);                                                     // Add a new node
                count++;
                break;

            case 2:
                search(&head);                                                   // Search for a node by Roll No.
                break;

            case 3:
                showAll(head);                                                  // Display all node data
                break;

            case 4:
                delete(&head);                                                  // Delete a node by Roll No.
                count--;
                break;

            case 5:
                exit(1);                                                        // Exit the program

            default:
                printf("Error: Please choose a valid option.\n");
                break;
        }
    }

    // freeAll(&head);                                                          // Free the memory before exiting
    return 0;
}

void add(struct node **p) 														//will add data in the sorted manner based on  flat number
{
	int ele=0;
	struct node *temp,*t;
	t = *p;																		//t = head;

	temp = (struct node *)malloc(sizeof(struct node));                          // Allocate memory for a new node node
    if (temp == NULL) 
    {
        printf("Memory can't be allocated. Please try again.\n");               //NULL check for MALLOC
        return;
    }

    temp->next = NULL;                                                          // Initialize the new node

    printf("\nEnter below details\n");
    printf("Enter Flat Owner Name :");
    __fpurge(stdin);
    scanf("%[^\n]s",temp->name);
    printf("Enter Building Name :");
    __fpurge(stdin);
    scanf("%[^\n]s",temp->b_name);
    printf("Enter Flat Number (4 digit) :");
    __fpurge(stdin);
    scanf("%d", &ele);
    temp->num=ele;
    printf("Enter Society Name :");
    __fpurge(stdin);
    scanf("%[^\n]s",temp->s_name);
    printf("Enter Pin Code (6 digit) :");
    __fpurge(stdin);
    scanf("%[^\n]s",temp->pin);

    if(*p==NULL)															//LL not initialized yet
    {
    	*p=temp;
    }else
    {
    	while(t->num>temp->num)												//traverse till flat number is lower than temp flat number
    	{
    		t=t->next;
    	}
    	//printf("Flat Owner Name : %s\n",t->name);							//to debug and check till where loop runs
    	temp->next=t->next;													//insert node ahead of it
    	t->next=temp;
    }																		
}

void search(struct node **p)
{
	struct node *t;
	t = *p;																	//t = head;
	int ele = 0;
	printf("Enter flat number to search details for: ");
    __fpurge(stdin);
    scanf("%d", &ele);	

    while(t!=NULL)															//traverse till last node
    	{
    		if(t->num==ele)
    		{
    			printf("Flat Owner Name : %s\n",t->name);
		        printf("Building Name : %s\n",t->b_name);
		        printf("Flat num : %d\n",t->num);
		        printf("Society Name : %s\n",t->s_name);
		        printf("Pin Code : %s\n",t->pin);
    			return;
    		}
    		t=t->next;
    	}

    	printf("Data not found\n");
    	return;
}
																				
void showAll(struct node *head)													//Display entire LL
{
    struct node	 *t=head;
    int i=1;
    
    if(head==NULL){
        printf("Empty\n");
        return;
    }
    printf("\n\n ----The owner details are---- ");

    while(t!=NULL)														//last node -> next = NULL, so will stop when it reaches there.
    {
        printf("\nFLAT OWNER %d DETAILS\n",i);
        printf("Flat Owner Name : %s\n",t->name);
        printf("Building Name : %s\n",t->b_name);
        printf("Flat num : %d\n",t->num);
        printf("Society Name : %s\n",t->s_name);
        printf("Pin Code : %s\n",t->pin);
        i++;
        t=t->next;
    }
    printf(" ---------------------------- ");
    printf("\n\n");
}

void delete(struct node **p)
{
	struct node *t,*temp;
	t = *p;																	//t = head;
	int ele = 0;
	printf("Enter flat number to delete details of: ");
    __fpurge(stdin);
    scanf("%d", &ele);

    if (*p == NULL)                                                       //check for LL initialization
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    while(t!=NULL)															//traverse till last node
    	{
    		if(t->next->num==ele)
    		{
    			break;
    		}
    		t=t->next;
    	}
    
    if (*p == NULL)                                                      
    {
        printf("Data not found.\n");
        return;
    }

    //printf("Flat Owner Name : %s\n",t->name);
    temp=t->next;
    t->next=temp->next;
    free(temp);
}
