/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:03:54 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/27 22:13:32 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_lang.h"
#include "libft/libft.h"
#include <stdlib.h>

// The constructor of Player.
// Will not free anything here, the caller should do it.
t_player *create_player(char *name)
{
    t_player *player;

    player = malloc(sizeof(t_player));
    if (!player)
        return (NULL);
    player->prev_x = -1;
    player->prev_y = -1;
    player->collectible = 0;
    player->movements = 0;
    if (!name)
        player->name = ft_strdup("player");
    else
        player->name = ft_strdup(name);
    if (!player->name)
        return (NULL);
    return (player);
}

// The constructor of Tile.
// Will not free anything here, the caller should do it.
t_tile *create_tile(int x, int y, char c)
{
    t_tile *tile;

    if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
        return (NULL);
    tile = malloc(sizeof(t_tile));
    if (!tile)
        return (NULL);
    tile->x = x;
    tile->y = y;
    if (c == '1')
        tile->type = tile_wall;
    else
        tile->type = tile_path;
    tile->is_collectible = false;
    tile->is_exit = false;
    tile->is_player = false;
    if (c == 'C')
        tile->is_collectible = true;
    if (c == 'E')
        tile->is_exit = true;
    if (c == 'P')
        tile->is_player = true;
    return (tile);
}

// The constructor of Board.
// Will not free anything here, the caller should do it.
t_tile ***create_board(int length, int height, char **parameter, t_player *player)
{
    int i;
    int j;
    t_tile ***board;
    bool has_start_point;
    bool has_exit;

    has_start_point = false;
    has_exit = false;
    board = malloc(height * sizeof(t_tile *));
    if (!board)
        return (NULL);
    i = 0;
    while (i < height)
    {
        board[i] = malloc(length * sizeof(t_tile *));
        if (!board[i])
            return (NULL);
        j = 0;
        while (j < length)
        {
            board[i][j] = create_tile(j, i, parameter[i][j]);
            if (!board[i][j])
                return (NULL);
            if (parameter[i][j] == 'P')
            {
                if (has_start_point)
                    return (NULL);
                has_start_point = true;
                player->x = j;
                player->y = i;
            }
            if (parameter[i][j] == 'E')
            {
                if (has_exit)
                    return (NULL);
                has_exit = true;
            }
            ++j;
        }
        ++i;
    }
    if (!has_start_point)
        return (NULL);
    return (board);
}

// The constructor of Game.
// Will not free anything here, the caller should do it.
t_game *create_game(int length, int height, char *name, char **parameter)
{
    t_game *game;
    t_player *player;
    t_tile ***board;
    
    if (length <= 0 || height <= 0)
        return (NULL);
    game = malloc(sizeof(t_game));
    if (!game)
        return (NULL);
    game->length = length;
    game->height = height;
    game->player = create_player(name);
    if (!game->player)
        return (NULL);
    game->status = status_not_start;
    game->board = create_board(length, height, parameter, player);
    if (!game->board)
        return (NULL);
    return (&game);
}
