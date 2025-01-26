/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:19:46 by Xifeng            #+#    #+#             */
/*   Updated: 2025/01/26 16:39:33 by Xifeng           ###   ########.fr       */
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

// Represents a message queue.
// `ts`: the timestamps of messages.
// `ids`: the ids of philos.
// `eventss`: the events of philos.
// `read`: the read index of message queue.
// `write`: the write index of first unread message.
// `lock`: the mutex of the mq.
// `capacity`: the capacity of a mq.
// `is_closed`: is the mq closed?
typedef struct s_mq
{
	long long		*ts;
	int				*ids;
	int				*events;
	int				read;
	int				write;
	int				capacity;
	bool			is_closed;
	pthread_mutex_t	lock;
}					t_mq;

// Represents a game.
// `args`: The arguments, the index is `t_arg_type`.
// `even_or_odd` : 4 philosopher or 5?
// `threads`: The array of threads.
// `forks`: The array of forks.
// `rounds`: How many times the philo ate, DATA RACE! MUST be protected by lock.
typedef struct s_game
{
	int				args[5];
	bool			even_or_odd;
	pthread_t		*threads;
	t_mq			*mq;
	pthread_mutex_t	*forks;
	int				*rounds;
}					t_game;

// Represents a timestamp.
typedef struct s_timeval {
    time_t 		tv_sec;
    suseconds_t tv_usec;
}				   t_timeval;

t_game				*return_null_and_free(t_game **game);
void				close_mutexes(int count, pthread_mutex_t *mutexes);

t_mq *create_mq(int capacity);
t_mq *close_mq(t_mq **mq, bool has_lock);
bool send_message(t_mq *mq, int ts, int id, int event);
static bool print_message_helper(t_mq *mq);

long long get_ts();

#endif