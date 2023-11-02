#include "binary_trees.h"

/**
* binary_tree_insert_right - Inserts a node with a specified value to the right
* of the given parent node in a binary tree.
* @parent: Pointer to the parent node.
* @value: Integer value for the new node to be inserted.
* Return: Pointer to the newly inserted node, or NULL on failure.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *new;

if (parent == NULL)
return (NULL);

new = binary_tree_node(parent, value);
if (new == NULL)
return (NULL);

if (parent->right != NULL)
{
new->right = parent->right;
parent->right->parent = new;
}
parent->right = new;

return (new);
}
