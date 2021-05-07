#include <stdio.h>
#include "heap.h"


void print_node_array(const node_t **array, size_t size)
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
