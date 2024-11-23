/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:41:53 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/23 20:45:52 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helper.h"
#include <stdint.h>

static int	utoa_base(uintptr_t n, char *base, char *buf, size_t buf_size)
{
	uintptr_t	ln;
	size_t		len_base;
	size_t		i;

	ft_bzero(buf, buf_size);
	ln = n;
	len_base = ft_strlen(base);
	i = buf_size - 1;
	while (ln >= len_base)
	{
		buf[i--] = base[ln % len_base];
		ln /= len_base;
	}
	buf[i--] = base[ln % len_base];
	return (i + 1);
}

int	print_ptr(void *ptr)
{
	char	buf[16];
	int		first_idx;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	first_idx = utoa_base((uintptr_t)ptr, "0123456789abcdef", buf, 16);
	return (write(1, &buf[first_idx], 16 - first_idx) + 2);
}

int	print_hex(unsigned int n, int is_lowercase)
{
	char	*base;
	char	buf[16];
	int		first_idx;

	if (is_lowercase)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	first_idx = utoa_base((uintptr_t)n, base, buf, 16);
	return (write(1, &buf[first_idx], 16 - first_idx));
}

int	print_unsigned_nbr(unsigned int n)
{
	char	buf[16];
	int		first_idx;

	first_idx = utoa_base((uintptr_t)n, "0123456789", buf, 16);
	return (write(1, &buf[first_idx], 16 - first_idx));
}
