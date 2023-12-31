#include "binary_trees.h"

/**
* binary_tree_depth - Calculates the depth of a node in a binary tree.
* @tree: Pointer to the node for which depth is being calculated.
* Return: Depth of the node as size_t value. Returns 0 if tree is NULL
* or if the node has no parent.
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
