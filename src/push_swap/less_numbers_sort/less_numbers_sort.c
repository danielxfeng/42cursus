/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_numbers_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:04:11 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/05 14:23:08 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

static int	sort_4_5_elems(t_stacks *stacks)
{
	if (stacks->stack_a->len > 0)
		return (0);
	return (1);
}

// A function to sort a list with only 3 elements.
// It's a very bad implementation, so sorry to do it for NORM.
// But it works because when evaluate `if` clause, `++c` will be executed
// after all previous conditions are `true`, which is what we want.
// Note we can not use `c++` because when `c = 0`, `c++` returns `0`.
static int	sort_3_elems(t_stacks *stacks)
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

// A function to sort a list with less than 6 elements.
int	less_numbers_sort(t_stacks *stacks)
{
	if (stacks->stack_a->len <= 1)
		return (0);
	if (stacks->stack_a->len == 2)
	{
		if (stacks->stack_a->root->value < stacks->stack_a->root->next->value)
			return (0);
		s(stacks, true);
		return (1);
	}
	if (stacks->stack_a->len == 3)
		return (sort_3_elems(stacks));
	return (sort_4_5_elems(stacks));
}
