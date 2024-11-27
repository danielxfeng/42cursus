/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 07:26:50 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/27 19:00:53 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

// A modified atoi that reject invalid value and overflow.
// The parsed value is `*n`, returns `true` on success, or `false` on error.
bool	ps_atoi(const char *nptr, int *n)
{
	int			sn;
	size_t		len;
	long long	ln;

	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		++nptr;
	sn = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sn = -1;
		++nptr;
	}
	ln = 0;
	len = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		++len;
		ln = ln * 10 + *nptr - '0';
		++nptr;
	}
	if (*nptr || !len || len > 10 || ln * sn > INT_MAX || ln * sn < INT_MIN)
		return (false);
	*n = ((int)(ln * sn));
	return (true);
}

// To free a string array.
bool	free_str_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return (false);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
	return (false);
}
