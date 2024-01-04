#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pt, *tp;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	pt = tree->right;
	tp = pt->left;
	pt->left = tree;
	tree->right = tp;

	if (tp != NULL)
		tp->parent = tree;

	tp = tree->parent;
	tree->parent = pt;
	pt->parent = tp;

	if (tp != NULL)
	{
		if (tp->left == tree)
			tp->left = pt;
		else
			tp->right = pt;
	}
	return (pt);
}
