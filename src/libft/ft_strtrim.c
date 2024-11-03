/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:10:30 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/03 14:44:05 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*p;

	if (!s1 || !set)
		return (char *)(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		--end;
	p = ft_calloc(end - start + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1 + start, end - start);
	p[end - start] = '\0';
	return (p);
}
