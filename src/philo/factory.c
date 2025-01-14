/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:36:31 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/18 08:32:00 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

// Constructor of the mutexes.
pthread_mutex_t *create_mutexes(t_game *game)
{
    int             i;
    pthread_mutex_t *mutexes;
    
    mutexes = malloc(game->args[NUMBERS] * sizeof(pthread_mutex_t));
    if (!mutexes)
        return (NULL);
    memset(mutexes, 0, game->args[NUMBERS] * sizeof(pthread_mutex_t));
    i = 0;
    while (i < game->args[NUMBERS])
    {
        if (pthread_mutex_init(&(mutexes[i]), NULL) != 0)
        {
            close_mutexes(game->args[NUMBERS], mutexes);
            return (NULL);
        }
        ++i;
    }
    return (mutexes);
}

// Constructor of a game.
t_game *create_game(int argc, int *args)
{
    int     i;
    t_game  *game;
    
    game = malloc(sizeof(t_game));
    if (!game)
        return (NULL);
    memset(game, 0, sizeof(t_game));
    i = 0;
    while (i++ < argc)
        game->args[i - 1] = args[i - 1];
    game->forks = malloc(game->args[NUMBERS] * sizeof(bool));
    if (!game->forks)
        return (return_null_and_free(&game));
    memset(game->forks, 0, game->args[NUMBERS] * sizeof(bool));
    game->mutexes = create_mutexes(game);
    if (!game->mutexes)
        return (return_null_and_free(&game));
    return (game);
}
