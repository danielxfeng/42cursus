/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:42:32 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/29 11:56:56 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"

// A recursive call helper for `path_check`.
static bool	path_check_helper(t_game *game, int x, int y)
{
	t_direction		direction;
	t_next_point	next_point;

	if (!is_valid_point(game, x, y) || game->board[y][x].is_visited)
		return (false);
	if (game->board[y][x].is_exit)
		return (true);
	next_point.x = x;
	next_point.y = y;
	game->board[y][x].is_visited = true;
	direction = DIR_U;
	while (direction <= DIR_R)
	{
		next_point.direction = direction;
		set_next_point(&next_point);
		if (path_check_helper(game, next_point.new_x, next_point.new_y))
			return (true);
		++direction;
	}
	return (false);
}
// To check if there is a valid path from entrance to exit.
bool	path_check(t_game *game)
{
	return (path_check_helper(game, game->player->x, game->player->y));
}
