/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_method_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:49:46 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/23 16:07:40 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A helper function for methods.
t_stack	*get_curr_stack(t_stacks *stacks, bool is_a)
{
	t_stack	*stack;

	stack = stacks->stack_a;
	if (!is_a)
		stack = stacks->stack_b;
	return (stack);
}

// Get the value from a stack.
int get_value_from_stack(t_stacks *stacks, bool is_a, size_t idx)
{
	t_stack	*stack;
	t_node *curr;
	size_t i;

	stack = get_curr_stack(stacks, is_a);
	if (stack->len <= idx)
		return (INT_MAX);
	if (idx == 0)
		return (stack->root->value);
	i = 1;
	curr = stack->root->next;
	while (i++ < idx)
		curr = curr->next;
	return (curr->value);
}

// Returns the length of `stack`.
size_t	get_len(t_stacks *stacks, bool is_a)
{
	t_stack	*stack;

	stack = get_curr_stack(stacks, is_a);
	return (stack->len);
}

// Push an int to `stack`; Duplicated value is not allowed.
bool	push_stack(t_stacks *stacks, int n, bool is_a)
{
	t_stack	*stack;

	stack = get_curr_stack(stacks, is_a);
	if (has(stack, n) || !push_back(stack, n))
		return (false);
	if (n > stack->max)
		stack->max = n;
	if (n < stack->min)
		stack->min = n;
	return (true);
}
