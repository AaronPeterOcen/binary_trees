#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mm, *pp;

	if (!first || !second)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	mm = first->parent, pp = second->parent;
	if (first == pp || !mm || (!mm->parent && pp))
		return (binary_trees_ancestor(first, pp));
	else if (mm == second || !pp || (!pp->parent && mm))
		return (binary_trees_ancestor(mm, second));
	return (binary_trees_ancestor(mm, pp));
}
