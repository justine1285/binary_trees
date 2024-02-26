#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the parent node of the new node
 * @value: value to put in new node
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;
	binary_tree_t *newnode_ptr;

	if (!parent)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));
	if (!newnode)
		return (NULL);

	newnode->n = value;
	newnode->left = newnode->right = NULL;

	if (!parent->right)
	{
		parent->right = newnode;
		newnode->parent = parent;
	}
	else
	{
		newnode->right = parent->right;
		(newnode->right)->parent = newnode;
		parent->right = newnode;
		newnode->parent = parent;
	}

	newnode_ptr = newnode;
	return (newnode_ptr);
}
