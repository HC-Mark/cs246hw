/* llist.c

   Implementation of an singly linked list sequence
*/

#include <stdlib.h>

#include "llist.h"
#include "llist_node.h"

typedef struct llist_record {
  llist_node* head;
  llist_node* tail;
  int size;  // number of nodes in the llist
} llist_record;

// return an empty llist. Make sure to call llist_free when you're done
// with it.
llist llist_new()
{
  llist l = malloc(sizeof(llist_record));
  l->head = NULL;
  l->tail = NULL;
  l->size = 0;
  return l;
}

// returns the number of elements in the llist. Runs in constant time.
int llist_size(llist l)
{
  return l->size;
}

// Adds a new element to the end of the list. Runs in constant time.
void llist_add(llist l, movie* elt)
{
  if(l->tail)
  {
    llist_node_insert_after(l->tail, elt);
    l->tail = l->tail->next;
  }
  else
  {
    l->head = l->tail = llist_node_new(elt, NULL);
  }
  l->size++;
}

// frees an llist. Takes O(size(l)) steps.
void llist_free(llist l)
{
  llist_node_free(l->head);
  free(l);
}

llist_node* llist_head(llist l)
{
  return l->head;
}
