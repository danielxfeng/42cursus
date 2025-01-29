/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:36:31 by Xifeng            #+#    #+#             */
/*   Updated: 2025/01/29 16:01:43 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

// @brief Constructor of the mutexes.
//
// @param game: the pointer to game.
// @returns: the array of mutexes.
static pthread_mutex_t	*create_mutexes(t_game *game)
{
	int				i;
	pthread_mutex_t	*mutexes;

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
static t_game	*create_game_helper(t_game *game)
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
// @param args: the pointer to args.
// @return: the pointer to game.
static t_game	*create_game(int *args)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	memset(game, 0, sizeof(t_game));
	game->args = args;
	game->even_or_odd = args[NUMBERS] % 2;
	game->threads = malloc(game->args[NUMBERS] * sizeof(pthread_t));
	if (!game->threads)
		return (return_null_and_free(&game));
	game->mq = create_mq(args[NUMBERS] * 2);
	if (!game->mq)
		return (return_null_and_free(&game));
	if (!create_game_helper(game))
		return (NULL);
	return (game);
}

// @brief the helper function for crate_params.st
static void	create_params_helper(t_th_param *params, t_game *game, int *args)
{
	int	i;

	i = 0;
	while (i < args[NUMBERS])
	{
		params[i].game = game;
		params[i].i = i;
		if (i % 2)
			params[i].next_status = THINKING;
		else
			params[i].next_status = EATING;
		++i;
	}
}

// @brief create an array of params for each thread.
//
// @param argc: the count of args.
// @param argv: the array of args.
// @param args: the container of args.
t_th_param	*create_params(int argc, char **argv, int *args)
{
	int			i;
	int			n;
	t_th_param	*params;
	t_game		*game;

	if (argc != 5 && argc != 6)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!philo_atoi(argv[i], &n))
			return (NULL);
		args[i++ - 1] = n;
	}
	if (argc == 5)
		args[4] = -1;
	game = create_game(args);
	if (!game)
		return (NULL);
	params = malloc(sizeof(t_th_param) * args[NUMBERS]);
	if (!params)
		return (NULL);
	create_params_helper(params, game, args);
	return (params);
}
