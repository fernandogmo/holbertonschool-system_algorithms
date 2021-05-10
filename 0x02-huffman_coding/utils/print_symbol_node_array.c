#include <stdio.h>
#include "huffman.h"

/**
 * symbol_print - Prints a symbol structure stored in a nested node
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 * Return: Number of bytes written in buffer
 */
static int _symbol_print(char *buffer, void *data)
{C99(
	node_t *nested = (binary_tree_node_t *)data;
	symbol_t *symbol = (symbol_t *)nested->data;
	char c = symbol->data;
	if (c == -1) c = '$';
	int length = sprintf(buffer, "(%c/%lu)", c, symbol->freq);
	return (length);
);}

/**
 * print_symbol_node_array - description
 * @array: array of nested symbol_t node_t nodes
 * @size: size_t length of @array
 */
void print_symbol_node_array(const node_t **array, size_t size)
{
	char buf[256] = {0};
	size_t len = 0, i;
	for (i = 0; array && i < size; ++i)
	{
		len += _symbol_print((char *)&buf[len + i], (void *)array[i]->data);
		buf[len + i] = ',';
	}
	buf[len + i - 1] = '\0';
	printf("%s\n", (char *)&buf);
}
