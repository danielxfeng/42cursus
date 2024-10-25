/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:51:38 by Xifeng            #+#    #+#             */
/*   Updated: 2024/10/25 19:04:53 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*c;

	len = ft_strlen(src);
	c = malloc(len + 1);
	if (!c)
		return (0);
	i = 0;
	while (i < len)
	{
		c[i] = src[i];
		++i;
	}
	c[i] = '\0';
	return (c);
}
