/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:33:08 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/24 10:32:55 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"

t_stack	*get_curr_stack(t_stacks *stacks, bool is_a);

// Helper function for `rr`, returns the label of `stack`.
static char	rotate_rr(t_stacks *stacks, bool is_a)
{
	t_stack	*stack;

	stack = get_curr_stack(stacks, is_a);
	stack->root = stack->root->prev;
	return (stack->label);
}

// To swap the bottom and top elements of the `stack`.
void rr(t_stacks *stacks, bool is_a)
{
	char label;
		
	label = rotate_rr(stacks, is_a);
	ft_printf("%s%c%c", "rr", label, '\n');
}

// To swap the bottom and top elements of the `stack`s.
void rrr(t_stacks *stacks)
{
	char label;
		
	rotate_rr(stacks, true);
	rotate_rr(stacks, false);
	ft_printf("rrr\n");
}
