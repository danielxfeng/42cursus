/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:42:32 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/30 16:43:21 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

// A recursive call helper for `path_check`.
static bool	path_check_helper(t_game *game, int x, int y)
{
	t_direction	direction;
	t_point		point;

	if (!is_valid_point(game, x, y) || game->board[y][x].is_visited)
		return (false);
	if (game->board[y][x].is_exit)
		return (true);
	point.x = x;
	point.y = y;
	game->board[y][x].is_visited = true;
	direction = DIR_U;
	while (direction <= DIR_R)
	{
		set_next_point(&point, direction);
		if (path_check_helper(game, point.x, point.y))
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

// A helper function for `validate_parameter`.
static void validate_parameter_row(char **p, t_parameter_check *pc, int i)
{
	int j;

	if (ft_strlen(p[i]) != pc->length)
		exit_prog(NULL, &p, "Map should be rectangular.");
	j = 0;
	while (j < pc->length)
	{
		if (p[i][j] != '1' && p[i][j] != '0' && p[i][j] != 'C' 
		&& p[i][j] != 'E' && p[i][j] != 'P')
			exit_prog(NULL, &p, "Illegal character in map.");
		if ((i == 0 || i == pc->height - 1 || j == 0 
		|| j == pc->length - 1) && p[i][j] != '1')
			exit_prog(NULL, &p, "Map should be surrounded by walls.");
		if (p[i][j] == 'C')
			++pc->collectible;
		if (p[i][j] == 'E')
			++pc->exit;
		if (p[i][j] == 'P')
			++pc->entrance;
		++j;
	}
}

// To validate the parameter, will `exit` when there is anything wrong.
void validate_parameter(char **parameter)
{
	t_parameter_check pc;
	int i;

	pc.height = str_arr_len(parameter);
	pc.length = ft_strlen(parameter[0]);
	pc.collectible = 0;
	pc.entrance = 0;
	pc.exit = 0;
	i = 0;
	while (i < pc.height)
		validate_parameter_row(parameter, &pc, i++);
	if (pc.collectible <= 0)
		exit_prog(NULL, &parameter, "Map needs at least 1 collectible.");
	if (pc.entrance != 0)
		exit_prog(NULL, &parameter, "Map needs only 1 player.");
	if (pc.exit != 0)
		exit_prog(NULL, &parameter, "Map needs only 1 exit.");	
}
