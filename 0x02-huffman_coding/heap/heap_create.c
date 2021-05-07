#include "heap.h"
#include <stdlib.h>

/**
 * heap_create - allocates a new heap_t heap data structure profile
 * @data_cmp: pointer to a comparison function
 * Return: pointer to the created heap_t structure, or NULL on failure
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *h = calloc(1, sizeof(heap_t));
	if (h) h->data_cmp = data_cmp;
	return (h);
}
