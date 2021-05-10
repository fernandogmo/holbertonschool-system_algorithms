#include "huffman.h"
#include <stdio.h>

/**
 * huffman_tree - description
 * @data: data
 * @freq: freq
 * @size: size
 * Return: int
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *q = huffman_priority_queue(data, freq, size);
	while (q->size > 1)
		huffman_extract_and_insert(q);
	return (q->root->data);
}
