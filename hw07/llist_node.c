/* llist_node.c

   A singly-linked list implementation
*/

#include <stdlib.h>

#include "abstract_types.h"
#include "llist_node.h"

// create (i.e., malloc) a new node
llist_node* llist_node_new(movie* data, llist_node* next)
{
  llist_node* n = malloc(sizeof(llist_node));
  n->data = data;
  n->next = next;
  return n;
}

// insert a new node after the given one
// Precondition: Supplied node is not NULL.
void llist_node_insert_after(llist_node* n, movie* data)
{
  n->next = llist_node_new(data, n->next);
}

// free an entire linked list. The list might be empty.
void llist_node_free(llist_node* head)
{
  llist_node* cur = head;
  while(cur)
  {
    head = cur;
    cur = cur->next;
    free(head);
  }
}

