/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:53:47 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/12 13:36:51 by Xifeng           ###   ########.fr       */
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
