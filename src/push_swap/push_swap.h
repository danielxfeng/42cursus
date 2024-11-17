/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:32:53 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/17 19:53:32 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>

typedef struct s_node t_node;

// Maintains a data structure of `stack`.
// `root` is the int list, as well as a `circular doubly linked list`.
// `len` is the length of `stack`.
// `label` is either 'a' or 'b'.
typedef struct s_stack
{
    t_node *root;
    size_t len;
    char label;
} t_stack;

typedef struct s_stacks
{
    t_stack *stack_a;
    t_stack *stack_b;
} t_stacks;

// Represents a node of `circular doubly linked list`.
typedef struct s_node
{
    int value;
    t_node *prev;
    t_node *next;
} t_node;

t_stacks *new_stacks();
t_stacks *free_helper(t_stacks **stacks);
char s(t_stacks *stacks, bool is_a);
char r(t_stacks *stacks, bool is_a);
char rr(t_stacks *stacks, bool is_a);
char p(t_stacks *stacks, bool is_a);
size_t get_len(t_stacks *stacks, bool is_a);
t_stacks *push_stack(t_stacks *stacks, int n, bool is_a);
t_node *push_back(t_stack *stack, int value);
t_node *insert_front(t_stack *stack, t_node *node);
t_node *pop_front(t_stack *stack);

#endif
