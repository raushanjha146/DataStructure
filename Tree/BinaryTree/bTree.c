#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

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

void printPreorder(struct node *tree)
{
	if(tree == NULL)
		return;
	printf("%d -> ", tree->data);
	printPreorder(tree->left);
	printPreorder(tree->right);
}

void printPostorder(struct node *tree)
{
	if(tree == NULL)
		return;
	printPostorder(tree->left);
	printPostorder(tree->right);
	printf("%d -> ", tree->data);
}

void printInorder(struct node *tree)
{
	if(tree == NULL)
		return;
	printInorder(tree->left);
	printf("%d -> ", tree->data);
	printInorder(tree->right);
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
	printInorder(root);
	printf("NULL\n\n");
	
	printf("Printing tree - PreOrder...\n");
	printPreorder(root);
	printf("NULL\n\n");
	
	printf("Printing tree - PostOrder...\n");
	printPostorder(root);
	printf("NULL\n\n");
	
	return 0;
}
