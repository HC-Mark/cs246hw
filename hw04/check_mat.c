/* check_mat.c

   Name:

   Unit tests for the matrix functions.

   These tests use the `check` library, available here:
   https://libcheck.github.io/check/

   Documentation for the functions is here:
   https://libcheck.github.io/check/doc/doxygen/html/check_8h.html

   When linking this file into an executable (with `gcc -o`), make sure
   to pass in `-lcheck` to link to the "check" library. For example,
   to compile this with the matrix.c file you would do

     gcc -c matrix.c
     gcc -c check_mat.c
     gcc -o check_mat matrix.o check_mat.o -lcheck

   or, if you wanted to compile and link at the same time,

     gcc -o check_mat matrix.c check_mat.c -lcheck
*/

#include <stdbool.h>
#include <check.h>

#include "matrix.h"

START_TEST(test_eq_matrix)
{ //initialize
  int i, j;
  int test1 [5][5] = {};
  int test2 [5][5] = {};
  int test3 [5][5] = {{1}, {0,1},{0,0,1},{0,0,0,1},{0,0,0,0,1}};
  for( i = 0; i < 5 ; i++){
    for( j = 0; j < 5; j++){
      test1[i][j] = i + j;
      test2[i][j] = i + j;
    }
  }
  
  ck_assert(eq_matrix(5,5,test1,test2));
  ck_assert(!eq_matrix(5,5,test1,test2));
  ck_assert(!eq_matrix(5,5,test1,test3));
  ck_assert(!eq_matrix(5,5,test2,test3));
  ck_assert(eq_matrix(5,5,test3,test3));
}
END_TEST

// You can have multiple tests in a file.
START_TEST(test_identity_mat)
{
  int standard2 [2][2] = {{1,0}, {0,1}};
  int standard3 [3][3] = {{1,0,0}, {0,1,0},{0,0,1}};
  int test1 [3][3] = {}
  int test2 [2][2] = {}

  identity_mat(3,test1);
  identity_mat(2,test2);

  ck_assert(eq_matrix(2,2,standard2, test2));
  ck_assert(eq_matrix(3,3,standard3, test1));
}
END_TEST

START_TEST(test_scalar_mult){
  int standard1 [3][3] = {{3,0,0}, {0,3,0}, {0,0,3}};
  int standard2 [3][3] = {{0,0,3}, {0,3,0}, {3,0,0}};
  int standard3 [3][3] = {{8,18,12}, {14,8,2}, {18,16,0}};
  int standard4 [4][3] = {{3,15,24}, {6,3,21},{30,12,24}, {138,0,12}};

  int test1 [3][3] = {}
  identity_mat(3,test1);
  int test2 [3][3] = {{0,0,1}, {0,1,0}, {1,0,0}};
  int test3 [3][3] = {{4,9,6},
		      {7,4,1},
		      {9,8,0}};
  int test4 [4][3] = {{1,5,8},
		    {2,1,7},
		    {10,4,8},
		    {46,0,4}};

  int result1 [3][3] = {};
  int result2 [3][3] = {};
  int result3 [3][3] = {};
  int result4 [4][3] = {};
  
  scalar_mult(3,3,3,test1,result1);
  scalar_mult(3,3,3,test2,result2);
  scalar_mult(2,3,3,test3,result3);
  scalar_mult(3,4,3,test4,result4);

  ck_assert(eq_matrix(3,3,result1,standard1));
  ck_assert(eq_matrix(3,3,result2,standard2));
  ck_assert(eq_matrix(3,3,result3,standard3));
  ck_assert(eq_matrix(4,3,result4,standard4));
}
END_TEST

START_TEST(test_matrix_mult){
  int test1 [3][3] = {}
  identity_mat(3,test1);
  int test2 [3][3] = {{0,0,1}, {0,1,0}, {1,0,0}};
  int test3 [3][3] = {{4,9,6},
		      {7,4,1},
		      {9,8,0}};

  int standard1 [3][3] = {{0,0,1},{0,1,0},{1,0,1}}; //test1 * test2
  int standard2 [3][3] = {{4,9,6},
			  {7,4,1},
			  {9,8,0}}; //test3 * test1 
  int standard3 [3][3] =  {{6,9,4},{1,4,7},{0,8,9}};

  int result1 [3][3] = {};
  int result2 [3][3] = {};
  int result3 [3][3] = {};

  matrix_mult(3,3,test1,3,test2,result1);
  matrix_mult(3,3,test3,3,test1,result2);
  matrix_mult(3,3,test3,3,test2,result3));

  ck_assert(ex_matrix(3,3,standard1,result1));
  ck_assert(ex_matrix(3,3,standard2,result2));
  ck_assert(ex_matrix(3,3,standard3,result3));
				      

}
END_TEST

