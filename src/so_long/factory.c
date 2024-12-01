/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:03:54 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/01 17:28:02 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void free_board(t_tile ***board, int height);

// The constructor of Player.
static t_player	*create_player(char **parameter, t_game *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		exit_prog(&game, &parameter, NULL, "Memory allocation failed: player creation.");
	player->prev_x = -1;
	player->prev_y = -1;
	player->has_collectible = 0;
	player->movements = 0;
	return (player);
}

// The constructor of Tile.
static void	create_tile(int x, int y, char c, t_tile *tile)
{
	tile->x = x;
	tile->y = y;
	tile->is_visited = false;
	if (c == '1')
		tile->type = TILE_WALL;
	else
		tile->type = TILE_EMPTY;
	tile->is_collectible = (c == 'C');
	tile->is_exit = (c == 'E');
}

// A helper function for creating each row of board.
static t_tile	*create_board_row(int i, int length, char **p, t_game *game)
{
	int		j;
	t_tile	*row;

	row = malloc(length * sizeof(t_tile));
	if (!row)
		return (NULL);
	j = 0;
	while (j < length)
	{
		create_tile(j, i, p[i][j], &(row[j]));
		if (p[i][j] == 'P')
		{
			game->player->x = j;
			game->player->y = i;
		}
		if (p[i][j] == 'C')
			++(game->total_collectible);
		++j;
	}
	return (row);
}

// The constructor of Board.
static t_tile	**create_board(int length, int height, char **parameter,
		t_game *game)
{
	int				i;
	t_tile			**board;

	board = malloc(height * sizeof(t_tile *));
	if (!board)
		exit_prog(&game, &parameter, NULL, "Memory allocation failed: map creation.");
	i = 0;
	while (i < height)
	{
		board[i] = create_board_row(i, length, parameter, game);
		if (!board[i])
		{
			free_board(&board, i);
			exit_prog(&game, &parameter, NULL, "Memory allocation failed: map row creation.");
		}
		++i;
	}
	return (board);
}

// The constructor of Game.
// Will not validate the parameter, please do it before call this func.
t_game	*create_game(int length, int height, char **parameter)
{
	t_game	*game;

	if (length <= 0 || height <= 0)
		exit_prog(NULL, &parameter, NULL, "Map should be a Rectangle.");
	game = malloc(sizeof(t_game));
	if (!game)
		exit_prog(NULL, &parameter, NULL, "Memory allocation failed: game creation.");
	game->player = NULL;
	game->board = NULL;
	game->length = length;
	game->height = height;
	game->total_collectible = 0;
	game->player = create_player(parameter, game);
	game->board = create_board(length, height, parameter, game);
	game->status = STATUS_NOT_START;
	return (game);
}
