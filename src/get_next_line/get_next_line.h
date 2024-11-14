/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:21:15 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/14 15:56:05 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	str_len(char *s);
void	free_helper(char **str);
void	append_str_in_heap(char **str, char *chars, size_t len);
char	*extract_line(char **str, size_t idx);
void	*ft_memcpy(void *dest, const void *src, size_t n);
ssize_t	first_lb(const char *s);
int		read_from_file(int fd, char **cache, ssize_t *bytesread);
char	*get_next_line(int fd);
char	*replicate_str(char **str);

#endif