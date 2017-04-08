/* imdb_functions.h

   Helper functions to implement the interactive IMDB viewer.
*/

#ifndef IMDB_FUNCTIONS_H_
#define IMDB_FUNCTIONS_H_

#include "abstract_types.h"

#include "array.h"
#include "map.h"

// reading in a cast member can have one of three results:
typedef enum read_result {
  FAILURE,      // the cast member entry is somehow malformed
  SUCCESS,      // cast member has been read in
  END_OF_LIST   // we have reached the end of the list of cast members in the file
} read_result;

// Reads in a cast member from the given file
// preconditions: the file is open and at a line where a cast member begins
//                member points to a valid cast_member struct
//                all_movies is a map of all known movies
// postconditions: if a cast_member can successfully be read from the file,
//                 *member is filled in. Any new movies found while reading
//                 the cast member are added to all_movies, and SUCCESS is returned
//                 Otherwise, if the end of the list of members is reached,
//                 END_OF_LIST is returned. Otherwise, FAILURE is returned.
read_result read_cast_member(FILE* file, cast_member* member, map all_movies);

// Merges two sorted arrays. Runs in time linear to the length of the two input arrays.
// preconditions: src1 and src2 are two valid arrays.
//                src1 and src2 are both in sorted order
// postconditions: returns a fresh array containing all the elements of src1 and src2
//                 in sorted order
// Note: You are responsible for freeing the returned array.
array merge_arrays(array src1, array src2);

// Finds a cast member in a sorted array of cast members. Runs in time logarithmic to
// the length of the array.
// preconditions: cast is a valid, sorted array of cast members
//                name is a valid string
// postconditions: If the cast member can be found, returns a pointer to the member
//                 Otherwise, returns NULL.
cast_member* find_cast_member(array cast, char* name);

#endif
