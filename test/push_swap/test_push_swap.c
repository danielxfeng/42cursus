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

void	export_list(t_stack *stack, int *arr, int *reversed)
{
	t_node	*curr;
	t_node	*rev;

	curr = stack->root;
	rev = stack->root;
	for (int i = 0; i < stack->len; ++i)
	{
		arr[i] = curr->value;
		reversed[i] = rev->value;
		curr = curr->next;
		rev = rev->prev;
	}
}

void	test_stack(void)
{
	t_stacks	*stacks;
	t_stack		*stack_a;
	int			expected[3] = {1, 2, 3};
	int			rev_expected[3] = {1, 3, 2};
	int			arr[100];
	int			reversed[100];
	int			expected2[3] = {2, 1, 3};
	int			rev_expected2[3] = {2, 3, 1};
	int			expected3[3] = {1, 3, 2};
	int			rev_expected3[3] = {1, 2, 3};
	int			expected4[3] = {2, 1, 3};
	int			rev_expected4[3] = {2, 3, 1};
	int			expected5[2] = {1, 3};
	int			expected6[1] = {2};
	int			arr_b[100];
	int			reversed_b[100];
	t_stack		*stack_b;
	int			expected7[1] = {3};
	int			expected8[2] = {1, 2};
	int			expected9[3] = {3, 1, 2};
	int			rev_expected9[3] = {3, 2, 1};

	stacks = new_stacks();
	push_stack(stacks, 1, true);
	push_stack(stacks, 2, true);
	push_stack(stacks, 3, true);
	stack_a = stacks->stack_a;
	export_list(stack_a, arr, reversed);
	TEST_ASSERT_EQUAL_INT(0, get_idx_by_value(stacks, 1, true));
	TEST_ASSERT_EQUAL_INT(1, get_idx_by_value(stacks, 2, true));
	TEST_ASSERT_EQUAL_INT(2, get_idx_by_value(stacks, 3, true));
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 3);
	TEST_ASSERT_EQUAL_INT_ARRAY(rev_expected, reversed, 3);
	TEST_ASSERT_EQUAL_INT(3, stack_a->len);
	s(stacks, true);
	export_list(stack_a, arr, reversed);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected2, arr, 3);
	TEST_ASSERT_EQUAL_INT_ARRAY(rev_expected2, reversed, 3);
	TEST_ASSERT_EQUAL_INT(3, stack_a->len);
	r(stacks, true);
	export_list(stack_a, arr, reversed);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected3, arr, 3);
	TEST_ASSERT_EQUAL_INT_ARRAY(rev_expected3, reversed, 3);
	TEST_ASSERT_EQUAL_INT(3, stack_a->len);
	rr(stacks, true);
	export_list(stack_a, arr, reversed);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected4, arr, 3);
	TEST_ASSERT_EQUAL_INT_ARRAY(rev_expected4, reversed, 3);
	TEST_ASSERT_EQUAL_INT(3, stack_a->len);
	p(stacks, false);
	stack_b = stacks->stack_b;
	export_list(stack_a, arr, reversed);
	export_list(stack_b, arr_b, reversed_b);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected5, arr, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected6, arr_b, 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected5, reversed, 2);
	TEST_ASSERT_EQUAL_INT(2, stack_a->len);
	TEST_ASSERT_EQUAL_INT(1, stack_b->len);
	p(stacks, false);
	export_list(stack_a, arr, reversed);
	export_list(stack_b, arr_b, reversed_b);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected7, arr, 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected8, arr_b, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected7, reversed, 1);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected8, reversed_b, 2);
	TEST_ASSERT_EQUAL_INT(1, stack_a->len);
	TEST_ASSERT_EQUAL_INT(2, stack_b->len);
	p(stacks, false);
	export_list(stack_b, arr_b, reversed_b);
	TEST_ASSERT_NULL(stack_a->root);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected9, arr_b, 3);
	TEST_ASSERT_EQUAL_INT_ARRAY(rev_expected9, reversed_b, 2);
	TEST_ASSERT_EQUAL_INT(0, stack_a->len);
	TEST_ASSERT_EQUAL_INT(3, stack_b->len);
	TEST_ASSERT_EQUAL_INT(3, get_value_from_stack(stacks, false, 0));
	TEST_ASSERT_EQUAL_INT(1, get_value_from_stack(stacks, false, 1));
	TEST_ASSERT_EQUAL_INT(2, get_value_from_stack(stacks, false, 2));
	TEST_ASSERT_EQUAL_INT(0, push_stack(stacks, 2, false));
	TEST_ASSERT_EQUAL_INT(0, push_stack(stacks, 3, false));
	TEST_ASSERT_EQUAL_INT(0, push_stack(stacks, 1, false));
	close_stacks(&stacks);
}

