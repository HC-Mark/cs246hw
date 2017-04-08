/* bigarray.c

   Implementation of a resizable array, for lab 6
*/

#include <stdlib.h>

#include "array.h"

#define INITIAL_SIZE 10

typedef struct array_record {
  cast_member** mem; // an array of pointers to cast_members
  int size;
  int num_elements;
} array_record;

// internal helper function:
// double the size of the memory storage backing an array
void grow(array arr)
{
  arr->size *= 2;
  cast_member** new_mem = malloc(sizeof(cast_member*) * arr->size);
  for(int i = 0; i < arr->num_elements; i++)
  {
    new_mem[i] = arr->mem[i];
  }
  free(arr->mem);
  arr->mem = new_mem;
}

// internal helper function
// return the greater of two numbers
int max(int a, int b)
{
  return a > b ? a : b;
}

// create a new, empty array, with an initial size of 10 but no elements
array array_new()
{
  array arr = malloc(sizeof(array_record));
  arr->mem = malloc(sizeof(cast_member*) * INITIAL_SIZE);
  arr->size = INITIAL_SIZE;
  arr->num_elements = 0;
  return arr;
}

// add a new element to the end of the array
void array_add(array arr, cast_member* new_elt)
{
  array_add_at(arr, arr->num_elements, new_elt);
}

// access an element in the array. Returns NULL if the index is out of range.
cast_member* array_get(array arr, int index)
{
  if(index >= 0 && index < arr->num_elements)
  {
    return arr->mem[index];
  }
  else
  {
    return NULL;
  }
}

// change an element in the array.
void array_set(array arr, int index, cast_member* new_val)
{
  if(index >= arr->num_elements)
  {
    array_add_at(arr, index, new_val);
  }
  else
  {
    arr->mem[index] = new_val;
  }
}

// returns the number of elements in an array
int array_size(array arr)
{
  return arr->num_elements;
}

// release the memory used for this array
void array_free(array arr)
{
  free(arr->mem);
  free(arr);
}

// adds an element at the given (non-negative) index, enlarging the array
// and shifting elements to the right to make it fit
void array_add_at(array arr, int index, cast_member* new_elt)
{
  while(arr->num_elements == arr->size || index >= arr->size)  // we will need to grow
  {
    grow(arr);
  }

  if(index < arr->size)  // do we have the memory already?
  {
    // move any necessary elements out of the way
    for(int i = arr->num_elements; i > index; i--)
    {
      arr->mem[i] = arr->mem[i-1];
    }

    arr->mem[index] = new_elt;
  }

  arr->num_elements = max(index + 1, arr->num_elements + 1);
}
    
