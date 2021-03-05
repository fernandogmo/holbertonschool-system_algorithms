#include "rb_trees.h"

/**
 * rb_tree_node - creates a node with no children
 * @parent: pointer to parent node of new node
 * @value: value of new node
 * @color: color of new node
 * Return: pointer to new node or NULL on failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new = malloc(sizeof(*new));

	if (!new || color / 3)
		return (NULL);
	new->parent = parent;
	new->n = value;
	new->color = color;
	new->left = new->right = NULL;

	return (new);
}


/* THESE FUNCTIONS WILL BE USED FOR TASK 2 AND TASK 4 */
/**
 * rotate_right - rotates subtree right
 * @tree: double pointer to root node
 * @node: pointer to parent of unbalanced children
 */
void rotate_right(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *pivot = node->left;

	if (!pivot)
		return;
	node->left = pivot->right;
	if (pivot->right)
		pivot->right->parent = node;
	pivot->parent = node->parent;
	if (!node->parent)
		*tree = pivot;
	else if (node == node->parent->right)
		node->parent->right = pivot;
	else
		node->parent->left = pivot;
	pivot->right = node;
	node->parent = pivot;
}

/**
 * rotate_left - rotates subtree left
 * @tree: double pointer to root node
 * @node: pointer to parent of unbalanced children
 */
void rotate_left(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *pivot = node->right;

	if (!pivot)
		return;
	node->right = pivot->left;
	if (pivot->left)
		pivot->left->parent = node;
	pivot->parent = node->parent;
	if (!node->parent)
		*tree = pivot;
	else if (node == node->parent->left)
		node->parent->left = pivot;
	else
		node->parent->right = pivot;
	pivot->left = node;
	node->parent = pivot;
}
