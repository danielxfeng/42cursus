/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:55:38 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/14 11:57:17 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_x.h"

int	return_process_res(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

// To check if it's an empty cmd.
bool	is_empty_cmd(t_ast *ast, t_cmd_prop *prop)
{
	int	i;

	i = 0;
	while (prop->ori_cmd[i])
	{
		if (prop->ori_cmd[i] != ' ')
			return (false);
		++i;
	}
	exit_prog(&ast, prop->ori_cmd, CMD_ERR, EXIT_CMD_ERR);
	return (true);
}
