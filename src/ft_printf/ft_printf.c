/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:49:44 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/07 23:20:40 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>

static int	print_format_str(const char *str, va_list args)
{
	if (*str == 'c')
		return (print_char((char)va_arg(args, int)));
	if (*str == 's')
		return (print_str(va_arg(args, char *)));
	if (*str == 'p')
		return (print_ptr(va_arg(args, void *)));
	if (*str == 'd')
		return (print_decimal(va_arg(args, int)));
	if (*str == 'i')
		return (print_int(va_arg(args, int)));
	if (*str == 'u')
		return (print_unsigned_decimal(va_arg(args, unsigned int)));
	if (*str == 'x')
		return (print_hex_lowercase(va_arg(args, unsigned int)));
	if (*str == 'X')
		return (print_hex_uppercase(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			++i;
			if (!str[i]) // invalid
				break ;
			if (str[i] == '%') // %
				count += print_char('%');
			else
				count += print_format_str(str[i], args);
		}
		else
			count += print_char(str[i]);
		++i;
	}
	va_end(args);
	return (count);
}
