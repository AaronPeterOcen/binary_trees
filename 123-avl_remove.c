#include "binary_trees.h"

avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
	{
		return NULL;
       	}

	if (value < root->n)
	{
		root->left = avl_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = avl_remove(root->right, value);
	}
	else
	{
		/* Node to be deleted found */
		/* 1. Handle node with no or one child */
	if (root->left == NULL)
	{
		avl_t *temp = root->right;
		free(root);
		return temp;
	}
	else if (root->right == NULL)
	{
		avl_t *temp = root->left;
		free(root);
		return temp;
	}

	/* 2. Node with two children: Replace with in-order successor */
	avl_t *temp = successor(root->right);
	root->n = temp->n;
	root->right = avl_remove(root->right, temp->n);
	}

	/* 3. Rebalance if necessary */
	root = bal(root);
	return root;
}
