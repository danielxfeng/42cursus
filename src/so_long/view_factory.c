/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:16:25 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/01 19:03:55 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

// Deconstructor of `view`.
void close_view(t_view **view)
{
    if (!view || !*view)
        return;
    if ((*view)->mlx)
    {
        if ((*view)->img_collectible)
            mlx_delete_image((*view)->mlx, (*view)->img_collectible);
        if ((*view)->img_exit)
            mlx_delete_image((*view)->mlx, (*view)->img_exit);
        if ((*view)->img_player)
            mlx_delete_image((*view)->mlx, (*view)->img_player);
        if ((*view)->img_tile)
            mlx_delete_image((*view)->mlx, (*view)->img_tile);
        if ((*view)->img_wall)
            mlx_delete_image((*view)->mlx, (*view)->img_wall);
        mlx_close_window((*view)->mlx);
    }
    free(*view);
    *view = NULL;
}

// A helper function for `create_view`.
static mlx_image_t	*create_image(t_game *game, t_view *view, const char *file_name)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = mlx_load_png(file_name);
	if (!tex)
		exit_prog(&game, NULL, &view, "MLX failed: tex creation.");
	img = mlx_texture_to_image(view->mlx, tex);
    mlx_delete_texture(tex);
	if (!img)
		exit_prog(&game, NULL, &view, "MLX failed: image creation.");
	return (img);
}

// Create the view.
t_view *create_view(t_game *game)
{
    t_view *view;
    int win_width;
    int win_height;

    view = malloc(sizeof(t_view));
    if (!view)
        exit_prog(&game, NULL, NULL, "Memory allocation failed: view creation.");
    view->mlx = NULL;
    view->img_tile = NULL;
    view->img_wall = NULL;
    view->img_player = NULL;
    view->img_collectible = NULL;
    view->img_exit = NULL;
    view->mlx = mlx_init(game->length * TILE_SIZE + 2 * (PADDING + MARGIN), 
    game->height * TILE_SIZE + 2 * (PADDING + MARGIN), "So Long by Daniel", true);
    if (!view->mlx)
        exit_prog(&game, NULL, view, "MLX init failed.");
    view->img_tile = create_image(game, view, IMG_TILE);
    view->img_wall = create_image(game, view, IMG_WALL);
    view->img_player = create_image(game, view, IMG_PLAYER);
    view->img_collectible = create_image(game, view, IMG_PLAYER);
    view->img_exit = create_image(game, view, IMG_EXIT);
    return (view);
}