START_TEST(test_matri_pow){
  int test1 [3][3] = {}
  identity_mat(3,test1);
  int test2 [3][3] = {{0,0,1}, {0,1,0}, {1,0,0}};
  int test3 [3][3] = {{4,9,6},
		      {7,4,1},
		      {9,8,0}};

  int result1 [3][3] = {};
  int result2 [3][3] = {};
  int result3 [3][3] = {};

  int standard1 [3][3] = {{1,0,0},{0,1,0},{0,0,1}}; //test1
  int standard2 [3][3] = {{1,0,0},{0,1,0},{0,0,1}}; //test2 
  int standard3 [3][3] =  {{133,120,33},{65,87,46},{92,113,62}};

  matrix_pow(3,test1,5,result1);
  matrix_pow(3,test2,2,result2);
  matrix_pow(3,test3,2,result3);
  
  ck_assert(ex_matrix(3,3,standard1,result1));
  ck_assert(ex_matrix(3,3,standard2,result2));
  ck_assert(ex_matrix(3,3,standard3,result3));
}
END_TEST

START_TEST(test_matri_pow_rec){
  int test1 [3][3] = {}
  identity_mat(3,test1);
  int test2 [3][3] = {{0,0,1}, {0,1,0}, {1,0,0}};
  int test3 [3][3] = {{4,9,6},
		      {7,4,1},
		      {9,8,0}};

  int result1 [3][3] = {};
  int result2 [3][3] = {};
  int result3 [3][3] = {};

  int standard1 [3][3] = {{1,0,0},{0,1,0},{0,0,1}}; //test1
  int standard2 [3][3] = {{1,0,0},{0,1,0},{0,0,1}}; //test2 
  int standard3 [3][3] =  {{133,120,33},{65,87,46},{92,113,62}};//test3

  matrix_pow_rec(3,test1,5,result1);
  matrix_pow_rec(3,test2,2,result2);
  matrix_pow_rec(3,test3,2,result3);
  
  ck_assert(ex_matrix(3,3,standard1,result1));
  ck_assert(ex_matrix(3,3,standard2,result2));
  ck_assert(ex_matrix(3,3,standard3,result3));
}
END_TEST

START_TEST(test_matrix_pow_and_matrix_pow_rec){
  int test1 [3][3] = {}
  identity_mat(3,test1);
  int test2 [3][3] = {{0,0,1}, {0,1,0}, {1,0,0}};
  int test3 [3][3] = {{4,9,6},
		      {7,4,1},
		      {9,8,0}};

  int result1 [3][3] = {};
  int result2 [3][3] = {};
  int result3 [3][3] = {};

  int result1_r [3][3] = {};
  int result2_r [3][3] = {};
  int result3_r [3][3] = {};

  matrix_pow(3,test1,5,result1);
  matrix_pow(3,test2,2,result2);
  matrix_pow(3,test3,2,result3);
  
  matrix_pow_rec(3,test1,5,result1_r);
  matrix_pow_rec(3,test2,2,result2_r);
  matrix_pow_rec(3,test3,2,result3_r);

  ck_assert(ex_matrix(3,3,result1_r,result1));
  ck_assert(ex_matrix(3,3,result2_r,result2));
  ck_assert(ex_matrix(3,3,result3_r,result3));

}
END_TEST
// the main() function for unit testing is fairly prescribed.
// Just copy & paste, but make sure to update the test names!
int main()
{
  // `check` allows for multiple test suites, but we'll always
  // just have one, called "main"
  Suite* s = suite_create("main");

  // Inside a suite are potentially many `TCase`s.
  TCase* tc = tcase_create("matrix");

  // Each TCase can have many individual testing functions.
  tcase_add_test(tc, test_eq_matrix);
  tcase_add_test(tc, test_identity_mat);
  tcase_add_test(tc, test_scalar_mult);
  tcase_add_test(tc, test_matrix_mult);
  tcase_add_test(tc, test_matrix_pow);
  tcase_add_test(tc, test_matrix_pow_rec);
  tcase_add_test(tc, test_matrix_pow_and_matrix_pow_rec);

  // Having set up the TCase, add it to the suite:
  suite_add_tcase(s, tc);

  // To run the tests, we need a runner:
  SRunner* sr = srunner_create(s);

  // You can see options for running only some of the tests at
  // the documentation link above. The CK_NORMAL indicates to
  // print only failing tests.
  srunner_run_all(sr, CK_NORMAL);

  // after running, we can retrieve the number of failures
  int number_failed = srunner_ntests_failed(sr);

  // We're done now with the testsuite, so dispose of it properly
  srunner_free(sr);

  // conveniently, number_failed makes a nice exit code.
  // a non-zero answer means a failed test!
  return number_failed;
}
				    
