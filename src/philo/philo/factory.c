/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:36:31 by Xifeng            #+#    #+#             */
/*   Updated: 2025/01/26 15:27:13 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

// @brief Constructor of the mutexes.
// 
// @param game: the pointer to game.
// @returns: the array of mutexes.
pthread_mutex_t *create_mutexes(t_game *game)
{
    int             i;
    pthread_mutex_t *mutexes;
    
    mutexes = malloc(game->args[NUMBERS] * sizeof(pthread_mutex_t));
    if (!mutexes)
        return (NULL);
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

// @brief The helper function for create_game.
//
// @parms game: the pointer to game.
// @return: the pointer to game.
static t_game *create_game_helper(t_game *game)
{
    game->forks = create_mutexes(game);
    if (!game->forks)
        return (return_null_and_free(&game));
    game->rounds = malloc(game->args[NUMBERS] * sizeof(int));
    if (!game->rounds)
        return (return_null_and_free(&game));
    memset(game->rounds, 0, game->args[NUMBERS] * sizeof(int));
    return (game);
}

// @brief Constructor of a game.
//
// @param argc: the count of args.
// @param args: the array of args.
// @return: the pointer to game.
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
    game->even_or_odd = args[NUMBERS] % 2;
    game->threads = malloc((game->args[NUMBERS] + 1) * sizeof(pthread_t));
    if (!game->threads)
        return (return_null_and_free(&game));
    game->mq = create_mq(args[NUMBERS] * 2);
    if (!game->mq)
        return (return_null_and_free(&game));
    if (!create_game_helper(game))
        return (NULL);
    return (game);
}
