/* llist.h

   Declarations for an abstract sequence type backed by a singly linked list.
*/

#ifndef LLIST_H_
#define LLIST_H_

#include "abstract_types.h"
#include "llist_node.h"

// An abstract sequence type of movie*s.
typedef struct llist_record* llist;

// return an empty llist. Make sure to call llist_free when you're done
// with it.
llist llist_new();

// returns the number of elements in the llist. Runs in constant time.
int llist_size(llist l);

// Adds a new element to the end of the list. Runs in constant time.
// Does *not* copy the movie.
void llist_add(llist l, movie* elt);

// frees an llist. Takes O(size(l)) steps.
void llist_free(llist l);

// access the underlying head llist_node. Useful for iteration.
llist_node* llist_head(llist l);

#endif
