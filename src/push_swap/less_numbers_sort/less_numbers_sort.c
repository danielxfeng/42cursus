/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_numbers_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:04:11 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/04 12:44:07 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

int	sort_3_elems_stack(t_stacks *stacks)
{
	t_node	*n;
	int		c;

	c = 0;
	n = stacks->stack_a->root;
	if (n->value < n->next->value && n->prev->value < n->next->value && c++)
		rr(stacks, true);
	if (n->value > n->next->value && n->next->value > n->prev->value && c++)
		r(stacks, true);
	if (n->value > n->next->value && n->value < n->prev->value && c++)
		s(stacks, true);
	if (n->value < n->next->value && n->value > n->prev->value && c++)
		rr(stacks, true);
	if (n->value > n->prev->value && n->prev->value > n->next->value && c++)
		r(stacks, true);
	return (c);
}

int	sort_less_6_elems_stack(t_stacks *stacks)
{
}