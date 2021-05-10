#include "heap.h"
#include <stdio.h>

/**
 * heapify - restores heap property from leaf node of subtree
 * @node: node_t leaf node of heap tree
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
	if (!heap->size)
	{
		harray[heap->size++] = binary_tree_node(NULL, data);
DBG(PRINT_NODE_ARRAY((const node_t **)&harray, heap->size));
DBG(printf("heap->size now %ld\n\n", heap->size));
		return (heap->root = harray[0]);
	}
	node_t *parent = harray[(heap->size - 1) / 2];
	harray[heap->size++] = (!parent->left)
			? (parent->left = binary_tree_node(parent, data))
			: (parent->right = binary_tree_node(parent, data));
	node_t *new = (heapify(harray[heap->size - 1], heap->data_cmp));
DBG(PRINT_NODE_ARRAY((const node_t **)&harray, heap->size));
DBG(printf("heap->size now %ld\n\n", heap->size));
	return (new);
);}
