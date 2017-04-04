/* dlist.h
   Declarations for an abstract sequence type backed by a doubly linked list.
*/

#ifndef DLIST_H_
#define DLIST_H_
#include "dlist_node.h"
// An abstract type for sequences
typedef struct dlist_record* dlist;

// return an empty dlist. Make sure to call dlist_free when you're done
// with it.
dlist dlist_new();

// returns the number of elements in the dlist. Runs in constant time.
int dlist_size(dlist l);

// appends a new element to the beginning of the dlist. Runs in constant time.
void dlist_push(dlist l, int elt);

// removes and returns the first element in the dlist. Runs in constant time.
// precondition: there is at least one element in the dlist.
int dlist_pop(dlist l);

// returns the first element in the dlist, without changing the dlist.
// Runs in constant time.
// precondition: there is at least one element in the dlist.
int dlist_peek(dlist l);

// appends a new element to the end of the dlist. Runs in constant time.
void dlist_push_end(dlist l, int elt);

// removes and returns the last element in the dlist. Runs in constant time.
// precondition: there is at least one element in the dlist.
int dlist_pop_end(dlist l);

// returns the last element in the dlist, without changing the dlist.
// Runs in constant time.
// precondition: there is at least one element in the dlist.
int dlist_peek_end(dlist l);

// adds a new element into the dlist, after n existing elements.
// Traverses from whichever side of the dlist is closer.
// precondition: the list has at least n elements
void dlist_insert(dlist l, int n, int elt);

// retrieves the nth element of the dlist.
// Traverses from whichever side of the dlist is closer.
// precondition: the list has at least (n+1) elements
int dlist_get(dlist l, int n);

// sets the nth element of the dlist to a new value.
// Traverses from whichever side of the dlist is closer.
// precondition: the list has at least (n+1) elements
// postcondition: returns the old value of the element that was set
int dlist_set(dlist l, int n, int new_elt);

// removes the nth element of the dlist.
// Traverses from whichever side of the dlist is closer.
// precondition: the list has at least (n+1) elements
// postcondition: returns the removed element
int dlist_remove(dlist l, int n);

// frees an dlist. Takes O(size(l)) steps.
void dlist_free(dlist l);

//two helper functions for checking
dlist_node* head(dlist l);

dlist_node* tail(dlist l);
#endif
