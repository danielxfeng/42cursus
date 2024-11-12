/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:53:40 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/12 13:37:20 by Xifeng           ###   ########.fr       */
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
		while ((*prev)[i])
			p[i] = (*prev)[i++];
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
	size_t	i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while ((*s)[i] && (*s)[i] != '\n')
		++i;
	if ((*s)[i] == '\n')
		++i;
	return (split_helper(s, i));
}

char	*split_helper(char **s, size_t idx)
{
	char *l;
	char *r;
	size_t i;

	l = malloc((idx + 1) * sizeof(char));
	if (!l)
		return (NULL);
	r = malloc((str_length(*s) - idx + 1) * sizeof(char));
	if (!r)
	{
		free(l);
		return (NULL);
	}
	i = 0;
	while (i < idx)
		l[i] = (*s)[i++];
	l[i] = '\0';
	while (i < str_length(*s))
		r[i - idx] = (*s)[i++];
	free(*s);
	*s = r;
	return (l);
}
