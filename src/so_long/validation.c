/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:42:32 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 19:38:52 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

// A recursive call helper for `path_check`.
static void	path_check_helper(t_game *game, int x, int y)
{
	t_direction	direction;
	t_point		point;

	if (!is_valid_point(game, x, y) || game->board[y][x].is_visited)
		return ;
	game->board[y][x].is_visited = true;
	direction = DIR_U;
	while (direction <= DIR_R)
	{
		point.x = x;
		point.y = y;
		set_next_point(&point, direction);
		path_check_helper(game, point.x, point.y);
		++direction;
	}
	return ;
}

// To check if there is a valid path from entrance to exit.
bool	path_check(t_game *game)
{
	int		i;
	int		j;

	path_check_helper(game, game->player->x, game->player->y);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->length)
		{
			if ((game->board[i][j].is_collectible || game->board[i][j].is_exit)
				&& !(game->board[i][j].is_visited))
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

// A helper function for `validate_parameter`.
static void	validate_parameter_row(char **p, t_parameter_check *pc, int i)
{
	int	j;

	if ((int)ft_strlen(p[i]) != pc->length)
		exit_prog(NULL, &p, NULL, "Map should be rectangular.");
	j = 0;
	while (j < pc->length)
	{
		if (p[i][j] != '1' && p[i][j] != '0' && p[i][j] != 'C' && p[i][j] != 'E'
			&& p[i][j] != 'P')
			exit_prog(NULL, &p, NULL, "Illegal character in map.");
		if ((i == 0 || i == pc->height - 1 || j == 0 || j == pc->length - 1)
			&& p[i][j] != '1')
			exit_prog(NULL, &p, NULL, "Map should be surrounded by walls.");
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
void	validate_parameter(char **parameter)
{
	t_parameter_check	pc;
	int					i;

	pc.height = str_arr_len(parameter);
	pc.length = ft_strlen(parameter[0]);
	if (pc.height > 130 || pc.length > 130)
		exit_prog(NULL, &parameter, NULL, "Map is too big to fit the game.");
	pc.collectible = 0;
	pc.entrance = 0;
	pc.exit = 0;
	i = 0;
	while (i < pc.height)
		validate_parameter_row(parameter, &pc, i++);
	if (pc.collectible <= 0)
		exit_prog(NULL, &parameter, NULL, "Map needs at least 1 collectible.");
	if (pc.entrance != 1)
		exit_prog(NULL, &parameter, NULL, "Map needs exactly 1 player.");
	if (pc.exit != 1)
		exit_prog(NULL, &parameter, NULL, "Map needs exactly 1 exit.");
}
