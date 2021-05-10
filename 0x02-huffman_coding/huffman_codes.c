#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_leaf_data - description
 * @buffer: char buffer for writing huffman code for leaf
 * @node: node_t root of huffman subtree
 */
void print_leaf_data(char *buffer, node_t *node)
{
	if (!node) return;

	if (node->left)
	{
		char buf[256] = {0};
		char *fmt = (buffer) ? "%s0" : "0";
		sprintf((char *)&buf, fmt, buffer);
		print_leaf_data((char *)&buf, node->left);
	}
	if (node->right)
	{
		char buf[256] = {0};
		char *fmt = (buffer) ? "%s1" : "1";
		sprintf((char *)&buf, fmt, buffer);
		print_leaf_data((char *)&buf, node->right);
	}
	if (!node->left && !node->right)
	{
		char c = ((symbol_t *)node->data)->data;
		printf("%c: %s\n", c, buffer);
	}
}

/**
 * free_symbol_node - description
 * @data: generic data
 */
void free_symbol_node(void *data)
{
	if (data)
	{
		node_t *nested = (node_t *)data;
		symbol_t *symbol = (symbol_t *)nested->data;
		free(symbol);
		free(nested);
	}
}
/**
 * huffman_codes - for (a/6),(b/11),(c/12),(d/13),(e/16),(f/36), prints:
 * * f: 0
 * * c: 100
 * * d: 101
 * * e: 110
 * * a: 1110
 * * b: 1111
 * @data: data
 * @freq: freq
 * @size: size
 * Return: int 1 on success, 0 on failure
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
	node_t *root = huffman_tree(data, freq, size);
	if (!root) return (0);
	print_leaf_data(NULL, root);
	free_binary_tree_node(root, free_symbol_node);
	return (1);
}
