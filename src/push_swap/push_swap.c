/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 07:17:42 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/05 14:12:03 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

bool is_ordered_stack(t_stacks *stacks)
{
	size_t i;
	t_node *curr;

	i = 0;
	curr = stacks->stack_a->root;
	while (i < stacks->stack_a->len)
	{
		if (i > 0 && curr->value < curr->prev->value)
			return (false);
		curr = curr->next;
		++i;
	}
	return (true);	
}

static int	error_exit(t_stacks **stacks)
{
	if (stacks && *stacks)
		close_stacks(stacks);
	write(2, "Error\n", 6);
	return (1);
}

// Insert the arguments to stacks.
// Returns false on error, otherwise returns true.
static bool	insert_value_to_stacks(t_stacks *stacks, int argc, char **argv)
{
	int		i;
	int		j;
	int		n;
	char	**list;

	i = 1;
	while (i < argc)
	{
		list = ft_split(argv[i], ' ');
		if (!list || !*list)
			return (free_str_arr(list));
		j = 0;
		while (list[j])
		{
			if (!ps_atoi(list[j], &n) || !push_stack(stacks, n, true))
				return (free_str_arr(list));
			++j;
		}
		free_str_arr(list);
		++i;
	}
	return (true);
}

// Entry point of the program.
// `apply_sort_func` is a function pointer for sorting.
// Dependency injection is to decouple the sorting logic,
// making it easier to test and extend with different sorting algorithms.
int	push_swap(int argc, char **argv, int (*apply_sort_func)(t_stacks *))
{
	t_stacks	*stacks;

	if (argc <= 1)
		return (1);
	stacks = new_stacks();
	if (!stacks || !insert_value_to_stacks(stacks, argc, argv))
		return (error_exit(&stacks));
	if (!is_ordered_stack(stacks))
	{
		if (stacks->stack_a->len < 6)
			less_numbers_sort(stacks);
		else
			apply_sort_func(stacks);		
	}
	close_stacks(&stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv, astar_sort_func);
}



