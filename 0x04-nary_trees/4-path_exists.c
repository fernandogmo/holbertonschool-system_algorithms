#include "nary_trees.h"

/**
* path_exists - check if path exists in an n-ary tree
* @root: pointer to root of nary_tree_t tree
* @path: NULL-terminated array of strings
* Return: 1 if path exists, 0 otherwise
*/
int path_exists(nary_tree_t const *root, char const * const *path)
{
	nary_tree_t const *node;

	if (!path || !path[0] || !root || strcmp(path[0], root->content) != 0)
		return (0);
	if (!path[1])
		return (1);
	node = root->children;
	while (node)
	{
		if (path_exists(node, path + 1))
			return (1);
		node = node->next;
	}
	return (0);
}
