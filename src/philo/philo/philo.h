/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:19:46 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/17 22:00:08 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

// The type of arguments.
typedef enum a_arg_type
{
	NUMBERS,
	TO_DIE,
	TO_EAT,
	TO_SLEEP,
	EAT_TIMES
}			t_arg_type;

// Represents a game.
// `args`: The arguments.
// `is_over` Is the game over.
// `forks`: The array of forks.
// `mutexes`: The array of mutex.
typedef struct s_game
{
	int				args[5];
	bool			is_over;
	bool			*forks;
	pthread_mutex_t	*mutexes;
}				t_game;

t_game  *return_null_and_free(t_game **game);
void close_mutexes(int count, pthread_mutex_t *mutexes);

#endif