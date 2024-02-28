#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: if tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, size;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	size = (int)binary_tree_size(tree);
	return ((1 << (height + 1)) - 1 == size ? 1 : 0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to be trasversed
 * Return: height of tree or 0 if tree is NULL or has a single node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t left_height;
        size_t right_height;

        if (!tree || (!tree->left && !tree->right))
                return (0);

        left_height = binary_tree_height(tree->left);
        right_height = binary_tree_height(tree->right);

        if (left_height > right_height)
                return (left_height + 1);
        else
                return (right_height + 1);
}

/**
 * binary_tree_size - measures the size of abinary tree
 * @tree: pointer to the root node of the tree to be traversed
 * Return: size of tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
        size_t left_depth;
        size_t right_depth;

        if (!tree)
                return (0);

        left_depth = binary_tree_size(tree->left);
        right_depth = binary_tree_size(tree->right);

        return (right_depth + left_depth + 1);
}
