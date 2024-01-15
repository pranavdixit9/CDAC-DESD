#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node	*next;
};
int count;
void bubbleSort(struct node **);
void insertionSort(struct node **);
void selectionSort(struct node **);
void display(struct node *);
void insertNode(struct node **,int);
void freeNode(struct node **);

int main(){
	struct node *head=NULL;
	int choice =0,ele;

	while(choice!=5){
		printf("Menu :\n1.Insert Link List\n2.Selection Sort\n3.InsertionSort\n4.Bubble Sort\n5.Exit\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice){
		case 1:
			printf("Enter Element :");
			scanf("%d",&ele);
			insertNode(&head,ele);
			break;
		case 2:
			selectionSort(&head);
			break;
		case 3:
			insertionSort(&head);
			break;
		case 4:
			bubbleSort(&head);
			break;
		default:
			if(choice!=5)
			printf("Invalid Choice\n");
			break;
		}
	}
	freeNode(&head);
	return 0;
}

//Fuction to add node in list
void insertNode(struct node **p,int ele){
	
	struct node *temp,*t=*p;						//declaring two pointers to nodes and assigning t pointer address to head	

	temp=(struct node *)malloc(sizeof(struct node));//allocating memory to new node

	if(temp==NULL){									//checking weather memory is allocated or not
		printf("Memory not Allocated\n");			//returning to main function if memory is not allocated
		return;
	}

	temp->next=NULL;								//assigning null to temp-next
	temp->data=ele;

	if(*p==NULL){
		*p=temp;
		return;
	}
	else{
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=temp;
	}
	printf("Element added at end of List\n");
	count++;
	display(*p);
}

void bubbleSort(struct node **p){

	struct node *t1,*t2;

	int temp;

	t1=*p;
	
	for(int i=0;i<count-1;i++){		
	t1=*p;
		
		while(t1->next!=0){
			t2=t1->next;
			if(t1->data>t2->data){
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
			t1=t1->next;
		}
	}
	display(*p);
}

void selectionSort(struct node **p){
	struct node *t1,*t2,*t;

	int temp;

	t=*p;
	
	while(t->next!=NULL){		
		t1=t;
		t2=t1->next;
		while(t2!=0){
			if(t1->data>t2->data){
				t1=t2;
			}
			t2=t2->next;
		}

		temp=t->data;
		t->data=t1->data;
		t1->data=temp;
		t=t->next;
	}
	display(*p);

}

void insertionSort(struct node **p) {
    struct node *sorted = NULL;
    struct node *current = *p;

    while (current != NULL) {
        struct node *next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct node *search = sorted;
            while (search->next != NULL && search->next->data < current->data) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }
        current = next;
    }

    *p = sorted; // Update the head of the list
    display(*p); // Display the sorted list
}

void display(struct node *p){
	struct node *temp=p;

	while(temp!=0){
		printf("----->||%d||",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void freeNode(struct node **p) {
    struct node *temp;
    while (*p != NULL) {
        temp = *p;
        *p = (*p)->next;
        free(temp);
    }
}