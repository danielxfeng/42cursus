/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:01:48 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/29 12:21:55 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"
#include <stdlib.h>

// A helper function for `create_board_row`, it returns `NULL` for norm.
t_tile	*free_row(t_tile **row)
{
	if (row && *row)
	{
		free(*row);
		*row = NULL;
	}
	return (NULL);
}

// The helper function for `exit_prog`, it returns `NULL` for norm.
t_tile	**free_board(t_tile ***board, int height)
{
	int	i;

	if (board && *board)
	{
		i = 0;
		while (i < height)
		{
			if ((*board)[i])
				free_row(&((*board)[i]));
			++i;
		}
		free(*board);
		*board = NULL;
	}
	return (NULL);
}

// Call this function before exit.
// `msg`: set to NULL for normal exit.
void	exit_prog(t_game **game, char ***parameter, char *msg)
{
	int	i;

	i = 0;
	if (parameter && *parameter)
	{
		while (*parameter[i])
			free(*parameter[i++]);
		free(*parameter);
		*parameter = NULL;
	}
	if (game && *game)
	{
		if ((*game)->player)
		{
			free((*game)->player);
			(*game)->player = NULL;
		}
		free_board(&(*game)->board, (*game)->height);
		free(*game);
		*game = NULL;
	}
	if (!msg)
		exit(0);
	perror(msg);
	exit(1);
}
