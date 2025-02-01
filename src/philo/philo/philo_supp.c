/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_supp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:42:41 by Xifeng            #+#    #+#             */
/*   Updated: 2025/02/01 19:49:17 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

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

// @brief the helper function to release the locks (if need), and
// set the next_status to DEAD, and returns null.
void	unlock_and_dead(int *next_status, pthread_mutex_t *fork1,
		pthread_mutex_t *fork2)
{
	if (fork1)
		pthread_mutex_unlock(fork1);
	if (fork2)
		pthread_mutex_unlock(fork2);
	*next_status = DEAD;
	return ;
}
