#include "heap.h"

/**
 * heapify - restores heap property from root node of subtree
 * @node: hode_t root root of heap tree
 * @data_cmp: comparison function over generic data pointers
 * Return: node_t pointer to sifted up node
 */
static node_t *heapify(node_t *node, int (*data_cmp)(void *, void *))
{
	if (!node || !data_cmp) return (NULL);
	while (node->parent && data_cmp(node->data, node->parent->data) < 0)
	{
		DATASWAP(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - inserts a value in a binary heap
 * *		 (uses static reference array)
 * @heap: pointer to heap_t where we'll insert node
 * @data: generic pointer to data for new node
 * Return: node_t pointer to the newly inserted node
 */
node_t *heap_insert(heap_t *heap, void *data)
{C99(
	if (!heap || !data) return (NULL);
	static node_t *harray[32];
	static size_t hlen;
	++heap->size;
	if (!heap->root)
	{
		harray[hlen = 0] = binary_tree_node(NULL, data);
		return (heap->root = harray[hlen++]);
	}
	node_t *parent = harray[(hlen - 1) / 2];
	harray[hlen++] = (!parent->left)
			? (parent->left = binary_tree_node(parent, data))
			: (parent->right = binary_tree_node(parent, data));
	return (heapify(harray[hlen - 1], heap->data_cmp));
);}
