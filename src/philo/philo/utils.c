/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:58:58 by Xifeng            #+#    #+#             */
/*   Updated: 2025/01/29 19:23:30 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>
#include <unistd.h>

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
	return ((long long)(tv.tv_sec) * 1000 + (long long)(tv.tv_usec) / 1000);
}

// @brief let philo die when neccessary.
//
// @param game: the pointer to game.
// @param i: the index of philo.
// @param ts: the start time of EATING.
// @param te: the end time the action.
// @return: if the philo is dead.
bool	try_die(t_game *game, int i, long long ts, long long te)
{
	long long	curr;

	if (game->args[NUMBERS] == 1)
		usleep(game->args[TO_DIE]);
	else
	{
		if (te - ts <= (long long)game->args[TO_DIE])
			return (false);
		curr = get_ts();
		if (te > curr)
			usleep(te - curr);
	}
	send_message(game->mq, get_ts(), i, DEAD);
	return (true);
}
