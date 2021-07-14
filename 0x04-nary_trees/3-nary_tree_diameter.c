#include "nary_trees.h"

/**
 * max_depth - desc
 * @root: root
 * Return: size_t max depth of n-ary tree
 */
static size_t max_depth(nary_tree_t const *root)
{
	size_t maxdepth = 0;
	nary_tree_t *node;

	if (!root) return (0);

	for (node = root->children; node; node = node->next)
		maxdepth = MAX(maxdepth , max_depth(node));

	return (maxdepth + 1);
}

/**
 * nary_tree_diameter - desc
 * @root: root
 * Return: size_t diameter of n-ary tree
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t max1 = 0, max2 = 0, max_child_diam = 0;
	nary_tree_t *node;

	if (!root) return (0);

	for (node = root->children; node; node = node->next)
	{
		size_t h = max_depth(node);

		if (h > max1)
		{
			max2 = max1;
			max1 = h;
		}
		else if (h > max2)
			max2 = h;
	}

	for (node = root->children; node; node = node->next)
		max_child_diam = MAX(max_child_diam, nary_tree_diameter(node));

	return (MAX(max_child_diam, max1 + max2 + 1));
}
