/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:25:33 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/02 16:45:41 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

    if (s == 0)
        return (0);
	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return (void *)(p + i);
		++i;
	}
	return (0);
}