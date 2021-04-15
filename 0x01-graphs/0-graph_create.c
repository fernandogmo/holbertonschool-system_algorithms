#include <stdlib.h>
#include "graphs.h"

/**
 * graph_create - allocates zeroed graph_t
 * Return: pointer to zeroed graph_t on the heap, or NULL on failure
 */
graph_t *graph_create(void)
{
	return (calloc(1, sizeof(graph_t)));
}
