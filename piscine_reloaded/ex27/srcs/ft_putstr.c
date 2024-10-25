/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:48:27 by Xifeng            #+#    #+#             */
/*   Updated: 2024/10/25 22:07:06 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int out, char c)
{
	write(out, &c, 1);
}

int	ft_putstr(int out, char *str)
{
	char	*c;

	c = str;
	while (*c != '\0')
	{
		ft_putchar(out, *c);
		++c;
	}
	if (out == 1)
		return (0);
	return (1);
}
