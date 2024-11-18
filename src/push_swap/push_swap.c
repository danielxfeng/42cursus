/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 07:17:42 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/18 09:56:34 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_exit(t_stacks **stacks)
{
    if (stacks && *stacks)
        free_helper(stacks);
    ft_putstr("Error\n");
    return (1);
}

// Insert the arguments to stacks. 
// Returns false on error, otherwise returns true.
static bool insert_value_to_stacks(t_stacks *stacks, int argc, char **argv)
{
    int i;
    int n;

    i = 1;
    while (i < argc)
    {
        if (!my_atoi(argv[i++], &n) || !push_stack(stacks, n, true))
            return (false);
    }
    return (true);
}

// Entry point of the program. 
// `apply_sort_func` is a function pointer for sorting.
// Dependency injection is to decouple the sorting logic,
// making it easier to test and extend with different sorting algorithms.
int push_swap(int argc, char **argv, void (*apply_sort_func)(t_stacks *))
{
    t_stacks *stacks;
    
    if (argc <= 1)
        return (1);
    stacks = new_stacks();
    if (!stacks || !insert_value_to_stacks(stacks, argc, argv))
        return (error_exit(&stacks));
    if (apply_sort_func)
        apply_sort_func(stacks);
    free_helper(&stacks);
    return (0);
}
