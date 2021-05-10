#include <stdlib.h>
#include "heap.h"

/**
 * free_binary_tree_node - frees a node_t node and its data
 * @node: node_t pointer to the node to free
 * @free_data: pointer to function to free node data
 */
void free_binary_tree_node(node_t *node, void (*free_data)(void *))
{
	if (node)
	{
		free_binary_tree_node(node->left, free_data);
		free_binary_tree_node(node->right, free_data);
		if (free_data) free_data(node->data);
		free(node);
	}
}

/**
 * heap_delete - deallocates a heap_t heap
 * @heap: heap_t pointer to the heap to delete
 * @free_data: pointer to function to free node data
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (heap)
	{
		free_binary_tree_node(heap->root, free_data);
		free(heap);
	}
}
