#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
* create_node - Creates a new node for the level-order traversal queue.
* @node: Pointer to the binary tree node to be stored in the new node.
* Return: Pointer to the newly created levelorder_queue_t node, NULL if memory allocation fails.
*/
levelorder_queue_t *create_node(binary_tree_t *node)
{
levelorder_queue_t *new;

new = malloc(sizeof(levelorder_queue_t));
if (new == NULL)
return (NULL);

new->node = node;
new->next = NULL;

return (new);
}

/**
* free_queue - Frees the memory of all nodes in the level-order traversal queue.
* @head: Pointer to the head of the queue.
*/
void free_queue(levelorder_queue_t *head)
{
levelorder_queue_t *tmp;

while (head != NULL)
{
tmp = head->next;
free(head);
head = tmp;
}
}

/**
* pint_push - Pushes nodes to the level-order traversal queue and applies a function to their values.
* @node: Pointer to the binary tree node.
* @head: Pointer to the head of the queue.
* @tail: Pointer to the tail of the queue.
* @func: Pointer to a function to apply to the values.
*/
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
levelorder_queue_t **tail, void (*func)(int))
{
levelorder_queue_t *new;

func(node->n);
if (node->left != NULL)
{
new = create_node(node->left);
if (new == NULL)
{
free_queue(head);
exit(1);
}
(*tail)->next = new;
*tail = new;
}
if (node->right != NULL)
{
new = create_node(node->right);
if (new == NULL)
{
free_queue(head);
exit(1);
}
(*tail)->next = new;
*tail = new;
}
}

/**
* pop - Removes the head node from the level-order traversal queue.
* @head: Pointer to the head of the queue.
*/
void pop(levelorder_queue_t **head)
{
levelorder_queue_t *tmp;

tmp = (*head)->next;
free(*head);
*head = tmp;
}

/**
* binary_tree_levelorder - Performs a level-order traversal of a binary tree and applies a function to each node's value.
* @tree: Pointer to the root node of the binary tree.
* @func: Pointer to the function to apply to each node's value.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
levelorder_queue_t *head, *tail;

if (tree == NULL || func == NULL)
return;

head = tail = create_node((binary_tree_t *)tree);
if (head == NULL)
return;

while (head != NULL)
{
pint_push(head->node, head, &tail, func);
pop(&head);
}
}
