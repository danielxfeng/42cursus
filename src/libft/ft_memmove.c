/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:30:07 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/02 14:19:59 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	const unsigned char	*stop;

	ptr_dest = dest;
	ptr_src = src;
	stop = src + n;
	if (ptr_dest > ptr_src)
	{
		ptr_dest += n;
		while (stop > ptr_src)
		{
			*(ptr_dest - 1) = *(stop - 1);
			--stop;
			--ptr_dest;
		}
		return (dest);
	}
	while (ptr_src < stop && (ptr_dest || ptr_dest))
	{
		*ptr_dest = *ptr_src;
		++ptr_src;
		++ptr_dest;
	}
	return (dest);
}
