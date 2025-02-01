/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:07:52 by Xifeng            #+#    #+#             */
/*   Updated: 2025/01/28 10:29:34 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

// @brief Destructor of mq.
// Call it ONLY when holding the lock of mq or the lock is not inited.
//
// @param mq: pointer to the message queue.
// @param has_lock: if the lock is initailized.
// @return NULL
t_mq	*close_mq(t_mq **mq, bool has_lock)
{
	if (mq && *mq)
	{
		(*mq)->is_closed = true;
		if ((*mq)->events)
		{
			free((*mq)->events);
			(*mq)->events = NULL;
		}
		if ((*mq)->ids)
		{
			free((*mq)->ids);
			(*mq)->ids = NULL;
		}
		if ((*mq)->ts)
		{
			free((*mq)->ts);
			(*mq)->ts = NULL;
		}
		if (has_lock)
			pthread_mutex_destroy(&((*mq)->lock));
		free(*mq);
		*mq = NULL;
	}
	return (NULL);
}

// Destructor of mutexes.
void	close_mutexes(int count, pthread_mutex_t *mutexes)
{
	int	i;

	if (mutexes)
	{
		i = 0;
		while (i < count)
		{
			if (pthread_mutex_destroy(&(mutexes[i])) != 0)
				printf("Error on destroy mutex\n");
			++i;
		}
		free(mutexes);
	}
}

// Destructor of game.
void	close_game(t_game **game)
{
	if (game && *game)
	{
		if ((*game)->threads)
			free((*game)->threads);
		(*game)->threads = NULL;
		if ((*game)->mq)
			(*game)->mq = close_mq(&((*game)->mq), true);
		close_mutexes((*game)->args[NUMBERS], (*game)->forks);
		if ((*game)->rounds)
			free((*game)->rounds);
		(*game)->rounds = NULL;
		(*game)->forks = NULL;
		free(*game);
		*game = NULL;
	}
}

// close the game then return NULL.
t_game	*return_null_and_free(t_game **game)
{
	close_game(game);
	return (NULL);
}
