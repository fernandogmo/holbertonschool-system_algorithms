#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * huffman_tree - description
 * @data: data
 * @freq: freq
 * @size: size
 * Return: int
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{C99(
	heap_t *q = huffman_priority_queue(data, freq, size);
	while (q && q->size > 1)
		huffman_extract_and_insert(q);
	node_t *huff = q->root->data;
	free(q->root);
	free(q);
	return (huff);
);}
