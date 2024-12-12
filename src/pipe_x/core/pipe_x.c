/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:02:14 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/12 14:50:54 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../pipe_x.h"
#include <stdlib.h>

// Returns the array of `path` from `env`
char	**parse_path(char **envp)
{
	int		i;
	char	**path;

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
bool	validate_param(int argc, char **argv, bool is_bonus)
{
	bool	is_double;

	if ((is_bonus && argc < 5) || (!is_bonus && argc != 5))
		exit_prog(NULL, NULL, "Usage: ./pipex infile cmd1 cmd2 outfile\n",
			EXIT_FAILURE);
	is_double = false;
	if (is_bonus && ft_strlen(argv[1]) == 8 && (ft_strncmp(argv[1], "here_doc",
				8)) == 0)
	{
		is_double = true;
		if (argc < 6)
			exit_prog(NULL, NULL,
				"Usage: ./pipex here_doc EOF cmd1 cmd2 outfile\n",
				EXIT_FAILURE);
	}
	return (is_double);
}

// The function for exit the program after closing all resources on heap.
// Also print the error infomation on error.
void	exit_prog(t_ast **ast, char *context, char *msg, int code)
{
	if (context || msg)
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

// The entry point of pipe_x.
// We do the validation first.
// Then initialize the AST tree.
// After that, we build the tree by given parameters.
// We excute the tree recursively.
// We clear the resource and quit.
int	pipe_x(int argc, char **argv, char **envp, bool is_bonus)
{
	t_ast	*ast;
	bool	is_double;
	int		status;

	is_double = validate_param(argc, argv, is_bonus);
	ast = create_ast(envp, parse_path(envp));
	if (!is_double)
		build_ast(ast, argc - 1, &(argv[1]), !is_double);
	else
		build_ast(ast, argc - 2, &(argv[2]), !is_double);
	status = ast->root->node_handler(ast, ast->root);
	exit_prog(&ast, NULL, NULL, status);
	return (EXIT_FAILURE);
}
