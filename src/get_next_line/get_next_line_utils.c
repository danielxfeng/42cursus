/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:53:40 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/12 14:54:21 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	str_length(char *s)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		++i;
	return (i);
}

int	join_str(char **prev, char **buf)
{
	ssize_t	len;
	char	*p;
	size_t	i;
	size_t	j;

	len = str_length(*prev) + str_length(*buf);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	if (*prev)
	{
		ft_memcpy(p, *prev, str_length(*prev));
		i = str_length(*prev);
	}
	j = 0;
	while ((*buf)[j])
		p[i++] = (*buf)[j++];
	p[i] = '\0';
	free(*prev);
	free(*buf);
	*prev = NULL;
	*buf = p;
	return (1);
}

char	*split_str_by_lb(char **s)
{
	ssize_t	i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while ((*s)[i] && (*s)[i] != '\n')
		++i;
	if ((*s)[i] == '\n')
		++i;
	return (split_helper(s, i));
}

char	*split_helper(char **s, ssize_t idx)
{
	char	*l;
	char	*r;

	l = malloc((idx + 1) * sizeof(char));
	if (!l)
		return (NULL);
	r = malloc((str_length(*s) - idx + 1) * sizeof(char));
	if (!r)
	{
		free(l);
		return (NULL);
	}
	ft_memcpy(l, *s, idx);
	l[idx] = '\0';
	ft_memcpy(r, &(*s)[idx], str_length(*s) - idx);
	free(*s);
	*s = r;
	return (l);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
