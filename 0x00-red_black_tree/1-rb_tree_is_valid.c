#include "rb_trees.h"

static size_t max_black;

/**
 * key_fail - checks if valid binary search tree
 * @cur: pointer to current tree node
 *
 * Return: 1 if invalid binary search tree, otherwise 0
 */
int key_fail(const rb_tree_t *cur)
{
	if ((cur->left && cur->left->n > cur->n) ||
			(cur->right && cur->right->n < cur->n))
		return (1);
	return (0);
}

/**
 * colour_fail - checks if red-black tree colour properties are valid
 * @cur: pointer to current tree node
 *
 * Return: 1 if invalid colour properties, otherwise 0
 */
int colour_fail(const rb_tree_t *cur)
{
	if (cur->color != RED && cur->color != BLACK)
		return (1);
	if (cur->color == RED &&
			((cur->parent && cur->parent->color == RED) ||
			 (cur->left && cur->left->color == RED) ||
			 (cur->right && cur->right->color == RED)))
		return (1);
	return (0);
}

/**
 * check_rb_tree - recursively checks if red-black tree is valid
 * @tree: pointer to tree node
 * @black_count: count of black nodes
 *
 * Return: 1 if valid, otherwise 0
 */
int check_rb_tree(const rb_tree_t *tree, size_t black_count)
{
	if (!tree)
	{
		if (!max_black)
			max_black = black_count;
		return (1);
	}
	if (colour_fail(tree) || key_fail(tree))
		return (0);
	if (tree->color == BLACK)
		++black_count;
	if (!check_rb_tree(tree->left, black_count) ||
			!check_rb_tree(tree->right, black_count))
		return (0);
	if ((!tree->left || !tree->right) && black_count != max_black)
		return (0);
	return (1);
}

/**
 * rb_tree_is_valid - checks if binary tree is valid red-black tree
 * @tree: pointer to root node of tree being checked
 *
 * Return: 1 if valid, otherwise 0
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	size_t black_count;

	if (!tree || tree->color != BLACK)
		return (0);
	black_count = max_black = 0;
	return (check_rb_tree(tree, black_count));
}
