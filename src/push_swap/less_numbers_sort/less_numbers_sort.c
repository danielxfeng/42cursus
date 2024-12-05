/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_numbers_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:04:11 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/05 18:19:10 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

int	sort_3_elems(t_stacks *stacks);
int	sort_4_5_elems(t_stacks *stacks);

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
