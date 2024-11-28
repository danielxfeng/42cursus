/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:03:54 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/28 21:23:41 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"
#include <stdlib.h>

t_tile			*free_row(t_tile **row);
t_tile			**free_board(t_tile ***board, int height);

// The constructor of Player.
// Will not free anything here, even on error, the caller should do it.
static t_player	*create_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->prev_x = -1;
	player->prev_y = -1;
	player->has_collectible = 0;
	player->movements = 0;
	return (player);
}

// The constructor of Tile.
// Will not free anything here, even on error, the caller should do it.
static bool	create_tile(int x, int y, char c, t_tile *tile)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
		return (false);
	tile->x = x;
	tile->y = y;
	if (c == '1')
		tile->type = TILE_WALL;
	else
		tile->type = TILE_EMPTY;
	tile->is_collectible = (c == 'C');
	tile->is_exit = (c == 'E');
	return (true);
}

static t_tile	*create_board_row(t_board_check *board_check, char **parameter,
		t_player *player)
{
	int		j;
	t_tile	*row;

	row = malloc(board_check->length * sizeof(t_tile));
	if (!row)
		return (NULL);
	j = 0;
	while (j < board_check->length)
	{
		if (!create_tile(j, board_check->i, parameter[board_check->i][j],
				&(row[j])))
			return (free_row(&row));
		if (parameter[board_check->i][j] == 'P')
		{
			++(board_check->entrance);
			player->x = j;
			player->y = board_check->i;
		}
		if (parameter[board_check->i][j] == 'E')
			++(board_check->exit);
		if (parameter[board_check->i][j] == 'C')
			++(board_check->collectible);
		++j;
	}
	return (row);
}

// The constructor of Board.
// Will not free anything here, even on error, the caller should do it.
static t_tile	**create_board(int length, int height, char **parameter,
		t_player *player)
{
	int				i;
	t_tile			**board;
	t_board_check	board_check;

	board_check.collectible = 0;
	board_check.entrance = 0;
	board_check.exit = 0;
	board = malloc(height * sizeof(t_tile *));
	if (!board)
		return (NULL);
	i = 0;
	board_check.length = length;
	while (i < height)
	{
		board_check.i = i;
		board[i] = create_board_row(&board_check, parameter, player);
		if (!board[i])
			return (free_board(&board, i));
		++i;
	}
	if (board_check.collectible <= 0 || board_check.entrance != 1
		|| board_check.exit != 1)
		return (free_board(&board, height));
	return (board);
}

// The constructor of Game.
// Will not free anything here, even on error, the caller should do it.
t_game	*create_game(int length, int height, char **parameter)
{
	t_game	*game;

	if (length <= 0 || height <= 0)
		exit_prog(NULL, &parameter, 1);
	game = malloc(sizeof(t_game));
	if (!game)
		exit_prog(NULL, &parameter, 1);
	game->player = NULL;
	game->board = NULL;
	game->length = length;
	game->height = height;
	game->player = create_player();
	if (!game->player)
		exit_prog(&game, &parameter, 1);
	game->board = create_board(length, height, parameter, game->player);
	if (!game->board || !path_check(game))
		exit_prog(&game, &parameter, 1);
	game->status = STATUS_NOT_START;
	return (game);
}
