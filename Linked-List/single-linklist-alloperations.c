/**
 * C program for:
 *  - insert node at first
 *  - insert node at last
 *  - delete first node 
 *  - delete last node
 *
 * To compile the code : gcc single-linklist-allfunction.c -o single-linklist-allfunction
 * To Run : ./single-linklist-allfunction
 */


#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* Function to push a node */
void insertFront(struct Node** h, int n)
{
  struct Node* tmp =(struct Node*) malloc(sizeof(struct Node));
  tmp->data = n;
  tmp->next = (*h);
  (*h) = tmp;
}

/* Function to push a node to last */
void insertLast(struct Node** h, int n)
{
  struct Node* tmp =(struct Node*) malloc(sizeof(struct Node));
  struct Node* h1 = *h;
  tmp->data = n;
  tmp->next = NULL;
  if(*h != NULL)
  {
    while(h1->next != NULL)
	h1 = h1->next;
    (h1)->next=tmp;
    //tmp = (*h);
  }
  else
    *h=tmp;
}



/* Function to print linked list */
void printList(struct Node *h) 
{ 
	if(h==NULL)
		printf("List is Empty!\n\n");
	else
	{
		struct Node *tmp = h; 
		printf("\n------------------------------------------------------------\n");
		while(tmp != NULL) 
		{ 
			printf("%d ", tmp->data);	 
			tmp = tmp->next; 
		}
		printf("\n------------------------------------------------------------\n");
	} 
}	

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL;
	int choice; 
	int num;
	//while(choice > 0)
	while(1)
	{
	  printf("\n***SINGLE LINKED LIST OPERATIONS:****\n");
          printf("=======================================================\n");
          printf(" 1.Insert at the beginning\n");
          printf(" 2.Insert at the end    \n");
	  printf(" 3.Display    \n");
          
          //printf(" 4.Insert at the end  \n");
          //printf(" 5.Insert at specified position       \n");
          //printf(" 6.Delete from beginning      \n");
          //printf(" 7.Delete from the end        \n");
          //printf(" 8.Delete from specified position     \n");
          printf(" 0.Exit       \n");
          printf("=======================================================\n");
	  printf("Please Enter your choice:\n"); 
	  scanf("%d",&choice);
	  switch(choice)
	  {
	    case 1:
		printf("before insertion the list is : \n");
		printList(head);
		//int num;
		printf("Please Enter the element to be inserted from start:\n"); 
		scanf("%d",&num);
		insertFront(&head, num);
		printf("after insertion the list is : \n");
		printList(head);
		break;
	    case 2:
		printf("before insertion the list is : \n");
		printList(head);
		//int num;
		printf("Please Enter the element to be inserted from last:\n"); 
		scanf("%d",&num);
		insertLast(&head, num);
		printf("after insertion the list is : \n");
		printList(head);
		break;
	    case 3:
		printf("list is : \n");
		printList(head);
		break;

	    case 0:
		//printf("Thank you!!\nTo exit the program, Please press any key \n");
		printf("Thank you!!\nNow Exiting \n");
                getchar();
		exit(0);

	    default:
		printf("Please enter the valid choice \n");
	  }
	}
		 
} 
