check_dlist: dlist.h dlist_node.h check_dlist.c
	gcc check_dlist.c dlist_node.c dlist.c -g -o check_dlist -lcheck

check_dlist_node: dlist_node.h check_dlist_node.c
	gcc check_dlist_node.c dlist_node.c -o check_node -lcheck
dlist: dlist.h dlist.c
	gcc dlist.c dlist_node.c -o dlist -std=c99

dlist_node: dlist_node.h dlist_node.c
	gcc dlist_node.c -o dlist_node -std=c99
