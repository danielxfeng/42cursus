/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:43:10 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/26 17:25:39 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// To calculate the cost that `insert` a number to sorted list `stack b`.
static int	cal_cost_to_b(t_stacks *stacks, size_t idx)
{
	int		n;
	size_t	i;
	size_t	start;
	t_node	*curr;

	if (stacks->stack_b->len <= 2)
		return (0);
	n = get_value_from_stack(stacks, true, idx);
	if (stacks->stack_b->max)
		start = get_idx_by_value(stacks, stacks->stack_b->max->value, false);
	else
		return (0);
	i = 0;
	curr = stacks->stack_b->max;
	while (i++ < stacks->stack_b->len)
	{
		if (n > curr->value)
			return ((stacks->stack_b->len + start + i - 1)
				% stacks->stack_b->len);
		curr = curr->next;
	}
	return (start);
}

// Fill the plan with `stack a` related properties.
static void	fill_plan_a(t_move_plan_ab *plan, t_stacks *stacks, size_t idx,
		bool is_r)
{
	plan->idx = idx;
	plan->a_is_r = is_r;
	if (is_r)
		plan->a_op_times = idx;
	else
		plan->a_op_times = stacks->stack_a->len - idx;
}

// Fill the plan with `stack b` related properties,
// and calculate the `total times`.
static void	fill_plan_b(t_move_plan_ab *plan, t_stacks *stacks, int cost,
		bool is_r)
{
	plan->b_is_r = is_r;
	if (is_r)
		plan->b_op_times = cost;
	else
		plan->b_op_times = stacks->stack_b->len - cost;
	if (plan->a_is_r != plan->b_is_r)
	{
		plan->double_op_times = 0;
		plan->total_times = plan->a_op_times + plan->b_op_times;
	}
	else
	{
		if (plan->a_op_times >= plan->b_op_times)
		{
			plan->double_op_times = plan->b_op_times;
			plan->total_times = plan->a_op_times;
		}
		else
		{
			plan->double_op_times = plan->a_op_times;
			plan->total_times = plan->b_op_times;
		}
	}
	plan->total_times += 1;
}

// To generate and compare different moving plans, and select the best one.
void	get_best_plan_ab(t_stacks *stacks, size_t idx,
		t_move_plan_ab *best_plan)
{
	int				b_cost;
	size_t			i;
	t_move_plan_ab	plans[4];

	b_cost = cal_cost_to_b(stacks, idx);
	fill_plan_a(&(plans[0]), stacks, idx, true);
	fill_plan_b(&(plans[0]), stacks, b_cost, true);
	fill_plan_a(&(plans[1]), stacks, idx, true);
	fill_plan_b(&(plans[1]), stacks, b_cost, false);
	fill_plan_a(&(plans[2]), stacks, idx, false);
	fill_plan_b(&(plans[2]), stacks, b_cost, true);
	fill_plan_a(&(plans[3]), stacks, idx, false);
	fill_plan_b(&(plans[3]), stacks, b_cost, false);
	*best_plan = plans[0];
	i = 1;
	while (i < 4)
	{
		if (plans[i].total_times < best_plan->total_times)
			*best_plan = plans[i];
		++i;
	}
}
