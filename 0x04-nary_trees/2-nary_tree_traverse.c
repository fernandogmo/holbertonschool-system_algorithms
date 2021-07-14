#include "nary_trees.h"

/**
 * nary_tree_traverse_rec - desc
 * @root: root
 * @action: action
 * @curr_depth: size_t
 * Return: size_t largest depth traversed
 */
static size_t nary_tree_traverse_rec(nary_tree_t const *root,
	void (*action)(nary_tree_t const *node, size_t depth),
	size_t curr_depth)
{
	nary_tree_t const *node;
	size_t depth = 1;

	if (!root) return (0);

	action(root, curr_depth);
	for (node = root->children; node; node = node->next)
	{
		size_t d = nary_tree_traverse_rec(node, action, curr_depth + 1);

		depth = MAX(depth, d);
	}
	return (depth);
}

/**
 * nary_tree_traverse - desc
 * @root: root
 * @action: action
 * Return: size_t largest depth traversed
 */
size_t nary_tree_traverse(nary_tree_t const *root,
	void (*action)(nary_tree_t const *node, size_t depth))
{
	return (nary_tree_traverse_rec(root, action, 0));
}
