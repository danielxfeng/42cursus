/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:08:35 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/27 09:23:51 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

void			get_best_plan_ab(t_stacks *stacks, size_t idx,
					t_move_plan_ab *best_plan);

// Returns the plan of next move from `stack a` to `stack b`.
static t_move_plan_ab	get_next_move_plan_ab(t_stacks *stacks,
		t_move_plan_ab *next_plan)
{
	size_t			i;
	size_t			j;
	int				cheapest;
	t_move_plan_ab	plans[60];

	i = 0;
	cheapest = INT_MAX;
	while (i < 30 && i < cheapest && i < stacks->stack_a->len / 2)
	{
		get_best_plan_ab(stacks, i, &(plans[i]));
		if (plans[i].total_times < cheapest)
			cheapest = plans[i].total_times;
		get_best_plan_ab(stacks, stacks->stack_a->len - 1 - i, &(plans[60 - 1 - i]));
		if (plans[60 - 1 - i].total_times < cheapest)
			cheapest = plans[60 - 1 - i].total_times;
		++i;
	}
	j = 0;
	while (j < i)
	{
		if (plans[j].total_times == cheapest)
			return (*next_plan = plans[j]);
		if (plans[60 - 1 - j].total_times == cheapest)
			return (*next_plan = plans[60 - 1 - j]);
		++j;
	}
}

// Perform move from `stack a` to `stack b`.
static void	perform_move_ab(t_stacks *stacks, t_move_plan_ab *plan)
{
	size_t	i;
	void	(*double_func)(t_stacks *stacks);
	void	(*single_func)(t_stacks *stacks, bool is_a);

	i = 0;
	double_func = rrr;
	if (plan->a_is_r)
		double_func = double_r;
	while (i++ < plan->double_op_times)
		double_func(stacks);
	i = 0;
	single_func = rr;
	if (plan->a_is_r)
		single_func = r;
	while (i++ < plan->a_op_times - plan->double_op_times)
		single_func(stacks, true);
	i = 0;
	single_func = rr;
	if (plan->b_is_r)
		single_func = r;
	while (i++ < plan->b_op_times - plan->double_op_times)
		single_func(stacks, false);
	p(stacks, false);
}

// Sort the `stack_b`
static int sort_stack_b(t_stacks *stacks)
{
	size_t i;
	int max_idx_in_b;
	
	max_idx_in_b = get_idx_by_value(stacks, stacks->stack_b->max->value, false);
	i = 0;
	while (max_idx_in_b <= stacks->stack_b->len / 2 && i++ < max_idx_in_b)
		r(stacks, false);
	while (max_idx_in_b > stacks->stack_b->len / 2
		&& i++ < stacks->stack_b->len - max_idx_in_b)
		rr(stacks, false);
	return (i - 1);
}

// The function which applies the sort algorithm.
int	astar_sort_func(t_stacks *stacks)
{
	int				total_times;
	t_move_plan_ab	next_plan;

	total_times = 0;
	while (stacks->stack_a->len)
	{
		get_next_move_plan_ab(stacks, &next_plan);
		perform_move_ab(stacks, &next_plan);
		total_times += next_plan.total_times;
	}
	total_times += sort_stack_b(stacks) + stacks->stack_b->len;
	while (stacks->stack_b->len)
		p(stacks, true);
	ft_printf("Total cost for debug: %d\n", total_times);
	return (total_times);
}
