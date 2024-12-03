/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:42:46 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 14:59:44 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void		free_parameter(char ***parameter);

// A helper function to deal with the file error.
static void	close_fd_and_exit(int fd, char *msg)
{
	close(fd);
	exit_prog(NULL, NULL, NULL, msg);
}

// Parse the parameter with map file checking.
// Returns a null-termited string array.
static char	**parse_parameter(char *file_name)
{
	int		fd;
	ssize_t	bytes_read;
	char	buf[38416];
	char	**parameter;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_prog(NULL, NULL, NULL, "Error on opening a map.");
	bytes_read = read(fd, buf, 38416);
	if (bytes_read == -1)
		close_fd_and_exit(fd, "Error on opening a map.");
	if (bytes_read == 0)
		close_fd_and_exit(fd, "Cannot open an empty map.");
	if (bytes_read == 38416)
		close_fd_and_exit(fd, "Cannot handle too big map.");
	close(fd);
	buf[bytes_read] = '\0';
	if ((*buf && (buf[0] == '\n')) || ft_strnstr(buf, "\n\n", bytes_read))
		close_fd_and_exit(fd, "The map should be a rectangle.");
	parameter = ft_split(buf, '\n');
	if (!parameter)
		exit_prog(NULL, NULL, NULL,
			"Memory allocation failed: parsing the map.");
	return (parameter);
}

// Start the mlx engine.
// 1 register a key hook to handle the key press event.
// 2 register a window close hook to handle the closing window event.
// 3 enter the mlx loop.
void	start_mlx_engine(t_game *game)
{
	t_param	*p;

	p = malloc(sizeof(t_param));
	if (!p)
		exit_prog(&game, NULL, NULL,
			"Memory allocation failed: controller creation.");
	p->view = create_view(game);
	if (!p->view)
		exit_prog(&game, NULL, NULL,
			"Memory allocation failed: view creation.");
	p->game = game;
	mlx_key_hook(p->view->mlx, handle_key_press_event, p);
	mlx_close_hook(p->view->mlx, handle_win_close_event, p);
	mlx_loop(p->view->mlx);
	exit_and_close_param(&p, "Cannot enter the loop.");
}

// Entry point here.
// Initialize the resource and hand over to the controller.
// The game engine should free the memory before quit.
int	so_long(int argc, char **argv, void(engine_start)(t_game *game))
{
	char	**parameter;
	t_game	*game;
	size_t	len;

	if (argc != 2)
		exit_prog(NULL, NULL, NULL, "Please specify a map file.");
	len = (int)ft_strlen(argv[1]);
	if (len < 5 || argv[1][len - 4] != '.' || argv[1][len - 3] != 'b'
		|| argv[1][len - 2] != 'e' || argv[1][len - 1] != 'r')
		exit_prog(NULL, NULL, NULL, "Map file should be endwith '.ber'.");
	parameter = parse_parameter(argv[1]);
	validate_parameter(parameter);
	game = create_game(ft_strlen(parameter[0]), str_arr_len(parameter),
			parameter);
	if (!path_check(game))
		exit_prog(&game, &parameter, NULL,
			"There is no valid path in the map.");
	free_parameter(&parameter);
	if (engine_start)
		engine_start(game);
	exit_prog(&game, NULL, NULL, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	so_long(argc, argv, start_mlx_engine);
}
