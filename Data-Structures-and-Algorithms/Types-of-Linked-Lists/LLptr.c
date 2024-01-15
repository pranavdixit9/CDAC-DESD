#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void insertBeg(struct node **);
void insertEnd(struct node **);
void insertPos(struct node **);
void display(struct node **);
void deleteBeg(struct node **);
void deleteEnd(struct node **);
void deletePos(struct node **);
void deleteEle(struct node **);
int countNode(struct node **);
void freeNodes(struct node **);

int main()
{
	struct node *head;
	head = NULL;

	int ch, count;
	while(1)
	{
		printf("----ENTER THE CHOICE----\n");
		printf("1-> Insert at Beginning\t\t2-> Insert at End\n3-> Insert at Position\t\t4-> Display Linked List\n5-> Delete Beginning Node\t6-> Delete End Node\n7-> Delete from Position\t8-> Delete by Element\n9-> Count No. of Nodes\t\t10-> Free all Nodes\n11-> EXIT\n");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				insertBeg(&head);
				break;
			case 2:
				insertEnd(&head);
				break;
			case 3:
				insertPos(&head);
				break;
			case 4:
				display(&head);
				break;
			case 5:
				deleteBeg(&head);
				break;
			case 6:
				deleteEnd(&head);
				break;
			case 7:
				deletePos(&head);
				break;
			case 8:
				deleteEle(&head);
				break;
			case 9:
				count = countNode(&head);
				printf("Number of nodes present in Linked List are %d\n", count);
				break;
			case 10:
				freeNodes(&head);
				break;
			case 11:
				exit(1);
			default:
				printf("Enter a valid option!\n");
				break;
		}
	}

	return 0;
}

void insertBeg(struct node **p)
{
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));					//NULL check for MALLOC
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
		return;
	}
	//printf("Node Space Created!\n");
	
	int ele;
	printf("Enter the Element: ");										//element to be added
	scanf("%d", &ele);

	temp->data = ele;													//element in LL node
	temp->next = NULL;													

	if(*p == NULL)
	{
		*p = temp;														//if LL not initialized, head ptr = temp
	}	
	else
	{
		temp->next = *p;												//temp->current begining & head = temp
		*p = temp;
	}
}

void insertEnd(struct node **p)
{
	struct node *temp, *t;

	t = *p;
	temp = (struct node *)malloc(sizeof(struct node));						//NULL check for MALLOC
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
		return;
	}
	// printf("Node Space Created!\n");

	int ele;
	printf("Enter the Element: ");					//element to be added
	scanf("%d", &ele);

	temp->data = ele;								//element in LL node
	temp->next = NULL;

	if(*p == NULL)
	{
		*p = temp;									//if LL not initialized, head ptr = temp
	}
	else
	{
		while(t->next != NULL)						//traverse LL by updating t by t->next until t->next is not NULL (t->next==NULL means last node)
		{
			t = t->next;
		}
		t->next = temp;								//t = last node; t->next = temp
	}
}

void insertPos(struct node **p)
{
	struct node *temp, *t;

	t = *p;
	temp = (struct node *)malloc(sizeof(struct node));						//NULL check for MALLOC
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
		return;
	}
	// printf("Node Space Created!\n");

	int ele, pos, c;
	c = countNode(p);
	printf("Enter the Position (Begins with 0): ");
	scanf("%d", &pos);

	if(pos > c)
	{
		printf("Position out of range!\n");
		printf("Node will be inserted at the End!\n");
		insertEnd(p);
	}
	else if(pos == 0)												//insert at begining if entered position is zero
	{
		insertBeg(p);
	}
	else
	{
		for(int i = 0; i < pos-1; i++)								//traverse to position - 1, element
		{
			t = t->next;
		}
			int ele;
		printf("Enter the Element: ");								//element to be added
		scanf("%d", &ele);
		temp->data = ele;											//element in LL node
		
		temp->next = t->next;										//element to be added -> next = address of element ahead of position 
		t->next = temp;												//position - 1 element -> next = temp
	}
}

void display(struct node **p)
{
	struct node *temp = *p;
	while(temp != NULL)												//traverse to last node and print each node
	{
		printf("--->|%d|", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void deleteBeg(struct node **p)
{
	struct node *temp, *t;
	t = *p;															//t=head
	temp = *p;														//temp=head
	*p = t->next;													//head=t->next = second element of LL
	free(temp);
	printf("Node was Deleted!\n");
	printf("\n");
}

void deleteEnd(struct node **p)
{
	struct node *temp, *t;
	t = *p;
	while(t->next->next != NULL)									//traverse to one node before last node	
	{
		t = t->next;
	}
	temp = t->next;													//temp = last node				
	t->next = NULL;													//make t->next of second last element as zero
	free(temp);
	printf("Node was Deleted!\n");
	printf("\n");
}

void deletePos(struct node **p)
{
	struct node *temp, *t;
	t = *p;
	int c, pos;
	c = countNode(p);
	printf("Enter the node position to Delete: ");
	scanf("%d", &pos);

	if(pos > c)
	{
		printf("Position out of range!\n");
		printf("Last node will be deleted!\n");
		deleteEnd(p);
	}
	else if(pos == 0)
	{
		deleteBeg(p);
	}
	else
	{
		for(int i = 0; i < pos-1; i++)									//traverse to node before position
		{
			t = t->next;
		}
		temp = t->next;													//temp=t->next; temp = address of node to be deleted		
		t->next = t->next->next;										//element before position->next = element after position
		free(temp);
		printf("Node at %d position was deleted!\n", pos);
		printf("\n");
	}
}

void deleteEle(struct node **p)
{
	struct node *temp, *t;
	t = *p;
	int ele;
	printf("Enter the Element to delete: ");
	scanf("%d", &ele);
	for(int i = 0; t->next->data != ele; i++)
	{
		t = t->next;
	}
	temp = t->next;
	t->next = t->next->next;
	free(temp);
	printf("Node with %d element was deleted!\n", ele);
	printf("\n");
}

int countNode(struct node **p)
{
	struct node *temp = *p;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	printf("Nodes in Linked List are %d\n", count);
	return count;
}

void freeNodes(struct node **p)
{
	struct node *temp, *t;
	temp = *p;
	int i;
	i = countNode(p);
	while(i)
	{
		t = temp->next;
		deleteBeg(p);
		temp = t;
		i--;
	}
}