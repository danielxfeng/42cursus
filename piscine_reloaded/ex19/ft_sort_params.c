/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:55:59 by Xifeng            #+#    #+#             */
/*   Updated: 2024/10/25 18:48:05 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	char	*c;

	c = str;
	while (*c != '\0')
	{
		ft_putchar(*c);
		++c;
	}
    ft_putchar('\n');
}

void	ft_swap(char **a, char **b)
{
	char	*swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	return (0);
}

void	bubble_sort(int len, char **str)
{
	int i;
    int j;
	int is_swapped;

	is_swapped = 1;
    j = 0;
	while (is_swapped)
	{
		is_swapped = 0;
		i = 0;
		while (i < len - 1 - j)
		{
			if (ft_strcmp(str[i], str[i + 1]) > 0)
			{
				ft_swap(&str[i], &str[i + 1]);
                is_swapped = 1;
			}
            ++i;
		}
        ++j;
	}
}

int main(int argc, char **argv)
{
    int i;

    bubble_sort(argc - 1, &argv[1]);
    i = 1;
    while (i < argc)
    {
        ft_putstr(argv[i]);
        ++i;
    }
}
