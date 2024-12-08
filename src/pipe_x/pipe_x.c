/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:02:14 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/08 15:12:52 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_x.h"
#include "libft/libft.h"
#include <stdlib.h>

// The function for exit the program after closing all resources on heap.
// Also print the error infomation on error.
void exit_prog(t_ast **ast, char *context, char *msg, int code)
{
    if (code != EXIT_SUCCESS)
    {
        ft_putstr_fd("pipex: ", 2);
        if (context)
        {
            ft_putstr_fd(context, 2);
            if (msg)
                ft_putstr_fd(": ", 2);
        }
        if (msg)
            ft_putstr_fd(msg, 2);
        ft_putchar_fd('\n', 2);
    }
    if (ast && *ast)
        close_ast(ast);
    exit(code);
}

