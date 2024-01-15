#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *head;
void insertBeg();
void insertEnd();
void insertPos();
void display();
void deleteBeg();
void deleteEnd();
void deletePos();
int countNode();
void freeNodes();

int main()
{
	head = NULL;
	int ch,count;
	while(1)
	{
		printf("Enter a choice\n");
		printf("1-> Insert at beginning\t\t2-> Insert at End\n3-> Insert at Position\t\t4-> Display Linked List\n5-> Delete node from Beginning\t6-> Delete node from End\n7-> Delete node from Position\t8-> Count No. of Nodes\n9-> Free All Nodes\t\t0-> Exit\n");
		printf("---> ");
		scanf("%d", &ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				insertBeg();
				break;
			case 2:
				insertEnd();
				break;
			case 3:
				insertPos();
				break;
			case 4:
				display();
				break;
			case 5:
				deleteBeg();
				break;
			case 6:
				deleteEnd();
				break;
			case 7:
				deletePos();
				break;
			case 8:
				count = countNode();
				printf("Total Number of Nodes in Linked List are %d\n", count);
				break;
			case 9:
				freeNodes();
				break;
			case 0:
				exit(1);
				break;
			default:
				printf("Enter a valid option!\n");
				break;
		}
	}
	freeNodes();
	return 0;
}

void insertBeg()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
	}
	printf("Node Space Created!\n");
	int ele;
	printf("Enter Element: ");
	scanf("%d", &ele);
	temp->data = ele;
	temp->next = NULL;
	if(head == NULL) // head == NULL means that no node exits thus temp will be the first node itself
	{
		head = temp; // head will take temp's address making the head point to the temp (i.e. first node)
	}
	else // else condition for if nodes already exist and we need to add a node at beginning
	{
		temp->next = head; // giving the new node the address stored in head, to make it the first node
		head = temp; //  to make head point to temp (i.e new first node)
	}
	printf("Node inserted at the beginning!\n");
}
void insertEnd()
{
	struct node *temp, *t; // t is temp pointer used for traversing
	t = head; // t assigned to head
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
	}
	printf("Node Space Created!\n");
	int ele;
	printf("Enter Element: ");
	scanf("%d", &ele);
	temp->data = ele;
	temp->next = NULL;
	// same procedure to create a new node
	if(head == NULL) // if no node exists
	{
		head = temp;
	}
	else
	{
		while(t->next != NULL) // used to get t to the end of the list
		{
			t = t->next; // to move to the next node
		}
		t->next = temp; // last node will point to the newly created node
	}

	printf("Node was inserted at the End!\n");
}
void insertPos()
{
	struct node *temp, *t;
	t = head;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
	}
	printf("Node Space Created!\n");
	int ele, pos;
	printf("Insert node at Position: ");
	scanf("%d", &pos);
	int c = countNode();
	if(pos > c)
	{
		printf("Position out of range!!\n");
		printf("Node will be inserted at the End!\n");
		insertEnd();
	}
	else if(pos == 0)
	{
		insertBeg();	}
	else
	{
		printf("Enter Element: ");
		scanf("%d", &ele);
		temp->data = ele;
		temp->next = NULL;
		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			for(int i = 0; i < pos-1; i++)
			{
				t = t->next;
			}
			temp->next = t->next; // store address of the present node in the new node
			t->next = temp; // last node to point to the new node
		}
	}
}
void display()
{
	struct node *temp = head; // head address stored in temp
	while(temp != NULL) // loop until temp reaches NULL, i.e the last node's next section would contain NULL
	{
		printf("-->|%d|", temp->data);
		temp = temp->next; // to traverse to the next node 
	}
	printf("\n");
}
void deleteBeg()
{
	struct node *temp, *t;
	t = head; //  make t point to head
	temp = head; // temp stores address stored in head to free later
	head = t->next; // make head point to the next node
	printf("Node was Deleted!\n");
	printf("\n");
	free(temp);
}
void deleteEnd()
{
	struct node *temp, *t;
	t = head; // make t point to head
	while(t->next->next != NULL) // traverse to second last node
	{
		t = t->next;
	}
	temp = t->next; // give last node address to temp
	t->next = NULL; // put NULL in last node next section
	printf("Last node was deleted!\n");
	printf("\n");
	free(temp); // free memory allocated
}
void deletePos()
{
	struct node *temp, *t;
	t = head;
	int c;
	c = countNode();
	int pos;
	printf("Enter the position of the node to be deleted: ");
	scanf("%d", &pos);
	if(pos > c)
	{
		printf("Position out of range!!\n");
		printf("Last node will be deleted!\n");
		deleteEnd();
	}
	else if(pos == 0)
	{
		deleteBeg();
	}
	else
	{
		for(int i = 0; i < pos-1; i++)
		{
			t = t->next;
		}
		temp = t->next; // temp to store node to be deleted
		t->next = t->next->next; // giving the address of next node to the prev node
		printf("Node at %d position was deleted!\n", pos);
		printf("\n");
		free(temp);
	}
}
int countNode() // same logic as display function just used a count var to count nodes
{
	struct node *temp = head;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	
	return count;
}
void freeNodes()
{
	struct node *temp, *t;
	int i;
	i = countNode();
	while(i)
	{
		t = temp->next;
		deleteBeg();
		temp = t;
		i--;
	}
}
