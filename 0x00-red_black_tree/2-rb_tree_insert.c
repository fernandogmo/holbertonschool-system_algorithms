#include "rb_trees.h"

/**
 * repair_rb_luncle - uncle of node is to the left
 * @tree: double pointer to root node
 * @node: pointer to node where violation detected
 *
 * Return: pointer to node
 */
rb_tree_t *repair_rb_luncle(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *grandparent, *uncle = node->parent->parent->left;

	if (uncle && uncle->color == RED)
	{
		node->parent->color = BLACK;
		uncle->color = BLACK;
		grandparent = node->parent->parent;
		grandparent->color = RED;
		node = grandparent;
	}
	else
	{
		if (node == node->parent->left)
		{
			node = node->parent;
			rotr(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		rotl(tree, node->parent->parent);
	}
	return (node);
}

/**
 * repair_rb_runcle - uncle of node is to the right
 * @tree: double pointer to root node
 * @node: pointer to node where violation detected
 *
 * Return: pointer to node
 */
rb_tree_t *repair_rb_runcle(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *grandparent, *uncle = node->parent->parent->right;

	if (uncle && uncle->color == RED)
	{
		node->parent->color = BLACK;
		uncle->color = BLACK;
		grandparent = node->parent->parent;
		grandparent->color = RED;
		node = grandparent;
	}
	else
	{
		if (node == node->parent->right)
		{
			node = node->parent;
			rotl(tree, node);
		}
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
		rotr(tree, node->parent->parent);
	}
	return (node);
}

/**
 * repair_rb - repairs red-black tree violations
 * @tree: double pointer to root node
 * @node: pointer to newly inserted node
 *
 * As violations are detected, node will continually shift up
 */
void repair_rb(rb_tree_t **tree, rb_tree_t *node)
{
	while (node->parent && node->parent->color == RED)
	{
		if (node->parent->parent &&
				node->parent == node->parent->parent->left)
			node = repair_rb_runcle(tree, node);
		else
			node = repair_rb_luncle(tree, node);
	}
	(*tree)->color = BLACK;
}

/**
 * insert_rb - inserts node into appropriate binary search tree position
 * @tree: pointer to red-black tree
 * @value: value of node to insert
 *
 * Description: newly created node will be RED
 * Return: pointer to newly created node, NULL on failure
 */
rb_tree_t *insert_rb(rb_tree_t **tree, int value)
{
	rb_tree_t *cur, *prev, *new;

	prev = NULL;
	cur = *tree;
	while (cur)
	{
		prev = cur;
		if (value < cur->n)
			cur = cur->left;
		else if (value > cur->n)
			cur = cur->right;
		else
			return (NULL);
	}
	new = rb_tree_node(NULL, value, RED);
	if (!new)
		return (NULL);
	new->parent = prev;
	if (!prev)
		*tree = new;
	else if (new->n < prev->n)
		prev->left = new;
	else
		prev->right = new;
	return (new);
}

/**
 * rb_tree_insert - inserts node into red-black tree
 * @tree: double pointer to root node of red-black tree
 * @value: value of node to insert
 *
 * Return: pointer to newly created node, NULL on failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new;

	if (!tree)
		return (NULL);
	new = insert_rb(tree, value);
	if (new)
		repair_rb(tree, new);
	return (new);
}
