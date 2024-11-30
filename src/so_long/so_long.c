/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:42:46 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/30 12:23:36 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

// A helper function to deal with the file error.
static void close_fd_and_exit(int fd, char *msg)
{
    close(fd);
    exit_prog(NULL, NULL, msg);
}

// Parse the parameter with map file checking.
// Returns a null-termited string array.
static char **parse_parameter(char *file_name)
{
    int fd;
    ssize_t bytes_read;
    char buf[38416];
    char **parameter;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        exit_prog(NULL, NULL, "Error on opening a map.");
    bytes_read = read(fd, buf, 38416);
    if (bytes_read == -1)
        close_fd_and_exit(fd, "Error on opening a map.");
    if (bytes_read == 0)
        close_fd_and_exit(fd, "Cannot open an empty map.");
    if (bytes_read == 38416)
        close_fd_and_exit(fd, "Cannot handle too big map.");
    close(fd);
    buf[bytes_read] = '\0';
    parameter = ft_split(buf, '\n');
    if (!parameter)
        exit_prog(NULL, NULL, "Memory allocation failed: parsing the map.");
    return (parameter);
}

// Entry point here.
// 1 Check the parameter length first.
// 2 Parse the map (with map file validation).
// 2 Validate the parameter (check map file).
// 3 Create the map.
// 4 Check if the path is valid.
int so_long(int argc, char** argv)
{
    char **parameter;
    t_game *game;
    
    if (argc != 2)
        exit_prog(NULL, NULL, "Please specify a map file.");
    parameter = parse_parameter(argv[1]);
    validate_parameter(parameter);
    game = create_game(ft_strlen(parameter[0]), str_arr_len(parameter), parameter);
    if (!path_check(game))
        exit_prog(&game, &parameter, "There is no valid path in the map.");
    start_game(game);
    exit_prog(&game, &parameter, NULL);
}

/**
int main(int argc, char** argv)
{
    so_long(argc, argv);
}
*/
