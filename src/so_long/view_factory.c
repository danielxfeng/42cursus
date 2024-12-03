/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:16:25 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 20:01:53 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

// Helper function for free the param and exit the program.
void	exit_and_close_param(t_param **param, char *msg)
{
	t_game	*game;
	t_view	*view;

	if (param && *param)
	{
		game = (*param)->game;
		view = (*param)->view;
		free(*param);
		*param = NULL;
		exit_prog(&game, NULL, &view, msg);
	}
}

// Deconstructor of `view`.
void	close_view(t_view **view)
{
	if (!view || !*view)
		return ;
	if ((*view)->mlx)
	{
		if ((*view)->img_background)
			mlx_delete_image((*view)->mlx, (*view)->img_background);
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
static mlx_image_t	*create_image(t_game *game, t_view *view,
		const char *file_name)
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
	if (!mlx_resize_image(img, TILE_SIZE, TILE_SIZE))
		exit_prog(&game, NULL, &view, "MLX failed: resizing image.");
	return (img);
}

// Create the background image.
static void	create_background(t_game *game, t_view *view)
{
	int			i;
	int			width;
	int			height;
	uint32_t	*pixels;

	width = gws(game->length);
	height = gws(game->height);
	view->img_background = mlx_new_image(view->mlx, width, height);
	if (!view->img_background || (mlx_image_to_window(view->mlx,
				view->img_background, 0, 0) < 0))
		exit_prog(&game, NULL, &view, "MLX failed: background creation.");
	i = 0;
	pixels = (uint32_t *)view->img_background->pixels;
	while (i < height * width)
		pixels[i++] = BG_COLOR;
}

// Create the view with background.
t_view	*create_view(t_game *game)
{
	t_view	*view;

	view = malloc(sizeof(t_view));
	if (!view)
		exit_prog(&game, NULL, NULL,
			"Memory allocation failed: view creation.");
	view->mlx = NULL;
	view->img_background = NULL;
	view->img_tile = NULL;
	view->img_wall = NULL;
	view->img_player = NULL;
	view->img_collectible = NULL;
	view->img_exit = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	view->mlx = mlx_init(gws(game->length), gws(game->height), "So Long", true);
	if (!view->mlx)
		exit_prog(&game, NULL, &view, "MLX init failed.");
	create_background(game, view);
	view->img_tile = create_image(game, view, IMG_TILE);
	view->img_wall = create_image(game, view, IMG_WALL);
	view->img_player = create_image(game, view, IMG_PLAYER);
	view->img_collectible = create_image(game, view, IMG_COLLECTIBLE);
	view->img_exit = create_image(game, view, IMG_EXIT);
	return (view);
}
