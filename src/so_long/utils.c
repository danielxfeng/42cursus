/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:53:19 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 13:34:31 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Returns the length of a null terminated string array.
int	str_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}
// Convert 2d coordinator to 1d.
int	two_to_one(int x, int y, t_game *game)
{
	return (y * game->length + x);
}
