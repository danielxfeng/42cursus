/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:57:15 by Xifeng            #+#    #+#             */
/*   Updated: 2025/02/01 13:44:21 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

bool		try_die(t_game *game, int i, long long ts, long long te);
void		wait_for_ready(t_game *game);

// @brief the helper function to release the locks (if need), and
// set the next_status to DEAD, and returns null.
static void	unlock_and_dead(int *next_status, pthread_mutex_t *fork1,
		pthread_mutex_t *fork2)
{
	if (fork1)
		pthread_mutex_unlock(fork1);
	if (fork2)
		pthread_mutex_unlock(fork2);
	*next_status = DEAD;
	return ;
}

// @brief the handler of a philo who need to avoid eating for this round.
// Some philos have to wait when the NUMBER of philos is odd.
//
// @param game: the pointer to the game.
// @param i: the idx of a philosopher.
// @param next_status: the next status of a philosopher.
// @param ts: the start time of EATING.
void	phio_think(t_game *game, int i, int *next_status, long long *ts)
{
	int	thinking_time;
	long long curr;

	curr = get_ts();
	thinking_time = game->args[TO_EAT] - (curr - *ts);
	if (game->even_or_odd && (i == 0 || game->rounds[i] > 0))
	{
		thinking_time += game->args[TO_EAT];
	}
	if (thinking_time > 0)
	{
		if (try_die(game, i, *ts, curr + thinking_time))
			return (unlock_and_dead(next_status, NULL, NULL));
		usleep(thinking_time * MS);
	}
	*next_status = EATING;
}

// @brief thd handler of a philo who need to eat.
// It includes 2 stages: getting 2 forks and eat.
//
// The whole process is:
// 1 try to get 2 forks. (by getting the locks)
// 2 then eat.
// 3 return the forks. (by releasing the locks)
// 4 send to sleep.
// ALWAYS FROM LEFT TO RIGHT WHEN OPERATING LOCKS FOR AVOIDING DEAD LOCK.
//
// @param game: the pointer to the game.
// @param i: the idx of a philosopher.
// @param next_status: the next status of a philosopher.
// @param ts: the start time of EATING.
void	phio_eat(t_game *game, int i, int *next_status, long long *ts)
{
	long long	curr;

	pthread_mutex_lock(&(game->forks[i]));
	curr = get_ts();
	if (try_die(game, i, *ts, curr) || !send_message(game->mq, curr, i,
			GET_FORK))
		return (unlock_and_dead(next_status, &(game->forks[i]), NULL));
	pthread_mutex_lock(&(game->forks[pp(game, i)]));
	curr = get_ts();
	if (try_die(game, i, *ts, curr) || !send_message(game->mq, curr, i,
			GET_FORK) || !send_message(game->mq, curr, i, EATING)
		|| try_die(game, i, curr, curr + game->args[TO_EAT]))
		return (unlock_and_dead(next_status, &(game->forks[i]),
				&(game->forks[pp(game, i)])));
	*ts = curr;
	usleep(game->args[TO_EAT] * MS);
	if (!send_message(game->mq, get_ts(), i, SLEEPING))
		return (unlock_and_dead(next_status, &(game->forks[i]),
				&(game->forks[pp(game, i)])));
	++(game->rounds[i]);
	pthread_mutex_unlock(&(game->forks[i]));
	pthread_mutex_unlock(&(game->forks[pp(game, i)]));
	*next_status = SLEEPING;
}

// @brief thd handler of a philo who need to sleeping.
//
// The process:
// 1 Sleep.
// 2 Turn to THINKING when wake up.
// 3 If the SLEEPING time is less than EATING,
// which means the forks are still in use by others,
// we continue to sleep.
// 4 If we cannot eat for this round, set next to THINKING,
// otherwise set to EATING.
//
// @param game: the pointer to the game.
// @param i: the idx of a philosopher.
// @param next_status: the next status of a philosopher.
// @param ts: the start time of EATING.
void	phio_sleep(t_game *game, int i, int *next_status, long long *ts)
{
	long long	curr;

	curr = get_ts();
	if (try_die(game, i, *ts, curr + game->args[TO_SLEEP]))
		return (unlock_and_dead(next_status, NULL, NULL));
	usleep(game->args[TO_SLEEP] * MS);
	curr = get_ts();
	if (!send_message(game->mq, curr, i, THINKING))
		return (unlock_and_dead(next_status, NULL, NULL));
	if (game->args[TO_SLEEP] < game->args[TO_EAT]) 
	{
		if (try_die(game, i, *ts, curr + game->args[TO_EAT] - game->args[TO_SLEEP]))
			return (unlock_and_dead(next_status, NULL, NULL));
		usleep((game->args[TO_EAT] - game->args[TO_SLEEP]) * MS);	
	}
	if (game->even_or_odd)
		*next_status = THINKING;
	else
		*next_status = EATING;
}

// @brief The philosopher's life cycle.
//
// It's a state machine.
// - When the status is `DEAD`, it can be due to:
//   1. Any philosopher reaching is dead.
//   2. An unexpected error occurring.
//
// Strategy:
// 0. Wait until all threads are ready.
// 1. Even-indexed philosophers (0, 2, 4, ...) eat first.
// 2. Odd-indexed philosophers (1, 3, 5, ...) eat next.
// 3. If the total number of philosophers is odd:
//    - Philosopher 0 skips the first eating round.
//    - After eating, all philosophers skip 2 rounds before eating again.
//
// Maximum ideal wait time calculation:
// - For even numbers of philosophers: 2 * max(to_eat, to_sleep).
// - For odd numbers of philosophers: 3 * max(to_eat, to_sleep).
//
// @param arg: the args.
// @return NULL.
void	*philo(void *arg)
{
	t_th_param	*param;
	long long	start;
	t_game		*game;
	int			i;
	int			next_status;

	param = (t_th_param *)arg;
	game = param->game;
	i = param->i;
	next_status = param->next_status;
	wait_for_ready(game);
	start = get_ts();
	if (!send_message(game->mq, start, i, THINKING))
		return (NULL);
	while (next_status != DEAD)
	{
		if (next_status == THINKING)
			phio_think(game, i, &next_status, &start);
		else if (next_status == EATING)
			phio_eat(game, i, &next_status, &start);
		else if (next_status == SLEEPING)
			phio_sleep(game, i, &next_status, &start);
	}
	return (NULL);
}
