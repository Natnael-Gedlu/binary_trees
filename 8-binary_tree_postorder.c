#include "binary_trees.h"

/**
* binary_tree_postorder - Executes a function on each node of a binary
* tree using post-order traversal.
* @tree: Pointer to the root node of the binary tree.
* @func: Pointer to the function to be applied to each node's value.
* Return: Void function.
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree && func)
{
binary_tree_postorder(tree->left, func);
binary_tree_postorder(tree->right, func);
func(tree->n);
}
}
