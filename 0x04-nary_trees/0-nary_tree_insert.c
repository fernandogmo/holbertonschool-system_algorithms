#include "nary_trees.h"

/**
 * nary_tree_insert - insert a new child node into an n-ary tree
 * @parent: pointer to nary_tree_t parent node
 * @str: string to copy into new node
 * Return: pointer to new nary_tree_t node, or NULL on failure
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *node = malloc(sizeof(*node));
	if (!node) goto fail;

	node->content = strdup(str);
	if (!node->content) goto fail;

	node->parent = parent;
	node->nb_children = 0;
	node->children = node->next = NULL;
	if (parent)
	{
		node->next = parent->children;
		parent->children = node;
		parent->nb_children++;
	}
	return (node);
fail:
	free(node);
	return (NULL);
}
