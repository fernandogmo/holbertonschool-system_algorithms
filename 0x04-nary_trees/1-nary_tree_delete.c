#include "nary_trees.h"

/**
 * nary_tree_delete - frees all nodes in a nary_tree_t
 * @tree: pointer to nary_tree_t to be freed
 */
void nary_tree_delete(nary_tree_t *tree)
{
	while (tree && tree->children)
	{
		nary_tree_t *node = tree->children;
		tree->children = node->next;
		nary_tree_delete(node);
	}
	if (tree) free(tree->content);
	free(tree);
}
