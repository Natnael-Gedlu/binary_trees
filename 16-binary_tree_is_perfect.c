#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
* is_leaf - Determines if a given node is a leaf.
* @node: Pointer to a node in the binary tree.
* Return: 1 if the node is a leaf, 0 if not or node is NULL.
*/
unsigned char is_leaf(const binary_tree_t *node)
{
return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
* depth - Computes the depth of a node in a binary tree.
* @tree: Pointer to a node in the binary tree.
* Return: The depth of the node from the root.
*/
size_t depth(const binary_tree_t *tree)
{
return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
* get_leaf - Retrieves a leaf node in the binary tree starting
* from a given node.
* @tree: Pointer to the root node of the binary tree.
* Return: Pointer to a leaf node starting from the given node.
*/
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
if (is_leaf(tree) == 1)
return (tree);
return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

int is_perfect_recursive(const binary_tree_t *tree,
size_t leaf_depth, size_t level)
{
if (is_leaf(tree))
return (level == leaf_depth ? 1 : 0);
if (tree->left == NULL || tree->right == NULL)
return (0);
return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect.
* @tree: Pointer to the root node of the binary tree.
* Return: 1 if the binary tree is perfect, 0 if not perfect or tree is NULL.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}