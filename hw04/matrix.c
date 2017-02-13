/* matrix.c

   Name:Tianming Xu
   Resources used (websites, books other than our texts, peers):

*/
#include "matrix.h"
#include <stdio.h>
#include <stdbool.h>

// checks to see if two NxM matrices are the same
bool eq_matrix(int n, int m, int mat1[n][m], int mat2[n][m])
{
  int i, j;
  for(i = 0; i < n; i++){
    for(j =0; j < m; j++){
      if(mat1[i][j] != mat2[i][j]){
	return false;
      }
    }
  }

  return true;
}

// prints an NxM matrix
void print_matrix(int n, int m, int mat[n][m])
{
  int i, j;
  for(i = 0; i< n; i++){
    for( j =0; j< m; j++){
      printf("%3d", mat[i][j]);
    }
    printf("\n");
  }
}

// fills in an NxN matrix with the identity matrix
void identity_mat(int n, int mat[n][n])
{
  int i;
  for(i =0; i < n; i++){
    mat[i][i] = 1;
  }
  
}

// multiplies an NxM matrix by a scalar; stores the result in `result`
void scalar_mult(int scalar, int n, int m, int mat[n][m], int result[n][m])
{
  int i, j;
  for(i =0; i < n; i++){
    for( j =0; j < n; j++){
      result[i][j] = mat[i][j] * scalar;
    }
  }

}

// multiplies an N1xM1 matrix by a M1xM2 matrix, storing the result in `result`
void matrix_mult(int n1, int m1, int mat1[n1][m1],
                 int m2, int mat2[m1][m2],
                 int result[n1][m2])
{
  
  int i, j, k;
  for( i = 0; i < n1; i++){
    for( j = 0; j < m2; j++){
      result[i][j] = 0;
      for(k = 0; k < m1; k++){
	result[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  
}

void matrix_mult2(int n1, int m1, int mat1[n1][m1],
                 int m2, int mat2[m1][m2],
                 int* result)
{
  int i, j, k;
  for( i = 0; i < n1; i++){
    for( j = 0; j < m2; j++){
      //result[i][j] = 0;
      for(k = 0; k < m1; k++){
	result[i*n1+j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  
}

// Exponentiate an NxN matrix. The result is stored in `result`.
void matrix_pow(int n, int mat[n][n], int power, int result[n][n])
{
  int temp [n][n];
  scalar_mult(1, n ,n ,mat, temp);
  while(power > 1){
    matrix_mult(n,n,temp,n,mat,result);
    scalar_mult(1, n ,n ,result, temp);
    
    power--;
  }
  
}

// Exponentiate an NxN matrix. The result is stored in `result`.
void matrix_pow_rec(int n, int mat[n][n], int power, int result[n][n])
{
  int i,j;
  int zero [n][n];
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      zero[i][j] = 0;
    }
  }
  
  
  int temp [n][n];
  scalar_mult(1,n,n,result,temp);
  //if mat is a zero matrix, return a zero matrix
  if(eq_matrix(n,n,mat,zero)){
    return ;
  }
  //return an identity matrix if the input power is 0
  if(power == 0){
    identity_mat(n,result);
    return ;
  }
  //if the input power is even number
  else if (power == 1 && eq_matrix(n,n,zero,temp)){
    int id [n][n];
      for(i = 0; i < n; i++){
	for(j =0; j <  n; j++){
	  id[i][j] = 0;
	}
      }
      identity_mat(n,id);
      matrix_mult(n,n,mat,n,id, result);
    return ;
  }
  //if the input power is odd number,except 1
  else if (power == 1){
    matrix_mult(n,n,temp,n,mat,result);
    return ;
  }
  else if ( power % 2 == 0){
    int buffer [n][n];
    for(i = 0; i < n; i++){
      for(j =0; j <  n; j++){
	buffer[i][j] = 0;
      }
    }
    matrix_mult(n,n,mat,n,mat,buffer);
    matrix_pow_rec(n,buffer,power/2,result);
  }
  else if ( power % 2 == 1){
    scalar_mult(1,n,n,mat,result);
    int buffer [n][n];
    for(i = 0; i < n; i++){
      for(j =0; j <  n; j++){
	buffer[i][j] = 0;
      }
    }
    matrix_mult(n,n,mat,n,mat,buffer);
    // print_matrix(n,n,buffer);
    matrix_pow_rec(n,buffer,(power-1)/2,result);
  }
  
}



int main(){
  int test1 [5][5] = {};
  int test2 [5][5] = {};
  int test3 [3][3] = {};
  int result1 [3][3] = {};
  int test4 [4][3] = {{1,5,8},
		    {2,1,7},
		    {10,4,8},
		    {46,0,4}};
  int test5 [3][3] = {{4,9,6},
		      {7,4,1},
		      {9,8,0}};
  int result2 [4][3] = {};
  int i, j;
  for( i = 0; i < 5 ; i++){
    for( j = 0; j < 5; j++){
      test1[i][j] = i + j;
      test2[i][j] = i + j;
    }
  }
  //test print_matrix
  // print_matrix(5,5,test1);
  // printf("\n");
  // print_matrix(5,5,test2);
  
  
  //test identity
  identity_mat(3,test3);
  scalar_mult(3,3,3,test3,test3);


  //test scalar
  // print_matrix(4,3,test4);
  //scalar_mult(2,4,3,test4,result2);
  //print_matrix(4,3,result2);



  
  //test multiple
  //matrix_mult(4,3,test4,3,test5,result2);
  // print_matrix(4,3,result2);
  //matrix_mult(3,3,test3,3,test3,result1);
  //print_matrix(3,3,result1);
  


  //test expon
  //print_matrix(3,3,test3);
  //matrix_pow(3, test3, 2, result1);
  //print_matrix(3,3,result1);


  //test fast
  print_matrix(3,3,test5);
  matrix_pow_rec(3,test5,2,result1);
  print_matrix(3,3,result1);
  
  return 0;
}


