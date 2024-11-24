/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:49:46 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/24 10:31:56 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node					*push_back(t_stack *stack, int value);
bool					has(t_stack *stack, int n);

// A helper function for methods.
t_stack	*get_curr_stack(t_stacks *stacks, bool is_a)
{
	t_stack	*stack;

	stack = stacks->stack_a;
	if (!is_a)
		stack = stacks->stack_b;
	return (stack);
}

// Get the value from a stack by index.
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
