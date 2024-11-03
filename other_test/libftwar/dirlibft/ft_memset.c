/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:28:49 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/02 14:20:02 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*stop;

	ptr = s;
	stop = (unsigned char *)s + n;
	while (ptr < stop)
	{
		*ptr = c;
		++ptr;
	}
	return (s);
}
