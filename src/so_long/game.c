/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:44:52 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/01 21:24:56 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Set the next point by `direction`.
void	set_next_point(t_point *point, t_direction direction)
{
	if (direction == DIR_U)
		--(point->y);
	else if (direction == DIR_D)
		++(point->y);
	else if (direction == DIR_L)
		--(point->x);
	else if (direction == DIR_R)
		++(point->x);
	else
	{
		point->x = -1;
		point->y = -1;
	}
}

// Return if a point is valid.
// Returns false when the point is out of border, or it's a wall
// Otherwise returns true;
bool	is_valid_point(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->length || y >= game->height
		|| game->board[y][x].type == TILE_WALL)
		return (false);
	return (true);
}

// Check if the game is over.
// All collectible are collected, and player is at the exit tile.
static void	check_game_over(t_game *game)
{
	if (game->total_collectible == game->player->has_collectible
		&& game->board[game->player->y][game->player->x].is_exit)
		game->status = STATUS_WON;
	else
		game->status = STATUS_WAIT_MOVE;
}

// Perform the move of the game.
// Return if it's a valid move.
// Collect the possible collectible.
// Update the counts of movements.
bool	move(t_game *game, t_direction direction)
{
	t_point	point;

	if (game->status != STATUS_WAIT_MOVE)
		return (false);
	game->status = STATUS_MOVING;
	point.x = game->player->x;
	point.y = game->player->y;
	set_next_point(&point, direction);
	if (!is_valid_point(game, point.x, point.y))
	{
		game->status = STATUS_WAIT_MOVE;
		return (false);
	}
	game->player->prev_x = game->player->x;
	game->player->prev_y = game->player->y;
	game->player->x = point.x;
	game->player->y = point.y;
	if (game->board[game->player->y][game->player->x].is_collectible)
	{
		++(game->player->has_collectible);
		game->board[game->player->y][game->player->x].is_collectible = false;
	}
	++(game->player->movements);
	check_game_over(game);
	return (true);
}
