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
