/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:41:45 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/24 10:31:38 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

// Helper function of `new_stacks` to create a new `stack`.
// The only caller of this function is `new_stacks` who will free the memory on error.
// The `max` and `min` are only updated when `push`, so after `pop`, it may be wrong. 
static t_stack	*new_stack(char label)
{
	t_stack	*stack;
	int		*arr;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->root = NULL;
	stack->label = label;
	stack->len = 0;
	stack->max = INT_MIN;
	stack->min = INT_MAX;
	return (stack);
}

// To create a new `stacks`.
t_stacks	*new_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = new_stack('a');
	if (!stacks->stack_a)
		return (NULL);
	stacks->stack_b = new_stack('b');
	if (!stacks->stack_b)
		return (NULL);
	return (stacks);
}

// Helper function of `free_helper` to free the `stack`.
static void	free_helper_stack(t_stack **stack)
{
	t_node	*curr;
	t_node	*temp;

	if (*stack)
	{
		if ((*stack)->root)
		{
			curr = (*stack)->root->next;
			while (curr != (*stack)->root)
			{
				temp = curr->next;
				free(curr);
				curr = temp;
			}
			free((*stack)->root);
			(*stack)->root = NULL;
		}
		free(*stack);
		*stack = NULL;
	}
}

// Free the whole `stacks`,
// and designed for anti double free by checking NULL before free.
t_stacks	*close_stacks(t_stacks **stacks)
{
	if (*stacks)
	{
		free_helper_stack(&((*stacks)->stack_a));
		free_helper_stack(&((*stacks)->stack_b));
	}
	free(*stacks);
	return (NULL);
}
