/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:13:15 by Xifeng            #+#    #+#             */
/*   Updated: 2024/10/25 22:07:32 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(int out, char c);
int		ft_putstr(int out, char *str);

void	print_file(int fd)
{
	char	c;

	while (read(fd, &c, 1))
	{
		ft_putchar(1, c);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*filename;

	if (argc == 1)
		return (ft_putstr(2, "File name missing.\n"));
	if (argc > 2)
		return (ft_putstr(2, "Too many arguments.\n"));
	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr(2, "Can not open file"));
	ft_putstr(1, "*content of file ");
	ft_putstr(1, filename);
	ft_putstr(1, "*\n");
	print_file(fd);
	close(fd);
}
