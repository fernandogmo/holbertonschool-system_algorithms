#include <stdio.h>
#include "heap.h"

/**
 * print_int_node_array - description
 * @array: array of int node_t nodes
 * @size: size_t length of @array
 */
void print_int_node_array(const node_t **array, size_t size)
{
	size_t i;
	for (i = 0; array && i < size; ++i)
	{
		if (i > 0)
			printf(", ");
		printf("%d", *((int *)array[i]->data));
	}
	printf("\n");
}
