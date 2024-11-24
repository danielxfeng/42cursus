/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:32:53 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/24 15:34:34 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_node	t_node;

// Maintains a data structure of `stack`.
// `root` is the int list, as well as a `circular doubly linked list`.
// `len` is the length of `stack`.
// `label` is either 'a' or 'b'.
typedef struct s_stack
{
	t_node				*root;
	size_t				len;
	char				label;
}						t_stack;

// The data structure of stacks.
typedef struct s_stacks
{
	t_stack				*stack_a;
	t_stack				*stack_b;
}						t_stacks;

// Represents a node of `circular doubly linked list`.
typedef struct s_node
{
	int					value;
	t_node				*prev;
	t_node				*next;
}						t_node;

typedef struct s_move_plan_ab
{
	bool				is_r;
	int					total_times;
	int					a_op_times;
	int					b_op_times;
	int					double_op_times;
}						t_move_plan_ab;

int						push_swap(int argc, char **argv,
							void (*apply_sort_func)(t_stacks *));
bool					insert_value_to_stacks(t_stacks *stacks, int argc,
							char **argv);
void					get_plan(t_stacks *stacks, size_t i,
							t_move_plan_ab *curr_plan);
void					generate_move_plan_ab(t_stacks *stacks, size_t i,
							bool is_r, t_move_plan_ab *plan);

t_stacks				*new_stacks(void);
t_stacks				*close_stacks(t_stacks **stacks);
void					s(t_stacks *stacks, bool is_a);
void					ss(t_stacks *stacks);
void					r(t_stacks *stacks, bool is_a);
void					double_r(t_stacks *stacks);
void					rr(t_stacks *stacks, bool is_a);
void					rrr(t_stacks *stacks);
void					p(t_stacks *stacks, bool is_a);
bool					push_stack(t_stacks *stacks, int n, bool is_a);
int						get_value_from_stack(t_stacks *stacks, bool is_a,
							size_t idx);

bool					ps_atoi(const char *nptr, int *n); 
bool					free_str_arr(char **arr);

#endif
