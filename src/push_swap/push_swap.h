/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:32:53 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/16 21:42:13 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>

// Maintains a data structure of `stack`.
// `arr` is the int list, as well as a circular `stack`.
// `len` is the length of `stack`.
// `capacity` is the capacity of `stack`.
// `label` is either 'a' or 'b'.
// `head` is the idx of the head element of the `stack`.
typedef struct s_stack
{
    int *arr;
    size_t head;
    size_t len;
    size_t capacity;
    char label;
} t_stack;

typedef struct s_stacks
{
    t_stack *stack_a;
    t_stack *stack_b;
} t_stacks;

t_stacks *new_stacks(size_t len);
t_stacks *free_helper(t_stacks **stacks);
char s(t_stacks *stacks, bool is_a);
char r(t_stacks *stacks, bool is_a);
char rr(t_stacks *stacks, bool is_a);
char p(t_stacks *stacks, bool is_a);
size_t get_raw_idx(t_stack *stack, size_t idx);
size_t get_len(t_stacks *stacks, bool is_a);
void push_stack(t_stacks *stacks, int n, bool is_a);

#endif
