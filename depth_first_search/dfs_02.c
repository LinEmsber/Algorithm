/* This is a simple implementation of depth first search (DPS) on binary search tree. */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * new_node(int data)
{
	struct node * node = (struct node *) malloc( sizeof(struct node) );
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node ;
}

/* Print tree nodes in postorder. */
void print_post_order(struct node * node)
{
	if (node == NULL)
		return;

	print_post_order(node->left);
	print_post_order(node->right);
	printf("%d ", node->data);
}

/* Print tree nodes in inorder. */
void print_in_order(struct node * node)
{
	if (node == NULL)
		return;

	print_in_order(node->left);
	printf("%d ", node->data);
	print_in_order(node->right);
}

/* Print tree nodes in preorder. */
void print_pre_order(struct node* node)
{
	if (node == NULL)
		return;

	printf("%d ", node->data);
	print_pre_order(node->left);
	print_pre_order(node->right);
}

/* Driver program to test above functions. */
int main()
{
	struct node * root  = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->left = new_node(6);
	root->right->right = new_node(7);
	root->left->left->left = new_node(8);
	root->left->left->right = new_node(9);

	printf("\nPreorder traversal of binary tree is \n");
	print_pre_order(root);

	printf("\nInorder traversal of binary tree is \n");
	print_in_order(root);

	printf("\nPostorder traversal of binary tree is \n");
	print_post_order(root);

	return 0;
}
