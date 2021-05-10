#include <stdlib.h>
#include "heap.h"
#include <stdio.h>

/**
 * heapify - restores heap property from root node of subtree
 * @root: hode_t root root of heap tree
 * @data_cmp: comparison function over generic data pointers
 */
static void heapify(node_t *root, int (*data_cmp)(void *, void *))
{
	if (!root || !root->left || !data_cmp) return;

	if (root->right && data_cmp(root->left->data, root->right->data) > 0)
	{
		if (data_cmp(root->data, root->right->data) >= 0)
			DATASWAP(root, root->right);
		heapify(root->right, data_cmp);
	}
	else
	{
		if (data_cmp(root->data, root->left->data) >= 0)
			DATASWAP(root, root->left);
		heapify(root->left, data_cmp);
	}
}

/**
 * heap_to_array - it does this while calculating heap size
 * @array: node_t buffer where we are storing our heap elements
 * @root: root node_t of our heap subtree
 * @i: size_t index of subtree's @root node
 * Return: size_t size of heap. the same as the length of @array
 */
static size_t heap_to_array(node_t **array, node_t *root, size_t i)
{
	return (!root || !array || !(array[i] = root)
		? 0 : 1 + heap_to_array(array, root->left, 2 * i + 1)
			+ heap_to_array(array, root->right, 2 * i + 2));
}

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 * @heap: heap_t pointer
 * Return: generic pointer to data that was stored in heap's root
 */
void *heap_extract(heap_t *heap)
{C99(
	node_t *a[heap->size], *last;
	void *data = heap->root->data;

	if (!heap || heap->size != heap_to_array((node_t **)&a, heap->root, 0))
		return (NULL);

	if (heap->root == (last = a[heap->size - 1]))
		heap->root = NULL;
	else
	{
		heap->root->data = last->data;
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
		heapify(heap->root, heap->data_cmp);
	}
	free(last);
	--heap->size;
DBG(PRINT_NODE_ARRAY((const node_t **)&a, heap->size));
DBG(printf("heap->size now %ld\n\n", heap->size));
	return (data);
);}
