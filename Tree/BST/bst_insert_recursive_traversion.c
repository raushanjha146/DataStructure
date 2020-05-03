#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
  
  
struct node* insert(struct node* root, int data)
{
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);   
 
    return root;
}

void inorder(struct node* root){
	// Left, Root, Right
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}

void preorder(struct node* root){
	// Root, Left, Right
    if(root == NULL) return;
    printf("%d ->", root->data);
    preorder(root->left);    
    preorder(root->right);
}

void postorder(struct node* root){
	// Left, Right, Root
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ->", root->data);
}

int main()
{
    struct node *root = NULL;
    int root_data, node_data;
    /*
	root = insert(root, 8);
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    insert(root, 10);
    insert(root, 14);
    insert(root, 4);
	*/
	printf("Please enter the root value\n");
	scanf("%d", &root_data);
	if(root_data > 0)
	{
		root = insert(root, root_data);
		printf("Please enter the node value, 0 to exit...\n");
		scanf("%d", &node_data);
		while(node_data > 0)	
		{
			insert(root, node_data);
			printf("Please enter the node value, 0 to exit...\n");
			scanf("%d", &node_data);
		}
	}
	printf("In-Order : \n");
    inorder(root);
    printf("\n\n");
    
    printf("Pre-Order : \n");
    preorder(root);
    printf("\n\n");
    
    printf("Post-Order : \n");
    postorder(root);
    printf("\n\n");
    
}

/*
Element : 21, 28, 14, 32, 25, 11,18, 30, 19, 15

InOrder : 11, 14, 15, 18, 19, 21, 25, 28, 32, 30
PreOrder : 21, 14, 11, 18, 15, 19, 28, 25, 32, 30
PostOrder : 11, 15, 19, 18, 14, 25, 30, 32, 28, 21
*/

