/* llist_node.h

   Prototypes for functions on a singly-linked list
*/

#ifndef LLIST_NODE_H_
#define LLIST_NODE_H_

typedef struct llist_node {
  movie* data;
  struct llist_node* next; // pointer to next node
} llist_node;

// create (i.e., malloc) a new node
llist_node* llist_node_new(movie* data, llist_node* next);

// insert a new node after the given one
// Precondition: Supplied node is not NULL.
void llist_node_insert_after(llist_node* n, movie* data);

// free an entire linked list. The list might be empty.
void llist_node_free(llist_node* head);

#endif
