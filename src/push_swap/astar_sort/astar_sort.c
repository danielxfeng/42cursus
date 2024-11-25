/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:08:35 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/25 12:48:17 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"

void get_best_plan_ab(t_stacks *stacks, size_t idx, t_move_plan_ab *best_plan);

// Returns the plan of next move from `stack a` to `stack b`.
t_move_plan_ab get_next_move_plan_ab(t_stacks *stacks, t_move_plan_ab *next_plan)
{
    size_t i;
    size_t j;
    int cheapest;
    t_move_plan_ab plans[60];
    
    i = 0;
    cheapest = INT_MAX;
    while (i < 30 && i < cheapest)
    {
        get_best_plan(stacks, i, &(plans[i]));
        if (plans[i].total_times < cheapest)
            cheapest = plans[i].total_times;
        get_best_plan(stacks, 60 - 1 - i, &(plans[60 - 1 - i]));
        if (plans[60 - 1 - i].total_times < cheapest)
            cheapest = plans[60 - 1 - i].total_times;
    }
    j = 0;
    while (j < i)
    {
        if (plans[i].total_times == cheapest)
            return (*next_plan = plans[i]);
        if (plans[60 - 1 - i].total_times == cheapest)
            return (*next_plan = plans[60 - 1 - i]);
        ++j;
    }
}

// Perform move from `stack a` to `stack b`.
void perform_move_ab(t_stacks *stacks, t_move_plan_ab *plan)
{
    size_t i;
    void (*double_func)(t_stacks *stacks);
    void (*single_func)(t_stacks *stacks, bool is_a);

    i = 0;
    double_func = r;
    if (plan->a_is_r)
        double_func = rr;
    while (i++ < plan->double_op_times)
        double_func(stacks);
    i = 0;
    single_func = r;
    if (plan->a_is_r)
        single_func = rr;
    while (i++ < plan->a_op_times - plan->double_op_times)
        single_func(stacks, true);            
    i = 0;
    single_func = r;
    if (plan->b_is_r)
        single_func = rr;
    while (i++ < plan->b_op_times - plan->double_op_times)
        single_func(stacks, false);
    p(stacks, false);    
}

// Sort the `stack b`.
int sort_stack_b(t_stacks *stacks)
{
    int i;
    int target;
    
    if (stacks->stack_a->len < 2)
        return (0);
    i = 0;
    target = get_idx_by_value(stacks, stacks->stack_b->max->value, false);
    if (target <= stacks->stack_b->len / 2)
    {
        while (i++ < target)
            r(stacks, false);
        return (target);    
    }
    while (i++ < stacks->stack_b->len - target)
        rr(stacks, false);
    return (i++ < stacks->stack_b->len - target);
}

// The function which applies the sort algorithm.
void	astar_sort_func(t_stacks *stacks)
{
	int total_times;
    size_t i;
    size_t max_idx_in_b;
    t_move_plan_ab next_plan;

	total_times = 0;
	while (stacks->stack_a->len)
    {
        get_next_move_plan_ab(stacks, &next_plan);
        perform_move_ab(stacks, &next_plan);
        total_times += next_plan.total_times;
    }
    max_idx_in_b = find_max_in_stack(stacks->stack_b);
    i = 0;
    while (max_idx_in_b < stacks->stack_b->len / 2 && i++ < max_idx_in_b)
        r(stacks, false);
    while (max_idx_in_b >= stacks->stack_b->len / 2 && i++ < stacks->stack_b->len - max_idx_in_b)
        rr(stacks, false);
    total_times += sort_stack_b(stacks);
	while (stacks->stack_b->len)
		p(stacks, false);
    total_times += stacks->stack_b->len;
	ft_printf("Total cost for debug: %d\n", total_times);
}
