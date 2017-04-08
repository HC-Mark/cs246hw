/* map.h

   Declarations for an abstract type mapping strings to movie*s.
*/

#ifndef MAP_H_
#define MAP_H_

#include <stdbool.h>

#include "abstract_types.h"

// An abstract type for maps from strings to movie*s.
typedef struct map_record* map;

// Create an empty map. Make sure to call map_free when you're done with it.
map map_new();

// Returns the number of elements in the map.
int map_size(map m);

// Returns whether the given string exists in the map.
bool map_contains(map m, char* s);

// Store the keys, in order, from the map into the given array. Note that
// the array's size must match the size of the map.
void map_get_keys(map m, char* keys[map_size(m)]);

// A type of key/value pairs
typedef struct map_entry {
  char* key;
  movie* value;
} map_entry;

// Store the entries, in order, from the map into the given array. Note that
// the array's size must match the size of the map.
void map_get_entries(map m, map_entry entries[map_size(m)]);

// Get the key associated with the given key, or returns NULL if the key
// is not present
movie* map_get(map m, char* key);

// Put an entry into the map. Returns the old value associated with this
// key if there was one; otherwise, returns NULL.
// This *does* copy the string into memory managed by the map, but does
// *not* copy the movie, which you will have to free yourself.
movie* map_put(map m, char* key, movie* new_val);

// Free a map, including all the keys in it. Does not free any movies.
void map_free(map m);

#endif
