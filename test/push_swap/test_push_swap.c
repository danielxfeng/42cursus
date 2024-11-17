#include "../../src/push_swap/push_swap.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    p(stacks, true);
    int *arr_b[100];
    int *reversed_b[100];
    t_stack *stack_b = stacks->stack_b;
    export_list(stack_a, arr, reversed);
    export_list(stack_b, arr_b, reversed_b);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected5, arr, 2);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected6, arr_b, 1);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected5, reversed, 2);
    TEST_ASSERT_EQUAL_INT(2, stack_a->len);
    TEST_ASSERT_EQUAL_INT(1, stack_b->len);
    free_helper(&stacks);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_stack);

	return (UNITY_END());
}