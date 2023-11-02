#include "binary_trees.h"

/**
* binary_tree_insert_left - Inserts a node with a specified value to
* the left of the given parent node in a binary tree.
* @parent: Pointer to the parent node.
* @value: Integer value for the new node to be inserted.
* Return: Pointer to the newly inserted node, or NULL on failure.
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new;

if (parent == NULL)
return (NULL);

new = binary_tree_node(parent, value);
if (new == NULL)
return (NULL);

if (parent->left != NULL)
{
new->left = parent->left;
parent->left->parent = new;
}
parent->left = new;

return (new);
}
