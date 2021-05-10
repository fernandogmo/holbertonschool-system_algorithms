#include <stdlib.h>
#include <string.h>

#include "huffman.h"

/**
 * symbol_create - allocates a symbol_t with a char and its frequency
 * @data: ascii-sized character
 * @freq: size_t frequency of @data in corpus
 * Return: pointer to new symbol_t or NULL on failure
 */
symbol_t *symbol_create(char data, size_t freq)
{C99(
	symbol_t src = (symbol_t){data, freq};
	symbol_t *dst = calloc(1, sizeof(*dst));
	if (!dst || !data) { free(dst); return (NULL);}
	return (memcpy(dst, &src, sizeof(src)));
);}
