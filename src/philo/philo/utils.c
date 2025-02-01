/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:58:58 by Xifeng            #+#    #+#             */
/*   Updated: 2025/02/01 19:44:06 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Immuted ++.
int	pp(t_game *game, int idx)
{
	if (idx == game->args[NUMBERS] - 1)
		return (0);
	return (idx + 1);
}

// Simplified `atoi` with error handling.
bool	philo_atoi(const char *nptr, int *n)
{
	while (*nptr == ' ')
		++nptr;
	if (*nptr == '+')
		++nptr;
	*n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		*n = *n * 10 + *nptr - '0';
		++nptr;
		if (*n < 0)
			return (false);
	}
	if (*nptr || *n <= 0)
		return (false);
	return (true);
}

// @brief returns the current timestamp in ms.
long long	get_ts(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
}
