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

START_TEST(write_test_name_here)
{
  // WRITE ME
}
END_TEST

// You can have multiple tests in a file.
START_TEST(write_other_test_name_here)
{
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
  tcase_add_test(tc, write_test_name_here);
  tcase_add_test(tc, write_other_test_name_here);

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
				    
