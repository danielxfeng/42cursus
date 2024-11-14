/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:27:29 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/14 21:16:03 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(char *s);
void	append_str_in_heap(char **str, char *chars, size_t len);
char	*extract_line(char **str, size_t idx);
void	*ft_memcpy(void *dest, const void *src, size_t n);

void	free_helper(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

// Returns the index of the first linebreaker in `s`.
// Returns -1 when not found.
static ssize_t	first_lb(const char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

static char	*replicate_str(char **str)
{
	char	*res;
	size_t	len;

	len = str_len(*str);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
	{
		free_helper(str);
		return (NULL);
	}
	ft_memcpy(res, *str, len);
	res[len] = '\0';
	free_helper(str);
	return (res);
}

int	read_from_file(int fd, char **cache, ssize_t *bytesread)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
	{
		free_helper(cache);
		return (0);
	}
	*bytesread = read(fd, buf, BUFFER_SIZE);
	if (*bytesread == -1)
		free_helper(cache);
	else
		append_str_in_heap(cache, buf, *bytesread);
	free_helper(&buf);
	if (*bytesread == -1 || !*cache)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	ssize_t		idx;
	ssize_t		bytesread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytesread = 1;
	while (1)
	{
		if (cache)
		{
			idx = first_lb(cache);
			if (idx != -1)
				return (extract_line(&cache, idx));
			if (!bytesread)
				return (replicate_str(&cache));
		}
		if (!read_from_file(fd, &cache, &bytesread))
			return (NULL);
	}
}

