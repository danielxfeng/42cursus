/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:55:59 by Xifeng            #+#    #+#             */
/*   Updated: 2024/10/25 19:00:38 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);

void	bubble_sort(int len, char **str)
{
	int	i;
	int	j;
	int	is_swapped;

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

int	main(int argc, char **argv)
{
	int	i;

	bubble_sort(argc - 1, &argv[1]);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		++i;
	}
}
