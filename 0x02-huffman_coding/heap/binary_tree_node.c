#include <stdlib.h>
#include <string.h>

#include "heap.h"

/**
 * binary_tree_node - creates a generic binary node with no children
 * @parent: parent node to new node
 * @data: void pointer to generic key value for new node
 * Return: pointer to new node or NULL on failure
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{C99(
	binary_tree_node_t src = (binary_tree_node_t){data, NULL, NULL, parent};
	binary_tree_node_t *dst = calloc(1, sizeof(*dst));
	if (!dst) return (NULL);
	return (memcpy(dst, &src, sizeof(src)));
);}
