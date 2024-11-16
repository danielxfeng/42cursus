/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:41:45 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/16 21:56:15 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// Helper function of `new_stacks` to create a new `stack`.
// The only caller of this function is `new_stacks` who will free the memory on error.
static t_stack *new_stack(size_t capacity, char label)
{
    t_stack *stack;
    int *arr;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->head = 0;
    stack->label = label;
    stack->len = 0;
    stack->capacity = capacity;
    stack->arr = malloc(capacity * sizeof(int));
    if (!(stack->arr))
        return (NULL);
    return (stack);
}

// To create a new `stacks`.
t_stacks *new_stacks(size_t capacity)
{
    t_stacks *stacks;

    stacks = malloc(sizeof(t_stacks));
    if (!stacks)
        return (NULL);
    stacks->stack_a = new_stack(capacity, 'a');
    if (!stacks->stack_a)
        return (free_helper(&stacks));
    stacks->stack_b = new_stack(capacity, 'b');
    if (!stacks->stack_b)
        return (free_helper(&stacks));
    return (stacks);
}

// Helper function of `free_helper` to free the `stack`.
static void free_helper_stack (t_stack **stack)
{
    if (*stack)
    {
        if ((*stack)->arr)
        {
            free((*stack)->arr);
            (*stack)->arr = NULL;
        }
        free(*stack);
        *stack = NULL;
    }
}

// Free the whole `stacks`, and designed for anti double free by checking NULL before free.
t_stacks *free_helper(t_stacks **stacks)
{
    if (*stacks)
    {
        free_helper_stack(&((*stacks)->stack_a));
        free_helper_stack(&((*stacks)->stack_b));        
    }
    free(*stacks);
    return (NULL);
}
