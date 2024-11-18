/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_method_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:49:46 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/18 09:41:14 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A helper function for methods.
t_stack *get_curr_stack(t_stacks *stacks, bool is_a)
{
    t_stack *stack;

    stack = stacks->stack_a;
    if (!is_a)
        stack = stacks->stack_b;
    return (stack);  
}

// Returns the length of `stack`.
size_t get_len(t_stacks *stacks, bool is_a)
{
    t_stack *stack;
    
    stack = get_curr_stack(stacks, is_a);
    return (stack->len);
}

// Push an int to `stack`; Duplicated value is not allowed.
bool push_stack(t_stacks *stacks, int n, bool is_a)
{
    t_stack *stack;
    
    stack = get_curr_stack(stacks, is_a);
    if (has(stack, n) || !push_back(stack, n))
        return (false);
    return (true);
}
