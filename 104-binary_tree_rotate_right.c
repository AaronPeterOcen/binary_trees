#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pt, *tp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pt = tree->left;
	tp = pt->right;
	pt->right = tree;
	tree->left = tp;

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
