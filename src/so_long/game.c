/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:44:52 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/28 21:31:39 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

// Set the next point by `direction`.
void set_next_point(t_next_point *next_point)
{
    next_point->new_x = next_point->x;
    next_point->new_y = next_point->y;
    if (next_point->direction == DIR_U)
        next_point->new_y = next_point->y - 1;
    else if (next_point->direction == DIR_D)
        next_point->new_y = next_point->y + 1;
    else if (next_point->direction == DIR_L)
        next_point->new_x = next_point->x - 1;
    else if (next_point->direction == DIR_R)
        next_point->new_x = next_point->x + 1;
    else
    {
        next_point->new_x = -1;
        next_point->new_y = -1;   
    }
}

// Return if a point is valid.
// Returns false when the point is out of border, or it's a wall 
// Otherwise returns true;
bool is_valid_point(t_game *game, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->length || y >= game->height 
    || game->board[y][x].type == TILE_WALL)
        return (false);
    return (true);
}

// Check if the game is over.
// All collectible are collected, and player is at the exit tile.
static void check_game_over(t_game *game)
{
    if (game->total_collectible == game->player->has_collectible 
    && game->board[game->player->y][game->player->x].is_exit)
        game->status = STATUS_WON;
}

// Perform the move of the game.
// Return if it's not a valid move.
// Collect the possible collectible.
// Update the counts of movements.
void move(t_game *game, t_direction direction)
{
    t_next_point next_point;

    next_point.direction = direction;
    next_point.x = game->player->x;
    next_point.y = game->player->y;
    set_next_point(&next_point);
    if(!is_valid_point(game, next_point.new_x, next_point.new_y))
        return ;
    game->player->prev_x = game->player->x;
    game->player->prev_y = game->player->y;
    game->player->x = next_point.new_x;
    game->player->y = next_point.new_y;
    if (game->board[game->player->y][game->player->x].is_collectible)
    {
        ++(game->player->has_collectible);
        game->board[game->player->y][game->player->x].is_collectible = false;
    }
    ++(game->player->movements);
    draw_move(game);
    check_game_over(game);
}
