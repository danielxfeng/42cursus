/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:07:51 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/01 21:31:51 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Convert 2d coordinator to 1d.
static int two_to_one(int x, int y, t_game *game)
{
    return (y * game->length + x);
}

// Helper function to draw a tile for `draw_all`.
// Each tile is drawn with a `collectible image` by default, and then toggle
// the `enabled` property by it's status. 
// Because `game`'s state only track whether a tile still has a collectible.
static void draw_tile(t_game *game, t_view *view, int i, int j)
{
    int x;
    int y;

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
    view->img_collectible->instances[two_to_one(j, i, game)].enabled = 
    game->board[i][j].is_collectible;
    if (game->board[i][j].is_exit)
    {
        if (mlx_image_to_window(view->mlx, view->img_exit, x, y) < 0)
            exit_prog(&game, NULL, &view, "Cannot draw exit image.");
    }
}

// Update ui for each pixel of game.
void draw_all(t_game *game, t_view *view)
{
    int i;
    int j;

    i = 0;
    while (i < game->height)
    {
        j = 0;
        while (j < game->length)
            draw_tile(game, view, i, j++);
        ++i;
    }
    if (mlx_image_to_window(view->mlx, view->img_player, game->player->x * TILE_SIZE + PADDING, game->player->y * TILE_SIZE + PADDING) < 0)
        exit_prog(&game, NULL, &view, "Cannot draw image");
}

// Update the ui for each moving.
void draw_move(t_game *game, t_view *view)
{
    view->img_player->instances[0].x = game->player->x * TILE_SIZE + PADDING;
    view->img_player->instances[0].y = game->player->y * TILE_SIZE + PADDING;
    if (!game->board[game->player->y][game->player->x].is_collectible)
        view->img_collectible->instances[two_to_one(game->player->x, game->player->y, game)].enabled = false;
}
