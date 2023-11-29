#include "binary_trees.h"
/**
 * binary_tree_leaves - measures the leaves count of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: number of leaves of a binary tree otherwise 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		leaves = 0;
	else if (tree->left && tree->right == NULL)
		leaves = 1;
	else if (tree->left == NULL && tree->right)
		leaves = 1;
	else
		leaves = 2;
	return (leaves);
}
