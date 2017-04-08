/* array.h

   Prototypes for functions defining an abstract array type
*/

#ifndef ARRAY_H_
#define ARRAY_H_

#include "abstract_types.h"

// The array type stores pointers to cast_members.
typedef struct array_record* array;

// create a new, empty array, with an initial size of 10 but no elements
array array_new();

// add a new element to the end of the array. Does *not* copy the cast_member.
void array_add(array arr, cast_member* new_elt);

// access an element in the array. Returns -1 if the index is out of range.
cast_member* array_get(array arr, int index);

// change an element in the array. grows the array to accommodate, if necessary.
// Does *not* copy the cast_member.
void array_set(array arr, int index, cast_member* new_val);

// returns the number of elements in an array
int array_size(array arr);

// release the memory used for this array
void array_free(array arr);

// adds an element at the given (non-negative) index, enlarging the array
// and shifting elements to the right to make it fit.
// Does *not* copy the cast_member.
void array_add_at(array arr, int index, cast_member* new_elt);

#endif
