#include "huffman.h"

/**
 * sym_cmp - compares two symbols
 * @p1: first pointer
 * @p2: second pointer
 * Return: difference between the two chars
 */
int sym_cmp(void *p1, void *p2)
{
	symbol_t *s1 = ((node_t *)p1)->data;
	symbol_t *s2 = ((node_t *)p2)->data;
	return (s1->freq - s2->freq);
}

/**
 * huffman_priority_queue - allocates a priority queue for
 * *			    the Huffman coding algorithm
 * @data: char array
 * @freq: freq array
 * @size: size_t length of @data and @freq
 * Return: heap_t pointer to allocated priority queue
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{C99(
	if (!data || !freq || !size) return (NULL);
	heap_t *q = heap_create(sym_cmp);
	if (!q) return (NULL);
	size_t i;
	for (i = 0; i < size; ++i)
	{
		symbol_t *s = symbol_create(data[i], freq[i]);
		if (heap_insert(q, binary_tree_node(NULL, s)) == NULL)
			return (NULL);
	}
	return (q);
);}
