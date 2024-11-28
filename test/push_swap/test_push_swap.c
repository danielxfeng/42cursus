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

/**
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
*/

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
			TEST_ASSERT_EQUAL_INT(cost, plan.a_op_times);
			TEST_ASSERT_EQUAL_INT(cost == i, plan.a_is_r);
			//TEST_ASSERT_EQUAL_INT(0, plan.b_op_times);
			//TEST_ASSERT_EQUAL_INT(1, plan.b_is_r);
			//TEST_ASSERT_EQUAL_INT(cost + 1, plan.total_times);
			printf("j: %d, i: %d; a_is_r: %d, a_op_times: %d, b_is_r: %d, b_op_times: %d, double_times: %d, idx: %d, total_times: %d\n", j, i, plan.a_is_r, plan.a_op_times, plan.b_is_r, plan.b_op_times, plan.double_op_times, plan.idx, plan.total_times);
		}
		printf("\n");
	}
	close_stacks(&stacks);
}

void single_test_sort(int *input, int len)
{
	t_stacks *stacks = new_stacks();
	for (size_t i = 0; i < len; ++i)
		push_stack(stacks, input[i], true);
	astar_sort_func(stacks);
	int output[len];
	int rev[len];
	int expect[len];
	for (size_t i = 0; i < len; ++i)
		expect[i] = i + 1;
	export_list(stacks->stack_a, output, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(expect, output, len);
	close_stacks(&stacks);
}

void test_astar_sort()
{
	int arr[500];
	int rev[500];
	int		value_1[] = {1, 2, 3, 4, 5};
	t_stacks *stacks = new_stacks();
	for (size_t i = 0; i < 5; ++i)
		push_stack(stacks, value_1[i], true);
	TEST_ASSERT_EQUAL_INT(10, astar_sort_func(stacks));
	close_stacks(&stacks);
	int value_2[] = {5, 4, 3, 2, 1};
	stacks = new_stacks();
	for (size_t i = 0; i < 5; ++i)
		push_stack(stacks, value_2[i], true);
	TEST_ASSERT_EQUAL_INT(14, astar_sort_func(stacks));
	close_stacks(&stacks);
		int value_3[] = {1, 5, 2, 3, 4};
	stacks = new_stacks();
	for (size_t i = 0; i < 5; ++i)
		push_stack(stacks, value_3[i], true);
	TEST_ASSERT_EQUAL_INT(15, astar_sort_func(stacks));
	int res3[500] = {1, 2, 3, 4, 5};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res3, arr, 5);
	int value_4[] = {5, 1, 2, 3, 4};
	stacks = new_stacks();
	for (size_t i = 0; i < 5; ++i)
		push_stack(stacks, value_4[i], true);
	TEST_ASSERT_EQUAL_INT(14, astar_sort_func(stacks));
	int res4[500] = {1, 2, 3, 4, 5};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res4, arr, 5);
	close_stacks(&stacks);
	int value_5[] = {5, 2, 4, 3, 1};
	stacks = new_stacks();
	for (size_t i = 0; i < 5; ++i)
		push_stack(stacks, value_5[i], true);
	astar_sort_func(stacks);
	int res5[500] = {1, 2, 3, 4, 5};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res5, arr, 5);
	close_stacks(&stacks);
	int value_6[] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
	stacks = new_stacks();
	for (size_t i = 0; i < 10; ++i)
		push_stack(stacks, value_6[i], true);
	astar_sort_func(stacks);
	int res6[500] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res6, arr, 10);
	close_stacks(&stacks);
	int value_7[] = {2, 1};
	stacks = new_stacks();
	for (size_t i = 0; i < 2; ++i)
		push_stack(stacks, value_7[i], true);
	astar_sort_func(stacks);
	int res7[500] = {1, 2};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res7, arr, 2);
	close_stacks(&stacks);

	int value_8[] = {2, 3, 1};
	stacks = new_stacks();
	for (size_t i = 0; i < 3; ++i)
		push_stack(stacks, value_8[i], true);
	astar_sort_func(stacks);
	int res8[500] = {1, 2, 3};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res8, arr, 3);
	close_stacks(&stacks);

	int value_9[] = {2, 1, 3};
	stacks = new_stacks();
	for (size_t i = 0; i < 3; ++i)
		push_stack(stacks, value_9[i], true);
	astar_sort_func(stacks);
	int res9[500] = {1, 2, 3};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res9, arr, 3);
	close_stacks(&stacks);

	int value_10[] = {3, 2, 1};
	stacks = new_stacks();
	for (size_t i = 0; i < 3; ++i)
		push_stack(stacks, value_10[i], true);
	astar_sort_func(stacks);
	int res10[500] = {1, 2, 3};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res10, arr, 3);
	close_stacks(&stacks);

	int value_11[] = {2, 1, 4, 3};
	stacks = new_stacks();
	for (size_t i = 0; i < 4; ++i)
		push_stack(stacks, value_11[i], true);
	astar_sort_func(stacks);
	int res11[500] = {1, 2, 3, 4};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res11, arr, 4);
	close_stacks(&stacks);

	int value_12[] = {4, 2, 1, 3};
	stacks = new_stacks();
	for (size_t i = 0; i < 4; ++i)
		push_stack(stacks, value_12[i], true);
	astar_sort_func(stacks);
	int res12[500] = {1, 2, 3, 4};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res12, arr, 4);
	close_stacks(&stacks);

	int value_13[] = {1, 2, 3, 5, 4};
	stacks = new_stacks();
	for (size_t i = 0; i < 5; ++i)
		push_stack(stacks, value_13[i], true);
	astar_sort_func(stacks);
	int res13[500] = {1, 2, 3, 4, 5};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res13, arr, 5);
	close_stacks(&stacks);

	int value14[2] = {2, 1};
	single_test_sort(value14, 2);

	int value15[5] = {1, 2, 4, 5, 3};
	single_test_sort(value15, 5);
	int value16[5] = {1, 2, 5, 3, 4};
	single_test_sort(value16, 5);
	int value17[5] = {1, 4, 2, 5, 3};
	single_test_sort(value17, 5);
	int value18[5] = {1, 5, 2, 4, 3};
	single_test_sort(value18, 5);
	int value19[5] = {3, 1, 2, 5, 4};
	single_test_sort(value19, 5);
	int value20[5] = {4, 2, 1, 5, 3};
	single_test_sort(value20, 5);
	int value21[5] = {5, 4, 3, 1, 2};
	single_test_sort(value21, 5);

	int value22[500] = {217, 355, 35, 2, 147, 374, 85, 103, 148, 471, 161, 56, 6, 252, 440, 356, 329, 90, 186, 55, 376, 126, 47, 241, 184, 88, 279, 84, 310, 412, 37, 414, 427, 275, 317, 257, 352, 487, 70, 289, 101, 398, 293, 45, 115, 223, 450, 401, 286, 191, 264, 443, 140, 325, 98, 322, 358, 357, 80, 274, 287, 151, 62, 467, 326, 121, 233, 15, 481, 110, 182, 265, 490, 159, 163, 100, 479, 432, 218, 291, 345, 446, 30, 395, 196, 187, 338, 42, 461, 386, 29, 363, 331, 421, 107, 160, 444, 194, 51, 18, 375, 178, 67, 177, 17, 430, 193, 327, 315, 370, 431, 208, 335, 132, 406, 9, 89, 36, 422, 204, 106, 268, 125, 378, 468, 185, 74, 334, 144, 429, 271, 16, 205, 1, 139, 94, 58, 448, 162, 137, 403, 202, 198, 336, 419, 5, 81, 342, 53, 278, 486, 83, 472, 158, 50, 131, 150, 411, 445, 93, 65, 301, 417, 133, 92, 328, 261, 23, 353, 359, 238, 409, 344, 128, 262, 283, 108, 225, 290, 495, 48, 400, 86, 222, 488, 54, 130, 439, 27, 373, 492, 240, 190, 7, 399, 470, 170, 391, 259, 155, 500, 314, 485, 28, 57, 489, 172, 39, 199, 246, 413, 66, 214, 458, 82, 242, 168, 497, 203, 11, 216, 154, 231, 13, 232, 462, 478, 281, 423, 404, 119, 237, 420, 354, 49, 181, 282, 323, 21, 175, 32, 146, 164, 416, 402, 436, 285, 385, 41, 389, 483, 234, 337, 31, 207, 284, 145, 97, 390, 153, 276, 319, 457, 273, 3, 441, 156, 280, 360, 288, 244, 307, 165, 215, 64, 343, 312, 340, 303, 316, 474, 111, 248, 14, 463, 426, 258, 63, 149, 305, 388, 364, 143, 236, 266, 76, 405, 397, 19, 469, 171, 12, 192, 173, 197, 394, 435, 78, 209, 384, 493, 484, 480, 465, 418, 351, 212, 434, 87, 59, 206, 451, 464, 123, 219, 104, 428, 91, 142, 382, 267, 459, 321, 455, 228, 34, 96, 260, 361, 415, 188, 456, 362, 339, 365, 112, 195, 377, 141, 20, 72, 24, 239, 220, 425, 313, 349, 183, 494, 295, 387, 309, 102, 299, 213, 117, 136, 226, 114, 245, 324, 311, 77, 347, 350, 201, 270, 296, 73, 176, 433, 251, 466, 134, 169, 224, 109, 174, 200, 46, 52, 247, 449, 383, 437, 473, 4, 120, 482, 230, 105, 393, 254, 454, 255, 180, 99, 272, 26, 368, 189, 127, 496, 221, 60, 250, 211, 263, 410, 138, 475, 447, 292, 124, 79, 333, 10, 499, 157, 379, 118, 371, 424, 460, 40, 298, 116, 304, 43, 498, 122, 366, 25, 256, 308, 367, 341, 68, 135, 33, 491, 477, 166, 407, 129, 348, 372, 330, 210, 253, 392, 95, 320, 179, 294, 167, 227, 269, 69, 302, 306, 346, 442, 381, 243, 113, 380, 300, 71, 453, 44, 8, 396, 452, 408, 476, 235, 75, 297, 369, 22, 277, 249, 229, 38, 438, 61, 318, 332, 152};
	single_test_sort(value22, 500);

	int value23[100] = {45, 30, 4, 84, 94, 60, 66, 73, 78, 8, 25, 92, 7, 12, 29, 99, 26, 2, 43, 67, 18, 54, 28, 61, 96, 38, 70, 95, 14, 51, 35, 41, 74, 15, 83, 65, 82, 76, 93, 85, 52, 89, 49, 31, 57, 19, 20, 77, 17, 39, 11, 79, 23, 62, 55, 63, 58, 56, 40, 34, 5, 71, 3, 21, 64, 37, 69, 50, 1, 44, 32, 80, 81, 22, 16, 10, 6, 86, 46, 27, 42, 47, 75, 100, 59, 9, 53, 68, 24, 88, 36, 87, 48, 33, 91, 90, 97, 72, 13, 98};
	single_test_sort(value23, 100);

	char *test1 = "338406 890235 -452911 714544 -555734 458659 -525863 737540 -377881 -886188 61850 -160320 -906042 -341138 815503 -674972 964880 -230756 188989 647826 179106 -464016 573537 284483 -780635 -356194 541649 617988 144204 -868015 424324 -762150 -472676 -392440 -388200 -657421 -737572 908908 -793267 212098 -97124 -528079 -427208 78110 -617041 -557180 -246059 -836104 903197 154606 837970 -869653 -150824 389825 539207 -893860 -435923 -688235 -600989 427277 420104 329744 -447003 183390 -127579 -278839 92815 -96555 35656 -274878 956355 748220 -821483 -246802 -459444 313443 408557 16541 582365 -315080 -529189 -682408 -60274 130854 137759 -213492 -97040 -485312 -341694 274092 -605727 150331 275439 100546 761549 758265 -393295 -966566 -775432 663603 478980 -191608 649177 235086 6254 729744 -843350 -931555 -25138 349010 802818 775293 -647446 451858 586443 54195 195618 711645 -421649 -36279 8369 962938 -529389 -95031 -388544 376430 6094 -284012 758149 -733322 -42613 -862596 -419976 -162927 475817 290232 -513157 -302474 626221 -791253 884743 742661 241360 237929 988123 694990 -207827 720470 935349 -410570 792064 -913413 -389171 626630 -204170 -292316 671875 399554 -104757 -58031 535195 -348846 136308 -287109 891008 -602718 378871 -907533 -855146 -690890 -976494 -498328 272539 369295 -96771 -501386 596532 23388 828253 361738 -300295 613493 -278924 -494888 -166134 160353 259576 -890623 1345 -30680 -982413 869679 -81113 -527940 -165473 804067 -810397 893278 -759606 -940657 566111 -420867 -119184 -546939 -202680 600521 -636906 185252 -792140 -595524 -335011 -156026 560134 107938 -619347 -856484 -200540 135534 329916 133149 463656 570709 85876 359656 427765 908257 821527 698594 830657 -419229 -795959 -817813 -231312 -352623 -265087 -769990 709001 52226 869222 379666 237719 -898379 630296 534869 403376 454905 -314513 921441 583424 442933 -512732 818073 -130981 328379 -413550 -495996 172703 -741717 -685202 26319 -773367 66497 -29355 -984616 335839 481805 -177546 -644259 -349589 777301 41983 201980 -649235 -589518 -686678 -243116 906098 -312682 -884578 -341714 82504 576668 -70514 469268 -899162 175335 -519605 -654477 -784485 -438344 509385 962615 -952421 -478995 673412 -408237 -646203 59884 693057 795226 70127 -61526 92423 -44574 -877125 -667255 577541 701058 -399342 705937 41569 -830107 212695 -528608 -895600 725012 756695 -131672 471650 -472654 93988 -292162 277830 -373797 -820294 -270048 -308362 82921 -855271 694023 -579909 915749 630787 978004 52452 -543859 -166480 654128 356893 -593867 172269 389297 -871529 619445 -860513 -911090 -879663 755651 10325 -933694 993889 71054 -38510 512001 630930 101454 -897551 -542791 -673929 -368774 940119 -749534 906758 629109 403423 -985416 -118979 -880265 -59910 20451 989122 107873 -720628 -142500 7689 -81848 611990 -510733 743722 116701 -522814 184965 147464 -499607 75070 -10511 699496 -792867 470285 -282775 170371 849751 104518 311823 -736174 988516 685893 -409662 -49440 290886 246010 270478 -427914 -214720 926764 -197744 235994 316061 120144 -11411 739457 783719 -521782 701938 552517 -297217 826607 758232 -150443 -651323 -4821 -905617 90541 201481 -63021 -96699 214541 -485766 -12708 376897 999047 -819188 420993 -483435 -765654 -183449 943710 8975 295385 -620826 -553241 -536242 337732 -340054 -869020 -498724 953132 -846937 580510 -930036 -988556 371204 710748 -938226 -78123 754001 -488532 -496732 -352921 203140 -205797 -323083 -45676 -319529 163749 569688 857995 -344801 491731 271713 57855 -344320 -929625 -787987 989903 495113 282502 336861 -781452 289002 -11683 -224910 -557019 502918 61953 326708 -645619 -507815 189651 233147 388964 420573 415405 -17800 -549652 130116 202139 238900 -133038 -745917";
	char *test2 = "-685084 -531943 -322300 646974 -781296 -550275 55828 -382616 706286 -473671 583407 -29266 -117870 514542 -183821 476566 -32220 144265 -600881 -154128 -234481 799292 43415 -981855 143236 -494584 744581 169417 -482541 662023 355027 -605963 623392 -953698 328560 -356699 151754 -991562 231157 738344 619620 49060 -393425 452386 497313 311006 -700566 -885158 -100062 677661 -218887 -929349 704465 133197 171786 584783 891742 101061 -246609 -877958 263019 859066 842330 522320 893498 -287178 -257210 -885274 445420 750415 -314888 -704511 -752160 523235 554095 442396 -104174 -600530 -221632 -315866 -612754 604858 -16856 730066 171158 918791 -160292 236220 162340 233384 -284584 341601 -933382 47956 670348 123893 777458 -830496 -254693 651305 862110 -563519 -787912 325631 -184383 875821 -868374 -581099 -840535 -615845 942555 991427 564508 -933338 -971058 324485 411244 74287 -471456 -794434 -341195 86264 -864895 397830 -386808 -852786 849149 529488 74323 760714 -228445 -14353 775913 623764 -352218 947128 -95193 1317 733257 -230829 220187 632137 -887702 177228 928422 98051 -355568 572201 -139580 -460182 -591312 798675 -648365 -276248 281125 365726 998316 -520516 -920853 -314501 869013 -493053 -537797 970475 46142 471346 -971857 -775968 -314423 62226 473199 -613494 -60139 809053 -278061 726505 156282 858861 -981421 -144271 317059 430206 -529916 -734847 62931 -928306 -529821 405136 377564 942410 513613 -117297 -713439 584472 889596 -59975 -66455 441311 813089 -256756 -267680 -858065 -363542 348542 -916711 46003 -608446 -564963 142018 1024 100563 936709 -588799 -481946 -381309 -439618 -716502 -704885 708744 -661245 -111858 -460678 -694886 -629093 348894 33596 -837669 427834 -788496 207664 -988588 -351692 -658774 -25009 -725653 -584072 483373 -251026 -95288 307279 -214405 36918 -200554 -411456 -430138 263125 -691055 334850 -770489 -93473 316186 -229053 560677 -463070 -32095 35640 -14346 972741 927155 182271 -363495 872522 -188949 973324 955633 -557025 689451 -314016 -614699 670616 -627796 -171130 -989750 -660794 -614911 319774 677668 -212137 356969 970547 -19249 -313821 -406272 587298 -253843 -251354 -265970 -906929 -130743 719200 -235736 -332020 219727 440407 -10923 -810242 288429 369050 457309 -77867 598626 -719999 368644 -818599 -689409 598378 -400456 677385 -645652 594959 -467903 -949018 -419917 -795048 -109475 460594 -796100 506813 -953683 882817 409637 36143 155900 -245821 -737161 -634261 493756 -334362 611279 523400 4952 -591173 -536395 707412 -631684 -918974 368405 260691 -519919 -680584 26461 -156563 747254 -937734 826494 105934 132895 862066 205843 -859777 -857284 466857 -521647 829807 -154162 104032 100602 -330750 999435 336617 -176086 763927 266836 -389607 15117 -359960 131114 600840 -728746 121890 -578145 -870141 295395 -587039 589004 70305 9591 -956122 -907735 485639 -746636 24710 570394 764808 -648922 934569 -9696 -386536 -86036 166398 -879050 670450 187713 52232 -617607 165185 844009 -671823 78132 -654878 676542 -934518 -314057 663294 -279329 -792740 156477 -92679 778857 846557 -959898 966056 766740 -792796 569715 -443704 -258101 77200 495288 -898557 -649546 684354 244556 76923 547636 289293 -16195 -276497 147401 -154881 791058 -316737 -240248 658390 -247817 325720 735166 331410 375278 -83448 -935628 978016 788005 -257717 -266707 -112491 -114380 681036 -571475 353492 112506 248527 -356346 134627 339038 -834049 880616 -827807 34842 -979689 88161 -495819 704220 655690 496241 -301990 439884 -526644 275239 -669191 291094 148672 -275129 -440165 147306 725541 478198 819179 729905 -104950 -377637 -183405 357894 867788 710358 -256642 691971 -771419 90411 -931452 -208294 -611279 -255790 637628 927272 -202668 -324009 -748661 174059 45468";
	char *test3 = "713406 968147 962283 -787630 452608 168645 387798 501318 522482 285130 -204001 -520171 908614 730235 490859 67355 578881 -549462 -949258 663246 226971 -420390 254047 -248356 481679 -503572 691957 -860651 -136452 -850040 278370 -946629 -990226 -351285 135905 -566130 -248061 704362 740906 -414011 -734922 -445613 41336 -191031 -57748 432419 -751321 -942511 -23703 296273 -798370 -648452 628867 395660 -641740 -955864 648531 -917933 13776 -350527 749450 -349910 -918125 -492155 695891 -695402 -78723 861628 -920123 463910 -691276 368045 903216 315927 945234 -925015 -778653 990031 825605 905712 -447752 444100 -260114 827240 235430 -490637 469684 -275215 713752 -20580 587527 -285481 -175973 -450334 -789971 -991930 938472 102101 -672277 -628018 -684835 769556 -877153 392916 915806 -210760 968129 -677857 -161747 -782227 651238 -16459 -193119 -613020 876149 -669903 -944235 643178 558454 -51835 -623295 242630 34531 -895231 581440 41720 755293 -869835 747504 -635072 775509 -617905 125483 -864405 -762262 -171866 -618931 -355850 -935650 -859809 -595556 -825265 553497 -496772 -772392 294412 -945590 924847 633950 -407396 591382 509584 230372 -43264 660169 -208449 685882 514405 707092 -692089 -460367 832281 -968582 -881414 623876 -835857 790828 -545563 -322104 379170 -516368 -176682 485960 927613 549833 282848 888608 499781 659285 304740 489831 187626 -989983 -942861 739498 -944815 -104079 559794 73509 83447 -453603 -634097 -686343 424917 348210 -375238 718441 812516 -574697 -204151 -155873 982686 -430281 945447 -136701 -19569 -40788 -708612 940714 -83196 725234 951496 -310248 915411 325612 500946 485834 399638 713506 -395816 392543 -251003 597030 238195 396481 -185431 -5853 126611 -624132 228756 -977404 -785541 567710 337495 45420 -20563 348671 -944856 201553 583510 -675459 938445 -553808 -953582 -407877 -949768 -486374 -399590 -809832 -821050 -814400 -782155 -182562 -422913 727862 726111 -560589 -866006 -507154 -640608 -545733 880393 278559 434707 728722 603338 408333 -766764 651649 474974 -578610 -975037 -150677 -175327 295360 35000 640732 44898 -93058 -178930 437277 -835785 481125 -907981 299769 -208439 511476 603060 -700601 -83324 598926 -337033 -303378 -813737 -684 767856 -644522 641198 516642 752221 -579871 702821 -52391 54935 959760 -727651 970217 -350642 -702964 -301937 -332499 -155755 312115 -594983 -243322 -90924 307921 776440 -725556 730160 620585 -851351 -230715 820432 -20834 -489092 298372 -389941 762713 440901 303237 -83825 181195 242152 234785 721077 874972 -461846 873737 544312 -965825 -125888 -757376 -466003 -275134 -868912 -167285 787133 -647480 -986484 -683659 -916549 -138699 -915959 150415 546125 -979335 968821 801583 512550 376310 277019 803968 -345948 60846 -521 832363 935838 -131516 929708 121041 -161920 -570336 735456 417663 502267 832435 -524455 -195887 -277009 435424 -925845 785486 -911737 -721964 213412 -161347 -996311 245937 -897453 -978151 -372399 764344 -637682 -870752 -812114 531406 -193821 -829406 -327028 647442 -847192 860415 601192 700191 -860551 -960248 124697 -609652 -400313 -458491 52031 591546 -170776 -389268 -544188 -100284 873708 46978 318873 -888171 -602687 835976 -503344 -876094 664516 707987 -733202 -601685 -449488 -534745 -561368 432721 -55866 770841 500731 705989 889818 508581 -228428 -105355 406144 -897207 8104 705815 -243285 858694 -312134 -302546 -396435 166586 -844439 151928 887073 -75093 -578242 -582441 -237468 817243 771245 17900 295964 -42610 864911 -806503 170692 -971574 446195 -520796 -410078 -483195 -882701 -272102 597478 -713881 160177 629551 539032 -387697 51468 -250005 -600889 472521 423142 -66902 -867848 121714 294269 928918 -435524 548382 -812400 775744 -159921 -587431 -824491 -500297 -1141 225076 160144";
	char *test4 = "-885558 922966 -335816 -180778 -958532 -846617 212437 -286858 -242277 -912862 218438 598198 328063 -844950 -77247 -528088 251963 -711792 209002 391812 146137 212584 -731945 535022 -699119 -498341 610887 739660 -550981 -254399 -498837 -378831 -68449 428332 203093 -794165 446957 -539905 19062 237594 546739 -802418 723085 -286084 -827811 -73005 551025 367125 -274201 648130 -708105 -312499 -777811 -26794 -460631 216992 875638 206311 -651066 -24967 -271226 558725 919884 662159 765256 966381 5390 629041 879003 -366954 -802987 -165286 -738253 -407697 -568071 -642182 660702 361395 -869231 -305400 322427 278176 -412658 477010 669172 -788799 -39411 959669 -267974 723587 -389794 -557241 613090 -839557 732502 431816 -458253 -858193 -651010 933775";
	char *test5 = "-266533 521157 463893 440897 534998 397591 -195157 137281 950303 337156 -394141 118341 -169906 -867298 -84978 838091 883377 101917 892513 960073 -346568 -319831 -501734 -368086 -407139 277238 867396 496843 -886211 479361 -48606 -326253 99488 432798 -512898 -215013 -999573 -504735 986793 14865 -226341 998234 -674191 928382 -813511 -319369 312771 -403844 328940 266244 87950 701681 -947190 523169 -22856 -733466 -899514 360791 -657245 -161503 -202267 -381895 -664572 362856 553765 -997090 -675790 536844 104292 118332 -158958 -280434 21857 66449 -846699 642894 -283599 302975 406191 555932 677982 78780 608969 -949713 318047 -641368 -391653 656791 439955 862283 280042 -31791 159928 -492333 182356 -788293 -232796 -327718 310821 123852";
	char *test6 = "-869204 -134445 325891 518727 304362 -386723 849201 212532 971439 320533 -812157 216236 866578 -730043 -817635 852362 -844551 526805 160093 -135994 602623 597063 176184 -224000 191023 -671680 55790 839919 -590112 -136870 -110874 826496 -747852 -200532 875358 168255 -812743 -24348 -519271 -419911 629058 425354 948798 732367 -479245 -421832 -421069 372804 9295 -837999 -509986 123258 843279 547332 -41987 -76832 -770840 614528 472556 552525 -476877 454192 -837047 -166252 510589 -422034 714954 825380 -585398 -956177 507944 -785274 992507 -487056 114276 182309 -268043 910868 308159 -662744 -964085 -457559 91679 -416639 29425 -688865 -421437 388980 -927687 -988732 356463 392256 844602 385051 652706 -461410 -331018 -202853 -747504 -103506";
}

void debug()
{
	t_stacks *stacks = new_stacks();
	int arr[500];
	int rev[500];
	int value_8[] = {2, 3, 1};
	stacks = new_stacks();
	for (size_t i = 0; i < 3; ++i)
		push_stack(stacks, value_8[i], true);
	astar_sort_func(stacks);
	int res8[500] = {1, 2, 3};
	export_list(stacks->stack_a, arr, rev);
	TEST_ASSERT_EQUAL_INT_ARRAY(res8, arr, 3);
	close_stacks(&stacks);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_stack);
	RUN_TEST(test_atoi);
	////RUN_TEST(test_insert_value_to_stacks);
	RUN_TEST(test_push_swap);
	RUN_TEST(test_stack_op);
	RUN_TEST(test_plan);
    RUN_TEST(test_astar_sort);
	//RUN_TEST(debug);
	return (UNITY_END());
}
