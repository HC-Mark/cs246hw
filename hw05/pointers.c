/* pointers.c

   Name:
   Resources used (websites, books other than our texts, peers):

*/
#include <stdio.h>
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
   in non-decreasing order. */
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
  int sum = 0;
  for( p ;p < q ; p ++){
    sum += *p;
  }
  return sum;
}

/* Check whether `n` array elements, starting at `start` and
   incrementing be `step`, all match, according to the rules
   of Tic Tac Toe. Returns X or O if there is a winner, or
   BLANK otherwise. */
int check_line(int* start, int step, int n)
{
  int player = *start;
  for(int i = 0; i < n; i++){
    int temp = * (start + step * i);
    if (player == temp)
      continue;
    else
      return 0;
  }
  return player;
}

/* Check for a winner of Tic Tac Toe. Precondition:
   board points to a region of memory containing at least
   n^2 ints. Returns the winner of Tic Tac Toe, or BLANK
   if there is no winner. */
int tic_tac_toe_winner(int n, int* board)
{
  //check row
  for(int i = 0; i < n; i++){
    int* start = board + n * i;
    int result = check_line(start, 1, n);

    if(result != 0)
      return result;
    else
      continue;
  }

  //check for column
    for(int i = 0; i < n; i++){
    int* start = board + i;
    int result = check_line(start, n, n);

    if(result != 0)
      return result;
    else
      continue;
  }

    //check for major diagnoal
    int* start = board;
    int result = check_line(start, n+1, n);
    if(result != 0)
      return result;

    start = board + (n-1);
    result = check_line(start, n-1, n);
    if(result != 0)
      return result;
    
  return 0;
}

/*
#define BLANK 0
#define X     1
#define O     2

int main() {
  //test for partial sum
  int test3[] = {4, 3, 8, 2, 7};
  int result = partial_sum(test3, test3+4);
  if ( result == 17){
    printf("partial sum test Pass\n");
  }
  
  //test for minisort
  int x = 4, y = 1, z = 5;
  minisort(&x, &y, &z);
  if(x == 1 && y == 4 && z == 5){
    printf("minisort test Pass\n");
  }

  //test for check-line
  int xs[] = {X, BLANK, X, O, X, BLANK};
  if(check_line(xs, 2, 3) == X)
    printf("check-line test1 pass\n");
  if(check_line(xs, 1, 3)== BLANK)
    printf("check_line test2 pass\n");

  //test for tic tac toe winner
  int board1[3][3] = { {O, O, X},
		       {X, X, O},
		       {X, O, X} };
  if(tic_tac_toe_winner(3, (int*)board1) == X)
    printf("winner test1 pass\n");

  int board2[2][2] = { {BLANK, O},
		       {X, BLANK} };
  if(tic_tac_toe_winner(2, (int*)board2) == BLANK)
  if(tic_tac_toe_winner(3, (int*)board1) == X)
    printf("winner test2 pass\n");
  return 0;
}
*/
