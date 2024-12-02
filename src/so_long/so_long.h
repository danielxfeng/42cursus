/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:03:49 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/02 08:58:30 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stddef.h>
# include "mlx/include/MLX42/MLX42.h"

// The size of each `Tile`
# define TILE_SIZE 32
// The padding of the game board;
# define PADDING 10
// The background color;
# define BG_COLOR 0x000000
// The path to IMGs
# define IMG_TILE "/assets/tile.png"
# define IMG_WALL "/assets/wall.png"
# define IMG_PLAYER "/assets/player.png"
# define IMG_COLLECTIBLE "/assets/collectible.png"
# define IMG_EXIT "/assets/exit.png"

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
	STATUS_WAIT_MOVE,
	STATUS_MOVING,
	STATUS_WON,
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
// `is_visited`: for `path_check`.
typedef struct s_tile
{
	t_type		type;
	int			x;
	int			y;
	bool		is_collectible;
	bool		is_exit;
	bool		is_visited;
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

// Represents a point.
typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

// A struct for checking the parameter.
typedef struct s_parameter_check
{
	int length;
	int height;
	int entrance;
	int exit;
	int collectible;
} t_parameter_check;

// The pointers of view.
typedef struct s_view
{
	void *mlx;
	mlx_image_t		*img_background;
	mlx_image_t		*img_tile;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_collectible;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_player;
} t_view;

// Integrated parameter for key hook.
typedef struct s_param
{
	t_view *view;
	t_game *game;
} t_param;

void			exit_prog(t_game **game, char ***parameter, t_view **view, char *msg);
t_game			*create_game(int length, int height, char **parameter);

void			set_next_point(t_point *point, t_direction direction);

bool			is_valid_point(t_game *game, int x, int y);
bool			path_check(t_game *game);
void validate_parameter(char **parameter);

bool			move(t_game *game, t_direction direction);

t_view *create_view(t_game *game);
void draw_all(t_game *game, t_view *view);
void draw_move(t_game *game, t_view *view);
void handle_key_press_event(mlx_key_data_t keydata, void *param);
void handle_win_close_event(void *param);
void exit_and_close_param(t_param **param, char *msg);

int str_arr_len(char **arr);
int two_to_one(int x, int y, t_game *game);

#endif