/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:41:53 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/08 14:44:10 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

int	print_unsigned_nbr_base(uintptr_t n, char *base)
{
	// todo
	return (0);
}

int	print_ptr(void *ptr)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(2, "0x", 2);
	return (2 + print_unsigned_nbr_base((uintptr_t)ptr, "0123456789"));
}

int	print_hex(unsigned int n, int is_lowercase)
{
	char	*base;

	if (is_lowercase)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (print_unsigned_nbr_base((uintptr_t)n, base));
}

int	print_unsigned_nbr(unsigned int n)
{
	return (print_unsigned_nbr_base((uintptr_t)n, "0123456789"));
}
