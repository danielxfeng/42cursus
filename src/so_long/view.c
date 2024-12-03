/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:07:51 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 15:02:21 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

// Helper function to draw a tile for `draw_all`.
// Each tile is drawn with a `collectible image` by default, and then toggle
// the `enabled` property by it's status.
// Because `game`'s state only track whether a tile still has a collectible.
static void	draw_tile(t_game *game, t_view *view, int i, int j)
{
	int	x;
	int	y;

	x = j * TILE_SIZE + PADDING;
	y = i * TILE_SIZE + PADDING;
	if (mlx_image_to_window(view->mlx, view->img_tile, x, y) < 0)
		exit_prog(&game, NULL, &view, "Cannot draw tile image.");
	if (game->board[i][j].type == TILE_WALL)
	{
		if (mlx_image_to_window(view->mlx, view->img_wall, x, y) < 0)
			exit_prog(&game, NULL, &view, "Cannot draw wall image.");
	}
	if (mlx_image_to_window(view->mlx, view->img_collectible, x, y) < 0)
		exit_prog(&game, NULL, &view, "Cannot draw collectible image.");
	view->img_collectible->instances[two_to_one(j, i,
			game)].enabled = game->board[i][j].is_collectible;
	if (game->board[i][j].is_exit)
	{
		if (mlx_image_to_window(view->mlx, view->img_exit, x, y) < 0)
			exit_prog(&game, NULL, &view, "Cannot draw exit image.");
	}
}

// Update ui for each pixel of game.
void	draw_all(t_game *game, t_view *view)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
			draw_tile(game, view, i, j++);
		++i;
	}
	if (mlx_image_to_window(view->mlx, view->img_player, game->player->x
			* TILE_SIZE + PADDING, game->player->y * TILE_SIZE + PADDING) < 0)
		exit_prog(&game, NULL, &view, "Cannot draw image");
}

// Update the ui for each moving.
void	draw_move(t_game *game, t_view *view)
{
	view->img_player->instances[0].x = game->player->x * TILE_SIZE + PADDING;
	view->img_player->instances[0].y = game->player->y * TILE_SIZE + PADDING;
	if (!game->board[game->player->y][game->player->x].is_collectible)
		view->img_collectible->instances[two_to_one(game->player->x,
				game->player->y, game)].enabled = false;
}

// Handle key press event.
void	handle_key_press_event(mlx_key_data_t keydata, void *param)
{
	t_param		*p;
	t_direction	direction;

	p = (t_param *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_and_close_param(&p, NULL);
	if (keydata.key == MLX_KEY_W)
		direction = DIR_U;
	else if (keydata.key == MLX_KEY_S)
		direction = DIR_D;
	else if (keydata.key == MLX_KEY_A)
		direction = DIR_L;
	else if (keydata.key == MLX_KEY_D)
		direction = DIR_R;
	else
		return ;
	if (!move(p->game, direction))
		return ;
	draw_move(p->game, p->view);
	ft_printf("Movements: %d\n", p->game->player->movements);
	if (p->game->status == STATUS_WON)
		exit_and_close_param(&p, NULL);
}

// Handle close window event.
void	handle_win_close_event(void *param)
{
	t_param	*p;

	p = (t_param *)param;
	exit_and_close_param(&p, NULL);
}
