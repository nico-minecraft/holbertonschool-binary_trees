#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (tree->left != NULL)
		left_height++;
	if (tree->right != NULL)
		right_height++;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, otherwise 0. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, expected;

	if (tree == NULL)
		return (0);

	height = tree_height(tree);
	size = tree_size(tree);
	expected = (1UL << (height + 1)) - 1;

	return (size == expected);
}
