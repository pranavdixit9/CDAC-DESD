#include <stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

void insert(struct node **, int);
void inorderT(struct node *);
void preorderT(struct node *);
void postorderT(struct node *);
void delete(struct node **, int);
void search(struct node **, int, struct node **, struct node **, int *);
int main()
{
    struct node *root;
    root = NULL;
    int choice;
    int ele;
	while(1)
	{
	    printf("\nenter 1->insert 2-inorderT 3->preorderT 4->postorderT 5->delete 6->exit\n");
    	scanf("%d", &choice);
    	switch(choice){
    		case 1:
                printf("enter ele\n");
                scanf("%d", &ele);
    			insert(&root, ele);
    			break;
    		case 2:
    			printf("tree inorder traversal\n");
    			inorderT(root);
    			break;
    		case 3:
    			printf("tree preorder traversal\n");
	    		preorderT(root);
	    		break;
	    	case 4:
	    		printf("tree postorder traversal\n");
	    		postorderT(root);
	    		break;
		
	    	case 5: 
	       		printf("enter ele\n");
                scanf("%d", &ele);
	       		delete(&root, ele);
	    		break;
			
	    	case 6:
		    	exit(0);
		
    	}
	}
	return 0;
}

void insert(struct node **p, int ele)
{
    if(*p == NULL)                                                             //for checking if tree is empty or not, add root node if empty
    {
        *p = (struct node *)malloc(sizeof(struct node));                       //NULL check for MALLOC
        if(p == NULL)
        {
            printf("TREE IS EMPTY!\n");
            return;
        }
        (*p)->data = ele;
        (*p)->left = NULL;
        (*p)->right = NULL;
    }
    else                                               //go to left or right depending on value of element to be added VS root element in recursion
    {
        if(ele < (*p)->data)
        {
            insert(&((*p)->left), ele);                //if ele<root, go left
        }
        else
        {
            insert(&((*p)->right), ele);               //if ele>root, go right
        }
    }
}

void inorderT(struct node *p)                          //LEFT->ROOT->RIGHT                                                   //         
{
    if(p != NULL)
    {
       inorderT(p->left);
       printf("%d ", p->data);
       inorderT(p->right);
    }
}

void preorderT(struct node *p)                          //ROOT->LEFT->RIGHT
{
    if(p != NULL)
    {
       printf("%d ", p->data);
       preorderT(p->left);
       preorderT(p->right);
    }
}

void postorderT(struct node *p)                         //LEFT->RIGHT->ROOT
{
    if(p != NULL)
    {
       postorderT(p->left);
       postorderT(p->right);
       printf("%d ", p->data);
    }
}

void delete(struct node **root, int ele)
{
    struct node *par, *x, *xsuc;                                //PAR= ONE NODE ABOVE TO BE DELTED, X = NODE TO BE DELETED, XSUC = NODE AFTER NODE TO BE DELTED
    int found;                                                  //FOUND = FLAG TO CHECK IF ELEMENT FOUND OR NOT, FALSE IN BEGINNING TRUE WHEN FOUND VIA SEARCH FUNCTION               
    
    if(root == NULL)                                            //CHECK FOR EMPTY TREE 
    {
        printf("TREE IS EMPTY!\n");
        return;
    }
    par = x = NULL; 
    
    search(root, ele, &par, &x, &found);                        //SEARCH FUNCTION CALLED, GOT X = ELEMENT TO BE DELETED
    
    if(found == FALSE)
    {
        printf("Element to be Deleted was not Found!\n");
        return;
    }

    if(x->left != NULL && x->right != NULL)                     //LEAF NODE DELETION
    {
        par = x;                                                
        xsuc = x->right;
        
        while(xsuc->left != NULL)
        {
            par = xsuc;
            xsuc = xsuc->left;
        }
        
        x->data = xsuc->data;
        x = xsuc;
 
    }
    
    if(x->left == NULL && x->right == NULL)                     //NODE TO BE DELTED HAS RIGHT CHILD 
    {
        if(par->right == x)                                     //PAR IS ONE ABOVE, SO IF NODE TO BE DELETED IS ON RIGHT MAKE IT NULL OR ELSE MAKE LEFT OF PAR NULL
        {
            par->right = NULL;
        }
        else
        {
            par->left = NULL;
        }
        free(x);
        return;
    }
    
    if(x->left == NULL && x->right != NULL)                     //NODE TO BE DELTED HAS LEFT CHILD
    {                                                         
        if(par->left == x)                                      //PAR IS ONE ABOVE, SO IF NODE TO BE DELETED IS ON RIGHT MAKE IT NULL OR ELSE MAKE LEFT OF PAR NULL
        {
            par->left = x->right;
        }
        else
        {
            par->right = x->right;
        }
        free(x);
        return;
    }
    
    if(x->left != NULL && x->right == NULL)                     //NODE TO BE DELETD HAS TWO CHILDREN                          
    {
        if(par->left == x)                                      //CONNECT PAR (PREVIOUS NODE) WITH NODE AFTER X (NODE TO BE DELETED) 
        {
            par->left = x->left;
        }
        else
        {
            par->right = x->left;
        }
        free(x);
        return;
    }
}

void search(struct node **root, int ele, struct node **par, struct node **x, int *found)
{
   struct node *q ;

    q = *root ;
    *found = FALSE ;
    *par = NULL ;

    while (q != NULL)
    {
        /* if the node to be deleted is found */
        if (q->data == ele)
        {
            *found = TRUE;
            *x = q;
            return;
        }

        *par = q ;
        /*MOVE TO LEFT IF ELEMENT TO BE FOUND IS LESSER THAN ROOT*/
        if (q->data > ele)  
        {
            q = q->left;
        }
        else /*MOVE TO RIGHT IF ELEMENT TO BE FOUND IS GREATER THAN ROOT*/
        {
            q = q->right;
        }
    }
    
}
