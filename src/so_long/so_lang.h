/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_lang.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:03:49 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/27 22:12:27 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>

// Enum of the type of tile.
typedef enum a_type
{
	tile_wall,
	tile_path,
}	t_type;

// Enum of game status.
typedef enum a_status
{
	status_not_start,
	status_in_progress,
    status_won,
    status_lose,
}	t_status;

// Represents a Tile.
// type: the type of Tile.
// xy: the point of Tile.
// is_collectible: if there is a collectible.
// is_player: if the player is here.
typedef struct s_tile
{
    t_type type;
    int x;
    int y;
    bool  is_collectible;
    bool  is_player;
    bool  is_exit;
} t_tile;

// Represents a Player.
// xy: the current point of player.
// prev: the prev points, -1 for n/a.
// collectible: the count of collectible.
// movements: the count of movements.
typedef struct s_player
{
    int x;
    int y;
    int prev_x;
    int prev_y;
    int collectible;
    int movements;
    char *name;
} t_player;

// Represents a Game.
// length, height: the size of board.
// board: matrix of Tiles.
// player: the player.
// status: the Game status.
typedef struct s_game
{
    int length;
    int height;
    t_tile ***board;
    t_player *player;
    t_status status;
} t_game;

#endif