/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:33:08 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/26 15:35:20 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../push_swap.h"

t_stack		*get_curr_stack(t_stacks *stacks, bool is_a);

// Helper function for `r`, returns the label of `stack`.
static char	rotate_r(t_stacks *stacks, bool is_a)
{
	t_stack	*stack;
	t_node	*curr;

	stack = get_curr_stack(stacks, is_a);
	curr = stack->root;
	stack->root = stack->root->next;
	return (stack->label);
}

// To rotate the stack, swap the top and bottom elements of the `stack`.
void	r(t_stacks *stacks, bool is_a)
{
	char	label;

	label = rotate_r(stacks, is_a);
	ft_printf("%c%c%c", 'r', label, '\n');
}

// To rotate the stack, swap the top and bottom elements of the 2 `stack`s.
void	double_r(t_stacks *stacks)
{
	char	label;

	rotate_r(stacks, true);
	rotate_r(stacks, false);
	ft_printf("rr\n");
}
