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
	struct node *temp, *t;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
		return;
	}
	printf("Node Space Created!\n");

	int ele;
	printf("Enter the element: ");
	scanf("%d", &ele);

	temp->data = ele;
	temp->next = NULL;

	t = *p;
	if(*p == NULL)
	{
		*p = temp;
		temp->next = *p;
	}
	else
	{
		temp->next = *p;
		while(t->next != *p)
		{
			t = t->next;
		}
		t->next = temp;
		*p = temp;
	}
}

void insertEnd(struct node **p)
{
	struct node *temp, *t;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
		return;
	}
	printf("Node Space Created!\n");

	int ele;
	printf("Enter the element: ");
	scanf("%d", &ele);

	temp->data = ele;
	temp->next = NULL;

	t = *p;
	if(*p == NULL)
	{
		*p = temp;
		temp->next = *p;
	}
	else
	{
		while(t->next != *p)
		{
			t = t->next;
		}
		t->next = temp;
		temp->next = *p;
	}
}

void insertPos(struct node **p)
{
	struct node *temp, *t;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		printf("Memory not Allocated!\n");
		return;
	}
	printf("Node Space Created!\n");

	int ele, pos, c;
	c = countNode(p);
	printf("Enter the Position: ");
	scanf("%d", &pos);
	if(pos > c)
	{
		printf("Position out of range!\n");
		printf("Element will be entered at the last!\n");
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

		temp->data = ele;
		temp->next = NULL;

		t = *p;
		for(int i = 0; i < pos-1; i++)
		{
			t = t->next;
		}
		temp->next = t->next;
		t->next = temp;
	}
}

void display(struct node **p)
{
	struct node *temp;
	temp = *p;
	do
	{
		printf("--->|%d|", temp->data);
		temp = temp->next;
	}
	while(temp != *p);
	printf("\n");
}

void deleteBeg(struct node **p)
{
	struct node *temp, *t;
	if(*p == NULL)
	{
		printf("List is empty!\n");
	}
	else
	{
		t = *p;
		temp = *p;
		*p = t->next;
		while(t->next != temp)
		{
			t = t->next;
		}
		t->next = *p;
		free(temp);
		printf("Node was deleted!\n");
		printf("\n");
	}
}

void deleteEnd(struct node **p)
{
	struct node *temp, *t;
	t = *p;
	if(*p == NULL)
	{
		printf("List empty! Deletion not possible!\n");
	}
	else
	{
		while(t->next->next != *p)
		{
			t = t->next;
		}
		temp = t->next;
		t->next = *p;
		free(temp);
		printf("Node was deleted!\n");
		printf("\n");
	}
}

void deletePos(struct node **p)
{
	struct node *temp, *t;
	t = *p;
	if(*p == NULL)
	{
		printf("List Empty! Deletion not possible!\n");
	}
	int pos, c;
	c = countNode(p);
	printf("Enter the position: ");
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
	struct node *temp;
	int count = 0;
	temp = *p;
	do
	{
		count++;
		temp = temp->next;
	}
	while(temp != *p);
	printf("Nodes in linked list are %d\n", count);
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
	*p = NULL;
}