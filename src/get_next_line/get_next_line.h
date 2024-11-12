/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:52:47 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/12 13:38:18 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30720
# endif

# include <unistd.h>

ssize_t	str_length(char *s);
int		join_str(char **prev, char **buf);
char	*split_str_by_lb(char **s);
char	*split_helper(char **s, size_t idx);

#endif
