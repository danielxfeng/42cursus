/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 07:26:50 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/18 20:07:02 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
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
    if (*nptr || !length || length > 10 || ln * sign > INT_MAX || ln * sign < INT_MIN)
        return (false);
	*n = ((int)(ln * sign));
    return (true);
}

void ft_putstr(char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        ++i;
    write(1, s, i);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	const unsigned char	*stop;

	ptr_dest = dest;
	ptr_src = src;
	if (!ptr_dest && !ptr_src)
		return (dest);
	stop = src + n;
	while (ptr_src < stop)
	{
		*ptr_dest = *ptr_src;
		++ptr_src;
		++ptr_dest;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	d_len;
	char	*p;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		d_len = 0;
	else
	{
		if (s_len - start < len)
			d_len = s_len - start;
		else
			d_len = len;
	}
	p = malloc(d_len + 1 * sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, s + start, d_len);
	p[d_len] = '\0';
	return (p);
}
