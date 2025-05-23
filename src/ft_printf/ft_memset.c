/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:28:49 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/23 19:10:04 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helper.h"

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
