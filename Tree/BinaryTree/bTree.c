#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct stackNode 
{ 
  struct node *t; 				// poiner to tree node
  struct stackNode *next; 		// pointer to next stack node
};

struct stackForPostOrder
{ 
  struct node *t; 				// poiner to tree node
  struct stackForPostOrder *next; 		// pointer to next stack node
};  

void push(struct stackNode** topRef, struct node *t); 
struct node *pop(struct stackNode** topRef); 
int isEmpty(struct stackNode *top); 
void pushForPostOrder(struct stackForPostOrder** topRef, struct node *t); 
struct node *popForPostOrder(struct stackForPostOrder** topRef); 
int isEmptyForPostOrder(struct stackForPostOrder *top);

/* Iterative function for inorder traversal */
void printInOrderNonRecursive(struct node *root) 
{ 
  /* set current to root of binary tree */
  struct node *current = root; 
  struct stackNode *s = NULL;  /* Initialize stack s */
  bool done = 0; 
  
  while (!done) 
  { 
    /* Reach the left most tree node of the current tree node */
    if(current !=  NULL) 
    { 
      push(&s, current);                                                
      current = current->left;   
    } 
    else                                                              
    { 
      if (!isEmpty(s)) 
      { 
        current = pop(&s); 
        printf("%d -> ", current->data);
        current = current->right; 
      } 
      else
        done = 1;  
    } 
  } /* end of while */  
}      

/* Iterative function for preorder traversal */
void printPreOrderNonRecursive(struct node *root) 
{ 
  /* set current to root of binary tree */
  struct node *current = root; 
  struct stackNode *s = NULL;  /* Initialize stack s */
  bool done = 0; 
  
  while (!done) 
  { 
    /* Reach the left most tree node of the current tree node */
    if(current !=  NULL) 
    {
	  printf("%d -> ", current->data);	
      push(&s, current);                                                
      current = current->left;   
    } 
    else                                                              
    { 
      if (!isEmpty(s)) 
      { 
        current = pop(&s); 
        current = current->right; 
      } 
      else
        done = 1;  
    } 
  } /* end of while */  
}      

/* Iterative function for postorder traversal */
void printPostOrderNonRecursive(struct node *root) 
{ 
  /* set current to root of binary tree */
  struct node *current = root; 
  struct stackNode *s = NULL;  /* Initialize stack s */
  struct stackForPostOrder *s2 = NULL;  /* Initialize stack for postorder */
  bool done = 0; 
  
  while (!done) 
  { 
    /* Reach the left most tree node of the current tree node */
    if(current !=  NULL) 
    {
	  
	  push(&s, current);
	  pushForPostOrder(&s2, current);
      current = current->right;   
    } 
    else                                                              
    { 
      if (!isEmpty(s)) 
      { 
        current = pop(&s); 
		//printf("%d -> ", current->data);
        current = current->left; 
      } 
      else
        done = 1;  
    } 
  } /* end of while */  
  
  while(!isEmptyForPostOrder(s2))
  {
	  printf("%d -> ", popForPostOrder(&s2)->data);
  }
}      

void pushForPostOrder(struct stackForPostOrder** topRef, struct node *t)
{ 
  /* allocate tree node */
  struct stackForPostOrder* newNode = (struct stackForPostOrder*) malloc(sizeof(struct stackForPostOrder)); 
  
  if(newNode == NULL) 
  { 
     printf("Stack Overflow \n"); 
     getchar(); 
     exit(0); 
  }             
  newNode->t  = t; 
  newNode->next = (*topRef);    
  (*topRef)    = newNode; 
} 
/* Function to push an item to stackNode*/
void push(struct stackNode** topRef, struct node *t) 
{ 
  /* allocate tree node */
  struct stackNode* newNode = (struct stackNode*) malloc(sizeof(struct stackNode)); 
  
  if(newNode == NULL) 
  { 
     printf("Stack Overflow \n"); 
     getchar(); 
     exit(0); 
  }             
  newNode->t  = t; 
  newNode->next = (*topRef);    
  (*topRef)    = newNode; 
} 
 
/* The function returns true if stack is empty, otherwise false */
int isEmptyForPostOrder(struct stackForPostOrder *top) 
{ 
   return (top == NULL)? 1 : 0; 
}  
 
/* The function returns true if stack is empty, otherwise false */
int isEmpty(struct stackNode *top) 
{ 
   return (top == NULL)? 1 : 0; 
}    

/* Function to pop an item from stack*/
struct node *popForPostOrder(struct stackForPostOrder** topRef) 
{ 
  struct node *res; 
  struct stackForPostOrder *top; 
  
  if(isEmptyForPostOrder(*topRef)) 
  { 
     printf("Stack Underflow \n"); 
     getchar(); 
     exit(0); 
  } 
  else
  { 
     top = *topRef; 
     res = top->t; 
     *topRef = top->next; 
     free(top); 
     return res; 
  } 
} 
  
/* Function to pop an item from stack*/
struct node *pop(struct stackNode** topRef) 
{ 
  struct node *res; 
  struct stackNode *top; 
  
  if(isEmpty(*topRef)) 
  { 
     printf("Stack Underflow \n"); 
     getchar(); 
     exit(0); 
  } 
  else
  { 
     top = *topRef; 
     res = top->t; 
     *topRef = top->next; 
     free(top); 
     return res; 
  } 
} 

struct node* newTree(int num)
{
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	if(newNode != NULL)
	{
		newNode->data = num;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	return NULL;
}

struct node* insert(struct node *tree, int num)
{
	if(tree == NULL)
		newTree(num);
	else if(num <= (tree->data))
		insert(tree->left, num);
	else if(num > tree->data)
		insert(tree->right, num);
	
	return tree;
}

void printTree(struct node *tree)
{
	if(tree == NULL)
		return;
	printf("%d -> ", tree->data);
	printTree(tree->left);
	printTree(tree->right);
}

void printPreorderRecursive(struct node *tree)
{
	if(tree == NULL)
		return;
	printf("%d -> ", tree->data);
	printPreorderRecursive(tree->left);
	printPreorderRecursive(tree->right);
}

void printPostorderRecursive(struct node *tree)
{
	if(tree == NULL)
		return;
	printPostorderRecursive(tree->left);
	printPostorderRecursive(tree->right);
	printf("%d -> ", tree->data);
}

void printInorderRecursive(struct node *tree)
{
	if(tree == NULL)
		return;
	printInorderRecursive(tree->left);
	printf("%d -> ", tree->data);
	printInorderRecursive(tree->right);
}

int main()
{
	struct node *root = newTree(1);
	root->left = newTree(2);
	root->right = newTree(3);
	root->left->left = newTree(4);
	root->left->right = newTree(5);
	root->right->left = newTree(6);
	root->right->right = newTree(7);

	//printf("Printing tree...\n");
	//printTree(root);
	
	printf("Printing tree - InOrder...\n");
	printInorderRecursive(root);
	printf("NULL\n\n");
	
	printf("Printing tree - PreOrder...\n");
	printPreorderRecursive(root);
	printf("NULL\n\n");
	
	printf("Printing tree - PostOrder...\n");
	printPostorderRecursive(root);
	printf("NULL\n\n");
	
	printf("Printing tree - InOrder non-recursive...\n");
	printInOrderNonRecursive(root);
	printf("NULL\n\n");
	
	printf("Printing tree - PreOrder non-recursive...\n");
	printPreOrderNonRecursive(root);
	printf("NULL\n\n");
	
	printf("Printing tree - PostOrder non-recursive...\n");
	printPostOrderNonRecursive(root);
	printf("NULL\n\n");
	
	return 0;
}
