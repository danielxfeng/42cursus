/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:53:47 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/12 00:23:58 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*prev;
	char		*p;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	prev = NULL;
	while (1)
	{
		if (buf)
		{
			p = parse_from_buf(&buf, &prev);
			if (p)
				return (p);
			if (!p && !buf)
				return (NULL);
		}
		p = parse_from_file(fd, &buf, &prev);
		if (p)
			return (p);
		if (!p && !buf)
			return (NULL);
	}
}

char	*parse_from_file(int fd, char **buf, char **prev)
{
	ssize_t	bytes;

	*buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buf)
		return (return_null(prev, NULL));
	bytes = read(fd, *buf, BUFFER_SIZE);
	if (bytes <= 0)
		return (return_null(prev, buf));
	(*buf)[bytes] = '\0';
	if (!join_str(prev, buf))
		return (return_null(prev, buf));
	return (NULL);
}

char	*parse_from_buf(char **buf, char **prev)
{
	char	*p;

	if (!buf || !*buf)
		return (NULL);
	p = split_str_by_lb(buf);
	if (!p)
	{
		free(*buf);
		*buf = NULL;
		return (NULL);
	}
	if (!(*buf)[0])
	{
		free(*buf);
		*buf = NULL;
	}
	if (*buf || p[str_length(p) - 1] == '\n')
		return (p);
	*prev = p;
	return (NULL);
}

char	*return_null(char **prev, char **buf)
{
	if (prev)
	{
		free(prev);
		*prev = NULL;
	}
	if (buf)
	{
		free(buf);
		*buf = NULL;
	}
	return (NULL);
}

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
	char	*l;
	char	*r;
	size_t	i;

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
