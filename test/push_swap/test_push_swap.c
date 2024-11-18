#include "../../src/push_swap/push_swap.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// valgrind --leak-check=full --show-leak-kinds=all ./build/test_push_swap

// Setup function called before each test
void	setUp(void)
{
	// Initialize or allocate resources if needed (optional)
}

// Teardown function called after each test
void	tearDown(void)
{
	// Clean up resources if needed (optional)
}

void export_list(t_stack *stack, int *arr, int *reversed)
{
    t_node *curr = stack->root;
    t_node *rev = stack->root;
    for (int i = 0; i < stack->len; ++i)
    {
        arr[i] = curr->value;
        reversed[i] = rev->value;
        curr = curr->next;
        rev = rev->prev;        
    }
}

void test_stack(void)
{
    t_stacks *stacks = new_stacks();
    push_stack(stacks, 1, true);
    push_stack(stacks, 2, true);
    push_stack(stacks, 3, true);
    t_stack *stack_a = stacks->stack_a;
    int expected[3] = {1, 2, 3};
    int rev_expected[3] = {1, 3, 2};
    int arr[100];
    int reversed[100];
    export_list(stack_a, arr, reversed);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 3);
    TEST_ASSERT_EQUAL_INT_ARRAY(rev_expected, reversed, 3);
    TEST_ASSERT_EQUAL_INT(3, stack_a->len);
    s(stacks, true);
    int expected2[3] = {2, 1, 3};
    int rev_expected2[3] = {2, 3, 1};
    export_list(stack_a, arr, reversed);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected2, arr, 3);
    TEST_ASSERT_EQUAL_INT_ARRAY(rev_expected2, reversed, 3);
    TEST_ASSERT_EQUAL_INT(3, stack_a->len);
    r(stacks, true);
    int expected3[3] = {1, 3, 2};
    int rev_expected3[3] = {1, 2, 3};
    export_list(stack_a, arr, reversed);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected3, arr, 3);
    TEST_ASSERT_EQUAL_INT_ARRAY(rev_expected3, reversed, 3);
    TEST_ASSERT_EQUAL_INT(3, stack_a->len);
    rr(stacks, true);
    int expected4[3] = {2, 1, 3};
    int rev_expected4[3] = {2, 3, 1};
    export_list(stack_a, arr, reversed);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected4, arr, 3);
    TEST_ASSERT_EQUAL_INT_ARRAY(rev_expected4, reversed, 3);
    TEST_ASSERT_EQUAL_INT(3, stack_a->len);
    int expected5[2] = {1, 3};
    int expected6[1] = {2};
    p(stacks, false);
    int arr_b[100];
    int reversed_b[100];
    t_stack *stack_b = stacks->stack_b;
    export_list(stack_a, arr, reversed);
    export_list(stack_b, arr_b, reversed_b);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected5, arr, 2);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected6, arr_b, 1);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected5, reversed, 2);
    TEST_ASSERT_EQUAL_INT(2, stack_a->len);
    TEST_ASSERT_EQUAL_INT(1, stack_b->len);
    int expected7[1] = {3};
    int expected8[2] = {1, 2};
    p(stacks, false);
    export_list(stack_a, arr, reversed);
    export_list(stack_b, arr_b, reversed_b);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected7, arr, 1);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected8, arr_b, 2);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected7, reversed, 1);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected8, reversed_b, 2);
    TEST_ASSERT_EQUAL_INT(1, stack_a->len);
    TEST_ASSERT_EQUAL_INT(2, stack_b->len);
    int expected9[3] = {3, 1, 2};
    int rev_expected9[3] = {3, 2, 1};
    p(stacks, false);
    export_list(stack_b, arr_b, reversed_b);
    TEST_ASSERT_NULL(stack_a->root);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected9, arr_b, 3);
    TEST_ASSERT_EQUAL_INT_ARRAY(rev_expected9, reversed_b, 2);
    TEST_ASSERT_EQUAL_INT(0, stack_a->len);
    TEST_ASSERT_EQUAL_INT(3, stack_b->len);
    TEST_ASSERT_EQUAL_INT(0, push_stack(stacks, 2, false));
    TEST_ASSERT_EQUAL_INT(0, push_stack(stacks, 3, false));
    TEST_ASSERT_EQUAL_INT(0, push_stack(stacks, 1, false));
    free_helper(&stacks);
}

