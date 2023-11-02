#include "binary_trees.h"

/**
* binary_tree_rotate_left - Performs a left rotation on a given
* binary tree node.
* @tree: Pointer to the node at which to perform the left rotation.
* Return: Pointer to the new root node after the left rotation,
* NULL if node is NULL or no right child.
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *pivot, *tmp;

if (tree == NULL || tree->right == NULL)
return (NULL);

pivot = tree->right;
tmp = pivot->left;
pivot->left = tree;
tree->right = tmp;
if (tmp != NULL)
tmp->parent = tree;
tmp = tree->parent;
tree->parent = pivot;
pivot->parent = tmp;
if (tmp != NULL)
{
if (tmp->left == tree)
tmp->left = pivot;
else
tmp->right = pivot;
}

return (pivot);
}
