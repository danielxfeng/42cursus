/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:27:49 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/09 20:24:18 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_supp.h"
#include "../libft/libft.h"

// ft_strlen, but returns `0` when `s` is NULL.
size_t	str_len(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

// Appends `chars` to the end of `str`.
// `str` should be dynamically allocated (on the heap).
// `chars` is not null-terminated; `len` specifies its length.
// If `malloc` fails, `*str` is freed and set to NULL.
void	append_str_in_heap(char **str, char *chars, size_t len)
{
	char	*res;
	size_t	i;
	size_t	len_str;

	if ((!*str || **str == '\0') && !len)
		return (free_helper(str));
	len_str = str_len(*str);
	res = malloc((len_str + len + 1) * sizeof(char));
	if (!res)
		return (free_helper(str));
	i = 0;
	while (i++ < len_str)
		res[i - 1] = (*str)[i - 1];
	if (len_str)
		free_helper(str);
	i = 0;
	while (i++ < len)
		res[i + len_str - 1] = chars[i - 1];
	res[i + len_str - 1] = '\0';
	*str = res;
}

static char	*extract_free_helper(char **s1, char **s2)
{
	if (s1)
		free_helper(s1);
	if (s2)
		free_helper(s2);
	return (NULL);
}

// Extract one line from `str`
// `idx` is the position of first lb.
// If `malloc` fails, `*str` is freed and set to NULL.
char	*extract_line(char **str, size_t idx)
{
	char	*left;
	char	*right;
	size_t	len;

	left = malloc((idx + 2) * sizeof(char));
	if (!left)
		return (extract_free_helper(str, NULL));
	len = str_len(*str);
	ft_memcpy(left, *str, idx + 1);
	left[idx + 1] = '\0';
	if (len - idx > 1)
	{
		right = malloc((len - idx) * sizeof(char));
		if (!right)
			return (extract_free_helper(&left, str));
		ft_memcpy(right, &((*str)[idx + 1]), len - idx - 1);
		right[len - idx - 1] = '\0';
		free_helper(str);
		*str = right;
	}
	else
		free_helper(str);
	return (left);
}
