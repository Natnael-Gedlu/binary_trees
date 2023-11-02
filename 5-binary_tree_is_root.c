#include "binary_trees.h"

/**
* binary_tree_is_root - Checks if a given node is a root node in a binary tree.
* @node: Pointer to the node to be checked.
* Return: 1 if the node is a root, 0 if the node is NULL or has a parent.
*/
int binary_tree_is_root(const binary_tree_t *node)
{
if (node == NULL || node->parent != NULL)
return (0);

return (1);
}
