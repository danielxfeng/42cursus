/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:01:48 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 19:24:40 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"
#include <stdlib.h>

void		close_view(t_view **view);

// A helper function for `create_board_row`.
static void	free_row(t_tile **row)
{
	if (row && *row)
	{
		free(*row);
		*row = NULL;
	}
}

// The helper function for `exit_prog`.
void	free_board(t_tile ***board, int height)
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
}

// Free parameter
void	free_parameter(char ***parameter)
{
	int	i;

	if (parameter && *parameter)
	{
		i = 0;
		while ((*parameter)[i])
		{
			free((*parameter)[i]);
			(*parameter)[i] = NULL;
			++i;
		}
		free(*parameter);
		*parameter = NULL;
	}
}

// A helper function to free the game.
void	free_game(t_game **game)
{
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
}

// Call this function before exit.
// `msg`: set to NULL for normal exit.
void	exit_prog(t_game **game, char ***parameter, t_view **view, char *msg)
{
	free_parameter(parameter);
	free_game(game);
	close_view(view);
	if (!msg)
	{
		ft_printf("Game Over!\n");
		exit(EXIT_SUCCESS);
	}	
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}
