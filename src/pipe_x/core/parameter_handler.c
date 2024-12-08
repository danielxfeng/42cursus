/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:43:45 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/08 16:24:13 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_x.h"
#include "../libft/libft.h"

// Returns the array of `path` from `env`
char **parse_path(char **envp)
{
    int i;
    char **path;

    if (envp && *envp)
    {
        i = 0;
        while (envp[i])
        {
            if (ft_strncmp(envp[i], "PATH=", 5) == 0)
            {
                path = ft_split(envp[i] + 5, ':');
                if (!path)
                    exit_prog(NULL, "ft_split()", MALLOC_ERR, EXIT_FAILURE);
                return (path);
            }
            ++i;
        }        
    }
    path = ft_split("", ':');
    if (!path)
        exit_prog(NULL, "ft_split()", MALLOC_ERR, EXIT_FAILURE);
    return (path);    
}

// Validate the parameter.
// Return if the RED is `<<` and `>>`.
bool validate_param(int argc, char **argv, bool is_bonus)
{
    if ((is_bonus && argc < 5) || (!is_bonus && argc != 5))
        exit_prog(NULL, NULL, "Usage: ./pipex infile cmd1 cmd2 outfile\n", EXIT_FAILURE);
    return (is_bonus && argv[1] == "here_doc");
}
