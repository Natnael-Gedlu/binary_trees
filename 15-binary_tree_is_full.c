#include "binary_trees.h"

/**
* is_full_recursive - Checks if a binary tree and its subtrees are full.
* @tree: Pointer to the root node of the binary tree or its subtree.
* Return: 1 if the tree is full, 0 if not full or tree is NULL.
*/
int is_full_recursive(const binary_tree_t *tree)
{
if (tree != NULL)
{
if ((tree->left != NULL && tree->right == NULL) ||
(tree->left == NULL && tree->right != NULL) ||
is_full_recursive(tree->left) == 0 ||
is_full_recursive(tree->right) == 0)
return (0);
}
return (1);
}

/**
* binary_tree_is_full - Checks if a binary tree is a full binary tree.
* @tree: Pointer to the root node of the binary tree.
* Return: 1 if the tree is a full binary tree, 0 otherwise.
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_full_recursive(tree));
}
