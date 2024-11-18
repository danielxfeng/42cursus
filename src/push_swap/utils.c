/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 07:26:50 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/18 10:24:29 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>

// A modified atoi.
// The parsed value is `*n`, returns `true` on success, or `false` on error.
bool	my_atoi(const char *nptr, int *n)
{
	int		sign;
    size_t length;
	long long	ln;

	while (*nptr && (*nptr >= 9 && *nptr <= 13 || *nptr == 32))
		++nptr;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	ln = 0;
    length = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
        ++length;
		ln = ln * 10 + *nptr - '0';
		++nptr;
	}
    if (!length || length > 10 || ln * sign > INT_MAX || ln * sign < INT_MIN)
        return (false);
	*n = ((int)(ln * sign));
    return (true);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        ++i;
    write(1, s, i);
}
