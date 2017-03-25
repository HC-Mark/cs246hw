/* check_llist_node.c

   Unit tests for a singly-linked list
*/

#include <check.h>

#include "llist_node.h"

void check_llist(llist_node* head, int xs[])
{
  for(int i = 0; head; i++, head = head->next)
  {
    ck_assert_int_eq(head->data, xs[i]);
  }
}

void reverse_array(int n, int a[n])
{
  for(int i = 0, j = n-1; i < j; i++, j--)
  {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
}

START_TEST(test_new_node)
{
  llist_node* n = NULL;
  
  int xs[] = { 1, 4, 8, 3, 5 };
  int len = sizeof(xs)/sizeof(xs[0]);
  for(int i = 0; i < len; i++)
  {
    n = new_node(xs[i], n);
  }

  reverse_array(len, xs);
  check_llist(n, xs);
  ck_assert_int_eq(length(n), len);

  free_llist(n);
}
END_TEST

START_TEST(test_insert_after)
{
  int xs[] = { 1, 4, 8, 3, 5 };
  int len = sizeof(xs)/sizeof(xs[0]);
  
  llist_node* n = new_node(xs[0], NULL);
  for(int i = len-1; i >= 1; i--)
  {
    insert_after(n, xs[i]);
  }

  check_llist(n, xs);
  ck_assert_int_eq(length(n), len);

  free_llist(n);
}
END_TEST

START_TEST(test_from_array)
{
  int xs[] = { 1, 4, 8, 3, 5 };
  int len = sizeof(xs)/sizeof(xs[0]);

  llist_node* n = from_array(len, xs);
  check_llist(n, xs);
  ck_assert_int_eq(length(n), len);

  free_llist(n);
}
END_TEST

START_TEST(test_delete_after)
{
  int xs[] = { 1, 4, 8, 3, 5 };
  int len = sizeof(xs)/sizeof(xs[0]);

  llist_node* n = from_array(len, xs);
  delete_after(n);
  delete_after(n);

  check_llist(n, (int[]){1, 3, 5});
  ck_assert_int_eq(length(n), 3);

  free_llist(n);
}
END_TEST

START_TEST(test_nth_node)
{
  int xs[] = { 1, 4, 8, 3, 5 };
  int len = sizeof(xs)/sizeof(xs[0]);

  llist_node* n = from_array(len, xs);
  for(int i = 0; i < len; i++)
  {
    ck_assert_int_eq(xs[i], nth_node(n, i)->data);
  }

  free_llist(n);
}
END_TEST

START_TEST(test_to_array)
{
  int xs[] = { 1, 4, 8, 3, 5 };
  int len = sizeof(xs)/sizeof(xs[0]);

  int ys[len];
  llist_node* n = from_array(len, xs);
  ck_assert_int_eq(to_array(n, len, ys), len);
  for(int i = 0; i < len; i++)
  {
    ck_assert_int_eq(xs[i], ys[i]);
  }

  free_llist(n);
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
  TCase* tc = tcase_create("llist");

  // Each TCase can have many individual testing functions.
  tcase_add_test(tc, test_new_node);
  tcase_add_test(tc, test_insert_after);
  tcase_add_test(tc, test_from_array);
  tcase_add_test(tc, test_delete_after);
  tcase_add_test(tc, test_nth_node);
  tcase_add_test(tc, test_to_array);

  // Having set up the TCase, add it to the suite:
  suite_add_tcase(s, tc);

  // To run the tests, we need a runner:
  SRunner* sr = srunner_create(s);

  // This next line means that all tests run sequentially (instead
  // of at the same time). It also means that valgrind's output is
  // simpler.
  srunner_set_fork_status(sr, CK_NOFORK);

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
				    
