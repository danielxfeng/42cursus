/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_lang.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:03:49 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/28 20:04:03 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>

// Enum of the type of `tile`.
typedef enum a_type
{
	TILE_WALL,
	TILE_EMPTY,
}				t_type;

// Enum of `game` `status`.
typedef enum a_status
{
	STATUS_NOT_START,
	STATUS_IN_PROGRESS,
	STATUS_WON,
	STATUS_LOSE,
}				t_status;

// Enum of `directions`, up, down, left and right.
typedef enum a_direction
{
	DIR_U,
	DIR_D,
	DIR_L,
	DIR_R,
}				t_direction;

// Represents a `Tile`.
// `type`: the type of `Tile`.
// xy: the point of `Tile`.
// `is_collectible`: if there is a `collectible`.
// `is_player`: if the `player` is here.
typedef struct s_tile
{
	t_type		type;
	int			x;
	int			y;
	bool		is_collectible;
	bool		is_player;
	bool		is_exit;
}				t_tile;

// Represents a `Player`.
// xy: the current point of `player`.
// `prev`: the `prev` points, -1 for n/a.
// `has_collectible`: the `collectible` the `player` has;
// `movements`: the count of movements.
typedef struct s_player
{
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
	int			has_collectible;
	int			movements;
}				t_player;

// Represents a `Game`.
// `length`, `height`: the size of `board`.
// `board`: matrix of `Tiles`.
// `player`: the `player`.
// `status`: the `Game` `status`.
// `total_collectible`: the count of `collectible`.
typedef struct s_game
{
	int			length;
	int			height;
	t_tile		**board;
	t_player	*player;
	t_status	status;
	int			total_collectible;
}				t_game;

// The struct for checking the board
// There should be one `exit`, one `entrance`, at least one `collectible`.
// length and i is the parameter when creating a row of `Tiles`.
typedef struct s_board_check
{
	int			exit;
	int			collectible;
	int			entrance;
	int			length;
	int			i;
}				t_board_check;

void			exit_prog(t_game **game, char ***parameter, int status);
t_game			*create_game(int length, int height, char **parameter);

#endif