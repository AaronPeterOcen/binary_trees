#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *now;

	now = malloc(sizeof(binary_tree_t));
	if (now == NULL)
		return (NULL);

	now->n = value;
	now->parent = parent;
	now->left = NULL;
	now->right = NULL;

	return (now);
}
