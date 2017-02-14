/* matrix.h

   Prototypes for the matrix multiplication functions.
*/

#include <stdbool.h>

// checks to see if two NxM matrices are the same
bool eq_matrix(int n, int m, int mat1[n][m], int mat2[n][m]);

// prints an NxM matrix
void print_matrix(int n, int m, int mat[n][m]);

// fills in an NxN matrix with the identity matrix
void identity_mat(int n, int mat[n][n]);

// multiplies an NxM matrix by a scalar; stores the result in `result`
void scalar_mult(int scalar, int n, int m, int mat[n][m], int result[n][m]);

// multiplies an N1xM1 matrix by a M1xM2 matrix, storing the result in `result`
void matrix_mult(int n1, int m1, int mat1[n1][m1],
                 int m2, int mat2[m1][m2],
                 int result[n1][m2]);

void matrix_mult2(int n1, int m1, int mat1[n1][m1],
		int m2, int mat2[m1][m2],
		int* result);

// Exponentiate an NxN matrix. The result is stored in `result`.
void matrix_pow(int n, int mat[n][n], int power, int result[n][n]);

// Exponentiate an NxN matrix. The result is stored in `result`.
void matrix_pow_rec(int n, int mat[n][n], int power, int result[n][n]);
