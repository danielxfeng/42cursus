/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:17:07 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/05 18:19:01 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// A function to sort a list with only 3 elements.
// It's a very bad implementation, so sorry to do it for NORM.
// But it works because when evaluate `if` clause, `++c` will be executed
// after all previous conditions are `true`, which is what we want.
// Note we can not use `c++` because when `c = 0`, `c++` returns `0`.
int	sort_3_elems(t_stacks *stacks)
{
	t_node	**n;
	int		c;

	c = 0;
	n = &(stacks->stack_a->root);
	if ((*n)->value < (*n)->prev->value && (*n)->prev->value < (*n)->next->value
		&& ++c)
		rr(stacks, true);
	if ((*n)->value > (*n)->next->value && (*n)->next->value > (*n)->prev->value
		&& ++c)
		r(stacks, true);
	if ((*n)->value > (*n)->next->value && (*n)->value < (*n)->prev->value
		&& ++c)
		s(stacks, true);
	if ((*n)->value < (*n)->next->value && (*n)->value > (*n)->prev->value
		&& ++c)
		rr(stacks, true);
	if ((*n)->value > (*n)->prev->value && (*n)->prev->value > (*n)->next->value
		&& ++c)
		r(stacks, true);
	return (c);
}

static void	set_min_ptr(t_stacks *stacks)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = stacks->stack_a->root;
	while (i < (int)stacks->stack_a->len)
	{
		if (i == 0 || curr->value < stacks->stack_a->min->value)
			stacks->stack_a->min = curr;
		++i;
		curr = curr->next;
	}
}

static void	get_best_plan_ba(t_stacks *stacks, t_move_plan_ab *plan)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = stacks->stack_a->min;
	while (i < (int)stacks->stack_a->len)
	{
		if (stacks->stack_b->root->value < curr->value)
			break ;
		++i;
		curr = curr->next;
	}
	i = (i + get_idx_by_value(stacks, stacks->stack_a->min->value, true))
		% stacks->stack_a->len;
	plan->a_is_r = true;
	if ((int)stacks->stack_a->len - i < i)
	{
		plan->a_is_r = false;
		i = (int)stacks->stack_a->len - i;
	}
	plan->a_op_times = i;
}

static int	sort_stack_a(t_stacks *stacks)
{
	int	i;
	int	min_idx;

	min_idx = get_idx_by_value(stacks, stacks->stack_a->min->value, true);
	i = 0;
	while (i++ < min_idx)
		r(stacks, true);
	return (i - 1);
}

int	sort_4_5_elems(t_stacks *stacks)
{
	int				c;
	int				i;
	t_move_plan_ab	plan;

	c = 0;
	while ((int)stacks->stack_a->len > 3 && ++c)
		p(stacks, false);
	c += sort_3_elems(stacks);
	set_min_ptr(stacks);
	while (stacks->stack_b->len)
	{
		get_best_plan_ba(stacks, &plan);
		i = 0;
		while (i++ < plan.a_op_times)
		{
			if (plan.a_is_r && ++c)
				r(stacks, true);
			else if (++c)
				rr(stacks, true);
		}
		p(stacks, true);
		++c;
	}
	return (c + sort_stack_a(stacks));
}
