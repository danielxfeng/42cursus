/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:26:39 by Xifeng            #+#    #+#             */
/*   Updated: 2024/10/24 22:42:39 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	helper(int nb, int min, int max)
{
	int	mid;

	if (min > max)
		return (0);
	mid = (max + min) / 2;
	if (mid * mid == nb)
		return (mid);
	if (mid * mid > nb)
		return (helper(nb, min, mid - 1));
	return (helper(nb, mid + 1, max));
}

int	ft_sqrt(int nb)
{
	int	mid;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	return (helper(nb, 2, nb / 2));
}
