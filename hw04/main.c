/* main.c

   Name:Tianming Xu
*/

#include "matrix.h"
#include <time.h>
#include <stdio.h>
#include "rand_array.h"

int main()
{
  int test1[30][30];
  int result1 [30][30];
  clock_t start,end;
  long total = 0;
  rand_array(30,30,test1,1,10);
  start = clock();

  matrix_pow(30,test1,50,result1);
  //matrix_pow_rec(30,test1,50,result1);

  end = clock();
  total = end - start;
  printf("Total time taken by exponentiation: %lu\n", total);

  
  return 0;
}
