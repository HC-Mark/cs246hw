/* rand_array.c

   Defines a function that fills in a two-dimensional array with random
   values in a given range, as an example both of "returning" a two-
   dimensional array and of randomness.
*/

#include <stdlib.h> // rand comes from here

#include "rand_array.h"

// Fills in NxM array `mat` with random values, between `lo` (inclusive)
// and `hi` (exclusive)
void rand_array(int n, int m, int mat[n][m], int lo, int hi)
// Note the array indices in the declaration for mat can mention
// previous parameters n and m. C does not check that the input array
// has these dimensions, but including them (in particular, including
// the column dimnesion) tells the compiler where in memory to look
// for individual elements. In a multi-dimensional array, do *not*
// leave array sizes out!
{
  for(int row = 0; row < n; row++)
  {
    for(int col = 0; col < n; col++)
    {
      int rand_int = rand(); // rand_int ranges from 0 to RAND_MAX
                             // On my machine, RAND_MAX is 2^31 - 1
      int range = hi - lo; // number of possible random numbers

      // converts rand_int into a number in the range [0..range)
      int in_range = rand_int % range;

      // translates the random number range to start at `lo`
      int between_lo_and_hi = in_range + lo;
      
      mat[row][col] = between_lo_and_hi;
    }
  }
}
