#include "huffman.h"

/**
 * huffman_extract_and_insert - description
 * @priority_queue: heap_t
 * Return: int
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	node_t *nl = heap_extract(priority_queue);
	node_t *nr = heap_extract(priority_queue);
	symbol_t *sl = (symbol_t *)nl->data;
	symbol_t *sr = (symbol_t *)nr->data;
	size_t freq = sl->freq + sr->freq;
	symbol_t *s = symbol_create(-1, freq);
	node_t *n = nl->parent = nr->parent = binary_tree_node(NULL, s);
	n->left = nl;
	n->right = nr;
	return (heap_insert(priority_queue, n) ? 1 : 0);
}
