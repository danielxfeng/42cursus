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

void test_stack(void)
{
    t_stacks *stacks = new_stacks(10);
    push_stack(stacks, 1, true);
    push_stack(stacks, 2, true);
    push_stack(stacks, 3, true);
    t_stack *stack_a = stacks->stack_a;
    int expected[3] = {1, 2, 3};
    for (size_t i = 0; i < stack_a->len; ++i)
    {
        size_t idx = get_raw_idx(stack_a, i);
        TEST_ASSERT_EQUAL_INT(expected[i], stack_a->arr[idx]);
    }
    s(stacks, true);
    int expected2[3] = {2, 1, 3};
    for (size_t i = 0; i < stack_a->len; ++i)
    {
        size_t idx = get_raw_idx(stack_a, i);
        TEST_ASSERT_EQUAL_INT(expected2[i], stack_a->arr[idx]);
    }
    TEST_ASSERT_EQUAL_UINT(0, stack_a->head);
    TEST_ASSERT_EQUAL_UINT(3, stack_a->len);
    free_helper(&stacks);
    stacks = new_stacks(10);
    push_stack(stacks, 1, true);
    push_stack(stacks, 2, true);
    push_stack(stacks, 3, true);
    r(stacks, true);
    int expected3[3] = {2, 3, 1};
    for (size_t i = 0; i < stack_a->len; ++i)
    {
        size_t idx = get_raw_idx(stack_a, i);
        TEST_ASSERT_EQUAL_INT(expected3[i], stack_a->arr[idx]);
    }
    printf("%d, %d\n", stack_a->head, stack_a->len);
    //TEST_ASSERT_EQUAL_UINT(0, stack_a->head);
    //TEST_ASSERT_EQUAL_UINT(3, stack_a->len);
    free_helper(&stacks);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_stack);

	return (UNITY_END());
}