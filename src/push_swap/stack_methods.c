/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:33:08 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/16 21:51:41 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_curr_stack(t_stacks *stacks, bool is_a);

// To get the raw idx of `stack-arr`.
size_t get_raw_idx(t_stack *stack, size_t idx)
{
    return ((stack-> head + idx) % stack->capacity);
}

// To swap 2 elements ont the top of `stack`.
// Returns the label of `stack`.
char s(t_stacks *stacks, bool is_a)
{
    t_stack *stack;
    int temp;

    stack = get_curr_stack(stacks, is_a);
    temp = stack->arr[get_raw_idx(stack, 0)];
    stack->arr[get_raw_idx(stack, 0)] = stack->arr[get_raw_idx(stack, 1)];
    stack->arr[get_raw_idx(stack, 1)] = temp;
    return (stack->label);
}

// To swap the top and bottom elements of the `stack`.
// Returns the label of `stack`.
char r(t_stacks *stacks, bool is_a)
{
    t_stack *stack;

    stack = get_curr_stack(stacks, is_a);
    stack->head = get_raw_idx(stack, 1);
    return (stack->label);
}

// To swap the bottom and top elements of the `stack`.
// Returns the label of `stack`.
char rr(t_stacks *stacks, bool is_a)
{
    t_stack *stack;

    stack = get_curr_stack(stacks, is_a);
    stack->head = get_raw_idx(stack, stack->len - 1);
    return (stack->label);
}

// To move the top element of opposite's `stack` to curr's `stack`.
// Returns the label of `stack`.
char p(t_stacks *stacks, bool is_a)
{
    t_stack *curr_stack;
    t_stack *opposite_stack;
    int temp;
    

    curr_stack = stacks->stack_a;
    opposite_stack = stacks->stack_b;
    if (!is_a)
    {
        curr_stack = stacks->stack_b;
        opposite_stack = stacks->stack_a;
    }
    temp = opposite_stack->arr[get_raw_idx(opposite_stack, 0)];
    curr_stack->arr[get_raw_idx(curr_stack, curr_stack->head - 1)] = temp;
    curr_stack->head = get_raw_idx(curr_stack, curr_stack->head - 1);
    ++(curr_stack->len);
    opposite_stack->head = get_raw_idx(opposite_stack, 1);
    --(opposite_stack->len);
    return (curr_stack->label);
}
