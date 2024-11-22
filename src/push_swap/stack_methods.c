/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:33:08 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/22 11:10:23 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_curr_stack(t_stacks *stacks, bool is_a);

// To swap 2 elements ont the top of `stack`.
// Returns the label of `stack`.
char	s(t_stacks *stacks, bool is_a)
{
	t_stack	*stack;
	int		temp;

	stack = get_curr_stack(stacks, is_a);
	temp = stack->root->value;
	stack->root->value = stack->root->next->value;
	stack->root->next->value = temp;
	return (stack->label);
}

// To swap the top and bottom elements of the `stack`.
// Returns the label of `stack`.
char	r(t_stacks *stacks, bool is_a)
{
	t_stack	*stack;
	t_node	*curr;

	stack = get_curr_stack(stacks, is_a);
	curr = stack->root;
	stack->root = stack->root->next;
	return (stack->label);
}

// To swap the bottom and top elements of the `stack`.
// Returns the label of `stack`.
char	rr(t_stacks *stacks, bool is_a)
{
	t_stack	*stack;

	stack = get_curr_stack(stacks, is_a);
	stack->root = stack->root->prev;
	return (stack->label);
}

// To move the top element of opposite's `stack` to curr's `stack`.
// Returns the label of `stack`.
char	p(t_stacks *stacks, bool is_a)
{
	t_stack	*curr_stack;
	t_stack	*opposite_stack;
	t_node	*temp;

	curr_stack = stacks->stack_a;
	opposite_stack = stacks->stack_b;
	if (!is_a)
	{
		curr_stack = stacks->stack_b;
		opposite_stack = stacks->stack_a;
	}
	temp = pop_front(opposite_stack);
	insert_front(curr_stack, temp);
	return (curr_stack->label);
}
