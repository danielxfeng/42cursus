/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:37:36 by Xifeng            #+#    #+#             */
/*   Updated: 2024/10/25 10:39:59 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	char	*c;

	c = str;
	while (*c != '\0')
	{
		ft_putchar(*c);
		++c;
	}
}

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		++i;
	}
}
