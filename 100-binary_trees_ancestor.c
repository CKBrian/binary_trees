#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the ancestor node otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *parent = NULL;
	binary_tree_t *second_parent = NULL, *first_parent = NULL;

	if (!first || !second || !first->parent || !second->parent)
		return (NULL);
	if (first->n == second->n)
		return ((binary_tree_t *)first);
	if (second->parent->n == first->n)
		return (second->parent);
	if (first->parent->n == second->n)
		return (first->parent);
	if (first->parent->n == second->parent->n)
		return (first->parent);
	first_parent = binary_trees_ancestor(first, second->parent);
	second_parent = binary_trees_ancestor(first->parent, second);
	if ((!first_parent && second_parent) || (first_parent && second_parent))
		parent = second_parent;
	if (first_parent && !second_parent)
		parent = first_parent;

	return (parent);
}
