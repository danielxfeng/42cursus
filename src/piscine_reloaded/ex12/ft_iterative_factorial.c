/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:11:27 by Xifeng            #+#    #+#             */
/*   Updated: 2024/10/24 22:21:46 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	res;

	if (nb <= 0)
		return (0);
	n = 1;
	res = 1;
	while (n <= nb)
	{
		res *= n;
		++n;
	}
	return (res);
}