void test_atoi()
{
    int n = 0;
    TEST_ASSERT_EQUAL_INT(1, my_atoi("22", &n));
    TEST_ASSERT_EQUAL_INT(22, n);
    TEST_ASSERT_EQUAL_INT(1, my_atoi("-22", &n));
    TEST_ASSERT_EQUAL_INT(-22, n);
    TEST_ASSERT_EQUAL_INT(1, my_atoi("+22", &n));
    TEST_ASSERT_EQUAL_INT(22, n);
    TEST_ASSERT_EQUAL_INT(1, my_atoi("   22", &n));
    TEST_ASSERT_EQUAL_INT(22, n);
    TEST_ASSERT_EQUAL_INT(0, my_atoi("22a", &n));
    TEST_ASSERT_EQUAL_INT(1, my_atoi("-2147483648", &n));
    TEST_ASSERT_EQUAL_INT(-2147483648, n);
    TEST_ASSERT_EQUAL_INT(0, my_atoi("2147483648", &n));
    TEST_ASSERT_EQUAL_INT(0, my_atoi("=22", &n));
    TEST_ASSERT_EQUAL_INT(0, my_atoi("18446744073709551618", &n));
    TEST_ASSERT_EQUAL_INT(0, my_atoi("22a", &n));
}

void test_insert_value_to_stacks()
{
    t_stacks *stacks = new_stacks();
    int arr[100];
    int rev[100];
    char *argv[] = {"prog", "1", "2", "11"};
    TEST_ASSERT_EQUAL_INT(1, insert_value_to_stacks(stacks, 4, argv));
    TEST_ASSERT_EQUAL_INT(3, stacks->stack_a->len);
    char *argv2[] = {"prog", "-2 12 8"};
    TEST_ASSERT_EQUAL_INT(1, insert_value_to_stacks(stacks, 2, argv2));
    TEST_ASSERT_EQUAL_INT(6, stacks->stack_a->len);
    char *argv3[] = {"prog", "3 9 111", "5"};
    TEST_ASSERT_EQUAL_INT(1, insert_value_to_stacks(stacks, 3, argv3));
    TEST_ASSERT_EQUAL_INT(10, stacks->stack_a->len);
    int expect[] = {1, 2, 11, -2, 12, 8, 3, 9, 111, 5};
    export_list(stacks->stack_a, arr, rev);
    TEST_ASSERT_EQUAL_INT_ARRAY(expect, arr, 10);
    char *argv4[] = {"prog", ""};
    TEST_ASSERT_EQUAL_INT(0, insert_value_to_stacks(stacks, 2, argv4));
    char *argv5[] = {"prog", "-2s"};
    TEST_ASSERT_EQUAL_INT(0, insert_value_to_stacks(stacks, 2, argv5));
    char *argv6[] = {"prog", "s"};
    TEST_ASSERT_EQUAL_INT(0, insert_value_to_stacks(stacks, 2, argv6));
    char *argv7[] = {"prog", "11"};
    TEST_ASSERT_EQUAL_INT(0, insert_value_to_stacks(stacks, 2, argv7));
    char *argv8[] = {"prog", "99  98"};
    TEST_ASSERT_EQUAL_INT(1, insert_value_to_stacks(stacks, 2, argv8));
    TEST_ASSERT_EQUAL_INT(12, stacks->stack_a->len);
    char *argv9[] = {"prog", "  76  75  "};
    TEST_ASSERT_EQUAL_INT(1, insert_value_to_stacks(stacks, 2, argv9));
    TEST_ASSERT_EQUAL_INT(14, stacks->stack_a->len);
    int expect2[] = {1, 2, 11, -2, 12, 8, 3, 9, 111, 5, 99, 98, 76, 75};
    export_list(stacks->stack_a, arr, rev);
    TEST_ASSERT_EQUAL_INT_ARRAY(expect2, arr, 14);
}

void test_push_swap()
{
    char *argv[] = {"prog", "1", "2", "3"};
    TEST_ASSERT_EQUAL_INT(0, push_swap(4, argv, NULL));
    char *argv2[] = {"prog", "-2147483648", "  +2", "3"};
    TEST_ASSERT_EQUAL_INT(0, push_swap(4, argv2, NULL));
    char *argv3[] = {"prog", "-1", "2147483648", "3"};
    TEST_ASSERT_EQUAL_INT(1, push_swap(4, argv3, NULL));
    char *argv4[] = {"prog", "+-1", "2", "3"};
    TEST_ASSERT_EQUAL_INT(1, push_swap(4, argv4, NULL));
    char *argv5[] = {"prog", "+-", "2", "3"};
    TEST_ASSERT_EQUAL_INT(1, push_swap(4, argv5, NULL));
    char *argv6[] = {"prog", "2", "2", "3"};
    TEST_ASSERT_EQUAL_INT(1, push_swap(4, argv6, NULL));
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_stack);
    RUN_TEST(test_atoi);
    RUN_TEST(test_insert_value_to_stacks);
    RUN_TEST(test_push_swap);

	return (UNITY_END());
}
