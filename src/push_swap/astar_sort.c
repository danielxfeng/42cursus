/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:08:35 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/23 20:35:13 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	cal_cost_in_b(t_stacks *stacks, bool is_r, int value)
{
	size_t	i;
	t_node	*node;

	if (!stacks->stack_b->root)
		return (0);
	i = 0;
	node = stacks->stack_b->root;
	while (i < stacks->stack_b->len)
	{
		if (value > node->value)
			return (i);
		if (is_r)
			node = node->next;
		else
			node = node->prev;
		++i;
	}
	return (i);
}

void	generate_move_plan_ab(t_stacks *stacks, size_t i, bool is_r,
		t_move_plan_ab *plan)
{
	plan->is_r = is_r;
	if (is_r)
		plan->a_op_times = i;
	else
		plan->a_op_times = stacks->stack_a->len - 1 - i;
	plan->b_op_times = cal_cost_in_b(stacks, is_r, get_value_from_stack(stacks,
				true, i));
	if (plan->a_op_times > plan->b_op_times)
	{
		plan->total_times = plan->a_op_times;
		plan->double_op_times = plan->b_op_times;
	}
	else
	{
		plan->total_times = plan->b_op_times;
		plan->double_op_times = plan->a_op_times;
	}
}

void	get_plan(t_stacks *stacks, size_t i, t_move_plan_ab *curr_plan)
{
	t_move_plan_ab	r_plan;
	t_move_plan_ab	rr_plan;

	generate_move_plan_ab(stacks, i, true, &r_plan);
	generate_move_plan_ab(stacks, i, false, &rr_plan);
	if (r_plan.total_times > rr_plan.total_times)
		*curr_plan = rr_plan;
	else
		*curr_plan = r_plan;
}

void	apply_double_move(t_stacks *stacks, bool is_r, size_t times)
{
	size_t	i;

	i = 0;
	while (i < times)
	{
		if (is_r)
		{
			r(stacks, true);
			r(stacks, true);
			ft_printf("rr\n");
		}
		else
		{
			rr(stacks, true);
			rr(stacks, false);
			ft_printf("rrr\n");
		}
		++i;
	}
}

void	apply_single_move(t_stacks *stacks, bool is_a, bool is_r, size_t times)
{
	size_t	i;

	i = 0;
	while (i < times)
	{
		if (is_r)
		{
			r(stacks, is_a);
			if (is_a)
				ft_printf("ra\n");
			else
				ft_printf("rb\n");
		}
		else
		{
			rr(stacks, is_a);
			if (is_a)
				ft_printf("rra\n");
			else
				ft_printf("rrb\n");
		}
		++i;
	}
}

void	move_from_a(t_stacks *stacks, size_t i)
{
	t_move_plan_ab	curr_plan;

	get_plan(stacks, i, &curr_plan);
	apply_double_move(stacks, curr_plan.is_r, curr_plan.double_op_times);
	if (curr_plan.a_op_times > curr_plan.b_op_times)
		apply_single_move(stacks, true, curr_plan.is_r, curr_plan.total_times
			- curr_plan.double_op_times);
	if (curr_plan.a_op_times < curr_plan.b_op_times)
		apply_single_move(stacks, false, curr_plan.is_r, curr_plan.total_times
			- curr_plan.double_op_times);
	p(stacks, true);
	ft_printf("pa\n");
}

int	cal_cost(t_stacks *stacks, size_t i)
{
	t_move_plan_ab	r_plan;
	t_move_plan_ab	rr_plan;

	generate_move_plan_ab(stacks, i, true, &r_plan);
	generate_move_plan_ab(stacks, i, true, &rr_plan);
	if (r_plan.total_times > rr_plan.total_times)
		return (rr_plan.total_times);
	return (r_plan.total_times);
}

size_t	get_cheapest_item(int *costs, size_t idx)
{
	size_t	i;
	size_t	min;

	i = 0;
	min = INT_MAX;
	while (i <= idx)
	{
		if (min == INT_MAX || costs[i] < costs[min])
			min = i;
		if (costs[60 - 1 - i] < costs[min])
			min = 60 - 1 - i;
		++i;
	}
	return (min);
}

size_t	find_next_node(t_stacks *stacks)
{
	size_t	i;
	int		costs[60];
	size_t	idxs[60];

	i = 0;
	while (i < 30 && i < stacks->stack_a->len / 2 + 1)
	{
		idxs[i] = i;
		costs[i] = cal_cost(stacks, i);
		idxs[60 - 1 - i] = stacks->stack_a->len - 1 - i;
		costs[60 - 1 - i] = cal_cost(stacks, stacks->stack_a->len - 1 - i);
		if (costs[i] == INT_MAX || costs[get_cheapest_item(costs, i)] < i)
			break ;
		++i;
	}
	return (get_cheapest_item(costs, i));
}

void	astar_sort_func(t_stacks *stacks)
{
	while (stacks->stack_a->len)
		move_from_a(stacks, find_next_node(stacks));
	while (stacks->stack_b->len)
	{
		p(stacks, false);
		ft_printf("pb\n");
	}
}