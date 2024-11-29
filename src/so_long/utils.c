/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:53:19 by Xifeng            #+#    #+#             */
/*   Updated: 2024/11/29 18:56:22 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns the length of a null terminated string array. 
int str_arr_len(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        ++i;
    return (i);
}