/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:58:58 by Xifeng            #+#    #+#             */
/*   Updated: 2025/02/01 12:12:08 by Xifeng           ###   ########.fr       */
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
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
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
	long long	wait_for_dead;

	if (game->args[NUMBERS] == 1)
		usleep(game->args[TO_DIE] * MS);
	else
	{
		if (te - ts <= (long long)game->args[TO_DIE])
			return (false);
		curr = get_ts();
		wait_for_dead = (long long)game->args[TO_DIE] - (curr - ts);
		if (wait_for_dead > 0)
			usleep(wait_for_dead * MS);
	}
	send_message(game->mq, get_ts(), i, DEAD);
	return (true);
}

// @brief wait until all the threads are ready.
//
// @param game: the pointer to game.
void	wait_for_ready(t_game *game)
{
	pthread_mutex_lock(&(game->forks[0]));
	++game->ready_threads;
	pthread_mutex_unlock(&(game->forks[0]));
	while (game->ready_threads < game->args[NUMBERS])
		usleep(MS);
}
