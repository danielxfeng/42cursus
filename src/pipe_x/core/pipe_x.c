/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:02:14 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/08 18:04:02 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_x.h"
#include "../libft/libft.h"
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

// The entry point of pipe_x.
// We do the validation first.
// Then initialize the AST tree.
// After that, we build the tree by given parameters.
// We excute the tree recursively.
// We clear the resource and quit.
int pipe_x(int argc, char **argv, char **envp, bool is_bonus)
{
    t_ast *ast;
    bool is_double;

    is_double = validate_param(argc, argv, is_bonus);
    ast = create_ast(parse_path(envp));
    build_ast(ast, argc - 1, &(argv[1]), !is_double);
    ast->root->node_handler(ast, ast->root);
    exit_prog(&ast, NULL, NULL, EXIT_SUCCESS);
    return (EXIT_FAILURE);
}
