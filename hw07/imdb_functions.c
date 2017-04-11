/* imdb_functions.c
   Name:Tianming Xu
   Resources used (websites / peers / etc):HackerRank.com(merge sort algorithms)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "imdb_functions.h"
#include "types.h"//need this to specify the cast_member and movies type

#define STRING_SIZE  200
#define LEN "199"

// copy the given string into a newly-malloc'd buffer
char* malloc_string(char* str)
{
  char* new = malloc(sizeof(char) * (strlen(str)+1));
  strcpy(new, str);
  return new;
}

// is the given string composed entirely of dashes?
bool all_dashes(char* str)
{
  while(*str)
  {
    if(*str++ != '-')
    {
      return false;
    }
  }
  return true;
}

// Reads in a cast member from the given file
// preconditions: the file is open and at a line where a cast member begins
//                member points to a valid cast_member struct
//                all_movies is a map of all known movies
// postconditions: if a cast_member can successfully be read from the file,
//                 *member is filled in. Any new movies found while reading
//                 the cast member are added to all_movies, and SUCCESS is returned
//                 Otherwise, if the end of the list of members is reached,
//                 END_OF_LIST is returned. Otherwise, FAILURE is returned.
read_result read_cast_member(FILE* file, cast_member* member, map all_movies)
{
  char buf[STRING_SIZE];
  if(fscanf(file, "%" LEN "[^\t\n]", buf) != 1) return FAILURE;

  if(all_dashes(buf)) return END_OF_LIST;

  // WRITE CODE HERE
  // At this point, `buf` contains the name of the cast member, and you can
  // fill in the two data fields of *member.
  member->name = malloc(sizeof(char) * STRING_SIZE);//remember to free it
  strcpy(member->name, buf);//allocate the memory and copy the content of buf to that memory, then let name to point to that piece of memory
  member->movies = llist_new();

  while(fscanf(file, "%*[\t]%" LEN "[^\n]", buf) == 1)
  {
    getc(file); // eat the newline
    
    // cut it off at the first instance of 2 spaces
    char* spaces = strstr(buf, "  ");
    if(spaces)
    {
      *spaces = '\0'; // cut off the string here
    }

    // WRITE CODE HERE
    // At this point, `buf` contains the name of the movie. You should:
    //   1. Look up the movie in all_movies to see if it already exists.
    //   2. If not, create (malloc) a new movie object and add it to the map.
    //   3. Update the movie to include the cast member.
    //   4. Update the cast member to include the movie.

    char* target = buf;
    //if the movie exists in the list
    if(map_contains(all_movies, target)){
      //find the movie needed to be changed
      movie* changed = map_get(all_movies, target);
      //update the data
      array_add(changed -> cast, member);
      llist_add(member->movies, changed);
    }
    else{
      movie* new_movie = malloc(sizeof(movie));
      //set up the name for the new_movie
      new_movie -> name = malloc(sizeof(char) * STRING_SIZE);
      strcpy(new_movie -> name, target);
      //set up the cast list for new_movie
      new_movie -> cast = array_new();
      //add new_movie to the map
      map_put(all_movies, target, new_movie);
      //update data
      //printf("old size: %d\n", array_size(new_movie->cast)
      array_add(new_movie -> cast, member);
      llist_add(member->movies, new_movie);
    }
    
  }

  return SUCCESS;
}

// Merges two sorted arrays. Runs in time linear to the length of the two input arrays.
// preconditions: src1 and src2 are two valid arrays.
//                src1 and src2 are both in sorted order
// postconditions: returns a fresh array containing all the elements of src1 and src2
//                 in sorted order
// Note: You are responsible for freeing the returned array.
array merge_arrays(array src1, array src2)
{
  int len1 = array_size(src1);
  int len2 = array_size(src2);

  /*wrong defined new
  array new = malloc(sizeof(array_record));
  arr-> mem = malloc (sizeof(cast_member*) * (len1 + len2));
  arr->size = len1 + len2;
  arr->num_elements = 0;
  */
  array new = array_new();
  int l1 = 0;
  int r1 = len1-1;
  int l2 = 0;
  int r2 = len2-1; // always do some stupid things, why use len2,which access out of index
   //if any of the array is empty, just return the other array.
  if(len1 == 0){
    return src2;
  }
  if(len2 == 0){
    return src1;
  }
  while(l1 <= r1 && l2 <= r2){
    int result = strcmp(array_get(src1,l1)->name,array_get(src2,l2)->name);
    //if the name of the cast member in src1 is larger than or equal to that in src2, store the cast member of src2 in new array first
    if( result >= 0) {
      array_add(new,array_get(src2,l2));
      l2++;
    }
    //else store cast member in src1
    else{
      array_add(new,array_get(src1,l1));
      l1++;
    }
  }
  printf("I know I succeed pass\n");
  //deal with the elements left in these two arrays
  while(l1 <= r1){
    array_add(new,array_get(src1,l1));
    l1++;
  }
  while(l2 <= r2){
    array_add(new,array_get(src2,l2));
    l2++;
  }
  
  return new; 
}

// Finds a cast member in a sorted array of cast members
// preconditions: cast is a valid, sorted array of cast members
//                name is a valid string
// postconditions: If the cast member can be found, returns a pointer to the member
//                 Otherwise, returns NULL.
cast_member* find_cast_member(array cast, char* name)
{
  int len = array_size(cast);
  int low = 0;
  int high = len-1;
  int mid;
  //printf("this time len is :%d\n", len);
  while(low <= high){
    mid = low + (high - low)/2;
    int result = strcmp(array_get(cast,mid)->name,name);
    if(result == 0)
      return array_get(cast, mid);
    else if(result < 0){
      //name is in right side of cast
      low = mid +1;
    }
    else{
      //name is in left side of cast
      high = mid -1;
    }
    //printf("this time mid is :%d\n", mid);
  }
  
  return NULL;
}
