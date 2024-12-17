/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:19:46 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/17 14:56:28 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>

// The status of a philosopher
typedef enum a_status
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}				t_status;

// Represents a philosopher.
// `idx`: index.
// `status`: status.
// `forks_i_have`: how many forks I do have.
// `time_stamp`: the time stamp of last activity.
typedef struct s_philo
{
	int			idx;
	t_status	status;
	int			forks_i_have;
	int			time_stamp;
}				t_philo;

// Represents a game.
// `numbers`: how many philoshpers.
// `to_die`: If a philosopher didn’t start eating time_to_die milliseconds since
//           the beginning of their last meal or the beginning of the simulation,
//           they die.
// `to_eat`: The time it takes for a philosopher to eat. During that time, they
//           will need to hold two forks.
// `to_sleep`: The time a philosopher will spend sleeping.
// `eat_times`: If all philosophers have eaten at least eat_times,
//              the simulation stops. If not specified(-1), the simulation stops
//              when a philosopher dies.
// `free_forks`: how many free forks.
// `philos`: The array of philoshpers.
typedef struct s_game
{
	int			numbers;
	int			to_die;
	int			to_eat;
	int			to_sleep;
	int			eat_times;

	int			free_forks;
	t_philo		**philos;
}				t_game;

#endif