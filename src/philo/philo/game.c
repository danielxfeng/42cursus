/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:44:05 by Xifeng            #+#    #+#             */
/*   Updated: 2025/02/01 10:26:56 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// @brief the coordinate role of the game
//
// It reads message from mq, and print it.
// When someone is dead, just set the close flag of mq..
// It also sets the close flag if all the philos ate enough rounds.
//
// @param game: the pointer to game.
void	coordinate(t_game *game)
{
	int		i;
	bool	can_stop;

	while (print_message(game->mq))
	{
		usleep(5 * MS);
		if (game->args[EAT_ROUNDS] == -1)
			continue ;
		i = 0;
		can_stop = true;
		while (i < game->args[NUMBERS])
		{
			if (game->rounds[i++] < game->args[EAT_ROUNDS])
			{
				can_stop = false;
				break ;
			}
		}
		if (can_stop)
		{
			send_message(game->mq, get_ts(), 0, ENOUGH_ROUNDS);
			print_message(game->mq);
			break ;
		}
	}
}

// @brief helper function of start_game
//
// @param: params: the array of params.
// @param: i: the idx of philo.
// @return: false on error, otherwise returns true.
static bool	start_game_helper(t_th_param *params, int i)
{
	if (pthread_create(&(params[0].game->threads[i - 1]), NULL, philo,
			&(params[i - 1])) != 0)
	{
		return_null_and_free(&(params[0].game));
		free(params);
		printf("ERROR\n");
		return (false);
	}
	return (true);
}

// @brief start the game.
//
// Process:
// 1 Prepare the params for each thread.
// 2 Start the threads.
// 3 Play as coordinator.
// 4 Wait when all the threads close.
// 5 Close.
//
// @param argc: the count of args.
// @param argv: the array of args.
// @return: 0 on success, 1 on error.
int	start_game(int argc, char **argv)
{
	int			i;
	t_th_param	*params;
	int			args[5];

	params = create_params(argc, argv, args);
	if (!params)
	{
		printf("ERROR\n");
		return (1);
	}
	i = 0;
	while (i++ < params[0].game->args[NUMBERS])
	{
		if (!start_game_helper(params, i))
			return (1);
	}
	coordinate(params[0].game);
	i = 0;
	while (i++ < params[0].game->args[NUMBERS])
		pthread_join(params[0].game->threads[i - 1], NULL);
	return_null_and_free(&(params[0].game));
	free(params);
	return (0);
}

int	main(int argc, char **argv)
{
	return (start_game(argc, argv));
}
