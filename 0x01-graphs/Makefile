SHELL	= bash

ifdef NIX_CC_FOR_TARGET
CC	= $$NIX_CC_FOR_TARGET/bin/gcc
else
CC	= gcc
endif

CFLAGS	= -Wall \
	  -Werror \
	  -Wextra \
	  -pedantic \
	  -ggdb3

.PHONY: test clean again fullgrind check_version

% :
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@.out $^

0 : 0-main.c 0-graph_create.c
1 : 1-main.c 1-graph_add_vertex.c 0-graph_create.c graph_display.c 3-graph_delete.c
2 : 2-main.c 2-graph_add_edge.c 1-graph_add_vertex.c 0-graph_create.c graph_display.c 3-graph_delete.c
3 : 3-main.c 3-graph_delete.c 0-graph_create.c 1-graph_add_vertex.c 2-graph_add_edge.c graph_display.c
4 : 4-main.c 4-depth_first_traverse.c 3-graph_delete.c 0-graph_create.c 1-graph_add_vertex.c 2-graph_add_edge.c graph_display.c
5 : 5-main.c 5-breadth_first_traverse.c 3-graph_delete.c 0-graph_create.c 1-graph_add_vertex.c 2-graph_add_edge.c graph_display.c


RED = \033[0;31m
BLUE = \033[0;34m
NC  = \033[0m

TARGET ?= 5
test: $(TARGET)
	@echo -en "${BLUE}"
	@$(CC) --version | head -1
	@echo -en "${NC}"
	@timeout --signal=KILL 0.005s ./$<*.out

clean:
	@$(RM) *.o *.so

again: clean 5

fullgrind: again
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./0.out

gcc_version:
	$(CC) --version

pycheck :
	@echo $(PYTHONLIB)
