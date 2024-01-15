#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
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

	temp = (struct node *)malloc(sizeof(struct node));			//NULL check for MALLOC
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
		return;
	}
	printf("Node Space Created!\n");

	int ele;
	printf("Enter the Element: ");								//user input for data to be put in DLL
	scanf("%d", &ele);

	temp->prev = NULL;
	temp->data = ele;											//temp->data = ele, temp->next and temp->prev initialized to NULL
	temp->next = NULL;

	if(*p == NULL)												//initialize DLL by giving head ptr the address of temp
	{
		*p = temp;
	}
	else
	{
		temp->next = *p;										//if already initialized, temp->next = head pointer = current first element
		*p = temp;												//head pointer = new element address
		temp->next->prev = *p;									//(temp->next)->prev = current first node -> prev = temp
	}
}																//head->|NULL|temp->data=ele|old 1st ele address|<-->|temp|data|adess to rest of DLL|

void insertEnd(struct node **p)
{
	struct node *temp, *t;

	t = *p;
	temp = (struct node *)malloc(sizeof(struct node));			//NULL check for MALLOC
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
		return;
	}
	printf("Node Space Created!\n");

	int ele;
	printf("Enter the Element: ");
	scanf("%d", &ele);
	temp->prev = NULL;
	temp->data = ele;											//temp->data = ele, temp->next and temp->prev initialized to NULL
	temp->next = NULL;

	if(*p == NULL)												//initialize DLL by giving head ptr the address of temp
	{
		*p = temp;
	}
	else
	{
		while(t->next != NULL)									//traverse to last node of DLL
		{
			t = t->next;
		}
		t->next = temp;											//old last node->next = temp
		temp->prev = t;											//temp->prev = old last node 
	}
}

void insertPos(struct node **p)
{
	struct node *temp, *t;
	t = *p;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)											//NULL check for MALLOC
	{
		printf("Memory not Allocated!\n");
		return;
	}
	printf("Node Space Created!\n");

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
	else if(pos == 0)
	{
		insertBeg(p);
	}
	else
	{
		printf("Enter the element: ");
		scanf("%d", &ele);

		temp->prev = NULL;
		temp->data = ele;
		temp->next = NULL;

		t = *p;
		for(int i = 0; i < pos-1; i++)
		{
			t = t->next;
		}
		temp->prev = t;
		temp->next = t->next;
		t->next->prev = temp;
		t->next = temp;
	}
}

void display(struct node **p)
{
	struct node *temp = *p;
	while(temp != NULL)
	{
		//printf("%u", *p);
		printf("--->|%p|%d|%p|", temp->prev, temp->data, temp->next);
		temp = temp->next;
	}
	printf("\n");
}

void deleteBeg(struct node **p)
{
	struct node *temp, *t;
	t = *p;
	temp = *p;
	*p = t->next;
	t->next->prev = NULL;
	free(temp);
	printf("Node was Deleted!\n");
	printf("\n");
}

void deleteEnd(struct node **p)
{
	struct node *temp, *t;
	t = *p;
	while(t->next->next != NULL)
	{
		t = t->next;
	}
	temp = t->next;
	t->next = NULL;
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
		for(int i = 0; i < pos-1; i++)
		{
			t = t->next;
		}
		temp = t->next;
		t->next = t->next->next;
		t->next->prev = t->prev->next;
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
	while(t->next->data != ele)
	{
		t = t->next;
	}
	temp = t->next;
	t->next = t->next->next;
	t->next->prev = t;
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