void test_stack_op(void)
{
	t_stacks	*stacks;
	t_stack		*stack_a;
	t_stack *stack_b;

	stacks = new_stacks();
	push_stack(stacks, 1, true);
	push_stack(stacks, 2, true);
	push_stack(stacks, 3, true);
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	r(stacks, true);
	TEST_ASSERT_EQUAL_INT(2, get_idx_by_value(stacks, 1, true));
	TEST_ASSERT_EQUAL_INT(0, get_idx_by_value(stacks, 2, true));
	rr(stacks, true);
	TEST_ASSERT_EQUAL_INT(0, get_idx_by_value(stacks, 1, true));
	TEST_ASSERT_EQUAL_INT(1, get_idx_by_value(stacks, 2, true));
	s(stacks, true);
	TEST_ASSERT_EQUAL_INT(1, get_idx_by_value(stacks, 1, true));
	TEST_ASSERT_EQUAL_INT(0, get_idx_by_value(stacks, 2, true));		
	p(stacks, false);
	TEST_ASSERT_EQUAL_INT(0, get_idx_by_value(stacks, 1, true));
	TEST_ASSERT_EQUAL_INT(1, get_idx_by_value(stacks, 3, true));		
	TEST_ASSERT_EQUAL_INT(0, get_idx_by_value(stacks, 2, false));
	TEST_ASSERT_EQUAL_INT(1, stack_b->len);
	TEST_ASSERT_EQUAL_INT(2, stack_a->len);	
	TEST_ASSERT_EQUAL_INT(2, stack_b->max->value);
	p(stacks, false);
	p(stacks, false);
	TEST_ASSERT_EQUAL_INT(0, stack_a->len);
	TEST_ASSERT_EQUAL_INT(3, stack_b->len);	
	TEST_ASSERT_EQUAL_INT(3, stack_b->max->value);
	TEST_ASSERT_EQUAL_INT(1, get_idx_by_value(stacks, 1, false));
	TEST_ASSERT_EQUAL_INT(0, get_idx_by_value(stacks, 3, false));		
	TEST_ASSERT_EQUAL_INT(2, get_idx_by_value(stacks, 2, false));
	TEST_ASSERT_EQUAL_INT(INT_MAX, get_idx_by_value(stacks, 5, true));
}

void	test_atoi(void)
{
	int	n;

	n = 0;
	TEST_ASSERT_EQUAL_INT(1, ps_atoi("22", &n));
	TEST_ASSERT_EQUAL_INT(22, n);
	TEST_ASSERT_EQUAL_INT(1, ps_atoi("-22", &n));
	TEST_ASSERT_EQUAL_INT(-22, n);
	TEST_ASSERT_EQUAL_INT(1, ps_atoi("+22", &n));
	TEST_ASSERT_EQUAL_INT(22, n);
	TEST_ASSERT_EQUAL_INT(1, ps_atoi("   22", &n));
	TEST_ASSERT_EQUAL_INT(22, n);
	TEST_ASSERT_EQUAL_INT(0, ps_atoi("22a", &n));
	TEST_ASSERT_EQUAL_INT(1, ps_atoi("-2147483648", &n));
	TEST_ASSERT_EQUAL_INT(-2147483648, n);
	TEST_ASSERT_EQUAL_INT(0, ps_atoi("2147483648", &n));
	TEST_ASSERT_EQUAL_INT(0, ps_atoi("=22", &n));
	TEST_ASSERT_EQUAL_INT(0, ps_atoi("18446744073709551618", &n));
	TEST_ASSERT_EQUAL_INT(0, ps_atoi("22a", &n));
}

void	test_insert_value_to_stacks(void)
{
	t_stacks	*stacks;
	int			arr[100];
	int			rev[100];
	char		*argv[] = {"prog", "1", "2", "11"};
	char		*argv2[] = {"prog", "-2 12 8"};
	char		*argv3[] = {"prog", "3 9 111", "5"};
	int			expect[] = {1, 2, 11, -2, 12, 8, 3, 9, 111, 5};
	char		*argv4[] = {"prog", ""};
	char		*argv5[] = {"prog", "-2s"};
	char		*argv6[] = {"prog", "s"};
	char		*argv7[] = {"prog", "11"};
	char		*argv8[] = {"prog", "99  98"};
	char		*argv9[] = {"prog", "  76  75 "};
	int			expect2[] = {1, 2, 11, -2, 12, 8, 3, 9, 111, 5, 99, 98, 76, 75};
	char		*argv10[] = {"prog", "    "};

	stacks = new_stacks();
	TEST_ASSERT_EQUAL_INT(1, insert_value_to_stacks(stacks, 4, argv));
	TEST_ASSERT_EQUAL_INT(3, stacks->stack_a->len);
	TEST_ASSERT_EQUAL_INT(1, insert_value_to_stacks(stacks, 2, argv2));
	TEST_ASSERT_EQUAL_INT(6, stacks->stack_a->len);
	TEST_ASSERT_EQUAL_INT(1, insert_value_to_stacks(stacks, 3, argv3));
	TEST_ASSERT_EQUAL_INT(10, stacks->stack_a->len);
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, arr, 10);
	TEST_ASSERT_EQUAL_INT(0, insert_value_to_stacks(stacks, 2, argv4));
	TEST_ASSERT_EQUAL_INT(0, insert_value_to_stacks(stacks, 2, argv5));
	TEST_ASSERT_EQUAL_INT(0, insert_value_to_stacks(stacks, 2, argv6));
	TEST_ASSERT_EQUAL_INT(0, insert_value_to_stacks(stacks, 2, argv7));
	TEST_ASSERT_EQUAL_INT(1, insert_value_to_stacks(stacks, 2, argv8));
	TEST_ASSERT_EQUAL_INT(12, stacks->stack_a->len);
	TEST_ASSERT_EQUAL_INT(1, insert_value_to_stacks(stacks, 2, argv9));
	TEST_ASSERT_EQUAL_INT(14, stacks->stack_a->len);
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect2, arr, 14);
	TEST_ASSERT_EQUAL_INT(0, insert_value_to_stacks(stacks, 2, argv10));
	close_stacks(&stacks);
}

