SHELL	= bash

ifdef NIX_CC_FOR_TARGET
CC	= $$NIX_CC_FOR_TARGET/bin/gcc
else
CC	= gcc
endif

CFLAGS	= -ggdb3 \
	  -Wall \
	  -Werror \
	  -Wextra \
	  -pedantic

.PHONY: test clean again fullgrind check_version

% :
	@$(CC) $(CFLAGS) $(LDFLAGS) -Iheap/ -I. -o $@.out $^

ex_0 : ex_0.c
ex_1 : ex_1.c
ex_2 : ex_2.c
0 : 0-main.c heap/*.c utils/*.c
1 : 1-main.c heap/*.c utils/*.c
2 : 2-main.c heap/*.c utils/*.c
3 : 3-main.c heap/*.c utils/*.c
4 : 4-main.c heap/*.c utils/*.c
5 : 5-main.c heap/*.c symbol.c
6 : 6-main.c heap/*.c symbol.c utils/*.c huffman_priority_queue.c
7 : 7-main.c heap/*.c symbol.c utils/*.c hhuffman_priority_queue.c huffman_extract_and_insert.c
8 : 8-main.c heap/*.c symbol.c utils/*.c hhuffman_priority_queue.c huffman_extract_and_insert.c huffman_tree.c
9 : 9-main.c heap/*.c symbol.c utils/*.c hhuffman_priority_queue.c huffman_extract_and_insert.c huffman_tree.c huffman_codes.c

RED = \033[0;31m
BLUE = \033[0;34m
NC  = \033[0m

TARGET ?= 5
test: $(TARGET)
	@echo -en "${BLUE}"
	@$(CC) --version | head -1
	@echo -en "${NC}"
	timeout --signal=KILL 0.5s ./$<.out

clean:
	@$(RM) *.o *.so *.out

again: clean test

fullgrind: again
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./0.out

gcc_version:
	$(CC) --version

pycheck :
	@echo $(PYTHONLIB)
