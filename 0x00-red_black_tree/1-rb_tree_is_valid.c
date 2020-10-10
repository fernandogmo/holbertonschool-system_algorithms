#include "rb_trees.h"
#include <limits.h>

size_t height(const rb_tree_t *tree);
int rb_tree_is_valid_helper(const rb_tree_t *tree, int lo, int hi);
int rb_tree_is_valid(const rb_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const rb_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
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
 * rb_tree_is_valid_helper - Checks if a binary tree is a valid R-B tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 * Return: If the tree is a valid R-B tree, 1, otherwise, 0.
 */
int rb_tree_is_valid_helper(const rb_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{

		if (tree->n < lo || tree->n > hi || colour_fail(tree))
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (rb_tree_is_valid_helper(tree->left, lo, tree->n - 1) &&
			rb_tree_is_valid_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * rb_tree_is_valid - Checks if a binary tree is a valid R-B tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid R-B tree, and 0 otherwise
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree || tree->color != BLACK)
		return (0);
	return (rb_tree_is_valid_helper(tree, INT_MIN, INT_MAX));
}
