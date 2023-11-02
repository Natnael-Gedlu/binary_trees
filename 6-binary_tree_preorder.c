#include "binary_trees.h"

/**
* binary_tree_preorder - Executes a function on each node of a binary
* tree using pre-order traversal.
* @tree: Pointer to the root node of the binary tree.
* @func: Pointer to the function to be applied to each node's value.
* Return: Void function.
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree && func)
{
func(tree->n);
binary_tree_preorder(tree->left, func);
binary_tree_preorder(tree->right, func);
}
}
