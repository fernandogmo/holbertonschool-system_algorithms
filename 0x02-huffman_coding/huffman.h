#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stddef.h>

#include "heap.h"

#define RED	"\033[0;31m"
#define BLUE	"\033[0;34m"
#define NC	"\033[0m"

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;

symbol_t *symbol_create(char data, size_t freq);
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
int huffman_extract_and_insert(heap_t *priority_queue);
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);
int huffman_codes(char *data, size_t *freq, size_t size);


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvariadic-macros"

#ifndef C99
#define C99(...) \
do { \
_Pragma("GCC diagnostic push")\
_Pragma("GCC diagnostic ignored \"-Wpedantic\"")\
	__VA_ARGS__ \
_Pragma("GCC diagnostic pop")\
} while (0)
#endif /* C99 */

#pragma GCC diagnostic pop

#endif /* HUFFMAN_H */