void	test_push_swap(void)
{
	char	*argv[] = {"prog", "1", "2", "3"};
	char	*argv2[] = {"prog", "-2147483648", "  +2", "3"};
	char	*argv3[] = {"prog", "-1", "2147483648", "3"};
	char	*argv4[] = {"prog", "+-1", "2", "3"};
	char	*argv5[] = {"prog", "+-", "2", "3"};
	char	*argv6[] = {"prog", "2", "2", "3"};

	TEST_ASSERT_EQUAL_INT(0, push_swap(4, argv, NULL));
	TEST_ASSERT_EQUAL_INT(0, push_swap(4, argv2, NULL));
	TEST_ASSERT_EQUAL_INT(1, push_swap(4, argv3, NULL));
	TEST_ASSERT_EQUAL_INT(1, push_swap(4, argv4, NULL));
	TEST_ASSERT_EQUAL_INT(1, push_swap(4, argv5, NULL));
	TEST_ASSERT_EQUAL_INT(1, push_swap(4, argv6, NULL));
}

void test_plan(void)
{
	int		value_1[] = {159, 146, 137, 125, 105, 99, 88};
	int		value_2[] = {158, 136, 128, 110, 101, 98, 86};
	t_stacks	*stacks;
	t_move_plan_ab plan;

	stacks = new_stacks();
	for (size_t i = 0; i < 7; ++i)
		push_stack(stacks, value_1[i], true);
	for (size_t i = 0; i < 7; ++i)
	{
		get_best_plan_ab(stacks, i, &plan);
		size_t cost = i;
		if (7 - i < cost)
			cost = 7 - i;
		TEST_ASSERT_EQUAL_INT(cost, plan.a_op_times);
		TEST_ASSERT_EQUAL_INT(cost == i, plan.a_is_r);
		TEST_ASSERT_EQUAL_INT(0, plan.b_op_times);
		TEST_ASSERT_EQUAL_INT(1, plan.b_is_r);
		TEST_ASSERT_EQUAL_INT(cost + 1, plan.total_times);
		// printf("a_is_r: %d, a_op_times: %d, b_is_r: %d, b_op_times: %d, double_times: %d, idx: %d, total_times: %d\n", plan.a_is_r, plan.a_op_times, plan.b_is_r, plan.b_op_times, plan.double_op_times, plan.idx, plan.total_times);
	}
	for (size_t j = 0; j < 7; ++j)
	{
		push_stack(stacks, value_2[j], false);
		if (!stacks->stack_b->max || value_2[j] > stacks->stack_b->max->value)
			stacks->stack_b->max = stacks->stack_b->root;
		for (size_t i = 0; i < 7; ++i)
		{
			get_best_plan_ab(stacks, i, &plan);
			size_t cost = i;
			if (7 - i < cost)
				cost = 7 - i;
			//TEST_ASSERT_EQUAL_INT(cost, plan.a_op_times);
			//TEST_ASSERT_EQUAL_INT(cost == i, plan.a_is_r);
			//TEST_ASSERT_EQUAL_INT(0, plan.b_op_times);
			//TEST_ASSERT_EQUAL_INT(1, plan.b_is_r);
			//TEST_ASSERT_EQUAL_INT(cost + 1, plan.total_times);
			printf("j: %d, i: %d; a_is_r: %d, a_op_times: %d, b_is_r: %d, b_op_times: %d, double_times: %d, idx: %d, total_times: %d\n", j, i, plan.a_is_r, plan.a_op_times, plan.b_is_r, plan.b_op_times, plan.double_op_times, plan.idx, plan.total_times);
		}
	}
	close_stacks(&stacks);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_stack);
	RUN_TEST(test_atoi);
	RUN_TEST(test_insert_value_to_stacks);
	RUN_TEST(test_push_swap);
	RUN_TEST(test_stack_op);
	RUN_TEST(test_plan);
    //RUN_TEST(test_astar_sort);
	return (UNITY_END());
}
