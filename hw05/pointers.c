/* pointers.c

   Name:Tianming Xu
   Resources used (websites, books other than our texts, peers):Elieen

*/

#include <stdlib.h>

#include "pointers.h"

/* Returns whether or not the region pointed to by p1 (of length n)
   overlaps with the region pointed to by p2 (of length m). Do not
   assume that p2 is greater than p1. */
bool overlaps(int n, int* p1, int m, int* p2)
{
  if( n == 0 || m == 0)
    return false;

  for(int i =0; i < n; i++){
    for(int j = 0; j < m; j++){
      if( (p1+i) == (p2 + j))
	return true;
    }
  }
  
  return false;
}

/* Changes the value in *a, *b, and *c so that *a, *b, and *c are
   in non-decreasing (increasing and contain equal terms) order. */
void minisort(int* a, int* b, int* c)
{
  int high , mid , low ;//helper variable
	if(*a > *b && *a > *c){
	  high = *a;
	  if(*b > *c){
	  	*a = *c;
		*c = high;
		return;
	  }
	  else{
	  	*a = *b;
		*b = *c;
		*c = high;
		return;
	  }
	}
	else if (*a > *b || *a > *c){
		mid = *a;
		if(*b > *c){
			*a = *c;
			*c = *b;
			*b = mid;
			return;
		}
		else{
			*a = *b;
			*b = mid;
			return;
		}
	}
	else{
		if(*b > *c){
			high = *b;
			*b = *c;
			*c = high;
		}
		else
			return;
	}
  
  
}

/* Computes the sum of the ints that sit in memory between p
   (inclusive) and q (exclusive). You may assume that q comes
   after p -- that is, q >= p. */
int partial_sum(int* p, int* q)
{
  /* WRITE THIS FUNCTION */
  return 0;
}

/* Check whether `n` array elements, starting at `start` and
   incrementing be `step`, all match, according to the rules
   of Tic Tac Toe. Returns X or O if there is a winner, or
   BLANK otherwise. */
int check_line(int* start, int step, int n)
{
  /* WRITE THIS FUNCTION */
  return 0;
}

/* Check for a winner of Tic Tac Toe. Precondition:
   board points to a region of memory containing at least
   n^2 ints. Returns the winner of Tic Tac Toe, or BLANK
   if there is no winner. */
int tic_tac_toe_winner(int n, int* board)
{
  /* WRITE THIS FUNCTION */
  return 0;
}
