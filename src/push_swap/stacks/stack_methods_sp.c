/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods_sp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:33:08 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/24 10:32:28 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"

t_stack	*get_curr_stack(t_stacks *stacks, bool is_a);
t_node	*insert_front(t_stack *stack, t_node *node);
t_node	*pop_front(t_stack *stack);

// Helper function of `s`, returns the label of `stack`.
static char	swap(t_stacks *stacks, bool is_a)
{
	t_stack	*stack;
	int		temp;

	stack = get_curr_stack(stacks, is_a);
	temp = stack->root->value;
	stack->root->value = stack->root->next->value;
	stack->root->next->value = temp;
	return (stack->label);
}

// To swap 2 elements ont the top of `stack`.
void s(t_stacks *stacks, bool is_a)
{
	char label;

	label = swap(stacks, is_a);
	ft_printf("%c%c%c", 's', label, '\n');
}

void ss(t_stacks *stacks)
{
	swap(stacks, true);
	swap(stacks, false);
	ft_printf("ss\n");
}

// Helper function for `p`, returns the label of `stack`.
static char	p_helper(t_stacks *stacks, bool is_a)
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
	if (temp->value < curr_stack->min)
		curr_stack->min = temp->value;
	if (temp->value > curr_stack->max)
		curr_stack->max = temp->value;	
	return (curr_stack->label);
}

// To move the top element of opposite's `stack` to curr's `stack`.
void p(t_stacks *stacks, bool is_a)
{
	char label;

	label = p_helper(stacks, is_a);
	ft_printf("%c%c%c", 'p', label, '\n');
}
