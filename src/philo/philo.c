/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:57:15 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/17 15:06:37 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

t_philo *create_philo(int idx)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    philo->idx = idx + 1;
    philo->time_stamp = gettimeofday(NULL, NULL);
    philo->status = THINKING;
    philo->forks_i_have = 0;
    return (philo);
}

