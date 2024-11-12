/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:52:47 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/12 14:08:11 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30720
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*parse_from_file(int fd, char **buf, char **prev);
char	*parse_from_buf(char **buf, char **prev);
char	*return_null(char **prev, char **buf);
ssize_t	str_length(char *s);
int		join_str(char **prev, char **buf);
char	*split_str_by_lb(char **s);
char	*split_helper(char **s, ssize_t idx);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
