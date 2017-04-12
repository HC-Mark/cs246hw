/* imdb.c
   Main program for interactive IMDB viewer.
   Name:
   Resources used (websites / peers / etc):
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "array.h"
#include "map.h"
#include "llist.h"
#include "types.h"

#include "imdb_functions.h"

// the IMDB files contain 239 header lines
#define HEADER_LINES 241 //it is not useful for the original actresses.list
#define STRING_SIZE  200
#define LEN "199"
//Discards all new_line sign in the string
void clean_new_line(char* str){
  char* track;
  for(track = str; track; track++){
    if(*track == '\n'){
      *track = 0;
      return;
    }
  }
}

// Reads in a file containing a list of cast members
// preconditions: all_movies exists and maps all movies encountered so far
// postconditions: If the file can be read successfully, returns an array
//                 of all cast members in the file, and updates all_movies
//                 to map all movies encountered. If there is an error reading
//                 the file, returns NULL.
// Note: You are responsible for freeing the returned array (if it's not NULL).
array read_cast_member_file(char* filename, map all_movies)
{
  FILE* file = fopen(filename, "r");
  if(!file)
  {
    printf("Cannot open file.");
    return NULL;
  }

  // skip header
  for(int i = 0; i < HEADER_LINES; i++)
  {
    skip_line(file);
  }

  array cast = array_new();

  while(!feof(file))
  {
    cast_member* member = malloc(sizeof(cast_member));
    read_result result = read_cast_member(file, member, all_movies);
    
    switch(result)
    {
    case SUCCESS:
      //printf("old size is %d\n",array_size(cast));
      array_add(cast, member);
      //printf("now size is %d\n",array_size(cast));
      // This is helpful for seeing progress as you're loading a file.
      if(array_size(cast) % 10 == 0)
	printf("Added cast member %s\n", member->name);
      
      break;
    case FAILURE:
      skip_line(file); // this makes sure we're always moving forward
      break;
      
    case END_OF_LIST:
      return cast;
    }
  }

  return cast; // shouldn't get here unless file is truncated
}

// Our main program loop.
// See King, p. 302, about argc and argv.
int main(int argc, char** argv)
{
  if(argc < 2)
  {
    printf("Usage: %s [cast_member lists]\n", argv[0]);
    return 1;
  }
	   
  map all_movies = map_new();
  array all_cast = array_new();

  // start i at one to skip program name
  // printf("argc is %d\n", argc);
  for(int i = 1; i < argc; i++)
  {
    array some_cast = read_cast_member_file(argv[i], all_movies);
    //printf("size of some cast is %d\n", array_size(some_cast));
    if(!some_cast)
    {
       // file reading failed, but read_cast_member_file alerted the user already
      continue;
    }

    // WRITE CODE HERE
    // At this point, some_cast has the cast members most recently read in,
    // and all_cast has all previous cast members.
    // You need to merge (with a call to merge_arrays) these two arrays, producing
    // a new all_cast that contains both.
    //printf("size of all cast is %d\n", array_size(all_cast));
    array new_all_cast = merge_arrays(all_cast, some_cast);
    //printf("size of all cast is %d\n", array_size(all_cast));
    //printf("size of some cast is %d\n", array_size(some_cast));
    //printf("size of new all cast is %d\n", array_size(new_all_cast));
    //array_free(all_cast);
    //array_free(some_cast);free here will get lost of the whole all_cast array
    
    all_cast = new_all_cast;//now, all_cast points to a new array merged by all_cast and some_cast
    
  }
  
  for(;;)
  {
    // WRITE CODE HERE
    // This is the main interactive loop, which you must write, as described
    // in the assignment.
    // When the user is done, this should `break`.
    char search[STRING_SIZE] = "";
    printf("Enter the actor/actress you want to search: \n");
    fgets(search,STRING_SIZE,stdin);//get an infinite loop if I use in this way -- but solve by some magic
    //if(search != "") I forget everything about string
    clean_new_line(search);
    if(stricmp(search,"") != 0){
      //printf("all cast is %d\n", array_size(all_cast));
      cast_member* want = find_cast_member(all_cast,search);
      if(want){
	printf("you want to find %s\n", want->name);//can we directly print name by using this?
	llist_node* head = llist_head(want->movies);
	int len = llist_size(want->movies);
	for(int i = 0; i < len; i++,head = head->next){
	  printf("%s is a cast of moive: %s\n", want->name, head->data->name);
	}
      }
      else{
	printf("Can't find that actor/actress you want, sorry, try again!\n");
      }
    }
    else{
      printf("Thank you for using this app!\n"); 
      break;
    }
    
    
  }

  // WRITE CODE HERE
  // Free all used memory before exiting.
  printf("the size of Map is %d\n", map_size(all_movies));
  printf("the size of all_cast is %d\n", array_size(all_cast));

  int len = array_size(all_cast);
  
  for(int i = 0; i < len; i++){
    cast_member* clean = array_get(all_cast,i);
    free(clean->name);
    llist_free(clean->movies);
    free(clean);
  }

  map_free(all_movies);
  //I learn that array_free will not touch the cast_member object
  // printf("the size of Map is %s\n", map_get(all_movies,"Todo x Sara (2014)")->name);
  array_free(all_cast);
  //printf("the test is %s\n", array_get(all_cast,0)->name);
  return 0;
}
