#include "binary_trees.h"

/**
* binary_tree_sibling - Finds the sibling of a given node in a binary tree.
* @node: Pointer to the node whose sibling is to be found.
* Return: Pointer to the sibling node if it exists, NULL if node is NULL or
* has no parent or sibling.
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL)
return (NULL);
if (node->parent->left == node)
return (node->parent->right);
return (node->parent->left);
}
