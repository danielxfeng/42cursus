/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:59:59 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/23 19:01:16 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HELPER_H
# define FT_PRINTF_HELPER_H

# include <unistd.h>

int		print_char(char c);
int		print_str(char *s);
int		print_ptr(void *ptr);
int		print_nbr(int n);
int		print_hex(unsigned int n, int is_lowercase);
int		print_unsigned_nbr(unsigned int n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strlen(const char *s);

#endif