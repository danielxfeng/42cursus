/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:07:52 by Xifeng            #+#    #+#             */
/*   Updated: 2025/01/26 15:27:57 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

// Destructor of mutexes.
void close_mutexes(int count, pthread_mutex_t *mutexes)
{
    int i;

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
void close_game(t_game **game)
{
    int i;
    if (game && *game)
    {
        if ((*game)->threads)
        {
            i = 0;
            while (i <= (*game)->args[NUMBERS])
                pthread_join((*game)->threads[i++], NULL);
            free((*game)->threads);
        }
        (*game)->threads = NULL;   
        if ((*game)->mq)
            (*game)->mq = close_mq(&((*game)->mq), true);
        close_mutexes((*game)->args[NUMBERS], (*game)->forks);
        (*game)->forks = NULL;
        free(*game);
        *game = NULL;
    }
}

// close the game then return NULL.
t_game  *return_null_and_free(t_game **game)
{
    close_game(game);
    return (NULL);
}
