/* pointers.h

   Prototypes for the pointer functions.
*/

#include <stdbool.h>

/* Returns whether or not the region pointed to by p1 (of length n)
   overlaps with the region pointed to by p2 (of length m). Do not
   assume that p2 is greater than p1. */
bool overlaps(int n, int* p1, int m, int* p2);

/* Changes the value in *a, *b, and *c so that *a, *b, and *c are
   in non-decreasing order. */
void minisort(int* a, int* b, int* c);

/* Computes the sum of the ints that sit in memory between p
   (inclusive) and q (exclusive). You may assume that q comes
   after p -- that is, q >= p. */
int partial_sum(int* p, int* q);

// constants for Tic Tac Toe problems
#define BLANK 0
#define X     1
#define O     2

/* Check whether `n` array elements, starting at `start` and
   incrementing be `step`, all match, according to the rules
   of Tic Tac Toe. Returns X or O if there is a winner, or
   BLANK otherwise. */
int check_line(int* start, int step, int n);

/* Check for a winner of Tic Tac Toe. Precondition:
   board points to a region of memory containing at least
   n^2 ints. Returns the winner of Tic Tac Toe, or BLANK
   if there is no winner. */
int tic_tac_toe_winner(int n, int* board);

