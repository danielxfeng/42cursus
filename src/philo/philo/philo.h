/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:19:46 by Xifeng            #+#    #+#             */
/*   Updated: 2025/01/30 19:13:02 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>

#define MS 1000LL

#define INFO_FORK "has taken a fork"
#define INFO_EAT "is eating"
#define INFO_SLEEP "is sleeping"
#define INFO_THINK "is thinking"
#define INFO_DEAD "is died"

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
	DEAD,
	ENOUGH_ROUNDS,
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
// `ready_thread`: How many threads are ready.  
// `forks`: The array of forks.
// `rounds`: How many times the philo ate, DATA RACE! MUST be protected by lock.
typedef struct s_game
{
	int				*args;
	bool			even_or_odd;
	pthread_t		*threads;
	t_mq			*mq;
	int     		ready_threads;
	pthread_mutex_t	*forks;
	int				*rounds;
}					t_game;

// Represents the params of a philo thread.
typedef struct s_th_param
{
	t_game			*game;
	int				i;
	int				next_status;
}					t_th_param;

t_th_param			*create_params(int argc, char **argv, int *args);

void				close_game(t_game **game);
t_game				*return_null_and_free(t_game **game);
void				close_mutexes(int count, pthread_mutex_t *mutexes);

t_mq				*create_mq(int capacity);
t_mq				*close_mq(t_mq **mq, bool has_lock);
bool	send_message(t_mq *mq, long long ts, int id, int event);
bool				print_message(t_mq *mq);

void				*philo(void *arg);

long long			get_ts(void);
bool				philo_atoi(const char *nptr, int *n);
int					pp(t_game *game, int idx);

int	start_game(int argc, char **argv);

#endif