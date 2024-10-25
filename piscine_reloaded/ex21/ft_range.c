/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:05:51 by Xifeng            #+#    #+#             */
/*   Updated: 2024/10/25 19:09:32 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*arr;

	len = max - min;
	if (len <= 0)
		return (0);
	arr = malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		arr[i] = min + i;
		++i;
	}
	return (arr);
}
