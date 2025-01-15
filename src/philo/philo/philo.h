/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:19:46 by Xifeng            #+#    #+#             */
/*   Updated: 2025/01/15 14:50:41 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>

// The type of arguments.
typedef enum a_arg_type
{
	NUMBERS,
	TO_DIE,
	TO_EAT,
	TO_SLEEP,
	EAT_ROUNDS
}					t_arg_type;

// The status of a philosopher
typedef enum a_status
{
	GET_FORK,
	EATING,
	THINKING,
	SLEEPING,
	DEAD
}					t_status;

// Represents a game.
// `args`: The arguments, the index is `t_arg_type`.
// `even_or_odd` : 4 philosopher or 5?
// `is_over` Is the game over?
// `threads`: The array of threads.
// `locks`: The array of mutex.
// `forks`: The array of forks, DATA RACE! MUST be protected by lock.
// `rounds`: How many times the philo ate, DATA RACE! MUST be protected by lock.
typedef struct s_game
{
	int				args[5];
	bool			even_or_odd;
	bool			is_over;
	pthread_t		*threads;
	pthread_mutex_t	*locks;
	bool			*forks;
	int				*rounds;
}					t_game;

// Represents a message
// `timestamp`: the timestamp of a message.
// `idx`: the index of a philo.
// `status`: the event of a philo.
typedef struct s_msg
{
	int				timestamp;
	int				idx;
	t_status		event;
}					t_msg;

// Represents a message queue.
// `msgs`: the messages in the queue.
// `size`: the size of message queue.
// `head`: the index of first unread message.
// `lock`: the mutex of the mq.
typedef struct s_mq
{
	t_msg			*msgs;
	int				size;
	int				head;
	pthread_mutex_t	lock;
}					t_mq;

t_game				*return_null_and_free(t_game **game);
void				close_mutexes(int count, pthread_mutex_t *mutexes);

#endif