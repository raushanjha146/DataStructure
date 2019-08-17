/**
 * C program for:
 *  - reverse a linked list 
 *  - reverse a linked list using recurson
 *  - find nth element from the list
 *
 * To compile the code : gcc single-linked-list-rev.c -o single-linked-list-rev
 * To Run : ./single-linked-list-rev
 * Initial linked list elements are : 85 15 4 20 
 */

#include<stdio.h> 
#include<stdlib.h> 

/* Link list node */
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

/* Function to reverse the linked list */
static void reverse(struct Node** head_ref) 
{ 
	struct Node* prev = NULL; 
	struct Node* current = *head_ref; 
	struct Node* next = NULL; 
	while (current != NULL) 
	{ 
		// Store next 
		next = current->next; 

		// Reverse current node's pointer 
		current->next = prev; 

		// Move pointers one position ahead. 
		prev = current; 
		current = next; 
	} 
	*head_ref = prev; 
} 

/* Function to reverse the linked list recursive */
static void reverseRecursive(struct Node** head_ref) 
{ 
	struct Node* p = NULL; 
	struct Node* q = NULL; 
	if(*head_ref==NULL)
	    return;
	p=*head_ref;
	q=p->next;
	if(q==NULL)
	    return;
	reverseRecursive(&q);
	struct Node *r=p->next;
	r->next=p;
	//p->next->next=p;
	p->next=NULL;

	*head_ref = q; 
} 

/* Function to find nth element from last to the linked list */
static void find_nth_element(struct Node* head, int n, int len) 
{ 
	struct Node* p = head; 
	if((head==NULL) || (len < n))
	    return;
	int count=len;
	while(p!=NULL)
	{
	    if(count>n)
	    {
		count--;
		p=p->next;
	    }
	    else
	    {
		printf("\n%dth element is %d\n",n,p->data);
		break;
	    }
	}	
} 

/* Function to find the length of the linked list */
static int findLength(struct Node* head) 
{ 
	struct Node* p = head;
	int count = 0;
	while(p!=NULL)
	{
	    count++;
	    p=p->next;
	}
	return count; 
} 


/* Function to push a node */
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = 
			(struct Node*) malloc(sizeof(struct Node));		 
	new_node->data = new_data; 
	new_node->next = (*head_ref);	 
	(*head_ref) = new_node; 
} 

/* Function to print linked list */
void printList(struct Node *head) 
{ 
	struct Node *temp = head; 
	while(temp != NULL) 
	{ 
		printf("%d ", temp->data);	 
		temp = temp->next; 
	} 
	printf("\n");
}	 

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	
	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 85);	 
	
	printf("==========================================\n");	
	printf("Given linked list is :\n"); 
	printList(head);	 
	
	/* find nth element from the list */
	int l=findLength(head);
	find_nth_element(head,3,l);
	
	/* reverse a linked list */
	reverse(&head);
	printf("\nReversed linked list is :\n"); 
	printList(head);	
	
	/* reverse a linked list using recursion */ 
	reverseRecursive(&head);					 
	printf("\nRecursive reversed linked list is :\n"); 
	printList(head);	
	printf("==========================================\n");	
//	getchar(); 
} 
