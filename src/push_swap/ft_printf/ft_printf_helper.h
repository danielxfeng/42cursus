/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:36:05 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/23 20:44:58 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HELPER_H
# define FT_PRINTF_HELPER_H

#include "../libft/libft.h"
#include "unistd.h"

int		print_char(char c);
int		print_str(char *s);
int		print_ptr(void *ptr);
int		print_nbr(int n);
int		print_hex(unsigned int n, int is_lowercase);
int		print_unsigned_nbr(unsigned int n);

#endif