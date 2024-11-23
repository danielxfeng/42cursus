/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:49:44 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/23 19:10:10 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helper.h"
#include <stdarg.h>
#include <unistd.h>

int	print_nbr(int n)
{
	long long	ln;
	char		buf[16];
	int			count;
	size_t		i;

	ln = n;
	count = 0;
	if (ln < 0)
	{
		count += write(1, "-", 1);
		ln = -ln;
	}
	ft_bzero(buf, 16);
	i = 15;
	while (ln >= 10)
	{
		buf[i--] = ln % 10 + '0';
		ln /= 10;
	}
	buf[i--] = ln + '0';
	count += write(1, &buf[i + 1], 15 - i);
	return (count);
}

static int	print_format_str(const char *str, va_list *args)
{
	if (*str == 'c')
		return (print_char((char)va_arg(*args, int)));
	if (*str == 's')
		return (print_str(va_arg(*args, char *)));
	if (*str == 'p')
		return (print_ptr(va_arg(*args, void *)));
	if (*str == 'd')
		return (print_nbr(va_arg(*args, int)));
	if (*str == 'i')
		return (print_nbr(va_arg(*args, int)));
	if (*str == 'u')
		return (print_unsigned_nbr(va_arg(*args, unsigned int)));
	if (*str == 'x')
		return (print_hex(va_arg(*args, unsigned int), 1));
	if (*str == 'X')
		return (print_hex(va_arg(*args, unsigned int), 0));
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
			if (!str[i])
				break ;
			if (str[i] == '%')
				count += print_char('%');
			else
				count += print_format_str(&str[i], &args);
		}
		else
			count += print_char(str[i]);
		++i;
	}
	va_end(args);
	return (count);
}
